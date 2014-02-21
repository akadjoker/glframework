#include <hxcpp.h>

#ifndef INCLUDED_com_engine_render_Clip
#include <com/engine/render/Clip.h>
#endif
namespace com{
namespace engine{
namespace render{

Void Clip_obj::__construct(Dynamic __o_x,Dynamic __o_y,Dynamic __o_width,Dynamic __o_height)
{
HX_STACK_PUSH("Clip::new","com/engine/render/Clip.hx",18);
Dynamic x = __o_x.Default(0);
Dynamic y = __o_y.Default(0);
Dynamic width = __o_width.Default(0);
Dynamic height = __o_height.Default(0);
{
	HX_STACK_LINE(19)
	this->x = x;
	HX_STACK_LINE(20)
	this->y = y;
	HX_STACK_LINE(21)
	this->width = width;
	HX_STACK_LINE(22)
	this->height = height;
}
;
	return null();
}

Clip_obj::~Clip_obj() { }

Dynamic Clip_obj::__CreateEmpty() { return  new Clip_obj; }
hx::ObjectPtr< Clip_obj > Clip_obj::__new(Dynamic __o_x,Dynamic __o_y,Dynamic __o_width,Dynamic __o_height)
{  hx::ObjectPtr< Clip_obj > result = new Clip_obj();
	result->__construct(__o_x,__o_y,__o_width,__o_height);
	return result;}

Dynamic Clip_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Clip_obj > result = new Clip_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Void Clip_obj::set( int x,int y,int width,int height){
{
		HX_STACK_PUSH("Clip::set","com/engine/render/Clip.hx",25);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_LINE(26)
		this->x = x;
		HX_STACK_LINE(27)
		this->y = y;
		HX_STACK_LINE(28)
		this->width = width;
		HX_STACK_LINE(29)
		this->height = height;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Clip_obj,set,(void))


Clip_obj::Clip_obj()
{
}

void Clip_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Clip);
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void Clip_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic Clip_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Clip_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
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
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Clip_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Clip_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Clip_obj::__mClass,"__mClass");
};

Class Clip_obj::__mClass;

void Clip_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.Clip"), hx::TCanCast< Clip_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Clip_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
