#ifndef CLOSEDLOOPSETTINGPRESENTER_HPP
#define CLOSEDLOOPSETTINGPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ClosedLoopSettingView;

class ClosedLoopSettingPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ClosedLoopSettingPresenter(ClosedLoopSettingView& v);

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

    void setPidParam(pidParam_type pid);
    pidParam_type getPidParam();
    void setActualValue(actualValue_type view_actualValue);
    actualValue_type getActualValue();

    void notifyActiveScreen() override;

    virtual ~ClosedLoopSettingPresenter() {};

private:
    ClosedLoopSettingPresenter();

    ClosedLoopSettingView& view;

  
};

#endif // CLOSEDLOOPSETTINGPRESENTER_HPP
