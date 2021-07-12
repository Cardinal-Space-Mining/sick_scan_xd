// Generated by gencpp from file sick_scan/SickLocSetResultPoseEnabledSrv.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSETRESULTPOSEENABLEDSRV_H
#define SICK_SCAN_MESSAGE_SICKLOCSETRESULTPOSEENABLEDSRV_H

#include <ros/service_traits.h>


#include <sick_scan/SickLocSetResultPoseEnabledSrvRequest.h>
#include <sick_scan/SickLocSetResultPoseEnabledSrvResponse.h>


namespace sick_scan
{

struct SickLocSetResultPoseEnabledSrv
{

typedef SickLocSetResultPoseEnabledSrvRequest Request;
typedef SickLocSetResultPoseEnabledSrvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SickLocSetResultPoseEnabledSrv
} // namespace sick_scan


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrv > {
  static const char* value()
  {
    return "1f66c3fbfa9f51fd9331860303d68bcc";
  }

  static const char* value(const ::sick_scan::SickLocSetResultPoseEnabledSrv&) { return value(); }
};

template<>
struct DataType< ::sick_scan::SickLocSetResultPoseEnabledSrv > {
  static const char* value()
  {
    return "sick_scan/SickLocSetResultPoseEnabledSrv";
  }

  static const char* value(const ::sick_scan::SickLocSetResultPoseEnabledSrv&) { return value(); }
};


// service_traits::MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrvRequest> should match
// service_traits::MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocSetResultPoseEnabledSrvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocSetResultPoseEnabledSrvRequest> should match
// service_traits::DataType< ::sick_scan::SickLocSetResultPoseEnabledSrv >
template<>
struct DataType< ::sick_scan::SickLocSetResultPoseEnabledSrvRequest>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocSetResultPoseEnabledSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocSetResultPoseEnabledSrvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrvResponse> should match
// service_traits::MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocSetResultPoseEnabledSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocSetResultPoseEnabledSrvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocSetResultPoseEnabledSrvResponse> should match
// service_traits::DataType< ::sick_scan::SickLocSetResultPoseEnabledSrv >
template<>
struct DataType< ::sick_scan::SickLocSetResultPoseEnabledSrvResponse>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocSetResultPoseEnabledSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocSetResultPoseEnabledSrvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCSETRESULTPOSEENABLEDSRV_H