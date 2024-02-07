#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickDevSetLidarConfigSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKDEVSETLIDARCONFIGSRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKDEVSETLIDARCONFIGSRVREQUEST_H


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


namespace sick_scan_xd
{
template <class ContainerAllocator>
struct SickDevSetLidarConfigSrvRequest_
{
  typedef SickDevSetLidarConfigSrvRequest_<ContainerAllocator> Type;

  SickDevSetLidarConfigSrvRequest_()
    : index(0)
    , minrange(0)
    , maxrange(0)
    , minangle(0)
    , maxangle(0)
    , x(0)
    , y(0)
    , yaw(0)
    , upsidedown(false)
    , ip()
    , port(0)
    , interfacetype(0)
    , maplayer(0)
    , active(false)  {
    }
  SickDevSetLidarConfigSrvRequest_(const ContainerAllocator& _alloc)
    : index(0)
    , minrange(0)
    , maxrange(0)
    , minangle(0)
    , maxangle(0)
    , x(0)
    , y(0)
    , yaw(0)
    , upsidedown(false)
    , ip(_alloc)
    , port(0)
    , interfacetype(0)
    , maplayer(0)
    , active(false)  {
  (void)_alloc;
    }



   typedef uint32_t _index_type;
  _index_type index;

   typedef uint32_t _minrange_type;
  _minrange_type minrange;

   typedef uint32_t _maxrange_type;
  _maxrange_type maxrange;

   typedef int32_t _minangle_type;
  _minangle_type minangle;

   typedef int32_t _maxangle_type;
  _maxangle_type maxangle;

   typedef int32_t _x_type;
  _x_type x;

   typedef int32_t _y_type;
  _y_type y;

   typedef int32_t _yaw_type;
  _yaw_type yaw;

   typedef uint8_t _upsidedown_type;
  _upsidedown_type upsidedown;

#if __cplusplus > 201703L
   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char> >  _ip_type;
#else
   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _ip_type;
#endif
  _ip_type ip;

   typedef uint32_t _port_type;
  _port_type port;

   typedef int32_t _interfacetype_type;
  _interfacetype_type interfacetype;

   typedef uint32_t _maplayer_type;
  _maplayer_type maplayer;

   typedef uint8_t _active_type;
  _active_type active;





  typedef std::shared_ptr< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickDevSetLidarConfigSrvRequest_

typedef ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<std::allocator<void> > SickDevSetLidarConfigSrvRequest;

typedef std::shared_ptr< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest > SickDevSetLidarConfigSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest const> SickDevSetLidarConfigSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.index == rhs.index &&
    lhs.minrange == rhs.minrange &&
    lhs.maxrange == rhs.maxrange &&
    lhs.minangle == rhs.minangle &&
    lhs.maxangle == rhs.maxangle &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.yaw == rhs.yaw &&
    lhs.upsidedown == rhs.upsidedown &&
    lhs.ip == rhs.ip &&
    lhs.port == rhs.port &&
    lhs.interfacetype == rhs.interfacetype &&
    lhs.maplayer == rhs.maplayer &&
    lhs.active == rhs.active;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan_xd

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bcc8a58e8b9a56100f4e9919c37f836a";
  }

  static const char* value(const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xbcc8a58e8b9a5610ULL;
  static const uint64_t static_value2 = 0x0f4e9919c37f836aULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickDevSetLidarConfigSrvRequest";
  }

  static const char* value(const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickDevSetLidarConfig for sick localization\n"
"# Sets the configuration for a lidar\n"
"# Example call (ROS1):\n"
"# rosservice call SickDevSetLidarConfig \"{index: 0, minrange: 100, maxrange: 200000, minangle: -15000, maxangle: 15000, x: 1000, y: -1000, yaw: 2000, upsidedown: true, ip: 192.168.0.123, port: 2111, interfacetype: 0, maplayer: 0, active: true}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickDevSetLidarConfig sick_scan/srv/SickDevSetLidarConfigSrv \"{index: 0, minrange: 100, maxrange: 200000, minangle: -15000, maxangle: 15000, x: 1000, y: -1000, yaw: 2000, upsidedown: true, ip: 192.168.0.123, port: 2111, interfacetype: 0, maplayer: 0, active: true}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"uint32 index # Index of the lidar that shall be configured. [0, 1] \n"
"uint32 minrange # Beams with a range lower than this distance will be discarded. [<min>, 250000] in [mm] \n"
"uint32 maxrange # Beams with a range greater than this distance will be discarded. [<min>, 250000] in [mm] \n"
"int32 minangle # Beams with an angle lower than this threshold will be discarded. [-180000, 180000] in [mdeg] \n"
"int32 maxangle # Beams with an angle greater than this threshold will be discarded. [-180000, 180000] in [mdeg] \n"
"int32 x # X position relative to vehicle coordinate system. [-50000, 50000] in [mm] \n"
"int32 y # Y position relative to vehicle coordinate system. [-50000, 50000] in [mm] \n"
"int32 yaw # Yaw angle relative to vehicle coordinate system. [-180000, 180000] in [mdeg] \n"
"bool upsidedown # Whether the sensor is mounted upside down. {0 (false), 1 (true)} \n"
"string ip # IP address of the sensor. Must be in the same subnet as the port which it is connected to. Max length = 15 \n"
"uint32 port # COLA Port of the scanner used for communication. This is usually 2111 or 2122. [0, 65535] \n"
"int32 interfacetype # The type of the interface to this lidar. {0 (TCP), 1 (SERIAL)} \n"
"uint32 maplayer # The index of the map layer on which this LiDAR operates. If no map layers are used, set it to 0. NOTE: This feature is not implemented yet but is reserved for later releases. [<min>, <max>] \n"
"bool active # Whether this scanner shall be used for localization. For the LiDAR with the index 0 this should be always 1 (true). {0 (false), 1 (true)} \n"
"\n"
;
  }

  static const char* value(const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.index);
      stream.next(m.minrange);
      stream.next(m.maxrange);
      stream.next(m.minangle);
      stream.next(m.maxangle);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.yaw);
      stream.next(m.upsidedown);
      stream.next(m.ip);
      stream.next(m.port);
      stream.next(m.interfacetype);
      stream.next(m.maplayer);
      stream.next(m.active);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickDevSetLidarConfigSrvRequest_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan_xd::SickDevSetLidarConfigSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "index: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.index);
    s << indent << "minrange: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.minrange);
    s << indent << "maxrange: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.maxrange);
    s << indent << "minangle: ";
    Printer<int32_t>::stream(s, indent + "  ", v.minangle);
    s << indent << "maxangle: ";
    Printer<int32_t>::stream(s, indent + "  ", v.maxangle);
    s << indent << "x: ";
    Printer<int32_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<int32_t>::stream(s, indent + "  ", v.y);
    s << indent << "yaw: ";
    Printer<int32_t>::stream(s, indent + "  ", v.yaw);
    s << indent << "upsidedown: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.upsidedown);
    s << indent << "ip: ";
#if __cplusplus > 201703L
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char> > >::stream(s, indent + "  ", v.ip);
#else
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.ip);
#endif
    s << indent << "port: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.port);
    s << indent << "interfacetype: ";
    Printer<int32_t>::stream(s, indent + "  ", v.interfacetype);
    s << indent << "maplayer: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.maplayer);
    s << indent << "active: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.active);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKDEVSETLIDARCONFIGSRVREQUEST_H
