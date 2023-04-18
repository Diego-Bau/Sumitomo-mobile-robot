// Generated by gencpp from file zed_interfaces/Keypoint2Df.msg
// DO NOT EDIT!


#ifndef ZED_INTERFACES_MESSAGE_KEYPOINT2DF_H
#define ZED_INTERFACES_MESSAGE_KEYPOINT2DF_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace zed_interfaces
{
template <class ContainerAllocator>
struct Keypoint2Df_
{
  typedef Keypoint2Df_<ContainerAllocator> Type;

  Keypoint2Df_()
    : kp()  {
      kp.assign(0.0);
  }
  Keypoint2Df_(const ContainerAllocator& _alloc)
    : kp()  {
  (void)_alloc;
      kp.assign(0.0);
  }



   typedef boost::array<float, 2>  _kp_type;
  _kp_type kp;





  typedef boost::shared_ptr< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> const> ConstPtr;

}; // struct Keypoint2Df_

typedef ::zed_interfaces::Keypoint2Df_<std::allocator<void> > Keypoint2Df;

typedef boost::shared_ptr< ::zed_interfaces::Keypoint2Df > Keypoint2DfPtr;
typedef boost::shared_ptr< ::zed_interfaces::Keypoint2Df const> Keypoint2DfConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::zed_interfaces::Keypoint2Df_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::zed_interfaces::Keypoint2Df_<ContainerAllocator1> & lhs, const ::zed_interfaces::Keypoint2Df_<ContainerAllocator2> & rhs)
{
  return lhs.kp == rhs.kp;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::zed_interfaces::Keypoint2Df_<ContainerAllocator1> & lhs, const ::zed_interfaces::Keypoint2Df_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace zed_interfaces

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cf5ebcd50ce370a9811fce73a9095e7b";
  }

  static const char* value(const ::zed_interfaces::Keypoint2Df_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcf5ebcd50ce370a9ULL;
  static const uint64_t static_value2 = 0x811fce73a9095e7bULL;
};

template<class ContainerAllocator>
struct DataType< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
{
  static const char* value()
  {
    return "zed_interfaces/Keypoint2Df";
  }

  static const char* value(const ::zed_interfaces::Keypoint2Df_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32[2] kp\n"
;
  }

  static const char* value(const ::zed_interfaces::Keypoint2Df_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.kp);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Keypoint2Df_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::zed_interfaces::Keypoint2Df_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::zed_interfaces::Keypoint2Df_<ContainerAllocator>& v)
  {
    s << indent << "kp[]" << std::endl;
    for (size_t i = 0; i < v.kp.size(); ++i)
    {
      s << indent << "  kp[" << i << "]: ";
      Printer<float>::stream(s, indent + "  ", v.kp[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ZED_INTERFACES_MESSAGE_KEYPOINT2DF_H