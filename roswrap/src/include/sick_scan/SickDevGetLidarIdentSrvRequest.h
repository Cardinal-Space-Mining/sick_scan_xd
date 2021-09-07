// Generated by gencpp from file sick_scan/SickDevGetLidarIdentSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKDEVGETLIDARIDENTSRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKDEVGETLIDARIDENTSRVREQUEST_H


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
struct SickDevGetLidarIdentSrvRequest_
{
  typedef SickDevGetLidarIdentSrvRequest_<ContainerAllocator> Type;

  SickDevGetLidarIdentSrvRequest_()
    : index(0)  {
    }
  SickDevGetLidarIdentSrvRequest_(const ContainerAllocator& _alloc)
    : index(0)  {
  (void)_alloc;
    }



   typedef uint32_t _index_type;
  _index_type index;





  typedef std::shared_ptr< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickDevGetLidarIdentSrvRequest_

typedef ::sick_scan::SickDevGetLidarIdentSrvRequest_<std::allocator<void> > SickDevGetLidarIdentSrvRequest;

typedef std::shared_ptr< ::sick_scan::SickDevGetLidarIdentSrvRequest > SickDevGetLidarIdentSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan::SickDevGetLidarIdentSrvRequest const> SickDevGetLidarIdentSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.index == rhs.index;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ad7b979103dbd563a352ef5270716728";
  }

  static const char* value(const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xad7b979103dbd563ULL;
  static const uint64_t static_value2 = 0xa352ef5270716728ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickDevGetLidarIdentSrvRequest";
  }

  static const char* value(const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickDevGetLidarIdent for sick localization\n"
"# Returns the scanner ident of the specified lidar.\n"
"# Example call (ROS1):\n"
"# rosservice call SickDevGetLidarIdent \"{index: 0}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickDevGetLidarIdent sick_scan/srv/SickDevGetLidarIdentSrv \"{index: 0}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"uint32 index # The scanner index. [<min>, 1] \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.index);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickDevGetLidarIdentSrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickDevGetLidarIdentSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "index: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.index);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKDEVGETLIDARIDENTSRVREQUEST_H
