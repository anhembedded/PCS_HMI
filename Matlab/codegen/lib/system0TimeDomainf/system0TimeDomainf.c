/*
 * File: system0TimeDomainf.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 02-Apr-2023 14:33:49
 */

/* Include Files */
#include "system0TimeDomainf.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : float timeVar
 *                float inputVar
 * Return Type  : float
 */
float system0TimeDomainf(float timeVar, float inputVar)
{
  float outputArg1_tmp;
  outputArg1_tmp = 6.70820427F * timeVar / 2.0F;
  return inputVar - inputVar * (float)exp(-(9.0F * timeVar) / 2.0F) * ((float)
    cosh(outputArg1_tmp) + 6.70820427F * (float)sinh(outputArg1_tmp) / 5.0F);
}

/*
 * File trailer for system0TimeDomainf.c
 *
 * [EOF]
 */
