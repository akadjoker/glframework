#ifndef INCLUDED_com_engine_math_Matrix
#define INCLUDED_com_engine_math_Matrix

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,math,Matrix)
HX_DECLARE_CLASS3(com,engine,math,Plane)
HX_DECLARE_CLASS3(com,engine,math,Vector3)
namespace com{
namespace engine{
namespace math{


class HXCPP_CLASS_ATTRIBUTES  Matrix_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Matrix_obj OBJ_;
		Matrix_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Matrix_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Matrix_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Matrix"); }

		virtual ::com::engine::math::Matrix clone( );
		Dynamic clone_dyn();

		virtual bool equals( ::com::engine::math::Matrix value);
		Dynamic equals_dyn();

		virtual Array< Float > multiplyToArray( ::com::engine::math::Matrix other,Array< Float > result,int offset);
		Dynamic multiplyToArray_dyn();

		virtual Void multiplyToRef( ::com::engine::math::Matrix other,::com::engine::math::Matrix result);
		Dynamic multiplyToRef_dyn();

		virtual Void copyFrom( ::com::engine::math::Matrix other);
		Dynamic copyFrom_dyn();

		virtual ::com::engine::math::Matrix multiply( ::com::engine::math::Matrix other);
		Dynamic multiply_dyn();

		virtual Void setTranslation( ::com::engine::math::Vector3 vector3);
		Dynamic setTranslation_dyn();

		virtual Void invertToRef( ::com::engine::math::Matrix other);
		Dynamic invertToRef_dyn();

		virtual Void invert( );
		Dynamic invert_dyn();

		virtual Array< Float > toArray( );
		Dynamic toArray_dyn();

		virtual Float determinant( );
		Dynamic determinant_dyn();

		virtual bool isIdentity( );
		Dynamic isIdentity_dyn();

		Array< Float > m;
		static ::com::engine::math::Matrix MatrixMultiply4x4( ::com::engine::math::Matrix A,::com::engine::math::Matrix B);
		static Dynamic MatrixMultiply4x4_dyn();

		static ::com::engine::math::Matrix FromArray( Array< Float > array,hx::Null< int >  offset);
		static Dynamic FromArray_dyn();

		static ::com::engine::math::Matrix FromArrayToRef( Array< Float > array,hx::Null< int >  offset,::com::engine::math::Matrix result);
		static Dynamic FromArrayToRef_dyn();

		static ::com::engine::math::Matrix FromValues( Float m11,Float m12,Float m13,Float m14,Float m21,Float m22,Float m23,Float m24,Float m31,Float m32,Float m33,Float m34,Float m41,Float m42,Float m43,Float m44);
		static Dynamic FromValues_dyn();

		static ::com::engine::math::Matrix FromValuesToRef( Float m11,Float m12,Float m13,Float m14,Float m21,Float m22,Float m23,Float m24,Float m31,Float m32,Float m33,Float m34,Float m41,Float m42,Float m43,Float m44,::com::engine::math::Matrix result);
		static Dynamic FromValuesToRef_dyn();

		static ::com::engine::math::Matrix Identity( );
		static Dynamic Identity_dyn();

		static ::com::engine::math::Matrix IdentityToRef( ::com::engine::math::Matrix result);
		static Dynamic IdentityToRef_dyn();

		static ::com::engine::math::Matrix Zero( );
		static Dynamic Zero_dyn();

		static ::com::engine::math::Matrix RotationX( Float angle);
		static Dynamic RotationX_dyn();

		static ::com::engine::math::Matrix RotationXToRef( Float angle,::com::engine::math::Matrix result);
		static Dynamic RotationXToRef_dyn();

		static ::com::engine::math::Matrix RotationY( Float angle);
		static Dynamic RotationY_dyn();

		static ::com::engine::math::Matrix RotationYToRef( Float angle,::com::engine::math::Matrix result);
		static Dynamic RotationYToRef_dyn();

		static ::com::engine::math::Matrix RotationZ( Float angle);
		static Dynamic RotationZ_dyn();

		static ::com::engine::math::Matrix RotationZToRef( Float angle,::com::engine::math::Matrix result);
		static Dynamic RotationZToRef_dyn();

		static ::com::engine::math::Matrix RotationAxis( ::com::engine::math::Vector3 axis,Float angle);
		static Dynamic RotationAxis_dyn();

		static ::com::engine::math::Matrix RotationYawPitchRoll( Float yaw,Float pitch,Float roll);
		static Dynamic RotationYawPitchRoll_dyn();

		static ::com::engine::math::Matrix RotationYawPitchRollToRef( Float yaw,Float pitch,Float roll,::com::engine::math::Matrix result);
		static Dynamic RotationYawPitchRollToRef_dyn();

		static ::com::engine::math::Matrix Scaling( Float x,Float y,Float z);
		static Dynamic Scaling_dyn();

		static ::com::engine::math::Matrix ScalingToRef( Float x,Float y,Float z,::com::engine::math::Matrix result);
		static Dynamic ScalingToRef_dyn();

		static ::com::engine::math::Matrix Translation( Float x,Float y,Float z);
		static Dynamic Translation_dyn();

		static Void TranslationToRef( Float x,Float y,Float z,::com::engine::math::Matrix result);
		static Dynamic TranslationToRef_dyn();

		static ::com::engine::math::Matrix LookAtLH( ::com::engine::math::Vector3 eye,::com::engine::math::Vector3 target,::com::engine::math::Vector3 up);
		static Dynamic LookAtLH_dyn();

		static ::com::engine::math::Matrix LookAtLHToRef( ::com::engine::math::Vector3 eye,::com::engine::math::Vector3 target,::com::engine::math::Vector3 up,::com::engine::math::Matrix result);
		static Dynamic LookAtLHToRef_dyn();

		static ::com::engine::math::Matrix OrthoLH( Float width,Float height,Float znear,Float zfar);
		static Dynamic OrthoLH_dyn();

		static ::com::engine::math::Matrix OrthoOffCenterLH( Float left,Float right,Float bottom,Float top,Float znear,Float zfar);
		static Dynamic OrthoOffCenterLH_dyn();

		static ::com::engine::math::Matrix OrthoOffCenterLHToRef( Float left,Float right,Float bottom,Float top,Float znear,Float zfar,::com::engine::math::Matrix result);
		static Dynamic OrthoOffCenterLHToRef_dyn();

		static ::com::engine::math::Matrix PerspectiveLH( Float width,Float height,Float znear,Float zfar);
		static Dynamic PerspectiveLH_dyn();

		static ::com::engine::math::Matrix PerspectiveFovLH( Float fov,Float aspect,Float znear,Float zfar);
		static Dynamic PerspectiveFovLH_dyn();

		static ::com::engine::math::Matrix PerspectiveFovLHToRef( Float fov,Float aspect,Float znear,Float zfar,::com::engine::math::Matrix result);
		static Dynamic PerspectiveFovLHToRef_dyn();

		static ::com::engine::math::Matrix Transpose( ::com::engine::math::Matrix matrix);
		static Dynamic Transpose_dyn();

		static ::com::engine::math::Matrix Reflection( ::com::engine::math::Plane plane);
		static Dynamic Reflection_dyn();

		static ::com::engine::math::Matrix create2D( Float x,Float y,hx::Null< Float >  scale,hx::Null< Float >  rotation);
		static Dynamic create2D_dyn();

		static ::com::engine::math::Matrix ReflectionToRef( ::com::engine::math::Plane plane,::com::engine::math::Matrix result);
		static Dynamic ReflectionToRef_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace math

#endif /* INCLUDED_com_engine_math_Matrix */ 
