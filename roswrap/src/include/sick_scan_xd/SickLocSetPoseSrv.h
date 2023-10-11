#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocSetPoseSrv.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSETPOSESRV_H
#define SICK_SCAN_MESSAGE_SICKLOCSETPOSESRV_H

#include <ros/service_traits.h>


#include <sick_scan_xd/SickLocSetPoseSrvRequest.h>
#include <sick_scan_xd/SickLocSetPoseSrvResponse.h>


namespace sick_scan_xd
{

struct SickLocSetPoseSrv
{

typedef SickLocSetPoseSrvRequest Request;
typedef SickLocSetPoseSrvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SickLocSetPoseSrv
} // namespace sick_scan_xd


namespace roswrap
{
namespace service_traits
{


template<>
struct MD5Sum< ::sick_scan_xd::SickLocSetPoseSrv > {
  static const char* value()
  {
    return "11bcade26cc02b7bbcb448a2abedd38e";
  }

  static const char* value(const ::sick_scan_xd::SickLocSetPoseSrv&) { return value(); }
};

template<>
struct DataType< ::sick_scan_xd::SickLocSetPoseSrv > {
  static const char* value()
  {
    return "sick_scan/SickLocSetPoseSrv";
  }

  static const char* value(const ::sick_scan_xd::SickLocSetPoseSrv&) { return value(); }
};


// service_traits::MD5Sum< ::sick_scan_xd::SickLocSetPoseSrvRequest> should match
// service_traits::MD5Sum< ::sick_scan_xd::SickLocSetPoseSrv >
template<>
struct MD5Sum< ::sick_scan_xd::SickLocSetPoseSrvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan_xd::SickLocSetPoseSrv >::value();
  }
  static const char* value(const ::sick_scan_xd::SickLocSetPoseSrvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan_xd::SickLocSetPoseSrvRequest> should match
// service_traits::DataType< ::sick_scan_xd::SickLocSetPoseSrv >
template<>
struct DataType< ::sick_scan_xd::SickLocSetPoseSrvRequest>
{
  static const char* value()
  {
    return DataType< ::sick_scan_xd::SickLocSetPoseSrv >::value();
  }
  static const char* value(const ::sick_scan_xd::SickLocSetPoseSrvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::sick_scan_xd::SickLocSetPoseSrvResponse> should match
// service_traits::MD5Sum< ::sick_scan_xd::SickLocSetPoseSrv >
template<>
struct MD5Sum< ::sick_scan_xd::SickLocSetPoseSrvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan_xd::SickLocSetPoseSrv >::value();
  }
  static const char* value(const ::sick_scan_xd::SickLocSetPoseSrvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan_xd::SickLocSetPoseSrvResponse> should match
// service_traits::DataType< ::sick_scan_xd::SickLocSetPoseSrv >
template<>
struct DataType< ::sick_scan_xd::SickLocSetPoseSrvResponse>
{
  static const char* value()
  {
    return DataType< ::sick_scan_xd::SickLocSetPoseSrv >::value();
  }
  static const char* value(const ::sick_scan_xd::SickLocSetPoseSrvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCSETPOSESRV_H
