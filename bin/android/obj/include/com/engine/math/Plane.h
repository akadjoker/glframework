#ifndef INCLUDED_com_engine_math_Plane
#define INCLUDED_com_engine_math_Plane

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,math,Matrix)
HX_DECLARE_CLASS3(com,engine,math,Plane)
HX_DECLARE_CLASS3(com,engine,math,Vector3)
namespace com{
namespace engine{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Plane_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Plane_obj OBJ_;
		Plane_obj();
		Void __construct(Float a,Float b,Float c,Float d);

	public:
		static hx::ObjectPtr< Plane_obj > __new(Float a,Float b,Float c,Float d);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Plane_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Plane"); }

		virtual Float signedDistanceTo( ::com::engine::math::Vector3 point);
		Dynamic signedDistanceTo_dyn();

		virtual bool isFrontFacingTo( ::com::engine::math::Vector3 direction,Float epsilon);
		Dynamic isFrontFacingTo_dyn();

		virtual Void copyFromPoints( ::com::engine::math::Vector3 point1,::com::engine::math::Vector3 point2,::com::engine::math::Vector3 point3);
		Dynamic copyFromPoints_dyn();

		virtual Float dotCoordinate( ::com::engine::math::Vector3 point);
		Dynamic dotCoordinate_dyn();

		virtual ::com::engine::math::Plane transform( ::com::engine::math::Matrix transformation);
		Dynamic transform_dyn();

		virtual Void normalize( );
		Dynamic normalize_dyn();

		virtual ::com::engine::math::Plane clone( );
		Dynamic clone_dyn();

		Float d;
		::com::engine::math::Vector3 normal;
		static ::com::engine::math::Plane FromArray( Array< Float > array);
		static Dynamic FromArray_dyn();

		static ::com::engine::math::Plane FromPoints( ::com::engine::math::Vector3 point1,::com::engine::math::Vector3 point2,::com::engine::math::Vector3 point3);
		static Dynamic FromPoints_dyn();

		static ::com::engine::math::Plane FromPositionAndNormal( ::com::engine::math::Vector3 origin,::com::engine::math::Vector3 normal);
		static Dynamic FromPositionAndNormal_dyn();

		static Float SignedDistanceToPlaneFromPositionAndNormal( ::com::engine::math::Vector3 origin,::com::engine::math::Vector3 normal,::com::engine::math::Vector3 point);
		static Dynamic SignedDistanceToPlaneFromPositionAndNormal_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace math

#endif /* INCLUDED_com_engine_math_Plane */ 
