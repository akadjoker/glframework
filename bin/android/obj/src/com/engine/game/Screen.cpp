#include <hxcpp.h>

#ifndef INCLUDED_com_engine_game_Game
#include <com/engine/game/Game.h>
#endif
#ifndef INCLUDED_com_engine_game_Screen
#include <com/engine/game/Screen.h>
#endif
#ifndef INCLUDED_com_engine_game_Transform
#include <com/engine/game/Transform.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_openfl_display_DirectRenderer
#include <openfl/display/DirectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_OpenGLView
#include <openfl/display/OpenGLView.h>
#endif
namespace com{
namespace engine{
namespace game{

Void Screen_obj::__construct()
{
HX_STACK_PUSH("Screen::new","com/engine/game/Screen.hx",7);
{
	HX_STACK_LINE(10)
	this->game = null();
	HX_STACK_LINE(7)
	super::__construct();
}
;
	return null();
}

Screen_obj::~Screen_obj() { }

Dynamic Screen_obj::__CreateEmpty() { return  new Screen_obj; }
hx::ObjectPtr< Screen_obj > Screen_obj::__new()
{  hx::ObjectPtr< Screen_obj > result = new Screen_obj();
	result->__construct();
	return result;}

Dynamic Screen_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Screen_obj > result = new Screen_obj();
	result->__construct();
	return result;}

Void Screen_obj::keyUp( int key){
{
		HX_STACK_PUSH("Screen::keyUp","com/engine/game/Screen.hx",21);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Screen_obj,keyUp,(void))

Void Screen_obj::keyDown( int key){
{
		HX_STACK_PUSH("Screen::keyDown","com/engine/game/Screen.hx",20);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Screen_obj,keyDown,(void))

Void Screen_obj::mouseDown( Float mousex,Float mousey){
{
		HX_STACK_PUSH("Screen::mouseDown","com/engine/game/Screen.hx",19);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Screen_obj,mouseDown,(void))

Void Screen_obj::mouseUp( Float mousex,Float mousey){
{
		HX_STACK_PUSH("Screen::mouseUp","com/engine/game/Screen.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Screen_obj,mouseUp,(void))

Void Screen_obj::mouseMove( Float mousex,Float mousey){
{
		HX_STACK_PUSH("Screen::mouseMove","com/engine/game/Screen.hx",17);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Screen_obj,mouseMove,(void))

Void Screen_obj::resize( int width,int height){
{
		HX_STACK_PUSH("Screen::resize","com/engine/game/Screen.hx",15);
		HX_STACK_THIS(this);
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Screen_obj,resize,(void))

Void Screen_obj::render( Float dt){
{
		HX_STACK_PUSH("Screen::render","com/engine/game/Screen.hx",14);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Screen_obj,render,(void))

Void Screen_obj::dispose( ){
{
		HX_STACK_PUSH("Screen::dispose","com/engine/game/Screen.hx",13);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Screen_obj,dispose,(void))

Void Screen_obj::show( ){
{
		HX_STACK_PUSH("Screen::show","com/engine/game/Screen.hx",12);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Screen_obj,show,(void))


Screen_obj::Screen_obj()
{
}

void Screen_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Screen);
	HX_MARK_MEMBER_NAME(game,"game");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Screen_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(game,"game");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Screen_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		if (HX_FIELD_EQ(inName,"game") ) { return game; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"keyUp") ) { return keyUp_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"keyDown") ) { return keyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseUp") ) { return mouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseMove") ) { return mouseMove_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Screen_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"game") ) { game=inValue.Cast< ::com::engine::game::Game >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Screen_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("game"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("keyUp"),
	HX_CSTRING("keyDown"),
	HX_CSTRING("mouseDown"),
	HX_CSTRING("mouseUp"),
	HX_CSTRING("mouseMove"),
	HX_CSTRING("resize"),
	HX_CSTRING("render"),
	HX_CSTRING("dispose"),
	HX_CSTRING("show"),
	HX_CSTRING("game"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Screen_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Screen_obj::__mClass,"__mClass");
};

Class Screen_obj::__mClass;

void Screen_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.game.Screen"), hx::TCanCast< Screen_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Screen_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace game
