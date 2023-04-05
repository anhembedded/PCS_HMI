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
