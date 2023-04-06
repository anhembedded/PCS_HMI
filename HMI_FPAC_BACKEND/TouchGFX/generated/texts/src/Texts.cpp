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
    0x46, 0x65, 0x65, 0x64, 0x62, 0x61, 0x63, 0x6b, 0x3a, 0x20, 0x2, 0x0, // @87 "Feedback: <>"
    0x43, 0x68, 0x2e, 0x30, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @99 "Ch.0:  <> V"
    0x43, 0x68, 0x2e, 0x31, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @110 "Ch.1:  <> V"
    0x43, 0x68, 0x2e, 0x32, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @121 "Ch.2:  <> V"
    0x43, 0x68, 0x2e, 0x33, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @132 "Ch.3:  <> V"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x30, 0x0, // @143 "Digital Output 0"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x31, 0x0, // @160 "Digital Output 1"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x32, 0x0, // @177 "Digital Output 2"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x33, 0x0, // @194 "Digital Output 3"
    0x44, 0x69, 0x67, 0x69, 0x74, 0x61, 0x6c, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x34, 0x0, // @211 "Digital Output 4"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x31, 0x0, // @228 "Analog Output 1"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x20, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x32, 0x0, // @244 "Analog Output 2"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x43, 0x68, 0x61, 0x6e, 0x6e, 0x65, 0x6c, 0x0, // @260 "AnalogChannel"
    0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x20, 0x50, 0x61, 0x6e, 0x65, 0x6c, 0x0, // @274 "Control Panel"
    0x6b, 0x50, 0x3a, 0x20, 0x2, 0x0, // @288 "kP: <>"
    0x74, 0x4e, 0x3a, 0x20, 0x2, 0x0, // @294 "tN: <>"
    0x76, 0x54, 0x3a, 0x20, 0x2, 0x0, // @300 "vT: <>"
    0x20, 0x2, 0x20, 0x25, 0x0, // @306 " <> %"
    0x43, 0x6c, 0x65, 0x61, 0x72, 0x47, 0x72, 0x61, 0x70, 0x68, 0x0, // @311 "ClearGraph"
    0x50, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x56, 0x61, 0x72, 0x0, // @322 "ProcessVar"
    0x2, 0x20, 0x53, 0x0, // @333 "<> S"
    0x52, 0x65, 0x63, 0x6f, 0x72, 0x64, 0x69, 0x6e, 0x67, 0x0, // @337 "Recording"
    0x61, 0x63, 0x74, 0x75, 0x61, 0x74, 0x6f, 0x72, 0x0, // @347 "actuator"
    0x43, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x0, // @356 "Confirm"
    0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x3a, 0x0, // @364 "Output:"
    0x30, 0x30, 0x30, 0x2e, 0x30, 0x30, 0x0, // @372 "000.00"
    0x46, 0x61, 0x63, 0x74, 0x6f, 0x72, 0x0, // @379 "Factor"
    0x4f, 0x66, 0x66, 0x73, 0x65, 0x74, 0x0, // @386 "Offset"
    0x45, 0x6e, 0x74, 0x65, 0x72, 0x0, // @393 "Enter"
    0x53, 0x74, 0x61, 0x72, 0x74, 0x0, // @399 "Start"
    0x30, 0x30, 0x2e, 0x30, 0x0, // @405 "00.0"
    0x31, 0x2e, 0x30, 0x30, 0x0, // @410 "1.00"
    0x53, 0x74, 0x6f, 0x70, 0x0, // @415 "Stop"
    0x30, 0x30, 0x30, 0x0, // @420 "000"
    0x41, 0x49, 0x30, 0x0, // @424 "AI0"
    0x41, 0x49, 0x31, 0x0, // @428 "AI1"
    0x41, 0x49, 0x32, 0x0, // @432 "AI2"
    0x41, 0x49, 0x33, 0x0, // @436 "AI3"
    0x41, 0x4f, 0x30, 0x0, // @440 "AO0"
    0x41, 0x4f, 0x31, 0x0, // @444 "AO1"
    0x4f, 0x75, 0x74, 0x0, // @448 "Out"
    0x52, 0x75, 0x6e, 0x0, // @452 "Run"
    0x53, 0x65, 0x74, 0x0, // @456 "Set"
    0x20, 0x36, 0x0, // @460 " 6"
    0x31, 0x30, 0x0, // @463 "10"
    0x2e, 0x0, // @466 "."
    0x35, 0x0, // @468 "5"
    0x37, 0x0, // @470 "7"
    0x38, 0x0, // @472 "8"
    0x39, 0x0, // @474 "9"
    0x3c, 0x0 // @476 "<"
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
