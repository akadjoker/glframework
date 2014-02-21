#ifndef INCLUDED_com_djoker_glteste_TesteBatch
#define INCLUDED_com_djoker_glteste_TesteBatch

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/game/Screen.h>
HX_DECLARE_CLASS3(com,djoker,glteste,Particle)
HX_DECLARE_CLASS3(com,djoker,glteste,TesteBatch)
HX_DECLARE_CLASS3(com,engine,game,Screen)
HX_DECLARE_CLASS3(com,engine,game,Transform)
HX_DECLARE_CLASS3(com,engine,render,Buffer)
HX_DECLARE_CLASS3(com,engine,render,Image)
HX_DECLARE_CLASS3(com,engine,render,SpriteBatch)
HX_DECLARE_CLASS3(com,engine,render,Texture)
namespace com{
namespace djoker{
namespace glteste{


class HXCPP_CLASS_ATTRIBUTES  TesteBatch_obj : public ::com::engine::game::Screen_obj{
	public:
		typedef ::com::engine::game::Screen_obj super;
		typedef TesteBatch_obj OBJ_;
		TesteBatch_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TesteBatch_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TesteBatch_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TesteBatch"); }

		virtual Void mouseDown( Float mousex,Float mousey);

		virtual Void addParticle2( Float x,Float y);
		Dynamic addParticle2_dyn();

		virtual Void addParticle( );
		Dynamic addParticle_dyn();

		virtual Void render( Float dt);

		virtual Void show( );

		Array< ::Dynamic > particles;
		::com::engine::render::SpriteBatch batch;
		::com::engine::render::Texture tex;
};

} // end namespace com
} // end namespace djoker
} // end namespace glteste

#endif /* INCLUDED_com_djoker_glteste_TesteBatch */ 
