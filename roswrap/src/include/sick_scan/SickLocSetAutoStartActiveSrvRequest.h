#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocSetAutoStartActiveSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSETAUTOSTARTACTIVESRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCSETAUTOSTARTACTIVESRVREQUEST_H


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
struct SickLocSetAutoStartActiveSrvRequest_
{
  typedef SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> Type;

  SickLocSetAutoStartActiveSrvRequest_()
    : active(false)  {
    }
  SickLocSetAutoStartActiveSrvRequest_(const ContainerAllocator& _alloc)
    : active(false)  {
  (void)_alloc;
    }



   typedef uint8_t _active_type;
  _active_type active;





  typedef std::shared_ptr< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocSetAutoStartActiveSrvRequest_

typedef ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<std::allocator<void> > SickLocSetAutoStartActiveSrvRequest;

typedef std::shared_ptr< ::sick_scan::SickLocSetAutoStartActiveSrvRequest > SickLocSetAutoStartActiveSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan::SickLocSetAutoStartActiveSrvRequest const> SickLocSetAutoStartActiveSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.active == rhs.active;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2c5cfb0a2565df41de6873994aee57d2";
  }

  static const char* value(const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2c5cfb0a2565df41ULL;
  static const uint64_t static_value2 = 0xde6873994aee57d2ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocSetAutoStartActiveSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocSetAutoStartActive for sick localization\n"
"# Sets whether autostart should be used or not.\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocSetAutoStartActive \"{active: True}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocSetAutoStartActive sick_scan/srv/SickLocSetAutoStartActiveSrv \"{active: True}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"bool active # Whether autostart should be used or not. {0 (false), 1 (true)} \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.active);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocSetAutoStartActiveSrvRequest_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocSetAutoStartActiveSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "active: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.active);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCSETAUTOSTARTACTIVESRVREQUEST_H
