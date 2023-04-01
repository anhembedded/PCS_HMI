#include "u_pidSim.h"
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

uint32_t systemFuctionTimeDomain(uint32_t u32_inputVar)
{
    uint32_t feedBack = 0u;
}
