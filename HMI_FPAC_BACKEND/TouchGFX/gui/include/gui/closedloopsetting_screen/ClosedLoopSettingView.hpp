#ifndef CLOSEDLOOPSETTINGVIEW_HPP
#define CLOSEDLOOPSETTINGVIEW_HPP

#include <gui_generated/closedloopsetting_screen/ClosedLoopSettingViewBase.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>

class ClosedLoopSettingView : public ClosedLoopSettingViewBase
{
public:
   

    pidParam_type pidParam;
    

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

    virtual void confirmUpdateParamter()
    {
        presenter->setPidParam(pidParam);
    }

    void drawTextAreaKp();
    void drawTextAreaKi();
    void drawTextAreaKd();
protected:
private:
    void textFrequencyUpdate();
    uint32_t u32_tick;
   
};

#endif // CLOSEDLOOPSETTINGVIEW_HPP
