#include <gui/closedloopsetting_screen/ClosedLoopSettingView.hpp>

ClosedLoopSettingView::ClosedLoopSettingView()
{

}

void ClosedLoopSettingView::setupScreen()
{
    ClosedLoopSettingViewBase::setupScreen();
}

void ClosedLoopSettingView::tearDownScreen()
{
    ClosedLoopSettingViewBase::tearDownScreen();
}

void ClosedLoopSettingView::drawTextAreaKp()
{
    Unicode::snprintfFloat(text_analogVal_KpBuffer, TEXT_ANALOGVAL_KP_SIZE, "%2.2f", static_cast<float>(this->kp));
    text_analogVal_Kp.invalidate();
}
void ClosedLoopSettingView::drawTextAreaKi()
{
    Unicode::snprintfFloat(text_analogVal_KiBuffer, TEXT_ANALOGVAL_KI_SIZE, "%2.2f", static_cast<float>(this->ki));
    text_analogVal_Ki.invalidate();
}
void ClosedLoopSettingView::drawTextAreaKd()
{
    Unicode::snprintfFloat(text_analogVal_KdBuffer, TEXT_ANALOGVAL_KD_SIZE, "%2.2f", static_cast<float>(this->kd));
    text_analogVal_Kd.invalidate();
}
