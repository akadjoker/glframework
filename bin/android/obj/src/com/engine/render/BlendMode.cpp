#include <hxcpp.h>

#ifndef INCLUDED_com_engine_render_BlendMode
#include <com/engine/render/BlendMode.h>
#endif
#ifndef INCLUDED_openfl_gl_GL
#include <openfl/gl/GL.h>
#endif
namespace com{
namespace engine{
namespace render{

Void BlendMode_obj::__construct()
{
	return null();
}

BlendMode_obj::~BlendMode_obj() { }

Dynamic BlendMode_obj::__CreateEmpty() { return  new BlendMode_obj; }
hx::ObjectPtr< BlendMode_obj > BlendMode_obj::__new()
{  hx::ObjectPtr< BlendMode_obj > result = new BlendMode_obj();
	result->__construct();
	return result;}

Dynamic BlendMode_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BlendMode_obj > result = new BlendMode_obj();
	result->__construct();
	return result;}

int BlendMode_obj::NORMAL;

int BlendMode_obj::ADD;

int BlendMode_obj::MULTIPLY;

int BlendMode_obj::SCREEN;

Void BlendMode_obj::setBlend( int mode){
{
		HX_STACK_PUSH("BlendMode::setBlend","com/engine/render/BlendMode.hx",20);
		HX_STACK_ARG(mode,"mode");
		HX_STACK_LINE(20)
		switch( (int)(mode)){
			case (int)0: {
				HX_STACK_LINE(22)
				::openfl::gl::GL_obj::blendFunc((int)1,(int)771);
			}
			;break;
			case (int)1: {
				HX_STACK_LINE(24)
				::openfl::gl::GL_obj::blendFunc((int)770,(int)772);
			}
			;break;
			case (int)2: {
				HX_STACK_LINE(26)
				::openfl::gl::GL_obj::blendFunc((int)774,(int)771);
			}
			;break;
			case (int)3: {
				HX_STACK_LINE(28)
				::openfl::gl::GL_obj::blendFunc((int)770,(int)1);
			}
			;break;
			default: {
				HX_STACK_LINE(30)
				::openfl::gl::GL_obj::blendFunc((int)1,(int)771);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(BlendMode_obj,setBlend,(void))


BlendMode_obj::BlendMode_obj()
{
}

void BlendMode_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BlendMode);
	HX_MARK_END_CLASS();
}

void BlendMode_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic BlendMode_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ADD") ) { return ADD; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"NORMAL") ) { return NORMAL; }
		if (HX_FIELD_EQ(inName,"SCREEN") ) { return SCREEN; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MULTIPLY") ) { return MULTIPLY; }
		if (HX_FIELD_EQ(inName,"setBlend") ) { return setBlend_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BlendMode_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"ADD") ) { ADD=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"NORMAL") ) { NORMAL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SCREEN") ) { SCREEN=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"MULTIPLY") ) { MULTIPLY=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BlendMode_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("NORMAL"),
	HX_CSTRING("ADD"),
	HX_CSTRING("MULTIPLY"),
	HX_CSTRING("SCREEN"),
	HX_CSTRING("setBlend"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BlendMode_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(BlendMode_obj::NORMAL,"NORMAL");
	HX_MARK_MEMBER_NAME(BlendMode_obj::ADD,"ADD");
	HX_MARK_MEMBER_NAME(BlendMode_obj::MULTIPLY,"MULTIPLY");
	HX_MARK_MEMBER_NAME(BlendMode_obj::SCREEN,"SCREEN");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BlendMode_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::NORMAL,"NORMAL");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::ADD,"ADD");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::MULTIPLY,"MULTIPLY");
	HX_VISIT_MEMBER_NAME(BlendMode_obj::SCREEN,"SCREEN");
};

Class BlendMode_obj::__mClass;

void BlendMode_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.BlendMode"), hx::TCanCast< BlendMode_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BlendMode_obj::__boot()
{
	NORMAL= (int)0;
	ADD= (int)1;
	MULTIPLY= (int)2;
	SCREEN= (int)3;
}

} // end namespace com
} // end namespace engine
} // end namespace render
