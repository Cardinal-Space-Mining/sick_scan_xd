#if defined _MSC_VER && _MSC_VER >= 1300
#   pragma warning( disable : 4996 ) // suppress warning 4996 about unsafe string functions like strcpy, sprintf, etc.
#   ifndef _CRT_SECURE_NO_DEPRECATE
#   define  _CRT_SECURE_NO_DEPRECATE // suppress warning 4996 about unsafe string functions like strcpy, sprintf, etc.
#   endif
#endif
#ifdef WIN32
#  include <windows.h>
#else
#  include <dlfcn.h>
#endif

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include  <ctype.h>

#include "sick_scan_api.h"

#ifdef WIN32
#else
typedef void* HINSTANCE;
static HINSTANCE LoadLibrary(const char* szLibFilename)
{
  return dlopen(szLibFilename,RTLD_GLOBAL|RTLD_LAZY);
}
static int FreeLibrary ( HINSTANCE hLib )
{
  return !dlclose(hLib);
}
static void* GetProcAddress(HINSTANCE hLib, const char* szFunctionName)
{
  return dlsym(hLib,szFunctionName);
}
#endif

static HINSTANCE hinstLib = NULL;

typedef SickScanApiHandle(*SickScanApiCreate_PROCTYPE)(int argc, char** argv);
static SickScanApiCreate_PROCTYPE ptSickScanApiCreate = 0;

typedef int32_t(*SickScanApiRelease_PROCTYPE)(SickScanApiHandle apiHandle);
static SickScanApiRelease_PROCTYPE ptSickScanApiRelease = 0;

typedef int32_t(*SickScanApiInitByLaunchfile_PROCTYPE)(SickScanApiHandle apiHandle, const char* launchfile);
static SickScanApiInitByLaunchfile_PROCTYPE ptSickScanApiInitByLaunchfile = 0;

typedef int32_t(*SickScanApiInitByCli_PROCTYPE)(SickScanApiHandle apiHandle, int argc, char** argv);
static SickScanApiInitByCli_PROCTYPE ptSickScanApiInitByCli = 0;

typedef int32_t(*SickScanApiClose_PROCTYPE)(SickScanApiHandle apiHandle);
static SickScanApiClose_PROCTYPE ptSickScanApiClose = 0;

typedef int32_t(*SickScanApiRegisterCartesianPointCloudMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback);
static SickScanApiRegisterCartesianPointCloudMsg_PROCTYPE ptSickScanApiRegisterCartesianPointCloudMsg = 0;

typedef int32_t(*SickScanApiDeregisterCartesianPointCloudMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback);
static SickScanApiDeregisterCartesianPointCloudMsg_PROCTYPE ptSickScanApiDeregisterCartesianPointCloudMsg = 0;

typedef int32_t(*SickScanApiRegisterPolarPointCloudMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback);
static SickScanApiRegisterPolarPointCloudMsg_PROCTYPE ptSickScanApiRegisterPolarPointCloudMsg = 0;

typedef int32_t(*SickScanApiDeregisterPolarPointCloudMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback);
static SickScanApiDeregisterPolarPointCloudMsg_PROCTYPE ptSickScanApiDeregisterPolarPointCloudMsg = 0;

typedef int32_t(*SickScanApiRegisterImuMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanImuMsgCallback callback);
static SickScanApiRegisterImuMsg_PROCTYPE ptSickScanApiRegisterImuMsg = 0;

typedef int32_t(*SickScanApiDeregisterImuMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanImuMsgCallback callback);
static SickScanApiDeregisterImuMsg_PROCTYPE ptSickScanApiDeregisterImuMsg = 0;

typedef int32_t(*SickScanApiRegisterLFErecMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLFErecMsgCallback callback);
static SickScanApiRegisterLFErecMsg_PROCTYPE ptSickScanApiRegisterLFErecMsg = 0;

typedef int32_t(*SickScanApiDeregisterLFErecMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLFErecMsgCallback callback);
static SickScanApiDeregisterLFErecMsg_PROCTYPE ptSickScanApiDeregisterLFErecMsg = 0;

typedef int32_t(*SickScanApiRegisterLIDoutputstateMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsgCallback callback);
static SickScanApiRegisterLIDoutputstateMsg_PROCTYPE ptSickScanApiRegisterLIDoutputstateMsg = 0;

typedef int32_t(*SickScanApiDeregisterLIDoutputstateMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsgCallback callback);
static SickScanApiDeregisterLIDoutputstateMsg_PROCTYPE ptSickScanApiDeregisterLIDoutputstateMsg = 0;

typedef int32_t(*SickScanApiRegisterRadarScanMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanRadarScanCallback callback);
static SickScanApiRegisterRadarScanMsg_PROCTYPE ptSickScanApiRegisterRadarScanMsg = 0;

typedef int32_t(*SickScanApiDeregisterRadarScanMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanRadarScanCallback callback);
static SickScanApiDeregisterRadarScanMsg_PROCTYPE ptSickScanApiDeregisterRadarScanMsg = 0;

typedef int32_t(*SickScanApiRegisterLdmrsObjectArrayMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLdmrsObjectArrayCallback callback);
static SickScanApiRegisterLdmrsObjectArrayMsg_PROCTYPE ptSickScanApiRegisterLdmrsObjectArrayMsg = 0;

typedef int32_t(*SickScanApiDeregisterLdmrsObjectArrayMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLdmrsObjectArrayCallback callback);
static SickScanApiDeregisterLdmrsObjectArrayMsg_PROCTYPE ptSickScanApiDeregisterLdmrsObjectArrayMsg = 0;

typedef int32_t(*SickScanApiRegisterVisualizationMarkerMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanVisualizationMarkerCallback callback);
static SickScanApiRegisterVisualizationMarkerMsg_PROCTYPE ptSickScanApiRegisterVisualizationMarkerMsg = 0;

typedef int32_t(*SickScanApiDeregisterVisualizationMarkerMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanVisualizationMarkerCallback callback);
static SickScanApiDeregisterVisualizationMarkerMsg_PROCTYPE ptSickScanApiDeregisterVisualizationMarkerMsg = 0;

typedef int32_t(*SickScanApiWaitNextCartesianPointCloudMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanPointCloudMsg* msg, double timeout_sec);
static SickScanApiWaitNextCartesianPointCloudMsg_PROCTYPE ptSickScanApiWaitNextCartesianPointCloudMsg = 0;

typedef int32_t(*SickScanApiWaitNextPolarPointCloudMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanPointCloudMsg* msg, double timeout_sec);
static SickScanApiWaitNextPolarPointCloudMsg_PROCTYPE ptSickScanApiWaitNextPolarPointCloudMsg = 0;

typedef int32_t(*SickScanApiFreePolarPointCloudMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanPointCloudMsg* msg);
static SickScanApiFreePolarPointCloudMsg_PROCTYPE ptSickScanApiFreePolarPointCloudMsg = 0;

typedef int32_t(*SickScanApiWaitNextImuMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanImuMsg* msg, double timeout_sec);
static SickScanApiWaitNextImuMsg_PROCTYPE ptSickScanApiWaitNextImuMsg = 0;

typedef int32_t(*SickScanApiFreeImuMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanImuMsg* msg);
static SickScanApiFreeImuMsg_PROCTYPE ptSickScanApiFreeImuMsg = 0;

typedef int32_t(*SickScanApiWaitNextLFErecMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLFErecMsg* msg, double timeout_sec);
static SickScanApiWaitNextLFErecMsg_PROCTYPE ptSickScanApiWaitNextLFErecMsg = 0;

typedef int32_t(*SickScanApiFreeLFErecMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLFErecMsg* msg);
static SickScanApiFreeLFErecMsg_PROCTYPE ptSickScanApiFreeLFErecMsg = 0;

typedef int32_t(*SickScanApiWaitNextLIDoutputstateMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsg* msg, double timeout_sec);
static SickScanApiWaitNextLIDoutputstateMsg_PROCTYPE ptSickScanApiWaitNextLIDoutputstateMsg = 0;

typedef int32_t(*SickScanApiFreeLIDoutputstateMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsg* msg);
static SickScanApiFreeLIDoutputstateMsg_PROCTYPE ptSickScanApiFreeLIDoutputstateMsg = 0;

typedef int32_t(*SickScanApiWaitNextRadarScanMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanRadarScan* msg, double timeout_sec);
static SickScanApiWaitNextRadarScanMsg_PROCTYPE ptSickScanApiWaitNextRadarScanMsg = 0;

typedef int32_t(*SickScanApiFreeRadarScanMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanRadarScan* msg);
static SickScanApiFreeRadarScanMsg_PROCTYPE ptSickScanApiFreeRadarScanMsg = 0;

typedef int32_t(*SickScanApiWaitNextLdmrsObjectArrayMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLdmrsObjectArray* msg, double timeout_sec);
static SickScanApiWaitNextLdmrsObjectArrayMsg_PROCTYPE ptSickScanApiWaitNextLdmrsObjectArrayMsg = 0;

typedef int32_t(*SickScanApiFreeLdmrsObjectArrayMsg_PROCTYPE)(SickScanApiHandle apiHandle, SickScanLdmrsObjectArray* msg);
static SickScanApiFreeLdmrsObjectArrayMsg_PROCTYPE ptSickScanApiFreeLdmrsObjectArrayMsg = 0;

/*
*  Functions and macros to initialize and close the API and a lidar
*/

// load a function by its name using GetProcAddress if not done before (i.e. if ptFunction is 0)
#define CACHE_FUNCTION_PTR(apiHandle, ptFunction, szFunctionName)                                        \
do                                                                                                       \
{                                                                                                        \
    if (hinstLib == 0 || apiHandle == 0)                                                                 \
    {                                                                                                    \
        printf("## ERROR SickScanApi, cacheFunctionPtr(%s): library not initialized\n", szFunctionName); \
        ptFunction = 0;                                                                                  \
    }                                                                                                    \
    else if (ptFunction == 0)                                                                            \
    {                                                                                                    \
        ptFunction = GetProcAddress(hinstLib, szFunctionName);                                           \
    }                                                                                                    \
    if (ptFunction == 0)                                                                                 \
    {                                                                                                    \
        printf("## ERROR SickScanApi, cacheFunctionPtr(%s): GetProcAddress failed\n", szFunctionName);   \
    }                                                                                                    \
}   while(0)

// Load sick_scan_xd api library (dll or so file)
int32_t SickScanApiLoadLibrary(const char* library_filepath)
{
    int32_t ret = SICK_SCAN_API_SUCCESS;
    if (hinstLib == NULL)
    {
        hinstLib = LoadLibrary(library_filepath);
    }
    if (hinstLib == NULL)
    {
        printf("## ERROR SickScanApiLoadLibrary: LoadLibrary(%s) failed\n", library_filepath);
        ret = SICK_SCAN_API_NOT_LOADED;
    }
    return ret;
}

// Unload sick_scan_xd api library
int32_t SickScanApiUnloadLibrary()
{
    int32_t ret = SICK_SCAN_API_SUCCESS;
    if (hinstLib != 0)
    {
        if (!FreeLibrary(hinstLib))
        {
            printf("## ERROR SickScanApiUnloadLibrary: FreeLibrary() failed\n");
            ret = SICK_SCAN_API_ERROR;
        }
    }
    hinstLib = 0;
    ptSickScanApiCreate = 0;
    ptSickScanApiRelease = 0;
    ptSickScanApiInitByLaunchfile = 0;
    ptSickScanApiInitByCli = 0;
    ptSickScanApiClose = 0;
    ptSickScanApiRegisterCartesianPointCloudMsg = 0;
    ptSickScanApiDeregisterCartesianPointCloudMsg = 0;
    ptSickScanApiRegisterPolarPointCloudMsg = 0;
    ptSickScanApiDeregisterPolarPointCloudMsg = 0;
    ptSickScanApiRegisterImuMsg = 0;
    ptSickScanApiDeregisterImuMsg = 0;
    ptSickScanApiRegisterLFErecMsg = 0;
    ptSickScanApiDeregisterLFErecMsg = 0;
    ptSickScanApiRegisterLIDoutputstateMsg = 0;
    ptSickScanApiDeregisterLIDoutputstateMsg = 0;
    ptSickScanApiRegisterRadarScanMsg = 0;
    ptSickScanApiDeregisterRadarScanMsg = 0;
    ptSickScanApiRegisterLdmrsObjectArrayMsg = 0;
    ptSickScanApiDeregisterLdmrsObjectArrayMsg = 0;
    ptSickScanApiRegisterVisualizationMarkerMsg = 0;
    ptSickScanApiDeregisterVisualizationMarkerMsg = 0;
    ptSickScanApiWaitNextCartesianPointCloudMsg = 0;
    ptSickScanApiWaitNextPolarPointCloudMsg = 0;
    ptSickScanApiFreePolarPointCloudMsg = 0;
    ptSickScanApiWaitNextImuMsg = 0;
    ptSickScanApiFreeImuMsg = 0;
    ptSickScanApiWaitNextLFErecMsg = 0;
    ptSickScanApiFreeLFErecMsg = 0;
    ptSickScanApiWaitNextLIDoutputstateMsg = 0;
    ptSickScanApiFreeLIDoutputstateMsg = 0;
    ptSickScanApiWaitNextRadarScanMsg = 0;
    ptSickScanApiFreeRadarScanMsg = 0;
    ptSickScanApiWaitNextLdmrsObjectArrayMsg = 0;
    ptSickScanApiFreeLdmrsObjectArrayMsg = 0;
    return ret;
}

/*
*  Create an instance of sick_scan_xd api.
*  Optional commandline arguments argc, argv identical to sick_generic_caller.
*  Call SickScanApiInitByLaunchfile or SickScanApiInitByCli to process a lidar.
*/
SickScanApiHandle SickScanApiCreate(int argc, char** argv)
{
    if (hinstLib == 0)
    {
        printf("## ERROR SickScanApiCreate: library not loaded\n");
        return 0;
    }
    if (ptSickScanApiCreate == 0)
    {
        ptSickScanApiCreate = GetProcAddress(hinstLib, "SickScanApiCreate");
    }
    if (ptSickScanApiCreate == 0)
    {
        printf("## ERROR SickScanApiCreate: GetProcAddress failed\n");
        return 0;
    }
    SickScanApiHandle apiHandle = ptSickScanApiCreate(argc, argv);
    if (apiHandle == 0)
    {
        printf("## ERROR SickScanApiCreate: library call SickScanApiCreate() returned 0\n");
    }
    return apiHandle;
}

// Release and free all resources of a handle; the handle is invalid after SickScanApiRelease
int32_t SickScanApiRelease(SickScanApiHandle apiHandle)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRelease, "SickScanApiRelease");
    int32_t ret = (ptSickScanApiRelease ? (ptSickScanApiRelease(apiHandle)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRelease: library call SickScanApiRelease() failed, error code %d\n", ret);
    return ret;
}

// Initializes a lidar by launchfile and starts message receiving and processing
int32_t SickScanApiInitByLaunchfile(SickScanApiHandle apiHandle, const char* launchfile_args)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiInitByLaunchfile, "SickScanApiInitByLaunchfile");
    int32_t ret = (ptSickScanApiInitByLaunchfile ? (ptSickScanApiInitByLaunchfile(apiHandle, launchfile_args)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiInitByLaunchfile: library call SickScanApiInitByLaunchfile() failed, error code %d\n", ret);
    return ret;
}

// Initializes a lidar by commandline arguments and starts message receiving and processing
int32_t SickScanApiInitByCli(SickScanApiHandle apiHandle, int argc, char** argv)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiInitByCli, "SickScanApiInitByCli");
    int32_t ret = (ptSickScanApiInitByCli ? (ptSickScanApiInitByCli(apiHandle, argc, argv)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiInitByCli: library call SickScanApiInitByCli() failed, error code %d\n", ret);
    return ret;
}

// Stops message receiving and processing and closes a lidar
int32_t SickScanApiClose(SickScanApiHandle apiHandle)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiClose, "SickScanApiClose");
    int32_t ret = (ptSickScanApiClose ? (ptSickScanApiClose(apiHandle)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiClose: library call SickScanApiClose() failed, error code %d\n", ret);
    return ret;
}

/*
*  Registration / deregistration of message callbacks
*/

// Register / deregister a callback for cartesian PointCloud messages, pointcloud in cartesian coordinates with fields x, y, z, intensity
int32_t SickScanApiRegisterCartesianPointCloudMsg(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterCartesianPointCloudMsg, "SickScanApiRegisterCartesianPointCloudMsg");
    int32_t ret = (ptSickScanApiRegisterCartesianPointCloudMsg ? (ptSickScanApiRegisterCartesianPointCloudMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterCartesianPointCloudMsg: library call SickScanApiRegisterCartesianPointCloudMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterCartesianPointCloudMsg(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterCartesianPointCloudMsg, "SickScanApiDeregisterCartesianPointCloudMsg");
    int32_t ret = (ptSickScanApiDeregisterCartesianPointCloudMsg ? (ptSickScanApiDeregisterCartesianPointCloudMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterCartesianPointCloudMsg: library call SickScanApiDeregisterCartesianPointCloudMsg() failed, error code %d\n", ret);
    return ret;
}

// Register / deregister a callback for polar PointCloud messages, pointcloud in polar coordinates with fields range, azimuth, elevation, intensity
int32_t SickScanApiRegisterPolarPointCloudMsg(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterPolarPointCloudMsg, "SickScanApiRegisterPolarPointCloudMsg");
    int32_t ret = (ptSickScanApiRegisterPolarPointCloudMsg ? (ptSickScanApiRegisterPolarPointCloudMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterPolarPointCloudMsg: library call SickScanApiRegisterPolarPointCloudMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterPolarPointCloudMsg(SickScanApiHandle apiHandle, SickScanPointCloudMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterPolarPointCloudMsg, "SickScanApiDeregisterPolarPointCloudMsg");
    int32_t ret = (ptSickScanApiDeregisterPolarPointCloudMsg ? (ptSickScanApiDeregisterPolarPointCloudMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterPolarPointCloudMsg: library call SickScanApiDeregisterPolarPointCloudMsg() failed, error code %d\n", ret);
    return ret;
}

// Register / deregister a callback for Imu messages
int32_t SickScanApiRegisterImuMsg(SickScanApiHandle apiHandle, SickScanImuMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterImuMsg, "SickScanApiRegisterImuMsg");
    int32_t ret = (ptSickScanApiRegisterImuMsg ? (ptSickScanApiRegisterImuMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterImuMsg: library call SickScanApiRegisterImuMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterImuMsg(SickScanApiHandle apiHandle, SickScanImuMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterImuMsg, "SickScanApiDeregisterImuMsg");
    int32_t ret = (ptSickScanApiDeregisterImuMsg ? (ptSickScanApiDeregisterImuMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterImuMsg: library call SickScanApiDeregisterImuMsg() failed, error code %d\n", ret);
    return ret;
}

// Register / deregister a callback for SickScanLFErecMsg messages
int32_t SickScanApiRegisterLFErecMsg(SickScanApiHandle apiHandle, SickScanLFErecMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterLFErecMsg, "SickScanApiRegisterLFErecMsg");
    int32_t ret = (ptSickScanApiRegisterLFErecMsg ? (ptSickScanApiRegisterLFErecMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterLFErecMsg: library call SickScanApiRegisterLFErecMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterLFErecMsg(SickScanApiHandle apiHandle, SickScanLFErecMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterLFErecMsg, "SickScanApiDeregisterLFErecMsg");
    int32_t ret = (ptSickScanApiDeregisterLFErecMsg ? (ptSickScanApiDeregisterLFErecMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterLFErecMsg: library call SickScanApiDeregisterLFErecMsg() failed, error code %d\n", ret);
    return ret;
}

// Register / deregister a callback for SickScanLIDoutputstateMsg messages
int32_t SickScanApiRegisterLIDoutputstateMsg(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterLIDoutputstateMsg, "SickScanApiRegisterLIDoutputstateMsg");
    int32_t ret = (ptSickScanApiRegisterLIDoutputstateMsg ? (ptSickScanApiRegisterLIDoutputstateMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterLIDoutputstateMsg: library call SickScanApiRegisterLIDoutputstateMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterLIDoutputstateMsg(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsgCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterLIDoutputstateMsg, "SickScanApiDeregisterLIDoutputstateMsg");
    int32_t ret = (ptSickScanApiDeregisterLIDoutputstateMsg ? (ptSickScanApiDeregisterLIDoutputstateMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterLIDoutputstateMsg: library call SickScanApiDeregisterLIDoutputstateMsg() failed, error code %d\n", ret);
    return ret;
}

// Register / deregister a callback for SickScanRadarScan messages
int32_t SickScanApiRegisterRadarScanMsg(SickScanApiHandle apiHandle, SickScanRadarScanCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterRadarScanMsg, "SickScanApiRegisterRadarScanMsg");
    int32_t ret = (ptSickScanApiRegisterRadarScanMsg ? (ptSickScanApiRegisterRadarScanMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterRadarScanMsg: library call SickScanApiRegisterRadarScanMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterRadarScanMsg(SickScanApiHandle apiHandle, SickScanRadarScanCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterRadarScanMsg, "SickScanApiDeregisterRadarScanMsg");
    int32_t ret = (ptSickScanApiDeregisterRadarScanMsg ? (ptSickScanApiDeregisterRadarScanMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterRadarScanMsg: library call SickScanApiDeregisterRadarScanMsg() failed, error code %d\n", ret);
    return ret;
}

// Register / deregister a callback for SickScanLdmrsObjectArray messages
int32_t SickScanApiRegisterLdmrsObjectArrayMsg(SickScanApiHandle apiHandle, SickScanLdmrsObjectArrayCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterLdmrsObjectArrayMsg, "SickScanApiRegisterLdmrsObjectArrayMsg");
    int32_t ret = (ptSickScanApiRegisterLdmrsObjectArrayMsg ? (ptSickScanApiRegisterLdmrsObjectArrayMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterLdmrsObjectArrayMsg: library call SickScanApiRegisterLdmrsObjectArrayMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterLdmrsObjectArrayMsg(SickScanApiHandle apiHandle, SickScanLdmrsObjectArrayCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterLdmrsObjectArrayMsg, "SickScanApiDeregisterLdmrsObjectArrayMsg");
    int32_t ret = (ptSickScanApiDeregisterLdmrsObjectArrayMsg ? (ptSickScanApiDeregisterLdmrsObjectArrayMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterLdmrsObjectArrayMsg: library call SickScanApiDeregisterLdmrsObjectArrayMsg() failed, error code %d\n", ret);
    return ret;
}

// Register / deregister a callback for VisualizationMarker messages
int32_t SickScanApiRegisterVisualizationMarkerMsg(SickScanApiHandle apiHandle, SickScanVisualizationMarkerCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiRegisterVisualizationMarkerMsg, "SickScanApiRegisterVisualizationMarkerMsg");
    int32_t ret = (ptSickScanApiRegisterVisualizationMarkerMsg ? (ptSickScanApiRegisterVisualizationMarkerMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiRegisterVisualizationMarkerMsg: library call SickScanApiRegisterVisualizationMarkerMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiDeregisterVisualizationMarkerMsg(SickScanApiHandle apiHandle, SickScanVisualizationMarkerCallback callback)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiDeregisterLdmrsObjectArrayMsg, "SickScanApiDeregisterVisualizationMarkerMsg");
    int32_t ret = (ptSickScanApiDeregisterVisualizationMarkerMsg ? (ptSickScanApiDeregisterVisualizationMarkerMsg(apiHandle, callback)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiDeregisterVisualizationMarkerMsg: library call SickScanApiDeregisterVisualizationMarkerMsg() failed, error code %d\n", ret);
    return ret;
}

/*
*  Polling functions
*/

// Wait for and return the next cartesian resp. polar PointCloud messages. Note: SickScanApiWait...Msg() allocates a message. Use function SickScanApiFree...Msg() to deallocate it after use.
int32_t SickScanApiWaitNextCartesianPointCloudMsg(SickScanApiHandle apiHandle, SickScanPointCloudMsg* msg, double timeout_sec)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiWaitNextCartesianPointCloudMsg, "SickScanApiWaitNextCartesianPointCloudMsg");
    int32_t ret = (ptSickScanApiWaitNextCartesianPointCloudMsg ? (ptSickScanApiWaitNextCartesianPointCloudMsg(apiHandle, msg, timeout_sec)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiWaitNextCartesianPointCloudMsg: library call SickScanApiWaitNextCartesianPointCloudMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiWaitNextPolarPointCloudMsg(SickScanApiHandle apiHandle, SickScanPointCloudMsg* msg, double timeout_sec)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiWaitNextPolarPointCloudMsg, "SickScanApiWaitNextPolarPointCloudMsg");
    int32_t ret = (ptSickScanApiWaitNextPolarPointCloudMsg ? (ptSickScanApiWaitNextPolarPointCloudMsg(apiHandle, msg, timeout_sec)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiWaitNextPolarPointCloudMsg: library call SickScanApiWaitNextPolarPointCloudMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiFreePolarPointCloudMsg(SickScanApiHandle apiHandle, SickScanPointCloudMsg* msg)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiFreePolarPointCloudMsg, "SickScanApiFreePolarPointCloudMsg");
    int32_t ret = (ptSickScanApiFreePolarPointCloudMsg ? (ptSickScanApiFreePolarPointCloudMsg(apiHandle, msg)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiFreePolarPointCloudMsg: library call SickScanApiFreePolarPointCloudMsg() failed, error code %d\n", ret);
    return ret;
}

// Wait for and return the next Imu messages. Note: SickScanApiWait...Msg() allocates a message. Use function SickScanApiFree...Msg() to deallocate it after use.
int32_t SickScanApiWaitNextImuMsg(SickScanApiHandle apiHandle, SickScanImuMsg* msg, double timeout_sec)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiWaitNextImuMsg, "SickScanApiWaitNextImuMsg");
    int32_t ret = (ptSickScanApiWaitNextImuMsg ? (ptSickScanApiWaitNextImuMsg(apiHandle, msg, timeout_sec)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiWaitNextImuMsg: library call SickScanApiWaitNextImuMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiFreeImuMsg(SickScanApiHandle apiHandle, SickScanImuMsg* msg)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiFreeImuMsg, "SickScanApiFreeImuMsg");
    int32_t ret = (ptSickScanApiFreeImuMsg ? (ptSickScanApiFreeImuMsg(apiHandle, msg)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiFreeImuMsg: library call SickScanApiFreeImuMsg() failed, error code %d\n", ret);
    return ret;
}

// Wait for and return the next LFErec messages. Note: SickScanApiWait...Msg() allocates a message. Use function SickScanApiFree...Msg() to deallocate it after use.
int32_t SickScanApiWaitNextLFErecMsg(SickScanApiHandle apiHandle, SickScanLFErecMsg* msg, double timeout_sec)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiWaitNextLFErecMsg, "SickScanApiWaitNextLFErecMsg");
    int32_t ret = (ptSickScanApiWaitNextLFErecMsg ? (ptSickScanApiWaitNextLFErecMsg(apiHandle, msg, timeout_sec)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiWaitNextLFErecMsg: library call SickScanApiWaitNextLFErecMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiFreeLFErecMsg(SickScanApiHandle apiHandle, SickScanLFErecMsg* msg)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiFreeLFErecMsg, "SickScanApiFreeLFErecMsg");
    int32_t ret = (ptSickScanApiFreeLFErecMsg ? (ptSickScanApiFreeLFErecMsg(apiHandle, msg)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiFreeLFErecMsg: library call SickScanApiFreeLFErecMsg() failed, error code %d\n", ret);
    return ret;
}

// Wait for and return the next LIDoutputstate messages. Note: SickScanApiWait...Msg() allocates a message. Use function SickScanApiFree...Msg() to deallocate it after use.
int32_t SickScanApiWaitNextLIDoutputstateMsg(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsg* msg, double timeout_sec)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiWaitNextLIDoutputstateMsg, "SickScanApiWaitNextLIDoutputstateMsg");
    int32_t ret = (ptSickScanApiWaitNextLIDoutputstateMsg ? (ptSickScanApiWaitNextLIDoutputstateMsg(apiHandle, msg, timeout_sec)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiWaitNextLIDoutputstateMsg: library call SickScanApiWaitNextLIDoutputstateMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiFreeLIDoutputstateMsg(SickScanApiHandle apiHandle, SickScanLIDoutputstateMsg* msg)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiFreeLIDoutputstateMsg, "SickScanApiFreeLIDoutputstateMsg");
    int32_t ret = (ptSickScanApiFreeLIDoutputstateMsg ? (ptSickScanApiFreeLIDoutputstateMsg(apiHandle, msg)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiFreeLIDoutputstateMsg: library call SickScanApiFreeLIDoutputstateMsg() failed, error code %d\n", ret);
    return ret;
}

// Wait for and return the next RadarScan messages. Note: SickScanApiWait...Msg() allocates a message. Use function SickScanApiFree...Msg() to deallocate it after use.
int32_t SickScanApiWaitNextRadarScanMsg(SickScanApiHandle apiHandle, SickScanRadarScan* msg, double timeout_sec)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiWaitNextRadarScanMsg, "SickScanApiWaitNextRadarScanMsg");
    int32_t ret = (ptSickScanApiWaitNextRadarScanMsg ? (ptSickScanApiWaitNextRadarScanMsg(apiHandle, msg, timeout_sec)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiWaitNextRadarScanMsg: library call SickScanApiWaitNextRadarScanMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiFreeRadarScanMsg(SickScanApiHandle apiHandle, SickScanRadarScan* msg)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiFreeRadarScanMsg, "SickScanApiFreeRadarScanMsg");
    int32_t ret = (ptSickScanApiFreeRadarScanMsg ? (ptSickScanApiFreeRadarScanMsg(apiHandle, msg)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiFreeRadarScanMsg: library call SickScanApiFreeRadarScanMsg() failed, error code %d\n", ret);
    return ret;
}

// Wait for and return the next LdmrsObjectArray messages. Note: SickScanApiWait...Msg() allocates a message. Use function SickScanApiFree...Msg() to deallocate it after use.
int32_t SickScanApiWaitNextLdmrsObjectArrayMsg(SickScanApiHandle apiHandle, SickScanLdmrsObjectArray* msg, double timeout_sec)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiWaitNextLdmrsObjectArrayMsg, "SickScanApiWaitNextLdmrsObjectArrayMsg");
    int32_t ret = (ptSickScanApiWaitNextLdmrsObjectArrayMsg ? (ptSickScanApiWaitNextLdmrsObjectArrayMsg(apiHandle, msg, timeout_sec)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiWaitNextLdmrsObjectArrayMsg: library call SickScanApiWaitNextLdmrsObjectArrayMsg() failed, error code %d\n", ret);
    return ret;
}
int32_t SickScanApiFreeLdmrsObjectArrayMsg(SickScanApiHandle apiHandle, SickScanLdmrsObjectArray* msg)
{
    CACHE_FUNCTION_PTR(apiHandle, ptSickScanApiFreeLdmrsObjectArrayMsg, "SickScanApiFreeLdmrsObjectArrayMsg");
    int32_t ret = (ptSickScanApiFreeLdmrsObjectArrayMsg ? (ptSickScanApiFreeLdmrsObjectArrayMsg(apiHandle, msg)) : SICK_SCAN_API_NOT_INITIALIZED);
    if (ret != SICK_SCAN_API_SUCCESS)
        printf("## ERROR SickScanApiFreeLdmrsObjectArrayMsg: library call SickScanApiFreeLdmrsObjectArrayMsg() failed, error code %d\n", ret);
    return ret;
}
