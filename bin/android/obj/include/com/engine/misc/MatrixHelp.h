#ifndef INCLUDED_com_engine_misc_MatrixHelp
#define INCLUDED_com_engine_misc_MatrixHelp

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,misc,MatrixHelp)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,geom,Matrix)
namespace com{
namespace engine{
namespace misc{


class HXCPP_CLASS_ATTRIBUTES  MatrixHelp_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef MatrixHelp_obj OBJ_;
		MatrixHelp_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< MatrixHelp_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MatrixHelp_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MatrixHelp"); }

		static ::flash::display::BitmapData getScaled( ::flash::display::BitmapData source,int newWidth,int newHeight);
		static Dynamic getScaled_dyn();

		static ::flash::display::BitmapData flipBitmapData( ::flash::display::BitmapData original,::String axis);
		static Dynamic flipBitmapData_dyn();

		static Void skew( ::flash::geom::Matrix matrix,Float skewX,Float skewY);
		static Dynamic skew_dyn();

		static Void setTo( ::flash::geom::Matrix matrix,Float a,Float b,Float c,Float d,Float tx,Float ty);
		static Dynamic setTo_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace misc

#endif /* INCLUDED_com_engine_misc_MatrixHelp */ 
