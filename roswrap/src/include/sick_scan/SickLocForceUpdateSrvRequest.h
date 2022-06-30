#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocForceUpdateSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCFORCEUPDATESRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCFORCEUPDATESRVREQUEST_H


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
struct SickLocForceUpdateSrvRequest_
{
  typedef SickLocForceUpdateSrvRequest_<ContainerAllocator> Type;

  SickLocForceUpdateSrvRequest_()
    {
    }
  SickLocForceUpdateSrvRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef std::shared_ptr< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocForceUpdateSrvRequest_

typedef ::sick_scan::SickLocForceUpdateSrvRequest_<std::allocator<void> > SickLocForceUpdateSrvRequest;

typedef std::shared_ptr< ::sick_scan::SickLocForceUpdateSrvRequest > SickLocForceUpdateSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan::SickLocForceUpdateSrvRequest const> SickLocForceUpdateSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocForceUpdateSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocForceUpdate for sick localization\n"
"# Forces an update of the map localization with the next scan. This should be used with care because it is not garanteed that this converges to the correct pose. Moving the LiDAR instead should be preferred because it produces more robust updates.\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocForceUpdate \"{}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocForceUpdate sick_scan/srv/SickLocForceUpdateSrv \"{}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocForceUpdateSrvRequest_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::sick_scan::SickLocForceUpdateSrvRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCFORCEUPDATESRVREQUEST_H
