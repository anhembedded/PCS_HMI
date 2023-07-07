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

    virtual void buttonText_Kp_clickHandle();
    virtual void buttonText_Ki_clickHandle();
    virtual void buttonText_Kd_clickHandle();
    virtual void buttonText_setPoint_clickHandle();

    virtual void confirmUpdateParamter();
    virtual void button_level_select_Handle();
    virtual void button_flowRate_select_Handle();
    virtual void button_pressure_select_Handle();
    virtual void button_temperature_select_Handle();
    virtual void openModelButton();
   
        
    void updateActualValue();
    
    void drawTextAreaKp();
    void drawTextAreaKi();
    void drawTextAreaKd();
    void drawTextAreaSetPoint();
   
   
    void notifyActiveScreen();
    activeScreen_type getActiveScreen() const;
    void notifyActualValueChanged();
    void pidParamCheckRange();
    void updatePidOutput(float pidOutput);
protected:
private:
    void textFrequencyUpdate();
    float constraint(float number ,float min, float max);
    uint32_t u32_tick;
    
};

#endif // CLOSEDLOOPSETTINGVIEW_HPP
