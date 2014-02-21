#include <hxcpp.h>

#ifndef INCLUDED_com_engine_math_Matrix
#include <com/engine/math/Matrix.h>
#endif
#ifndef INCLUDED_com_engine_math_Vector3
#include <com/engine/math/Vector3.h>
#endif
#ifndef INCLUDED_com_engine_render_Clip
#include <com/engine/render/Clip.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace engine{
namespace math{

Void Vector3_obj::__construct(Float initialX,Float initialY,Dynamic __o_initialZ)
{
HX_STACK_PUSH("Vector3::new","com/engine/math/Vector3.hx",29);
Dynamic initialZ = __o_initialZ.Default(0);
{
	HX_STACK_LINE(30)
	this->x = initialX;
	HX_STACK_LINE(31)
	this->y = initialY;
	HX_STACK_LINE(32)
	this->z = initialZ;
}
;
	return null();
}

Vector3_obj::~Vector3_obj() { }

Dynamic Vector3_obj::__CreateEmpty() { return  new Vector3_obj; }
hx::ObjectPtr< Vector3_obj > Vector3_obj::__new(Float initialX,Float initialY,Dynamic __o_initialZ)
{  hx::ObjectPtr< Vector3_obj > result = new Vector3_obj();
	result->__construct(initialX,initialY,__o_initialZ);
	return result;}

Dynamic Vector3_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector3_obj > result = new Vector3_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

Void Vector3_obj::copyFromFloats( Float x,Float y,Float z){
{
		HX_STACK_PUSH("Vector3::copyFromFloats","com/engine/math/Vector3.hx",183);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(z,"z");
		HX_STACK_LINE(184)
		this->x = x;
		HX_STACK_LINE(185)
		this->y = y;
		HX_STACK_LINE(186)
		this->z = z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,copyFromFloats,(void))

Void Vector3_obj::copyFrom( ::com::engine::math::Vector3 source){
{
		HX_STACK_PUSH("Vector3::copyFrom","com/engine/math/Vector3.hx",177);
		HX_STACK_THIS(this);
		HX_STACK_ARG(source,"source");
		HX_STACK_LINE(178)
		this->x = source->x;
		HX_STACK_LINE(179)
		this->y = source->y;
		HX_STACK_LINE(180)
		this->z = source->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,copyFrom,(void))

::com::engine::math::Vector3 Vector3_obj::clone( ){
	HX_STACK_PUSH("Vector3::clone","com/engine/math/Vector3.hx",173);
	HX_STACK_THIS(this);
	HX_STACK_LINE(173)
	return ::com::engine::math::Vector3_obj::__new(this->x,this->y,this->z);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,clone,return )

Void Vector3_obj::normalize( ){
{
		HX_STACK_PUSH("Vector3::normalize","com/engine/math/Vector3.hx",161);
		HX_STACK_THIS(this);
		HX_STACK_LINE(162)
		Float len = ::Math_obj::sqrt((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(164)
		if (((len != (int)0))){
			HX_STACK_LINE(165)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(167)
			hx::MultEq(this->x,num);
			HX_STACK_LINE(168)
			hx::MultEq(this->y,num);
			HX_STACK_LINE(169)
			hx::MultEq(this->z,num);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,normalize,(void))

Float Vector3_obj::lengthSquared( ){
	HX_STACK_PUSH("Vector3::lengthSquared","com/engine/math/Vector3.hx",157);
	HX_STACK_THIS(this);
	HX_STACK_LINE(157)
	return (((this->x * this->x) + (this->y * this->y)) + (this->z * this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,lengthSquared,return )

Float Vector3_obj::length( ){
	HX_STACK_PUSH("Vector3::length","com/engine/math/Vector3.hx",153);
	HX_STACK_THIS(this);
	HX_STACK_LINE(153)
	return ::Math_obj::sqrt((((this->x * this->x) + (this->y * this->y)) + (this->z * this->z)));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,length,return )

Void Vector3_obj::divideToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::divideToRef","com/engine/math/Vector3.hx",147);
		HX_STACK_THIS(this);
		HX_STACK_ARG(otherVector,"otherVector");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(148)
		result->x = (Float(this->x) / Float(otherVector->x));
		HX_STACK_LINE(149)
		result->y = (Float(this->y) / Float(otherVector->y));
		HX_STACK_LINE(150)
		result->z = (Float(this->z) / Float(otherVector->z));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,divideToRef,(void))

::com::engine::math::Vector3 Vector3_obj::divide( ::com::engine::math::Vector3 otherVector){
	HX_STACK_PUSH("Vector3::divide","com/engine/math/Vector3.hx",143);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(143)
	return ::com::engine::math::Vector3_obj::__new((Float(this->x) / Float(otherVector->x)),(Float(this->y) / Float(otherVector->y)),(Float(this->z) / Float(otherVector->z)));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,divide,return )

::com::engine::math::Vector3 Vector3_obj::multiplyByFloats( Float x,Float y,Float z){
	HX_STACK_PUSH("Vector3::multiplyByFloats","com/engine/math/Vector3.hx",139);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
	HX_STACK_LINE(139)
	return ::com::engine::math::Vector3_obj::__new((this->x * x),(this->y * y),(this->z * z));
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,multiplyByFloats,return )

Void Vector3_obj::multiplyToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::multiplyToRef","com/engine/math/Vector3.hx",133);
		HX_STACK_THIS(this);
		HX_STACK_ARG(otherVector,"otherVector");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(134)
		result->x = (this->x * otherVector->x);
		HX_STACK_LINE(135)
		result->y = (this->y * otherVector->y);
		HX_STACK_LINE(136)
		result->z = (this->z * otherVector->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,multiplyToRef,(void))

::com::engine::math::Vector3 Vector3_obj::multiply( ::com::engine::math::Vector3 otherVector){
	HX_STACK_PUSH("Vector3::multiply","com/engine/math/Vector3.hx",129);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(129)
	return ::com::engine::math::Vector3_obj::__new((this->x * otherVector->x),(this->y * otherVector->y),(this->z * otherVector->z));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,multiply,return )

Void Vector3_obj::multiplyInPlace( ::com::engine::math::Vector3 otherVector){
{
		HX_STACK_PUSH("Vector3::multiplyInPlace","com/engine/math/Vector3.hx",123);
		HX_STACK_THIS(this);
		HX_STACK_ARG(otherVector,"otherVector");
		HX_STACK_LINE(124)
		hx::MultEq(this->x,otherVector->x);
		HX_STACK_LINE(125)
		hx::MultEq(this->y,otherVector->y);
		HX_STACK_LINE(126)
		hx::MultEq(this->z,otherVector->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,multiplyInPlace,(void))

bool Vector3_obj::equalsToFloats( Float x,Float y,Float z){
	HX_STACK_PUSH("Vector3::equalsToFloats","com/engine/math/Vector3.hx",119);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
	HX_STACK_LINE(119)
	return (bool((bool((this->x == x)) && bool((this->y == y)))) && bool((this->z == z)));
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,equalsToFloats,return )

bool Vector3_obj::equals( ::com::engine::math::Vector3 otherVector){
	HX_STACK_PUSH("Vector3::equals","com/engine/math/Vector3.hx",115);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(115)
	return (bool((bool((this->x == otherVector->x)) && bool((this->y == otherVector->y)))) && bool((this->z == otherVector->z)));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,equals,return )

Void Vector3_obj::scaleToRef( Float scale,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::scaleToRef","com/engine/math/Vector3.hx",109);
		HX_STACK_THIS(this);
		HX_STACK_ARG(scale,"scale");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(110)
		result->x = (this->x * scale);
		HX_STACK_LINE(111)
		result->y = (this->y * scale);
		HX_STACK_LINE(112)
		result->z = (this->z * scale);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,scaleToRef,(void))

::com::engine::math::Vector3 Vector3_obj::scale( Float scale){
	HX_STACK_PUSH("Vector3::scale","com/engine/math/Vector3.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_ARG(scale,"scale");
	HX_STACK_LINE(105)
	return ::com::engine::math::Vector3_obj::__new((this->x * scale),(this->y * scale),(this->z * scale));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,scale,return )

Void Vector3_obj::scaleInPlace( Float scale){
{
		HX_STACK_PUSH("Vector3::scaleInPlace","com/engine/math/Vector3.hx",99);
		HX_STACK_THIS(this);
		HX_STACK_ARG(scale,"scale");
		HX_STACK_LINE(100)
		hx::MultEq(this->x,scale);
		HX_STACK_LINE(101)
		hx::MultEq(this->y,scale);
		HX_STACK_LINE(102)
		hx::MultEq(this->z,scale);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,scaleInPlace,(void))

::com::engine::math::Vector3 Vector3_obj::negate( ){
	HX_STACK_PUSH("Vector3::negate","com/engine/math/Vector3.hx",95);
	HX_STACK_THIS(this);
	HX_STACK_LINE(95)
	return ::com::engine::math::Vector3_obj::__new(-(this->x),-(this->y),-(this->z));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,negate,return )

Void Vector3_obj::subtractFromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::subtractFromFloatsToRef","com/engine/math/Vector3.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(z,"z");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(90)
		result->x = (this->x - x);
		HX_STACK_LINE(91)
		result->y = (this->y - y);
		HX_STACK_LINE(92)
		result->z = (this->z - z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(Vector3_obj,subtractFromFloatsToRef,(void))

::com::engine::math::Vector3 Vector3_obj::subtractFromFloats( Float x,Float y,Float z){
	HX_STACK_PUSH("Vector3::subtractFromFloats","com/engine/math/Vector3.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
	HX_STACK_LINE(85)
	return ::com::engine::math::Vector3_obj::__new((this->x - x),(this->y - y),(this->z - z));
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,subtractFromFloats,return )

Void Vector3_obj::subtractToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::subtractToRef","com/engine/math/Vector3.hx",79);
		HX_STACK_THIS(this);
		HX_STACK_ARG(otherVector,"otherVector");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(80)
		result->x = (this->x - otherVector->x);
		HX_STACK_LINE(81)
		result->y = (this->y - otherVector->y);
		HX_STACK_LINE(82)
		result->z = (this->z - otherVector->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,subtractToRef,(void))

::com::engine::math::Vector3 Vector3_obj::subtract( ::com::engine::math::Vector3 otherVector){
	HX_STACK_PUSH("Vector3::subtract","com/engine/math/Vector3.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(75)
	return ::com::engine::math::Vector3_obj::__new((this->x - otherVector->x),(this->y - otherVector->y),(this->z - otherVector->z));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,subtract,return )

Void Vector3_obj::subtractInPlace( ::com::engine::math::Vector3 otherVector){
{
		HX_STACK_PUSH("Vector3::subtractInPlace","com/engine/math/Vector3.hx",69);
		HX_STACK_THIS(this);
		HX_STACK_ARG(otherVector,"otherVector");
		HX_STACK_LINE(70)
		hx::SubEq(this->x,otherVector->x);
		HX_STACK_LINE(71)
		hx::SubEq(this->y,otherVector->y);
		HX_STACK_LINE(72)
		hx::SubEq(this->z,otherVector->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,subtractInPlace,(void))

::com::engine::math::Vector3 Vector3_obj::addToRef( ::com::engine::math::Vector3 otherVector,::com::engine::math::Vector3 result){
	HX_STACK_PUSH("Vector3::addToRef","com/engine/math/Vector3.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(63)
	result->x = (this->x + otherVector->x);
	HX_STACK_LINE(64)
	result->y = (this->y + otherVector->y);
	HX_STACK_LINE(65)
	result->z = (this->z + otherVector->z);
	HX_STACK_LINE(66)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,addToRef,return )

::com::engine::math::Vector3 Vector3_obj::add( ::com::engine::math::Vector3 otherVector){
	HX_STACK_PUSH("Vector3::add","com/engine/math/Vector3.hx",58);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(58)
	return ::com::engine::math::Vector3_obj::__new((this->x + otherVector->x),(this->y + otherVector->y),(this->z + otherVector->z));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,add,return )

Void Vector3_obj::addInPlace( ::com::engine::math::Vector3 otherVector){
{
		HX_STACK_PUSH("Vector3::addInPlace","com/engine/math/Vector3.hx",52);
		HX_STACK_THIS(this);
		HX_STACK_ARG(otherVector,"otherVector");
		HX_STACK_LINE(53)
		hx::AddEq(this->x,otherVector->x);
		HX_STACK_LINE(54)
		hx::AddEq(this->y,otherVector->y);
		HX_STACK_LINE(55)
		hx::AddEq(this->z,otherVector->z);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,addInPlace,(void))

Array< Float > Vector3_obj::toArray( Array< Float > array,hx::Null< int >  __o_index){
int index = __o_index.Default(0);
	HX_STACK_PUSH("Vector3::toArray","com/engine/math/Vector3.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(array,"array");
	HX_STACK_ARG(index,"index");
{
		HX_STACK_LINE(46)
		array[index] = this->x;
		HX_STACK_LINE(47)
		array[(index + (int)1)] = this->y;
		HX_STACK_LINE(48)
		array[(index + (int)2)] = this->z;
		HX_STACK_LINE(49)
		return array;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,toArray,return )

Array< Float > Vector3_obj::asArray( ){
	HX_STACK_PUSH("Vector3::asArray","com/engine/math/Vector3.hx",39);
	HX_STACK_THIS(this);
	HX_STACK_LINE(40)
	Array< Float > result = Array_obj< Float >::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(41)
	{
		HX_STACK_LINE(41)
		result[(int)0] = this->x;
		HX_STACK_LINE(41)
		result[(int)1] = this->y;
		HX_STACK_LINE(41)
		result[(int)2] = this->z;
		HX_STACK_LINE(41)
		result;
	}
	HX_STACK_LINE(42)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,asArray,return )

::String Vector3_obj::toString( ){
	HX_STACK_PUSH("Vector3::toString","com/engine/math/Vector3.hx",35);
	HX_STACK_THIS(this);
	HX_STACK_LINE(35)
	return ((((((HX_CSTRING("{X:") + this->x) + HX_CSTRING(" Y:")) + this->y) + HX_CSTRING(" Z:")) + this->z) + HX_CSTRING("}"));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,toString,return )

Void Vector3_obj::set( Float initialX,Float initialY,Dynamic __o_initialZ){
Dynamic initialZ = __o_initialZ.Default(0);
	HX_STACK_PUSH("Vector3::set","com/engine/math/Vector3.hx",14);
	HX_STACK_THIS(this);
	HX_STACK_ARG(initialX,"initialX");
	HX_STACK_ARG(initialY,"initialY");
	HX_STACK_ARG(initialZ,"initialZ");
{
		HX_STACK_LINE(15)
		this->x = initialX;
		HX_STACK_LINE(16)
		this->y = initialY;
		HX_STACK_LINE(17)
		this->z = initialZ;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,set,(void))

::com::engine::math::Vector3 Vector3_obj::Sub( ::com::engine::math::Vector3 a,::com::engine::math::Vector3 b){
	HX_STACK_PUSH("Vector3::Sub","com/engine/math/Vector3.hx",21);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(21)
	return ::com::engine::math::Vector3_obj::__new((a->x - b->x),(a->y - b->y),(a->z - b->z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Sub,return )

::com::engine::math::Vector3 Vector3_obj::Add( ::com::engine::math::Vector3 a,::com::engine::math::Vector3 b){
	HX_STACK_PUSH("Vector3::Add","com/engine/math/Vector3.hx",25);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(25)
	return ::com::engine::math::Vector3_obj::__new((a->x + b->x),(a->y + b->y),(a->z + b->z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Add,return )

::com::engine::math::Vector3 Vector3_obj::FromArray( Array< Float > array,hx::Null< int >  __o_offset){
int offset = __o_offset.Default(0);
	HX_STACK_PUSH("Vector3::FromArray","com/engine/math/Vector3.hx",190);
	HX_STACK_ARG(array,"array");
	HX_STACK_ARG(offset,"offset");
{
		HX_STACK_LINE(190)
		return ::com::engine::math::Vector3_obj::__new(array->__get(offset),array->__get((offset + (int)1)),array->__get((offset + (int)2)));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,FromArray,return )

Void Vector3_obj::FromArrayToRef( Array< Float > array,hx::Null< int >  __o_offset,::com::engine::math::Vector3 result){
int offset = __o_offset.Default(0);
	HX_STACK_PUSH("Vector3::FromArrayToRef","com/engine/math/Vector3.hx",194);
	HX_STACK_ARG(array,"array");
	HX_STACK_ARG(offset,"offset");
	HX_STACK_ARG(result,"result");
{
		HX_STACK_LINE(195)
		result->x = array->__get(offset);
		HX_STACK_LINE(196)
		result->y = array->__get((offset + (int)1));
		HX_STACK_LINE(197)
		result->z = array->__get((offset + (int)2));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,FromArrayToRef,(void))

Void Vector3_obj::FromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::FromFloatsToRef","com/engine/math/Vector3.hx",200);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(z,"z");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(201)
		result->x = x;
		HX_STACK_LINE(202)
		result->y = y;
		HX_STACK_LINE(203)
		result->z = z;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Vector3_obj,FromFloatsToRef,(void))

::com::engine::math::Vector3 Vector3_obj::Zero( ){
	HX_STACK_PUSH("Vector3::Zero","com/engine/math/Vector3.hx",206);
	HX_STACK_LINE(206)
	return ::com::engine::math::Vector3_obj::__new(0.0,0.0,0.0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,Zero,return )

::com::engine::math::Vector3 Vector3_obj::Up( ){
	HX_STACK_PUSH("Vector3::Up","com/engine/math/Vector3.hx",210);
	HX_STACK_LINE(210)
	return ::com::engine::math::Vector3_obj::__new((int)0,1.0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector3_obj,Up,return )

::com::engine::math::Vector3 Vector3_obj::TransformCoordinates( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation){
	HX_STACK_PUSH("Vector3::TransformCoordinates","com/engine/math/Vector3.hx",214);
	HX_STACK_ARG(vector,"vector");
	HX_STACK_ARG(transformation,"transformation");
	HX_STACK_LINE(215)
	::com::engine::math::Vector3 result = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(217)
	{
		HX_STACK_LINE(217)
		Float x = ((((vector->x * transformation->m->__get((int)0)) + (vector->y * transformation->m->__get((int)4))) + (vector->z * transformation->m->__get((int)8))) + transformation->m->__get((int)12));		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(217)
		Float y = ((((vector->x * transformation->m->__get((int)1)) + (vector->y * transformation->m->__get((int)5))) + (vector->z * transformation->m->__get((int)9))) + transformation->m->__get((int)13));		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(217)
		Float z = ((((vector->x * transformation->m->__get((int)2)) + (vector->y * transformation->m->__get((int)6))) + (vector->z * transformation->m->__get((int)10))) + transformation->m->__get((int)14));		HX_STACK_VAR(z,"z");
		HX_STACK_LINE(217)
		Float w = ((((vector->x * transformation->m->__get((int)3)) + (vector->y * transformation->m->__get((int)7))) + (vector->z * transformation->m->__get((int)11))) + transformation->m->__get((int)15));		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(217)
		result->x = (Float(x) / Float(w));
		HX_STACK_LINE(217)
		result->y = (Float(y) / Float(w));
		HX_STACK_LINE(217)
		result->z = (Float(z) / Float(w));
	}
	HX_STACK_LINE(219)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,TransformCoordinates,return )

Void Vector3_obj::TransformCoordinatesToRef( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::TransformCoordinatesToRef","com/engine/math/Vector3.hx",222);
		HX_STACK_ARG(vector,"vector");
		HX_STACK_ARG(transformation,"transformation");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(223)
		Float x = ((((vector->x * transformation->m->__get((int)0)) + (vector->y * transformation->m->__get((int)4))) + (vector->z * transformation->m->__get((int)8))) + transformation->m->__get((int)12));		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(224)
		Float y = ((((vector->x * transformation->m->__get((int)1)) + (vector->y * transformation->m->__get((int)5))) + (vector->z * transformation->m->__get((int)9))) + transformation->m->__get((int)13));		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(225)
		Float z = ((((vector->x * transformation->m->__get((int)2)) + (vector->y * transformation->m->__get((int)6))) + (vector->z * transformation->m->__get((int)10))) + transformation->m->__get((int)14));		HX_STACK_VAR(z,"z");
		HX_STACK_LINE(226)
		Float w = ((((vector->x * transformation->m->__get((int)3)) + (vector->y * transformation->m->__get((int)7))) + (vector->z * transformation->m->__get((int)11))) + transformation->m->__get((int)15));		HX_STACK_VAR(w,"w");
		HX_STACK_LINE(228)
		result->x = (Float(x) / Float(w));
		HX_STACK_LINE(229)
		result->y = (Float(y) / Float(w));
		HX_STACK_LINE(230)
		result->z = (Float(z) / Float(w));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,TransformCoordinatesToRef,(void))

::com::engine::math::Vector3 Vector3_obj::TransformCoordinatesFromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result){
	HX_STACK_PUSH("Vector3::TransformCoordinatesFromFloatsToRef","com/engine/math/Vector3.hx",233);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
	HX_STACK_ARG(transformation,"transformation");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(234)
	Float rx = ((((x * transformation->m->__get((int)0)) + (y * transformation->m->__get((int)4))) + (z * transformation->m->__get((int)8))) + transformation->m->__get((int)12));		HX_STACK_VAR(rx,"rx");
	HX_STACK_LINE(235)
	Float ry = ((((x * transformation->m->__get((int)1)) + (y * transformation->m->__get((int)5))) + (z * transformation->m->__get((int)9))) + transformation->m->__get((int)13));		HX_STACK_VAR(ry,"ry");
	HX_STACK_LINE(236)
	Float rz = ((((x * transformation->m->__get((int)2)) + (y * transformation->m->__get((int)6))) + (z * transformation->m->__get((int)10))) + transformation->m->__get((int)14));		HX_STACK_VAR(rz,"rz");
	HX_STACK_LINE(237)
	Float rw = ((((x * transformation->m->__get((int)3)) + (y * transformation->m->__get((int)7))) + (z * transformation->m->__get((int)11))) + transformation->m->__get((int)15));		HX_STACK_VAR(rw,"rw");
	HX_STACK_LINE(239)
	result->x = (Float(rx) / Float(rw));
	HX_STACK_LINE(240)
	result->y = (Float(ry) / Float(rw));
	HX_STACK_LINE(241)
	result->z = (Float(rz) / Float(rw));
	HX_STACK_LINE(243)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Vector3_obj,TransformCoordinatesFromFloatsToRef,return )

::com::engine::math::Vector3 Vector3_obj::TransformNormal( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation){
	HX_STACK_PUSH("Vector3::TransformNormal","com/engine/math/Vector3.hx",246);
	HX_STACK_ARG(vector,"vector");
	HX_STACK_ARG(transformation,"transformation");
	HX_STACK_LINE(247)
	::com::engine::math::Vector3 result = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(249)
	{
		HX_STACK_LINE(249)
		result->x = (((vector->x * transformation->m->__get((int)0)) + (vector->y * transformation->m->__get((int)4))) + (vector->z * transformation->m->__get((int)8)));
		HX_STACK_LINE(249)
		result->y = (((vector->x * transformation->m->__get((int)1)) + (vector->y * transformation->m->__get((int)5))) + (vector->z * transformation->m->__get((int)9)));
		HX_STACK_LINE(249)
		result->z = (((vector->x * transformation->m->__get((int)2)) + (vector->y * transformation->m->__get((int)6))) + (vector->z * transformation->m->__get((int)10)));
	}
	HX_STACK_LINE(251)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,TransformNormal,return )

Void Vector3_obj::TransformNormalToRef( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::TransformNormalToRef","com/engine/math/Vector3.hx",254);
		HX_STACK_ARG(vector,"vector");
		HX_STACK_ARG(transformation,"transformation");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(255)
		result->x = (((vector->x * transformation->m->__get((int)0)) + (vector->y * transformation->m->__get((int)4))) + (vector->z * transformation->m->__get((int)8)));
		HX_STACK_LINE(256)
		result->y = (((vector->x * transformation->m->__get((int)1)) + (vector->y * transformation->m->__get((int)5))) + (vector->z * transformation->m->__get((int)9)));
		HX_STACK_LINE(257)
		result->z = (((vector->x * transformation->m->__get((int)2)) + (vector->y * transformation->m->__get((int)6))) + (vector->z * transformation->m->__get((int)10)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,TransformNormalToRef,(void))

Void Vector3_obj::TransformNormalFromFloatsToRef( Float x,Float y,Float z,::com::engine::math::Matrix transformation,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::TransformNormalFromFloatsToRef","com/engine/math/Vector3.hx",260);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(z,"z");
		HX_STACK_ARG(transformation,"transformation");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(261)
		result->x = (((x * transformation->m->__get((int)0)) + (y * transformation->m->__get((int)4))) + (z * transformation->m->__get((int)8)));
		HX_STACK_LINE(262)
		result->y = (((x * transformation->m->__get((int)1)) + (y * transformation->m->__get((int)5))) + (z * transformation->m->__get((int)9)));
		HX_STACK_LINE(263)
		result->z = (((x * transformation->m->__get((int)2)) + (y * transformation->m->__get((int)6))) + (z * transformation->m->__get((int)10)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Vector3_obj,TransformNormalFromFloatsToRef,(void))

::com::engine::math::Vector3 Vector3_obj::CatmullRom( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 value2,::com::engine::math::Vector3 value3,::com::engine::math::Vector3 value4,Float amount){
	HX_STACK_PUSH("Vector3::CatmullRom","com/engine/math/Vector3.hx",267);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(value2,"value2");
	HX_STACK_ARG(value3,"value3");
	HX_STACK_ARG(value4,"value4");
	HX_STACK_ARG(amount,"amount");
	HX_STACK_LINE(268)
	Float squared = (amount * amount);		HX_STACK_VAR(squared,"squared");
	HX_STACK_LINE(269)
	Float cubed = (amount * squared);		HX_STACK_VAR(cubed,"cubed");
	HX_STACK_LINE(271)
	Float x = (0.5 * (((((2.0 * value2->x) + (((-(value1->x) + value3->x)) * amount)) + ((((((2.0 * value1->x) - (5.0 * value2->x)) + (4.0 * value3->x)) - value4->x)) * squared)) + (((((-(value1->x) + (3.0 * value2->x)) - (3.0 * value3->x)) + value4->x)) * cubed))));		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(275)
	Float y = (0.5 * (((((2.0 * value2->y) + (((-(value1->y) + value3->y)) * amount)) + ((((((2.0 * value1->y) - (5.0 * value2->y)) + (4.0 * value3->y)) - value4->y)) * squared)) + (((((-(value1->y) + (3.0 * value2->y)) - (3.0 * value3->y)) + value4->y)) * cubed))));		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(279)
	Float z = (0.5 * (((((2.0 * value2->z) + (((-(value1->z) + value3->z)) * amount)) + ((((((2.0 * value1->z) - (5.0 * value2->z)) + (4.0 * value3->z)) - value4->z)) * squared)) + (((((-(value1->z) + (3.0 * value2->z)) - (3.0 * value3->z)) + value4->z)) * cubed))));		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(283)
	return ::com::engine::math::Vector3_obj::__new(x,y,z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Vector3_obj,CatmullRom,return )

::com::engine::math::Vector3 Vector3_obj::Clamp( ::com::engine::math::Vector3 value,::com::engine::math::Vector3 min,::com::engine::math::Vector3 max){
	HX_STACK_PUSH("Vector3::Clamp","com/engine/math/Vector3.hx",286);
	HX_STACK_ARG(value,"value");
	HX_STACK_ARG(min,"min");
	HX_STACK_ARG(max,"max");
	HX_STACK_LINE(287)
	Float x = value->x;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(288)
	x = (  (((x > max->x))) ? Float(max->x) : Float(x) );
	HX_STACK_LINE(289)
	x = (  (((x < min->x))) ? Float(min->x) : Float(x) );
	HX_STACK_LINE(291)
	Float y = value->y;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(292)
	y = (  (((y > max->y))) ? Float(max->y) : Float(y) );
	HX_STACK_LINE(293)
	y = (  (((y < min->y))) ? Float(min->y) : Float(y) );
	HX_STACK_LINE(295)
	Float z = value->z;		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(296)
	z = (  (((z > max->z))) ? Float(max->z) : Float(z) );
	HX_STACK_LINE(297)
	z = (  (((z < min->z))) ? Float(min->z) : Float(z) );
	HX_STACK_LINE(299)
	return ::com::engine::math::Vector3_obj::__new(x,y,z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,Clamp,return )

::com::engine::math::Vector3 Vector3_obj::Hermite( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 tangent1,::com::engine::math::Vector3 value2,::com::engine::math::Vector3 tangent2,Float amount){
	HX_STACK_PUSH("Vector3::Hermite","com/engine/math/Vector3.hx",302);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(tangent1,"tangent1");
	HX_STACK_ARG(value2,"value2");
	HX_STACK_ARG(tangent2,"tangent2");
	HX_STACK_ARG(amount,"amount");
	HX_STACK_LINE(303)
	Float squared = (amount * amount);		HX_STACK_VAR(squared,"squared");
	HX_STACK_LINE(304)
	Float cubed = (amount * squared);		HX_STACK_VAR(cubed,"cubed");
	HX_STACK_LINE(305)
	Float part1 = (((2.0 * cubed) - (3.0 * squared)) + 1.0);		HX_STACK_VAR(part1,"part1");
	HX_STACK_LINE(306)
	Float part2 = ((-2. * cubed) + (3.0 * squared));		HX_STACK_VAR(part2,"part2");
	HX_STACK_LINE(307)
	Float part3 = ((cubed - (2.0 * squared)) + amount);		HX_STACK_VAR(part3,"part3");
	HX_STACK_LINE(308)
	Float part4 = (cubed - squared);		HX_STACK_VAR(part4,"part4");
	HX_STACK_LINE(310)
	Float x = ((((value1->x * part1) + (value2->x * part2)) + (tangent1->x * part3)) + (tangent2->x * part4));		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(311)
	Float y = ((((value1->y * part1) + (value2->y * part2)) + (tangent1->y * part3)) + (tangent2->y * part4));		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(312)
	Float z = ((((value1->z * part1) + (value2->z * part2)) + (tangent1->z * part3)) + (tangent2->z * part4));		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(314)
	return ::com::engine::math::Vector3_obj::__new(x,y,z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Vector3_obj,Hermite,return )

::com::engine::math::Vector3 Vector3_obj::Lerp( ::com::engine::math::Vector3 start,::com::engine::math::Vector3 end,Float amount){
	HX_STACK_PUSH("Vector3::Lerp","com/engine/math/Vector3.hx",317);
	HX_STACK_ARG(start,"start");
	HX_STACK_ARG(end,"end");
	HX_STACK_ARG(amount,"amount");
	HX_STACK_LINE(318)
	Float x = (start->x + (((end->x - start->x)) * amount));		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(319)
	Float y = (start->y + (((end->y - start->y)) * amount));		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(320)
	Float z = (start->z + (((end->z - start->z)) * amount));		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(322)
	return ::com::engine::math::Vector3_obj::__new(x,y,z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,Lerp,return )

Float Vector3_obj::Dot( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right){
	HX_STACK_PUSH("Vector3::Dot","com/engine/math/Vector3.hx",325);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_LINE(325)
	return (((left->x * right->x) + (left->y * right->y)) + (left->z * right->z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Dot,return )

::com::engine::math::Vector3 Vector3_obj::Cross( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right){
	HX_STACK_PUSH("Vector3::Cross","com/engine/math/Vector3.hx",329);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_LINE(330)
	::com::engine::math::Vector3 result = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(331)
	{
		HX_STACK_LINE(331)
		result->x = ((left->y * right->z) - (left->z * right->y));
		HX_STACK_LINE(331)
		result->y = ((left->z * right->x) - (left->x * right->z));
		HX_STACK_LINE(331)
		result->z = ((left->x * right->y) - (left->y * right->x));
	}
	HX_STACK_LINE(332)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Cross,return )

Void Vector3_obj::CrossToRef( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::CrossToRef","com/engine/math/Vector3.hx",335);
		HX_STACK_ARG(left,"left");
		HX_STACK_ARG(right,"right");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(336)
		result->x = ((left->y * right->z) - (left->z * right->y));
		HX_STACK_LINE(337)
		result->y = ((left->z * right->x) - (left->x * right->z));
		HX_STACK_LINE(338)
		result->z = ((left->x * right->y) - (left->y * right->x));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector3_obj,CrossToRef,(void))

::com::engine::math::Vector3 Vector3_obj::Normalize( ::com::engine::math::Vector3 vector){
	HX_STACK_PUSH("Vector3::Normalize","com/engine/math/Vector3.hx",341);
	HX_STACK_ARG(vector,"vector");
	HX_STACK_LINE(342)
	::com::engine::math::Vector3 result = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(343)
	{
		HX_STACK_LINE(343)
		{
			HX_STACK_LINE(343)
			result->x = vector->x;
			HX_STACK_LINE(343)
			result->y = vector->y;
			HX_STACK_LINE(343)
			result->z = vector->z;
		}
		HX_STACK_LINE(343)
		{
			HX_STACK_LINE(343)
			Float len = ::Math_obj::sqrt((((result->x * result->x) + (result->y * result->y)) + (result->z * result->z)));		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(343)
			if (((len != (int)0))){
				HX_STACK_LINE(343)
				Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
				HX_STACK_LINE(343)
				hx::MultEq(result->x,num);
				HX_STACK_LINE(343)
				hx::MultEq(result->y,num);
				HX_STACK_LINE(343)
				hx::MultEq(result->z,num);
			}
		}
	}
	HX_STACK_LINE(344)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector3_obj,Normalize,return )

Void Vector3_obj::NormalizeToRef( ::com::engine::math::Vector3 vector,::com::engine::math::Vector3 result){
{
		HX_STACK_PUSH("Vector3::NormalizeToRef","com/engine/math/Vector3.hx",347);
		HX_STACK_ARG(vector,"vector");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(348)
		{
			HX_STACK_LINE(348)
			result->x = vector->x;
			HX_STACK_LINE(348)
			result->y = vector->y;
			HX_STACK_LINE(348)
			result->z = vector->z;
		}
		HX_STACK_LINE(349)
		{
			HX_STACK_LINE(349)
			Float len = ::Math_obj::sqrt((((result->x * result->x) + (result->y * result->y)) + (result->z * result->z)));		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(349)
			if (((len != (int)0))){
				HX_STACK_LINE(349)
				Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
				HX_STACK_LINE(349)
				hx::MultEq(result->x,num);
				HX_STACK_LINE(349)
				hx::MultEq(result->y,num);
				HX_STACK_LINE(349)
				hx::MultEq(result->z,num);
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,NormalizeToRef,(void))

::com::engine::math::Vector3 Vector3_obj::Project( ::com::engine::math::Vector3 vector,::com::engine::math::Matrix world,::com::engine::math::Matrix transform,::com::engine::render::Clip viewport){
	HX_STACK_PUSH("Vector3::Project","com/engine/math/Vector3.hx",353);
	HX_STACK_ARG(vector,"vector");
	HX_STACK_ARG(world,"world");
	HX_STACK_ARG(transform,"transform");
	HX_STACK_ARG(viewport,"viewport");
	HX_STACK_LINE(354)
	int cw = viewport->width;		HX_STACK_VAR(cw,"cw");
	HX_STACK_LINE(355)
	int ch = viewport->height;		HX_STACK_VAR(ch,"ch");
	HX_STACK_LINE(356)
	int cx = viewport->x;		HX_STACK_VAR(cx,"cx");
	HX_STACK_LINE(357)
	int cy = viewport->y;		HX_STACK_VAR(cy,"cy");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( int &cw,int &ch,int &cy,int &cx){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",359);
			{
				HX_STACK_LINE(359)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(359)
				result->m[(int)0] = (Float(cw) / Float(2.0));
				HX_STACK_LINE(359)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)5] = (Float(-(ch)) / Float(2.0));
				HX_STACK_LINE(359)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)10] = (int)1;
				HX_STACK_LINE(359)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)12] = (cx + (Float(cw) / Float(2.0)));
				HX_STACK_LINE(359)
				result->m[(int)13] = ((Float(ch) / Float(2.0)) + cy);
				HX_STACK_LINE(359)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(359)
				result->m[(int)15] = (int)1;
				HX_STACK_LINE(359)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(359)
	::com::engine::math::Matrix viewportMatrix = _Function_1_1::Block(cw,ch,cy,cx);		HX_STACK_VAR(viewportMatrix,"viewportMatrix");
	struct _Function_1_2{
		inline static ::com::engine::math::Matrix Block( ::com::engine::math::Matrix &transform,::com::engine::math::Matrix &viewportMatrix,::com::engine::math::Matrix &world){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",365);
			{
				struct _Function_2_1{
					inline static ::com::engine::math::Matrix Block( ::com::engine::math::Matrix &world,::com::engine::math::Matrix &transform){
						HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",365);
						{
							HX_STACK_LINE(365)
							::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
							HX_STACK_LINE(365)
							{
								HX_STACK_LINE(365)
								Array< Float > result1 = result->m;		HX_STACK_VAR(result1,"result1");
								HX_STACK_LINE(365)
								Float tm0 = world->m->__get((int)0);		HX_STACK_VAR(tm0,"tm0");
								HX_STACK_LINE(365)
								Float tm1 = world->m->__get((int)1);		HX_STACK_VAR(tm1,"tm1");
								HX_STACK_LINE(365)
								Float tm2 = world->m->__get((int)2);		HX_STACK_VAR(tm2,"tm2");
								HX_STACK_LINE(365)
								Float tm3 = world->m->__get((int)3);		HX_STACK_VAR(tm3,"tm3");
								HX_STACK_LINE(365)
								Float tm4 = world->m->__get((int)4);		HX_STACK_VAR(tm4,"tm4");
								HX_STACK_LINE(365)
								Float tm5 = world->m->__get((int)5);		HX_STACK_VAR(tm5,"tm5");
								HX_STACK_LINE(365)
								Float tm6 = world->m->__get((int)6);		HX_STACK_VAR(tm6,"tm6");
								HX_STACK_LINE(365)
								Float tm7 = world->m->__get((int)7);		HX_STACK_VAR(tm7,"tm7");
								HX_STACK_LINE(365)
								Float tm8 = world->m->__get((int)8);		HX_STACK_VAR(tm8,"tm8");
								HX_STACK_LINE(365)
								Float tm9 = world->m->__get((int)9);		HX_STACK_VAR(tm9,"tm9");
								HX_STACK_LINE(365)
								Float tm10 = world->m->__get((int)10);		HX_STACK_VAR(tm10,"tm10");
								HX_STACK_LINE(365)
								Float tm11 = world->m->__get((int)11);		HX_STACK_VAR(tm11,"tm11");
								HX_STACK_LINE(365)
								Float tm12 = world->m->__get((int)12);		HX_STACK_VAR(tm12,"tm12");
								HX_STACK_LINE(365)
								Float tm13 = world->m->__get((int)13);		HX_STACK_VAR(tm13,"tm13");
								HX_STACK_LINE(365)
								Float tm14 = world->m->__get((int)14);		HX_STACK_VAR(tm14,"tm14");
								HX_STACK_LINE(365)
								Float tm15 = world->m->__get((int)15);		HX_STACK_VAR(tm15,"tm15");
								HX_STACK_LINE(365)
								Float om0 = transform->m->__get((int)0);		HX_STACK_VAR(om0,"om0");
								HX_STACK_LINE(365)
								Float om1 = transform->m->__get((int)1);		HX_STACK_VAR(om1,"om1");
								HX_STACK_LINE(365)
								Float om2 = transform->m->__get((int)2);		HX_STACK_VAR(om2,"om2");
								HX_STACK_LINE(365)
								Float om3 = transform->m->__get((int)3);		HX_STACK_VAR(om3,"om3");
								HX_STACK_LINE(365)
								Float om4 = transform->m->__get((int)4);		HX_STACK_VAR(om4,"om4");
								HX_STACK_LINE(365)
								Float om5 = transform->m->__get((int)5);		HX_STACK_VAR(om5,"om5");
								HX_STACK_LINE(365)
								Float om6 = transform->m->__get((int)6);		HX_STACK_VAR(om6,"om6");
								HX_STACK_LINE(365)
								Float om7 = transform->m->__get((int)7);		HX_STACK_VAR(om7,"om7");
								HX_STACK_LINE(365)
								Float om8 = transform->m->__get((int)8);		HX_STACK_VAR(om8,"om8");
								HX_STACK_LINE(365)
								Float om9 = transform->m->__get((int)9);		HX_STACK_VAR(om9,"om9");
								HX_STACK_LINE(365)
								Float om10 = transform->m->__get((int)10);		HX_STACK_VAR(om10,"om10");
								HX_STACK_LINE(365)
								Float om11 = transform->m->__get((int)11);		HX_STACK_VAR(om11,"om11");
								HX_STACK_LINE(365)
								Float om12 = transform->m->__get((int)12);		HX_STACK_VAR(om12,"om12");
								HX_STACK_LINE(365)
								Float om13 = transform->m->__get((int)13);		HX_STACK_VAR(om13,"om13");
								HX_STACK_LINE(365)
								Float om14 = transform->m->__get((int)14);		HX_STACK_VAR(om14,"om14");
								HX_STACK_LINE(365)
								Float om15 = transform->m->__get((int)15);		HX_STACK_VAR(om15,"om15");
								HX_STACK_LINE(365)
								result1[(int)0] = ((((tm0 * om0) + (tm1 * om4)) + (tm2 * om8)) + (tm3 * om12));
								HX_STACK_LINE(365)
								result1[(int)1] = ((((tm0 * om1) + (tm1 * om5)) + (tm2 * om9)) + (tm3 * om13));
								HX_STACK_LINE(365)
								result1[(int)2] = ((((tm0 * om2) + (tm1 * om6)) + (tm2 * om10)) + (tm3 * om14));
								HX_STACK_LINE(365)
								result1[(int)3] = ((((tm0 * om3) + (tm1 * om7)) + (tm2 * om11)) + (tm3 * om15));
								HX_STACK_LINE(365)
								result1[(int)4] = ((((tm4 * om0) + (tm5 * om4)) + (tm6 * om8)) + (tm7 * om12));
								HX_STACK_LINE(365)
								result1[(int)5] = ((((tm4 * om1) + (tm5 * om5)) + (tm6 * om9)) + (tm7 * om13));
								HX_STACK_LINE(365)
								result1[(int)6] = ((((tm4 * om2) + (tm5 * om6)) + (tm6 * om10)) + (tm7 * om14));
								HX_STACK_LINE(365)
								result1[(int)7] = ((((tm4 * om3) + (tm5 * om7)) + (tm6 * om11)) + (tm7 * om15));
								HX_STACK_LINE(365)
								result1[(int)8] = ((((tm8 * om0) + (tm9 * om4)) + (tm10 * om8)) + (tm11 * om12));
								HX_STACK_LINE(365)
								result1[(int)9] = ((((tm8 * om1) + (tm9 * om5)) + (tm10 * om9)) + (tm11 * om13));
								HX_STACK_LINE(365)
								result1[(int)10] = ((((tm8 * om2) + (tm9 * om6)) + (tm10 * om10)) + (tm11 * om14));
								HX_STACK_LINE(365)
								result1[(int)11] = ((((tm8 * om3) + (tm9 * om7)) + (tm10 * om11)) + (tm11 * om15));
								HX_STACK_LINE(365)
								result1[(int)12] = ((((tm12 * om0) + (tm13 * om4)) + (tm14 * om8)) + (tm15 * om12));
								HX_STACK_LINE(365)
								result1[(int)13] = ((((tm12 * om1) + (tm13 * om5)) + (tm14 * om9)) + (tm15 * om13));
								HX_STACK_LINE(365)
								result1[(int)14] = ((((tm12 * om2) + (tm13 * om6)) + (tm14 * om10)) + (tm15 * om14));
								HX_STACK_LINE(365)
								result1[(int)15] = ((((tm12 * om3) + (tm13 * om7)) + (tm14 * om11)) + (tm15 * om15));
								HX_STACK_LINE(365)
								result1;
							}
							HX_STACK_LINE(365)
							return result;
						}
						return null();
					}
				};
				HX_STACK_LINE(365)
				::com::engine::math::Matrix _this = _Function_2_1::Block(world,transform);		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(365)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(365)
				{
					HX_STACK_LINE(365)
					Array< Float > result1 = result->m;		HX_STACK_VAR(result1,"result1");
					HX_STACK_LINE(365)
					Float tm0 = _this->m->__get((int)0);		HX_STACK_VAR(tm0,"tm0");
					HX_STACK_LINE(365)
					Float tm1 = _this->m->__get((int)1);		HX_STACK_VAR(tm1,"tm1");
					HX_STACK_LINE(365)
					Float tm2 = _this->m->__get((int)2);		HX_STACK_VAR(tm2,"tm2");
					HX_STACK_LINE(365)
					Float tm3 = _this->m->__get((int)3);		HX_STACK_VAR(tm3,"tm3");
					HX_STACK_LINE(365)
					Float tm4 = _this->m->__get((int)4);		HX_STACK_VAR(tm4,"tm4");
					HX_STACK_LINE(365)
					Float tm5 = _this->m->__get((int)5);		HX_STACK_VAR(tm5,"tm5");
					HX_STACK_LINE(365)
					Float tm6 = _this->m->__get((int)6);		HX_STACK_VAR(tm6,"tm6");
					HX_STACK_LINE(365)
					Float tm7 = _this->m->__get((int)7);		HX_STACK_VAR(tm7,"tm7");
					HX_STACK_LINE(365)
					Float tm8 = _this->m->__get((int)8);		HX_STACK_VAR(tm8,"tm8");
					HX_STACK_LINE(365)
					Float tm9 = _this->m->__get((int)9);		HX_STACK_VAR(tm9,"tm9");
					HX_STACK_LINE(365)
					Float tm10 = _this->m->__get((int)10);		HX_STACK_VAR(tm10,"tm10");
					HX_STACK_LINE(365)
					Float tm11 = _this->m->__get((int)11);		HX_STACK_VAR(tm11,"tm11");
					HX_STACK_LINE(365)
					Float tm12 = _this->m->__get((int)12);		HX_STACK_VAR(tm12,"tm12");
					HX_STACK_LINE(365)
					Float tm13 = _this->m->__get((int)13);		HX_STACK_VAR(tm13,"tm13");
					HX_STACK_LINE(365)
					Float tm14 = _this->m->__get((int)14);		HX_STACK_VAR(tm14,"tm14");
					HX_STACK_LINE(365)
					Float tm15 = _this->m->__get((int)15);		HX_STACK_VAR(tm15,"tm15");
					HX_STACK_LINE(365)
					Float om0 = viewportMatrix->m->__get((int)0);		HX_STACK_VAR(om0,"om0");
					HX_STACK_LINE(365)
					Float om1 = viewportMatrix->m->__get((int)1);		HX_STACK_VAR(om1,"om1");
					HX_STACK_LINE(365)
					Float om2 = viewportMatrix->m->__get((int)2);		HX_STACK_VAR(om2,"om2");
					HX_STACK_LINE(365)
					Float om3 = viewportMatrix->m->__get((int)3);		HX_STACK_VAR(om3,"om3");
					HX_STACK_LINE(365)
					Float om4 = viewportMatrix->m->__get((int)4);		HX_STACK_VAR(om4,"om4");
					HX_STACK_LINE(365)
					Float om5 = viewportMatrix->m->__get((int)5);		HX_STACK_VAR(om5,"om5");
					HX_STACK_LINE(365)
					Float om6 = viewportMatrix->m->__get((int)6);		HX_STACK_VAR(om6,"om6");
					HX_STACK_LINE(365)
					Float om7 = viewportMatrix->m->__get((int)7);		HX_STACK_VAR(om7,"om7");
					HX_STACK_LINE(365)
					Float om8 = viewportMatrix->m->__get((int)8);		HX_STACK_VAR(om8,"om8");
					HX_STACK_LINE(365)
					Float om9 = viewportMatrix->m->__get((int)9);		HX_STACK_VAR(om9,"om9");
					HX_STACK_LINE(365)
					Float om10 = viewportMatrix->m->__get((int)10);		HX_STACK_VAR(om10,"om10");
					HX_STACK_LINE(365)
					Float om11 = viewportMatrix->m->__get((int)11);		HX_STACK_VAR(om11,"om11");
					HX_STACK_LINE(365)
					Float om12 = viewportMatrix->m->__get((int)12);		HX_STACK_VAR(om12,"om12");
					HX_STACK_LINE(365)
					Float om13 = viewportMatrix->m->__get((int)13);		HX_STACK_VAR(om13,"om13");
					HX_STACK_LINE(365)
					Float om14 = viewportMatrix->m->__get((int)14);		HX_STACK_VAR(om14,"om14");
					HX_STACK_LINE(365)
					Float om15 = viewportMatrix->m->__get((int)15);		HX_STACK_VAR(om15,"om15");
					HX_STACK_LINE(365)
					result1[(int)0] = ((((tm0 * om0) + (tm1 * om4)) + (tm2 * om8)) + (tm3 * om12));
					HX_STACK_LINE(365)
					result1[(int)1] = ((((tm0 * om1) + (tm1 * om5)) + (tm2 * om9)) + (tm3 * om13));
					HX_STACK_LINE(365)
					result1[(int)2] = ((((tm0 * om2) + (tm1 * om6)) + (tm2 * om10)) + (tm3 * om14));
					HX_STACK_LINE(365)
					result1[(int)3] = ((((tm0 * om3) + (tm1 * om7)) + (tm2 * om11)) + (tm3 * om15));
					HX_STACK_LINE(365)
					result1[(int)4] = ((((tm4 * om0) + (tm5 * om4)) + (tm6 * om8)) + (tm7 * om12));
					HX_STACK_LINE(365)
					result1[(int)5] = ((((tm4 * om1) + (tm5 * om5)) + (tm6 * om9)) + (tm7 * om13));
					HX_STACK_LINE(365)
					result1[(int)6] = ((((tm4 * om2) + (tm5 * om6)) + (tm6 * om10)) + (tm7 * om14));
					HX_STACK_LINE(365)
					result1[(int)7] = ((((tm4 * om3) + (tm5 * om7)) + (tm6 * om11)) + (tm7 * om15));
					HX_STACK_LINE(365)
					result1[(int)8] = ((((tm8 * om0) + (tm9 * om4)) + (tm10 * om8)) + (tm11 * om12));
					HX_STACK_LINE(365)
					result1[(int)9] = ((((tm8 * om1) + (tm9 * om5)) + (tm10 * om9)) + (tm11 * om13));
					HX_STACK_LINE(365)
					result1[(int)10] = ((((tm8 * om2) + (tm9 * om6)) + (tm10 * om10)) + (tm11 * om14));
					HX_STACK_LINE(365)
					result1[(int)11] = ((((tm8 * om3) + (tm9 * om7)) + (tm10 * om11)) + (tm11 * om15));
					HX_STACK_LINE(365)
					result1[(int)12] = ((((tm12 * om0) + (tm13 * om4)) + (tm14 * om8)) + (tm15 * om12));
					HX_STACK_LINE(365)
					result1[(int)13] = ((((tm12 * om1) + (tm13 * om5)) + (tm14 * om9)) + (tm15 * om13));
					HX_STACK_LINE(365)
					result1[(int)14] = ((((tm12 * om2) + (tm13 * om6)) + (tm14 * om10)) + (tm15 * om14));
					HX_STACK_LINE(365)
					result1[(int)15] = ((((tm12 * om3) + (tm13 * om7)) + (tm14 * om11)) + (tm15 * om15));
					HX_STACK_LINE(365)
					result1;
				}
				HX_STACK_LINE(365)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(365)
	::com::engine::math::Matrix finalMatrix = _Function_1_2::Block(transform,viewportMatrix,world);		HX_STACK_VAR(finalMatrix,"finalMatrix");
	struct _Function_1_3{
		inline static ::com::engine::math::Vector3 Block( ::com::engine::math::Vector3 &vector,::com::engine::math::Matrix &finalMatrix){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",367);
			{
				HX_STACK_LINE(367)
				::com::engine::math::Vector3 result = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(367)
				{
					HX_STACK_LINE(367)
					Float x = ((((vector->x * finalMatrix->m->__get((int)0)) + (vector->y * finalMatrix->m->__get((int)4))) + (vector->z * finalMatrix->m->__get((int)8))) + finalMatrix->m->__get((int)12));		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(367)
					Float y = ((((vector->x * finalMatrix->m->__get((int)1)) + (vector->y * finalMatrix->m->__get((int)5))) + (vector->z * finalMatrix->m->__get((int)9))) + finalMatrix->m->__get((int)13));		HX_STACK_VAR(y,"y");
					HX_STACK_LINE(367)
					Float z = ((((vector->x * finalMatrix->m->__get((int)2)) + (vector->y * finalMatrix->m->__get((int)6))) + (vector->z * finalMatrix->m->__get((int)10))) + finalMatrix->m->__get((int)14));		HX_STACK_VAR(z,"z");
					HX_STACK_LINE(367)
					Float w = ((((vector->x * finalMatrix->m->__get((int)3)) + (vector->y * finalMatrix->m->__get((int)7))) + (vector->z * finalMatrix->m->__get((int)11))) + finalMatrix->m->__get((int)15));		HX_STACK_VAR(w,"w");
					HX_STACK_LINE(367)
					result->x = (Float(x) / Float(w));
					HX_STACK_LINE(367)
					result->y = (Float(y) / Float(w));
					HX_STACK_LINE(367)
					result->z = (Float(z) / Float(w));
				}
				HX_STACK_LINE(367)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(367)
	return _Function_1_3::Block(vector,finalMatrix);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Vector3_obj,Project,return )

::com::engine::math::Vector3 Vector3_obj::Unproject( ::com::engine::math::Vector3 source,Float viewportWidth,Float viewportHeight,::com::engine::math::Matrix world,::com::engine::math::Matrix view,::com::engine::math::Matrix projection){
	HX_STACK_PUSH("Vector3::Unproject","com/engine/math/Vector3.hx",370);
	HX_STACK_ARG(source,"source");
	HX_STACK_ARG(viewportWidth,"viewportWidth");
	HX_STACK_ARG(viewportHeight,"viewportHeight");
	HX_STACK_ARG(world,"world");
	HX_STACK_ARG(view,"view");
	HX_STACK_ARG(projection,"projection");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ::com::engine::math::Matrix &view,::com::engine::math::Matrix &projection,::com::engine::math::Matrix &world){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",371);
			{
				struct _Function_2_1{
					inline static ::com::engine::math::Matrix Block( ::com::engine::math::Matrix &world,::com::engine::math::Matrix &view){
						HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",371);
						{
							HX_STACK_LINE(371)
							::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
							HX_STACK_LINE(371)
							{
								HX_STACK_LINE(371)
								Array< Float > result1 = result->m;		HX_STACK_VAR(result1,"result1");
								HX_STACK_LINE(371)
								Float tm0 = world->m->__get((int)0);		HX_STACK_VAR(tm0,"tm0");
								HX_STACK_LINE(371)
								Float tm1 = world->m->__get((int)1);		HX_STACK_VAR(tm1,"tm1");
								HX_STACK_LINE(371)
								Float tm2 = world->m->__get((int)2);		HX_STACK_VAR(tm2,"tm2");
								HX_STACK_LINE(371)
								Float tm3 = world->m->__get((int)3);		HX_STACK_VAR(tm3,"tm3");
								HX_STACK_LINE(371)
								Float tm4 = world->m->__get((int)4);		HX_STACK_VAR(tm4,"tm4");
								HX_STACK_LINE(371)
								Float tm5 = world->m->__get((int)5);		HX_STACK_VAR(tm5,"tm5");
								HX_STACK_LINE(371)
								Float tm6 = world->m->__get((int)6);		HX_STACK_VAR(tm6,"tm6");
								HX_STACK_LINE(371)
								Float tm7 = world->m->__get((int)7);		HX_STACK_VAR(tm7,"tm7");
								HX_STACK_LINE(371)
								Float tm8 = world->m->__get((int)8);		HX_STACK_VAR(tm8,"tm8");
								HX_STACK_LINE(371)
								Float tm9 = world->m->__get((int)9);		HX_STACK_VAR(tm9,"tm9");
								HX_STACK_LINE(371)
								Float tm10 = world->m->__get((int)10);		HX_STACK_VAR(tm10,"tm10");
								HX_STACK_LINE(371)
								Float tm11 = world->m->__get((int)11);		HX_STACK_VAR(tm11,"tm11");
								HX_STACK_LINE(371)
								Float tm12 = world->m->__get((int)12);		HX_STACK_VAR(tm12,"tm12");
								HX_STACK_LINE(371)
								Float tm13 = world->m->__get((int)13);		HX_STACK_VAR(tm13,"tm13");
								HX_STACK_LINE(371)
								Float tm14 = world->m->__get((int)14);		HX_STACK_VAR(tm14,"tm14");
								HX_STACK_LINE(371)
								Float tm15 = world->m->__get((int)15);		HX_STACK_VAR(tm15,"tm15");
								HX_STACK_LINE(371)
								Float om0 = view->m->__get((int)0);		HX_STACK_VAR(om0,"om0");
								HX_STACK_LINE(371)
								Float om1 = view->m->__get((int)1);		HX_STACK_VAR(om1,"om1");
								HX_STACK_LINE(371)
								Float om2 = view->m->__get((int)2);		HX_STACK_VAR(om2,"om2");
								HX_STACK_LINE(371)
								Float om3 = view->m->__get((int)3);		HX_STACK_VAR(om3,"om3");
								HX_STACK_LINE(371)
								Float om4 = view->m->__get((int)4);		HX_STACK_VAR(om4,"om4");
								HX_STACK_LINE(371)
								Float om5 = view->m->__get((int)5);		HX_STACK_VAR(om5,"om5");
								HX_STACK_LINE(371)
								Float om6 = view->m->__get((int)6);		HX_STACK_VAR(om6,"om6");
								HX_STACK_LINE(371)
								Float om7 = view->m->__get((int)7);		HX_STACK_VAR(om7,"om7");
								HX_STACK_LINE(371)
								Float om8 = view->m->__get((int)8);		HX_STACK_VAR(om8,"om8");
								HX_STACK_LINE(371)
								Float om9 = view->m->__get((int)9);		HX_STACK_VAR(om9,"om9");
								HX_STACK_LINE(371)
								Float om10 = view->m->__get((int)10);		HX_STACK_VAR(om10,"om10");
								HX_STACK_LINE(371)
								Float om11 = view->m->__get((int)11);		HX_STACK_VAR(om11,"om11");
								HX_STACK_LINE(371)
								Float om12 = view->m->__get((int)12);		HX_STACK_VAR(om12,"om12");
								HX_STACK_LINE(371)
								Float om13 = view->m->__get((int)13);		HX_STACK_VAR(om13,"om13");
								HX_STACK_LINE(371)
								Float om14 = view->m->__get((int)14);		HX_STACK_VAR(om14,"om14");
								HX_STACK_LINE(371)
								Float om15 = view->m->__get((int)15);		HX_STACK_VAR(om15,"om15");
								HX_STACK_LINE(371)
								result1[(int)0] = ((((tm0 * om0) + (tm1 * om4)) + (tm2 * om8)) + (tm3 * om12));
								HX_STACK_LINE(371)
								result1[(int)1] = ((((tm0 * om1) + (tm1 * om5)) + (tm2 * om9)) + (tm3 * om13));
								HX_STACK_LINE(371)
								result1[(int)2] = ((((tm0 * om2) + (tm1 * om6)) + (tm2 * om10)) + (tm3 * om14));
								HX_STACK_LINE(371)
								result1[(int)3] = ((((tm0 * om3) + (tm1 * om7)) + (tm2 * om11)) + (tm3 * om15));
								HX_STACK_LINE(371)
								result1[(int)4] = ((((tm4 * om0) + (tm5 * om4)) + (tm6 * om8)) + (tm7 * om12));
								HX_STACK_LINE(371)
								result1[(int)5] = ((((tm4 * om1) + (tm5 * om5)) + (tm6 * om9)) + (tm7 * om13));
								HX_STACK_LINE(371)
								result1[(int)6] = ((((tm4 * om2) + (tm5 * om6)) + (tm6 * om10)) + (tm7 * om14));
								HX_STACK_LINE(371)
								result1[(int)7] = ((((tm4 * om3) + (tm5 * om7)) + (tm6 * om11)) + (tm7 * om15));
								HX_STACK_LINE(371)
								result1[(int)8] = ((((tm8 * om0) + (tm9 * om4)) + (tm10 * om8)) + (tm11 * om12));
								HX_STACK_LINE(371)
								result1[(int)9] = ((((tm8 * om1) + (tm9 * om5)) + (tm10 * om9)) + (tm11 * om13));
								HX_STACK_LINE(371)
								result1[(int)10] = ((((tm8 * om2) + (tm9 * om6)) + (tm10 * om10)) + (tm11 * om14));
								HX_STACK_LINE(371)
								result1[(int)11] = ((((tm8 * om3) + (tm9 * om7)) + (tm10 * om11)) + (tm11 * om15));
								HX_STACK_LINE(371)
								result1[(int)12] = ((((tm12 * om0) + (tm13 * om4)) + (tm14 * om8)) + (tm15 * om12));
								HX_STACK_LINE(371)
								result1[(int)13] = ((((tm12 * om1) + (tm13 * om5)) + (tm14 * om9)) + (tm15 * om13));
								HX_STACK_LINE(371)
								result1[(int)14] = ((((tm12 * om2) + (tm13 * om6)) + (tm14 * om10)) + (tm15 * om14));
								HX_STACK_LINE(371)
								result1[(int)15] = ((((tm12 * om3) + (tm13 * om7)) + (tm14 * om11)) + (tm15 * om15));
								HX_STACK_LINE(371)
								result1;
							}
							HX_STACK_LINE(371)
							return result;
						}
						return null();
					}
				};
				HX_STACK_LINE(371)
				::com::engine::math::Matrix _this = _Function_2_1::Block(world,view);		HX_STACK_VAR(_this,"_this");
				HX_STACK_LINE(371)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(371)
				{
					HX_STACK_LINE(371)
					Array< Float > result1 = result->m;		HX_STACK_VAR(result1,"result1");
					HX_STACK_LINE(371)
					Float tm0 = _this->m->__get((int)0);		HX_STACK_VAR(tm0,"tm0");
					HX_STACK_LINE(371)
					Float tm1 = _this->m->__get((int)1);		HX_STACK_VAR(tm1,"tm1");
					HX_STACK_LINE(371)
					Float tm2 = _this->m->__get((int)2);		HX_STACK_VAR(tm2,"tm2");
					HX_STACK_LINE(371)
					Float tm3 = _this->m->__get((int)3);		HX_STACK_VAR(tm3,"tm3");
					HX_STACK_LINE(371)
					Float tm4 = _this->m->__get((int)4);		HX_STACK_VAR(tm4,"tm4");
					HX_STACK_LINE(371)
					Float tm5 = _this->m->__get((int)5);		HX_STACK_VAR(tm5,"tm5");
					HX_STACK_LINE(371)
					Float tm6 = _this->m->__get((int)6);		HX_STACK_VAR(tm6,"tm6");
					HX_STACK_LINE(371)
					Float tm7 = _this->m->__get((int)7);		HX_STACK_VAR(tm7,"tm7");
					HX_STACK_LINE(371)
					Float tm8 = _this->m->__get((int)8);		HX_STACK_VAR(tm8,"tm8");
					HX_STACK_LINE(371)
					Float tm9 = _this->m->__get((int)9);		HX_STACK_VAR(tm9,"tm9");
					HX_STACK_LINE(371)
					Float tm10 = _this->m->__get((int)10);		HX_STACK_VAR(tm10,"tm10");
					HX_STACK_LINE(371)
					Float tm11 = _this->m->__get((int)11);		HX_STACK_VAR(tm11,"tm11");
					HX_STACK_LINE(371)
					Float tm12 = _this->m->__get((int)12);		HX_STACK_VAR(tm12,"tm12");
					HX_STACK_LINE(371)
					Float tm13 = _this->m->__get((int)13);		HX_STACK_VAR(tm13,"tm13");
					HX_STACK_LINE(371)
					Float tm14 = _this->m->__get((int)14);		HX_STACK_VAR(tm14,"tm14");
					HX_STACK_LINE(371)
					Float tm15 = _this->m->__get((int)15);		HX_STACK_VAR(tm15,"tm15");
					HX_STACK_LINE(371)
					Float om0 = projection->m->__get((int)0);		HX_STACK_VAR(om0,"om0");
					HX_STACK_LINE(371)
					Float om1 = projection->m->__get((int)1);		HX_STACK_VAR(om1,"om1");
					HX_STACK_LINE(371)
					Float om2 = projection->m->__get((int)2);		HX_STACK_VAR(om2,"om2");
					HX_STACK_LINE(371)
					Float om3 = projection->m->__get((int)3);		HX_STACK_VAR(om3,"om3");
					HX_STACK_LINE(371)
					Float om4 = projection->m->__get((int)4);		HX_STACK_VAR(om4,"om4");
					HX_STACK_LINE(371)
					Float om5 = projection->m->__get((int)5);		HX_STACK_VAR(om5,"om5");
					HX_STACK_LINE(371)
					Float om6 = projection->m->__get((int)6);		HX_STACK_VAR(om6,"om6");
					HX_STACK_LINE(371)
					Float om7 = projection->m->__get((int)7);		HX_STACK_VAR(om7,"om7");
					HX_STACK_LINE(371)
					Float om8 = projection->m->__get((int)8);		HX_STACK_VAR(om8,"om8");
					HX_STACK_LINE(371)
					Float om9 = projection->m->__get((int)9);		HX_STACK_VAR(om9,"om9");
					HX_STACK_LINE(371)
					Float om10 = projection->m->__get((int)10);		HX_STACK_VAR(om10,"om10");
					HX_STACK_LINE(371)
					Float om11 = projection->m->__get((int)11);		HX_STACK_VAR(om11,"om11");
					HX_STACK_LINE(371)
					Float om12 = projection->m->__get((int)12);		HX_STACK_VAR(om12,"om12");
					HX_STACK_LINE(371)
					Float om13 = projection->m->__get((int)13);		HX_STACK_VAR(om13,"om13");
					HX_STACK_LINE(371)
					Float om14 = projection->m->__get((int)14);		HX_STACK_VAR(om14,"om14");
					HX_STACK_LINE(371)
					Float om15 = projection->m->__get((int)15);		HX_STACK_VAR(om15,"om15");
					HX_STACK_LINE(371)
					result1[(int)0] = ((((tm0 * om0) + (tm1 * om4)) + (tm2 * om8)) + (tm3 * om12));
					HX_STACK_LINE(371)
					result1[(int)1] = ((((tm0 * om1) + (tm1 * om5)) + (tm2 * om9)) + (tm3 * om13));
					HX_STACK_LINE(371)
					result1[(int)2] = ((((tm0 * om2) + (tm1 * om6)) + (tm2 * om10)) + (tm3 * om14));
					HX_STACK_LINE(371)
					result1[(int)3] = ((((tm0 * om3) + (tm1 * om7)) + (tm2 * om11)) + (tm3 * om15));
					HX_STACK_LINE(371)
					result1[(int)4] = ((((tm4 * om0) + (tm5 * om4)) + (tm6 * om8)) + (tm7 * om12));
					HX_STACK_LINE(371)
					result1[(int)5] = ((((tm4 * om1) + (tm5 * om5)) + (tm6 * om9)) + (tm7 * om13));
					HX_STACK_LINE(371)
					result1[(int)6] = ((((tm4 * om2) + (tm5 * om6)) + (tm6 * om10)) + (tm7 * om14));
					HX_STACK_LINE(371)
					result1[(int)7] = ((((tm4 * om3) + (tm5 * om7)) + (tm6 * om11)) + (tm7 * om15));
					HX_STACK_LINE(371)
					result1[(int)8] = ((((tm8 * om0) + (tm9 * om4)) + (tm10 * om8)) + (tm11 * om12));
					HX_STACK_LINE(371)
					result1[(int)9] = ((((tm8 * om1) + (tm9 * om5)) + (tm10 * om9)) + (tm11 * om13));
					HX_STACK_LINE(371)
					result1[(int)10] = ((((tm8 * om2) + (tm9 * om6)) + (tm10 * om10)) + (tm11 * om14));
					HX_STACK_LINE(371)
					result1[(int)11] = ((((tm8 * om3) + (tm9 * om7)) + (tm10 * om11)) + (tm11 * om15));
					HX_STACK_LINE(371)
					result1[(int)12] = ((((tm12 * om0) + (tm13 * om4)) + (tm14 * om8)) + (tm15 * om12));
					HX_STACK_LINE(371)
					result1[(int)13] = ((((tm12 * om1) + (tm13 * om5)) + (tm14 * om9)) + (tm15 * om13));
					HX_STACK_LINE(371)
					result1[(int)14] = ((((tm12 * om2) + (tm13 * om6)) + (tm14 * om10)) + (tm15 * om14));
					HX_STACK_LINE(371)
					result1[(int)15] = ((((tm12 * om3) + (tm13 * om7)) + (tm14 * om11)) + (tm15 * om15));
					HX_STACK_LINE(371)
					result1;
				}
				HX_STACK_LINE(371)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(371)
	::com::engine::math::Matrix matrix = _Function_1_1::Block(view,projection,world);		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(372)
	{
		HX_STACK_LINE(372)
		Float l1 = matrix->m->__get((int)0);		HX_STACK_VAR(l1,"l1");
		HX_STACK_LINE(372)
		Float l2 = matrix->m->__get((int)1);		HX_STACK_VAR(l2,"l2");
		HX_STACK_LINE(372)
		Float l3 = matrix->m->__get((int)2);		HX_STACK_VAR(l3,"l3");
		HX_STACK_LINE(372)
		Float l4 = matrix->m->__get((int)3);		HX_STACK_VAR(l4,"l4");
		HX_STACK_LINE(372)
		Float l5 = matrix->m->__get((int)4);		HX_STACK_VAR(l5,"l5");
		HX_STACK_LINE(372)
		Float l6 = matrix->m->__get((int)5);		HX_STACK_VAR(l6,"l6");
		HX_STACK_LINE(372)
		Float l7 = matrix->m->__get((int)6);		HX_STACK_VAR(l7,"l7");
		HX_STACK_LINE(372)
		Float l8 = matrix->m->__get((int)7);		HX_STACK_VAR(l8,"l8");
		HX_STACK_LINE(372)
		Float l9 = matrix->m->__get((int)8);		HX_STACK_VAR(l9,"l9");
		HX_STACK_LINE(372)
		Float l10 = matrix->m->__get((int)9);		HX_STACK_VAR(l10,"l10");
		HX_STACK_LINE(372)
		Float l11 = matrix->m->__get((int)10);		HX_STACK_VAR(l11,"l11");
		HX_STACK_LINE(372)
		Float l12 = matrix->m->__get((int)11);		HX_STACK_VAR(l12,"l12");
		HX_STACK_LINE(372)
		Float l13 = matrix->m->__get((int)12);		HX_STACK_VAR(l13,"l13");
		HX_STACK_LINE(372)
		Float l14 = matrix->m->__get((int)13);		HX_STACK_VAR(l14,"l14");
		HX_STACK_LINE(372)
		Float l15 = matrix->m->__get((int)14);		HX_STACK_VAR(l15,"l15");
		HX_STACK_LINE(372)
		Float l16 = matrix->m->__get((int)15);		HX_STACK_VAR(l16,"l16");
		HX_STACK_LINE(372)
		Float l17 = ((l11 * l16) - (l12 * l15));		HX_STACK_VAR(l17,"l17");
		HX_STACK_LINE(372)
		Float l18 = ((l10 * l16) - (l12 * l14));		HX_STACK_VAR(l18,"l18");
		HX_STACK_LINE(372)
		Float l19 = ((l10 * l15) - (l11 * l14));		HX_STACK_VAR(l19,"l19");
		HX_STACK_LINE(372)
		Float l20 = ((l9 * l16) - (l12 * l13));		HX_STACK_VAR(l20,"l20");
		HX_STACK_LINE(372)
		Float l21 = ((l9 * l15) - (l11 * l13));		HX_STACK_VAR(l21,"l21");
		HX_STACK_LINE(372)
		Float l22 = ((l9 * l14) - (l10 * l13));		HX_STACK_VAR(l22,"l22");
		HX_STACK_LINE(372)
		Float l23 = (((l6 * l17) - (l7 * l18)) + (l8 * l19));		HX_STACK_VAR(l23,"l23");
		HX_STACK_LINE(372)
		Float l24 = -(((((l5 * l17) - (l7 * l20)) + (l8 * l21))));		HX_STACK_VAR(l24,"l24");
		HX_STACK_LINE(372)
		Float l25 = (((l5 * l18) - (l6 * l20)) + (l8 * l22));		HX_STACK_VAR(l25,"l25");
		HX_STACK_LINE(372)
		Float l26 = -(((((l5 * l19) - (l6 * l21)) + (l7 * l22))));		HX_STACK_VAR(l26,"l26");
		HX_STACK_LINE(372)
		Float l27 = (Float(1.0) / Float((((((l1 * l23) + (l2 * l24)) + (l3 * l25)) + (l4 * l26)))));		HX_STACK_VAR(l27,"l27");
		HX_STACK_LINE(372)
		Float l28 = ((l7 * l16) - (l8 * l15));		HX_STACK_VAR(l28,"l28");
		HX_STACK_LINE(372)
		Float l29 = ((l6 * l16) - (l8 * l14));		HX_STACK_VAR(l29,"l29");
		HX_STACK_LINE(372)
		Float l30 = ((l6 * l15) - (l7 * l14));		HX_STACK_VAR(l30,"l30");
		HX_STACK_LINE(372)
		Float l31 = ((l5 * l16) - (l8 * l13));		HX_STACK_VAR(l31,"l31");
		HX_STACK_LINE(372)
		Float l32 = ((l5 * l15) - (l7 * l13));		HX_STACK_VAR(l32,"l32");
		HX_STACK_LINE(372)
		Float l33 = ((l5 * l14) - (l6 * l13));		HX_STACK_VAR(l33,"l33");
		HX_STACK_LINE(372)
		Float l34 = ((l7 * l12) - (l8 * l11));		HX_STACK_VAR(l34,"l34");
		HX_STACK_LINE(372)
		Float l35 = ((l6 * l12) - (l8 * l10));		HX_STACK_VAR(l35,"l35");
		HX_STACK_LINE(372)
		Float l36 = ((l6 * l11) - (l7 * l10));		HX_STACK_VAR(l36,"l36");
		HX_STACK_LINE(372)
		Float l37 = ((l5 * l12) - (l8 * l9));		HX_STACK_VAR(l37,"l37");
		HX_STACK_LINE(372)
		Float l38 = ((l5 * l11) - (l7 * l9));		HX_STACK_VAR(l38,"l38");
		HX_STACK_LINE(372)
		Float l39 = ((l5 * l10) - (l6 * l9));		HX_STACK_VAR(l39,"l39");
		HX_STACK_LINE(372)
		matrix->m[(int)0] = (l23 * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)4] = (l24 * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)8] = (l25 * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)12] = (l26 * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)1] = (-(((((l2 * l17) - (l3 * l18)) + (l4 * l19)))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)5] = (((((l1 * l17) - (l3 * l20)) + (l4 * l21))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)9] = (-(((((l1 * l18) - (l2 * l20)) + (l4 * l22)))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)13] = (((((l1 * l19) - (l2 * l21)) + (l3 * l22))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)2] = (((((l2 * l28) - (l3 * l29)) + (l4 * l30))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)6] = (-(((((l1 * l28) - (l3 * l31)) + (l4 * l32)))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)10] = (((((l1 * l29) - (l2 * l31)) + (l4 * l33))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)14] = (-(((((l1 * l30) - (l2 * l32)) + (l3 * l33)))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)3] = (-(((((l2 * l34) - (l3 * l35)) + (l4 * l36)))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)7] = (((((l1 * l34) - (l3 * l37)) + (l4 * l38))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)11] = (-(((((l1 * l35) - (l2 * l37)) + (l4 * l39)))) * l27);
		HX_STACK_LINE(372)
		matrix->m[(int)15] = (((((l1 * l36) - (l2 * l38)) + (l3 * l39))) * l27);
	}
	HX_STACK_LINE(373)
	source->x = (((Float(source->x) / Float(viewportWidth)) * (int)2) - (int)1);
	HX_STACK_LINE(374)
	source->y = -(((((Float(source->y) / Float(viewportHeight)) * (int)2) - (int)1)));
	struct _Function_1_2{
		inline static ::com::engine::math::Vector3 Block( ::com::engine::math::Vector3 &source,::com::engine::math::Matrix &matrix){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",375);
			{
				HX_STACK_LINE(375)
				::com::engine::math::Vector3 result = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(375)
				{
					HX_STACK_LINE(375)
					Float x = ((((source->x * matrix->m->__get((int)0)) + (source->y * matrix->m->__get((int)4))) + (source->z * matrix->m->__get((int)8))) + matrix->m->__get((int)12));		HX_STACK_VAR(x,"x");
					HX_STACK_LINE(375)
					Float y = ((((source->x * matrix->m->__get((int)1)) + (source->y * matrix->m->__get((int)5))) + (source->z * matrix->m->__get((int)9))) + matrix->m->__get((int)13));		HX_STACK_VAR(y,"y");
					HX_STACK_LINE(375)
					Float z = ((((source->x * matrix->m->__get((int)2)) + (source->y * matrix->m->__get((int)6))) + (source->z * matrix->m->__get((int)10))) + matrix->m->__get((int)14));		HX_STACK_VAR(z,"z");
					HX_STACK_LINE(375)
					Float w = ((((source->x * matrix->m->__get((int)3)) + (source->y * matrix->m->__get((int)7))) + (source->z * matrix->m->__get((int)11))) + matrix->m->__get((int)15));		HX_STACK_VAR(w,"w");
					HX_STACK_LINE(375)
					result->x = (Float(x) / Float(w));
					HX_STACK_LINE(375)
					result->y = (Float(y) / Float(w));
					HX_STACK_LINE(375)
					result->z = (Float(z) / Float(w));
				}
				HX_STACK_LINE(375)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(375)
	::com::engine::math::Vector3 vector = _Function_1_2::Block(source,matrix);		HX_STACK_VAR(vector,"vector");
	HX_STACK_LINE(376)
	Float num = ((((source->x * matrix->m->__get((int)3)) + (source->y * matrix->m->__get((int)7))) + (source->z * matrix->m->__get((int)11))) + matrix->m->__get((int)15));		HX_STACK_VAR(num,"num");
	struct _Function_1_3{
		inline static bool Block( Float &num){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",378);
			{
				HX_STACK_LINE(378)
				Float num1 = (num - 1.0);		HX_STACK_VAR(num1,"num1");
				HX_STACK_LINE(378)
				return (bool((-1.401298e-045 <= num1)) && bool((num1 <= 1.401298E-45)));
			}
			return null();
		}
	};
	HX_STACK_LINE(378)
	if ((_Function_1_3::Block(num))){
		struct _Function_2_1{
			inline static ::com::engine::math::Vector3 Block( Float &num,::com::engine::math::Vector3 &vector){
				HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",379);
				{
					HX_STACK_LINE(379)
					Float scale = (Float(1.0) / Float(num));		HX_STACK_VAR(scale,"scale");
					HX_STACK_LINE(379)
					return ::com::engine::math::Vector3_obj::__new((vector->x * scale),(vector->y * scale),(vector->z * scale));
				}
				return null();
			}
		};
		HX_STACK_LINE(378)
		vector = _Function_2_1::Block(num,vector);
	}
	HX_STACK_LINE(382)
	return vector;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Vector3_obj,Unproject,return )

::com::engine::math::Vector3 Vector3_obj::Minimize( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right){
	HX_STACK_PUSH("Vector3::Minimize","com/engine/math/Vector3.hx",385);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_LINE(386)
	Float x = (  (((left->x < right->x))) ? Float(left->x) : Float(right->x) );		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(387)
	Float y = (  (((left->y < right->y))) ? Float(left->y) : Float(right->y) );		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(388)
	Float z = (  (((left->z < right->z))) ? Float(left->z) : Float(right->z) );		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(389)
	return ::com::engine::math::Vector3_obj::__new(x,y,z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Minimize,return )

::com::engine::math::Vector3 Vector3_obj::Maximize( ::com::engine::math::Vector3 left,::com::engine::math::Vector3 right){
	HX_STACK_PUSH("Vector3::Maximize","com/engine/math/Vector3.hx",392);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_LINE(393)
	Float x = (  (((left->x > right->x))) ? Float(left->x) : Float(right->x) );		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(394)
	Float y = (  (((left->y > right->y))) ? Float(left->y) : Float(right->y) );		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(395)
	Float z = (  (((left->z > right->z))) ? Float(left->z) : Float(right->z) );		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(396)
	return ::com::engine::math::Vector3_obj::__new(x,y,z);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Maximize,return )

Float Vector3_obj::Distance( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 value2){
	HX_STACK_PUSH("Vector3::Distance","com/engine/math/Vector3.hx",399);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(value2,"value2");
	struct _Function_1_1{
		inline static Float Block( ::com::engine::math::Vector3 &value1,::com::engine::math::Vector3 &value2){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector3.hx",400);
			{
				HX_STACK_LINE(400)
				Float x = (value1->x - value2->x);		HX_STACK_VAR(x,"x");
				HX_STACK_LINE(400)
				Float y = (value1->y - value2->y);		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(400)
				Float z = (value1->z - value2->z);		HX_STACK_VAR(z,"z");
				HX_STACK_LINE(400)
				return (((x * x) + (y * y)) + (z * z));
			}
			return null();
		}
	};
	HX_STACK_LINE(399)
	return ::Math_obj::sqrt(_Function_1_1::Block(value1,value2));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,Distance,return )

Float Vector3_obj::DistanceSquared( ::com::engine::math::Vector3 value1,::com::engine::math::Vector3 value2){
	HX_STACK_PUSH("Vector3::DistanceSquared","com/engine/math/Vector3.hx",403);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(value2,"value2");
	HX_STACK_LINE(404)
	Float x = (value1->x - value2->x);		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(405)
	Float y = (value1->y - value2->y);		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(406)
	Float z = (value1->z - value2->z);		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(408)
	return (((x * x) + (y * y)) + (z * z));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector3_obj,DistanceSquared,return )


Vector3_obj::Vector3_obj()
{
}

void Vector3_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector3);
	HX_MARK_MEMBER_NAME(z,"z");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void Vector3_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(z,"z");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic Vector3_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { return z; }
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 2:
		if (HX_FIELD_EQ(inName,"Up") ) { return Up_dyn(); }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Sub") ) { return Sub_dyn(); }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Dot") ) { return Dot_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"set") ) { return set_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Zero") ) { return Zero_dyn(); }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clamp") ) { return Clamp_dyn(); }
		if (HX_FIELD_EQ(inName,"Cross") ) { return Cross_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length_dyn(); }
		if (HX_FIELD_EQ(inName,"divide") ) { return divide_dyn(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"negate") ) { return negate_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Hermite") ) { return Hermite_dyn(); }
		if (HX_FIELD_EQ(inName,"Project") ) { return Project_dyn(); }
		if (HX_FIELD_EQ(inName,"toArray") ) { return toArray_dyn(); }
		if (HX_FIELD_EQ(inName,"asArray") ) { return asArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Minimize") ) { return Minimize_dyn(); }
		if (HX_FIELD_EQ(inName,"Maximize") ) { return Maximize_dyn(); }
		if (HX_FIELD_EQ(inName,"Distance") ) { return Distance_dyn(); }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"multiply") ) { return multiply_dyn(); }
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		if (HX_FIELD_EQ(inName,"addToRef") ) { return addToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FromArray") ) { return FromArray_dyn(); }
		if (HX_FIELD_EQ(inName,"Normalize") ) { return Normalize_dyn(); }
		if (HX_FIELD_EQ(inName,"Unproject") ) { return Unproject_dyn(); }
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"CatmullRom") ) { return CatmullRom_dyn(); }
		if (HX_FIELD_EQ(inName,"CrossToRef") ) { return CrossToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"scaleToRef") ) { return scaleToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"addInPlace") ) { return addInPlace_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"divideToRef") ) { return divideToRef_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"scaleInPlace") ) { return scaleInPlace_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lengthSquared") ) { return lengthSquared_dyn(); }
		if (HX_FIELD_EQ(inName,"multiplyToRef") ) { return multiplyToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"subtractToRef") ) { return subtractToRef_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"FromArrayToRef") ) { return FromArrayToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"NormalizeToRef") ) { return NormalizeToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"copyFromFloats") ) { return copyFromFloats_dyn(); }
		if (HX_FIELD_EQ(inName,"equalsToFloats") ) { return equalsToFloats_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"FromFloatsToRef") ) { return FromFloatsToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"TransformNormal") ) { return TransformNormal_dyn(); }
		if (HX_FIELD_EQ(inName,"DistanceSquared") ) { return DistanceSquared_dyn(); }
		if (HX_FIELD_EQ(inName,"multiplyInPlace") ) { return multiplyInPlace_dyn(); }
		if (HX_FIELD_EQ(inName,"subtractInPlace") ) { return subtractInPlace_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"multiplyByFloats") ) { return multiplyByFloats_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"subtractFromFloats") ) { return subtractFromFloats_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"TransformCoordinates") ) { return TransformCoordinates_dyn(); }
		if (HX_FIELD_EQ(inName,"TransformNormalToRef") ) { return TransformNormalToRef_dyn(); }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"subtractFromFloatsToRef") ) { return subtractFromFloatsToRef_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"TransformCoordinatesToRef") ) { return TransformCoordinatesToRef_dyn(); }
		break;
	case 30:
		if (HX_FIELD_EQ(inName,"TransformNormalFromFloatsToRef") ) { return TransformNormalFromFloatsToRef_dyn(); }
		break;
	case 35:
		if (HX_FIELD_EQ(inName,"TransformCoordinatesFromFloatsToRef") ) { return TransformCoordinatesFromFloatsToRef_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector3_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"z") ) { z=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector3_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("z"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Sub"),
	HX_CSTRING("Add"),
	HX_CSTRING("FromArray"),
	HX_CSTRING("FromArrayToRef"),
	HX_CSTRING("FromFloatsToRef"),
	HX_CSTRING("Zero"),
	HX_CSTRING("Up"),
	HX_CSTRING("TransformCoordinates"),
	HX_CSTRING("TransformCoordinatesToRef"),
	HX_CSTRING("TransformCoordinatesFromFloatsToRef"),
	HX_CSTRING("TransformNormal"),
	HX_CSTRING("TransformNormalToRef"),
	HX_CSTRING("TransformNormalFromFloatsToRef"),
	HX_CSTRING("CatmullRom"),
	HX_CSTRING("Clamp"),
	HX_CSTRING("Hermite"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("Dot"),
	HX_CSTRING("Cross"),
	HX_CSTRING("CrossToRef"),
	HX_CSTRING("Normalize"),
	HX_CSTRING("NormalizeToRef"),
	HX_CSTRING("Project"),
	HX_CSTRING("Unproject"),
	HX_CSTRING("Minimize"),
	HX_CSTRING("Maximize"),
	HX_CSTRING("Distance"),
	HX_CSTRING("DistanceSquared"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("copyFromFloats"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("clone"),
	HX_CSTRING("normalize"),
	HX_CSTRING("lengthSquared"),
	HX_CSTRING("length"),
	HX_CSTRING("divideToRef"),
	HX_CSTRING("divide"),
	HX_CSTRING("multiplyByFloats"),
	HX_CSTRING("multiplyToRef"),
	HX_CSTRING("multiply"),
	HX_CSTRING("multiplyInPlace"),
	HX_CSTRING("equalsToFloats"),
	HX_CSTRING("equals"),
	HX_CSTRING("scaleToRef"),
	HX_CSTRING("scale"),
	HX_CSTRING("scaleInPlace"),
	HX_CSTRING("negate"),
	HX_CSTRING("subtractFromFloatsToRef"),
	HX_CSTRING("subtractFromFloats"),
	HX_CSTRING("subtractToRef"),
	HX_CSTRING("subtract"),
	HX_CSTRING("subtractInPlace"),
	HX_CSTRING("addToRef"),
	HX_CSTRING("add"),
	HX_CSTRING("addInPlace"),
	HX_CSTRING("toArray"),
	HX_CSTRING("asArray"),
	HX_CSTRING("toString"),
	HX_CSTRING("set"),
	HX_CSTRING("z"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector3_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector3_obj::__mClass,"__mClass");
};

Class Vector3_obj::__mClass;

void Vector3_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.math.Vector3"), hx::TCanCast< Vector3_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Vector3_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace math
