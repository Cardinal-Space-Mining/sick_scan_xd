#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file pcl_msgs/Vertices.msg
// DO NOT EDIT!


#ifndef PCL_MSGS_MESSAGE_VERTICES_H
#define PCL_MSGS_MESSAGE_VERTICES_H


#if _HAS_CXX20
#include <memory>
#endif
#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace pcl_msgs
{
template <class ContainerAllocator>
struct Vertices_
{
  typedef Vertices_<ContainerAllocator> Type;

  Vertices_()
    : vertices()  {
    }
  Vertices_(const ContainerAllocator& _alloc)
    : vertices(_alloc)  {
  (void)_alloc;
    }



#if _HAS_CXX20
   typedef std::vector<uint32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint32_t> >  _vertices_type;
#else
   typedef std::vector<uint32_t, typename ContainerAllocator::template rebind<uint32_t>::other >  _vertices_type;
#endif
  _vertices_type vertices;





  typedef std::shared_ptr< ::pcl_msgs::Vertices_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::pcl_msgs::Vertices_<ContainerAllocator> const> ConstPtr;

}; // struct Vertices_

typedef ::pcl_msgs::Vertices_<std::allocator<void> > Vertices;

typedef std::shared_ptr< ::pcl_msgs::Vertices > VerticesPtr;
typedef std::shared_ptr< ::pcl_msgs::Vertices const> VerticesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pcl_msgs::Vertices_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pcl_msgs::Vertices_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::pcl_msgs::Vertices_<ContainerAllocator1> & lhs, const ::pcl_msgs::Vertices_<ContainerAllocator2> & rhs)
{
  return lhs.vertices == rhs.vertices;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::pcl_msgs::Vertices_<ContainerAllocator1> & lhs, const ::pcl_msgs::Vertices_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace pcl_msgs

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::pcl_msgs::Vertices_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pcl_msgs::Vertices_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pcl_msgs::Vertices_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pcl_msgs::Vertices_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pcl_msgs::Vertices_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pcl_msgs::Vertices_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pcl_msgs::Vertices_<ContainerAllocator> >
{
  static const char* value()
  {
    return "39bd7b1c23763ddd1b882b97cb7cfe11";
  }

  static const char* value(const ::pcl_msgs::Vertices_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x39bd7b1c23763dddULL;
  static const uint64_t static_value2 = 0x1b882b97cb7cfe11ULL;
};

template<class ContainerAllocator>
struct DataType< ::pcl_msgs::Vertices_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pcl_msgs/Vertices";
  }

  static const char* value(const ::pcl_msgs::Vertices_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pcl_msgs::Vertices_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# List of point indices\n"
"uint32[] vertices\n"
;
  }

  static const char* value(const ::pcl_msgs::Vertices_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pcl_msgs::Vertices_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.vertices);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Vertices_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pcl_msgs::Vertices_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pcl_msgs::Vertices_<ContainerAllocator>& v)
  {
    s << indent << "vertices[]" << std::endl;
    for (size_t i = 0; i < v.vertices.size(); ++i)
    {
      s << indent << "  vertices[" << i << "]: ";
      Printer<uint32_t>::stream(s, indent + "  ", v.vertices[i]);
    }
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // PCL_MSGS_MESSAGE_VERTICES_H
