#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <gui_generated/containers/KeyboardBase.hpp>
#include <string>
#include <stdint.h>

class Keyboard : public KeyboardBase
{
public:
    Keyboard();
    float buffer;
    virtual ~Keyboard() {}

    virtual void initialize();
    void button1ClickHandler() final;
    void button2ClickHandler() final;
    void button3ClickHandler() final;
    void button4ClickHandler() final;
    void button5ClickHandler() final;
    void button6ClickHandler() final;
    void button7ClickHandler() final;
    void button8ClickHandler() final;
    void button9ClickHandler() final;
    void button0ClickHandler() final;
    void buttonDelClickHandler() final;
    void buttonDotClickHandler() final;
    void buttonEnterClickHandler() final;

    void callKeyboard(float *desNumber, uint8_t maxOfDesBuffer);

protected:
    std::string keyBoardBuffer; 
    uint8_t indexBuffer;
    float* inputNumber;
    uint8_t maxOfDesBuffer;
    void (*updateDisplay)(float number);
private:
    void clearBuffer()
    {
        keyBoardBuffer.clear();
    }
    void numericButtonLogic(char ch)
    {
        if (indexBuffer <= maxOfDesBuffer)
        {
            keyBoardBuffer = keyBoardBuffer + ch;
            indexBuffer++;
            if (inputNumber != nullptr)
            {
                *inputNumber = std::stof(keyBoardBuffer);
            }
        }
        else
        {
            indexBuffer = 0;
        }
    }
};

#endif // KEYBOARD_HPP
