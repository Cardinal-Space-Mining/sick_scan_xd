#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickDevGetLidarIdentSrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKDEVGETLIDARIDENTSRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKDEVGETLIDARIDENTSRVRESPONSE_H


#if __cplusplus > 201703L
#include <memory>
#endif
#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sick_scan_xd
{
template <class ContainerAllocator>
struct SickDevGetLidarIdentSrvResponse_
{
  typedef SickDevGetLidarIdentSrvResponse_<ContainerAllocator> Type;

  SickDevGetLidarIdentSrvResponse_()
    : scannerident()
    , success(false)  {
    }
  SickDevGetLidarIdentSrvResponse_(const ContainerAllocator& _alloc)
    : scannerident(_alloc)
    , success(false)  {
  (void)_alloc;
    }



#if __cplusplus > 201703L
   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char> >  _scannerident_type;
#else
   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _scannerident_type;
#endif
  _scannerident_type scannerident;

   typedef uint8_t _success_type;
  _success_type success;





  typedef std::shared_ptr< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickDevGetLidarIdentSrvResponse_

typedef ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<std::allocator<void> > SickDevGetLidarIdentSrvResponse;

typedef std::shared_ptr< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse > SickDevGetLidarIdentSrvResponsePtr;
typedef std::shared_ptr< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse const> SickDevGetLidarIdentSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.scannerident == rhs.scannerident &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan_xd

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ccaa4378b23eb60cda0d247767d6cc5f";
  }

  static const char* value(const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xccaa4378b23eb60cULL;
  static const uint64_t static_value2 = 0xda0d247767d6cc5fULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickDevGetLidarIdentSrvResponse";
  }

  static const char* value(const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# \n"
"# Response (output)\n"
"# \n"
"\n"
"string scannerident # The type name of the scanner available after configuration and successful connection. Max length = 255 \n"
"bool success # true: success response received from localization controller, false: service failed (timeout or error status from controller)\n"
"\n"
;
  }

  static const char* value(const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.scannerident);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickDevGetLidarIdentSrvResponse_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan_xd::SickDevGetLidarIdentSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "scannerident: ";
#if __cplusplus > 201703L
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char> > >::stream(s, indent + "  ", v.scannerident);
#else
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.scannerident);
#endif
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKDEVGETLIDARIDENTSRVRESPONSE_H
