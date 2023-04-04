#include "__cf_pidSimulink.h"
#ifndef RTW_HEADER_pidSimulink_cap_host_h_
#define RTW_HEADER_pidSimulink_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
pidSimulink_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void pidSimulink_host_InitializeDataMapInfo ( pidSimulink_host_DataMapInfo_T
* dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
