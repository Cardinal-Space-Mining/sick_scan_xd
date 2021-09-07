// Generated by gencpp from file sick_scan/SickLocAutoStartSavePoseSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCAUTOSTARTSAVEPOSESRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCAUTOSTARTSAVEPOSESRVREQUEST_H


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
struct SickLocAutoStartSavePoseSrvRequest_
{
  typedef SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> Type;

  SickLocAutoStartSavePoseSrvRequest_()
    {
    }
  SickLocAutoStartSavePoseSrvRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef std::shared_ptr< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocAutoStartSavePoseSrvRequest_

typedef ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<std::allocator<void> > SickLocAutoStartSavePoseSrvRequest;

typedef std::shared_ptr< ::sick_scan::SickLocAutoStartSavePoseSrvRequest > SickLocAutoStartSavePoseSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan::SickLocAutoStartSavePoseSrvRequest const> SickLocAutoStartSavePoseSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocAutoStartSavePoseSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocAutoStartSavePose for sick localization\n"
"# Saves the current pose. If no further pose writing occurs the system will reinitialize itself at this position on restart if LocAutoStart is enabled.\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocAutoStartSavePose \"{}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocAutoStartSavePose sick_scan/srv/SickLocAutoStartSavePoseSrv \"{}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocAutoStartSavePoseSrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::sick_scan::SickLocAutoStartSavePoseSrvRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCAUTOSTARTSAVEPOSESRVREQUEST_H
