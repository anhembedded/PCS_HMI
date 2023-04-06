#ifndef DIGITALINPUTINDICATOR_HPP
#define DIGITALINPUTINDICATOR_HPP

#include <gui_generated/containers/DigitalInputIndicatorBase.hpp>

class DigitalInputIndicator : public DigitalInputIndicatorBase
{
public:
    DigitalInputIndicator();
    virtual ~DigitalInputIndicator() {}

    virtual void initialize();
    void drawDigtalInputState(decltype(boxDigitalInput_0)& boxParam, uint8_t state);
    void drawDigtalInputState(uint32_t regiterVar);
    uint32_t readBit(uint32_t res, uint8_t pos) const;
protected:
private:
    
};

#endif // DIGITALINPUTINDICATOR_HPP
