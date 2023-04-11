#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <cstdint>
#ifdef SIMULATOR

#else
#include "u_firmwareDefination.h"
#include "u_appMain.h"
#include "FreeRTOS.h"
#include "queue.h"
#endif // !SIMULATOR

#include <algorithm>

Model::Model() : modelListener(0)
{
#ifdef SIMULATOR

#else

#endif // SIMULATOR
}

void Model::tick()
{
#ifdef SIMULATOR
    tickVal++;
    if (tickVal % 1000)
    {
        for (auto &i : analogIn.u32_10BitAnalogIn)
        {
            i =  i++;
        }

      
    }

#else
    auto isRecieved = xQueueReceive(adcSendToFrontEndHandle, &u32_adcPtr, 0);
    if (isRecieved == pdTRUE)
    {
        adcValue.at(0) = u32_adcPtr[0];
        adcValue.at(1) = u32_adcPtr[1];
        adcValue.at(2) = u32_adcPtr[2];
        adcValue.at(3) = u32_adcPtr[3];

        if (modelListener != 0)
        {
            modelListener->notifyADCChanged(adcValue);
        }
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
#ifdef SIMULATOR
    touchgfx_printf("sendAdcOuputToBackEnd_1! %d \n", registerVar);
#endif // SIMULATOR
#ifndef SIMULATOR
    xQueueSend(queue_updatePwmCh0Handle, &registerVar, 0);
#endif // !SIMULATOR
}

void Model::sendAdcOuputToBackEnd_0(uint32_t registerVar)
{
#ifdef SIMULATOR
    touchgfx_printf("sendAdcOuputToBackEnd_0! %d \n", registerVar);
#else
    xQueueSend(queue_updatePwmCh1Handle, &registerVar, 0);
#endif // SIMULATOR
}

// !SIMULATOR

 void Model::setPidParam(pidParam_type pidSet)
{
    this->pidParam = pidSet;
    
}

 pidParam_type Model::getPidParam()
{
    return   this->pidParam;
}

 void Model::setActualValue(actualValue_type view_actualValue)
{
    this->actualValue = view_actualValue;
    touchgfx_printf("actual! %d \n", actualValue);
}

 actualValue_type Model::getActualValue()
{
    return   this->actualValue;
}

  void Model::setSettingVar(settingVar_type setVar)
 {
     this->settingVar = setVar;
 }

  settingVar_type Model::getSettingVar()
 {
     return this->settingVar;
 }

#ifdef SIMULATOR

uint32_t Model::modelGetTick()
{
    return this->tickVal;
}
#endif // SIMULATOR

float pidParam_type::getFloatSetpint()
{
    return 0.0f;
}

float analogIn_type::getAnalogValueFloat(uint32_t indexChannel)
{
    auto vol = static_cast<float>(u32_10BitAnalogIn.at(indexChannel)) / rawAnalogMax;
    vol = vol * maxVolage;
    return vol;
}

float settingVar_type::getProcessValue(uint32_t indexChannel, float analogInFloat)
{
    return (analogInFloat * f_factor.at(indexChannel)) + f_offset.at(indexChannel);
}
