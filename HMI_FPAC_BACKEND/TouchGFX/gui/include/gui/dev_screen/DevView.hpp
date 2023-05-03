#ifndef DEVVIEW_HPP
#define DEVVIEW_HPP

#include <gui_generated/dev_screen/DevViewBase.hpp>
#include <gui/dev_screen/DevPresenter.hpp>

class DevView : public DevViewBase
{
public:
    DevView();
    virtual ~DevView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DEVVIEW_HPP
