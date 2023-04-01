#ifndef INCLUDE_GUI_MESUARING_SCREEN_MESUARINGPRESENTER
#define INCLUDE_GUI_MESUARING_SCREEN_MESUARINGPRESENTER

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>
#include <array>
using namespace touchgfx;

class MesuaringView;

class MesuaringPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MesuaringPresenter(MesuaringView &v);

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

    virtual ~MesuaringPresenter(){};

    virtual void notifyADCChanged(std::array<uint32_t, 4> arrayParameters);


private:
    MesuaringPresenter();

    MesuaringView &view;
};

#endif /* INCLUDE_GUI_MESUARING_SCREEN_MESUARINGPRESENTER */
