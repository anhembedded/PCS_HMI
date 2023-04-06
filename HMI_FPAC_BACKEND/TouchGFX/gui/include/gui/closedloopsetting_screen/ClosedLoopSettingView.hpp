#ifndef CLOSEDLOOPSETTINGVIEW_HPP
#define CLOSEDLOOPSETTINGVIEW_HPP

#include <gui_generated/closedloopsetting_screen/ClosedLoopSettingViewBase.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>

class ClosedLoopSettingView : public ClosedLoopSettingViewBase
{
public:
    float kp;
    float ki;
    float kd;

    


    ClosedLoopSettingView();
    virtual ~ClosedLoopSettingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void buttonText_Kp_clickHandle()
    {
        keyboard1.callKeyboard(&kp, TEXT_ANALOGVAL_KP_SIZE);
    }
    virtual void buttonText_Ki_clickHandle()
    {
        keyboard1.callKeyboard(&ki, TEXT_ANALOGVAL_KI_SIZE);
    }
    virtual void buttonText_Kd_clickHandle()
    {
        keyboard1.callKeyboard(&kd, TEXT_ANALOGVAL_KD_SIZE);
    }

    void drawTextAreaKp();
    void drawTextAreaKi();
    void drawTextAreaKd();
protected:
   
};

#endif // CLOSEDLOOPSETTINGVIEW_HPP
