#include <gui/setting_screen/SettingView.hpp>
#include <touchgfx/Color.hpp>

float adcFloat[4];
SettingView::SettingView() : f_channelFactor0(1.),
                             f_channelFactor1(1.),
                             f_channelFactor2(1.),
                             f_channelFactor3(1.),
                             f_channelOffset0(0.),
                             f_channelOffset1(0.),
                             f_channelOffset2(0.),
                             f_channelOffset3(0.),
                             f_channelProcessVariable0(0.),
                             f_channelProcessVariable1(0.),
                             f_channelProcessVariable2(0.),
                             f_channelProcessVariable3(0.),
                             f_analogChannel0(0.f),
                             f_analogChannel1(0.f),
                             f_analogChannel2(0.f),
                             f_analogChannel3(0.f),
                             u32_channelAnalogOut0(0u),
                             u32_channelAnalogOut1(0u)
{
}

void SettingView::setupScreen()
{
    SettingViewBase::setupScreen();
}

void SettingView::tearDownScreen()
{
    SettingViewBase::tearDownScreen();
}

void SettingView::handleTickEvent()
{

#ifdef SIMULATOR
    f_analogChannel0 = adcRawValueToVoltage((uint32_t)1023);
    f_analogChannel1 = adcRawValueToVoltage(0u);
    f_analogChannel2 = adcRawValueToVoltage(500u);
    f_analogChannel3 = adcRawValueToVoltage(10u);

    drawTextAdcIn0(f_analogChannel0);
    drawTextAdcIn1(f_analogChannel1);
    drawTextAdcIn2(f_analogChannel2);
    drawTextAdcIn3(f_analogChannel3);

    drawTextProcessVar0();
    drawTextProcessVar1();
    drawTextProcessVar2();
    drawTextProcessVar3();

    drawTextAreaFactor0();
    drawTextAreaFactor1();
    drawTextAreaFactor2();
    drawTextAreaFactor3();

    drawTextAreaOffset0();
    drawTextAreaOffset1();
    drawTextAreaOffset2();
    drawTextAreaOffset3();

   
#endif // ! SIMULATOR
}

inline void SettingView::buttonTextFactor0ClickHandle()
{
    keyboard1.callKeyboard(&f_channelFactor0, TEXTAREAFACTOR0_SIZE);
}

inline void SettingView::buttonTextFactor1ClickHandle()
{
    keyboard1.callKeyboard(&f_channelFactor1, TEXTAREAFACTOR1_SIZE);
}

inline void SettingView::buttonTextFactor2ClickHandle()
{
    keyboard1.callKeyboard(&f_channelFactor2, TEXTAREAFACTOR2_SIZE);
}

inline void SettingView::buttonTextFactor3ClickHandle()
{
    keyboard1.callKeyboard(&f_channelFactor3, TEXTAREAFACTOR3_SIZE);
}

inline void SettingView::buttonTextOffset0ClickHandle()
{
    keyboard1.callKeyboard(&f_channelOffset0, TEXTAREAOFFSET0_SIZE);
}

inline void SettingView::buttonTextOffset1ClickHandle()
{
    keyboard1.callKeyboard(&f_channelOffset1, TEXTAREAOFFSET1_SIZE);
}

inline void SettingView::buttonTextOffset2ClickHandle()
{
    keyboard1.callKeyboard(&f_channelOffset2, TEXTAREAOFFSET2_SIZE);
}

inline void SettingView::buttonTextOffset3ClickHandle()
{
    keyboard1.callKeyboard(&f_channelOffset3, TEXTAREAOFFSET3_SIZE);
}

void SettingView::sliderAnalogOutHandle0(int value)
{
    updateAnalogOut0();
}
void SettingView::sliderAnalogOutHandle1(int value)
{
    updateAnalogOut1();
}
void SettingView::setADC(std::array<uint32_t, 4> arrayParameters)
{
    f_analogChannel0 = adcRawValueToVoltage(arrayParameters.at(0));
    f_analogChannel1 = adcRawValueToVoltage(arrayParameters.at(1));
    f_analogChannel2 = adcRawValueToVoltage(arrayParameters.at(2));
    f_analogChannel3 = adcRawValueToVoltage(arrayParameters.at(3));

    drawTextAdcIn0(f_analogChannel0);
    drawTextAdcIn1(f_analogChannel1);
    drawTextAdcIn2(f_analogChannel2);
    drawTextAdcIn3(f_analogChannel3);

    drawTextProcessVar0();
    drawTextProcessVar1();
    drawTextProcessVar2();
    drawTextProcessVar3();
}

void SettingView::updateAnalogOut0()
{
    u32_channelAnalogOut0 = sliderAnalogOut0.getValue();
    auto sliderAnalog0MaxValue = sliderAnalogOut0.getMaxValue();
    auto analogOut = (maxVol / sliderAnalog0MaxValue) * u32_channelAnalogOut0;
    Unicode::snprintfFloat(textAreaAnalogOut0Buffer, TEXTAREAANALOGOUT0_SIZE, "%2.1f", static_cast<float>(analogOut));
    textAreaAnalogOut0.invalidate();
#ifndef SIMMULATION
    presenter->notifyAnalogOutputChanged_0(u32_channelAnalogOut0);
#endif // !SIMMULATION
}

void SettingView::updateAnalogOut1()
{
    u32_channelAnalogOut1 = sliderAnalogOut1.getValue();
    auto sliderAnalog1MaxValue = sliderAnalogOut1.getMaxValue();
    auto analogOut = (maxVol / sliderAnalog1MaxValue) * u32_channelAnalogOut1;
    Unicode::snprintfFloat(textAreaAnalogOut1Buffer, TEXTAREAANALOGOUT1_SIZE, "%2.1f", static_cast<float>(analogOut));
    textAreaAnalogOut1.invalidate();
#ifndef SIMMULATION
    presenter->notifyAnalogOutputChanged_1(u32_channelAnalogOut1);
#endif // !SIMMULATION
}
void SettingView::drawTextAreaFactor0()
{
    Unicode::snprintfFloat(textAreaFactor0Buffer, TEXTAREAFACTOR0_SIZE, "%4.2f", static_cast<float>(f_channelFactor0));
    textAreaFactor0.invalidate();
}
void SettingView::drawTextAreaFactor1()
{
    Unicode::snprintfFloat(textAreaFactor1Buffer, TEXTAREAFACTOR1_SIZE, "%4.2f", static_cast<float>(f_channelFactor1));
    textAreaFactor1.invalidate();
}
inline void SettingView::drawTextAreaFactor2()
{
    Unicode::snprintfFloat(textAreaFactor2Buffer, TEXTAREAFACTOR2_SIZE, "%4.2f", static_cast<float>(f_channelFactor2));
    textAreaFactor2.invalidate();
}
inline void SettingView::drawTextAreaFactor3()
{
    Unicode::snprintfFloat(textAreaFactor3Buffer, TEXTAREAFACTOR3_SIZE, "%4.2f", static_cast<float>(f_channelFactor3));
    textAreaFactor3.invalidate();
}
inline void SettingView::drawTextAreaOffset0()
{
    Unicode::snprintfFloat(textAreaOffset0Buffer, TEXTAREAOFFSET0_SIZE, "%4.2f", static_cast<float>(f_channelOffset0));
    textAreaOffset0.invalidate();
}
inline void SettingView::drawTextAreaOffset1()
{
    Unicode::snprintfFloat(textAreaOffset1Buffer, TEXTAREAOFFSET1_SIZE, "%4.2f", static_cast<float>(f_channelOffset1));
    textAreaOffset1.invalidate();
}
inline void SettingView::drawTextAreaOffset2()
{
    Unicode::snprintfFloat(textAreaOffset2Buffer, TEXTAREAOFFSET2_SIZE, "%4.2f", static_cast<float>(f_channelOffset2));
    textAreaOffset2.invalidate();
}
inline void SettingView::drawTextAreaOffset3()
{
    Unicode::snprintfFloat(textAreaOffset3Buffer, TEXTAREAOFFSET3_SIZE, "%4.2f", static_cast<float>(f_channelOffset3));
    textAreaOffset3.invalidate();
}
inline void SettingView::drawTextProcessVar0()
{
    f_channelProcessVariable0 = (f_analogChannel0 * f_channelFactor0) + f_channelOffset0;
    Unicode::snprintfFloat(textProcessVar0Buffer, TEXTPROCESSVAR0_SIZE, "%4.2f", static_cast<float>(f_channelProcessVariable0));
    textProcessVar0.invalidate();
}
inline void SettingView::drawTextProcessVar1()
{
    f_channelProcessVariable1 = (f_analogChannel1 * f_channelFactor1) + f_channelOffset1;
    Unicode::snprintfFloat(textProcessVar1Buffer, TEXTPROCESSVAR1_SIZE, "%4.2f", static_cast<float>(f_channelProcessVariable1));
    textProcessVar1.invalidate();
}
inline void SettingView::drawTextProcessVar2()
{
    f_channelProcessVariable2 = (f_analogChannel2 * f_channelFactor2) + f_channelOffset2;
    Unicode::snprintfFloat(textProcessVar2Buffer, TEXTPROCESSVAR2_SIZE, "%4.2f", static_cast<float>(f_channelProcessVariable2));
    textProcessVar2.invalidate();
}
inline void SettingView::drawTextProcessVar3()
{
    f_channelProcessVariable3 = (f_analogChannel3 * f_channelFactor3) + f_channelOffset3;
    Unicode::snprintfFloat(textProcessVar3Buffer, TEXTPROCESSVAR3_SIZE, "%4.2f", static_cast<float>(f_channelProcessVariable3));
    textProcessVar3.invalidate();
}
inline void SettingView::drawTextAdcIn0(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH0Buffer, TEXTAREACH0_SIZE, "%2.1f", adcValue);
    textAreaCH0.invalidate();
}
inline void SettingView::drawTextAdcIn1(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH1Buffer, TEXTAREACH1_SIZE, "%2.1f", adcValue);
    textAreaCH1.invalidate();
}
inline void SettingView::drawTextAdcIn2(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH2Buffer, TEXTAREACH2_SIZE, "%2.1f", adcValue);
    textAreaCH2.invalidate();
}
inline void SettingView::drawTextAdcIn3(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH3Buffer, TEXTAREACH3_SIZE, "%2.1f", adcValue);
    textAreaCH3.invalidate();
}
inline float SettingView::adcRawValueToVoltage(uint32_t adcVal) const
{
    auto vol = static_cast<float>(adcVal) / maxAdcRawVal;
    vol = vol * maxVoltage;
    return vol;
}
