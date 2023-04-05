#ifndef DIGITALOUTPUT_HPP
#define DIGITALOUTPUT_HPP

#include <gui_generated/containers/DigitalOutputBase.hpp>

class DigitalOutput : public DigitalOutputBase
{
public:
    DigitalOutput();
    virtual ~DigitalOutput() {}

    virtual void initialize();
protected:
};

#endif // DIGITALOUTPUT_HPP
