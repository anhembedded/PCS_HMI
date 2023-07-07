#ifndef KEYBOARD_HPP
#define KEYBOARD_HPP

#include <gui_generated/containers/KeyboardBase.hpp>
#include <touchgfx/hal/Types.hpp>
#include <string>
#include <stdint.h>

//#include "gui/setting_screen/SettingView.hpp"

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
    virtual void buttonSubClickHandler()
    {
         numericButtonLogic('-');
    }
    void buttonEnterClickHandler() final;
   

    void callKeyboard(float *desNumber, uint8_t maxOfDesBuffer);
    void callKeyboard(float* desNumber, uint8_t maxOfDesBuffer, void (*callerRedraw)());

protected:
    std::string keyBoardBuffer; 
    uint8_t indexBuffer;
    float* inputNumber;
    uint8_t maxOfDesBuffer;
    void (*updateDisplay)(float number);
    void (*callerRedraw_ptr)(void);
private:
    void drawTextAreaBuffer();
    void clearBuffer()
    {
        keyBoardBuffer.clear();     
        for (auto& i : textArea_bufferBuffer)
        {
            i = 0;
        }
    }
    void numericButtonLogic(char ch)
    {
        if (indexBuffer == 0 && (ch == '.'))
        {
            numericButtonLogic('0');
            numericButtonLogic(ch);
        }
        else if (indexBuffer == 0 && ch == '-')
        {
            keyBoardBuffer = keyBoardBuffer + '-';
            indexBuffer++;
            keyBoardBuffer = keyBoardBuffer + '0';
            indexBuffer++;
            buffer = std::stof(keyBoardBuffer);
            drawTextAreaBuffer();
        }else if (indexBuffer <= maxOfDesBuffer)
        {
            keyBoardBuffer = keyBoardBuffer + ch;
            indexBuffer++;
            buffer = std::stof(keyBoardBuffer);
            drawTextAreaBuffer();
        }
        else
        {
            indexBuffer = 0;
        }
    }
};

#endif // KEYBOARD_HPP
