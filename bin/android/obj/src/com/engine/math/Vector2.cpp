#include <hxcpp.h>

#ifndef INCLUDED_com_engine_math_Matrix
#include <com/engine/math/Matrix.h>
#endif
#ifndef INCLUDED_com_engine_math_Vector2
#include <com/engine/math/Vector2.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace engine{
namespace math{

Void Vector2_obj::__construct(Float x,Float y)
{
HX_STACK_PUSH("Vector2::new","com/engine/math/Vector2.hx",20);
{
	HX_STACK_LINE(21)
	this->x = x;
	HX_STACK_LINE(22)
	this->y = y;
}
;
	return null();
}

Vector2_obj::~Vector2_obj() { }

Dynamic Vector2_obj::__CreateEmpty() { return  new Vector2_obj; }
hx::ObjectPtr< Vector2_obj > Vector2_obj::__new(Float x,Float y)
{  hx::ObjectPtr< Vector2_obj > result = new Vector2_obj();
	result->__construct(x,y);
	return result;}

Dynamic Vector2_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Vector2_obj > result = new Vector2_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

::com::engine::math::Vector2 Vector2_obj::clone( ){
	HX_STACK_PUSH("Vector2::clone","com/engine/math/Vector2.hx",85);
	HX_STACK_THIS(this);
	HX_STACK_LINE(85)
	return ::com::engine::math::Vector2_obj::__new(this->x,this->y);
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,clone,return )

Void Vector2_obj::normalize( ){
{
		HX_STACK_PUSH("Vector2::normalize","com/engine/math/Vector2.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_LINE(75)
		Float len = ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(77)
		if (((len != (int)0))){
			HX_STACK_LINE(78)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(80)
			hx::MultEq(this->x,num);
			HX_STACK_LINE(81)
			hx::MultEq(this->y,num);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,normalize,(void))

Float Vector2_obj::lengthSquared( ){
	HX_STACK_PUSH("Vector2::lengthSquared","com/engine/math/Vector2.hx",70);
	HX_STACK_THIS(this);
	HX_STACK_LINE(70)
	return ((this->x * this->x) + (this->y * this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,lengthSquared,return )

Float Vector2_obj::length( ){
	HX_STACK_PUSH("Vector2::length","com/engine/math/Vector2.hx",66);
	HX_STACK_THIS(this);
	HX_STACK_LINE(66)
	return ::Math_obj::sqrt(((this->x * this->x) + (this->y * this->y)));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,length,return )

bool Vector2_obj::equals( ::com::engine::math::Vector2 otherVector){
	HX_STACK_PUSH("Vector2::equals","com/engine/math/Vector2.hx",62);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(62)
	return (bool((this->x == otherVector->x)) && bool((this->y == otherVector->y)));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,equals,return )

::com::engine::math::Vector2 Vector2_obj::scale( Float scale){
	HX_STACK_PUSH("Vector2::scale","com/engine/math/Vector2.hx",58);
	HX_STACK_THIS(this);
	HX_STACK_ARG(scale,"scale");
	HX_STACK_LINE(58)
	return ::com::engine::math::Vector2_obj::__new((this->x * scale),(this->y * scale));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,scale,return )

Void Vector2_obj::scaleInPlace( Float scale){
{
		HX_STACK_PUSH("Vector2::scaleInPlace","com/engine/math/Vector2.hx",53);
		HX_STACK_THIS(this);
		HX_STACK_ARG(scale,"scale");
		HX_STACK_LINE(54)
		hx::MultEq(this->x,scale);
		HX_STACK_LINE(55)
		hx::MultEq(this->y,scale);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,scaleInPlace,(void))

::com::engine::math::Vector2 Vector2_obj::negate( ){
	HX_STACK_PUSH("Vector2::negate","com/engine/math/Vector2.hx",49);
	HX_STACK_THIS(this);
	HX_STACK_LINE(49)
	return ::com::engine::math::Vector2_obj::__new(-(this->x),-(this->y));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,negate,return )

::com::engine::math::Vector2 Vector2_obj::subtract( ::com::engine::math::Vector2 otherVector){
	HX_STACK_PUSH("Vector2::subtract","com/engine/math/Vector2.hx",45);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(45)
	return ::com::engine::math::Vector2_obj::__new((this->x - otherVector->x),(this->y - otherVector->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,subtract,return )

Void Vector2_obj::toArray( Array< Float > array,hx::Null< int >  __o_index){
int index = __o_index.Default(0);
	HX_STACK_PUSH("Vector2::toArray","com/engine/math/Vector2.hx",40);
	HX_STACK_THIS(this);
	HX_STACK_ARG(array,"array");
	HX_STACK_ARG(index,"index");
{
		HX_STACK_LINE(41)
		array[index] = this->x;
		HX_STACK_LINE(42)
		array[(index + (int)1)] = this->y;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,toArray,(void))

Array< Float > Vector2_obj::asArray( ){
	HX_STACK_PUSH("Vector2::asArray","com/engine/math/Vector2.hx",34);
	HX_STACK_THIS(this);
	HX_STACK_LINE(35)
	Array< Float > result = Array_obj< Float >::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(36)
	{
		HX_STACK_LINE(36)
		result[(int)0] = this->x;
		HX_STACK_LINE(36)
		result[(int)1] = this->y;
	}
	HX_STACK_LINE(37)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,asArray,return )

::com::engine::math::Vector2 Vector2_obj::add( ::com::engine::math::Vector2 otherVector){
	HX_STACK_PUSH("Vector2::add","com/engine/math/Vector2.hx",30);
	HX_STACK_THIS(this);
	HX_STACK_ARG(otherVector,"otherVector");
	HX_STACK_LINE(30)
	return ::com::engine::math::Vector2_obj::__new((this->x + otherVector->x),(this->y + otherVector->y));
}


HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,add,return )

::String Vector2_obj::toString( ){
	HX_STACK_PUSH("Vector2::toString","com/engine/math/Vector2.hx",25);
	HX_STACK_THIS(this);
	HX_STACK_LINE(25)
	return ((((HX_CSTRING("{X: ") + this->x) + HX_CSTRING(" Y:")) + this->y) + HX_CSTRING("}"));
}


HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,toString,return )

::com::engine::math::Vector2 Vector2_obj::Sub( ::com::engine::math::Vector2 a,::com::engine::math::Vector2 b){
	HX_STACK_PUSH("Vector2::Sub","com/engine/math/Vector2.hx",12);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(12)
	return ::com::engine::math::Vector2_obj::__new((a->x - b->x),(a->y - b->y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Sub,return )

::com::engine::math::Vector2 Vector2_obj::Add( ::com::engine::math::Vector2 a,::com::engine::math::Vector2 b){
	HX_STACK_PUSH("Vector2::Add","com/engine/math/Vector2.hx",16);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(16)
	return ::com::engine::math::Vector2_obj::__new((a->x + b->x),(a->y + b->y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Add,return )

::com::engine::math::Vector2 Vector2_obj::Zero( ){
	HX_STACK_PUSH("Vector2::Zero","com/engine/math/Vector2.hx",91);
	HX_STACK_LINE(91)
	return ::com::engine::math::Vector2_obj::__new((int)0,(int)0);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Vector2_obj,Zero,return )

::com::engine::math::Vector2 Vector2_obj::CatmullRom( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 value2,::com::engine::math::Vector2 value3,::com::engine::math::Vector2 value4,Float amount){
	HX_STACK_PUSH("Vector2::CatmullRom","com/engine/math/Vector2.hx",95);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(value2,"value2");
	HX_STACK_ARG(value3,"value3");
	HX_STACK_ARG(value4,"value4");
	HX_STACK_ARG(amount,"amount");
	HX_STACK_LINE(96)
	Float squared = (amount * amount);		HX_STACK_VAR(squared,"squared");
	HX_STACK_LINE(97)
	Float cubed = (amount * squared);		HX_STACK_VAR(cubed,"cubed");
	HX_STACK_LINE(99)
	Float x = (0.5 * (((((2.0 * value2->x) + (((-(value1->x) + value3->x)) * amount)) + ((((((2.0 * value1->x) - (5.0 * value2->x)) + (4.0 * value3->x)) - value4->x)) * squared)) + (((((-(value1->x) + (3.0 * value2->x)) - (3.0 * value3->x)) + value4->x)) * cubed))));		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(103)
	Float y = (0.5 * (((((2.0 * value2->y) + (((-(value1->y) + value3->y)) * amount)) + ((((((2.0 * value1->y) - (5.0 * value2->y)) + (4.0 * value3->y)) - value4->y)) * squared)) + (((((-(value1->y) + (3.0 * value2->y)) - (3.0 * value3->y)) + value4->y)) * cubed))));		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(107)
	return ::com::engine::math::Vector2_obj::__new(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Vector2_obj,CatmullRom,return )

::com::engine::math::Vector2 Vector2_obj::Clamp( ::com::engine::math::Vector2 value,::com::engine::math::Vector2 min,::com::engine::math::Vector2 max){
	HX_STACK_PUSH("Vector2::Clamp","com/engine/math/Vector2.hx",110);
	HX_STACK_ARG(value,"value");
	HX_STACK_ARG(min,"min");
	HX_STACK_ARG(max,"max");
	HX_STACK_LINE(111)
	Float x = value->x;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(112)
	x = (  (((x > max->x))) ? Float(max->x) : Float(x) );
	HX_STACK_LINE(113)
	x = (  (((x < min->x))) ? Float(min->x) : Float(x) );
	HX_STACK_LINE(115)
	Float y = value->y;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(116)
	y = (  (((y > max->y))) ? Float(max->y) : Float(y) );
	HX_STACK_LINE(117)
	y = (  (((y < min->y))) ? Float(min->y) : Float(y) );
	HX_STACK_LINE(119)
	return ::com::engine::math::Vector2_obj::__new(x,y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector2_obj,Clamp,return )

::com::engine::math::Vector2 Vector2_obj::Hermite( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 tangent1,::com::engine::math::Vector2 value2,::com::engine::math::Vector2 tangent2,Float amount){
	HX_STACK_PUSH("Vector2::Hermite","com/engine/math/Vector2.hx",122);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(tangent1,"tangent1");
	HX_STACK_ARG(value2,"value2");
	HX_STACK_ARG(tangent2,"tangent2");
	HX_STACK_ARG(amount,"amount");
	HX_STACK_LINE(123)
	Float squared = (amount * amount);		HX_STACK_VAR(squared,"squared");
	HX_STACK_LINE(124)
	Float cubed = (amount * squared);		HX_STACK_VAR(cubed,"cubed");
	HX_STACK_LINE(125)
	Float part1 = (((2.0 * cubed) - (3.0 * squared)) + 1.0);		HX_STACK_VAR(part1,"part1");
	HX_STACK_LINE(126)
	Float part2 = ((-2. * cubed) + (3.0 * squared));		HX_STACK_VAR(part2,"part2");
	HX_STACK_LINE(127)
	Float part3 = ((cubed - (2.0 * squared)) + amount);		HX_STACK_VAR(part3,"part3");
	HX_STACK_LINE(128)
	Float part4 = (cubed - squared);		HX_STACK_VAR(part4,"part4");
	HX_STACK_LINE(130)
	Float _x = ((((value1->x * part1) + (value2->x * part2)) + (tangent1->x * part3)) + (tangent2->x * part4));		HX_STACK_VAR(_x,"_x");
	HX_STACK_LINE(131)
	Float _y = ((((value1->y * part1) + (value2->y * part2)) + (tangent1->y * part3)) + (tangent2->y * part4));		HX_STACK_VAR(_y,"_y");
	HX_STACK_LINE(133)
	return ::com::engine::math::Vector2_obj::__new(_x,_y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Vector2_obj,Hermite,return )

::com::engine::math::Vector2 Vector2_obj::Lerp( ::com::engine::math::Vector2 start,::com::engine::math::Vector2 end,Float amount){
	HX_STACK_PUSH("Vector2::Lerp","com/engine/math/Vector2.hx",136);
	HX_STACK_ARG(start,"start");
	HX_STACK_ARG(end,"end");
	HX_STACK_ARG(amount,"amount");
	HX_STACK_LINE(137)
	Float _x = (start->x + (((end->x - start->x)) * amount));		HX_STACK_VAR(_x,"_x");
	HX_STACK_LINE(138)
	Float _y = (start->y + (((end->y - start->y)) * amount));		HX_STACK_VAR(_y,"_y");
	HX_STACK_LINE(140)
	return ::com::engine::math::Vector2_obj::__new(_x,_y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Vector2_obj,Lerp,return )

Float Vector2_obj::Dot( ::com::engine::math::Vector2 left,::com::engine::math::Vector2 right){
	HX_STACK_PUSH("Vector2::Dot","com/engine/math/Vector2.hx",143);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_LINE(143)
	return ((left->x * right->x) + (left->y * right->y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Dot,return )

::com::engine::math::Vector2 Vector2_obj::Normalize( ::com::engine::math::Vector2 vector){
	HX_STACK_PUSH("Vector2::Normalize","com/engine/math/Vector2.hx",147);
	HX_STACK_ARG(vector,"vector");
	HX_STACK_LINE(148)
	::com::engine::math::Vector2 newVector = ::com::engine::math::Vector2_obj::__new(vector->x,vector->y);		HX_STACK_VAR(newVector,"newVector");
	HX_STACK_LINE(149)
	{
		HX_STACK_LINE(149)
		Float len = ::Math_obj::sqrt(((newVector->x * newVector->x) + (newVector->y * newVector->y)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(149)
		if (((len != (int)0))){
			HX_STACK_LINE(149)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(149)
			hx::MultEq(newVector->x,num);
			HX_STACK_LINE(149)
			hx::MultEq(newVector->y,num);
		}
	}
	HX_STACK_LINE(150)
	return newVector;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Vector2_obj,Normalize,return )

::com::engine::math::Vector2 Vector2_obj::Minimize( ::com::engine::math::Vector2 left,::com::engine::math::Vector2 right){
	HX_STACK_PUSH("Vector2::Minimize","com/engine/math/Vector2.hx",153);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_LINE(154)
	Float _x = (  (((left->x < right->x))) ? Float(left->x) : Float(right->x) );		HX_STACK_VAR(_x,"_x");
	HX_STACK_LINE(155)
	Float _y = (  (((left->y < right->y))) ? Float(left->y) : Float(right->y) );		HX_STACK_VAR(_y,"_y");
	HX_STACK_LINE(157)
	return ::com::engine::math::Vector2_obj::__new(_x,_y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Minimize,return )

::com::engine::math::Vector2 Vector2_obj::Maximize( ::com::engine::math::Vector2 left,::com::engine::math::Vector2 right){
	HX_STACK_PUSH("Vector2::Maximize","com/engine/math/Vector2.hx",160);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_LINE(161)
	Float _x = (  (((left->x > right->x))) ? Float(left->x) : Float(right->x) );		HX_STACK_VAR(_x,"_x");
	HX_STACK_LINE(162)
	Float _y = (  (((left->y > right->y))) ? Float(left->y) : Float(right->y) );		HX_STACK_VAR(_y,"_y");
	HX_STACK_LINE(164)
	return ::com::engine::math::Vector2_obj::__new(_x,_y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Maximize,return )

::com::engine::math::Vector2 Vector2_obj::Transform( ::com::engine::math::Vector2 vector,::com::engine::math::Matrix transformation){
	HX_STACK_PUSH("Vector2::Transform","com/engine/math/Vector2.hx",167);
	HX_STACK_ARG(vector,"vector");
	HX_STACK_ARG(transformation,"transformation");
	HX_STACK_LINE(168)
	Float _x = ((vector->x * transformation->m->__get((int)0)) + (vector->y * transformation->m->__get((int)4)));		HX_STACK_VAR(_x,"_x");
	HX_STACK_LINE(169)
	Float _y = ((vector->x * transformation->m->__get((int)1)) + (vector->y * transformation->m->__get((int)5)));		HX_STACK_VAR(_y,"_y");
	HX_STACK_LINE(171)
	return ::com::engine::math::Vector2_obj::__new(_x,_y);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Transform,return )

Float Vector2_obj::Distance( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 value2){
	HX_STACK_PUSH("Vector2::Distance","com/engine/math/Vector2.hx",174);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(value2,"value2");
	struct _Function_1_1{
		inline static Float Block( ::com::engine::math::Vector2 &value1,::com::engine::math::Vector2 &value2){
			HX_STACK_PUSH("*::closure","com/engine/math/Vector2.hx",175);
			{
				HX_STACK_LINE(175)
				Float _x = (value1->x - value2->x);		HX_STACK_VAR(_x,"_x");
				HX_STACK_LINE(175)
				Float _y = (value1->y - value2->y);		HX_STACK_VAR(_y,"_y");
				HX_STACK_LINE(175)
				return ((_x * _x) + (_y * _y));
			}
			return null();
		}
	};
	HX_STACK_LINE(174)
	return ::Math_obj::sqrt(_Function_1_1::Block(value1,value2));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,Distance,return )

Float Vector2_obj::DistanceSquared( ::com::engine::math::Vector2 value1,::com::engine::math::Vector2 value2){
	HX_STACK_PUSH("Vector2::DistanceSquared","com/engine/math/Vector2.hx",178);
	HX_STACK_ARG(value1,"value1");
	HX_STACK_ARG(value2,"value2");
	HX_STACK_LINE(179)
	Float _x = (value1->x - value2->x);		HX_STACK_VAR(_x,"_x");
	HX_STACK_LINE(180)
	Float _y = (value1->y - value2->y);		HX_STACK_VAR(_y,"_y");
	HX_STACK_LINE(182)
	return ((_x * _x) + (_y * _y));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Vector2_obj,DistanceSquared,return )


Vector2_obj::Vector2_obj()
{
}

void Vector2_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Vector2);
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void Vector2_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic Vector2_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Sub") ) { return Sub_dyn(); }
		if (HX_FIELD_EQ(inName,"Add") ) { return Add_dyn(); }
		if (HX_FIELD_EQ(inName,"Dot") ) { return Dot_dyn(); }
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Zero") ) { return Zero_dyn(); }
		if (HX_FIELD_EQ(inName,"Lerp") ) { return Lerp_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"Clamp") ) { return Clamp_dyn(); }
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		if (HX_FIELD_EQ(inName,"scale") ) { return scale_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { return length_dyn(); }
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"negate") ) { return negate_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Hermite") ) { return Hermite_dyn(); }
		if (HX_FIELD_EQ(inName,"toArray") ) { return toArray_dyn(); }
		if (HX_FIELD_EQ(inName,"asArray") ) { return asArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Minimize") ) { return Minimize_dyn(); }
		if (HX_FIELD_EQ(inName,"Maximize") ) { return Maximize_dyn(); }
		if (HX_FIELD_EQ(inName,"Distance") ) { return Distance_dyn(); }
		if (HX_FIELD_EQ(inName,"subtract") ) { return subtract_dyn(); }
		if (HX_FIELD_EQ(inName,"toString") ) { return toString_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"Normalize") ) { return Normalize_dyn(); }
		if (HX_FIELD_EQ(inName,"Transform") ) { return Transform_dyn(); }
		if (HX_FIELD_EQ(inName,"normalize") ) { return normalize_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"CatmullRom") ) { return CatmullRom_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"scaleInPlace") ) { return scaleInPlace_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"lengthSquared") ) { return lengthSquared_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"DistanceSquared") ) { return DistanceSquared_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Vector2_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Vector2_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("Sub"),
	HX_CSTRING("Add"),
	HX_CSTRING("Zero"),
	HX_CSTRING("CatmullRom"),
	HX_CSTRING("Clamp"),
	HX_CSTRING("Hermite"),
	HX_CSTRING("Lerp"),
	HX_CSTRING("Dot"),
	HX_CSTRING("Normalize"),
	HX_CSTRING("Minimize"),
	HX_CSTRING("Maximize"),
	HX_CSTRING("Transform"),
	HX_CSTRING("Distance"),
	HX_CSTRING("DistanceSquared"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("normalize"),
	HX_CSTRING("lengthSquared"),
	HX_CSTRING("length"),
	HX_CSTRING("equals"),
	HX_CSTRING("scale"),
	HX_CSTRING("scaleInPlace"),
	HX_CSTRING("negate"),
	HX_CSTRING("subtract"),
	HX_CSTRING("toArray"),
	HX_CSTRING("asArray"),
	HX_CSTRING("add"),
	HX_CSTRING("toString"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Vector2_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Vector2_obj::__mClass,"__mClass");
};

Class Vector2_obj::__mClass;

void Vector2_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.math.Vector2"), hx::TCanCast< Vector2_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Vector2_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace math
