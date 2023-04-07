#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>

ClosedLoopGraphView::ClosedLoopGraphView()
{
   
}

void ClosedLoopGraphView::setupScreen()
{
    ClosedLoopGraphViewBase::setupScreen();
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
