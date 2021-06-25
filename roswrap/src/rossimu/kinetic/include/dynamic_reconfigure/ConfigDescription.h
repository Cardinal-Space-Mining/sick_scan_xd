// Generated by gencpp from file dynamic_reconfigure/ConfigDescription.msg
// DO NOT EDIT!


#ifndef DYNAMIC_RECONFIGURE_MESSAGE_CONFIGDESCRIPTION_H
#define DYNAMIC_RECONFIGURE_MESSAGE_CONFIGDESCRIPTION_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/Config.h>
#include <dynamic_reconfigure/Config.h>
#include <dynamic_reconfigure/Config.h>

namespace dynamic_reconfigure
{
template <class ContainerAllocator>
struct ConfigDescription_
{
  typedef ConfigDescription_<ContainerAllocator> Type;

  ConfigDescription_()
    : groups()
    , dflt()  {
    }
  ConfigDescription_(const ContainerAllocator& _alloc)
    : groups(_alloc)
    , dflt(_alloc)  {
  (void)_alloc;
    }



   typedef std::vector< ::dynamic_reconfigure::Group_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::dynamic_reconfigure::Group_<ContainerAllocator> >::other >  _groups_type;
  _groups_type groups;

   typedef  ::dynamic_reconfigure::Config_<ContainerAllocator>  _max_type;
  _max_type max;

   typedef  ::dynamic_reconfigure::Config_<ContainerAllocator>  _min_type;
  _min_type min;

   typedef  ::dynamic_reconfigure::Config_<ContainerAllocator>  _dflt_type;
  _dflt_type dflt;




  typedef boost::shared_ptr< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> const> ConstPtr;

}; // struct ConfigDescription_

typedef ::dynamic_reconfigure::ConfigDescription_<std::allocator<void> > ConfigDescription;

typedef boost::shared_ptr< ::dynamic_reconfigure::ConfigDescription > ConfigDescriptionPtr;
typedef boost::shared_ptr< ::dynamic_reconfigure::ConfigDescription const> ConfigDescriptionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dynamic_reconfigure

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'dynamic_reconfigure': ['/tmp/binarydeb/ros-kinetic-dynamic-reconfigure-1.5.48/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "757ce9d44ba8ddd801bb30bc456f946f";
  }

  static const char* value(const ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x757ce9d44ba8ddd8ULL;
  static const uint64_t static_value2 = 0x01bb30bc456f946fULL;
};

template<class ContainerAllocator>
struct DataType< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dynamic_reconfigure/ConfigDescription";
  }

  static const char* value(const ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Group[] groups\n\
Config max\n\
Config min\n\
Config dflt\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/Group\n\
string name\n\
string type\n\
ParamDescription[] parameters\n\
int32 parent \n\
int32 id\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/ParamDescription\n\
string name\n\
string type\n\
uint32 level\n\
string description\n\
string edit_method\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/Config\n\
BoolParameter[] bools\n\
IntParameter[] ints\n\
StrParameter[] strs\n\
DoubleParameter[] doubles\n\
GroupState[] groups\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/BoolParameter\n\
string name\n\
bool value\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/IntParameter\n\
string name\n\
int32 value\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/StrParameter\n\
string name\n\
string value\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/DoubleParameter\n\
string name\n\
float64 value\n\
\n\
================================================================================\n\
MSG: dynamic_reconfigure/GroupState\n\
string name\n\
bool state\n\
int32 id\n\
int32 parent\n\
";
  }

  static const char* value(const ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.groups);
      stream.next(m.max);
      stream.next(m.min);
      stream.next(m.dflt);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ConfigDescription_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dynamic_reconfigure::ConfigDescription_<ContainerAllocator>& v)
  {
    s << indent << "groups[]" << std::endl;
    for (size_t i = 0; i < v.groups.size(); ++i)
    {
      s << indent << "  groups[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::dynamic_reconfigure::Group_<ContainerAllocator> >::stream(s, indent + "    ", v.groups[i]);
    }
    s << indent << "max: ";
    s << std::endl;
    Printer< ::dynamic_reconfigure::Config_<ContainerAllocator> >::stream(s, indent + "  ", v.max);
    s << indent << "min: ";
    s << std::endl;
    Printer< ::dynamic_reconfigure::Config_<ContainerAllocator> >::stream(s, indent + "  ", v.min);
    s << indent << "dflt: ";
    s << std::endl;
    Printer< ::dynamic_reconfigure::Config_<ContainerAllocator> >::stream(s, indent + "  ", v.dflt);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DYNAMIC_RECONFIGURE_MESSAGE_CONFIGDESCRIPTION_H
