// Generated by gencpp from file sick_scan/SickLocResultPoseIntervalSrv.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCRESULTPOSEINTERVALSRV_H
#define SICK_SCAN_MESSAGE_SICKLOCRESULTPOSEINTERVALSRV_H

#include <ros/service_traits.h>


#include <sick_scan/SickLocResultPoseIntervalSrvRequest.h>
#include <sick_scan/SickLocResultPoseIntervalSrvResponse.h>


namespace sick_scan
{

struct SickLocResultPoseIntervalSrv
{

typedef SickLocResultPoseIntervalSrvRequest Request;
typedef SickLocResultPoseIntervalSrvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SickLocResultPoseIntervalSrv
} // namespace sick_scan


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrv > {
  static const char* value()
  {
    return "5fbbb521f9143c1864acfd50dae1fd6e";
  }

  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrv&) { return value(); }
};

template<>
struct DataType< ::sick_scan::SickLocResultPoseIntervalSrv > {
  static const char* value()
  {
    return "sick_scan/SickLocResultPoseIntervalSrv";
  }

  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrv&) { return value(); }
};


// service_traits::MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrvRequest> should match
// service_traits::MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocResultPoseIntervalSrvRequest> should match
// service_traits::DataType< ::sick_scan::SickLocResultPoseIntervalSrv >
template<>
struct DataType< ::sick_scan::SickLocResultPoseIntervalSrvRequest>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocResultPoseIntervalSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrvResponse> should match
// service_traits::MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocResultPoseIntervalSrvResponse> should match
// service_traits::DataType< ::sick_scan::SickLocResultPoseIntervalSrv >
template<>
struct DataType< ::sick_scan::SickLocResultPoseIntervalSrvResponse>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocResultPoseIntervalSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCRESULTPOSEINTERVALSRV_H
