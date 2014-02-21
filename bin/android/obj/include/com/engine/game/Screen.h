#ifndef INCLUDED_com_engine_game_Screen
#define INCLUDED_com_engine_game_Screen

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/game/Transform.h>
HX_DECLARE_CLASS3(com,engine,game,Game)
HX_DECLARE_CLASS3(com,engine,game,Screen)
HX_DECLARE_CLASS3(com,engine,game,Transform)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(openfl,display,DirectRenderer)
HX_DECLARE_CLASS2(openfl,display,OpenGLView)
namespace com{
namespace engine{
namespace game{


class HXCPP_CLASS_ATTRIBUTES  Screen_obj : public ::com::engine::game::Transform_obj{
	public:
		typedef ::com::engine::game::Transform_obj super;
		typedef Screen_obj OBJ_;
		Screen_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Screen_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Screen_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Screen"); }

		virtual Void keyUp( int key);
		Dynamic keyUp_dyn();

		virtual Void keyDown( int key);
		Dynamic keyDown_dyn();

		virtual Void mouseDown( Float mousex,Float mousey);
		Dynamic mouseDown_dyn();

		virtual Void mouseUp( Float mousex,Float mousey);
		Dynamic mouseUp_dyn();

		virtual Void mouseMove( Float mousex,Float mousey);
		Dynamic mouseMove_dyn();

		virtual Void resize( int width,int height);
		Dynamic resize_dyn();

		virtual Void render( Float dt);
		Dynamic render_dyn();

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void show( );
		Dynamic show_dyn();

		::com::engine::game::Game game;
};

} // end namespace com
} // end namespace engine
} // end namespace game

#endif /* INCLUDED_com_engine_game_Screen */ 
