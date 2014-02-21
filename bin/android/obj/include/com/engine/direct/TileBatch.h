#ifndef INCLUDED_com_engine_direct_TileBatch
#define INCLUDED_com_engine_direct_TileBatch

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flash/display/Sprite.h>
HX_DECLARE_CLASS3(com,engine,direct,SpriteClip)
HX_DECLARE_CLASS3(com,engine,direct,TileBatch)
HX_DECLARE_CLASS3(com,engine,direct,TileImage)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,geom,Point)
HX_DECLARE_CLASS2(flash,geom,Rectangle)
HX_DECLARE_CLASS2(openfl,display,Tilesheet)
namespace com{
namespace engine{
namespace direct{


class HXCPP_CLASS_ATTRIBUTES  TileBatch_obj : public ::flash::display::Sprite_obj{
	public:
		typedef ::flash::display::Sprite_obj super;
		typedef TileBatch_obj OBJ_;
		TileBatch_obj();
		Void __construct(::flash::display::BitmapData image);

	public:
		static hx::ObjectPtr< TileBatch_obj > __new(::flash::display::BitmapData image);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TileBatch_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TileBatch"); }

		virtual int set_numTiles( int v);
		Dynamic set_numTiles_dyn();

		virtual int get_numTiles( );
		Dynamic get_numTiles_dyn();

		virtual Void renderTile( Array< Float > data,int tile,Float mX,Float mY,Float mPivotX,Float mPivotY,Float mScaleX,Float mScaleY,Float mSkewX,Float mSkewY,Float mRotation,Float red,Float green,Float blue,Float alpha);
		Dynamic renderTile_dyn();

		virtual Void renderObject( Array< Float > data,::com::engine::direct::TileImage obj);
		Dynamic renderObject_dyn();

		virtual Void onEnterFrame( ::flash::events::Event e);
		Dynamic onEnterFrame_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual ::com::engine::direct::TileImage remove( ::com::engine::direct::TileImage obj,hx::Null< bool >  Splice);
		Dynamic remove_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual int numObjects( );
		Dynamic numObjects_dyn();

		virtual ::com::engine::direct::TileImage add( ::com::engine::direct::TileImage Object);
		Dynamic add_dyn();

		virtual Void kill( );
		Dynamic kill_dyn();

		virtual Void clear( );
		Dynamic clear_dyn();

		virtual int sortObjects( ::com::engine::direct::TileImage a,::com::engine::direct::TileImage b);
		Dynamic sortObjects_dyn();

		virtual int addTileRect( ::flash::geom::Rectangle rectangle,::flash::geom::Point centerPoint);
		Dynamic addTileRect_dyn();

		virtual ::com::engine::direct::SpriteClip getClip( int index);
		Dynamic getClip_dyn();

		virtual Void parseXML( ::String data);
		Dynamic parseXML_dyn();

		int previousTime;
		int currentTime;
		int numTile;
		int maxSize;
		int length;
		bool sort;
		Array< ::Dynamic > clips;
		Array< ::Dynamic > sprites;
		Array< Float > tileData;
		::openfl::display::Tilesheet tilesheet;
};

} // end namespace com
} // end namespace engine
} // end namespace direct

#endif /* INCLUDED_com_engine_direct_TileBatch */ 
