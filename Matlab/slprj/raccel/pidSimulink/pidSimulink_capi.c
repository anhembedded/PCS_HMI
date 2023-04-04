#include "__cf_pidSimulink.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "pidSimulink_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "pidSimulink.h"
#include "pidSimulink_capi.h"
#include "pidSimulink_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"pidSimulink/Gain" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 , 0 ,
TARGET_STRING ( "pidSimulink/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
1 } , { 2 , 0 , TARGET_STRING (
"pidSimulink/Transfer Fcn (with initial outputs)/State Space" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"pidSimulink/PID Controller/D Gain/Internal Parameters/Derivative Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 4 , 0 , TARGET_STRING (
"pidSimulink/PID Controller/Filter/Cont. Filter/Filter" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 1 } , { 5 , 0 , TARGET_STRING (
"pidSimulink/PID Controller/Filter/Cont. Filter/SumD" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 1 } , { 6 , 0 , TARGET_STRING (
"pidSimulink/PID Controller/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 7 , 0 , TARGET_STRING (
"pidSimulink/PID Controller/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 8 , 0 , TARGET_STRING (
"pidSimulink/PID Controller/N Gain/Internal Parameters/Filter Coefficient" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 9 , 0 , TARGET_STRING (
 "pidSimulink/PID Controller/Parallel P Gain/Internal Parameters/Proportional Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 10 , 0 , TARGET_STRING (
"pidSimulink/PID Controller/Sum/Sum_PID/Sum" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 11 ,
TARGET_STRING ( "pidSimulink/PID Controller" ) , TARGET_STRING ( "P" ) , 0 ,
0 , 0 } , { 12 , TARGET_STRING ( "pidSimulink/PID Controller" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 13 , TARGET_STRING (
"pidSimulink/PID Controller" ) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 14 ,
TARGET_STRING ( "pidSimulink/PID Controller" ) , TARGET_STRING ( "N" ) , 0 ,
0 , 0 } , { 15 , TARGET_STRING ( "pidSimulink/PID Controller" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 16 ,
TARGET_STRING ( "pidSimulink/PID Controller" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 17 , TARGET_STRING (
"pidSimulink/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 18 ,
TARGET_STRING ( "pidSimulink/Step" ) , TARGET_STRING ( "Time" ) , 0 , 0 , 0 }
, { 19 , TARGET_STRING ( "pidSimulink/Step" ) , TARGET_STRING ( "Before" ) ,
0 , 0 , 0 } , { 20 , TARGET_STRING ( "pidSimulink/Step" ) , TARGET_STRING (
"After" ) , 0 , 0 , 0 } , { 21 , TARGET_STRING (
"pidSimulink/Transfer Fcn (with initial outputs)/State Space" ) ,
TARGET_STRING ( "A" ) , 0 , 1 , 0 } , { 22 , TARGET_STRING (
"pidSimulink/Transfer Fcn (with initial outputs)/State Space" ) ,
TARGET_STRING ( "B" ) , 0 , 0 , 0 } , { 23 , TARGET_STRING (
"pidSimulink/Transfer Fcn (with initial outputs)/State Space" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 24 , TARGET_STRING (
"pidSimulink/Transfer Fcn (with initial outputs)/State Space" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , ( NULL
) , 0 , 0 , 0 } } ; static const rtwCAPI_ModelParameters rtModelParameters [
] = { { 0 , ( NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . l2k1ba5may , & rtB . ooxh1c112y ,
& rtB . pdp5uzullh , & rtB . ikzb2rhopv , & rtB . l32ssigwpg , & rtB .
fym3wacfhb , & rtB . nffy5gyo0j , & rtB . hdurvlhf1v , & rtB . iwce0mskkf , &
rtB . npiatwyeaw , & rtB . cv10wusltj , & rtP . PIDController_P , & rtP .
PIDController_I , & rtP . PIDController_D , & rtP . PIDController_N , & rtP .
PIDController_InitialConditionForIntegrator , & rtP .
PIDController_InitialConditionForFilter , & rtP . Gain_Gain , & rtP .
Step_Time , & rtP . Step_Y0 , & rtP . Step_YFinal , & rtP . StateSpace_A [ 0
] , & rtP . StateSpace_B , & rtP . StateSpace_C , & rtP .
StateSpace_InitialCondition [ 0 ] , } ; static int32_T * rtVarDimsAddrMap [ ]
= { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 3 , 1 , 2 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0
, 1.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , (
NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 1 ] , 1 ,
0 } , { ( const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 11 , ( NULL ) , 0 , ( NULL ) , 0 } , {
rtBlockParameters , 14 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 2791633083U , 3201848868U , 1490434435U ,
3796668776U } , ( NULL ) , 0 , 0 } ; const rtwCAPI_ModelMappingStaticInfo *
pidSimulink_GetCAPIStaticMap ( void ) { return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void pidSimulink_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void pidSimulink_host_InitializeDataMapInfo ( pidSimulink_host_DataMapInfo_T
* dataMap , const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
