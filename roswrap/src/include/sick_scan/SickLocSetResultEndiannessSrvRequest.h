#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocSetResultEndiannessSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSETRESULTENDIANNESSSRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCSETRESULTENDIANNESSSRVREQUEST_H


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
struct SickLocSetResultEndiannessSrvRequest_
{
  typedef SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> Type;

  SickLocSetResultEndiannessSrvRequest_()
    : endianness(0)  {
    }
  SickLocSetResultEndiannessSrvRequest_(const ContainerAllocator& _alloc)
    : endianness(0)  {
  (void)_alloc;
    }



   typedef int32_t _endianness_type;
  _endianness_type endianness;





  typedef std::shared_ptr< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocSetResultEndiannessSrvRequest_

typedef ::sick_scan::SickLocSetResultEndiannessSrvRequest_<std::allocator<void> > SickLocSetResultEndiannessSrvRequest;

typedef std::shared_ptr< ::sick_scan::SickLocSetResultEndiannessSrvRequest > SickLocSetResultEndiannessSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan::SickLocSetResultEndiannessSrvRequest const> SickLocSetResultEndiannessSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.endianness == rhs.endianness;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dbfcd5480d5ddb32a624017eae94b7b5";
  }

  static const char* value(const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xdbfcd5480d5ddb32ULL;
  static const uint64_t static_value2 = 0xa624017eae94b7b5ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocSetResultEndiannessSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocSetResultEndianness for sick localization.\n"
"#\n"
"# ROS service SickLocSetResultEndianness sets the endianness of the result output\n"
"# by sending cola command (\"sMN LocSetResultEndianness <endianness>\")\n"
"# with parameter\n"
"# <endianness>:  0: big endian, 1: little endian, default: big endian\n"
"#\n"
"# See Telegram-Listing-v1.1.0.241R.pdf for further details about \n"
"# Cola telegrams and this command.\n"
"\n"
"#\n"
"# Request (input)\n"
"#\n"
"\n"
"int32 endianness # 0: big endian, 1: little endian, default: big endian\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.endianness);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocSetResultEndiannessSrvRequest_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocSetResultEndiannessSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "endianness: ";
    Printer<int32_t>::stream(s, indent + "  ", v.endianness);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCSETRESULTENDIANNESSSRVREQUEST_H
