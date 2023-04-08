#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>

ClosedLoopGraphView::ClosedLoopGraphView()
{
   
}

void ClosedLoopGraphView::setupScreen()
{
    ClosedLoopGraphViewBase::setupScreen();
    pidParam = presenter->getPidParam();
    this->drawTextAreaKp();
    this->drawTextAreaKi();
    this->drawTextAreaKd();
    spOpFb1.drawtextAreaFeedback(pidParam.f_setPoint);
    spOpFb1.drawtextAreaSetpoint(pidParam.f_setPoint);
   
}

void ClosedLoopGraphView::tearDownScreen()
{
    ClosedLoopGraphViewBase::tearDownScreen();
}

void ClosedLoopGraphView::handleTickEvent()
{
#ifdef SIMULATOR
    viewTick++;
    spOpFb1.drawLineProgressOutput((int)viewTick % 1023u);
#endif // SIMULATOR

   
}

void ClosedLoopGraphView::updateScreenParam()
{
      
}

void ClosedLoopGraphView::drawTextAreaKp()
{
    Unicode::snprintfFloat(text_analogVal_KpBuffer, TEXT_ANALOGVAL_KP_SIZE, "%2.2f", static_cast<float>(this->pidParam.f_kp));
    text_analogVal_Kp.invalidate();
}

void ClosedLoopGraphView::drawTextAreaKi()
{

    Unicode::snprintfFloat(text_analogVal_KiBuffer, TEXT_ANALOGVAL_KI_SIZE, "%2.2f", static_cast<float>(this->pidParam.f_ki));
    text_analogVal_Ki.invalidate();
}

void ClosedLoopGraphView::drawTextAreaKd()
{
    Unicode::snprintfFloat(text_analogVal_KdBuffer, TEXT_ANALOGVAL_KD_SIZE, "%2.2f", static_cast<float>(this->pidParam.f_kd));
    text_analogVal_Kd.invalidate();
}
