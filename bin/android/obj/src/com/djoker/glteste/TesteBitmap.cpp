#include <hxcpp.h>

#ifndef INCLUDED_com_djoker_glteste_Movable
#include <com/djoker/glteste/Movable.h>
#endif
#ifndef INCLUDED_com_djoker_glteste_TesteBitmap
#include <com/djoker/glteste/TesteBitmap.h>
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
#ifndef INCLUDED_flash_display_Bitmap
#include <flash/display/Bitmap.h>
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
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
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
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void TesteBitmap_obj::__construct()
{
HX_STACK_PUSH("TesteBitmap::new","com/djoker/glteste/TesteBitmap.hx",18);
{
	HX_STACK_LINE(18)
	super::__construct();
}
;
	return null();
}

TesteBitmap_obj::~TesteBitmap_obj() { }

Dynamic TesteBitmap_obj::__CreateEmpty() { return  new TesteBitmap_obj; }
hx::ObjectPtr< TesteBitmap_obj > TesteBitmap_obj::__new()
{  hx::ObjectPtr< TesteBitmap_obj > result = new TesteBitmap_obj();
	result->__construct();
	return result;}

Dynamic TesteBitmap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TesteBitmap_obj > result = new TesteBitmap_obj();
	result->__construct();
	return result;}

Void TesteBitmap_obj::render( Float dt){
{
		HX_STACK_PUSH("TesteBitmap::render","com/djoker/glteste/TesteBitmap.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(44)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< ::Dynamic > _g1 = this->particles;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(44)
		while(((_g < _g1->length))){
			HX_STACK_LINE(44)
			::com::djoker::glteste::Movable p = _g1->__get(_g).StaticCast< ::com::djoker::glteste::Movable >();		HX_STACK_VAR(p,"p");
			HX_STACK_LINE(44)
			++(_g);
			HX_STACK_LINE(46)
			p->move(dt);
		}
	}
return null();
}


Void TesteBitmap_obj::show( ){
{
		HX_STACK_PUSH("TesteBitmap::show","com/djoker/glteste/TesteBitmap.hx",35);
		HX_STACK_THIS(this);
		HX_STACK_LINE(36)
		this->bitmapData = ::openfl::Assets_obj::getBitmapData(HX_CSTRING("assets/zazaka.png"),null());
		HX_STACK_LINE(37)
		this->particles = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(38)
		{
			HX_STACK_LINE(38)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(38)
			while(((_g < (int)200))){
				HX_STACK_LINE(38)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(39)
				this->addParticle();
			}
		}
	}
return null();
}


Void TesteBitmap_obj::addParticle( ){
{
		HX_STACK_PUSH("TesteBitmap::addParticle","com/djoker/glteste/TesteBitmap.hx",27);
		HX_STACK_THIS(this);
		HX_STACK_LINE(28)
		::com::djoker::glteste::Movable particle = ::com::djoker::glteste::Movable_obj::__new(this->bitmapData,null(),null());		HX_STACK_VAR(particle,"particle");
		HX_STACK_LINE(29)
		particle->init();
		HX_STACK_LINE(30)
		this->particles->push(particle);
		HX_STACK_LINE(31)
		::flash::Lib_obj::get_current()->get_stage()->addChild(particle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TesteBitmap_obj,addParticle,(void))


TesteBitmap_obj::TesteBitmap_obj()
{
}

void TesteBitmap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TesteBitmap);
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(particles,"particles");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TesteBitmap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	HX_VISIT_MEMBER_NAME(particles,"particles");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TesteBitmap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"particles") ) { return particles; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"addParticle") ) { return addParticle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TesteBitmap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 9:
		if (HX_FIELD_EQ(inName,"particles") ) { particles=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { bitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TesteBitmap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("particles"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	HX_CSTRING("show"),
	HX_CSTRING("addParticle"),
	HX_CSTRING("bitmapData"),
	HX_CSTRING("particles"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TesteBitmap_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TesteBitmap_obj::__mClass,"__mClass");
};

Class TesteBitmap_obj::__mClass;

void TesteBitmap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.TesteBitmap"), hx::TCanCast< TesteBitmap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TesteBitmap_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
