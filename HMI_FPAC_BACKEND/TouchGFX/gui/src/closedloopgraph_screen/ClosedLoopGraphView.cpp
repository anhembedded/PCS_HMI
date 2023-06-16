#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>
#ifdef  SIMULATOR

#endif //  simulator


ClosedLoopGraphView::ClosedLoopGraphView()
{
  
    diff_constructor(&this->diffVar, 0, 0);
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

    notifyActiveScreen();
   
}

void ClosedLoopGraphView::tearDownScreen()
{
    ClosedLoopGraphViewBase::tearDownScreen();
}

void ClosedLoopGraphView::handleTickEvent()
{
#ifdef SIMULATOR
    float diff_var;
    viewTick++;
    mathTick = mathTick + 0.01f;
    diff_var = diff_getRes(&this->diffVar, mathTick, help_sinFunction(5, mathTick));
    graphFeadback.addDataPoint(help_sinFunction(5, mathTick));
    graphSetpoint.addDataPoint(diff_var);
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
