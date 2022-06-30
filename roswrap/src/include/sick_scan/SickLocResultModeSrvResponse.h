#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocResultModeSrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCRESULTMODESRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKLOCRESULTMODESRVRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sick_scan
{
template <class ContainerAllocator>
struct SickLocResultModeSrvResponse_
{
  typedef SickLocResultModeSrvResponse_<ContainerAllocator> Type;

  SickLocResultModeSrvResponse_()
    : mode(0)
    , success(false)  {
    }
  SickLocResultModeSrvResponse_(const ContainerAllocator& _alloc)
    : mode(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef int32_t _mode_type;
  _mode_type mode;

   typedef uint8_t _success_type;
  _success_type success;





  typedef std::shared_ptr< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocResultModeSrvResponse_

typedef ::sick_scan::SickLocResultModeSrvResponse_<std::allocator<void> > SickLocResultModeSrvResponse;

typedef std::shared_ptr< ::sick_scan::SickLocResultModeSrvResponse > SickLocResultModeSrvResponsePtr;
typedef std::shared_ptr< ::sick_scan::SickLocResultModeSrvResponse const> SickLocResultModeSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.mode == rhs.mode &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2f5955347ceb3a6a079af7cb70bb2354";
  }

  static const char* value(const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2f5955347ceb3a6aULL;
  static const uint64_t static_value2 = 0x079af7cb70bb2354ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocResultModeSrvResponse";
  }

  static const char* value(const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# \n"
"# Response (output)\n"
"# \n"
"\n"
"int32 mode # The current result mode. 0 STREAM (default), 1 POLL\n"
"bool success # true: success response received from localization controller, false: service failed (timeout or error status from controller)\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mode);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocResultModeSrvResponse_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocResultModeSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "mode: ";
    Printer<int32_t>::stream(s, indent + "  ", v.mode);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCRESULTMODESRVRESPONSE_H
