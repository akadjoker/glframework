#ifndef INCLUDED_com_engine_math_Quaternion
#define INCLUDED_com_engine_math_Quaternion

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,math,Matrix)
HX_DECLARE_CLASS3(com,engine,math,Quaternion)
HX_DECLARE_CLASS3(com,engine,math,Vector3)
namespace com{
namespace engine{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Quaternion_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Quaternion_obj OBJ_;
		Quaternion_obj();
		Void __construct(hx::Null< Float >  __o_initialX,hx::Null< Float >  __o_initialY,hx::Null< Float >  __o_initialZ,hx::Null< Float >  __o_initialW);

	public:
		static hx::ObjectPtr< Quaternion_obj > __new(hx::Null< Float >  __o_initialX,hx::Null< Float >  __o_initialY,hx::Null< Float >  __o_initialZ,hx::Null< Float >  __o_initialW);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Quaternion_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Quaternion"); }

		virtual ::com::engine::math::Matrix toRotationMatrix( ::com::engine::math::Matrix result);
		Dynamic toRotationMatrix_dyn();

		virtual ::com::engine::math::Vector3 toEulerAngles( );
		Dynamic toEulerAngles_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual Float length( );
		Dynamic length_dyn();

		virtual ::com::engine::math::Quaternion multiplyToRef( ::com::engine::math::Quaternion q1,::com::engine::math::Quaternion result);
		Dynamic multiplyToRef_dyn();

		virtual ::com::engine::math::Quaternion multiply( ::com::engine::math::Quaternion q1);
		Dynamic multiply_dyn();

		virtual ::com::engine::math::Quaternion scale( Float value);
		Dynamic scale_dyn();

		virtual ::com::engine::math::Quaternion add( ::com::engine::math::Quaternion other);
		Dynamic add_dyn();

		virtual Void copyFrom( ::com::engine::math::Quaternion other);
		Dynamic copyFrom_dyn();

		virtual ::com::engine::math::Quaternion clone( );
		Dynamic clone_dyn();

		virtual bool equals( ::com::engine::math::Quaternion otherQuaternion);
		Dynamic equals_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		Float w;
		Float z;
		Float y;
		Float x;
		static ::com::engine::math::Quaternion FromArray( Array< Float > array,hx::Null< int >  offset);
		static Dynamic FromArray_dyn();

		static ::com::engine::math::Quaternion RotationYawPitchRoll( Float yaw,Float pitch,Float roll);
		static Dynamic RotationYawPitchRoll_dyn();

		static ::com::engine::math::Quaternion RotationYawPitchRollToRef( Float yaw,Float pitch,Float roll,::com::engine::math::Quaternion result);
		static Dynamic RotationYawPitchRollToRef_dyn();

		static ::com::engine::math::Quaternion Slerp( ::com::engine::math::Quaternion left,::com::engine::math::Quaternion right,Float amount);
		static Dynamic Slerp_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace math

#endif /* INCLUDED_com_engine_math_Quaternion */ 
