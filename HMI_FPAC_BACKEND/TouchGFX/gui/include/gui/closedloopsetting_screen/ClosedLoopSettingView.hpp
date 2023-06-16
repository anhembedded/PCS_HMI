#ifndef CLOSEDLOOPSETTINGVIEW_HPP
#define CLOSEDLOOPSETTINGVIEW_HPP

#include <gui_generated/closedloopsetting_screen/ClosedLoopSettingViewBase.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>

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
        presenter->setPidParam(pidParam);
    }
    virtual void button_level_select_Handle()
    {
        this->actualValue = actualValue_type::level;
        presenter->setActualValue(this->actualValue);
    }
    virtual void button_flowRate_select_Handle()
    {
        this->actualValue = actualValue_type::flowRate;
        presenter->setActualValue(this->actualValue);
    }
    virtual void button_pressure_select_Handle()
    {
        this->actualValue = actualValue_type::pressure;
        presenter->setActualValue(this->actualValue);
    }
    virtual void button_temperature_select_Handle()
    {
        this->actualValue = actualValue_type::temperature;
        presenter->setActualValue(this->actualValue);
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
protected:
private:
    void textFrequencyUpdate();
    uint32_t u32_tick;
    
};

#endif // CLOSEDLOOPSETTINGVIEW_HPP
