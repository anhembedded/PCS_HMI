#ifndef DIGITALOUTPUT_HPP
#define DIGITALOUTPUT_HPP

#include <gui_generated/containers/DigitalOutputBase.hpp>

class DigitalOutput : public DigitalOutputBase
{
public:
    DigitalOutput();
    virtual ~DigitalOutput() {}

    virtual void initialize();

    virtual void buttonDigital0Handle()
    {
        if (buttonDigital0.getState() == ClickEvent::PRESSED)
        {
              
        }
        else
        {

        }
    }
    virtual void buttonDigital1Handle()
    {
        // Override and implement this function in DigitalOutput
    }
    virtual void buttonDigital2Handle()
    {
        // Override and implement this function in DigitalOutput
    }
    virtual void buttonDigital3Handle()
    {
        // Override and implement this function in DigitalOutput
    }
    virtual void buttonDigital4Handle()
    {
        // Override and implement this function in DigitalOutput
    }

protected:
    std::array<uint8_t, 5> u8_digiOut;
};

#endif // DIGITALOUTPUT_HPP
