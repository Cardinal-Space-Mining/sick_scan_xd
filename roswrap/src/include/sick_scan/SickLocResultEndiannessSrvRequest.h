// Generated by gencpp from file sick_scan/SickLocResultEndiannessSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCRESULTENDIANNESSSRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCRESULTENDIANNESSSRVREQUEST_H


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
struct SickLocResultEndiannessSrvRequest_
{
  typedef SickLocResultEndiannessSrvRequest_<ContainerAllocator> Type;

  SickLocResultEndiannessSrvRequest_()
    {
    }
  SickLocResultEndiannessSrvRequest_(const ContainerAllocator& _alloc)
    {
  (void)_alloc;
    }







  typedef boost::shared_ptr< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocResultEndiannessSrvRequest_

typedef ::sick_scan::SickLocResultEndiannessSrvRequest_<std::allocator<void> > SickLocResultEndiannessSrvRequest;

typedef boost::shared_ptr< ::sick_scan::SickLocResultEndiannessSrvRequest > SickLocResultEndiannessSrvRequestPtr;
typedef boost::shared_ptr< ::sick_scan::SickLocResultEndiannessSrvRequest const> SickLocResultEndiannessSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d41d8cd98f00b204e9800998ecf8427e";
  }

  static const char* value(const ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd41d8cd98f00b204ULL;
  static const uint64_t static_value2 = 0xe9800998ecf8427eULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocResultEndiannessSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocResultEndianness for sick localization\n"
"# Returns the endianness of the result port: 0 BIG_ENDIAN (default), 1 LITTLE_ENDIAN\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocResultEndianness \"{}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocResultEndianness sick_scan/srv/SickLocResultEndiannessSrv \"{}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream&, T)
    {}

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocResultEndiannessSrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream&, const std::string&, const ::sick_scan::SickLocResultEndiannessSrvRequest_<ContainerAllocator>&)
  {}
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCRESULTENDIANNESSSRVREQUEST_H
