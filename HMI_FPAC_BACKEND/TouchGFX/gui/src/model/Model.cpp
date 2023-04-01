#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#ifndef SIMULATOR
#include "u_firmwareDefination.h"
#include "u_appMain.h"
#include "FreeRTOS.h"
#include "queue.h"
#endif // !SIMULATOR

#include <algorithm>

Model::Model() : modelListener(0)
{
#ifndef SIMULATOR

#endif // !SIMULATOR
}

void Model::tick()
{
#ifdef SIMULATOR
    tickVal++;
#endif // SIMULATOR
#ifndef SIMULATOR
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
#endif // !SIMULATOR
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
#endif // SIMULATOR
#ifndef SIMULATOR
    xQueueSend(queue_updatePwmCh1Handle, &registerVar, 0);
#endif // !SIMULATOR
}
