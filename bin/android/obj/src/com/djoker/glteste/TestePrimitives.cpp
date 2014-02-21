#include <hxcpp.h>

#ifndef INCLUDED_com_djoker_glteste_TestePrimitives
#include <com/djoker/glteste/TestePrimitives.h>
#endif
#ifndef INCLUDED_com_engine_game_Game
#include <com/engine/game/Game.h>
#endif
#ifndef INCLUDED_com_engine_game_Screen
#include <com/engine/game/Screen.h>
#endif
#ifndef INCLUDED_com_engine_game_Transform
#include <com/engine/game/Transform.h>
#endif
#ifndef INCLUDED_com_engine_render_BatchPrimitives
#include <com/engine/render/BatchPrimitives.h>
#endif
#ifndef INCLUDED_com_engine_render_Buffer
#include <com/engine/render/Buffer.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_openfl_display_DirectRenderer
#include <openfl/display/DirectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_OpenGLView
#include <openfl/display/OpenGLView.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void TestePrimitives_obj::__construct()
{
HX_STACK_PUSH("TestePrimitives::new","com/djoker/glteste/TestePrimitives.hx",17);
{
	HX_STACK_LINE(17)
	super::__construct();
}
;
	return null();
}

TestePrimitives_obj::~TestePrimitives_obj() { }

Dynamic TestePrimitives_obj::__CreateEmpty() { return  new TestePrimitives_obj; }
hx::ObjectPtr< TestePrimitives_obj > TestePrimitives_obj::__new()
{  hx::ObjectPtr< TestePrimitives_obj > result = new TestePrimitives_obj();
	result->__construct();
	return result;}

Dynamic TestePrimitives_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TestePrimitives_obj > result = new TestePrimitives_obj();
	result->__construct();
	return result;}

Void TestePrimitives_obj::render( Float dt){
{
		HX_STACK_PUSH("TestePrimitives::render","com/djoker/glteste/TestePrimitives.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(50)
		this->batch->begin();
		HX_STACK_LINE(52)
		this->batch->renderMode(false);
		HX_STACK_LINE(53)
		this->batch->line((int)10,(int)10,(int)100,(int)100,(int)1,(int)0,(int)1,null());
		HX_STACK_LINE(54)
		this->batch->rect((int)100,(int)100,(int)90,(int)120,(int)1,(int)1,(int)1,null());
		HX_STACK_LINE(55)
		this->batch->circle((int)100,(int)100,(int)12,(int)8,(int)1,(int)1,(int)1,(int)1);
		HX_STACK_LINE(56)
		this->batch->ellipse((int)300,(int)90,(int)55,(int)15,(int)8,(int)1,(int)1,(int)1,(int)1);
		HX_STACK_LINE(57)
		this->batch->render();
		HX_STACK_LINE(59)
		this->batch->renderMode(true);
		HX_STACK_LINE(60)
		this->batch->fillrect((int)200,(int)200,(int)50,(int)50,(int)1,(int)0,(int)0,(int)1);
		HX_STACK_LINE(61)
		this->batch->fillrect((int)280,(int)200,(int)50,(int)50,(int)1,(int)0,(int)1,(int)1);
		HX_STACK_LINE(62)
		this->batch->fillcircle((int)200,(int)100,(int)8,(int)18,(int)1,(int)1,(int)1,(int)1);
		HX_STACK_LINE(63)
		this->batch->fillellipse((int)300,(int)100,(int)55,(int)15,(int)8,(int)1,(int)1,(int)1,(int)1);
		HX_STACK_LINE(64)
		this->batch->render();
		HX_STACK_LINE(66)
		this->batch->end();
	}
return null();
}


Void TestePrimitives_obj::show( ){
{
		HX_STACK_PUSH("TestePrimitives::show","com/djoker/glteste/TestePrimitives.hx",28);
		HX_STACK_THIS(this);
		HX_STACK_LINE(32)
		this->batch = ::com::engine::render::BatchPrimitives_obj::__new((int)500);
		HX_STACK_LINE(35)
		::flash::text::TextField caption = ::flash::text::TextField_obj::__new();		HX_STACK_VAR(caption,"caption");
		HX_STACK_LINE(36)
		caption->set_x(((Float(this->game->gameWidth) / Float((int)2)) - (int)100));
		HX_STACK_LINE(37)
		caption->set_y((int)20);
		HX_STACK_LINE(38)
		caption->set_width((int)200);
		HX_STACK_LINE(39)
		caption->set_defaultTextFormat(::flash::text::TextFormat_obj::__new(HX_CSTRING("_sans"),(int)12,(int)11141375,null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
		HX_STACK_LINE(40)
		caption->set_text(HX_CSTRING("Teste Primitives Batch"));
		HX_STACK_LINE(41)
		this->game->addChild(caption);
	}
return null();
}



TestePrimitives_obj::TestePrimitives_obj()
{
}

void TestePrimitives_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TestePrimitives);
	HX_MARK_MEMBER_NAME(batch,"batch");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TestePrimitives_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(batch,"batch");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TestePrimitives_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"batch") ) { return batch; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TestePrimitives_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"batch") ) { batch=inValue.Cast< ::com::engine::render::BatchPrimitives >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TestePrimitives_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("batch"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	HX_CSTRING("show"),
	HX_CSTRING("batch"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TestePrimitives_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TestePrimitives_obj::__mClass,"__mClass");
};

Class TestePrimitives_obj::__mClass;

void TestePrimitives_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.TestePrimitives"), hx::TCanCast< TestePrimitives_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TestePrimitives_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
