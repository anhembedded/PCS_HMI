/*
 * File: _coder_system1TimeDomainf_mex.c
 *
 * MATLAB Coder version            : 4.3
 * C/C++ source code generated on  : 02-Apr-2023 13:07:32
 */

/* Include Files */
#include "_coder_system1TimeDomainf_mex.h"
#include "_coder_system1TimeDomainf_api.h"

/* Function Declarations */
MEXFUNCTION_LINKAGE void system1TimeDomainf_mexFunction(int32_T nlhs, mxArray
  *plhs[1], int32_T nrhs, const mxArray *prhs[1]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[1]
 * Return Type  : void
 */
void system1TimeDomainf_mexFunction(int32_T nlhs, mxArray *plhs[1], int32_T nrhs,
  const mxArray *prhs[1])
{
  const mxArray *outputs[1];
  emlrtStack st = { NULL,              /* site */
    NULL,                              /* tls */
    NULL                               /* prev */
  };

  st.tls = emlrtRootTLSGlobal;

  /* Check for proper number of arguments. */
  if (nrhs != 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 1, 4,
                        18, "system1TimeDomainf");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "system1TimeDomainf");
  }

  /* Call the function. */
  system1TimeDomainf_api(prhs, nlhs, outputs);

  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, plhs, outputs);
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(system1TimeDomainf_atexit);

  /* Module initialization. */
  system1TimeDomainf_initialize();

  /* Dispatch the entry-point. */
  system1TimeDomainf_mexFunction(nlhs, plhs, nrhs, prhs);

  /* Module termination. */
  system1TimeDomainf_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_system1TimeDomainf_mex.c
 *
 * [EOF]
 */
