/*
 * File: system0TimeDomainf.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2023 08:40:05
 */

/* Include Files */
#include "system0TimeDomainf.h"
#include <math.h>

/* Function Definitions */

/*
 * Arguments    : double timeVar
 *                double pidOut
 * Return Type  : double
 */
double system0TimeDomainf(double timeVar, double pidOut)
{
  double systemOut_tmp;
  systemOut_tmp = 6.7082039324993694 * timeVar / 2.0;
  return pidOut - pidOut * exp(-(9.0 * timeVar) / 2.0) * (cosh(systemOut_tmp) +
    6.7082039324993694 * sinh(systemOut_tmp) / 5.0);
}

/*
 * File trailer for system0TimeDomainf.c
 *
 * [EOF]
 */
