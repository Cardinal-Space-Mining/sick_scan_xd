// Generated by gencpp from file sick_scan/SickLocSetMapSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSETMAPSRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCSETMAPSRVREQUEST_H


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
struct SickLocSetMapSrvRequest_
{
  typedef SickLocSetMapSrvRequest_<ContainerAllocator> Type;

  SickLocSetMapSrvRequest_()
    : mapfilename()  {
    }
  SickLocSetMapSrvRequest_(const ContainerAllocator& _alloc)
    : mapfilename(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _mapfilename_type;
  _mapfilename_type mapfilename;





  typedef boost::shared_ptr< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocSetMapSrvRequest_

typedef ::sick_scan::SickLocSetMapSrvRequest_<std::allocator<void> > SickLocSetMapSrvRequest;

typedef boost::shared_ptr< ::sick_scan::SickLocSetMapSrvRequest > SickLocSetMapSrvRequestPtr;
typedef boost::shared_ptr< ::sick_scan::SickLocSetMapSrvRequest const> SickLocSetMapSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.mapfilename == rhs.mapfilename;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "addff8cd5f06ebbf641e643a51548f18";
  }

  static const char* value(const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xaddff8cd5f06ebbfULL;
  static const uint64_t static_value2 = 0x641e643a51548f18ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocSetMapSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocSetMap for sick localization\n"
"# Loads the given map\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocSetMap \"{mapfilename: test.map}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocSetMap sick_scan/srv/SickLocSetMapSrv \"{mapfilename: test.map}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"string mapfilename # The filename of the map to load. Max length = 255 \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.mapfilename);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocSetMapSrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocSetMapSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "mapfilename: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.mapfilename);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCSETMAPSRVREQUEST_H
