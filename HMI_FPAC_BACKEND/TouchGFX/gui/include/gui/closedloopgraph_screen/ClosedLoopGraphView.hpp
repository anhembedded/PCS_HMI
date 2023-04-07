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

    void updateScreenParam();
    uint32_t viewTick;
    pidParam_type pidParam;

    void drawTextAreaKp();
    void drawTextAreaKi();
    void drawTextAreaKd();
    

};

#endif // CLOSEDLOOPGRAPHVIEW_HPP
