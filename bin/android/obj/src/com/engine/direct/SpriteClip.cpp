#include <hxcpp.h>

#ifndef INCLUDED_com_engine_direct_SpriteClip
#include <com/engine/direct/SpriteClip.h>
#endif
namespace com{
namespace engine{
namespace direct{

Void SpriteClip_obj::__construct(int x,int y,int width,int height,int offsetX,int offsetY)
{
HX_STACK_PUSH("SpriteClip::new","com/engine/direct/SpriteClip.hx",18);
{
	HX_STACK_LINE(20)
	this->x = x;
	HX_STACK_LINE(21)
	this->y = y;
	HX_STACK_LINE(22)
	this->width = width;
	HX_STACK_LINE(23)
	this->height = height;
	HX_STACK_LINE(24)
	this->offsetX = offsetX;
	HX_STACK_LINE(25)
	this->offsetY = offsetY;
}
;
	return null();
}

SpriteClip_obj::~SpriteClip_obj() { }

Dynamic SpriteClip_obj::__CreateEmpty() { return  new SpriteClip_obj; }
hx::ObjectPtr< SpriteClip_obj > SpriteClip_obj::__new(int x,int y,int width,int height,int offsetX,int offsetY)
{  hx::ObjectPtr< SpriteClip_obj > result = new SpriteClip_obj();
	result->__construct(x,y,width,height,offsetX,offsetY);
	return result;}

Dynamic SpriteClip_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SpriteClip_obj > result = new SpriteClip_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3],inArgs[4],inArgs[5]);
	return result;}


SpriteClip_obj::SpriteClip_obj()
{
}

void SpriteClip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SpriteClip);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(offsetY,"offsetY");
	HX_MARK_MEMBER_NAME(offsetX,"offsetX");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_END_CLASS();
}

void SpriteClip_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(offsetY,"offsetY");
	HX_VISIT_MEMBER_NAME(offsetX,"offsetX");
	HX_VISIT_MEMBER_NAME(height,"height");
}

Dynamic SpriteClip_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"offsetY") ) { return offsetY; }
		if (HX_FIELD_EQ(inName,"offsetX") ) { return offsetX; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SpriteClip_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"offsetY") ) { offsetY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"offsetX") ) { offsetX=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SpriteClip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("offsetY"));
	outFields->push(HX_CSTRING("offsetX"));
	outFields->push(HX_CSTRING("height"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("width"),
	HX_CSTRING("offsetY"),
	HX_CSTRING("offsetX"),
	HX_CSTRING("height"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpriteClip_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SpriteClip_obj::__mClass,"__mClass");
};

Class SpriteClip_obj::__mClass;

void SpriteClip_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.direct.SpriteClip"), hx::TCanCast< SpriteClip_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SpriteClip_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace direct
