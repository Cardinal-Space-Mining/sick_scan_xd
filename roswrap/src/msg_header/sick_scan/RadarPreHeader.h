// Generated by gencpp from file sick_scan/RadarPreHeader.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_RADARPREHEADER_H
#define SICK_SCAN_MESSAGE_RADARPREHEADER_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <sick_scan/RadarPreHeaderDeviceBlock.h>
#include <sick_scan/RadarPreHeaderStatusBlock.h>
#include <sick_scan/RadarPreHeaderMeasurementParam1Block.h>
#include <sick_scan/RadarPreHeaderEncoderBlock.h>

namespace sick_scan
{
template <class ContainerAllocator>
struct RadarPreHeader_
{
  typedef RadarPreHeader_<ContainerAllocator> Type;

  RadarPreHeader_()
    : uiversionno(0)
    , radarpreheaderdeviceblock()
    , radarpreheaderstatusblock()
    , radarpreheadermeasurementparam1block()
    , radarpreheaderarrayencoderblock()  {
    }
  RadarPreHeader_(const ContainerAllocator& _alloc)
    : uiversionno(0)
    , radarpreheaderdeviceblock(_alloc)
    , radarpreheaderstatusblock(_alloc)
    , radarpreheadermeasurementparam1block(_alloc)
    , radarpreheaderarrayencoderblock(_alloc)  {
  (void)_alloc;
    }



   typedef uint16_t _uiversionno_type;
  _uiversionno_type uiversionno;

   typedef  ::sick_scan::RadarPreHeaderDeviceBlock_<ContainerAllocator>  _radarpreheaderdeviceblock_type;
  _radarpreheaderdeviceblock_type radarpreheaderdeviceblock;

   typedef  ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator>  _radarpreheaderstatusblock_type;
  _radarpreheaderstatusblock_type radarpreheaderstatusblock;

   typedef  ::sick_scan::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator>  _radarpreheadermeasurementparam1block_type;
  _radarpreheadermeasurementparam1block_type radarpreheadermeasurementparam1block;

   typedef std::vector< ::sick_scan::RadarPreHeaderEncoderBlock_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sick_scan::RadarPreHeaderEncoderBlock_<ContainerAllocator> >::other >  _radarpreheaderarrayencoderblock_type;
  _radarpreheaderarrayencoderblock_type radarpreheaderarrayencoderblock;





  typedef std::shared_ptr< ::sick_scan::RadarPreHeader_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::RadarPreHeader_<ContainerAllocator> const> ConstPtr;

}; // struct RadarPreHeader_

typedef ::sick_scan::RadarPreHeader_<std::allocator<void> > RadarPreHeader;

typedef std::shared_ptr< ::sick_scan::RadarPreHeader > RadarPreHeaderPtr;
typedef std::shared_ptr< ::sick_scan::RadarPreHeader const> RadarPreHeaderConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::RadarPreHeader_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::RadarPreHeader_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::RadarPreHeader_<ContainerAllocator1> & lhs, const ::sick_scan::RadarPreHeader_<ContainerAllocator2> & rhs)
{
  return lhs.uiversionno == rhs.uiversionno &&
    lhs.radarpreheaderdeviceblock == rhs.radarpreheaderdeviceblock &&
    lhs.radarpreheaderstatusblock == rhs.radarpreheaderstatusblock &&
    lhs.radarpreheadermeasurementparam1block == rhs.radarpreheadermeasurementparam1block &&
    lhs.radarpreheaderarrayencoderblock == rhs.radarpreheaderarrayencoderblock;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::RadarPreHeader_<ContainerAllocator1> & lhs, const ::sick_scan::RadarPreHeader_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::RadarPreHeader_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::RadarPreHeader_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::RadarPreHeader_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "93c686aba0ebefe54be53e989cc7f823";
  }

  static const char* value(const ::sick_scan::RadarPreHeader_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x93c686aba0ebefe5ULL;
  static const uint64_t static_value2 = 0x4be53e989cc7f823ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/RadarPreHeader";
  }

  static const char* value(const ::sick_scan::RadarPreHeader_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Version information for this whole structure (MeasurementData)\n"
"\n"
"# ROS-1:\n"
"#uint16 uiVersionNo\n"
"#sick_scan/RadarPreHeaderDeviceBlock radarPreHeaderDeviceBlock\n"
"#sick_scan/RadarPreHeaderStatusBlock radarPreHeaderStatusBlock\n"
"#sick_scan/RadarPreHeaderMeasurementParam1Block radarPreHeaderMeasurementParam1Block\n"
"#sick_scan/RadarPreHeaderEncoderBlock[] radarPreHeaderArrayEncoderBlock\n"
"\n"
"# ROS-2:\n"
"uint16 uiversionno\n"
"sick_scan/RadarPreHeaderDeviceBlock radarpreheaderdeviceblock\n"
"sick_scan/RadarPreHeaderStatusBlock radarpreheaderstatusblock\n"
"sick_scan/RadarPreHeaderMeasurementParam1Block radarpreheadermeasurementparam1block\n"
"sick_scan/RadarPreHeaderEncoderBlock[] radarpreheaderarrayencoderblock\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderDeviceBlock\n"
"#\n"
"#\n"
"#\n"
"#\n"
"\n"
"# ROS-1:\n"
"#uint32 uiIdent             # Logical number of the device\"\n"
"#uint32 udiSerialNo         # Serial number of the device\n"
"#bool bDeviceError          # State of the device\n"
"#bool bContaminationWarning # Contamination Warning\n"
"#bool bContaminationError   # Contamination Error\n"
"\n"
"# ROS-2:\n"
"uint32 uiident             # Logical number of the device\"\n"
"uint32 udiserialno         # Serial number of the device\n"
"bool bdeviceerror          # State of the device\n"
"bool bcontaminationwarning # Contamination Warning\n"
"bool bcontaminationerror   # Contamination Error\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderStatusBlock\n"
"#\n"
"#\n"
"#\n"
"# ROS-1:\n"
"#uint32 uiTelegramCount # telegram number\n"
"#uint32 uiCycleCount # \"scan number\"\n"
"#uint32 udiSystemCountScan # system time since power on of scan gen. [us]\n"
"#uint32 udiSystemCountTransmit # system time since power on of scan transmission [us]\n"
"#uint16 uiInputs # state of digital inputs\n"
"#uint16 uiOutputs # state of digital outputs\n"
"\n"
"# ROS-2:\n"
"uint32 uitelegramcount # telegram number\n"
"uint32 uicyclecount # \"scan number\"\n"
"uint32 udisystemcountscan # system time since power on of scan gen. [us]\n"
"uint32 udisystemcounttransmit # system time since power on of scan transmission [us]\n"
"uint16 uiinputs # state of digital inputs\n"
"uint16 uioutputs # state of digital outputs\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderMeasurementParam1Block\n"
"# ROS-1:\n"
"#uint32 uiCycleDuration # Time in microseconds to detect this items\n"
"#uint32 uiNoiseLevel # [1/100dB]\n"
"# ROS-2:\n"
"uint32 uicycleduration # Time in microseconds to detect this items\n"
"uint32 uinoiselevel # [1/100dB]\n"
"\n"
"================================================================================\n"
"MSG: sick_scan/RadarPreHeaderEncoderBlock\n"
"# Array with connected encoder sensors\n"
"# ROS-1:\n"
"#uint32 udiEncoderPos  # encoder position [inc]\n"
"#int16 iEncoderSpeed   # encoder speed [inc/mm]\n"
"# ROS-2:\n"
"uint32 udiencoderpos  # encoder position [inc]\n"
"int16 iencoderspeed   # encoder speed [inc/mm]\n"
;
  }

  static const char* value(const ::sick_scan::RadarPreHeader_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.uiversionno);
      stream.next(m.radarpreheaderdeviceblock);
      stream.next(m.radarpreheaderstatusblock);
      stream.next(m.radarpreheadermeasurementparam1block);
      stream.next(m.radarpreheaderarrayencoderblock);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarPreHeader_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::RadarPreHeader_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::RadarPreHeader_<ContainerAllocator>& v)
  {
    s << indent << "uiversionno: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.uiversionno);
    s << indent << "radarpreheaderdeviceblock: ";
    s << std::endl;
    Printer< ::sick_scan::RadarPreHeaderDeviceBlock_<ContainerAllocator> >::stream(s, indent + "  ", v.radarpreheaderdeviceblock);
    s << indent << "radarpreheaderstatusblock: ";
    s << std::endl;
    Printer< ::sick_scan::RadarPreHeaderStatusBlock_<ContainerAllocator> >::stream(s, indent + "  ", v.radarpreheaderstatusblock);
    s << indent << "radarpreheadermeasurementparam1block: ";
    s << std::endl;
    Printer< ::sick_scan::RadarPreHeaderMeasurementParam1Block_<ContainerAllocator> >::stream(s, indent + "  ", v.radarpreheadermeasurementparam1block);
    s << indent << "radarpreheaderarrayencoderblock[]" << std::endl;
    for (size_t i = 0; i < v.radarpreheaderarrayencoderblock.size(); ++i)
    {
      s << indent << "  radarpreheaderarrayencoderblock[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sick_scan::RadarPreHeaderEncoderBlock_<ContainerAllocator> >::stream(s, indent + "    ", v.radarpreheaderarrayencoderblock[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // SICK_SCAN_MESSAGE_RADARPREHEADER_H
