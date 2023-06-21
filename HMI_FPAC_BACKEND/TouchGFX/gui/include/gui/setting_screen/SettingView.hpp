#ifndef INCLUDE_GUI_SETTING_SCREEN_SETTINGVIEW
#define INCLUDE_GUI_SETTING_SCREEN_SETTINGVIEW

#include <gui_generated/setting_screen/SettingViewBase.hpp>
#include <gui/setting_screen/SettingPresenter.hpp>
#include <touchgfx/hal/Types.hpp>
#include <array>

class SettingView : public SettingViewBase
{
public:
    const uint32_t maxAdcRawVal = 1024;
    const float maxVoltage = 10.0f;
    SettingView();
    virtual ~SettingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void handleTickEvent() override;

    virtual void buttonTextFactor0ClickHandle() final;
    virtual void buttonTextFactor1ClickHandle() final;
    virtual void buttonTextFactor2ClickHandle() final;
    virtual void buttonTextFactor3ClickHandle() final;
    virtual void buttonTextOffset0ClickHandle() final;
    virtual void buttonTextOffset1ClickHandle() final;
    virtual void buttonTextOffset2ClickHandle() final;
    virtual void buttonTextOffset3ClickHandle() final;
    virtual void sliderAnalogOutHandle0(int value) final;
    virtual void sliderAnalogOutHandle1(int value) final;
    virtual void button_confirm_ClickHandle() final;
    virtual void buttonDigital0Handle() final
    {
        if (buttonDigital0.getState() == ClickEvent::RELEASED)
        {
            digitalOutput.u8_digiOut.at(0) = 1U;
        }
        else
        {
            digitalOutput.u8_digiOut.at(0) = 0U;
        }
        setDigitalOut(this->digitalOutput);
    }
    virtual void buttonDigital1Handle() final
    {
        if (buttonDigital1.getState() == ClickEvent::RELEASED)
        {
            digitalOutput.u8_digiOut.at(1) = 1U;
        }
        else
        {
            digitalOutput.u8_digiOut.at(1) = 0U;
        }
        setDigitalOut(this->digitalOutput);
    }
    virtual void buttonDigital2Handle() final
    {
        if (buttonDigital2.getState() == ClickEvent::RELEASED)
        {
            digitalOutput.u8_digiOut.at(2) = 1U;
        }
        else
        {
            digitalOutput.u8_digiOut.at(2) = 0U;
        }
        setDigitalOut(this->digitalOutput);
    }
    virtual void buttonDigital3Handle() final
    {
        if (buttonDigital3.getState() == ClickEvent::RELEASED)
        {
            digitalOutput.u8_digiOut.at(3) = 1U;
        }
        else
        {
            digitalOutput.u8_digiOut.at(3) = 0U;
        }
        setDigitalOut(this->digitalOutput);
    }
    virtual void buttonDigital4Handle() final
    {
        if (buttonDigital4.getState() == ClickEvent::RELEASED)
        {
            digitalOutput.u8_digiOut.at(4) = 1U;
        }
        else
        {
            digitalOutput.u8_digiOut.at(4) = 0U;
        }
        setDigitalOut(this->digitalOutput);
    }

    void setADC();

    void drawTextAreaFactor0();
    void drawTextAreaFactor1();
    void drawTextAreaFactor2();
    void drawTextAreaFactor3();
    void drawTextAreaOffset0();
    void drawTextAreaOffset1();
    void drawTextAreaOffset2();
    void drawTextAreaOffset3();
    void drawTextProcessVar0();
    void drawTextProcessVar1();
    void drawTextProcessVar2();
    void drawTextProcessVar3();
    void drawTextFloat(decltype(textAreaFactor1Buffer) textBuffer, decltype(TEXTAREAFACTOR1_SIZE) textBufferSize, decltype("%4.2f") textFormat, decltype(textAreaFactor0) textObject, float number);
    void drawTextAdcIn0(float adcValue);
    void drawTextAdcIn1(float adcValue);
    void drawTextAdcIn2(float adcValue);
    void drawTextAdcIn3(float adcValue);

    void drawDigitalIn(uint8_t index, uint8_t state);
    void drawDigitalIn(digitalIn_type par)
    {
        for (uint8_t i = 0; i <= 6; i++)
        {
            drawDigitalIn(i, par.u8_digiIn.at(i));
        }
    }
    void notifyActiveScreen()
    {
        presenter->notifyActiveScreen();
    }

protected:
    uint32_t u32_channelAnalogOut0;
    uint32_t u32_channelAnalogOut1;

private:
    uint32_t tick;
    settingVar_type settingVar;
    analogIn_type analogIn;
    digitaOut_type digitalOutput;
    digitalIn_type digitalInput;
    const float maxVol = 10.f;
    void updateAnalogOut0();
    void updateAnalogOut1();
    analogIn_type getAnalogIn();
    float adcRawValueToVoltage(uint32_t adcVal) const;
    digitalIn_type getDigitalIn();
    void setDigitalOut(digitaOut_type digiOut);
    digitaOut_type getDigitalOut();
    void screenTearDownHandle()
    {
        this->u32_channelAnalogOut0 = 0U;
        this->u32_channelAnalogOut1 = 0U;
        updateAnalogOut0();
        updateAnalogOut1();
    
    }
};

#endif /* INCLUDE_GUI_SETTING_SCREEN_SETTINGVIEW */
