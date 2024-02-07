#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/LIDoutputstateMsg.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_LIDOUTPUTSTATEMSG_H
#define SICK_SCAN_MESSAGE_LIDOUTPUTSTATEMSG_H


#if __cplusplus > 201703L
#include <memory>
#endif
#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace sick_scan_xd
{
template <class ContainerAllocator>
struct LIDoutputstateMsg_
{
  typedef LIDoutputstateMsg_<ContainerAllocator> Type;

  LIDoutputstateMsg_()
    : header()
    , version_number(0)
    , system_counter(0)
    , output_state()
    , output_count()
    , time_state(0)
    , year(0)
    , month(0)
    , day(0)
    , hour(0)
    , minute(0)
    , second(0)
    , microsecond(0)  {
    }
  LIDoutputstateMsg_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , version_number(0)
    , system_counter(0)
    , output_state(_alloc)
    , output_count(_alloc)
    , time_state(0)
    , year(0)
    , month(0)
    , day(0)
    , hour(0)
    , minute(0)
    , second(0)
    , microsecond(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint16_t _version_number_type;
  _version_number_type version_number;

   typedef uint32_t _system_counter_type;
  _system_counter_type system_counter;

#if __cplusplus > 201703L
   typedef std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t> >  _output_state_type;
#else
   typedef std::vector<uint8_t, typename ContainerAllocator::template rebind<uint8_t>::other >  _output_state_type;
#endif
  _output_state_type output_state;

#if __cplusplus > 201703L
   typedef std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t> >  _output_count_type;
#else
   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _output_count_type;
#endif
  _output_count_type output_count;

   typedef uint16_t _time_state_type;
  _time_state_type time_state;

   typedef uint16_t _year_type;
  _year_type year;

   typedef uint8_t _month_type;
  _month_type month;

   typedef uint8_t _day_type;
  _day_type day;

   typedef uint8_t _hour_type;
  _hour_type hour;

   typedef uint8_t _minute_type;
  _minute_type minute;

   typedef uint8_t _second_type;
  _second_type second;

   typedef uint32_t _microsecond_type;
  _microsecond_type microsecond;





  typedef std::shared_ptr< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> const> ConstPtr;

}; // struct LIDoutputstateMsg_

typedef ::sick_scan_xd::LIDoutputstateMsg_<std::allocator<void> > LIDoutputstateMsg;

typedef std::shared_ptr< ::sick_scan_xd::LIDoutputstateMsg > LIDoutputstateMsgPtr;
typedef std::shared_ptr< ::sick_scan_xd::LIDoutputstateMsg const> LIDoutputstateMsgConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator1> & lhs, const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.version_number == rhs.version_number &&
    lhs.system_counter == rhs.system_counter &&
    lhs.output_state == rhs.output_state &&
    lhs.output_count == rhs.output_count &&
    lhs.time_state == rhs.time_state &&
    lhs.year == rhs.year &&
    lhs.month == rhs.month &&
    lhs.day == rhs.day &&
    lhs.hour == rhs.hour &&
    lhs.minute == rhs.minute &&
    lhs.second == rhs.second &&
    lhs.microsecond == rhs.microsecond;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator1> & lhs, const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan_xd

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e31d4eb61fa1d840e24cb97a0ef71ace";
  }

  static const char* value(const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe31d4eb61fa1d840ULL;
  static const uint64_t static_value2 = 0xe24cb97a0ef71aceULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/LIDoutputstateMsg";
  }

  static const char* value(const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This message contains the \"sSN LIDoutputstate\" message of a Sick laser scanner as an ros message.\n"
"#\n"
"\n"
"Header header\n"
"\n"
"# Status code\n"
"uint16 version_number # Status code version number\n"
"uint32 system_counter # Status code system counter (time in microsec since power up, max. 71 min then starting from 0 again)\n"
"\n"
"# Array of output states (state and count)\n"
"uint8[] output_state  # output states, each state with value 0 (not active), 1 (active) or 2 (not used)\n"
"uint32[] output_count # output counter\n"
"\n"
"# Time block (sensortime from the last change of min. one of the outputs)\n"
"uint16 time_state   # No time data: 0, Time data: 1\n"
"uint16 year        # f.e. 2021\n"
"uint8 month        # 1 ... 12\n"
"uint8 day          # 1 ... 31\n"
"uint8 hour         # 0 ... 23\n"
"uint8 minute       # 0 ... 59\n"
"uint8 second       # 0 ... 59\n"
"uint32 microsecond # 0 ... 999999\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
;
  }

  static const char* value(const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.version_number);
      stream.next(m.system_counter);
      stream.next(m.output_state);
      stream.next(m.output_count);
      stream.next(m.time_state);
      stream.next(m.year);
      stream.next(m.month);
      stream.next(m.day);
      stream.next(m.hour);
      stream.next(m.minute);
      stream.next(m.second);
      stream.next(m.microsecond);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct LIDoutputstateMsg_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan_xd::LIDoutputstateMsg_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "version_number: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.version_number);
    s << indent << "system_counter: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.system_counter);
    s << indent << "output_state[]" << std::endl;
    for (size_t i = 0; i < v.output_state.size(); ++i)
    {
      s << indent << "  output_state[" << i << "]: ";
      Printer<uint8_t>::stream(s, indent + "  ", v.output_state[i]);
    }
    s << indent << "output_count[]" << std::endl;
    for (size_t i = 0; i < v.output_count.size(); ++i)
    {
      s << indent << "  output_count[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.output_count[i]);
    }
    s << indent << "time_state: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.time_state);
    s << indent << "year: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.year);
    s << indent << "month: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.month);
    s << indent << "day: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.day);
    s << indent << "hour: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.hour);
    s << indent << "minute: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.minute);
    s << indent << "second: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.second);
    s << indent << "microsecond: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.microsecond);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_LIDOUTPUTSTATEMSG_H
