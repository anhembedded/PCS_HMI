#include <gui/containers/Keyboard.hpp>
#include <cstring>

Keyboard::Keyboard()
{

}

void Keyboard::initialize()
{
    KeyboardBase::initialize();
}

void Keyboard::button1ClickHandler()
{
    numericButtonLogic('1');
}

void Keyboard::button2ClickHandler()
{
    numericButtonLogic('2');
}

void Keyboard::button3ClickHandler()
{
    numericButtonLogic('3');
}

void Keyboard::button4ClickHandler()
{
    numericButtonLogic('4');
}

void Keyboard::button5ClickHandler()
{
    numericButtonLogic('5');
}

void Keyboard::button6ClickHandler()
{
    numericButtonLogic('6');
}

void Keyboard::button7ClickHandler()
{
    numericButtonLogic('7');
}

void Keyboard::button8ClickHandler()
{
    numericButtonLogic('8');
}

void Keyboard::button9ClickHandler()
{
    numericButtonLogic('9');
}

void Keyboard::button0ClickHandler()
{
    numericButtonLogic('0');
}

void Keyboard::buttonDotClickHandler()
{
    numericButtonLogic('.');

}

void Keyboard::buttonEnterClickHandler()
{
    this->setVisible(false);
    this->invalidate();
    clearBuffer();
    inputNumber = nullptr;
}

void Keyboard::buttonDelClickHandler()
{
    if (!keyBoardBuffer.empty())
    {
        keyBoardBuffer.pop_back();
        indexBuffer--;
        if (inputNumber != nullptr)
        {
            if (!keyBoardBuffer.empty())
            {
                *inputNumber = std::stof(keyBoardBuffer);
            }
            else
            {
                *inputNumber = 0.F;
            }
           
        }
        else
        {
            return;
        }
       
    }
    else
    {
        return;
    }
   
}

void Keyboard::callKeyboard(float* desNumber, uint8_t maxOfDesBuffer)
{
    setXY(352, 39);
    clearBuffer();
    inputNumber = desNumber;
    this->maxOfDesBuffer = maxOfDesBuffer;
    setVisible(true);
    invalidate();
}
