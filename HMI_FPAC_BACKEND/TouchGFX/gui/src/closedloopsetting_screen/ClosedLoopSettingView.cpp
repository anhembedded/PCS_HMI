#include <gui/closedloopsetting_screen/ClosedLoopSettingView.hpp>

ClosedLoopSettingView::ClosedLoopSettingView()
{
   
}

void ClosedLoopSettingView::setupScreen()
{
    ClosedLoopSettingViewBase::setupScreen();
    this->pidParam = presenter->getPidParam();
    this->drawTextAreaKp();
    this->drawTextAreaKi();
    this->drawTextAreaKd();
    this->drawTextAreaSetPoint();
    this->updateActualValue();
    notifyActiveScreen();
}

void ClosedLoopSettingView::tearDownScreen()
{
    ClosedLoopSettingViewBase::tearDownScreen();
}

void ClosedLoopSettingView::handleTickEvent()
{
    this->u32_tick++;

    this->textFrequencyUpdate();
}

void ClosedLoopSettingView::drawTextAreaKp()
{
    Unicode::snprintfFloat(text_analogVal_KpBuffer, TEXT_ANALOGVAL_KP_SIZE, "%2.2f", static_cast<float>(this->pidParam.f_kp));
    text_analogVal_Kp.invalidate();
}
void ClosedLoopSettingView::drawTextAreaKi()
{
    Unicode::snprintfFloat(text_analogVal_KiBuffer, TEXT_ANALOGVAL_KI_SIZE, "%2.2f", static_cast<float>(this->pidParam.f_ki));
    text_analogVal_Ki.invalidate();
}
void ClosedLoopSettingView::drawTextAreaKd()
{
    Unicode::snprintfFloat(text_analogVal_KdBuffer, TEXT_ANALOGVAL_KD_SIZE, "%2.2f", static_cast<float>(this-> pidParam.f_kd));
    text_analogVal_Kd.invalidate();
}

void ClosedLoopSettingView::drawTextAreaSetPoint()
{
    Unicode::snprintfFloat(text_setPointBuffer, TEXT_SETPOINT_SIZE, "%3.2f", static_cast<float>(this->pidParam.f_setPoint));
    text_setPoint.invalidate();

}

 void ClosedLoopSettingView::updatePidOutput(float pidOutput)
{
    auto pidOut10Float = cov1024to10Float((uint32_t)pidOutput);

}

void ClosedLoopSettingView::textFrequencyUpdate()
{
    if (this->u32_tick % 50)
    {
        this->pidParamCheckRange();
        this->drawTextAreaKp();
        this->drawTextAreaKi();
        this->drawTextAreaKd();
        this->drawTextAreaSetPoint();
     }
}
