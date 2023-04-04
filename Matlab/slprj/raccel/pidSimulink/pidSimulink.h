#include "__cf_pidSimulink.h"
#ifndef RTW_HEADER_pidSimulink_h_
#define RTW_HEADER_pidSimulink_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef pidSimulink_COMMON_INCLUDES_
#define pidSimulink_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "pidSimulink_types.h"
#include "multiword_types.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME pidSimulink
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (11) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (4)   
#elif NCSTATES != 4
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T pdp5uzullh ; real_T l2k1ba5may ; real_T ooxh1c112y ;
real_T npiatwyeaw ; real_T hdurvlhf1v ; real_T ikzb2rhopv ; real_T l32ssigwpg
; real_T fym3wacfhb ; real_T iwce0mskkf ; real_T cv10wusltj ; real_T
nffy5gyo0j ; } B ; typedef struct { struct { void * LoggedData ; } be3mmkhywh
; struct { void * LoggedData ; } l5tmqmeh53 ; int_T gytm0sllan ; } DW ;
typedef struct { real_T doiwyyfd5g [ 2 ] ; real_T osckvceuox ; real_T
grmxq04fp5 ; } X ; typedef struct { real_T doiwyyfd5g [ 2 ] ; real_T
osckvceuox ; real_T grmxq04fp5 ; } XDot ; typedef struct { boolean_T
doiwyyfd5g [ 2 ] ; boolean_T osckvceuox ; boolean_T grmxq04fp5 ; } XDis ;
typedef struct { real_T doiwyyfd5g [ 2 ] ; real_T osckvceuox ; real_T
grmxq04fp5 ; } CStateAbsTol ; typedef struct { real_T kw5tbo302k ; } ZCV ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
real_T PIDController_D ; real_T PIDController_I ; real_T
PIDController_InitialConditionForFilter ; real_T
PIDController_InitialConditionForIntegrator ; real_T PIDController_N ; real_T
PIDController_P ; real_T StateSpace_A [ 3 ] ; real_T StateSpace_B ; real_T
StateSpace_C ; real_T StateSpace_InitialCondition [ 2 ] ; real_T Step_Time ;
real_T Step_Y0 ; real_T Step_YFinal ; real_T Gain_Gain ; } ; extern const
char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW
rtDW ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo *
pidSimulink_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ; extern
const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const
int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern
const char * gblInportFileName ; extern const int_T gblNumRootInportBlks ;
extern const int_T gblNumModelInputs ; extern const int_T
gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ; extern
const int_T gblInportComplex [ ] ; extern const int_T gblInportInterpoFlag [
] ; extern const int_T gblInportContinuous [ ] ; extern const int_T
gblParameterTuningTid ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model ( void
) ;
#endif
