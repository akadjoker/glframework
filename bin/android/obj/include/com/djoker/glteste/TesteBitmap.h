#ifndef INCLUDED_com_djoker_glteste_TesteBitmap
#define INCLUDED_com_djoker_glteste_TesteBitmap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/game/Screen.h>
HX_DECLARE_CLASS3(com,djoker,glteste,Movable)
HX_DECLARE_CLASS3(com,djoker,glteste,TesteBitmap)
HX_DECLARE_CLASS3(com,engine,game,Screen)
HX_DECLARE_CLASS3(com,engine,game,Transform)
HX_DECLARE_CLASS2(flash,display,Bitmap)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
namespace com{
namespace djoker{
namespace glteste{


class HXCPP_CLASS_ATTRIBUTES  TesteBitmap_obj : public ::com::engine::game::Screen_obj{
	public:
		typedef ::com::engine::game::Screen_obj super;
		typedef TesteBitmap_obj OBJ_;
		TesteBitmap_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TesteBitmap_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TesteBitmap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TesteBitmap"); }

		virtual Void render( Float dt);

		virtual Void show( );

		virtual Void addParticle( );
		Dynamic addParticle_dyn();

		::flash::display::BitmapData bitmapData;
		Array< ::Dynamic > particles;
};

} // end namespace com
} // end namespace djoker
} // end namespace glteste

#endif /* INCLUDED_com_djoker_glteste_TesteBitmap */ 
