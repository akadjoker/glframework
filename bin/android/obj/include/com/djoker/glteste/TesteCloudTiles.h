#ifndef INCLUDED_com_djoker_glteste_TesteCloudTiles
#define INCLUDED_com_djoker_glteste_TesteCloudTiles

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/game/Screen.h>
HX_DECLARE_CLASS3(com,djoker,glteste,TesteCloudTiles)
HX_DECLARE_CLASS3(com,engine,game,Screen)
HX_DECLARE_CLASS3(com,engine,game,Transform)
HX_DECLARE_CLASS3(com,engine,math,Vector3)
HX_DECLARE_CLASS3(com,engine,render,BatchPrimitives)
HX_DECLARE_CLASS3(com,engine,render,Buffer)
HX_DECLARE_CLASS3(com,engine,render,SpriteCloud)
HX_DECLARE_CLASS3(com,engine,render,TileMap)
namespace com{
namespace djoker{
namespace glteste{


class HXCPP_CLASS_ATTRIBUTES  TesteCloudTiles_obj : public ::com::engine::game::Screen_obj{
	public:
		typedef ::com::engine::game::Screen_obj super;
		typedef TesteCloudTiles_obj OBJ_;
		TesteCloudTiles_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TesteCloudTiles_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TesteCloudTiles_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TesteCloudTiles"); }

		virtual Void mouseUp( Float mousex,Float mousey);

		virtual Void mouseMove( Float mousex,Float mousey);

		virtual Void mouseDown( Float mousex,Float mousey);

		virtual Void render( Float dt);

		virtual Void show( );

		::com::engine::math::Vector3 lastToutch;
		::com::engine::math::Vector3 Toutch;
		Float disty;
		Float distx;
		bool toutch;
		Float mouseY;
		Float mouseX;
		Float lastmouseY;
		Float lastmouseX;
		::com::engine::render::TileMap tilemap;
		::com::engine::render::BatchPrimitives primitives;
		::com::engine::render::SpriteCloud batch;
};

} // end namespace com
} // end namespace djoker
} // end namespace glteste

#endif /* INCLUDED_com_djoker_glteste_TesteCloudTiles */ 
