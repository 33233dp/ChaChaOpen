#ifndef sm1_h_
#define sm1_h_
#ifndef sm1_COMMON_INCLUDES_
#define sm1_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "rt_nonfinite.h"
#include "math.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "sm1_types.h"
#include <stddef.h>
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#include <string.h>
#include "rtGetInf.h"
#define MODEL_NAME sm1
#define NSAMPLE_TIMES (2) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (19) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (6)   
#elif NCSTATES != 6
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
typedef struct { real_T ahbh4dqxfe ; real_T dh2bmjcyyq ; real_T aeagys2iku ;
real_T iamasc52hr ; real_T nnul02x04d ; real_T oshvruifnr ; real_T dlmrswrjvg
; real_T arjbnkesvj ; real_T k1oqexyhkx ; real_T lztzupnoql ; real_T
nsflg1dszx ; real_T actck2jqwv ; real_T hft3l1x4hb ; real_T cm203shx32 ;
real_T f505lgmlsf ; real_T nlrqcbl4dq ; real_T idy5tojhv4 ; real_T kkzsfpijqe
; } B ; typedef struct { struct { void * LoggedData [ 3 ] ; } ib4elqouvx ;
struct { void * LoggedData [ 3 ] ; } n20ujq255g ; int32_T lpne02cyvg ;
boolean_T k1ee23jyxs ; } DW ; typedef struct { real_T oxyevdst1e ; real_T
lsilgyxgfx ; real_T ohg0hain3q ; real_T cv44tdkzm3 ; real_T hmqprd2mba ;
real_T ljd4kb0suh ; } X ; typedef struct { real_T oxyevdst1e ; real_T
lsilgyxgfx ; real_T ohg0hain3q ; real_T cv44tdkzm3 ; real_T hmqprd2mba ;
real_T ljd4kb0suh ; } XDot ; typedef struct { boolean_T oxyevdst1e ;
boolean_T lsilgyxgfx ; boolean_T ohg0hain3q ; boolean_T cv44tdkzm3 ;
boolean_T hmqprd2mba ; boolean_T ljd4kb0suh ; } XDis ; typedef struct {
real_T oxyevdst1e ; real_T lsilgyxgfx ; real_T ohg0hain3q ; real_T cv44tdkzm3
; real_T hmqprd2mba ; real_T ljd4kb0suh ; } CStateAbsTol ; typedef struct {
real_T oxyevdst1e ; real_T lsilgyxgfx ; real_T ohg0hain3q ; real_T cv44tdkzm3
; real_T hmqprd2mba ; real_T ljd4kb0suh ; } CXPtMin ; typedef struct { real_T
oxyevdst1e ; real_T lsilgyxgfx ; real_T ohg0hain3q ; real_T cv44tdkzm3 ;
real_T hmqprd2mba ; real_T ljd4kb0suh ; } CXPtMax ; typedef struct {
rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ { real_T
TransferFcn3_A ; real_T TransferFcn3_C ; real_T Gain_Gain ; real_T
TransferFcn2_A ; real_T TransferFcn2_C ; real_T TransferFcn8_A ; real_T
TransferFcn8_C ; real_T Gain1_Gain ; real_T TransferFcn7_A ; real_T
TransferFcn7_C ; real_T TransferFcn_A ; real_T TransferFcn_C ; real_T
TransferFcn1_D ; real_T TransferFcn4_D ; real_T TransferFcn5_A ; real_T
TransferFcn5_C ; real_T TransferFcn6_D ; real_T TransferFcn9_D ; real_T
Constant_Value ; real_T Constant1_Value ; real_T Constant2_Value ; } ; extern
const char_T * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ;
extern DW rtDW ; extern P rtP ; extern mxArray * mr_sm1_GetDWork ( ) ; extern
void mr_sm1_SetDWork ( const mxArray * ssDW ) ; extern mxArray *
mr_sm1_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * sm1_GetCAPIStaticMap ( void ) ; extern
SimStruct * const rtS ; extern DataMapInfo * rt_dataMapInfoPtr ; extern
rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid )
; void MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T
tid ) ; void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
