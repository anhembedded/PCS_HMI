/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <stdarg.h>
#include <touchgfx/TextProvider.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/TypedText.hpp>
#include <touchgfx/Unicode.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <touchgfx/lcd/LCD.hpp>
#include <texts/TypedTextDatabase.hpp>

uint16_t touchgfx::Font::getStringWidth(const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(TEXT_DIRECTION_LTR, text, pArg);
    va_end(pArg);
    return width;
}

uint16_t touchgfx::Font::getStringWidth(touchgfx::TextDirection textDirection, const touchgfx::Unicode::UnicodeChar* text, ...) const
{
    va_list pArg;
    va_start(pArg, text);
    uint16_t width = getStringWidthLTR(textDirection, text, pArg);
    va_end(pArg);
    return width;
}

touchgfx::Unicode::UnicodeChar touchgfx::TextProvider::getNextLigature(TextDirection direction)
{
    if (fontGsubTable && nextCharacters.peekChar())
    {
        substituteGlyphs();
        if (nextCharacters.peekChar(1) == 0x093F) // Hindi I-matra
        {
            nextCharacters.replaceAt1(nextCharacters.peekChar());
            nextCharacters.replaceAt0(0x093F);
        }
    }
    return getNextChar();
}

void touchgfx::TextProvider::initializeInternal()
{
    fillInputBuffer();
}

void touchgfx::LCD::drawString(touchgfx::Rect widgetArea, const touchgfx::Rect& invalidatedArea, const touchgfx::LCD::StringVisuals& stringVisuals, const touchgfx::Unicode::UnicodeChar* format, ...)
{
    va_list pArg;
    va_start(pArg, format);
    drawStringLTR(widgetArea, invalidatedArea, stringVisuals, format, pArg);
    va_end(pArg);
}

// Default TypedTextDatabase
extern const touchgfx::TypedText::TypedTextData* const typedTextDatabaseArray[];

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const touchgfx::Unicode::UnicodeChar texts_all_languages[] TEXT_LOCATION_FLASH_ATTRIBUTE = {
    0x43, 0x6c, 0x6f, 0x73, 0x65, 0x64, 0x2d, 0x6c, 0x6f, 0x6f, 0x70, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6e, 0x75, 0x6f, 0x75, 0x73, 0x0, // @0 "Closed-loop Control Continuous"
    0x4d, 0x65, 0x73, 0x75, 0x61, 0x72, 0x69, 0x6e, 0x67, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x0, // @31 "Mesuaring and Control"
    0x20, 0x53, 0x65, 0x74, 0x20, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x3a, 0x20, 0x2, 0x0, // @53 " Set point: <>"
    0x53, 0x65, 0x6c, 0x65, 0x63, 0x74, 0x20, 0x6d, 0x61, 0x6e, 0x69, 0x70, 0x2e, 0x20, 0x56, 0x61, 0x6c, 0x75, 0x65, 0x0, // @67 "Select manip. Value"
    0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x3a, 0x20, 0x30, 0x2e, 0x31, 0x73, 0x0, // @87 "Sampler Time: 0.1s"
    0x46, 0x65, 0x65, 0x64, 0x62, 0x61, 0x63, 0x6b, 0x3a, 0x20, 0x2, 0x0, // @106 "Feedback: <>"
    0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x3a, 0x20, 0x30, 0x2e, 0x31, 0x0, // @118 "Sampler Time: 0.1"
    0x54, 0x72, 0x61, 0x63, 0x69, 0x6e, 0x67, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x3a, 0x20, 0x36, 0x30, 0x73, 0x0, // @136 "Tracing Time: 60s"
    0x43, 0x68, 0x2e, 0x30, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @154 "Ch.0:  <> V"
    0x43, 0x68, 0x2e, 0x31, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @165 "Ch.1:  <> V"
    0x43, 0x68, 0x2e, 0x32, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @176 "Ch.2:  <> V"
    0x43, 0x68, 0x2e, 0x33, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @187 "Ch.3:  <> V"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x30, 0x0, // @198 "Digital Output 0"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x31, 0x0, // @215 "Digital Output 1"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x32, 0x0, // @232 "Digital Output 2"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x33, 0x0, // @249 "Digital Output 3"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x34, 0x0, // @266 "Digital Output 4"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x31, 0x0, // @283 "Analog Output 1"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x32, 0x0, // @299 "Analog Output 2"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x43, 0x68, 0x61, 0x6e, 0x6e, 0x65, 0x6c, 0x0, // @315 "AnalogChannel"
    0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x20, 0x50, 0x61, 0x6e, 0x65, 0x6c, 0x0, // @329 "Control Panel"
    0x41, 0x6e, 0x68, 0x2e, 0x45, 0x6d, 0x62, 0x65, 0x64, 0x64, 0x65, 0x64, 0x0, // @343 "Anh.Embedded"
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x2e, 0x30, 0x30, 0x0, // @356 "00000000.00"
    0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x0, // @368 "Temperature"
    0x6b, 0x44, 0x3a, 0x20, 0x2, 0x0, // @380 "kD: <>"
    0x6b, 0x49, 0x3a, 0x20, 0x2, 0x0, // @386 "kI: <>"
    0x6b, 0x50, 0x3a, 0x20, 0x2, 0x0, // @392 "kP: <>"
    0x20, 0x2, 0x20, 0x25, 0x0, // @398 " <> %"
    0x43, 0x6c, 0x65, 0x61, 0x72, 0x47, 0x72, 0x61, 0x70, 0x68, 0x0, // @403 "ClearGraph"
    0x50, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x56, 0x61, 0x72, 0x0, // @414 "ProcessVar"
    0x2, 0x20, 0x53, 0x0, // @425 "<> S"
    0x46, 0x6c, 0x6f, 0x77, 0x20, 0x72, 0x61, 0x74, 0x65, 0x0, // @429 "Flow rate"
    0x52, 0x65, 0x63, 0x6f, 0x72, 0x64, 0x69, 0x6e, 0x67, 0x0, // @439 "Recording"
    0x41, 0x63, 0x74, 0x75, 0x61, 0x74, 0x6f, 0x72, 0x0, // @449 "Actuator"
    0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, // @458 "Pressure"
    0x53, 0x65, 0x74, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x0, // @467 "SetPoint"
    0x43, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x0, // @476 "Confirm"
    0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x3a, 0x0, // @484 "Output:"
    0x46, 0x61, 0x63, 0x74, 0x6f, 0x72, 0x0, // @492 "Factor"
    0x4f, 0x66, 0x66, 0x73, 0x65, 0x74, 0x0, // @499 "Offset"
    0x43, 0x6c, 0x65, 0x61, 0x72, 0x0, // @506 "Clear"
    0x45, 0x6e, 0x74, 0x65, 0x72, 0x0, // @512 "Enter"
    0x4c, 0x65, 0x76, 0x65, 0x6c, 0x0, // @518 "Level"
    0x53, 0x74, 0x61, 0x72, 0x74, 0x0, // @524 "Start"
    0x30, 0x30, 0x2e, 0x30, 0x0, // @530 "00.0"
    0x31, 0x2e, 0x30, 0x30, 0x0, // @535 "1.00"
    0x53, 0x74, 0x6f, 0x70, 0x0, // @540 "Stop"
    0x30, 0x30, 0x30, 0x0, // @545 "000"
    0x41, 0x49, 0x30, 0x0, // @549 "AI0"
    0x41, 0x49, 0x31, 0x0, // @553 "AI1"
    0x41, 0x49, 0x32, 0x0, // @557 "AI2"
    0x41, 0x49, 0x33, 0x0, // @561 "AI3"
    0x41, 0x4f, 0x30, 0x0, // @565 "AO0"
    0x41, 0x4f, 0x31, 0x0, // @569 "AO1"
    0x4f, 0x75, 0x74, 0x0, // @573 "Out"
    0x52, 0x75, 0x6e, 0x0, // @577 "Run"
    0x53, 0x65, 0x74, 0x0, // @581 "Set"
    0x20, 0x36, 0x0, // @585 " 6"
    0x31, 0x30, 0x0, // @588 "10"
    0x4b, 0x64, 0x0, // @591 "Kd"
    0x4b, 0x69, 0x0, // @594 "Ki"
    0x4b, 0x70, 0x0, // @597 "Kp"
    0x2e, 0x0, // @600 "."
    0x35, 0x0, // @602 "5"
    0x37, 0x0, // @604 "7"
    0x38, 0x0, // @606 "8"
    0x39, 0x0, // @608 "9"
    0x3c, 0x0 // @610 "<"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[1] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 1)
    {
        if (languagesArray[id] != 0)
        {
            // Dynamic translation is added
            const TranslationHeader* translation = languagesArray[id];
            currentLanguagePtr = (const touchgfx::Unicode::UnicodeChar*)(((const uint8_t*)translation) + translation->offset_to_texts);
            currentLanguageIndices = (const uint32_t*)(((const uint8_t*)translation) + translation->offset_to_indices);
            currentLanguageTypedText = (const touchgfx::TypedText::TypedTextData*)(((const uint8_t*)translation) + translation->offset_to_typedtext);
        }
        else
        {
            // Compiled and linked in languages
            currentLanguagePtr = texts_all_languages;
            currentLanguageIndices = staticLanguageIndices[id];
            currentLanguageTypedText = typedTextDatabaseArray[id];
        }
    }

    if (currentLanguageTypedText)
    {
        currentLanguage = id;
        touchgfx::TypedText::registerTypedTextDatabase(currentLanguageTypedText,
                                                       TypedTextDatabase::getFonts(), TypedTextDatabase::getInstanceSize());
    }
}

void touchgfx::Texts::setTranslation(touchgfx::LanguageId id, const void* translation)
{
    languagesArray[id] = (const TranslationHeader*)translation;
}

const touchgfx::Unicode::UnicodeChar* touchgfx::Texts::getText(TypedTextId id) const
{
    return &currentLanguagePtr[currentLanguageIndices[id]];
}
