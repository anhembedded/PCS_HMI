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
    0x43, 0x68, 0x2e, 0x30, 0x20, 0x3a, 0x20, 0x4c, 0x65, 0x76, 0x65, 0x6c, 0xa, 0x43, 0x68, 0x2e, 0x31, 0x3a, 0x20, 0x46, 0x6c, 0x6f, 0x77, 0x20, 0x72, 0x61, 0x74, 0x65, 0xa, 0x43, 0x68, 0x2e, 0x32, 0x3a, 0x20, 0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0xa, 0x43, 0x68, 0x2e, 0x33, 0x3a, 0x20, 0x54, 0x65, 0x6d, 0x70, 0x65, 0x72, 0x61, 0x74, 0x75, 0x72, 0x65, 0x0, // @0 "Ch.0 : Level\nCh.1: Flow rate\nCh.2: Pressure\nCh.3: Temperature"
    0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x30, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x31, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x32, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x33, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x34, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x35, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x36, 0x3a, 0x0, // @62 "D.In.0:\nD.In.1:\nD.In.2:\nD.In.3:\nD.In.4:\nD.In.5:\nD.In.6:"
    0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x30, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x31, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x32, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x33, 0x3a, 0xa, 0x44, 0x2e, 0x49, 0x6e, 0x2e, 0x34, 0x3a, 0x0, // @118 "D.In.0:\nD.In.1:\nD.In.2:\nD.In.3:\nD.In.4:"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x2e, 0x30, 0x3a, 0x20, 0x50, 0x75, 0x6d, 0x70, 0xa, 0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x2e, 0x30, 0x3a, 0x20, 0x4c, 0x69, 0x6e, 0x65, 0x61, 0x72, 0x20, 0x76, 0x61, 0x6c, 0x76, 0x65, 0x0, // @158 "Analog.0: Pump\nAnalog.0: Linear valve"
    0x43, 0x6c, 0x6f, 0x73, 0x65, 0x64, 0x2d, 0x6c, 0x6f, 0x6f, 0x70, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x72, 0x6f, 0x6c, 0x20, 0x43, 0x6f, 0x6e, 0x74, 0x69, 0x6e, 0x75, 0x6f, 0x75, 0x73, 0x0, // @196 "Closed-loop Control Continuous"
    0x110, 0x69, 0x1ec1, 0x75, 0x20, 0x4b, 0x68, 0x69, 0x1ec3, 0x6e, 0x20, 0x76, 0xf2, 0x6e, 0x67, 0x20, 0x6b, 0xed, 0x6e, 0x20, 0x50, 0x49, 0x44, 0x0, // @227 "?i?u Khi?n v?ng k?n PID"
    0x20, 0x53, 0x65, 0x74, 0x20, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x3a, 0x20, 0x2, 0x0, // @251 " Set point: <>"
    0x4b, 0xea, 0x6e, 0x68, 0x2e, 0x30, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @265 "K?nh.0:  <> V"
    0x4b, 0xea, 0x6e, 0x68, 0x2e, 0x31, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @278 "K?nh.1:  <> V"
    0x4b, 0xea, 0x6e, 0x68, 0x2e, 0x32, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @291 "K?nh.2:  <> V"
    0x4b, 0xea, 0x6e, 0x68, 0x2e, 0x33, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @304 "K?nh.3:  <> V"
    0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x3a, 0x20, 0x30, 0x2e, 0x31, 0x73, 0x0, // @317 "Sampler Time: 0.1s"
    0x46, 0x65, 0x65, 0x64, 0x62, 0x61, 0x63, 0x6b, 0x3a, 0x20, 0x2, 0x0, // @336 "Feedback: <>"
    0x53, 0x61, 0x6d, 0x70, 0x6c, 0x65, 0x72, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x3a, 0x20, 0x30, 0x2e, 0x31, 0x0, // @348 "Sampler Time: 0.1"
    0x54, 0x72, 0x61, 0x63, 0x69, 0x6e, 0x67, 0x20, 0x54, 0x69, 0x6d, 0x65, 0x3a, 0x20, 0x36, 0x30, 0x73, 0x0, // @366 "Tracing Time: 60s"
    0x43, 0x68, 0x2e, 0x30, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @384 "Ch.0:  <> V"
    0x43, 0x68, 0x2e, 0x31, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @395 "Ch.1:  <> V"
    0x43, 0x68, 0x2e, 0x32, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @406 "Ch.2:  <> V"
    0x43, 0x68, 0x2e, 0x33, 0x3a, 0x20, 0x20, 0x2, 0x20, 0x56, 0x0, // @417 "Ch.3:  <> V"
    0x41, 0x6e, 0x61, 0x6c, 0x6f, 0x67, 0x43, 0x68, 0x61, 0x6e, 0x6e, 0x65, 0x6c, 0x0, // @428 "AnalogChannel"
    0x41, 0x6e, 0x68, 0x2e, 0x45, 0x6d, 0x62, 0x65, 0x64, 0x64, 0x65, 0x64, 0x0, // @442 "Anh.Embedded"
    0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x2e, 0x30, 0x30, 0x0, // @455 "00000000.00"
    0x6b, 0x44, 0x3a, 0x20, 0x2, 0x0, // @467 "kD: <>"
    0x6b, 0x49, 0x3a, 0x20, 0x2, 0x0, // @473 "kI: <>"
    0x6b, 0x50, 0x3a, 0x20, 0x2, 0x0, // @479 "kP: <>"
    0x50, 0x72, 0x6f, 0x63, 0x65, 0x73, 0x73, 0x56, 0x61, 0x72, 0x0, // @485 "ProcessVar"
    0x46, 0x6c, 0x6f, 0x77, 0x20, 0x72, 0x61, 0x74, 0x65, 0x0, // @496 "Flow rate"
    0x4c, 0x1b0, 0x75, 0x20, 0x6c, 0x1b0, 0x1ee3, 0x6e, 0x67, 0x0, // @506 "L?u l??ng"
    0x41, 0x63, 0x74, 0x75, 0x61, 0x74, 0x6f, 0x72, 0x0, // @516 "Actuator"
    0x4d, 0x1ee9, 0x63, 0x20, 0x6e, 0x1b0, 0x1edb, 0x63, 0x0, // @525 "M?c n??c"
    0x4e, 0x68, 0x69, 0x1ec7, 0x74, 0x20, 0x111, 0x1ed9, 0x0, // @534 "Nhi?t ??"
    0x50, 0x72, 0x65, 0x73, 0x73, 0x75, 0x72, 0x65, 0x0, // @543 "Pressure"
    0x53, 0x65, 0x74, 0x50, 0x6f, 0x69, 0x6e, 0x74, 0x0, // @552 "SetPoint"
    0x58, 0xe1, 0x63, 0x20, 0x6e, 0x68, 0x1ead, 0x6e, 0x0, // @561 "X?c nh?n"
    0x110, 0x69, 0x1ec3, 0x6d, 0x20, 0x111, 0x1eb7, 0x63, 0x0, // @570 "?i?m ??c"
    0x43, 0x6f, 0x6e, 0x66, 0x69, 0x72, 0x6d, 0x0, // @579 "Confirm"
    0x43, 0xe0, 0x69, 0x20, 0x111, 0x1eb7, 0x74, 0x0, // @587 "C?i ??t"
    0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x3a, 0x0, // @595 "Output:"
    0xc1, 0x70, 0x20, 0x73, 0x75, 0x1ea5, 0x74, 0x0, // @603 "?p su?t"
    0x46, 0x61, 0x63, 0x74, 0x6f, 0x72, 0x0, // @611 "Factor"
    0x4f, 0x66, 0x66, 0x73, 0x65, 0x74, 0x0, // @618 "Offset"
    0x43, 0x6c, 0x65, 0x61, 0x72, 0x0, // @625 "Clear"
    0x45, 0x6e, 0x74, 0x65, 0x72, 0x0, // @631 "Enter"
    0x4c, 0x65, 0x76, 0x65, 0x6c, 0x0, // @637 "Level"
    0x53, 0x74, 0x61, 0x72, 0x74, 0x0, // @643 "Start"
    0x30, 0x30, 0x2e, 0x30, 0x0, // @649 "00.0"
    0x43, 0x68, 0x1ea1, 0x79, 0x0, // @654 "Ch?y"
    0x44, 0x6f, 0x6e, 0x65, 0x0, // @659 "Done"
    0x44, 0x1eeb, 0x6e, 0x67, 0x0, // @664 "D?ng"
    0x53, 0x74, 0x6f, 0x70, 0x0, // @669 "Stop"
    0x53, 0x65, 0x74, 0x0, // @674 "Set"
    0x58, 0xf3, 0x61, 0x0, // @678 "X?a"
    0x20, 0x36, 0x0, // @682 " 6"
    0x31, 0x30, 0x0, // @685 "10"
    0x4b, 0x64, 0x0, // @688 "Kd"
    0x4b, 0x69, 0x0, // @691 "Ki"
    0x4b, 0x70, 0x0, // @694 "Kp"
    0x4f, 0x4b, 0x0, // @697 "OK"
    0x2e, 0x0, // @700 "."
    0x32, 0x0, // @702 "2"
    0x33, 0x0, // @704 "3"
    0x34, 0x0, // @706 "4"
    0x35, 0x0, // @708 "5"
    0x37, 0x0, // @710 "7"
    0x38, 0x0, // @712 "8"
    0x39, 0x0, // @714 "9"
    0x3c, 0x0 // @716 "<"
};

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesGb[] TEXT_LOCATION_FLASH_ATTRIBUTE;

TEXT_LOCATION_FLASH_PRAGMA
KEEP extern const uint32_t indicesVietnamese[] TEXT_LOCATION_FLASH_ATTRIBUTE;

// Array holding dynamically installed languages
struct TranslationHeader
{
    uint32_t offset_to_texts;
    uint32_t offset_to_indices;
    uint32_t offset_to_typedtext;
};
static const TranslationHeader* languagesArray[2] = { 0 };

// Compiled and linked in languages
static const uint32_t* const staticLanguageIndices[] = {
    indicesGb,
    indicesVietnamese
};

touchgfx::LanguageId touchgfx::Texts::currentLanguage = static_cast<touchgfx::LanguageId>(0);
static const touchgfx::Unicode::UnicodeChar* currentLanguagePtr = 0;
static const uint32_t* currentLanguageIndices = 0;

void touchgfx::Texts::setLanguage(touchgfx::LanguageId id)
{
    const touchgfx::TypedText::TypedTextData* currentLanguageTypedText = 0;
    if (id < 2)
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
