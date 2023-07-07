#ifndef CLOSEDLOOPSETTINGVIEW_HPP
#define CLOSEDLOOPSETTINGVIEW_HPP

#include <gui_generated/closedloopsetting_screen/ClosedLoopSettingViewBase.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>
#include "gui/model/u_touchGfxUtilities.hpp"


class ClosedLoopSettingView : public ClosedLoopSettingViewBase
{
public:
   

    pidParam_type pidParam;
    actualValue_type actualValue;
    

    ClosedLoopSettingView();
    virtual ~ClosedLoopSettingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void  handleTickEvent();

    virtual void buttonText_Kp_clickHandle()
    {
        keyboard1.callKeyboard(&pidParam.f_kp, TEXT_ANALOGVAL_KP_SIZE);
    }
    virtual void buttonText_Ki_clickHandle()
    {
        keyboard1.callKeyboard(&pidParam.f_ki, TEXT_ANALOGVAL_KI_SIZE);
    }
    virtual void buttonText_Kd_clickHandle()
    {
        keyboard1.callKeyboard(&pidParam.f_kd, TEXT_ANALOGVAL_KD_SIZE);
    }
    virtual void buttonText_setPoint_clickHandle()
    {
        keyboard1.callKeyboard(&pidParam.f_setPoint, TEXT_SETPOINT_SIZE);
    }

    virtual void confirmUpdateParamter()
    {
        pidParamCheckRange();
        presenter->setPidParam(pidParam);
        presenter->setActualValue(this->actualValue);
        presenter->notifyActualValueChanged(this->actualValue);
        //presenter->statePidGraph_entry();
       
    }
    virtual void button_level_select_Handle()
    {
     
        this->actualValue = actualValue_type::level;
      
    }
    virtual void button_flowRate_select_Handle()
    {
        this->actualValue = actualValue_type::flowRate;
      
    }
    virtual void button_pressure_select_Handle()
    {
        this->actualValue = actualValue_type::pressure;
        
    }
    virtual void button_temperature_select_Handle()
    {
        this->actualValue = actualValue_type::temperature;
        
    }
    virtual void openModelButton()
    {
        this->updateActualValue();
        if (actualValue == actualValue_type::level)
        {
            radioButtonGroup1.setSelected(button_level);
        }
        else if (actualValue == actualValue_type::flowRate)
        {
            radioButtonGroup1.setSelected(button_flowRate);
        }
        else if (actualValue == actualValue_type::pressure)
        {
            radioButtonGroup1.setSelected(button_pressure);
        }
        else if (actualValue == actualValue_type::temperature)
        {
            radioButtonGroup1.setSelected(button_temperature);
        }
    }
   
        
    void updateActualValue()
    {
        this->actualValue = presenter->getActualValueFromModel();
    }
    
    void drawTextAreaKp();
    void drawTextAreaKi();
    void drawTextAreaKd();
    void drawTextAreaSetPoint();
   
   
    void notifyActiveScreen()
    {
        presenter->notifyActiveScreen();
    }
    activeScreen_type getActiveScreen() const
    {
        return activeScreen_type::closedLoopSettingScreen;
    }
    void notifyActualValueChanged()
    {
        presenter->notifyActualValueChanged(actualValue);
    }
    void pidParamCheckRange()
    {
        
        pidParam.f_kp = constraint(pidParam.f_kp, pidRange::KP_MIN, pidRange::KP_MAX);
        pidParam.f_ki = constraint(pidParam.f_ki, pidRange::KI_MIN, pidRange::KI_MAX);
        pidParam.f_kd = constraint(pidParam.f_kd, pidRange::KD_MIN, pidRange::KD_MAX);

    }
    void updatePidOutput(float pidOutput);
protected:
private:
    void textFrequencyUpdate();
    float constraint(float number ,float min, float max)
    {
       if (number < min) 
       {
        number = min;
       }else if (number > max)
       {
         number = max;
       }else
       {
         // do not thing
       }
        return (number);
    }
    uint32_t u32_tick;
    
};

#endif // CLOSEDLOOPSETTINGVIEW_HPP
