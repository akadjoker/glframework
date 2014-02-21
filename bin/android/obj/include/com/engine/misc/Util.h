#ifndef INCLUDED_com_engine_misc_Util
#define INCLUDED_com_engine_misc_Util

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,misc,Util)
namespace com{
namespace engine{
namespace misc{


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

		virtual int getExponantOfTwo( int value,int max);
		Dynamic getExponantOfTwo_dyn();

		virtual Float rad2deg( Float rad);
		Dynamic rad2deg_dyn();

		static Float DEG;
		static Float RAD;
		static Float EPSILON;
		static Float randf( Float max,Float min);
		static Dynamic randf_dyn();

		static int randi( int max,int min);
		static Dynamic randi_dyn();

		static bool WithinEpsilon( Float a,Float b);
		static Dynamic WithinEpsilon_dyn();

		static Float getColorValue( int color);
		static Dynamic getColorValue_dyn();

		static Float deg2rad( Float deg);
		static Dynamic deg2rad_dyn();

		static Void print( Dynamic s);
		static Dynamic print_dyn();

		static Dynamic deepCopy( Dynamic arr);
		static Dynamic deepCopy_dyn();

		static Dynamic copy( Dynamic value);
		static Dynamic copy_dyn();

		static int getNextPowerOfTwo( int number);
		static Dynamic getNextPowerOfTwo_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace misc

#endif /* INCLUDED_com_engine_misc_Util */ 
