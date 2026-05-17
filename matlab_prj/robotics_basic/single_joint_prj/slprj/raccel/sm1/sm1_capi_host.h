#ifndef sm1_cap_host_h__
#define sm1_cap_host_h__
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap_simtarget.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } sm1_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void sm1_host_InitializeDataMapInfo ( sm1_host_DataMapInfo_T * dataMap ,
const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
