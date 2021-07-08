// Generated by gencpp from file sick_scan/SickLocOdometryRestrictYMotionSrv.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCODOMETRYRESTRICTYMOTIONSRV_H
#define SICK_SCAN_MESSAGE_SICKLOCODOMETRYRESTRICTYMOTIONSRV_H

#include <ros/service_traits.h>


#include <sick_scan/SickLocOdometryRestrictYMotionSrvRequest.h>
#include <sick_scan/SickLocOdometryRestrictYMotionSrvResponse.h>


namespace sick_scan
{

struct SickLocOdometryRestrictYMotionSrv
{

typedef SickLocOdometryRestrictYMotionSrvRequest Request;
typedef SickLocOdometryRestrictYMotionSrvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SickLocOdometryRestrictYMotionSrv
} // namespace sick_scan


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrv > {
  static const char* value()
  {
    return "9bb3f90ef7a4dde50a9193067d4298d5";
  }

  static const char* value(const ::sick_scan::SickLocOdometryRestrictYMotionSrv&) { return value(); }
};

template<>
struct DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrv > {
  static const char* value()
  {
    return "sick_scan/SickLocOdometryRestrictYMotionSrv";
  }

  static const char* value(const ::sick_scan::SickLocOdometryRestrictYMotionSrv&) { return value(); }
};


// service_traits::MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrvRequest> should match
// service_traits::MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocOdometryRestrictYMotionSrvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrvRequest> should match
// service_traits::DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrv >
template<>
struct DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrvRequest>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocOdometryRestrictYMotionSrvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrvResponse> should match
// service_traits::MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocOdometryRestrictYMotionSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocOdometryRestrictYMotionSrvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrvResponse> should match
// service_traits::DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrv >
template<>
struct DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrvResponse>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocOdometryRestrictYMotionSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocOdometryRestrictYMotionSrvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCODOMETRYRESTRICTYMOTIONSRV_H
