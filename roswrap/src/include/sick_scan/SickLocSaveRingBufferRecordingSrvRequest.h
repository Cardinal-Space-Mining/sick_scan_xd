// Generated by gencpp from file sick_scan/SickLocSaveRingBufferRecordingSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSAVERINGBUFFERRECORDINGSRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCSAVERINGBUFFERRECORDINGSRVREQUEST_H


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
struct SickLocSaveRingBufferRecordingSrvRequest_
{
  typedef SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> Type;

  SickLocSaveRingBufferRecordingSrvRequest_()
    : reason()  {
    }
  SickLocSaveRingBufferRecordingSrvRequest_(const ContainerAllocator& _alloc)
    : reason(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _reason_type;
  _reason_type reason;





  typedef boost::shared_ptr< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocSaveRingBufferRecordingSrvRequest_

typedef ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<std::allocator<void> > SickLocSaveRingBufferRecordingSrvRequest;

typedef boost::shared_ptr< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest > SickLocSaveRingBufferRecordingSrvRequestPtr;
typedef boost::shared_ptr< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest const> SickLocSaveRingBufferRecordingSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.reason == rhs.reason;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a280da32bbce672d6bdb55a7f298c5c0";
  }

  static const char* value(const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa280da32bbce672dULL;
  static const uint64_t static_value2 = 0x6bdb55a7f298c5c0ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocSaveRingBufferRecordingSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocSaveRingBufferRecording for sick localization\n"
"# Saves the current sensor data ring buffer as log file. The log file can be downloaded via FTP.\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocSaveRingBufferRecording \"{reason: test}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocSaveRingBufferRecording sick_scan/srv/SickLocSaveRingBufferRecordingSrv \"{reason: test}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"string reason # Reason why the recording should be saved. Max length = 512\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.reason);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocSaveRingBufferRecordingSrvRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocSaveRingBufferRecordingSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "reason: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.reason);
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_SICKLOCSAVERINGBUFFERRECORDINGSRVREQUEST_H
