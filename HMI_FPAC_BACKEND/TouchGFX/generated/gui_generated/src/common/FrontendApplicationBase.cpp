/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <gui/main_screen/MainView.hpp>
#include <gui/main_screen/MainPresenter.hpp>
#include <gui/setting_screen/SettingView.hpp>
#include <gui/setting_screen/SettingPresenter.hpp>
#include <gui/mesuaring_screen/MesuaringView.hpp>
#include <gui/mesuaring_screen/MesuaringPresenter.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingView.hpp>
#include <gui/closedloopsetting_screen/ClosedLoopSettingPresenter.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphView.hpp>
#include <gui/closedloopgraph_screen/ClosedLoopGraphPresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
}

/*
 * Screen Transition Declarations
 */

// Main

void FrontendApplicationBase::gotoMainScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMainScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMainScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<MainView, MainPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Setting

void FrontendApplicationBase::gotoSettingScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoSettingScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoSettingScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<SettingView, SettingPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Mesuaring

void FrontendApplicationBase::gotoMesuaringScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoMesuaringScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoMesuaringScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<MesuaringView, MesuaringPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// ClosedLoopSetting

void FrontendApplicationBase::gotoClosedLoopSettingScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoClosedLoopSettingScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoClosedLoopSettingScreenNoTransitionImpl()
{
    touchgfx::makeTransition<ClosedLoopSettingView, ClosedLoopSettingPresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoClosedLoopSettingScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoClosedLoopSettingScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoClosedLoopSettingScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<ClosedLoopSettingView, ClosedLoopSettingPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// ClosedLoopGraph

void FrontendApplicationBase::gotoClosedLoopGraphScreenCoverTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplication::gotoClosedLoopGraphScreenCoverTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoClosedLoopGraphScreenCoverTransitionEastImpl()
{
    touchgfx::makeTransition<ClosedLoopGraphView, ClosedLoopGraphPresenter, touchgfx::CoverTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}
