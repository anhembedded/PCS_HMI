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
    virtual void setupScreen() ;
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

    uint32_t u32_channelAnalogOut0;
    uint32_t u32_channelAnalogOut1;

private:
    settingVar_type settingVar;
    analogIn_type analogIn;
    const float maxVol = 10.f;
    void updateAnalogOut0();
    void updateAnalogOut1();
    analogIn_type getAnalogIn();
    float adcRawValueToVoltage(uint32_t adcVal) const;
};

#endif /* INCLUDE_GUI_SETTING_SCREEN_SETTINGVIEW */
