#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_djoker_glteste_Particle
#include <com/djoker/glteste/Particle.h>
#endif
#ifndef INCLUDED_com_engine_render_Clip
#include <com/engine/render/Clip.h>
#endif
#ifndef INCLUDED_com_engine_render_Image
#include <com/engine/render/Image.h>
#endif
#ifndef INCLUDED_com_engine_render_Texture
#include <com/engine/render/Texture.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void Particle_obj::__construct(::com::engine::render::Texture Tex)
{
HX_STACK_PUSH("Particle::new","com/djoker/glteste/Particle.hx",9);
{
	HX_STACK_LINE(9)
	super::__construct(Tex);
}
;
	return null();
}

Particle_obj::~Particle_obj() { }

Dynamic Particle_obj::__CreateEmpty() { return  new Particle_obj; }
hx::ObjectPtr< Particle_obj > Particle_obj::__new(::com::engine::render::Texture Tex)
{  hx::ObjectPtr< Particle_obj > result = new Particle_obj();
	result->__construct(Tex);
	return result;}

Dynamic Particle_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Particle_obj > result = new Particle_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Particle_obj::move( Float dt){
{
		HX_STACK_PUSH("Particle::move","com/djoker/glteste/Particle.hx",66);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(67)
		Float rad = ((int)30 * this->scaleX);		HX_STACK_VAR(rad,"rad");
		HX_STACK_LINE(69)
		hx::AddEq(this->x,(this->dx * dt));
		HX_STACK_LINE(70)
		if (((this->x < rad))){
			HX_STACK_LINE(72)
			this->x = rad;
			HX_STACK_LINE(73)
			this->dx = -(this->dx);
		}
		HX_STACK_LINE(75)
		if (((this->x > ((int)640 - rad)))){
			HX_STACK_LINE(77)
			this->x = ((int)640 - rad);
			HX_STACK_LINE(78)
			this->dx = -(this->dx);
		}
		HX_STACK_LINE(81)
		hx::AddEq(this->y,(this->dy * dt));
		HX_STACK_LINE(82)
		if (((this->y < rad))){
			HX_STACK_LINE(84)
			this->y = rad;
			HX_STACK_LINE(85)
			this->dy = -(this->dy);
		}
		HX_STACK_LINE(87)
		if (((this->y > ((int)480 - rad)))){
			HX_STACK_LINE(89)
			this->y = ((int)480 - rad);
			HX_STACK_LINE(90)
			this->dy = -(this->dy);
		}
		HX_STACK_LINE(93)
		hx::AddEq(this->angle,this->da);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Particle_obj,move,(void))

Void Particle_obj::Init( ){
{
		HX_STACK_PUSH("Particle::Init","com/djoker/glteste/Particle.hx",18);
		HX_STACK_THIS(this);
		HX_STACK_LINE(20)
		this->x = (int)320;
		HX_STACK_LINE(21)
		this->y = (int)240;
		HX_STACK_LINE(22)
		this->angle = (int)0;
		HX_STACK_LINE(23)
		this->dx = ((::Math_obj::random() * 200.0) - 100.0);
		HX_STACK_LINE(24)
		this->dy = ((::Math_obj::random() * 200.0) - 100.0);
		HX_STACK_LINE(25)
		this->da = ((::Math_obj::random() * 0.2) - 0.1);
		HX_STACK_LINE(27)
		int frame = ::Std_obj::random((int)16);		HX_STACK_VAR(frame,"frame");
		HX_STACK_LINE(28)
		int columns = (int)4;		HX_STACK_VAR(columns,"columns");
		HX_STACK_LINE(30)
		int w = (int)32;		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(31)
		int h = (int)32;		HX_STACK_VAR(h,"h");
		HX_STACK_LINE(49)
		this->clip->set((w * (hx::Mod(frame,columns))),(h * ::Std_obj::_int((Float(frame) / Float(columns)))),w,h);
		HX_STACK_LINE(52)
		this->red = (int)1;
		HX_STACK_LINE(52)
		::Math_obj::random();
		HX_STACK_LINE(53)
		this->green = ::Math_obj::random();
		HX_STACK_LINE(54)
		this->blue = ::Math_obj::random();
		HX_STACK_LINE(55)
		this->alpha = ::Math_obj::random();
		HX_STACK_LINE(57)
		this->scaleX = 0.2;
		HX_STACK_LINE(58)
		this->scaleY = 0.2;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Particle_obj,Init,(void))


Particle_obj::Particle_obj()
{
}

void Particle_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Particle);
	HX_MARK_MEMBER_NAME(da,"da");
	HX_MARK_MEMBER_NAME(dy,"dy");
	HX_MARK_MEMBER_NAME(dx,"dx");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Particle_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(da,"da");
	HX_VISIT_MEMBER_NAME(dy,"dy");
	HX_VISIT_MEMBER_NAME(dx,"dx");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Particle_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"da") ) { return da; }
		if (HX_FIELD_EQ(inName,"dy") ) { return dy; }
		if (HX_FIELD_EQ(inName,"dx") ) { return dx; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"move") ) { return move_dyn(); }
		if (HX_FIELD_EQ(inName,"Init") ) { return Init_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Particle_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"da") ) { da=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dy") ) { dy=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dx") ) { dx=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Particle_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("Init"),
	HX_CSTRING("da"),
	HX_CSTRING("dy"),
	HX_CSTRING("dx"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Particle_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Particle_obj::__mClass,"__mClass");
};

Class Particle_obj::__mClass;

void Particle_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.Particle"), hx::TCanCast< Particle_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Particle_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
