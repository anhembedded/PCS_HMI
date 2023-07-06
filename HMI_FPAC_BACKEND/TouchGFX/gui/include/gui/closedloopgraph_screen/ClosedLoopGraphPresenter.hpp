#ifndef CLOSEDLOOPGRAPHPRESENTER_HPP
#define CLOSEDLOOPGRAPHPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ClosedLoopGraphView;

class ClosedLoopGraphPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ClosedLoopGraphPresenter(ClosedLoopGraphView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~ClosedLoopGraphPresenter() {};

    virtual pidParam_type getPidParam();

    void notifyActiveScreen() override;
    float getFeedbackDataPointFormModel();
   
    void  sendFeedbackToView();
    void statePidGraphRunP_entry();
    void statePidGraphRunP_exit();
    void statePidGraph_entry();
    void statePidGrap_exit();
    void notifyUpdatePidOutput(uint32_t pidOutput);
    void setDigitalOut(digitaOut_type setOutput);
    digitaOut_type getDigitalOutFormModel();
   
private:
    ClosedLoopGraphPresenter();

    ClosedLoopGraphView& view;
};

#endif // CLOSEDLOOPGRAPHPRESENTER_HPP
