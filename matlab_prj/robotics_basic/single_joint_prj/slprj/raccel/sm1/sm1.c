#include "sm1.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "sm1_private.h"
#include "rt_logging_mmi.h"
#include "sm1_capi.h"
#include "sm1_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; extern ssExecutionInfo gblExecutionInfo ; RTWExtModeInfo *
gblRTWExtModeInfo = NULL ; void raccelForceExtModeShutdown ( boolean_T
extModeStartPktReceived ) { if ( ! extModeStartPktReceived ) { boolean_T
stopRequested = false ; rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 1 , &
stopRequested ) ; } rtExtModeShutdown ( 1 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_engine_exec.h"
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 2 ; const char_T
* gbl_raccel_Version = "24.1 (R2024a) 19-Nov-2023" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; int_T enableFcnCallFlag [ ] = { 1 , 1 } ; const char
* raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_engine_exec.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
#define nh5macrchr (-1)
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . oxyevdst1e = 0.0 ; rtX .
lsilgyxgfx = 0.0 ; rtX . ohg0hain3q = 0.0 ; rtX . cv44tdkzm3 = 0.0 ; rtX .
hmqprd2mba = 0.0 ; rtX . ljd4kb0suh = 0.0 ; rtDW . k1ee23jyxs = false ; rtDW
. lpne02cyvg = nh5macrchr ; } void MdlStart ( void ) { { bool
externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { rtB . ahbh4dqxfe =
0.0 ; rtB . ahbh4dqxfe += rtP . TransferFcn3_C * rtX . oxyevdst1e ; rtB .
dh2bmjcyyq = rtP . Constant_Value - rtB . ahbh4dqxfe ; rtB . aeagys2iku = rtP
. Gain_Gain * rtB . dh2bmjcyyq ; rtB . iamasc52hr = 0.0 ; rtB . iamasc52hr +=
rtP . TransferFcn2_C * rtX . lsilgyxgfx ; rtB . nnul02x04d = 0.0 ; rtB .
nnul02x04d += rtP . TransferFcn8_C * rtX . ohg0hain3q ; rtB . oshvruifnr =
rtP . Constant_Value - rtB . nnul02x04d ; rtB . dlmrswrjvg = rtP . Gain1_Gain
* rtB . oshvruifnr ; rtB . arjbnkesvj = 0.0 ; rtB . arjbnkesvj += rtP .
TransferFcn7_C * rtX . cv44tdkzm3 ; rtDW . lpne02cyvg = nh5macrchr ; rtB .
k1oqexyhkx = rtP . TransferFcn_C * rtX . hmqprd2mba ; rtB . lztzupnoql = rtP
. TransferFcn1_D * rtB . k1oqexyhkx ; rtB . nsflg1dszx = rtB . lztzupnoql -
0.5 * rtP . Constant2_Value * rtP . Constant1_Value * muDoubleScalarSin ( rtB
. ahbh4dqxfe ) ; rtB . actck2jqwv = rtP . TransferFcn4_D * rtB . iamasc52hr ;
rtB . hft3l1x4hb = rtB . aeagys2iku - rtB . actck2jqwv ; rtB . cm203shx32 =
rtP . TransferFcn5_C * rtX . ljd4kb0suh ; rtB . f505lgmlsf = rtP .
TransferFcn6_D * rtB . cm203shx32 ; rtB . nlrqcbl4dq = rtB . f505lgmlsf ; rtB
. idy5tojhv4 = rtP . TransferFcn9_D * rtB . arjbnkesvj ; rtB . kkzsfpijqe =
rtB . dlmrswrjvg - rtB . idy5tojhv4 ; UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID1 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID1 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> oxyevdst1e = rtP .
TransferFcn3_A * rtX . oxyevdst1e ; _rtXdot -> oxyevdst1e += rtB . iamasc52hr
; _rtXdot -> lsilgyxgfx = rtP . TransferFcn2_A * rtX . lsilgyxgfx ; _rtXdot
-> lsilgyxgfx += rtB . nsflg1dszx ; _rtXdot -> ohg0hain3q = rtP .
TransferFcn8_A * rtX . ohg0hain3q ; _rtXdot -> ohg0hain3q += rtB . arjbnkesvj
; _rtXdot -> cv44tdkzm3 = rtP . TransferFcn7_A * rtX . cv44tdkzm3 ; _rtXdot
-> cv44tdkzm3 += rtB . nlrqcbl4dq ; _rtXdot -> hmqprd2mba = rtP .
TransferFcn_A * rtX . hmqprd2mba ; _rtXdot -> hmqprd2mba += rtB . hft3l1x4hb
; _rtXdot -> ljd4kb0suh = rtP . TransferFcn5_A * rtX . ljd4kb0suh ; _rtXdot
-> ljd4kb0suh += rtB . kkzsfpijqe ; } void MdlProjection ( void ) { } void
MdlTerminate ( void ) { } static void mr_sm1_cacheDataAsMxArray ( mxArray *
destArray , mwIndex i , int j , const void * srcData , size_t numBytes ) ;
static void mr_sm1_cacheDataAsMxArray ( mxArray * destArray , mwIndex i , int
j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_sm1_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static void
mr_sm1_restoreDataFromMxArray ( void * destData , const mxArray * srcArray ,
mwIndex i , int j , size_t numBytes ) { memcpy ( ( uint8_T * ) destData , (
const uint8_T * ) mxGetData ( mxGetFieldByNumber ( srcArray , i , j ) ) ,
numBytes ) ; } static void mr_sm1_cacheBitFieldToMxArray ( mxArray *
destArray , mwIndex i , int j , uint_T bitVal ) ; static void
mr_sm1_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i , int j ,
uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( real_T ) bitVal ) ) ; } static uint_T
mr_sm1_extractBitFieldFromMxArray ( const mxArray * srcArray , mwIndex i ,
int j , uint_T numBits ) ; static uint_T mr_sm1_extractBitFieldFromMxArray (
const mxArray * srcArray , mwIndex i , int j , uint_T numBits ) { const
uint_T varVal = ( uint_T ) mxGetScalar ( mxGetFieldByNumber ( srcArray , i ,
j ) ) ; return varVal & ( ( 1u << numBits ) - 1u ) ; } static void
mr_sm1_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j
, mwIndex offset , const void * srcData , size_t numBytes ) ; static void
mr_sm1_cacheDataToMxArrayWithOffset ( mxArray * destArray , mwIndex i , int j
, mwIndex offset , const void * srcData , size_t numBytes ) { uint8_T *
varData = ( uint8_T * ) mxGetData ( mxGetFieldByNumber ( destArray , i , j )
) ; memcpy ( ( uint8_T * ) & varData [ offset * numBytes ] , ( const uint8_T
* ) srcData , numBytes ) ; } static void
mr_sm1_restoreDataFromMxArrayWithOffset ( void * destData , const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) ; static
void mr_sm1_restoreDataFromMxArrayWithOffset ( void * destData , const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t numBytes ) {
const uint8_T * varData = ( const uint8_T * ) mxGetData ( mxGetFieldByNumber
( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData , ( const uint8_T *
) & varData [ offset * numBytes ] , numBytes ) ; } static void
mr_sm1_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i ,
int j , mwIndex offset , uint_T fieldVal ) ; static void
mr_sm1_cacheBitFieldToCellArrayWithOffset ( mxArray * destArray , mwIndex i ,
int j , mwIndex offset , uint_T fieldVal ) { mxSetCell ( mxGetFieldByNumber (
destArray , i , j ) , offset , mxCreateDoubleScalar ( ( real_T ) fieldVal ) )
; } static uint_T mr_sm1_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ;
static uint_T mr_sm1_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) { const
uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell ( mxGetFieldByNumber (
srcArray , i , j ) , offset ) ) ; return fieldVal & ( ( 1u << numBits ) - 1u
) ; } mxArray * mr_sm1_GetDWork ( ) { static const char_T * ssDWFieldNames [
3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX" , } ; mxArray * ssDW =
mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_sm1_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & ( rtB ) ,
sizeof ( rtB ) ) ; { static const char_T * rtdwDataFieldNames [ 2 ] = {
"rtDW.lpne02cyvg" , "rtDW.k1ee23jyxs" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 2 , rtdwDataFieldNames ) ;
mr_sm1_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * ) & ( rtDW .
lpne02cyvg ) , sizeof ( rtDW . lpne02cyvg ) ) ; mr_sm1_cacheDataAsMxArray (
rtdwData , 0 , 1 , ( const void * ) & ( rtDW . k1ee23jyxs ) , sizeof ( rtDW .
k1ee23jyxs ) ) ; mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return
ssDW ; } void mr_sm1_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_sm1_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0 , 0 , sizeof
( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber ( ssDW , 0 , 1 )
; mr_sm1_restoreDataFromMxArray ( ( void * ) & ( rtDW . lpne02cyvg ) ,
rtdwData , 0 , 0 , sizeof ( rtDW . lpne02cyvg ) ) ;
mr_sm1_restoreDataFromMxArray ( ( void * ) & ( rtDW . k1ee23jyxs ) , rtdwData
, 0 , 1 , sizeof ( rtDW . k1ee23jyxs ) ) ; } } mxArray *
mr_sm1_GetSimStateDisallowedBlocks ( ) { mxArray * data = mxCreateCellMatrix
( 2 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static const char_T * blockType [
2 ] = { "Scope" , "Scope" , } ; static const char_T * blockPath [ 2 ] = {
"sm1/Scope" , "sm1/Scope1" , } ; static const int reason [ 2 ] = { 0 , 0 , }
; for ( subs [ 0 ] = 0 ; subs [ 0 ] < 2 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] =
0 ; offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockType [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateString ( blockPath [ subs [ 0 ] ] ) ) ; subs [ 1 ] = 2 ;
offset = mxCalcSingleSubscript ( data , 2 , subs ) ; mxSetCell ( data ,
offset , mxCreateDoubleScalar ( ( real_T ) reason [ subs [ 0 ] ] ) ) ; } }
return data ; } void MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS ,
6 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ;
ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ;
ssSetNumSampleTimes ( rtS , 1 ) ; ssSetNumBlocks ( rtS , 25 ) ;
ssSetNumBlockIO ( rtS , 19 ) ; ssSetNumBlockParams ( rtS , 21 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 1143637577U ) ; ssSetChecksumVal ( rtS , 1 ,
3735292694U ) ; ssSetChecksumVal ( rtS , 2 , 3997353491U ) ; ssSetChecksumVal
( rtS , 3 , 3963665068U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; executionInfo -> gblObjects_ . numToFiles = 0 ;
executionInfo -> gblObjects_ . numFrFiles = 0 ; executionInfo -> gblObjects_
. numFrWksBlocks = 0 ; executionInfo -> gblObjects_ . numModelInputs = 0 ;
executionInfo -> gblObjects_ . numRootInportBlks = 0 ; executionInfo ->
gblObjects_ . inportDataTypeIdx = NULL ; executionInfo -> gblObjects_ .
inportDims = NULL ; executionInfo -> gblObjects_ . inportComplex = NULL ;
executionInfo -> gblObjects_ . inportInterpoFlag = NULL ; executionInfo ->
gblObjects_ . inportContinuous = NULL ; ( void ) memset ( ( char_T * ) rtS ,
0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char_T * ) & mdlInfo , 0 ,
sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char_T * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char_T * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 23 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
sm1_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS , true )
; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 )
; ssSetModelName ( rtS , "sm1" ) ; ssSetPath ( rtS , "sm1" ) ; ssSetTStart (
rtS , 0.0 ) ; ssSetTFinal ( rtS , 10.0 ) ; { static RTWLogInfo
rt_DataLoggingInfo ; rt_DataLoggingInfo . loggingInterval = ( NULL ) ;
ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; } { { static int_T
rt_LoggedStateWidths [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ; static
RTWPreprocessingFcnPtr rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static const char_T
* rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" } ; static const char_T * rt_LoggedStateBlockNames [ ] =
{ "sm1/Transfer Fcn3" , "sm1/Transfer Fcn2" , "sm1/Transfer Fcn8" ,
"sm1/Transfer Fcn7" , "sm1/Transfer Fcn" , "sm1/Transfer Fcn5" } ; static
const char_T * rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" } ;
static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_DOUBLE
, SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 ,
0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ; static int_T
rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 } ; static
RTWLogSignalInfo rt_LoggedStateSignalInfo = { 6 , rt_LoggedStateWidths ,
rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 6 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . oxyevdst1e ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . lsilgyxgfx ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . ohg0hain3q ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . cv44tdkzm3 ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . hmqprd2mba ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . ljd4kb0suh ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 6 ] ;
static real_T absTol [ 6 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 } ; static uint8_T absTolControl [ 6 ] = { 0U , 0U , 0U , 0U , 0U , 0U
} ; static real_T contStateJacPerturbBoundMinVec [ 6 ] ; static real_T
contStateJacPerturbBoundMaxVec [ 6 ] ; { int i ; for ( i = 0 ; i < 6 ; ++ i )
{ contStateJacPerturbBoundMinVec [ i ] = 0 ; contStateJacPerturbBoundMaxVec [
i ] = rtGetInf ( ) ; } } ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 0.2 )
; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetJacobianPerturbationBoundsMinVec ( rtS , contStateJacPerturbBoundMinVec
) ; ssSetJacobianPerturbationBoundsMaxVec ( rtS ,
contStateJacPerturbBoundMaxVec ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelUpdate ( rtS , MdlUpdate ) ; ssSetModelDerivatives ( rtS ,
MdlDerivatives ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 1143637577U ) ; ssSetChecksumVal ( rtS , 1 ,
3735292694U ) ; ssSetChecksumVal ( rtS , 2 , 3997353491U ) ; ssSetChecksumVal
( rtS , 3 , 3963665068U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 2 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_sm1_GetSimStateDisallowedBlocks ) ; slsaGetWorkFcnForSimTargetOP ( rtS ,
mr_sm1_GetDWork ) ; slsaSetWorkFcnForSimTargetOP ( rtS , mr_sm1_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } executionInfo -> simulationOptions_ . stateSaveName_ =
rtliGetLogX ( ssGetRTWLogInfo ( rtS ) ) ; executionInfo -> simulationOptions_
. finalStateName_ = rtliGetLogXFinal ( ssGetRTWLogInfo ( rtS ) ) ;
executionInfo -> simulationOptions_ . outputSaveName_ = rtliGetLogY (
ssGetRTWLogInfo ( rtS ) ) ; return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
void MdlOutputsParameterSampleTime ( int_T tid ) { MdlOutputsTID1 ( tid ) ; }
