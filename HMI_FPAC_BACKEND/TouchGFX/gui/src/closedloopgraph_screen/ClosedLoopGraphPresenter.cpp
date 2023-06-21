#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>

ClosedLoopGraphPresenter::ClosedLoopGraphPresenter(ClosedLoopGraphView& v)
    : view(v)
{

}

void ClosedLoopGraphPresenter::activate()
{

}

void ClosedLoopGraphPresenter::deactivate()
{

}

pidParam_type ClosedLoopGraphPresenter::getPidParam()
{
    return model->pidParam;
}

 void ClosedLoopGraphPresenter::notifyActiveScreen()
{
    model->updateActiveScreen(view.getActiveScreen());
}
