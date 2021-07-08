// Generated by gencpp from file sick_scan/SickLocResultStateSrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCRESULTSTATESRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKLOCRESULTSTATESRVRESPONSE_H


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
struct SickLocResultStateSrvResponse_
{
  typedef SickLocResultStateSrvResponse_<ContainerAllocator> Type;

  SickLocResultStateSrvResponse_()
    : state(0)
    , success(false)  {
    }
  SickLocResultStateSrvResponse_(const ContainerAllocator& _alloc)
    : state(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef uint32_t _state_type;
  _state_type state;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocResultStateSrvResponse_

typedef ::sick_scan::SickLocResultStateSrvResponse_<std::allocator<void> > SickLocResultStateSrvResponse;

typedef boost::shared_ptr< ::sick_scan::SickLocResultStateSrvResponse > SickLocResultStateSrvResponsePtr;
typedef boost::shared_ptr< ::sick_scan::SickLocResultStateSrvResponse const> SickLocResultStateSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.state == rhs.state &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9c5ad6cfbe3078e7136569fb578473b6";
  }

  static const char* value(const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9c5ad6cfbe3078e7ULL;
  static const uint64_t static_value2 = 0x136569fb578473b6ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocResultStateSrvResponse";
  }

  static const char* value(const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# \n"
"# Response (output)\n"
"# \n"
"\n"
"uint32 state # The output state of the result interface as bit field: From LSB to MSB: Bit 1: Pose output enabled Bit 8: Error flag\n"
"bool success # true: success response received from localization controller, false: service failed (timeout or error status from controller)\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.state);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocResultStateSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocResultStateSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "state: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.state);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCRESULTSTATESRVRESPONSE_H
