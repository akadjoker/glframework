#ifndef INCLUDED_com_engine_math_Vector2
#define INCLUDED_com_engine_math_Vector2

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,math,Matrix)
HX_DECLARE_CLASS3(com,engine,math,Vector2)
namespace com{
namespace engine{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Vector2_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Vector2_obj OBJ_;
		Vector2_obj();
		Void __construct(Float x,Float y);

	public:
		static hx::ObjectPtr< Vector2_obj > __new(Float x,Float y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Vector2_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Vector2"); }

		virtual ::com::engine::math::Vector2 clone( );
		Dynamic clone_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual Float lengthSquared( );
		Dynamic lengthSquared_dyn();

		virtual Float length( );
		Dynamic length_dyn();

		virtual bool equals( ::com::engine::math::Vector2 otherVector);
		Dynamic equals_dyn();

		virtual ::com::engine::math::Vector2 scale( Float scale);
		Dynamic scale_dyn();

		virtual Void scaleInPlace( Float scale);
		Dynamic scaleInPlace_dyn();

		virtual ::com::engine::math::Vector2 negate( );
		Dynamic negate_dyn();

		virtual ::com::engine::math::Vector2 subtract( ::com::engine::math::Vector2 otherVector);
		Dynamic subtract_dyn();

		virtual Void toArray( Array< Float > array,hx::Null< int >  index);
		Dynamic toArray_dyn();

		virtual Array< Float > asArray( );
		Dynamic asArray_dyn();

		virtual ::com::engine::math::Vector2 add( ::com::engine::math::Vector2 otherVector);
		Dynamic add_dyn();

		virtual ::String toString( );
		Dynamic toString_dyn();

		Float y;
		Float x;
		static ::com::engine::math::Vector2 Sub( ::com::engine::math::Vector2 a,::com::engine::math::Vector2 b);
		static Dynamic Sub_dyn();

		static ::com::engine::math::Vector2 Add( ::com::engine::math::Vector2 a,::com::engine::math::Vector2 b);
		static Dynamic Add_dyn();

		static ::com::engine::math::Vector2 Zero( );
		static Dynamic Zero_dyn();

		static ::com::engine::math::Vector2 CatmullRom( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 value2,::com::engine::math::Vector2 value3,::com::engine::math::Vector2 value4,Float amount);
		static Dynamic CatmullRom_dyn();

		static ::com::engine::math::Vector2 Clamp( ::com::engine::math::Vector2 value,::com::engine::math::Vector2 min,::com::engine::math::Vector2 max);
		static Dynamic Clamp_dyn();

		static ::com::engine::math::Vector2 Hermite( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 tangent1,::com::engine::math::Vector2 value2,::com::engine::math::Vector2 tangent2,Float amount);
		static Dynamic Hermite_dyn();

		static ::com::engine::math::Vector2 Lerp( ::com::engine::math::Vector2 start,::com::engine::math::Vector2 end,Float amount);
		static Dynamic Lerp_dyn();

		static Float Dot( ::com::engine::math::Vector2 left,::com::engine::math::Vector2 right);
		static Dynamic Dot_dyn();

		static ::com::engine::math::Vector2 Normalize( ::com::engine::math::Vector2 vector);
		static Dynamic Normalize_dyn();

		static ::com::engine::math::Vector2 Minimize( ::com::engine::math::Vector2 left,::com::engine::math::Vector2 right);
		static Dynamic Minimize_dyn();

		static ::com::engine::math::Vector2 Maximize( ::com::engine::math::Vector2 left,::com::engine::math::Vector2 right);
		static Dynamic Maximize_dyn();

		static ::com::engine::math::Vector2 Transform( ::com::engine::math::Vector2 vector,::com::engine::math::Matrix transformation);
		static Dynamic Transform_dyn();

		static Float Distance( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 value2);
		static Dynamic Distance_dyn();

		static Float DistanceSquared( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 value2);
		static Dynamic DistanceSquared_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace math

#endif /* INCLUDED_com_engine_math_Vector2 */ 
