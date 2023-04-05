#ifndef CLOSEDLOOPGRAPHVIEW_HPP
#define CLOSEDLOOPGRAPHVIEW_HPP

#include <gui_generated/closedloopgraph_screen/ClosedLoopGraphViewBase.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>

class ClosedLoopGraphView : public ClosedLoopGraphViewBase
{
public:
    ClosedLoopGraphView();
    virtual ~ClosedLoopGraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();
protected:
private:
    uint32_t viewTick;
};

#endif // CLOSEDLOOPGRAPHVIEW_HPP
