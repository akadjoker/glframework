#ifndef INCLUDED_com_engine_math_Vector3
#define INCLUDED_com_engine_math_Vector3

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,math,Matrix)
HX_DECLARE_CLASS3(com,engine,math,Vector3)
HX_DECLARE_CLASS3(com,engine,render,Clip)
namespace com{
namespace engine{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Vector3_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vector3_obj OBJ_;
		Vector3_obj();
		Void __construct(Float initialX,Float initialY,Dynamic __o_initialZ);

	public:
		static hx::ObjectPtr< Vector3_obj > __new(Float initialX,Float initialY,Dynamic __o_initialZ);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Vector3_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector3"); }

		virtual Void copyFromFloats( Float x,Float y,Float z);
		Dynamic copyFromFloats_dyn();

		virtual Void copyFrom( ::com::engine::math::Vector3 source);
		Dynamic copyFrom_dyn();

		virtual ::com::engine::math::Vector3 clone( );
		Dynamic clone_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual Float lengthSquared( );
		Dynamic lengthSquared_dyn();

		virtual Float length( );
		Dynamic length_dyn();

		virtual Void divideToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result);
		Dynamic divideToRef_dyn();

		virtual ::com::engine::math::Vector3 divide( ::com::engine::math::Vector3 otherVector);
		Dynamic divide_dyn();

		virtual ::com::engine::math::Vector3 multiplyByFloats( Float x,Float y,Float z);
		Dynamic multiplyByFloats_dyn();

		virtual Void multiplyToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result);
		Dynamic multiplyToRef_dyn();

		virtual ::com::engine::math::Vector3 multiply( ::com::engine::math::Vector3 otherVector);
		Dynamic multiply_dyn();

		virtual Void multiplyInPlace( ::com::engine::math::Vector3 otherVector);
		Dynamic multiplyInPlace_dyn();

		virtual bool equalsToFloats( Float x,Float y,Float z);
		Dynamic equalsToFloats_dyn();

		virtual bool equals( ::com::engine::math::Vector3 otherVector);
		Dynamic equals_dyn();

		virtual Void scaleToRef( Float scale,::com::engine::math::Vector3 result);
		Dynamic scaleToRef_dyn();

		virtual ::com::engine::math::Vector3 scale( Float scale);
		Dynamic scale_dyn();

		virtual Void scaleInPlace( Float scale);
		Dynamic scaleInPlace_dyn();

		virtual ::com::engine::math::Vector3 negate( );
		Dynamic negate_dyn();

		virtual Void subtractFromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Vector3 result);
		Dynamic subtractFromFloatsToRef_dyn();

		virtual ::com::engine::math::Vector3 subtractFromFloats( Float x,Float y,Float z);
		Dynamic subtractFromFloats_dyn();

		virtual Void subtractToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result);
		Dynamic subtractToRef_dyn();

		virtual ::com::engine::math::Vector3 subtract( ::com::engine::math::Vector3 otherVector);
		Dynamic subtract_dyn();

		virtual Void subtractInPlace( ::com::engine::math::Vector3 otherVector);
		Dynamic subtractInPlace_dyn();

		virtual ::com::engine::math::Vector3 addToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result);
		Dynamic addToRef_dyn();

		virtual ::com::engine::math::Vector3 add( ::com::engine::math::Vector3 otherVector);
		Dynamic add_dyn();

		virtual Void addInPlace( ::com::engine::math::Vector3 otherVector);
		Dynamic addInPlace_dyn();

		virtual Array< Float > toArray( Array< Float > array,hx::Null< int >  index);
		Dynamic toArray_dyn();

		virtual Array< Float > asArray( );
		Dynamic asArray_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		virtual Void set( Float initialX,Float initialY,Dynamic initialZ);
		Dynamic set_dyn();

		Float z;
		Float y;
		Float x;
		static ::com::engine::math::Vector3 Sub( ::com::engine::math::Vector3 a,::com::engine::math::Vector3 b);
		static Dynamic Sub_dyn();

		static ::com::engine::math::Vector3 Add( ::com::engine::math::Vector3 a,::com::engine::math::Vector3 b);
		static Dynamic Add_dyn();

		static ::com::engine::math::Vector3 FromArray( Array< Float > array,hx::Null< int >  offset);
		static Dynamic FromArray_dyn();

		static Void FromArrayToRef( Array< Float > array,hx::Null< int >  offset,::com::engine::math::Vector3 result);
		static Dynamic FromArrayToRef_dyn();

		static Void FromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Vector3 result);
		static Dynamic FromFloatsToRef_dyn();

		static ::com::engine::math::Vector3 Zero( );
		static Dynamic Zero_dyn();

		static ::com::engine::math::Vector3 Up( );
		static Dynamic Up_dyn();

		static ::com::engine::math::Vector3 TransformCoordinates( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation);
		static Dynamic TransformCoordinates_dyn();

		static Void TransformCoordinatesToRef( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result);
		static Dynamic TransformCoordinatesToRef_dyn();

		static ::com::engine::math::Vector3 TransformCoordinatesFromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result);
		static Dynamic TransformCoordinatesFromFloatsToRef_dyn();

		static ::com::engine::math::Vector3 TransformNormal( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation);
		static Dynamic TransformNormal_dyn();

		static Void TransformNormalToRef( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result);
		static Dynamic TransformNormalToRef_dyn();

		static Void TransformNormalFromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result);
		static Dynamic TransformNormalFromFloatsToRef_dyn();

		static ::com::engine::math::Vector3 CatmullRom( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 value2,::com::engine::math::Vector3 value3,::com::engine::math::Vector3 value4,Float amount);
		static Dynamic CatmullRom_dyn();

		static ::com::engine::math::Vector3 Clamp( ::com::engine::math::Vector3 value,::com::engine::math::Vector3 min,::com::engine::math::Vector3 max);
		static Dynamic Clamp_dyn();

		static ::com::engine::math::Vector3 Hermite( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 tangent1,::com::engine::math::Vector3 value2,::com::engine::math::Vector3 tangent2,Float amount);
		static Dynamic Hermite_dyn();

		static ::com::engine::math::Vector3 Lerp( ::com::engine::math::Vector3 start,::com::engine::math::Vector3 end,Float amount);
		static Dynamic Lerp_dyn();

		static Float Dot( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right);
		static Dynamic Dot_dyn();

		static ::com::engine::math::Vector3 Cross( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right);
		static Dynamic Cross_dyn();

		static Void CrossToRef( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right,::com::engine::math::Vector3 result);
		static Dynamic CrossToRef_dyn();

		static ::com::engine::math::Vector3 Normalize( ::com::engine::math::Vector3 vector);
		static Dynamic Normalize_dyn();

		static Void NormalizeToRef( ::com::engine::math::Vector3 vector,::com::engine::math::Vector3 result);
		static Dynamic NormalizeToRef_dyn();

		static ::com::engine::math::Vector3 Project( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix world,::com::engine::math::Matrix transform,::com::engine::render::Clip viewport);
		static Dynamic Project_dyn();

		static ::com::engine::math::Vector3 Unproject( ::com::engine::math::Vector3 source,Float viewportWidth,Float viewportHeight,::com::engine::math::Matrix world,::com::engine::math::Matrix view,::com::engine::math::Matrix projection);
		static Dynamic Unproject_dyn();

		static ::com::engine::math::Vector3 Minimize( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right);
		static Dynamic Minimize_dyn();

		static ::com::engine::math::Vector3 Maximize( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right);
		static Dynamic Maximize_dyn();

		static Float Distance( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 value2);
		static Dynamic Distance_dyn();

		static Float DistanceSquared( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 value2);
		static Dynamic DistanceSquared_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace math

#endif /* INCLUDED_com_engine_math_Vector3 */ 
