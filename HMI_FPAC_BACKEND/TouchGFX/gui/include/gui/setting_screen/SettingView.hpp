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

    virtual void buttonTextFactor0ClickHandle();
    virtual void buttonTextFactor1ClickHandle();
    virtual void buttonTextFactor2ClickHandle();
    virtual void buttonTextFactor3ClickHandle();
    virtual void buttonTextOffset0ClickHandle();
    virtual void buttonTextOffset1ClickHandle();
    virtual void buttonTextOffset2ClickHandle();
    virtual void buttonTextOffset3ClickHandle();
    virtual void sliderAnalogOutHandle0(int value);
    virtual void sliderAnalogOutHandle1(int value);
    virtual void button_confirm_ClickHandle()
    {
        presenter->setSettingVar(this->settingVar);
    }
    void setADC(std::array<uint32_t, 4> arrayParameters);

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

protected:
    float f_channelFactor0;
    float f_channelFactor1;
    float f_channelFactor2;
    float f_channelFactor3;

    float f_channelOffset0;
    float f_channelOffset1;
    float f_channelOffset2;
    float f_channelOffset3;

    float f_channelProcessVariable0;
    float f_channelProcessVariable1;
    float f_channelProcessVariable2;
    float f_channelProcessVariable3;

    float f_analogChannel0;
    float f_analogChannel1;
    float f_analogChannel2;
    float f_analogChannel3;

    uint32_t u32_channelAnalogOut0;
    uint32_t u32_channelAnalogOut1;

private:
    settingVar_type settingVar;
    const float maxVol = 10.f;
    void updateAnalogOut0();
    void updateAnalogOut1();

    float adcRawValueToVoltage(uint32_t adcVal) const;
};

#endif /* INCLUDE_GUI_SETTING_SCREEN_SETTINGVIEW */
