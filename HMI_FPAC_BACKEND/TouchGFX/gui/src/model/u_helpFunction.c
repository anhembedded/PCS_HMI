#include "gui/model/u_helpFunction.h"

void diff_constructor(struct diff_type *c_this, float x, float y)
{
    c_this->x = x;
    c_this->y = y;
}

float diff_getRes(struct diff_type *c_this, float current_x, float current_y)
{
    float diff = 0;
    c_this->x_delta = current_x - c_this->x;
    c_this->y_delta = current_y - c_this->y;
    c_this->x = current_x;
    c_this->y = current_y;
    diff = (float)c_this->y_delta / c_this->x_delta;
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
    return 0.5f * (a * powf(t, 2));
}
