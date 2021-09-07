// Generated by gencpp from file sick_scan/SickLocAutoStartActiveSrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCAUTOSTARTACTIVESRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKLOCAUTOSTARTACTIVESRVRESPONSE_H


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
struct SickLocAutoStartActiveSrvResponse_
{
  typedef SickLocAutoStartActiveSrvResponse_<ContainerAllocator> Type;

  SickLocAutoStartActiveSrvResponse_()
    : active(false)
    , success(false)  {
    }
  SickLocAutoStartActiveSrvResponse_(const ContainerAllocator& _alloc)
    : active(false)
    , success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _active_type;
  _active_type active;

   typedef uint8_t _success_type;
  _success_type success;





  typedef std::shared_ptr< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocAutoStartActiveSrvResponse_

typedef ::sick_scan::SickLocAutoStartActiveSrvResponse_<std::allocator<void> > SickLocAutoStartActiveSrvResponse;

typedef std::shared_ptr< ::sick_scan::SickLocAutoStartActiveSrvResponse > SickLocAutoStartActiveSrvResponsePtr;
typedef std::shared_ptr< ::sick_scan::SickLocAutoStartActiveSrvResponse const> SickLocAutoStartActiveSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.active == rhs.active &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9bb3f90ef7a4dde50a9193067d4298d5";
  }

  static const char* value(const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9bb3f90ef7a4dde5ULL;
  static const uint64_t static_value2 = 0x0a9193067d4298d5ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocAutoStartActiveSrvResponse";
  }

  static const char* value(const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# \n"
"# Response (output)\n"
"# \n"
"\n"
"bool active # Whether autostart should be used or not. {0 (false), 1 (true)} \n"
"bool success # true: success response received from localization controller, false: service failed (timeout or error status from controller)\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.active);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocAutoStartActiveSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocAutoStartActiveSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "active: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.active);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCAUTOSTARTACTIVESRVRESPONSE_H
