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
    frameTickVal++;
#else
    auto isRecieved = xQueueReceive(adcSendToFrontEndHandle, &u32_adcPtr, 0);
    if (isRecieved == pdTRUE)
    {
     

        analogIn.u32_10BitAnalogIn.at(0) = u32_adcPtr[0];
        analogIn.u32_10BitAnalogIn.at(1) = u32_adcPtr[1];
        analogIn.u32_10BitAnalogIn.at(2) = u32_adcPtr[2];
        analogIn.u32_10BitAnalogIn.at(3) = u32_adcPtr[3];
        

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
#else
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

void Model::sendDigitalOutputToBackEnd()
{
#ifdef SIMULATOR
    touchgfx_printf("DigitalOutputSendToBackend: %d, %d, %d,%d  \n", 
        digitalOutput.u8_digiOut.at(3),
        digitalOutput.u8_digiOut.at(2),
        digitalOutput.u8_digiOut.at(1),
        digitalOutput.u8_digiOut.at(0));
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

   void Model::setDigitalOut(digitaOut_type setOutput)
  {

      digitalOutput = setOutput;
      this->sendDigitalOutputToBackEnd();
  }

    void Model::setDigitalIn(digitalIn_type setInput)
   {
       digitalInput = setInput;
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
    auto multiFactor = analogInFloat * f_factor.at(indexChannel);
    auto res = multiFactor + f_offset.at(indexChannel);
    return res;
}
