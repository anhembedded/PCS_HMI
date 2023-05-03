#include <gui/setting_screen/SettingView.hpp>
#include <touchgfx/Color.hpp>

SettingView::SettingView() : u32_channelAnalogOut0(0u),
                             u32_channelAnalogOut1(0u)
{
}

void SettingView::setupScreen()
{
    SettingViewBase::setupScreen();
    settingVar = presenter->getSettingVar();
}

void SettingView::tearDownScreen()
{
    SettingViewBase::tearDownScreen();
}

void SettingView::handleTickEvent()
{

#ifdef SIMULATOR

    this->tick++;

    this->analogIn = getAnalogIn();
    this->digitalInput = getDigitalIn();
    drawTextAdcIn0(analogIn.getAnalogValueFloat(0));
    drawTextAdcIn1(analogIn.getAnalogValueFloat(1));
    drawTextAdcIn2(analogIn.getAnalogValueFloat(2));
    drawTextAdcIn3(analogIn.getAnalogValueFloat(3));

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

    for (uint8_t i = 0; i <= 6; i++)
    {
        drawDigitalIn(i, digitalInput.u8_digiIn.at(i));
    }

#endif // ! SIMULATOR
}

inline void SettingView::buttonTextFactor0ClickHandle()
{

    keyboard1.callKeyboard(&settingVar.f_factor[0], TEXTAREAFACTOR0_SIZE);
}

inline void SettingView::buttonTextFactor1ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_factor[1], TEXTAREAFACTOR1_SIZE);
}

inline void SettingView::buttonTextFactor2ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_factor[2], TEXTAREAFACTOR2_SIZE);
}

inline void SettingView::buttonTextFactor3ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_factor[3], TEXTAREAFACTOR3_SIZE);
}

inline void SettingView::buttonTextOffset0ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[0], TEXTAREAOFFSET0_SIZE);
}

inline void SettingView::buttonTextOffset1ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[1], TEXTAREAOFFSET1_SIZE);
}

inline void SettingView::buttonTextOffset2ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[2], TEXTAREAOFFSET2_SIZE);
}

inline void SettingView::buttonTextOffset3ClickHandle()
{
    keyboard1.callKeyboard(&settingVar.f_offset[3], TEXTAREAOFFSET3_SIZE);
}

void SettingView::sliderAnalogOutHandle0(int value)
{
    updateAnalogOut0();
}
void SettingView::sliderAnalogOutHandle1(int value)
{
    updateAnalogOut1();
}
void SettingView::button_confirm_ClickHandle()
{
    presenter->setSettingVar(this->settingVar);
}
void SettingView::setADC(std::array<uint32_t, 4> arrayParameters)
{

    drawTextAdcIn0(analogIn.getAnalogValueFloat(0));
    drawTextAdcIn1(analogIn.getAnalogValueFloat(1));
    drawTextAdcIn2(analogIn.getAnalogValueFloat(2));
    drawTextAdcIn3(analogIn.getAnalogValueFloat(3));

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
analogIn_type SettingView::getAnalogIn()
{
    return presenter->getAnalogIn();
}
void SettingView::drawTextAreaFactor0()
{
    Unicode::snprintfFloat(textAreaFactor0Buffer, TEXTAREAFACTOR0_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[0]));
    textAreaFactor0.invalidate();
}
void SettingView::drawTextAreaFactor1()
{
    Unicode::snprintfFloat(textAreaFactor1Buffer, TEXTAREAFACTOR1_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[1]));
    textAreaFactor1.invalidate();
}
inline void SettingView::drawTextAreaFactor2()
{
    Unicode::snprintfFloat(textAreaFactor2Buffer, TEXTAREAFACTOR2_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[2]));
    textAreaFactor2.invalidate();
}
inline void SettingView::drawTextAreaFactor3()
{
    Unicode::snprintfFloat(textAreaFactor3Buffer, TEXTAREAFACTOR3_SIZE, "%4.2f", static_cast<float>(settingVar.f_factor[3]));
    textAreaFactor3.invalidate();
}
inline void SettingView::drawTextAreaOffset0()
{
    Unicode::snprintfFloat(textAreaOffset0Buffer, TEXTAREAOFFSET0_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[0]));
    textAreaOffset0.invalidate();
}
inline void SettingView::drawTextAreaOffset1()
{
    Unicode::snprintfFloat(textAreaOffset1Buffer, TEXTAREAOFFSET1_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[1]));
    textAreaOffset1.invalidate();
}
inline void SettingView::drawTextAreaOffset2()
{
    Unicode::snprintfFloat(textAreaOffset2Buffer, TEXTAREAOFFSET2_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[2]));
    textAreaOffset2.invalidate();
}
inline void SettingView::drawTextAreaOffset3()
{
    Unicode::snprintfFloat(textAreaOffset3Buffer, TEXTAREAOFFSET3_SIZE, "%4.2f", static_cast<float>(settingVar.f_offset[3]));
    textAreaOffset3.invalidate();
}
inline void SettingView::drawTextProcessVar0()
{

    auto analogFloat = analogIn.getAnalogValueFloat(0);
    auto processVar = settingVar.getProcessValue(0, analogFloat);
    Unicode::snprintfFloat(textProcessVar0Buffer, TEXTPROCESSVAR0_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar0.invalidate();
}
inline void SettingView::drawTextProcessVar1()
{

    auto analogFloat = analogIn.getAnalogValueFloat(1);
    auto processVar = settingVar.getProcessValue(1, analogFloat);
    Unicode::snprintfFloat(textProcessVar1Buffer, TEXTPROCESSVAR1_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar1.invalidate();
}
inline void SettingView::drawTextProcessVar2()
{

    auto analogFloat = analogIn.getAnalogValueFloat(2);
    auto processVar = settingVar.getProcessValue(2, analogFloat);
    Unicode::snprintfFloat(textProcessVar2Buffer, TEXTPROCESSVAR2_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar2.invalidate();
}
inline void SettingView::drawTextProcessVar3()
{

    auto analogFloat = analogIn.getAnalogValueFloat(3);
    auto processVar = settingVar.getProcessValue(3, analogFloat);
    Unicode::snprintfFloat(textProcessVar3Buffer, TEXTPROCESSVAR3_SIZE, "%4.2f", static_cast<float>(processVar));
    textProcessVar3.invalidate();
}
void SettingView::drawTextFloat(decltype(textAreaFactor1Buffer) textBuffer, decltype(TEXTAREAFACTOR1_SIZE) textBufferSize, decltype("%4.2f") textFormat, decltype(textAreaFactor0) textObject, float number)
{
    Unicode::snprintfFloat(textBuffer, textBufferSize, textFormat, number);
    textObject.invalidate();
}
inline void SettingView::drawTextAdcIn0(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH0Buffer, TEXTAREACH0_SIZE, "%2.2f", adcValue);
    textAreaCH0.invalidate();
}
inline void SettingView::drawTextAdcIn1(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH1Buffer, TEXTAREACH1_SIZE, "%2.2f", adcValue);
    textAreaCH1.invalidate();
}
inline void SettingView::drawTextAdcIn2(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH2Buffer, TEXTAREACH2_SIZE, "%2.2f", adcValue);
    textAreaCH2.invalidate();
}
inline void SettingView::drawTextAdcIn3(float adcValue)
{
    Unicode::snprintfFloat(textAreaCH3Buffer, TEXTAREACH3_SIZE, "%2.2f", adcValue);
    textAreaCH3.invalidate();
}
void SettingView::drawDigitalIn(uint8_t index, uint8_t state)
{
    if (index == 0)
    {
        digitalInputIndicator1.drawDigtalInputState(static_cast<uint8_t>(0), static_cast<uint8_t>(state));
    }
    else if (index == 1)
    {
        digitalInputIndicator1.drawDigtalInputState(static_cast<uint8_t>(1), static_cast<uint8_t>(state));
    }
    else if (index == 2)
    {
        digitalInputIndicator1.drawDigtalInputState(static_cast<uint8_t>(2), static_cast<uint8_t>(state));
    }
    else if (index == 3)
    {
        digitalInputIndicator1.drawDigtalInputState(static_cast<uint8_t>(3), static_cast<uint8_t>(state));
    }
    else if (index == 4)
    {
        digitalInputIndicator1.drawDigtalInputState(static_cast<uint8_t>(4), static_cast<uint8_t>(state));
    }
    else if (index == 5)
    {
        digitalInputIndicator1.drawDigtalInputState(static_cast<uint8_t>(5), static_cast<uint8_t>(state));
    }
    else if (index == 6)
    {
        digitalInputIndicator1.drawDigtalInputState(static_cast<uint8_t>(6), static_cast<uint8_t>(state));
    }
}
inline float SettingView::adcRawValueToVoltage(uint32_t adcVal) const
{
    auto vol = static_cast<float>(adcVal) / maxAdcRawVal;
    vol = vol * maxVoltage;
    return vol;
}

inline digitalIn_type SettingView::getDigitalIn()
{
    return this->digitalInput = presenter->getDigitalIn();
}

inline void SettingView::setDigitalOut(digitaOut_type digiOut)
{
    presenter->setDigitalOut(digiOut);
}

inline digitaOut_type SettingView::getDigitalOut()
{
    return presenter->getDigitalOut();
}
