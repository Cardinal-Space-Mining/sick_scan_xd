#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file nav_msgs/OccupancyGrid.msg
// DO NOT EDIT!


#ifndef NAV_MSGS_MESSAGE_OCCUPANCYGRID_H
#define NAV_MSGS_MESSAGE_OCCUPANCYGRID_H


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
#include <nav_msgs/MapMetaData.h>

namespace nav_msgs
{
template <class ContainerAllocator>
struct OccupancyGrid_
{
  typedef OccupancyGrid_<ContainerAllocator> Type;

  OccupancyGrid_()
    : header()
    , info()
    , data()  {
    }
  OccupancyGrid_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , info(_alloc)
    , data(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::nav_msgs::MapMetaData_<ContainerAllocator>  _info_type;
  _info_type info;

#if __cplusplus > 201703L
   typedef std::vector<int8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int8_t> >  _data_type;
#else
   typedef std::vector<int8_t, typename ContainerAllocator::template rebind<int8_t>::other >  _data_type;
#endif
  _data_type data;





  typedef std::shared_ptr< ::nav_msgs::OccupancyGrid_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::nav_msgs::OccupancyGrid_<ContainerAllocator> const> ConstPtr;

}; // struct OccupancyGrid_

typedef ::nav_msgs::OccupancyGrid_<std::allocator<void> > OccupancyGrid;

typedef std::shared_ptr< ::nav_msgs::OccupancyGrid > OccupancyGridPtr;
typedef std::shared_ptr< ::nav_msgs::OccupancyGrid const> OccupancyGridConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nav_msgs::OccupancyGrid_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::nav_msgs::OccupancyGrid_<ContainerAllocator1> & lhs, const ::nav_msgs::OccupancyGrid_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.info == rhs.info &&
    lhs.data == rhs.data;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::nav_msgs::OccupancyGrid_<ContainerAllocator1> & lhs, const ::nav_msgs::OccupancyGrid_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace nav_msgs

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nav_msgs::OccupancyGrid_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nav_msgs::OccupancyGrid_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nav_msgs::OccupancyGrid_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "3381f2d731d4076ec5c71b0759edbe4e";
  }

  static const char* value(const ::nav_msgs::OccupancyGrid_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x3381f2d731d4076eULL;
  static const uint64_t static_value2 = 0xc5c71b0759edbe4eULL;
};

template<class ContainerAllocator>
struct DataType< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nav_msgs/OccupancyGrid";
  }

  static const char* value(const ::nav_msgs::OccupancyGrid_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This represents a 2-D grid map, in which each cell represents the probability of\n"
"# occupancy.\n"
"\n"
"Header header \n"
"\n"
"#MetaData for the map\n"
"MapMetaData info\n"
"\n"
"# The map data, in row-major order, starting with (0,0).  Occupancy\n"
"# probabilities are in the range [0,100].  Unknown is -1.\n"
"int8[] data\n"
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
"\n"
"================================================================================\n"
"MSG: nav_msgs/MapMetaData\n"
"# This hold basic information about the characterists of the OccupancyGrid\n"
"\n"
"# The time at which the map was loaded\n"
"time map_load_time\n"
"# The map resolution [m/cell]\n"
"float32 resolution\n"
"# Map width [cells]\n"
"uint32 width\n"
"# Map height [cells]\n"
"uint32 height\n"
"# The origin of the map [m, m, rad].  This is the real-world pose of the\n"
"# cell (0,0) in the map.\n"
"geometry_msgs/Pose origin\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::nav_msgs::OccupancyGrid_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.info);
      stream.next(m.data);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct OccupancyGrid_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nav_msgs::OccupancyGrid_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nav_msgs::OccupancyGrid_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "info: ";
    s << std::endl;
    Printer< ::nav_msgs::MapMetaData_<ContainerAllocator> >::stream(s, indent + "  ", v.info);
    s << indent << "data[]" << std::endl;
    for (size_t i = 0; i < v.data.size(); ++i)
    {
      s << indent << "  data[" << i << "]: ";
      Printer<int8_t>::stream(s, indent + "  ", v.data[i]);
    }
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // NAV_MSGS_MESSAGE_OCCUPANCYGRID_H
