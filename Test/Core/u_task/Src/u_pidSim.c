#include "u_pidSim.h"
#include "pid.h"
#include <stdint.h>

/*
 *  each transfer function we have 2 PID function:
 *  The first one is: open loop transfer function, which is the PID control theory without feedback
 *  The second one is: closed loop transfer function, which is the PID control theory with feedback
 *	Only use closed loop
 *  3 transfer function (S domain):
 *    1. Control System engineering page 165/ graph C.
 *    2.
 *    3.
 *    the system function G(s) (NOTE: G(s) is not a transfer function)
 */

PID_TypeDef TPID;
double Temp, PIDOut, TempSetpoint;

void u_pidSim_Init(void)
{
    PID(&TPID, &Temp, &PIDOut, &TempSetpoint, 2, 5, 1, _PID_P_ON_E, _PID_CD_DIRECT);
    PID_SetSampleTime(&TPID, 10);
}
uint32_t systemFuctionTimeDomain(uint32_t u32_inputVar)
{
    uint32_t feedBack = 0u;
}
