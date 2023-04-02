/*
 * File: system1TimeDomainf.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 02-Apr-2023 13:07:32
 */

/* Include Files */
#include "system1TimeDomainf.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : float t
 * Return Type  : float
 */
float system1TimeDomainf(float t)
{
  return 8.0F * (float)exp(-t / 340.0F) / 29.0F - 8.0F * (float)exp(-t / 50.0F) /
    29.0F;
}

/*
 * File trailer for system1TimeDomainf.c
 *
 * [EOF]
 */
