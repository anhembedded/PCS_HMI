/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef DIGITALOUTPUTBASE_HPP
#define DIGITALOUTPUTBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <touchgfx/containers/Container.hpp>
#include <touchgfx/containers/SlideMenu.hpp>
#include <touchgfx/widgets/ToggleButton.hpp>
#include <touchgfx/widgets/TextArea.hpp>
#include <touchgfx/widgets/Image.hpp>

class DigitalOutputBase : public touchgfx::Container
{
public:
    DigitalOutputBase();
    virtual ~DigitalOutputBase();
    virtual void initialize();

    /*
     * Virtual Action Handlers
     */
    virtual void buttonDigital0Handle()
    {
        // Override and implement this function in DigitalOutput
    }
    virtual void buttonDigital1Handle()
    {
        // Override and implement this function in DigitalOutput
    }
    virtual void buttonDigital2Handle()
    {
        // Override and implement this function in DigitalOutput
    }
    virtual void buttonDigital3Handle()
    {
        // Override and implement this function in DigitalOutput
    }
    virtual void buttonDigital4Handle()
    {
        // Override and implement this function in DigitalOutput
    }

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::SlideMenu binaryMenu;
    touchgfx::Container binaryButton;
    touchgfx::ToggleButton buttonDigital4;
    touchgfx::ToggleButton buttonDigital3;
    touchgfx::ToggleButton buttonDigital2;
    touchgfx::ToggleButton buttonDigital1;
    touchgfx::ToggleButton buttonDigital0;
    touchgfx::TextArea textArea4;
    touchgfx::TextArea textArea4_2;
    touchgfx::TextArea textArea4_2_1;
    touchgfx::TextArea textArea4_2_1_1;
    touchgfx::TextArea textArea4_1;
    touchgfx::Image image1_1;

private:

    /*
     * Callback Declarations
     */
    touchgfx::Callback<DigitalOutputBase, const touchgfx::AbstractButton&> buttonCallback;

    /*
     * Callback Handler Declarations
     */
    void buttonCallbackHandler(const touchgfx::AbstractButton& src);

};

#endif // DIGITALOUTPUTBASE_HPP
