#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>
#ifdef SIMULATOR

#else
#include "u_firmwareDefination.h"
#include "u_appMain.h"
#include "FreeRTOS.h"
#include "queue.h"
#include "u_appDigitalInput.h"
#endif // !SIMULATOR

#include <algorithm>
#include <string>
#include "gui/model/u_touchGfxUtilities.hpp"

extern "C"
{
#include "gui/model/u_type.h"
}

Model::Model() : modelListener(0)
{
}

void Model::tick()
{
    frameTickVal++;
#ifdef SIMULATOR

#else
    auto isRecieved = xQueueReceive(adcSendToFrontEndHandle, (void *)&u32_adcPtr, 0);
    auto isReciOuputBackEnd = xQueueReceive(u_pid_queue_sendOutPutToFrontEnd, (void *)&pidOutFromBackend, 0);
    if (isReciOuputBackEnd == pdTRUE)
    {
        if (modelListener != nullptr)
        {
            modelListener->notifyUpdatePidOutput(pidOutFromBackend);
        }
    }
    if (isRecieved == pdTRUE)
    {

        analogIn.u32_10BitAnalogIn.at(0) = u32_adcPtr[0];
        analogIn.u32_10BitAnalogIn.at(1) = u32_adcPtr[1];
        analogIn.u32_10BitAnalogIn.at(2) = u32_adcPtr[2];
        analogIn.u32_10BitAnalogIn.at(3) = u32_adcPtr[3];

        if (modelListener != nullptr)
        {
            modelListener->notifyADCChanged(analogIn);
            modelListener->sendFeedbackToView();
        }
    }

    if (modelListener != 0)
    {
        digitalInput.u8_digiIn.at(0) = (bool)u32_applicationInputState[0];
        digitalInput.u8_digiIn.at(1) = (bool)u32_applicationInputState[1];
        digitalInput.u8_digiIn.at(2) = (bool)u32_applicationInputState[2];
        digitalInput.u8_digiIn.at(3) = (bool)u32_applicationInputState[3];
        digitalInput.u8_digiIn.at(4) = (bool)u32_applicationInputState[4];
        digitalInput.u8_digiIn.at(5) = (bool)u32_applicationInputState[5];
        digitalInput.u8_digiIn.at(6) = (bool)u32_applicationInputState[6];

        modelListener->notifyDigitalInputChanged(digitalInput);
    }

#endif // SIMULATOR
}

void Model::sendAdcOuputToBackEnd_1(uint32_t registerVar)
{
    // touchgfx_printf("sendAdcOuputToBackEnd_1! %d \n", registerVar);
    debugPrint<decltype(registerVar)>("sendAdcOuputToBackEnd_1", registerVar);
#ifdef BACKEND
    xQueueSend(queue_updatePwmCh1Handle, &registerVar, 0);
#endif
}

void Model::sendAdcOuputToBackEnd_0(uint32_t registerVar)
{
    debugPrint<decltype(registerVar)>("sendAdcOuputToBackEnd_0", registerVar);

#ifdef BACKEND
    xQueueSend(queue_updatePwmCh0Handle, &registerVar, 0);
#endif
}

void Model::sendDigitalOutputToBackEnd()
{
#ifdef SIMULATOR
    touchgfx_printf("DigitalOutputSendToBackend: %d, %d, %d,%d  \n",
                    digitalOutput.u8_digiOut.at(3),
                    digitalOutput.u8_digiOut.at(2),
                    digitalOutput.u8_digiOut.at(1),
                    digitalOutput.u8_digiOut.at(0));
#endif
  
#ifdef BACKEND
    u_appDigitalOut_array[0] = digitalOutput.u8_digiOut.at(0);
    u_appDigitalOut_array[1] = digitalOutput.u8_digiOut.at(1);
    u_appDigitalOut_array[2] = digitalOutput.u8_digiOut.at(2);
    u_appDigitalOut_array[3] = digitalOutput.u8_digiOut.at(3);
    xQueueSend(u_app_queue_digitalOutput, u_appDigitalOut_array, 0);
#endif // BACKEND

}

void Model::updateActiveScreen(activeScreen_type param)
{
    this->activeScreenVar = param;
    debugPrint<decltype(param)>("debugPrint::ActiveScreen", param);
}
// !SIMULATOR
void Model::setPidParam(pidParam_type pidSet)
{
    float const1023Div10 = 1023.0F / 10.0F;
    u_appPid_updateParam_type backendPid;
    auto thisOffset = settingVar.f_offset.at(static_cast<uint32_t>(getActualValue()));
    auto thisFactor = settingVar.f_factor.at(static_cast<uint32_t>(getActualValue()));
    this->pidParam = pidSet;
    backendPid.Kp = pidSet.f_kp;
    backendPid.Ki = computingKi(pidSet.f_kp, pidSet.f_ki);
    backendPid.Kd = computingKd(pidSet.f_kp, pidSet.f_kd);
    backendPid.setPoint = (pidSet.f_setPoint - thisOffset)/thisFactor;
    backendPid.setPoint = backendPid.setPoint * const1023Div10;
    debugPrint<decltype(pidSet.f_kp)>("debugPrint::pidSet.f_kp", pidSet.f_kp);
    debugPrint<decltype(pidSet.f_ki)>("debugPrint::pidSet.f_ki", pidSet.f_ki);
    debugPrint<decltype(pidSet.f_kd)>("debugPrint::pidSet.f_kd", pidSet.f_kd);
    debugPrint<decltype(pidSet.f_setPoint)>("debugPrint::pidSet.setPoint", pidSet.f_setPoint);
#ifdef BACKEND
    xQueueSend(u_pid_queue_pidParam, (void *)&backendPid, 0);
#endif
}

pidParam_type Model::getPidParam()
{
    return this->pidParam;
}

void Model::setActualValue(actualValue_type view_actualValue)
{
    this->actualValue = view_actualValue;
    debugPrint<actualValue_type>("debugPrint::actual", this->actualValue);
#ifdef BACKEND
    xQueueSend(u_pid_queue_actuator, (void *)&view_actualValue, 0);
#endif
}

actualValue_type Model::getActualValue()
{
    return this->actualValue;
}

void Model::setSettingVar(settingVar_type setVar)
{
    this->settingVar = setVar;
}

void Model::setDigitalOut(digitaOut_type setOutput)
{

    digitalOutput = setOutput;
    this->sendDigitalOutputToBackEnd();
}

void Model::setDigitalIn(digitalIn_type setInput)
{
    digitalInput = setInput;
}

void Model::setActiveScreen(activeScreen_type activeScreenParam)
{
    // todo: get screen form View.
    this->activeScreenVar = activeScreenParam;
}

void Model::setState(systemState_type sysState)
{
}

void Model::updateActualValue(actualValue_type actualValueParam)
{
    this->actualValue = actualValueParam;
    debugPrint<actualValue_type>("debugPrint::actualValueParam", this->actualValue);
}

float Model::getFeedBackToPresentor()
{
    auto factorVal = this->settingVar.f_factor.at(static_cast<uint32_t>(actualValue));
    auto offsetVal = this->settingVar.f_offset.at(static_cast<uint32_t>(actualValue));
    auto feedback = analogIn.getAnalogValueFloat(static_cast<uint32_t>(actualValue));
    auto feedBackFactorAndOffset = (feedback * factorVal) + offsetVal;
    return feedBackFactorAndOffset;
}

void Model::statePidGraphRun_entry()
{
#ifdef BACKEND
    u_app_pidGraphRun_entry();
#endif // BACKEND
}

void Model::statePidGraphRun_exit()
{
#ifdef BACKEND
    u_app_pidGraphRun_exit();
#endif // BACKEND
}

void Model::stateSettingVar_entry()
{
#ifdef BACKEND
    u_app_settingVarState_entry();
#endif // BACKEND
}

void Model::stateSettingVar_exit()
{
#ifdef BACKEND
    u_app_settingVarState_exit();
#endif // BACKEND
}
void Model::statePidGraph_exit()
{
#ifdef BACKEND
    u_app_pidGraph_exit();
#endif // BACKEND
}
void Model::statePidGraph_entry()
{
#ifdef BACKEND
    u_app_pidGraph_entry();
#endif // BACKEND
}

settingVar_type Model::getSettingVar()
{
    return this->settingVar;
}

analogIn_type Model::getAnalogIn()
{
    return this->analogIn;
}

digitaOut_type Model::getDigitalOut()
{
#ifdef BACKEND
    digitalOutput.u8_digiOut.at(0) = u_appDigitalVar.digitalState[0];
    digitalOutput.u8_digiOut.at(1) = u_appDigitalVar.digitalState[1];
    digitalOutput.u8_digiOut.at(2) = u_appDigitalVar.digitalState[2];
    digitalOutput.u8_digiOut.at(3) = u_appDigitalVar.digitalState[3];
#endif   
    return digitalOutput;
}

digitalIn_type Model::getDigitalIn()
{
    return digitalInput;
}

#ifdef SIMULATOR

uint32_t Model::modelGetTick()
{
    return this->frameTickVal;
}

#endif // SIMULATOR

float analogIn_type::getAnalogValueFloat(uint32_t indexChannel)
{
    auto vol = static_cast<float>(u32_10BitAnalogIn.at(indexChannel)) / rawAnalogMax;
    vol = vol * maxVolage;
    return vol;
}

float settingVar_type::getProcessValue(uint32_t indexChannel, float analogInFloat)
{
    auto multiFactor = analogInFloat * f_factor.at(indexChannel);
    auto res = multiFactor + f_offset.at(indexChannel);
    return res;
}
 float Model::computingKi(float kP, float tI)
{
    auto res = (kP / tI);
    return res;
}
  float Model::computingKd(float kP, float tD)
 {
     auto res = kP * tD;
     return res;
 }
