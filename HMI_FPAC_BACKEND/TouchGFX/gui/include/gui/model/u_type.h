#ifndef B643C8FE_D8FC_45EE_AA0A_B790CF25052C
#define B643C8FE_D8FC_45EE_AA0A_B790CF25052C

#include <stdint.h>


enum systemState_type
{
    eSYSTEM_STARTUP,
    eSETTING_VAR,
    eMENU,
    ePID_GRAPH_RUN,
    ePID_GRAPH,
    ePID_SET,
    eUPDATE_VAR,
    eSET_ACTUATOR,
    eUPDATE_ACTUATOR_PID_PARAMETER,
    eSYSTEM_STARTUP_EXIT,
    eSETTING_VAR_EXIT,
    eMENU_EXIT,
    ePID_GRAPH_RUN_EXIT,
    ePID_GRAPH_EXIT,
    ePID_SET_EXIT,
    eUPDATE_VAR_EXIT,
    eSET_ACTUATOR_EXIT,
    eUPDATE_ACTUATOR_PID_PARAMETER_EXIT
};

struct u_appPid_updateParam_type
{
    uint32_t messControl;
    double Kp;
    double Ki;
    double Kd;
    double feedback;
    double setPoint;
    double pidOutput;
    uint32_t sampleTime;
};


#endif /* B643C8FE_D8FC_45EE_AA0A_B790CF25052C */
