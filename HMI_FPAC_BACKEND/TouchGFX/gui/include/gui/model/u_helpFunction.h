#ifndef INCLUDE_GUI_MODEL_U_HELPFUNCTION
#define INCLUDE_GUI_MODEL_U_HELPFUNCTION

#include <stdint.h>
#include <math.h>


struct diff_type
{
    double var;
    float x_delta;
    float x;
    float y_delta;
    float y;
    uint32_t isFristTime;
};

void diff_constructor(struct diff_type *c_this, float x, float y);
float diff_getRes(struct diff_type *c_this, float current_x, float current_y);
float help_sinFunction(uint32_t scale, float time);
float help_uniformIncreaseSteadilyMotion(float t, float v);
float help_uniformlyAcceleratedLinearMotion(float t, float a);
/* Control system nise, page 64 */
float help_systemOneEquationOfMotion(float x,float diff1,float diff2, float t);
#endif /* INCLUDE_GUI_MODEL_U_HELPFUNCTION */
