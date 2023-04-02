/*
 * File: _coder_system1TimeDomainf_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 02-Apr-2023 13:07:32
 */

#ifndef _CODER_SYSTEM1TIMEDOMAINF_API_H
#define _CODER_SYSTEM1TIMEDOMAINF_API_H

/* Include Files */
#include <stddef.h>
#include <stdlib.h>
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real32_T system1TimeDomainf(real32_T t);
extern void system1TimeDomainf_api(const mxArray * const prhs[1], int32_T nlhs,
  const mxArray *plhs[1]);
extern void system1TimeDomainf_atexit(void);
extern void system1TimeDomainf_initialize(void);
extern void system1TimeDomainf_terminate(void);
extern void system1TimeDomainf_xil_shutdown(void);
extern void system1TimeDomainf_xil_terminate(void);

#endif

/*
 * File trailer for _coder_system1TimeDomainf_api.h
 *
 * [EOF]
 */
