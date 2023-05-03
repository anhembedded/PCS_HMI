#include <gui/dev_screen/DevView.hpp>

DevView::DevView()
{
    diff_constructor(&this->diffVar, 0, 0);
    diff_constructor(&this->diffVar2, 0, 0);
}

void DevView::setupScreen()
{
    DevViewBase::setupScreen();
}

void DevView::tearDownScreen()
{

    DevViewBase::tearDownScreen();
}

void DevView::handleTickEvent()
{
    float diff_var = 0.0F;;
    float diff_var2 = 0.0F;;
    float y = 0.0F;
    mathTick = mathTick + 0.01F;

    if (isRun == whichFunction_type::run)
    {
        if (whichFunction == whichFunction_type::sine)
        {
            y = help_sinFunction(5, mathTick);
        }
        else if (whichFunction == whichFunction_type::increase)
        {
            y = help_uniformIncreaseSteadilyMotion(mathTick, 3.F);
        }
        else if(whichFunction == whichFunction_type::accelerated)
        {
            y = help_uniformlyAcceleratedLinearMotion(mathTick, 4.F);
        }

        diff_var = diff_getRes(&this->diffVar, mathTick, y);
        diff_var2 = diff_getRes(&this->diffVar2, mathTick, diff_var);

        graphS.addDataPoint(y);
        graphV.addDataPoint(diff_var);
        graphA.addDataPoint(diff_var2);
    }
    else
    {
        reinitFunction();
    }
   
   
}
