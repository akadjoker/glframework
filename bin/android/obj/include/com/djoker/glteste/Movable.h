#ifndef INCLUDED_com_djoker_glteste_Movable
#define INCLUDED_com_djoker_glteste_Movable

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Bitmap.h>
HX_DECLARE_CLASS3(com,djoker,glteste,Movable)
HX_DECLARE_CLASS2(flash,display,Bitmap)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,PixelSnapping)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
namespace com{
namespace djoker{
namespace glteste{


class HXCPP_CLASS_ATTRIBUTES  Movable_obj : public ::flash::display::Bitmap_obj{
	public:
		typedef ::flash::display::Bitmap_obj super;
		typedef Movable_obj OBJ_;
		Movable_obj();
		Void __construct(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,Dynamic smoothing);

	public:
		static hx::ObjectPtr< Movable_obj > __new(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,Dynamic smoothing);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Movable_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Movable"); }

		virtual Void move( Float dt);
		Dynamic move_dyn();

		virtual Void init( );
		Dynamic init_dyn();

		Float da;
		Float dy;
		Float dx;
};

} // end namespace com
} // end namespace djoker
} // end namespace glteste

#endif /* INCLUDED_com_djoker_glteste_Movable */ 
