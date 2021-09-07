// Generated by gencpp from file sick_scan/SickLocSetOdometryPortSrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSETODOMETRYPORTSRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKLOCSETODOMETRYPORTSRVRESPONSE_H


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
struct SickLocSetOdometryPortSrvResponse_
{
  typedef SickLocSetOdometryPortSrvResponse_<ContainerAllocator> Type;

  SickLocSetOdometryPortSrvResponse_()
    : set(false)
    , executed(false)  {
    }
  SickLocSetOdometryPortSrvResponse_(const ContainerAllocator& _alloc)
    : set(false)
    , executed(false)  {
  (void)_alloc;
    }



   typedef uint8_t _set_type;
  _set_type set;

   typedef uint8_t _executed_type;
  _executed_type executed;





  typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocSetOdometryPortSrvResponse_

typedef ::sick_scan::SickLocSetOdometryPortSrvResponse_<std::allocator<void> > SickLocSetOdometryPortSrvResponse;

typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvResponse > SickLocSetOdometryPortSrvResponsePtr;
typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvResponse const> SickLocSetOdometryPortSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.set == rhs.set &&
    lhs.executed == rhs.executed;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a87c5e48d0d9101bb537f9649927b8f7";
  }

  static const char* value(const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa87c5e48d0d9101bULL;
  static const uint64_t static_value2 = 0xb537f9649927b8f7ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocSetOdometryPortSrvResponse";
  }

  static const char* value(const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# \n"
"# Response (output)\n"
"# \n"
"\n"
"bool set # Whether the arguments were valid and have been configured. {0 (false), 1 (true)} \n"
"bool executed # Whether the lidar driver started and received data. {0 (false), 1 (true)} \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.set);
      stream.next(m.executed);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocSetOdometryPortSrvResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocSetOdometryPortSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "set: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.set);
    s << indent << "executed: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.executed);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCSETODOMETRYPORTSRVRESPONSE_H
