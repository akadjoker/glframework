#include <hxcpp.h>

#ifndef INCLUDED_List
#include <List.h>
#endif
#ifndef INCLUDED_com_engine_game_Game
#include <com/engine/game/Game.h>
#endif
#ifndef INCLUDED_com_engine_game_Transform
#include <com/engine/game/Transform.h>
#endif
#ifndef INCLUDED_com_engine_misc_MatrixHelp
#include <com/engine/misc/MatrixHelp.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_openfl_display_DirectRenderer
#include <openfl/display/DirectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_OpenGLView
#include <openfl/display/OpenGLView.h>
#endif
namespace com{
namespace engine{
namespace game{

Void Transform_obj::__construct()
{
HX_STACK_PUSH("Transform::new","com/engine/game/Transform.hx",9);
{
	HX_STACK_LINE(26)
	this->scrollFactorY = (int)1;
	HX_STACK_LINE(25)
	this->scrollFactorX = (int)1;
	HX_STACK_LINE(24)
	this->y = (int)0;
	HX_STACK_LINE(23)
	this->x = (int)0;
	HX_STACK_LINE(22)
	this->pivotY = (int)0;
	HX_STACK_LINE(21)
	this->pivotX = (int)0;
	HX_STACK_LINE(20)
	this->skewY = (int)0;
	HX_STACK_LINE(19)
	this->skewX = (int)0;
	HX_STACK_LINE(18)
	this->scaleY = (int)1;
	HX_STACK_LINE(17)
	this->scaleX = (int)1;
	HX_STACK_LINE(16)
	this->rotation = (int)0;
	HX_STACK_LINE(14)
	this->isDirty = false;
	HX_STACK_LINE(33)
	this->parent = null();
	HX_STACK_LINE(34)
	this->mTransformationMatrix = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(35)
	this->children = ::List_obj::__new();
}
;
	return null();
}

Transform_obj::~Transform_obj() { }

Dynamic Transform_obj::__CreateEmpty() { return  new Transform_obj; }
hx::ObjectPtr< Transform_obj > Transform_obj::__new()
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct();
	return result;}

Dynamic Transform_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Transform_obj > result = new Transform_obj();
	result->__construct();
	return result;}

::flash::geom::Matrix Transform_obj::getLocalToWorldMatrix( ){
	HX_STACK_PUSH("Transform::getLocalToWorldMatrix","com/engine/game/Transform.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_LINE(75)
	if (((this->parent == null()))){
		HX_STACK_LINE(77)
		return this->getTransformationMatrix();
	}
	else{
		HX_STACK_LINE(81)
		return this->parent->getTransformationMatrix()->mult(this->getTransformationMatrix());
	}
	HX_STACK_LINE(75)
	return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,getLocalToWorldMatrix,return )

::flash::geom::Matrix Transform_obj::getTransformationMatrix( ){
	HX_STACK_PUSH("Transform::getTransformationMatrix","com/engine/game/Transform.hx",50);
	HX_STACK_THIS(this);
	HX_STACK_LINE(51)
	this->mTransformationMatrix->identity();
	HX_STACK_LINE(53)
	Float cx = ::com::engine::game::Game_obj::scrollX;		HX_STACK_VAR(cx,"cx");
	HX_STACK_LINE(54)
	Float cy = ::com::engine::game::Game_obj::scrollY;		HX_STACK_VAR(cy,"cy");
	HX_STACK_LINE(55)
	Float sx = (this->x - (cx * this->scrollFactorX));		HX_STACK_VAR(sx,"sx");
	HX_STACK_LINE(56)
	Float sy = (this->y - (cy * this->scrollFactorY));		HX_STACK_VAR(sy,"sy");
	HX_STACK_LINE(59)
	if (((bool((this->scaleX != 1.0)) || bool((this->scaleY != 1.0))))){
		HX_STACK_LINE(59)
		this->mTransformationMatrix->scale(this->scaleX,this->scaleY);
	}
	HX_STACK_LINE(60)
	if (((bool((this->skewX != 0.0)) || bool((this->skewY != 0.0))))){
		HX_STACK_LINE(60)
		::com::engine::misc::MatrixHelp_obj::skew(this->mTransformationMatrix,this->skewX,this->skewY);
	}
	HX_STACK_LINE(61)
	if (((this->rotation != 0.0))){
		HX_STACK_LINE(61)
		this->mTransformationMatrix->rotate(this->rotation);
	}
	HX_STACK_LINE(62)
	if (((bool((sx != 0.0)) || bool((sy != 0.0))))){
		HX_STACK_LINE(62)
		this->mTransformationMatrix->translate(sx,sy);
	}
	HX_STACK_LINE(64)
	if (((bool((this->pivotX != 0.0)) || bool((this->pivotY != 0.0))))){
		HX_STACK_LINE(66)
		this->mTransformationMatrix->tx = ((sx - (this->mTransformationMatrix->a * this->pivotX)) - (this->mTransformationMatrix->c * this->pivotY));
		HX_STACK_LINE(68)
		this->mTransformationMatrix->ty = ((sy - (this->mTransformationMatrix->b * this->pivotX)) - (this->mTransformationMatrix->d * this->pivotY));
	}
	HX_STACK_LINE(71)
	return this->mTransformationMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(Transform_obj,getTransformationMatrix,return )

Void Transform_obj::remove( ::com::engine::game::Transform child){
{
		HX_STACK_PUSH("Transform::remove","com/engine/game/Transform.hx",44);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(44)
		this->children->remove(child);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,remove,(void))

Void Transform_obj::add( ::com::engine::game::Transform child){
{
		HX_STACK_PUSH("Transform::add","com/engine/game/Transform.hx",40);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(40)
		this->children->add(child);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Transform_obj,add,(void))


Transform_obj::Transform_obj()
{
}

void Transform_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Transform);
	HX_MARK_MEMBER_NAME(scrollFactorY,"scrollFactorY");
	HX_MARK_MEMBER_NAME(scrollFactorX,"scrollFactorX");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(pivotY,"pivotY");
	HX_MARK_MEMBER_NAME(pivotX,"pivotX");
	HX_MARK_MEMBER_NAME(skewY,"skewY");
	HX_MARK_MEMBER_NAME(skewX,"skewX");
	HX_MARK_MEMBER_NAME(scaleY,"scaleY");
	HX_MARK_MEMBER_NAME(scaleX,"scaleX");
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(isDirty,"isDirty");
	HX_MARK_MEMBER_NAME(children,"children");
	HX_MARK_MEMBER_NAME(parent,"parent");
	HX_MARK_MEMBER_NAME(mTransformationMatrix,"mTransformationMatrix");
	HX_MARK_END_CLASS();
}

void Transform_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(scrollFactorY,"scrollFactorY");
	HX_VISIT_MEMBER_NAME(scrollFactorX,"scrollFactorX");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(pivotY,"pivotY");
	HX_VISIT_MEMBER_NAME(pivotX,"pivotX");
	HX_VISIT_MEMBER_NAME(skewY,"skewY");
	HX_VISIT_MEMBER_NAME(skewX,"skewX");
	HX_VISIT_MEMBER_NAME(scaleY,"scaleY");
	HX_VISIT_MEMBER_NAME(scaleX,"scaleX");
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(isDirty,"isDirty");
	HX_VISIT_MEMBER_NAME(children,"children");
	HX_VISIT_MEMBER_NAME(parent,"parent");
	HX_VISIT_MEMBER_NAME(mTransformationMatrix,"mTransformationMatrix");
}

Dynamic Transform_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"skewY") ) { return skewY; }
		if (HX_FIELD_EQ(inName,"skewX") ) { return skewX; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"pivotY") ) { return pivotY; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { return pivotX; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { return scaleY; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { return scaleX; }
		if (HX_FIELD_EQ(inName,"parent") ) { return parent; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isDirty") ) { return isDirty; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		if (HX_FIELD_EQ(inName,"children") ) { return children; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"scrollFactorY") ) { return scrollFactorY; }
		if (HX_FIELD_EQ(inName,"scrollFactorX") ) { return scrollFactorX; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"getLocalToWorldMatrix") ) { return getLocalToWorldMatrix_dyn(); }
		if (HX_FIELD_EQ(inName,"mTransformationMatrix") ) { return mTransformationMatrix; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"getTransformationMatrix") ) { return getTransformationMatrix_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Transform_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"skewY") ) { skewY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"skewX") ) { skewX=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"pivotY") ) { pivotY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"pivotX") ) { pivotX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleY") ) { scaleY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scaleX") ) { scaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"parent") ) { parent=inValue.Cast< ::com::engine::game::Transform >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"isDirty") ) { isDirty=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"children") ) { children=inValue.Cast< ::List >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"scrollFactorY") ) { scrollFactorY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollFactorX") ) { scrollFactorX=inValue.Cast< Float >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mTransformationMatrix") ) { mTransformationMatrix=inValue.Cast< ::flash::geom::Matrix >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Transform_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("scrollFactorY"));
	outFields->push(HX_CSTRING("scrollFactorX"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("pivotY"));
	outFields->push(HX_CSTRING("pivotX"));
	outFields->push(HX_CSTRING("skewY"));
	outFields->push(HX_CSTRING("skewX"));
	outFields->push(HX_CSTRING("scaleY"));
	outFields->push(HX_CSTRING("scaleX"));
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("isDirty"));
	outFields->push(HX_CSTRING("children"));
	outFields->push(HX_CSTRING("parent"));
	outFields->push(HX_CSTRING("mTransformationMatrix"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getLocalToWorldMatrix"),
	HX_CSTRING("getTransformationMatrix"),
	HX_CSTRING("remove"),
	HX_CSTRING("add"),
	HX_CSTRING("scrollFactorY"),
	HX_CSTRING("scrollFactorX"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("pivotY"),
	HX_CSTRING("pivotX"),
	HX_CSTRING("skewY"),
	HX_CSTRING("skewX"),
	HX_CSTRING("scaleY"),
	HX_CSTRING("scaleX"),
	HX_CSTRING("rotation"),
	HX_CSTRING("isDirty"),
	HX_CSTRING("children"),
	HX_CSTRING("parent"),
	HX_CSTRING("mTransformationMatrix"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Transform_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Transform_obj::__mClass,"__mClass");
};

Class Transform_obj::__mClass;

void Transform_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.game.Transform"), hx::TCanCast< Transform_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Transform_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace game
