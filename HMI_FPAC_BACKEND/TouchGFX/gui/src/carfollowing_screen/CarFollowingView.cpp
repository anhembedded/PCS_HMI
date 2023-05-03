#include <gui/carfollowing_screen/CarFollowingView.hpp>

CarFollowingView::CarFollowingView()  : u32_simulateVar(0), tick(0) , u32_pwmVar(0)
{

}

void CarFollowingView::setupScreen()
{
    CarFollowingViewBase::setupScreen();
}

void CarFollowingView::tearDownScreen()
{
    CarFollowingViewBase::tearDownScreen();
}

void CarFollowingView::handleTickEvent()
{
    this->tick++;
    auto watchVar = tick % 100;
    
        if (u32_simulateVar > u32_pwmVar)
        {
            this->u32_simulateVar = 0;
        }
        else
        {
            u32_simulateVar = u32_simulateVar +5;
            setAndDrawBattery(u32_simulateVar);
            setAndDrawGaugeLeft(u32_simulateVar);
            setAndDrawGaugeRight(u32_simulateVar);
            graphSetPoint.addDataPoint((float)u32_pwmVar/100);
            graphFeedBack.addDataPoint((float)u32_simulateVar / 100);
        }
      
       
    

}

void CarFollowingView::setAndDrawGaugeLeft(uint32_t var)
{
    gaugeLeft.setValue(var);
    gaugeLeft.invalidate();
}

void CarFollowingView::setAndDrawGaugeRight(uint32_t var)
{

    gaugeRight.setValue(var);
    gaugeRight.invalidate();
}

void CarFollowingView::setAndDrawBattery(uint32_t var)
{
    imageProgress_battery.setValue(var);
    imageProgress_battery.invalidate();
}
