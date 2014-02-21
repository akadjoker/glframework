#include <hxcpp.h>

#ifndef INCLUDED_com_djoker_glteste_MoveSprite
#include <com/djoker/glteste/MoveSprite.h>
#endif
#ifndef INCLUDED_com_engine_direct_TileImage
#include <com/engine/direct/TileImage.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void MoveSprite_obj::__construct(Float x,Float y,int graph)
{
HX_STACK_PUSH("MoveSprite::new","com/djoker/glteste/TesteDraTiles.hx",17);
{
	HX_STACK_LINE(17)
	super::__construct(x,y,graph);
}
;
	return null();
}

MoveSprite_obj::~MoveSprite_obj() { }

Dynamic MoveSprite_obj::__CreateEmpty() { return  new MoveSprite_obj; }
hx::ObjectPtr< MoveSprite_obj > MoveSprite_obj::__new(Float x,Float y,int graph)
{  hx::ObjectPtr< MoveSprite_obj > result = new MoveSprite_obj();
	result->__construct(x,y,graph);
	return result;}

Dynamic MoveSprite_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MoveSprite_obj > result = new MoveSprite_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void MoveSprite_obj::move( Float dt){
{
		HX_STACK_PUSH("MoveSprite::move","com/djoker/glteste/TesteDraTiles.hx",57);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(58)
		Float rad = ((int)30 * this->ScaleX);		HX_STACK_VAR(rad,"rad");
		HX_STACK_LINE(60)
		hx::AddEq(this->x,(this->dx * dt));
		HX_STACK_LINE(61)
		if (((this->x < rad))){
			HX_STACK_LINE(63)
			this->x = rad;
			HX_STACK_LINE(64)
			this->dx = -(this->dx);
		}
		HX_STACK_LINE(66)
		if (((this->x > ((int)640 - rad)))){
			HX_STACK_LINE(68)
			this->x = ((int)640 - rad);
			HX_STACK_LINE(69)
			this->dx = -(this->dx);
		}
		HX_STACK_LINE(72)
		hx::AddEq(this->y,(this->dy * dt));
		HX_STACK_LINE(73)
		if (((this->y < rad))){
			HX_STACK_LINE(75)
			this->y = rad;
			HX_STACK_LINE(76)
			this->dy = -(this->dy);
		}
		HX_STACK_LINE(78)
		if (((this->y > ((int)480 - rad)))){
			HX_STACK_LINE(80)
			this->y = ((int)480 - rad);
			HX_STACK_LINE(81)
			this->dy = -(this->dy);
		}
		HX_STACK_LINE(84)
		hx::AddEq(this->Rotation,this->da);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(MoveSprite_obj,move,(void))

Void MoveSprite_obj::update( ){
{
		HX_STACK_PUSH("MoveSprite::update","com/djoker/glteste/TesteDraTiles.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_LINE(51)
		this->move(0.03);
	}
return null();
}


Void MoveSprite_obj::init( ){
{
		HX_STACK_PUSH("MoveSprite::init","com/djoker/glteste/TesteDraTiles.hx",26);
		HX_STACK_THIS(this);
		HX_STACK_LINE(28)
		this->x = (int)320;
		HX_STACK_LINE(29)
		this->y = (int)240;
		HX_STACK_LINE(30)
		this->Rotation = (int)0;
		HX_STACK_LINE(31)
		this->dx = ((::Math_obj::random() * 200.0) - 100.0);
		HX_STACK_LINE(32)
		this->dy = ((::Math_obj::random() * 200.0) - 100.0);
		HX_STACK_LINE(33)
		this->da = ((::Math_obj::random() * 10.2) - 12.1);
		HX_STACK_LINE(38)
		this->Red = ::Math_obj::random();
		HX_STACK_LINE(39)
		this->Green = ::Math_obj::random();
		HX_STACK_LINE(40)
		this->Blue = ::Math_obj::random();
		HX_STACK_LINE(41)
		this->Alpha = ::Math_obj::random();
		HX_STACK_LINE(44)
		this->ScaleX = ((::Math_obj::random() * 1.1) + 0.1);
		HX_STACK_LINE(45)
		this->ScaleY = ((::Math_obj::random() * 1.1) + 0.1);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(MoveSprite_obj,init,(void))


MoveSprite_obj::MoveSprite_obj()
{
}

void MoveSprite_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MoveSprite);
	HX_MARK_MEMBER_NAME(da,"da");
	HX_MARK_MEMBER_NAME(dy,"dy");
	HX_MARK_MEMBER_NAME(dx,"dx");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void MoveSprite_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(da,"da");
	HX_VISIT_MEMBER_NAME(dy,"dy");
	HX_VISIT_MEMBER_NAME(dx,"dx");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic MoveSprite_obj::__Field(const ::String &inName,bool inCallProp)
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
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MoveSprite_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 2:
		if (HX_FIELD_EQ(inName,"da") ) { da=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dy") ) { dy=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"dx") ) { dx=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void MoveSprite_obj::__GetFields(Array< ::String> &outFields)
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
	HX_CSTRING("update"),
	HX_CSTRING("init"),
	HX_CSTRING("da"),
	HX_CSTRING("dy"),
	HX_CSTRING("dx"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MoveSprite_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MoveSprite_obj::__mClass,"__mClass");
};

Class MoveSprite_obj::__mClass;

void MoveSprite_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.MoveSprite"), hx::TCanCast< MoveSprite_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MoveSprite_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
