#ifndef INCLUDED_com_engine_direct_Util
#define INCLUDED_com_engine_direct_Util

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,direct,Util)
HX_DECLARE_CLASS2(flash,geom,Matrix)
HX_DECLARE_CLASS2(flash,geom,Rectangle)
namespace com{
namespace engine{
namespace direct{


class HXCPP_CLASS_ATTRIBUTES  Util_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Util_obj OBJ_;
		Util_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Util_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Util_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Util"); }

		static Float EPSILON;
		static int WHITE;
		static int SILVER;
		static int GRAY;
		static int BLACK;
		static int RED;
		static int MAROON;
		static int YELLOW;
		static int OLIVE;
		static int LIME;
		static int GREEN;
		static int AQUA;
		static int TEAL;
		static int BLUE;
		static int NAVY;
		static int FUCHSIA;
		static int PURPLE;
		static Void matrixsetTo( ::flash::geom::Matrix matrix,Float aa,Float ba,Float ca,Float da,Float txa,Float tya);
		static Dynamic matrixsetTo_dyn();

		static Void skew( ::flash::geom::Matrix matrix,Float skewX,Float skewY);
		static Dynamic skew_dyn();

		static bool isEquivalent( Float a,Float b,hx::Null< Float >  epsilon);
		static Dynamic isEquivalent_dyn();

		static Float normalizeAngle( Float angle);
		static Dynamic normalizeAngle_dyn();

		static int getAlpha( int color);
		static Dynamic getAlpha_dyn();

		static int getRed( int color);
		static Dynamic getRed_dyn();

		static int getGreen( int color);
		static Dynamic getGreen_dyn();

		static int getBlue( int color);
		static Dynamic getBlue_dyn();

		static int rgb( int red,int green,int blue);
		static Dynamic rgb_dyn();

		static int argb( int alpha,int red,int green,int blue);
		static Dynamic argb_dyn();

		static ::flash::geom::Rectangle intersect( ::flash::geom::Rectangle rect1,::flash::geom::Rectangle rect2,::flash::geom::Rectangle resultRect);
		static Dynamic intersect_dyn();

		static ::flash::geom::Rectangle fit( ::flash::geom::Rectangle rectangle,::flash::geom::Rectangle into,::flash::geom::Rectangle resultRect);
		static Dynamic fit_dyn();

		static Void setLength( Dynamic array,int newLength);
		static Dynamic setLength_dyn();

		static int indexOf( Dynamic array,Dynamic whatToFind,hx::Null< int >  fromIndex);
		static Dynamic indexOf_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace direct

#endif /* INCLUDED_com_engine_direct_Util */ 
