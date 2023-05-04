#include "gui/model/u_helpFunction.h"

void diff_constructor(struct diff_type *c_this, float x, float y)
{
    c_this->x = x;
    c_this->y = y;
    c_this->isFristTime = 1U;
}

float diff_getRes(struct diff_type *c_this, float current_x, float current_y)
{
    float diff = 0.F;
    if (c_this->isFristTime == 0.F)
    {
        c_this->x_delta = current_x - c_this->x;
        c_this->y_delta = current_y - c_this->y;
        c_this->x = current_x;
        c_this->y = current_y;
        diff = (float)c_this->y_delta / c_this->x_delta;
    }
    else
    {
        c_this->x = current_x;
        c_this->y = current_y;
        c_this->isFristTime = 0U;
        diff = 0.F;
    }
   
    return diff;
}

float help_sinFunction(uint32_t scale, float time)
{
    return (scale * sinf(time));
}

float help_uniformIncreaseSteadilyMotion(float t, float v)
{
    /* S = t * v */
    return t * v;
}

float help_uniformlyAcceleratedLinearMotion(float t, float a)
{
    /* S = 0.5 * (a* pow(t,2)) */
    return 0.5F * (a * powf(t, 2));
}

/* Control system nise, page 64 */
float help_systemOneEquationOfMotion(float x, float diff1, float diff2, float t)
{
    const float M = 0.05F; // 5Kg
    const float Fv = 1.5F; // 3
    const float K = 2.F; // 4
    return (M * diff2 + Fv * diff1 + K*x);
}
