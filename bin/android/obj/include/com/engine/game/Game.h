#ifndef INCLUDED_com_engine_game_Game
#define INCLUDED_com_engine_game_Game

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/display/OpenGLView.h>
HX_DECLARE_CLASS3(com,engine,game,Game)
HX_DECLARE_CLASS3(com,engine,game,Screen)
HX_DECLARE_CLASS3(com,engine,game,Transform)
HX_DECLARE_CLASS3(com,engine,math,Matrix)
HX_DECLARE_CLASS2(flash,display,DisplayObject)
HX_DECLARE_CLASS2(flash,display,DisplayObjectContainer)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(flash,display,InteractiveObject)
HX_DECLARE_CLASS2(flash,display,Sprite)
HX_DECLARE_CLASS2(flash,events,Event)
HX_DECLARE_CLASS2(flash,events,EventDispatcher)
HX_DECLARE_CLASS2(flash,events,IEventDispatcher)
HX_DECLARE_CLASS2(flash,events,KeyboardEvent)
HX_DECLARE_CLASS2(flash,events,MouseEvent)
HX_DECLARE_CLASS2(flash,events,TouchEvent)
HX_DECLARE_CLASS2(flash,geom,Rectangle)
HX_DECLARE_CLASS2(openfl,display,DirectRenderer)
HX_DECLARE_CLASS2(openfl,display,OpenGLView)
namespace com{
namespace engine{
namespace game{


class HXCPP_CLASS_ATTRIBUTES  Game_obj : public ::openfl::display::OpenGLView_obj{
	public:
		typedef ::openfl::display::OpenGLView_obj super;
		typedef Game_obj OBJ_;
		Game_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Game_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Game_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Game"); }

		virtual Void renderView( ::flash::geom::Rectangle rect);
		Dynamic renderView_dyn();

		virtual Void setScreen( ::com::engine::game::Screen screen);
		Dynamic setScreen_dyn();

		virtual Void mouseDown( Float mousex,Float mousey);
		Dynamic mouseDown_dyn();

		virtual Void mouseUp( Float mousex,Float mousey);
		Dynamic mouseUp_dyn();

		virtual Void mouseMove( Float mousex,Float mousey);
		Dynamic mouseMove_dyn();

		virtual Void keyUp( int key);
		Dynamic keyUp_dyn();

		virtual Void keyDown( int key);
		Dynamic keyDown_dyn();

		virtual Void update( Float dt);
		Dynamic update_dyn();

		virtual Void resize( int width,int height);
		Dynamic resize_dyn();

		virtual Void end( );
		Dynamic end_dyn();

		virtual Void begin( );
		Dynamic begin_dyn();

		virtual Void onResize( ::flash::events::Event e);
		Dynamic onResize_dyn();

		virtual Void focusLost( ::flash::events::Event e);
		Dynamic focusLost_dyn();

		virtual Void doTouchMove( ::flash::events::TouchEvent event);
		Dynamic doTouchMove_dyn();

		virtual Void doTouchUp( ::flash::events::TouchEvent event);
		Dynamic doTouchUp_dyn();

		virtual Void doTouchDown( ::flash::events::TouchEvent event);
		Dynamic doTouchDown_dyn();

		virtual Void doMouseMove( ::flash::events::MouseEvent event);
		Dynamic doMouseMove_dyn();

		virtual Void doMouseUp( ::flash::events::MouseEvent event);
		Dynamic doMouseUp_dyn();

		virtual Void doMouseDown( ::flash::events::MouseEvent event);
		Dynamic doMouseDown_dyn();

		virtual Void stage_onKeyUp( ::flash::events::KeyboardEvent event);
		Dynamic stage_onKeyUp_dyn();

		virtual Void stage_onKeyDown( ::flash::events::KeyboardEvent event);
		Dynamic stage_onKeyDown_dyn();

		virtual Void focusGained( ::flash::events::Event e);
		Dynamic focusGained_dyn();

		virtual Void addedToStage( ::flash::events::Event e);
		Dynamic addedToStage_dyn();

		virtual Void addChild( ::flash::display::DisplayObject child);
		Dynamic addChild_dyn();

		virtual Void removeChild( ::flash::display::DisplayObject child);
		Dynamic removeChild_dyn();

		virtual Void fixRatio( int w,int h);
		Dynamic fixRatio_dyn();

		bool rescale;
		int gameHeight;
		int gameWidth;
		int screenHeight;
		int screenWidth;
		::flash::display::Sprite container;
		::com::engine::game::Screen screen;
		bool mMultiTouch;
		int nextFrame;
		int prevFrame;
		Float deltaTime;
		bool ready;
		::flash::geom::Rectangle viewPort;
		static Float scrollX;
		static Float scrollY;
		static Float viewWidth;
		static Float viewHeight;
		static ::com::engine::math::Matrix projMatrix;
		static ::com::engine::math::Matrix viewMatrix;
};

} // end namespace com
} // end namespace engine
} // end namespace game

#endif /* INCLUDED_com_engine_game_Game */ 
