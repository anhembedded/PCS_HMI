#ifndef CLOSEDLOOPGRAPHVIEW_HPP
#define CLOSEDLOOPGRAPHVIEW_HPP

extern "C"
{
#include "gui/model/u_helpFunction.h"
}

#include <gui_generated/closedloopgraph_screen/ClosedLoopGraphViewBase.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>

enum class graphState {
    stop,
    run,
    clear
 };
class ClosedLoopGraphView : public ClosedLoopGraphViewBase
{
public:
    ClosedLoopGraphView();
    virtual ~ClosedLoopGraphView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

   
    void notifyActiveScreen()
    {
        presenter->notifyActiveScreen();
    }
    activeScreen_type getActiveScreen() const
    {
        return activeScreen_type::closedLoopGraphScreen;
    }
    void addFeedbackDataPoint(float dataPoint)
    {
        graphFeadback.addDataPoint(dataPoint);
    }
    void getFeedbackDataPoint()
    {
        auto dataPoint = presenter->getFeedbackDataPointFormModel();
        graphFeadback.addDataPoint(dataPoint);
    }
protected:
private:

    void updateScreenParam();
    uint32_t viewTick;
    pidParam_type pidParam;
    float mathTick;

    void drawTextAreaKp();
    void drawTextAreaKi();
    void drawTextAreaKd();
    
    struct diff_type diffVar;


   

};

#endif // CLOSEDLOOPGRAPHVIEW_HPP
