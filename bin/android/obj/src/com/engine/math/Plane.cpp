#include <hxcpp.h>

#ifndef INCLUDED_com_engine_math_Matrix
#include <com/engine/math/Matrix.h>
#endif
#ifndef INCLUDED_com_engine_math_Plane
#include <com/engine/math/Plane.h>
#endif
#ifndef INCLUDED_com_engine_math_Vector3
#include <com/engine/math/Vector3.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace engine{
namespace math{

Void Plane_obj::__construct(Float a,Float b,Float c,Float d)
{
HX_STACK_PUSH("Plane::new","com/engine/math/Plane.hx",11);
{
	HX_STACK_LINE(12)
	this->normal = ::com::engine::math::Vector3_obj::__new(a,b,c);
	HX_STACK_LINE(13)
	this->d = d;
}
;
	return null();
}

Plane_obj::~Plane_obj() { }

Dynamic Plane_obj::__CreateEmpty() { return  new Plane_obj; }
hx::ObjectPtr< Plane_obj > Plane_obj::__new(Float a,Float b,Float c,Float d)
{  hx::ObjectPtr< Plane_obj > result = new Plane_obj();
	result->__construct(a,b,c,d);
	return result;}

Dynamic Plane_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Plane_obj > result = new Plane_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2],inArgs[3]);
	return result;}

Float Plane_obj::signedDistanceTo( ::com::engine::math::Vector3 point){
	HX_STACK_PUSH("Plane::signedDistanceTo","com/engine/math/Plane.hx",86);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	struct _Function_1_1{
		inline static Float Block( ::com::engine::math::Plane_obj *__this,::com::engine::math::Vector3 &point){
			HX_STACK_PUSH("*::closure","com/engine/math/Plane.hx",87);
			{
				HX_STACK_LINE(87)
				::com::engine::math::Vector3 right = __this->normal;		HX_STACK_VAR(right,"right");
				HX_STACK_LINE(87)
				return (((point->x * right->x) + (point->y * right->y)) + (point->z * right->z));
			}
			return null();
		}
	};
	HX_STACK_LINE(86)
	return (_Function_1_1::Block(this,point) + this->d);
}


HX_DEFINE_DYNAMIC_FUNC1(Plane_obj,signedDistanceTo,return )

bool Plane_obj::isFrontFacingTo( ::com::engine::math::Vector3 direction,Float epsilon){
	HX_STACK_PUSH("Plane::isFrontFacingTo","com/engine/math/Plane.hx",80);
	HX_STACK_THIS(this);
	HX_STACK_ARG(direction,"direction");
	HX_STACK_ARG(epsilon,"epsilon");
	struct _Function_1_1{
		inline static Float Block( ::com::engine::math::Plane_obj *__this,::com::engine::math::Vector3 &direction){
			HX_STACK_PUSH("*::closure","com/engine/math/Plane.hx",81);
			{
				HX_STACK_LINE(81)
				::com::engine::math::Vector3 left = __this->normal;		HX_STACK_VAR(left,"left");
				HX_STACK_LINE(81)
				return (((left->x * direction->x) + (left->y * direction->y)) + (left->z * direction->z));
			}
			return null();
		}
	};
	HX_STACK_LINE(81)
	Float dot = _Function_1_1::Block(this,direction);		HX_STACK_VAR(dot,"dot");
	HX_STACK_LINE(83)
	return (dot <= epsilon);
}


HX_DEFINE_DYNAMIC_FUNC2(Plane_obj,isFrontFacingTo,return )

Void Plane_obj::copyFromPoints( ::com::engine::math::Vector3 point1,::com::engine::math::Vector3 point2,::com::engine::math::Vector3 point3){
{
		HX_STACK_PUSH("Plane::copyFromPoints","com/engine/math/Plane.hx",54);
		HX_STACK_THIS(this);
		HX_STACK_ARG(point1,"point1");
		HX_STACK_ARG(point2,"point2");
		HX_STACK_ARG(point3,"point3");
		HX_STACK_LINE(55)
		Float x1 = (point2->x - point1->x);		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(56)
		Float y1 = (point2->y - point1->y);		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(57)
		Float z1 = (point2->z - point1->z);		HX_STACK_VAR(z1,"z1");
		HX_STACK_LINE(58)
		Float x2 = (point3->x - point1->x);		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(59)
		Float y2 = (point3->y - point1->y);		HX_STACK_VAR(y2,"y2");
		HX_STACK_LINE(60)
		Float z2 = (point3->z - point1->z);		HX_STACK_VAR(z2,"z2");
		HX_STACK_LINE(61)
		Float yz = ((y1 * z2) - (z1 * y2));		HX_STACK_VAR(yz,"yz");
		HX_STACK_LINE(62)
		Float xz = ((z1 * x2) - (x1 * z2));		HX_STACK_VAR(xz,"xz");
		HX_STACK_LINE(63)
		Float xy = ((x1 * y2) - (y1 * x2));		HX_STACK_VAR(xy,"xy");
		HX_STACK_LINE(64)
		Float pyth = ::Math_obj::sqrt((((yz * yz) + (xz * xz)) + (xy * xy)));		HX_STACK_VAR(pyth,"pyth");
		HX_STACK_LINE(65)
		Float invPyth;		HX_STACK_VAR(invPyth,"invPyth");
		HX_STACK_LINE(67)
		if (((pyth != (int)0))){
			HX_STACK_LINE(67)
			invPyth = (Float(1.0) / Float(pyth));
		}
		else{
			HX_STACK_LINE(70)
			invPyth = (int)0;
		}
		HX_STACK_LINE(74)
		this->normal->x = (yz * invPyth);
		HX_STACK_LINE(75)
		this->normal->y = (xz * invPyth);
		HX_STACK_LINE(76)
		this->normal->z = (xy * invPyth);
		HX_STACK_LINE(77)
		this->d = -(((((this->normal->x * point1->x) + (this->normal->y * point1->y)) + (this->normal->z * point1->z))));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Plane_obj,copyFromPoints,(void))

Float Plane_obj::dotCoordinate( ::com::engine::math::Vector3 point){
	HX_STACK_PUSH("Plane::dotCoordinate","com/engine/math/Plane.hx",50);
	HX_STACK_THIS(this);
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(50)
	return ((((this->normal->x * point->x) + (this->normal->y * point->y)) + (this->normal->z * point->z)) + this->d);
}


HX_DEFINE_DYNAMIC_FUNC1(Plane_obj,dotCoordinate,return )

::com::engine::math::Plane Plane_obj::transform( ::com::engine::math::Matrix transformation){
	HX_STACK_PUSH("Plane::transform","com/engine/math/Plane.hx",35);
	HX_STACK_THIS(this);
	HX_STACK_ARG(transformation,"transformation");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ::com::engine::math::Matrix &transformation){
			HX_STACK_PUSH("*::closure","com/engine/math/Plane.hx",36);
			{
				HX_STACK_LINE(36)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(36)
				result->m[(int)0] = transformation->m->__get((int)0);
				HX_STACK_LINE(36)
				result->m[(int)1] = transformation->m->__get((int)4);
				HX_STACK_LINE(36)
				result->m[(int)2] = transformation->m->__get((int)8);
				HX_STACK_LINE(36)
				result->m[(int)3] = transformation->m->__get((int)12);
				HX_STACK_LINE(36)
				result->m[(int)4] = transformation->m->__get((int)1);
				HX_STACK_LINE(36)
				result->m[(int)5] = transformation->m->__get((int)5);
				HX_STACK_LINE(36)
				result->m[(int)6] = transformation->m->__get((int)9);
				HX_STACK_LINE(36)
				result->m[(int)7] = transformation->m->__get((int)13);
				HX_STACK_LINE(36)
				result->m[(int)8] = transformation->m->__get((int)2);
				HX_STACK_LINE(36)
				result->m[(int)9] = transformation->m->__get((int)6);
				HX_STACK_LINE(36)
				result->m[(int)10] = transformation->m->__get((int)10);
				HX_STACK_LINE(36)
				result->m[(int)11] = transformation->m->__get((int)14);
				HX_STACK_LINE(36)
				result->m[(int)12] = transformation->m->__get((int)3);
				HX_STACK_LINE(36)
				result->m[(int)13] = transformation->m->__get((int)7);
				HX_STACK_LINE(36)
				result->m[(int)14] = transformation->m->__get((int)11);
				HX_STACK_LINE(36)
				result->m[(int)15] = transformation->m->__get((int)15);
				HX_STACK_LINE(36)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(36)
	::com::engine::math::Matrix transposedMatrix = _Function_1_1::Block(transformation);		HX_STACK_VAR(transposedMatrix,"transposedMatrix");
	HX_STACK_LINE(37)
	Float x = this->normal->x;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(38)
	Float y = this->normal->y;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(39)
	Float z = this->normal->z;		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(40)
	Float d = this->d;		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(42)
	Float normalX = ((((x * transposedMatrix->m->__get((int)0)) + (y * transposedMatrix->m->__get((int)1))) + (z * transposedMatrix->m->__get((int)2))) + (d * transposedMatrix->m->__get((int)3)));		HX_STACK_VAR(normalX,"normalX");
	HX_STACK_LINE(43)
	Float normalY = ((((x * transposedMatrix->m->__get((int)4)) + (y * transposedMatrix->m->__get((int)5))) + (z * transposedMatrix->m->__get((int)6))) + (d * transposedMatrix->m->__get((int)7)));		HX_STACK_VAR(normalY,"normalY");
	HX_STACK_LINE(44)
	Float normalZ = ((((x * transposedMatrix->m->__get((int)8)) + (y * transposedMatrix->m->__get((int)9))) + (z * transposedMatrix->m->__get((int)10))) + (d * transposedMatrix->m->__get((int)11)));		HX_STACK_VAR(normalZ,"normalZ");
	HX_STACK_LINE(45)
	Float finalD = ((((x * transposedMatrix->m->__get((int)12)) + (y * transposedMatrix->m->__get((int)13))) + (z * transposedMatrix->m->__get((int)14))) + (d * transposedMatrix->m->__get((int)15)));		HX_STACK_VAR(finalD,"finalD");
	HX_STACK_LINE(47)
	return ::com::engine::math::Plane_obj::__new(normalX,normalY,normalZ,finalD);
}


HX_DEFINE_DYNAMIC_FUNC1(Plane_obj,transform,return )

Void Plane_obj::normalize( ){
{
		HX_STACK_PUSH("Plane::normalize","com/engine/math/Plane.hx",20);
		HX_STACK_THIS(this);
		HX_STACK_LINE(21)
		Float norm = ::Math_obj::sqrt((((this->normal->x * this->normal->x) + (this->normal->y * this->normal->y)) + (this->normal->z * this->normal->z)));		HX_STACK_VAR(norm,"norm");
		HX_STACK_LINE(22)
		Float magnitude = (int)0;		HX_STACK_VAR(magnitude,"magnitude");
		HX_STACK_LINE(24)
		if (((norm != (int)0))){
			HX_STACK_LINE(24)
			magnitude = (Float(1.0) / Float(norm));
		}
		HX_STACK_LINE(28)
		hx::MultEq(this->normal->x,magnitude);
		HX_STACK_LINE(29)
		hx::MultEq(this->normal->y,magnitude);
		HX_STACK_LINE(30)
		hx::MultEq(this->normal->z,magnitude);
		HX_STACK_LINE(32)
		hx::MultEq(this->d,magnitude);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Plane_obj,normalize,(void))

::com::engine::math::Plane Plane_obj::clone( ){
	HX_STACK_PUSH("Plane::clone","com/engine/math/Plane.hx",16);
	HX_STACK_THIS(this);
	HX_STACK_LINE(16)
	return ::com::engine::math::Plane_obj::__new(this->normal->x,this->normal->y,this->normal->z,this->d);
}


HX_DEFINE_DYNAMIC_FUNC0(Plane_obj,clone,return )

::com::engine::math::Plane Plane_obj::FromArray( Array< Float > array){
	HX_STACK_PUSH("Plane::FromArray","com/engine/math/Plane.hx",91);
	HX_STACK_ARG(array,"array");
	HX_STACK_LINE(91)
	return ::com::engine::math::Plane_obj::__new(array->__get((int)0),array->__get((int)1),array->__get((int)2),array->__get((int)3));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Plane_obj,FromArray,return )

::com::engine::math::Plane Plane_obj::FromPoints( ::com::engine::math::Vector3 point1,::com::engine::math::Vector3 point2,::com::engine::math::Vector3 point3){
	HX_STACK_PUSH("Plane::FromPoints","com/engine/math/Plane.hx",95);
	HX_STACK_ARG(point1,"point1");
	HX_STACK_ARG(point2,"point2");
	HX_STACK_ARG(point3,"point3");
	HX_STACK_LINE(96)
	::com::engine::math::Plane result = ::com::engine::math::Plane_obj::__new((int)0,(int)0,(int)0,(int)0);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(97)
	{
		HX_STACK_LINE(97)
		Float x1 = (point2->x - point1->x);		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(97)
		Float y1 = (point2->y - point1->y);		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(97)
		Float z1 = (point2->z - point1->z);		HX_STACK_VAR(z1,"z1");
		HX_STACK_LINE(97)
		Float x2 = (point3->x - point1->x);		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(97)
		Float y2 = (point3->y - point1->y);		HX_STACK_VAR(y2,"y2");
		HX_STACK_LINE(97)
		Float z2 = (point3->z - point1->z);		HX_STACK_VAR(z2,"z2");
		HX_STACK_LINE(97)
		Float yz = ((y1 * z2) - (z1 * y2));		HX_STACK_VAR(yz,"yz");
		HX_STACK_LINE(97)
		Float xz = ((z1 * x2) - (x1 * z2));		HX_STACK_VAR(xz,"xz");
		HX_STACK_LINE(97)
		Float xy = ((x1 * y2) - (y1 * x2));		HX_STACK_VAR(xy,"xy");
		HX_STACK_LINE(97)
		Float pyth = ::Math_obj::sqrt((((yz * yz) + (xz * xz)) + (xy * xy)));		HX_STACK_VAR(pyth,"pyth");
		HX_STACK_LINE(97)
		Float invPyth;		HX_STACK_VAR(invPyth,"invPyth");
		HX_STACK_LINE(97)
		if (((pyth != (int)0))){
			HX_STACK_LINE(97)
			invPyth = (Float(1.0) / Float(pyth));
		}
		else{
			HX_STACK_LINE(97)
			invPyth = (int)0;
		}
		HX_STACK_LINE(97)
		result->normal->x = (yz * invPyth);
		HX_STACK_LINE(97)
		result->normal->y = (xz * invPyth);
		HX_STACK_LINE(97)
		result->normal->z = (xy * invPyth);
		HX_STACK_LINE(97)
		result->d = -(((((result->normal->x * point1->x) + (result->normal->y * point1->y)) + (result->normal->z * point1->z))));
	}
	HX_STACK_LINE(99)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Plane_obj,FromPoints,return )

::com::engine::math::Plane Plane_obj::FromPositionAndNormal( ::com::engine::math::Vector3 origin,::com::engine::math::Vector3 normal){
	HX_STACK_PUSH("Plane::FromPositionAndNormal","com/engine/math/Plane.hx",102);
	HX_STACK_ARG(origin,"origin");
	HX_STACK_ARG(normal,"normal");
	HX_STACK_LINE(103)
	::com::engine::math::Plane result = ::com::engine::math::Plane_obj::__new((int)0,(int)0,(int)0,(int)0);		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(104)
	{
		HX_STACK_LINE(104)
		Float len = ::Math_obj::sqrt((((normal->x * normal->x) + (normal->y * normal->y)) + (normal->z * normal->z)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(104)
		if (((len != (int)0))){
			HX_STACK_LINE(104)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(104)
			hx::MultEq(normal->x,num);
			HX_STACK_LINE(104)
			hx::MultEq(normal->y,num);
			HX_STACK_LINE(104)
			hx::MultEq(normal->z,num);
		}
	}
	HX_STACK_LINE(106)
	result->normal = normal;
	HX_STACK_LINE(107)
	result->d = -(((((normal->x * origin->x) + (normal->y * origin->y)) + (normal->z * origin->z))));
	HX_STACK_LINE(109)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Plane_obj,FromPositionAndNormal,return )

Float Plane_obj::SignedDistanceToPlaneFromPositionAndNormal( ::com::engine::math::Vector3 origin,::com::engine::math::Vector3 normal,::com::engine::math::Vector3 point){
	HX_STACK_PUSH("Plane::SignedDistanceToPlaneFromPositionAndNormal","com/engine/math/Plane.hx",112);
	HX_STACK_ARG(origin,"origin");
	HX_STACK_ARG(normal,"normal");
	HX_STACK_ARG(point,"point");
	HX_STACK_LINE(113)
	Float d = -(((((normal->x * origin->x) + (normal->y * origin->y)) + (normal->z * origin->z))));		HX_STACK_VAR(d,"d");
	HX_STACK_LINE(115)
	return ((((point->x * normal->x) + (point->y * normal->y)) + (point->z * normal->z)) + d);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Plane_obj,SignedDistanceToPlaneFromPositionAndNormal,return )


Plane_obj::Plane_obj()
{
}

void Plane_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Plane);
	HX_MARK_MEMBER_NAME(d,"d");
	HX_MARK_MEMBER_NAME(normal,"normal");
	HX_MARK_END_CLASS();
}

void Plane_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(d,"d");
	HX_VISIT_MEMBER_NAME(normal,"normal");
}

Dynamic Plane_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"d") ) { return d; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { return normal; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FromArray") ) { return FromArray_dyn(); }
		if (HX_FIELD_EQ(inName,"transform") ) { return transform_dyn(); }
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromPoints") ) { return FromPoints_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"dotCoordinate") ) { return dotCoordinate_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"copyFromPoints") ) { return copyFromPoints_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"isFrontFacingTo") ) { return isFrontFacingTo_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"signedDistanceTo") ) { return signedDistanceTo_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"FromPositionAndNormal") ) { return FromPositionAndNormal_dyn(); }
		break;
	case 42:
		if (HX_FIELD_EQ(inName,"SignedDistanceToPlaneFromPositionAndNormal") ) { return SignedDistanceToPlaneFromPositionAndNormal_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Plane_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"d") ) { d=inValue.Cast< Float >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"normal") ) { normal=inValue.Cast< ::com::engine::math::Vector3 >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Plane_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("d"));
	outFields->push(HX_CSTRING("normal"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("FromArray"),
	HX_CSTRING("FromPoints"),
	HX_CSTRING("FromPositionAndNormal"),
	HX_CSTRING("SignedDistanceToPlaneFromPositionAndNormal"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("signedDistanceTo"),
	HX_CSTRING("isFrontFacingTo"),
	HX_CSTRING("copyFromPoints"),
	HX_CSTRING("dotCoordinate"),
	HX_CSTRING("transform"),
	HX_CSTRING("normalize"),
	HX_CSTRING("clone"),
	HX_CSTRING("d"),
	HX_CSTRING("normal"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Plane_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Plane_obj::__mClass,"__mClass");
};

Class Plane_obj::__mClass;

void Plane_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.math.Plane"), hx::TCanCast< Plane_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Plane_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace math
