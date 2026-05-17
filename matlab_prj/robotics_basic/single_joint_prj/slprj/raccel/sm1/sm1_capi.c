#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "sm1_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 17
#endif
#ifndef SS_INT64
#define SS_INT64 18
#endif
#else
#include "builtin_typeid_types.h"
#include "sm1.h"
#include "sm1_capi.h"
#include "sm1_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"sm1/Gain" ) , TARGET_STRING ( "Input Voltage" ) , 0 , 0 , 0 , 0 , 0 } , { 1
, 0 , TARGET_STRING ( "sm1/Gain1" ) , TARGET_STRING ( "Input Voltage" ) , 0 ,
0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING ( "sm1/Add" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 3 , 0 , TARGET_STRING ( "sm1/Add1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING (
"sm1/Add2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 ,
TARGET_STRING ( "sm1/Add3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
6 , 0 , TARGET_STRING ( "sm1/Add4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 7 , 0 , TARGET_STRING ( "sm1/Add5" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 8 , 0 , TARGET_STRING ( "sm1/Transfer Fcn" ) , TARGET_STRING
( "I(s)" ) , 0 , 0 , 0 , 0 , 0 } , { 9 , 0 , TARGET_STRING (
"sm1/Transfer Fcn1" ) , TARGET_STRING ( "T(s)" ) , 0 , 0 , 0 , 0 , 0 } , { 10
, 0 , TARGET_STRING ( "sm1/Transfer Fcn2" ) , TARGET_STRING ( "Omega" ) , 0 ,
0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING ( "sm1/Transfer Fcn3" ) ,
TARGET_STRING ( "theta" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"sm1/Transfer Fcn4" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0
, TARGET_STRING ( "sm1/Transfer Fcn5" ) , TARGET_STRING ( "I(s)" ) , 0 , 0 ,
0 , 0 , 0 } , { 14 , 0 , TARGET_STRING ( "sm1/Transfer Fcn6" ) ,
TARGET_STRING ( "T(s)" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"sm1/Transfer Fcn7" ) , TARGET_STRING ( "Omega" ) , 0 , 0 , 0 , 0 , 0 } , {
16 , 0 , TARGET_STRING ( "sm1/Transfer Fcn8" ) , TARGET_STRING ( "theta" ) ,
0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING ( "sm1/Transfer Fcn9" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 18 , TARGET_STRING ( "sm1/Constant" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 19 , TARGET_STRING (
"sm1/Constant1" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 20 ,
TARGET_STRING ( "sm1/Constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } ,
{ 21 , TARGET_STRING ( "sm1/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 }
, { 22 , TARGET_STRING ( "sm1/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0
} , { 23 , TARGET_STRING ( "sm1/Transfer Fcn" ) , TARGET_STRING ( "A" ) , 0 ,
0 , 0 } , { 24 , TARGET_STRING ( "sm1/Transfer Fcn" ) , TARGET_STRING ( "C" )
, 0 , 0 , 0 } , { 25 , TARGET_STRING ( "sm1/Transfer Fcn1" ) , TARGET_STRING
( "D" ) , 0 , 0 , 0 } , { 26 , TARGET_STRING ( "sm1/Transfer Fcn2" ) ,
TARGET_STRING ( "A" ) , 0 , 0 , 0 } , { 27 , TARGET_STRING (
"sm1/Transfer Fcn2" ) , TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 28 ,
TARGET_STRING ( "sm1/Transfer Fcn3" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } ,
{ 29 , TARGET_STRING ( "sm1/Transfer Fcn3" ) , TARGET_STRING ( "C" ) , 0 , 0
, 0 } , { 30 , TARGET_STRING ( "sm1/Transfer Fcn4" ) , TARGET_STRING ( "D" )
, 0 , 0 , 0 } , { 31 , TARGET_STRING ( "sm1/Transfer Fcn5" ) , TARGET_STRING
( "A" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING ( "sm1/Transfer Fcn5" ) ,
TARGET_STRING ( "C" ) , 0 , 0 , 0 } , { 33 , TARGET_STRING (
"sm1/Transfer Fcn6" ) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 34 ,
TARGET_STRING ( "sm1/Transfer Fcn7" ) , TARGET_STRING ( "A" ) , 0 , 0 , 0 } ,
{ 35 , TARGET_STRING ( "sm1/Transfer Fcn7" ) , TARGET_STRING ( "C" ) , 0 , 0
, 0 } , { 36 , TARGET_STRING ( "sm1/Transfer Fcn8" ) , TARGET_STRING ( "A" )
, 0 , 0 , 0 } , { 37 , TARGET_STRING ( "sm1/Transfer Fcn8" ) , TARGET_STRING
( "C" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING ( "sm1/Transfer Fcn9" ) ,
TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 }
} ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . aeagys2iku , & rtB . dlmrswrjvg ,
& rtB . nsflg1dszx , & rtB . hft3l1x4hb , & rtB . dh2bmjcyyq , & rtB .
nlrqcbl4dq , & rtB . kkzsfpijqe , & rtB . oshvruifnr , & rtB . k1oqexyhkx , &
rtB . lztzupnoql , & rtB . iamasc52hr , & rtB . ahbh4dqxfe , & rtB .
actck2jqwv , & rtB . cm203shx32 , & rtB . f505lgmlsf , & rtB . arjbnkesvj , &
rtB . nnul02x04d , & rtB . idy5tojhv4 , & rtP . Constant_Value , & rtP .
Constant1_Value , & rtP . Constant2_Value , & rtP . Gain_Gain , & rtP .
Gain1_Gain , & rtP . TransferFcn_A , & rtP . TransferFcn_C , & rtP .
TransferFcn1_D , & rtP . TransferFcn2_A , & rtP . TransferFcn2_C , & rtP .
TransferFcn3_A , & rtP . TransferFcn3_C , & rtP . TransferFcn4_D , & rtP .
TransferFcn5_A , & rtP . TransferFcn5_C , & rtP . TransferFcn6_D , & rtP .
TransferFcn7_A , & rtP . TransferFcn7_C , & rtP . TransferFcn8_A , & rtP .
TransferFcn8_C , & rtP . TransferFcn9_D , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } }
;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 } ; static const
rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , } ; static const
rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] , (
int8_T ) 0 , ( uint8_T ) 0 } } ; static rtwCAPI_ModelMappingStaticInfo
mmiStatic = { { rtBlockSignals , 18 , rtRootInputs , 0 , rtRootOutputs , 0 }
, { rtBlockParameters , 21 , rtModelParameters , 0 } , { ( NULL ) , 0 } , {
rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap , rtSampleTimeMap
, rtDimensionArray } , "float" , { 1143637577U , 3735292694U , 3997353491U ,
3963665068U } , ( NULL ) , 0 , ( boolean_T ) 0 , rt_LoggedStateIdxList } ;
const rtwCAPI_ModelMappingStaticInfo * sm1_GetCAPIStaticMap ( void ) { return
& mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void sm1_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
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
void sm1_host_InitializeDataMapInfo ( sm1_host_DataMapInfo_T * dataMap ,
const char * path ) { rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ;
rtwCAPI_SetStaticMap ( dataMap -> mmi , & mmiStatic ) ;
rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ; rtwCAPI_SetPath
( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
