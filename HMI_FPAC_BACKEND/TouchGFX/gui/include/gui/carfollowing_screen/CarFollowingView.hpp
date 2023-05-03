#ifndef CARFOLLOWINGVIEW_HPP
#define CARFOLLOWINGVIEW_HPP

#include <gui_generated/carfollowing_screen/CarFollowingViewBase.hpp>
#include <gui/carfollowing_screen/CarFollowingPresenter.hpp>

class CarFollowingView : public CarFollowingViewBase
{
public:
    CarFollowingView();
    virtual ~CarFollowingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void  handleTickEvent() override;


protected:
private:
    virtual void button_onOff_Handle()
    {
        // Override and implement this function in CarFollowing
    }
    virtual void slider_PwmConfirm_Handle(int value)
    {
        u32_pwmVar = slider_Pwm.getValue();
    }
    virtual void slider_PwmChange_Handle(int value)
    {
        u32_pwmVar = slider_Pwm.getValue();
    }
    void setAndDrawGaugeLeft(uint32_t var);
    void setAndDrawGaugeRight(uint32_t var);
    void setAndDrawBattery(uint32_t var);

    uint32_t tick;

    uint32_t u32_simulateVar;
    uint32_t u32_pwmVar;


};

#endif // CARFOLLOWINGVIEW_HPP
