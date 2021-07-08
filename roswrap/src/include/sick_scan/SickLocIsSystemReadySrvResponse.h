// Generated by gencpp from file sick_scan/SickLocIsSystemReadySrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCISSYSTEMREADYSRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKLOCISSYSTEMREADYSRVRESPONSE_H


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
struct SickLocIsSystemReadySrvResponse_
{
  typedef SickLocIsSystemReadySrvResponse_<ContainerAllocator> Type;

  SickLocIsSystemReadySrvResponse_()
    : success(false)  {
    }
  SickLocIsSystemReadySrvResponse_(const ContainerAllocator& _alloc)
    : success(false)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocIsSystemReadySrvResponse_

typedef ::sick_scan::SickLocIsSystemReadySrvResponse_<std::allocator<void> > SickLocIsSystemReadySrvResponse;

typedef boost::shared_ptr< ::sick_scan::SickLocIsSystemReadySrvResponse > SickLocIsSystemReadySrvResponsePtr;
typedef boost::shared_ptr< ::sick_scan::SickLocIsSystemReadySrvResponse const> SickLocIsSystemReadySrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "358e233cde0c8a8bcfea4ce193f8fc15";
  }

  static const char* value(const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x358e233cde0c8a8bULL;
  static const uint64_t static_value2 = 0xcfea4ce193f8fc15ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocIsSystemReadySrvResponse";
  }

  static const char* value(const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"#\n"
"# Response (output)\n"
"#\n"
"\n"
"bool success # true: system ready response received from localization controller, false: system not ready or service failed (timeout or error status from controller)\n"
"\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocIsSystemReadySrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocIsSystemReadySrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCISSYSTEMREADYSRVRESPONSE_H
