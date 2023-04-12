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
    void  drawDigtalInputState(uint8_t index, uint8_t state);
protected:
private:
    uint32_t readBit(uint32_t res, uint8_t pos) const;
};

#endif // DIGITALINPUTINDICATOR_HPP
