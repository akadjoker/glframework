#include <hxcpp.h>

#ifndef INCLUDED_com_djoker_glteste_MoveSprite
#include <com/djoker/glteste/MoveSprite.h>
#endif
#ifndef INCLUDED_com_djoker_glteste_TesteDraTiles
#include <com/djoker/glteste/TesteDraTiles.h>
#endif
#ifndef INCLUDED_com_engine_direct_TileBatch
#include <com/engine/direct/TileBatch.h>
#endif
#ifndef INCLUDED_com_engine_direct_TileImage
#include <com/engine/direct/TileImage.h>
#endif
#ifndef INCLUDED_com_engine_game_Screen
#include <com/engine/game/Screen.h>
#endif
#ifndef INCLUDED_com_engine_game_Transform
#include <com/engine/game/Transform.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_MovieClip
#include <flash/display/MovieClip.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void TesteDraTiles_obj::__construct()
{
HX_STACK_PUSH("TesteDraTiles::new","com/djoker/glteste/TesteDraTiles.hx",95);
{
	HX_STACK_LINE(95)
	super::__construct();
}
;
	return null();
}

TesteDraTiles_obj::~TesteDraTiles_obj() { }

Dynamic TesteDraTiles_obj::__CreateEmpty() { return  new TesteDraTiles_obj; }
hx::ObjectPtr< TesteDraTiles_obj > TesteDraTiles_obj::__new()
{  hx::ObjectPtr< TesteDraTiles_obj > result = new TesteDraTiles_obj();
	result->__construct();
	return result;}

Dynamic TesteDraTiles_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TesteDraTiles_obj > result = new TesteDraTiles_obj();
	result->__construct();
	return result;}

Void TesteDraTiles_obj::render( Float dt){
{
		HX_STACK_PUSH("TesteDraTiles::render","com/djoker/glteste/TesteDraTiles.hx",118);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
	}
return null();
}


Void TesteDraTiles_obj::show( ){
{
		HX_STACK_PUSH("TesteDraTiles::show","com/djoker/glteste/TesteDraTiles.hx",102);
		HX_STACK_THIS(this);
		HX_STACK_LINE(103)
		this->bitmapData = ::openfl::Assets_obj::getBitmapData(HX_CSTRING("assets/zazaka.png"),null());
		HX_STACK_LINE(104)
		this->batch = ::com::engine::direct::TileBatch_obj::__new(this->bitmapData);
		HX_STACK_LINE(105)
		this->batch->addTileRect(::flash::geom::Rectangle_obj::__new((int)0,(int)0,(int)64,(int)64),null());
		HX_STACK_LINE(106)
		{
			HX_STACK_LINE(106)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(106)
			while(((_g < (int)200))){
				HX_STACK_LINE(106)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(108)
				::com::djoker::glteste::MoveSprite spr = ::com::djoker::glteste::MoveSprite_obj::__new((int)0,(int)0,(int)0);		HX_STACK_VAR(spr,"spr");
				HX_STACK_LINE(109)
				spr->init();
				HX_STACK_LINE(110)
				this->batch->add(spr);
			}
		}
		HX_STACK_LINE(112)
		::flash::Lib_obj::get_current()->get_stage()->addChild(this->batch);
	}
return null();
}



TesteDraTiles_obj::TesteDraTiles_obj()
{
}

void TesteDraTiles_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TesteDraTiles);
	HX_MARK_MEMBER_NAME(batch,"batch");
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TesteDraTiles_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(batch,"batch");
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TesteDraTiles_obj::__Field(const ::String &inName,bool inCallProp)
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
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TesteDraTiles_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"batch") ) { batch=inValue.Cast< ::com::engine::direct::TileBatch >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { bitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TesteDraTiles_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("batch"));
	outFields->push(HX_CSTRING("bitmapData"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	HX_CSTRING("show"),
	HX_CSTRING("batch"),
	HX_CSTRING("bitmapData"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TesteDraTiles_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TesteDraTiles_obj::__mClass,"__mClass");
};

Class TesteDraTiles_obj::__mClass;

void TesteDraTiles_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.TesteDraTiles"), hx::TCanCast< TesteDraTiles_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TesteDraTiles_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
