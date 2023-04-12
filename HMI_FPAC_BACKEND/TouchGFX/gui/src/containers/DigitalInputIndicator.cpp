#include <gui/containers/DigitalInputIndicator.hpp>
#include <touchgfx/Color.hpp>

DigitalInputIndicator::DigitalInputIndicator()
{

}

void DigitalInputIndicator::initialize()
{
    DigitalInputIndicatorBase::initialize();
}



void DigitalInputIndicator::drawDigtalInputState(decltype(boxDigitalInput_0)& boxParam, uint8_t state)
{
    if (state == 1)
    {
        boxParam.setColor(touchgfx::Color::getColorFromRGB(0x65, 0xFF, 0x36));
    }
    else
    {
        boxParam.setColor(touchgfx::Color::getColorFromRGB(0x94, 0x94, 0x94));
    }
    boxParam.invalidate();
}

void DigitalInputIndicator::drawDigtalInputState(uint32_t regiterVar)
{
    drawDigtalInputState(boxDigitalInput_0, readBit(regiterVar, 0));
    drawDigtalInputState(boxDigitalInput_1, readBit(regiterVar, 1));
    drawDigtalInputState(boxDigitalInput_2, readBit(regiterVar, 2));
    drawDigtalInputState(boxDigitalInput_3, readBit(regiterVar, 3));
    drawDigtalInputState(boxDigitalInput_4, readBit(regiterVar, 4));
    drawDigtalInputState(boxDigitalInput_5, readBit(regiterVar, 5));
    drawDigtalInputState(boxDigitalInput_6, readBit(regiterVar, 6));
}
void DigitalInputIndicator::drawDigtalInputState(uint8_t index, uint8_t state)
{
    if (index == 0)
    {
        drawDigtalInputState(boxDigitalInput_0, state);
    }
    else if (index == 1)
    {
        drawDigtalInputState(boxDigitalInput_1, state);
    }
    else if (index == 2)
    {
        drawDigtalInputState(boxDigitalInput_2, state);
    }
    else if (index == 3)
    {
        drawDigtalInputState(boxDigitalInput_3, state);
    }
    else  if (index == 4)
    {
        drawDigtalInputState(boxDigitalInput_4, state);
    }
    else  if (index == 5)
    {
        drawDigtalInputState(boxDigitalInput_5, state);
    } else if (index == 6)
    {
        drawDigtalInputState(boxDigitalInput_6, state);
    }
    
  
}
uint32_t DigitalInputIndicator::readBit(uint32_t res, uint8_t pos) const
{
    return ((res >> pos) & 1);
}
