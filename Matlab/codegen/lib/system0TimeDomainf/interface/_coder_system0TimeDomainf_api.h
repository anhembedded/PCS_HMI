/*
 * File: _coder_system0TimeDomainf_api.h
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 03-Apr-2023 08:40:05
 */

#ifndef _CODER_SYSTEM0TIMEDOMAINF_API_H
#define _CODER_SYSTEM0TIMEDOMAINF_API_H

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
extern real_T system0TimeDomainf(real_T timeVar, real_T pidOut);
extern void system0TimeDomainf_api(const mxArray * const prhs[2], int32_T nlhs,
  const mxArray *plhs[1]);
extern void system0TimeDomainf_atexit(void);
extern void system0TimeDomainf_initialize(void);
extern void system0TimeDomainf_terminate(void);
extern void system0TimeDomainf_xil_shutdown(void);
extern void system0TimeDomainf_xil_terminate(void);

#endif

/*
 * File trailer for _coder_system0TimeDomainf_api.h
 *
 * [EOF]
 */
