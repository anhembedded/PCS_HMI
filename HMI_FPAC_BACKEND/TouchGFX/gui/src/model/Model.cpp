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
#ifdef SIMULATOR

#else

#endif // SIMULATOR
}

void Model::tick()
{
    frameTickVal++;
#ifdef SIMULATOR

#else
    auto isRecieved = xQueueReceive(adcSendToFrontEndHandle, &u32_adcPtr, 0);
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
    /* DigitalInput */
    /*  isRecieved = xQueueReceive(digitalInputSendToFrontEndHandle, &u32_digitalInputVar, 0);
     if (isRecieved == pdTRUE)
     {
         if (modelListener != 0)
         {
             modelListener->notifyDigitalInput(u32_digitalInputVar);
         }
     } */

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
#else
    u_appDigitalVar.digitalState[0] = digitalOutput.u8_digiOut.at(0);
    u_appDigitalVar.digitalState[1] = digitalOutput.u8_digiOut.at(1);
    u_appDigitalVar.digitalState[2] = digitalOutput.u8_digiOut.at(2);
    u_appDigitalVar.digitalState[3] = digitalOutput.u8_digiOut.at(3);
    u_appDigitalVar.digitalState[4] = digitalOutput.u8_digiOut.at(4);
    u_appDigitalVar.isUpdate = 1;
#endif
}

void Model::updateActiveScreen(activeScreen_type param)
{
    this->activeScreenVar = param;
    debugPrint<decltype(param)>("debugPrint::ActiveScreen", param);
}

// !SIMULATOR

void Model::setPidParam(pidParam_type pidSet)
{
    u_appPid_updateParam_type backendPid;
    this->pidParam = pidSet;
    backendPid.Kp = pidSet.f_kp;
    backendPid.Ki = pidSet.f_ki;
    backendPid.Kd = pidSet.f_kd;
    backendPid.setPoint = pidSet.f_setPoint;
    debugPrint<decltype(pidSet.f_kp)>("debugPrint::pidSet.f_kp", pidSet.f_kp);
    debugPrint<decltype(pidSet.f_ki)>("debugPrint::pidSet.f_ki", pidSet.f_ki);
    debugPrint<decltype(pidSet.f_kd)>("debugPrint::pidSet.f_kd", pidSet.f_kd);
    debugPrint<decltype(pidSet.f_setPoint)>("debugPrint::pidSet.setPoint", pidSet.f_setPoint);
}

pidParam_type Model::getPidParam()
{
    return this->pidParam;
}

void Model::setActualValue(actualValue_type view_actualValue)
{
    this->actualValue = view_actualValue;
    debugPrint<actualValue_type>("debugPrint::actual", this->actualValue);
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
    return analogIn.getAnalogValueFloat(static_cast<uint32_t>(actualValue));
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
