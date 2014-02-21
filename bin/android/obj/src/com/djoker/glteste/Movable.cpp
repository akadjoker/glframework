#include <hxcpp.h>

#ifndef INCLUDED_com_djoker_glteste_Movable
#include <com/djoker/glteste/Movable.h>
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
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_PixelSnapping
#include <flash/display/PixelSnapping.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void Movable_obj::__construct(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,Dynamic smoothing)
{
HX_STACK_PUSH("Movable::new","com/djoker/glteste/Movable.hx",8);
{
	HX_STACK_LINE(8)
	super::__construct(bitmapData,pixelSnapping,smoothing);
}
;
	return null();
}

Movable_obj::~Movable_obj() { }

Dynamic Movable_obj::__CreateEmpty() { return  new Movable_obj; }
hx::ObjectPtr< Movable_obj > Movable_obj::__new(::flash::display::BitmapData bitmapData,::flash::display::PixelSnapping pixelSnapping,Dynamic smoothing)
{  hx::ObjectPtr< Movable_obj > result = new Movable_obj();
	result->__construct(bitmapData,pixelSnapping,smoothing);
	return result;}

Dynamic Movable_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Movable_obj > result = new Movable_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Movable_obj::move( Float dt){
{
		HX_STACK_PUSH("Movable::move","com/djoker/glteste/Movable.hx",48);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(49)
		Float rad = ((int)30 * this->get_scaleX());		HX_STACK_VAR(rad,"rad");
		HX_STACK_LINE(51)
		{
			HX_STACK_LINE(51)
			::com::djoker::glteste::Movable _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(51)
			_g->set_x((_g->get_x() + (this->dx * dt)));
		}
		HX_STACK_LINE(52)
		if (((this->get_x() < rad))){
			HX_STACK_LINE(54)
			this->set_x(rad);
			HX_STACK_LINE(55)
			this->dx = -(this->dx);
		}
		HX_STACK_LINE(57)
		if (((this->get_x() > ((int)640 - rad)))){
			HX_STACK_LINE(59)
			this->set_x(((int)640 - rad));
			HX_STACK_LINE(60)
			this->dx = -(this->dx);
		}
		HX_STACK_LINE(63)
		{
			HX_STACK_LINE(63)
			::com::djoker::glteste::Movable _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(63)
			_g->set_y((_g->get_y() + (this->dy * dt)));
		}
		HX_STACK_LINE(64)
		if (((this->get_y() < rad))){
			HX_STACK_LINE(66)
			this->set_y(rad);
			HX_STACK_LINE(67)
			this->dy = -(this->dy);
		}
		HX_STACK_LINE(69)
		if (((this->get_y() > ((int)480 - rad)))){
			HX_STACK_LINE(71)
			this->set_y(((int)480 - rad));
			HX_STACK_LINE(72)
			this->dy = -(this->dy);
		}
		HX_STACK_LINE(75)
		{
			HX_STACK_LINE(75)
			::com::djoker::glteste::Movable _g = hx::ObjectPtr<OBJ_>(this);		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(75)
			_g->set_rotation((_g->get_rotation() + this->da));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Movable_obj,move,(void))

Void Movable_obj::init( ){
{
		HX_STACK_PUSH("Movable::init","com/djoker/glteste/Movable.hx",19);
		HX_STACK_THIS(this);
		HX_STACK_LINE(21)
		this->set_x((int)320);
		HX_STACK_LINE(22)
		this->set_y((int)240);
		HX_STACK_LINE(23)
		this->set_rotation((int)0);
		HX_STACK_LINE(24)
		this->dx = ((::Math_obj::random() * 200.0) - 100.0);
		HX_STACK_LINE(25)
		this->dy = ((::Math_obj::random() * 200.0) - 100.0);
		HX_STACK_LINE(26)
		this->da = ((::Math_obj::random() * 360.2) - 180.1);
		HX_STACK_LINE(34)
		this->set_alpha(::Math_obj::random());
		HX_STACK_LINE(37)
		this->set_scaleX(((::Math_obj::random() * 1.1) + 0.1));
		HX_STACK_LINE(38)
		this->set_scaleY(((::Math_obj::random() * 1.1) + 0.1));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Movable_obj,init,(void))


Movable_obj::Movable_obj()
{
}

void Movable_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Movable);
	HX_MARK_MEMBER_NAME(da,"da");
	HX_MARK_MEMBER_NAME(dy,"dy");
	HX_MARK_MEMBER_NAME(dx,"dx");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Movable_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(da,"da");
	HX_VISIT_MEMBER_NAME(dy,"dy");
	HX_VISIT_MEMBER_NAME(dx,"dx");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Movable_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"da") ) { return da; }
		if (HX_FIELD_EQ(inName,"dy") ) { return dy; }
		if (HX_FIELD_EQ(inName,"dx") ) { return dx; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"move") ) { return move_dyn(); }
		if (HX_FIELD_EQ(inName,"init") ) { return init_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Movable_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"da") ) { da=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dy") ) { dy=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dx") ) { dx=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Movable_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("da"));
	outFields->push(HX_CSTRING("dy"));
	outFields->push(HX_CSTRING("dx"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("move"),
	HX_CSTRING("init"),
	HX_CSTRING("da"),
	HX_CSTRING("dy"),
	HX_CSTRING("dx"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Movable_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Movable_obj::__mClass,"__mClass");
};

Class Movable_obj::__mClass;

void Movable_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.Movable"), hx::TCanCast< Movable_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Movable_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
