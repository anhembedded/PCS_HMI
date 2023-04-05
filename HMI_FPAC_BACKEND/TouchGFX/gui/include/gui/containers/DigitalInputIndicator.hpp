#ifndef DIGITALINPUTINDICATOR_HPP
#define DIGITALINPUTINDICATOR_HPP

#include <gui_generated/containers/DigitalInputIndicatorBase.hpp>

class DigitalInputIndicator : public DigitalInputIndicatorBase
{
public:
    DigitalInputIndicator();
    virtual ~DigitalInputIndicator() {}

    virtual void initialize();
protected:
};

#endif // DIGITALINPUTINDICATOR_HPP
