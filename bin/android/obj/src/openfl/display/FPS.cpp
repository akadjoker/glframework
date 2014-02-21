#include <hxcpp.h>

#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
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
#ifndef INCLUDED_haxe_Timer
#include <haxe/Timer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
#endif
namespace openfl{
namespace display{

Void FPS_obj::__construct(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< int >  __o_color)
{
HX_STACK_PUSH("FPS::new","openfl/display/FPS.hx",17);
Float x = __o_x.Default(10);
Float y = __o_y.Default(10);
int color = __o_color.Default(0);
{
	HX_STACK_LINE(19)
	super::__construct();
	HX_STACK_LINE(21)
	this->set_x(x);
	HX_STACK_LINE(22)
	this->set_y(y);
	HX_STACK_LINE(24)
	this->set_selectable(false);
	HX_STACK_LINE(25)
	this->set_defaultTextFormat(::flash::text::TextFormat_obj::__new(HX_CSTRING("_sans"),(int)12,color,null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
	HX_STACK_LINE(26)
	this->set_text(HX_CSTRING("FPS: "));
	HX_STACK_LINE(28)
	this->cacheCount = (int)0;
	HX_STACK_LINE(29)
	this->times = Array_obj< Float >::__new();
	HX_STACK_LINE(31)
	this->addEventListener(::flash::events::Event_obj::ENTER_FRAME,this->this_onEnterFrame_dyn(),null(),null(),null());
}
;
	return null();
}

FPS_obj::~FPS_obj() { }

Dynamic FPS_obj::__CreateEmpty() { return  new FPS_obj; }
hx::ObjectPtr< FPS_obj > FPS_obj::__new(hx::Null< Float >  __o_x,hx::Null< Float >  __o_y,hx::Null< int >  __o_color)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(__o_x,__o_y,__o_color);
	return result;}

Dynamic FPS_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< FPS_obj > result = new FPS_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void FPS_obj::this_onEnterFrame( ::flash::events::Event event){
{
		HX_STACK_PUSH("FPS::this_onEnterFrame","openfl/display/FPS.hx",43);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(45)
		Float currentTime = ::haxe::Timer_obj::stamp();		HX_STACK_VAR(currentTime,"currentTime");
		HX_STACK_LINE(46)
		this->times->push(currentTime);
		HX_STACK_LINE(48)
		while(((this->times->__get((int)0) < (currentTime - (int)1)))){
			HX_STACK_LINE(48)
			this->times->shift();
		}
		HX_STACK_LINE(54)
		int currentCount = this->times->length;		HX_STACK_VAR(currentCount,"currentCount");
		HX_STACK_LINE(56)
		if (((bool((currentCount != this->cacheCount)) && bool(this->get_visible())))){
			HX_STACK_LINE(56)
			this->set_text((HX_CSTRING("FPS: ") + ::Math_obj::round((Float(((currentCount + this->cacheCount))) / Float((int)2)))));
		}
		HX_STACK_LINE(62)
		this->cacheCount = currentCount;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(FPS_obj,this_onEnterFrame,(void))


FPS_obj::FPS_obj()
{
}

void FPS_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(FPS);
	HX_MARK_MEMBER_NAME(times,"times");
	HX_MARK_MEMBER_NAME(cacheCount,"cacheCount");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void FPS_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(times,"times");
	HX_VISIT_MEMBER_NAME(cacheCount,"cacheCount");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic FPS_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { return times; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cacheCount") ) { return cacheCount; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"this_onEnterFrame") ) { return this_onEnterFrame_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic FPS_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"times") ) { times=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"cacheCount") ) { cacheCount=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void FPS_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("times"));
	outFields->push(HX_CSTRING("cacheCount"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("this_onEnterFrame"),
	HX_CSTRING("times"),
	HX_CSTRING("cacheCount"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(FPS_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(FPS_obj::__mClass,"__mClass");
};

Class FPS_obj::__mClass;

void FPS_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("openfl.display.FPS"), hx::TCanCast< FPS_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void FPS_obj::__boot()
{
}

} // end namespace openfl
} // end namespace display
