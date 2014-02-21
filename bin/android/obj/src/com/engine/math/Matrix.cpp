#include <hxcpp.h>

#ifndef INCLUDED_com_engine_math_Matrix
#include <com/engine/math/Matrix.h>
#endif
#ifndef INCLUDED_com_engine_math_Plane
#include <com/engine/math/Plane.h>
#endif
#ifndef INCLUDED_com_engine_math_Quaternion
#include <com/engine/math/Quaternion.h>
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

Void Matrix_obj::__construct()
{
HX_STACK_PUSH("Matrix::new","com/engine/math/Matrix.hx",11);
{
	HX_STACK_LINE(11)
	this->m = Array_obj< Float >::__new();
}
;
	return null();
}

Matrix_obj::~Matrix_obj() { }

Dynamic Matrix_obj::__CreateEmpty() { return  new Matrix_obj; }
hx::ObjectPtr< Matrix_obj > Matrix_obj::__new()
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct();
	return result;}

Dynamic Matrix_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Matrix_obj > result = new Matrix_obj();
	result->__construct();
	return result;}

::com::engine::math::Matrix Matrix_obj::clone( ){
	HX_STACK_PUSH("Matrix::clone","com/engine/math/Matrix.hx",226);
	HX_STACK_THIS(this);
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ::com::engine::math::Matrix_obj *__this){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",227);
			{
				HX_STACK_LINE(227)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(227)
				result->m[(int)0] = __this->m->__get((int)0);
				HX_STACK_LINE(227)
				result->m[(int)1] = __this->m->__get((int)1);
				HX_STACK_LINE(227)
				result->m[(int)2] = __this->m->__get((int)2);
				HX_STACK_LINE(227)
				result->m[(int)3] = __this->m->__get((int)3);
				HX_STACK_LINE(227)
				result->m[(int)4] = __this->m->__get((int)4);
				HX_STACK_LINE(227)
				result->m[(int)5] = __this->m->__get((int)5);
				HX_STACK_LINE(227)
				result->m[(int)6] = __this->m->__get((int)6);
				HX_STACK_LINE(227)
				result->m[(int)7] = __this->m->__get((int)7);
				HX_STACK_LINE(227)
				result->m[(int)8] = __this->m->__get((int)8);
				HX_STACK_LINE(227)
				result->m[(int)9] = __this->m->__get((int)9);
				HX_STACK_LINE(227)
				result->m[(int)10] = __this->m->__get((int)10);
				HX_STACK_LINE(227)
				result->m[(int)11] = __this->m->__get((int)11);
				HX_STACK_LINE(227)
				result->m[(int)12] = __this->m->__get((int)12);
				HX_STACK_LINE(227)
				result->m[(int)13] = __this->m->__get((int)13);
				HX_STACK_LINE(227)
				result->m[(int)14] = __this->m->__get((int)14);
				HX_STACK_LINE(227)
				result->m[(int)15] = __this->m->__get((int)15);
				HX_STACK_LINE(227)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(226)
	return _Function_1_1::Block(this);
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,clone,return )

bool Matrix_obj::equals( ::com::engine::math::Matrix value){
	HX_STACK_PUSH("Matrix::equals","com/engine/math/Matrix.hx",219);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(219)
	return (bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((this->m->__get((int)0) == value->m->__get((int)0))) && bool((this->m->__get((int)1) == value->m->__get((int)1))))) && bool((this->m->__get((int)2) == value->m->__get((int)2))))) && bool((this->m->__get((int)3) == value->m->__get((int)3))))) && bool((this->m->__get((int)4) == value->m->__get((int)4))))) && bool((this->m->__get((int)5) == value->m->__get((int)5))))) && bool((this->m->__get((int)6) == value->m->__get((int)6))))) && bool((this->m->__get((int)7) == value->m->__get((int)7))))) && bool((this->m->__get((int)8) == value->m->__get((int)8))))) && bool((this->m->__get((int)9) == value->m->__get((int)9))))) && bool((this->m->__get((int)10) == value->m->__get((int)10))))) && bool((this->m->__get((int)11) == value->m->__get((int)11))))) && bool((this->m->__get((int)12) == value->m->__get((int)12))))) && bool((this->m->__get((int)13) == value->m->__get((int)13))))) && bool((this->m->__get((int)14) == value->m->__get((int)14))))) && bool((this->m->__get((int)15) == value->m->__get((int)15))));
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,equals,return )

Array< Float > Matrix_obj::multiplyToArray( ::com::engine::math::Matrix other,Array< Float > result,int offset){
	HX_STACK_PUSH("Matrix::multiplyToArray","com/engine/math/Matrix.hx",160);
	HX_STACK_THIS(this);
	HX_STACK_ARG(other,"other");
	HX_STACK_ARG(result,"result");
	HX_STACK_ARG(offset,"offset");
	HX_STACK_LINE(162)
	Float tm0 = this->m->__get((int)0);		HX_STACK_VAR(tm0,"tm0");
	HX_STACK_LINE(163)
	Float tm1 = this->m->__get((int)1);		HX_STACK_VAR(tm1,"tm1");
	HX_STACK_LINE(164)
	Float tm2 = this->m->__get((int)2);		HX_STACK_VAR(tm2,"tm2");
	HX_STACK_LINE(165)
	Float tm3 = this->m->__get((int)3);		HX_STACK_VAR(tm3,"tm3");
	HX_STACK_LINE(166)
	Float tm4 = this->m->__get((int)4);		HX_STACK_VAR(tm4,"tm4");
	HX_STACK_LINE(167)
	Float tm5 = this->m->__get((int)5);		HX_STACK_VAR(tm5,"tm5");
	HX_STACK_LINE(168)
	Float tm6 = this->m->__get((int)6);		HX_STACK_VAR(tm6,"tm6");
	HX_STACK_LINE(169)
	Float tm7 = this->m->__get((int)7);		HX_STACK_VAR(tm7,"tm7");
	HX_STACK_LINE(170)
	Float tm8 = this->m->__get((int)8);		HX_STACK_VAR(tm8,"tm8");
	HX_STACK_LINE(171)
	Float tm9 = this->m->__get((int)9);		HX_STACK_VAR(tm9,"tm9");
	HX_STACK_LINE(172)
	Float tm10 = this->m->__get((int)10);		HX_STACK_VAR(tm10,"tm10");
	HX_STACK_LINE(173)
	Float tm11 = this->m->__get((int)11);		HX_STACK_VAR(tm11,"tm11");
	HX_STACK_LINE(174)
	Float tm12 = this->m->__get((int)12);		HX_STACK_VAR(tm12,"tm12");
	HX_STACK_LINE(175)
	Float tm13 = this->m->__get((int)13);		HX_STACK_VAR(tm13,"tm13");
	HX_STACK_LINE(176)
	Float tm14 = this->m->__get((int)14);		HX_STACK_VAR(tm14,"tm14");
	HX_STACK_LINE(177)
	Float tm15 = this->m->__get((int)15);		HX_STACK_VAR(tm15,"tm15");
	HX_STACK_LINE(179)
	Float om0 = other->m->__get((int)0);		HX_STACK_VAR(om0,"om0");
	HX_STACK_LINE(180)
	Float om1 = other->m->__get((int)1);		HX_STACK_VAR(om1,"om1");
	HX_STACK_LINE(181)
	Float om2 = other->m->__get((int)2);		HX_STACK_VAR(om2,"om2");
	HX_STACK_LINE(182)
	Float om3 = other->m->__get((int)3);		HX_STACK_VAR(om3,"om3");
	HX_STACK_LINE(183)
	Float om4 = other->m->__get((int)4);		HX_STACK_VAR(om4,"om4");
	HX_STACK_LINE(184)
	Float om5 = other->m->__get((int)5);		HX_STACK_VAR(om5,"om5");
	HX_STACK_LINE(185)
	Float om6 = other->m->__get((int)6);		HX_STACK_VAR(om6,"om6");
	HX_STACK_LINE(186)
	Float om7 = other->m->__get((int)7);		HX_STACK_VAR(om7,"om7");
	HX_STACK_LINE(187)
	Float om8 = other->m->__get((int)8);		HX_STACK_VAR(om8,"om8");
	HX_STACK_LINE(188)
	Float om9 = other->m->__get((int)9);		HX_STACK_VAR(om9,"om9");
	HX_STACK_LINE(189)
	Float om10 = other->m->__get((int)10);		HX_STACK_VAR(om10,"om10");
	HX_STACK_LINE(190)
	Float om11 = other->m->__get((int)11);		HX_STACK_VAR(om11,"om11");
	HX_STACK_LINE(191)
	Float om12 = other->m->__get((int)12);		HX_STACK_VAR(om12,"om12");
	HX_STACK_LINE(192)
	Float om13 = other->m->__get((int)13);		HX_STACK_VAR(om13,"om13");
	HX_STACK_LINE(193)
	Float om14 = other->m->__get((int)14);		HX_STACK_VAR(om14,"om14");
	HX_STACK_LINE(194)
	Float om15 = other->m->__get((int)15);		HX_STACK_VAR(om15,"om15");
	HX_STACK_LINE(196)
	result[offset] = ((((tm0 * om0) + (tm1 * om4)) + (tm2 * om8)) + (tm3 * om12));
	HX_STACK_LINE(197)
	result[(offset + (int)1)] = ((((tm0 * om1) + (tm1 * om5)) + (tm2 * om9)) + (tm3 * om13));
	HX_STACK_LINE(198)
	result[(offset + (int)2)] = ((((tm0 * om2) + (tm1 * om6)) + (tm2 * om10)) + (tm3 * om14));
	HX_STACK_LINE(199)
	result[(offset + (int)3)] = ((((tm0 * om3) + (tm1 * om7)) + (tm2 * om11)) + (tm3 * om15));
	HX_STACK_LINE(201)
	result[(offset + (int)4)] = ((((tm4 * om0) + (tm5 * om4)) + (tm6 * om8)) + (tm7 * om12));
	HX_STACK_LINE(202)
	result[(offset + (int)5)] = ((((tm4 * om1) + (tm5 * om5)) + (tm6 * om9)) + (tm7 * om13));
	HX_STACK_LINE(203)
	result[(offset + (int)6)] = ((((tm4 * om2) + (tm5 * om6)) + (tm6 * om10)) + (tm7 * om14));
	HX_STACK_LINE(204)
	result[(offset + (int)7)] = ((((tm4 * om3) + (tm5 * om7)) + (tm6 * om11)) + (tm7 * om15));
	HX_STACK_LINE(206)
	result[(offset + (int)8)] = ((((tm8 * om0) + (tm9 * om4)) + (tm10 * om8)) + (tm11 * om12));
	HX_STACK_LINE(207)
	result[(offset + (int)9)] = ((((tm8 * om1) + (tm9 * om5)) + (tm10 * om9)) + (tm11 * om13));
	HX_STACK_LINE(208)
	result[(offset + (int)10)] = ((((tm8 * om2) + (tm9 * om6)) + (tm10 * om10)) + (tm11 * om14));
	HX_STACK_LINE(209)
	result[(offset + (int)11)] = ((((tm8 * om3) + (tm9 * om7)) + (tm10 * om11)) + (tm11 * om15));
	HX_STACK_LINE(211)
	result[(offset + (int)12)] = ((((tm12 * om0) + (tm13 * om4)) + (tm14 * om8)) + (tm15 * om12));
	HX_STACK_LINE(212)
	result[(offset + (int)13)] = ((((tm12 * om1) + (tm13 * om5)) + (tm14 * om9)) + (tm15 * om13));
	HX_STACK_LINE(213)
	result[(offset + (int)14)] = ((((tm12 * om2) + (tm13 * om6)) + (tm14 * om10)) + (tm15 * om14));
	HX_STACK_LINE(214)
	result[(offset + (int)15)] = ((((tm12 * om3) + (tm13 * om7)) + (tm14 * om11)) + (tm15 * om15));
	HX_STACK_LINE(216)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,multiplyToArray,return )

Void Matrix_obj::multiplyToRef( ::com::engine::math::Matrix other,::com::engine::math::Matrix result){
{
		HX_STACK_PUSH("Matrix::multiplyToRef","com/engine/math/Matrix.hx",128);
		HX_STACK_THIS(this);
		HX_STACK_ARG(other,"other");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(129)
		Array< Float > result1 = result->m;		HX_STACK_VAR(result1,"result1");
		HX_STACK_LINE(129)
		Float tm0 = this->m->__get((int)0);		HX_STACK_VAR(tm0,"tm0");
		HX_STACK_LINE(129)
		Float tm1 = this->m->__get((int)1);		HX_STACK_VAR(tm1,"tm1");
		HX_STACK_LINE(129)
		Float tm2 = this->m->__get((int)2);		HX_STACK_VAR(tm2,"tm2");
		HX_STACK_LINE(129)
		Float tm3 = this->m->__get((int)3);		HX_STACK_VAR(tm3,"tm3");
		HX_STACK_LINE(129)
		Float tm4 = this->m->__get((int)4);		HX_STACK_VAR(tm4,"tm4");
		HX_STACK_LINE(129)
		Float tm5 = this->m->__get((int)5);		HX_STACK_VAR(tm5,"tm5");
		HX_STACK_LINE(129)
		Float tm6 = this->m->__get((int)6);		HX_STACK_VAR(tm6,"tm6");
		HX_STACK_LINE(129)
		Float tm7 = this->m->__get((int)7);		HX_STACK_VAR(tm7,"tm7");
		HX_STACK_LINE(129)
		Float tm8 = this->m->__get((int)8);		HX_STACK_VAR(tm8,"tm8");
		HX_STACK_LINE(129)
		Float tm9 = this->m->__get((int)9);		HX_STACK_VAR(tm9,"tm9");
		HX_STACK_LINE(129)
		Float tm10 = this->m->__get((int)10);		HX_STACK_VAR(tm10,"tm10");
		HX_STACK_LINE(129)
		Float tm11 = this->m->__get((int)11);		HX_STACK_VAR(tm11,"tm11");
		HX_STACK_LINE(129)
		Float tm12 = this->m->__get((int)12);		HX_STACK_VAR(tm12,"tm12");
		HX_STACK_LINE(129)
		Float tm13 = this->m->__get((int)13);		HX_STACK_VAR(tm13,"tm13");
		HX_STACK_LINE(129)
		Float tm14 = this->m->__get((int)14);		HX_STACK_VAR(tm14,"tm14");
		HX_STACK_LINE(129)
		Float tm15 = this->m->__get((int)15);		HX_STACK_VAR(tm15,"tm15");
		HX_STACK_LINE(129)
		Float om0 = other->m->__get((int)0);		HX_STACK_VAR(om0,"om0");
		HX_STACK_LINE(129)
		Float om1 = other->m->__get((int)1);		HX_STACK_VAR(om1,"om1");
		HX_STACK_LINE(129)
		Float om2 = other->m->__get((int)2);		HX_STACK_VAR(om2,"om2");
		HX_STACK_LINE(129)
		Float om3 = other->m->__get((int)3);		HX_STACK_VAR(om3,"om3");
		HX_STACK_LINE(129)
		Float om4 = other->m->__get((int)4);		HX_STACK_VAR(om4,"om4");
		HX_STACK_LINE(129)
		Float om5 = other->m->__get((int)5);		HX_STACK_VAR(om5,"om5");
		HX_STACK_LINE(129)
		Float om6 = other->m->__get((int)6);		HX_STACK_VAR(om6,"om6");
		HX_STACK_LINE(129)
		Float om7 = other->m->__get((int)7);		HX_STACK_VAR(om7,"om7");
		HX_STACK_LINE(129)
		Float om8 = other->m->__get((int)8);		HX_STACK_VAR(om8,"om8");
		HX_STACK_LINE(129)
		Float om9 = other->m->__get((int)9);		HX_STACK_VAR(om9,"om9");
		HX_STACK_LINE(129)
		Float om10 = other->m->__get((int)10);		HX_STACK_VAR(om10,"om10");
		HX_STACK_LINE(129)
		Float om11 = other->m->__get((int)11);		HX_STACK_VAR(om11,"om11");
		HX_STACK_LINE(129)
		Float om12 = other->m->__get((int)12);		HX_STACK_VAR(om12,"om12");
		HX_STACK_LINE(129)
		Float om13 = other->m->__get((int)13);		HX_STACK_VAR(om13,"om13");
		HX_STACK_LINE(129)
		Float om14 = other->m->__get((int)14);		HX_STACK_VAR(om14,"om14");
		HX_STACK_LINE(129)
		Float om15 = other->m->__get((int)15);		HX_STACK_VAR(om15,"om15");
		HX_STACK_LINE(129)
		result1[(int)0] = ((((tm0 * om0) + (tm1 * om4)) + (tm2 * om8)) + (tm3 * om12));
		HX_STACK_LINE(129)
		result1[(int)1] = ((((tm0 * om1) + (tm1 * om5)) + (tm2 * om9)) + (tm3 * om13));
		HX_STACK_LINE(129)
		result1[(int)2] = ((((tm0 * om2) + (tm1 * om6)) + (tm2 * om10)) + (tm3 * om14));
		HX_STACK_LINE(129)
		result1[(int)3] = ((((tm0 * om3) + (tm1 * om7)) + (tm2 * om11)) + (tm3 * om15));
		HX_STACK_LINE(129)
		result1[(int)4] = ((((tm4 * om0) + (tm5 * om4)) + (tm6 * om8)) + (tm7 * om12));
		HX_STACK_LINE(129)
		result1[(int)5] = ((((tm4 * om1) + (tm5 * om5)) + (tm6 * om9)) + (tm7 * om13));
		HX_STACK_LINE(129)
		result1[(int)6] = ((((tm4 * om2) + (tm5 * om6)) + (tm6 * om10)) + (tm7 * om14));
		HX_STACK_LINE(129)
		result1[(int)7] = ((((tm4 * om3) + (tm5 * om7)) + (tm6 * om11)) + (tm7 * om15));
		HX_STACK_LINE(129)
		result1[(int)8] = ((((tm8 * om0) + (tm9 * om4)) + (tm10 * om8)) + (tm11 * om12));
		HX_STACK_LINE(129)
		result1[(int)9] = ((((tm8 * om1) + (tm9 * om5)) + (tm10 * om9)) + (tm11 * om13));
		HX_STACK_LINE(129)
		result1[(int)10] = ((((tm8 * om2) + (tm9 * om6)) + (tm10 * om10)) + (tm11 * om14));
		HX_STACK_LINE(129)
		result1[(int)11] = ((((tm8 * om3) + (tm9 * om7)) + (tm10 * om11)) + (tm11 * om15));
		HX_STACK_LINE(129)
		result1[(int)12] = ((((tm12 * om0) + (tm13 * om4)) + (tm14 * om8)) + (tm15 * om12));
		HX_STACK_LINE(129)
		result1[(int)13] = ((((tm12 * om1) + (tm13 * om5)) + (tm14 * om9)) + (tm15 * om13));
		HX_STACK_LINE(129)
		result1[(int)14] = ((((tm12 * om2) + (tm13 * om6)) + (tm14 * om10)) + (tm15 * om14));
		HX_STACK_LINE(129)
		result1[(int)15] = ((((tm12 * om3) + (tm13 * om7)) + (tm14 * om11)) + (tm15 * om15));
		HX_STACK_LINE(129)
		result1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,multiplyToRef,(void))

Void Matrix_obj::copyFrom( ::com::engine::math::Matrix other){
{
		HX_STACK_PUSH("Matrix::copyFrom","com/engine/math/Matrix.hx",122);
		HX_STACK_THIS(this);
		HX_STACK_ARG(other,"other");
		HX_STACK_LINE(123)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(123)
		while(((_g < (int)16))){
			HX_STACK_LINE(123)
			int index = (_g)++;		HX_STACK_VAR(index,"index");
			HX_STACK_LINE(124)
			this->m[index] = other->m->__get(index);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,copyFrom,(void))

::com::engine::math::Matrix Matrix_obj::multiply( ::com::engine::math::Matrix other){
	HX_STACK_PUSH("Matrix::multiply","com/engine/math/Matrix.hx",116);
	HX_STACK_THIS(this);
	HX_STACK_ARG(other,"other");
	HX_STACK_LINE(117)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(118)
	{
		HX_STACK_LINE(118)
		Array< Float > result1 = result->m;		HX_STACK_VAR(result1,"result1");
		HX_STACK_LINE(118)
		Float tm0 = this->m->__get((int)0);		HX_STACK_VAR(tm0,"tm0");
		HX_STACK_LINE(118)
		Float tm1 = this->m->__get((int)1);		HX_STACK_VAR(tm1,"tm1");
		HX_STACK_LINE(118)
		Float tm2 = this->m->__get((int)2);		HX_STACK_VAR(tm2,"tm2");
		HX_STACK_LINE(118)
		Float tm3 = this->m->__get((int)3);		HX_STACK_VAR(tm3,"tm3");
		HX_STACK_LINE(118)
		Float tm4 = this->m->__get((int)4);		HX_STACK_VAR(tm4,"tm4");
		HX_STACK_LINE(118)
		Float tm5 = this->m->__get((int)5);		HX_STACK_VAR(tm5,"tm5");
		HX_STACK_LINE(118)
		Float tm6 = this->m->__get((int)6);		HX_STACK_VAR(tm6,"tm6");
		HX_STACK_LINE(118)
		Float tm7 = this->m->__get((int)7);		HX_STACK_VAR(tm7,"tm7");
		HX_STACK_LINE(118)
		Float tm8 = this->m->__get((int)8);		HX_STACK_VAR(tm8,"tm8");
		HX_STACK_LINE(118)
		Float tm9 = this->m->__get((int)9);		HX_STACK_VAR(tm9,"tm9");
		HX_STACK_LINE(118)
		Float tm10 = this->m->__get((int)10);		HX_STACK_VAR(tm10,"tm10");
		HX_STACK_LINE(118)
		Float tm11 = this->m->__get((int)11);		HX_STACK_VAR(tm11,"tm11");
		HX_STACK_LINE(118)
		Float tm12 = this->m->__get((int)12);		HX_STACK_VAR(tm12,"tm12");
		HX_STACK_LINE(118)
		Float tm13 = this->m->__get((int)13);		HX_STACK_VAR(tm13,"tm13");
		HX_STACK_LINE(118)
		Float tm14 = this->m->__get((int)14);		HX_STACK_VAR(tm14,"tm14");
		HX_STACK_LINE(118)
		Float tm15 = this->m->__get((int)15);		HX_STACK_VAR(tm15,"tm15");
		HX_STACK_LINE(118)
		Float om0 = other->m->__get((int)0);		HX_STACK_VAR(om0,"om0");
		HX_STACK_LINE(118)
		Float om1 = other->m->__get((int)1);		HX_STACK_VAR(om1,"om1");
		HX_STACK_LINE(118)
		Float om2 = other->m->__get((int)2);		HX_STACK_VAR(om2,"om2");
		HX_STACK_LINE(118)
		Float om3 = other->m->__get((int)3);		HX_STACK_VAR(om3,"om3");
		HX_STACK_LINE(118)
		Float om4 = other->m->__get((int)4);		HX_STACK_VAR(om4,"om4");
		HX_STACK_LINE(118)
		Float om5 = other->m->__get((int)5);		HX_STACK_VAR(om5,"om5");
		HX_STACK_LINE(118)
		Float om6 = other->m->__get((int)6);		HX_STACK_VAR(om6,"om6");
		HX_STACK_LINE(118)
		Float om7 = other->m->__get((int)7);		HX_STACK_VAR(om7,"om7");
		HX_STACK_LINE(118)
		Float om8 = other->m->__get((int)8);		HX_STACK_VAR(om8,"om8");
		HX_STACK_LINE(118)
		Float om9 = other->m->__get((int)9);		HX_STACK_VAR(om9,"om9");
		HX_STACK_LINE(118)
		Float om10 = other->m->__get((int)10);		HX_STACK_VAR(om10,"om10");
		HX_STACK_LINE(118)
		Float om11 = other->m->__get((int)11);		HX_STACK_VAR(om11,"om11");
		HX_STACK_LINE(118)
		Float om12 = other->m->__get((int)12);		HX_STACK_VAR(om12,"om12");
		HX_STACK_LINE(118)
		Float om13 = other->m->__get((int)13);		HX_STACK_VAR(om13,"om13");
		HX_STACK_LINE(118)
		Float om14 = other->m->__get((int)14);		HX_STACK_VAR(om14,"om14");
		HX_STACK_LINE(118)
		Float om15 = other->m->__get((int)15);		HX_STACK_VAR(om15,"om15");
		HX_STACK_LINE(118)
		result1[(int)0] = ((((tm0 * om0) + (tm1 * om4)) + (tm2 * om8)) + (tm3 * om12));
		HX_STACK_LINE(118)
		result1[(int)1] = ((((tm0 * om1) + (tm1 * om5)) + (tm2 * om9)) + (tm3 * om13));
		HX_STACK_LINE(118)
		result1[(int)2] = ((((tm0 * om2) + (tm1 * om6)) + (tm2 * om10)) + (tm3 * om14));
		HX_STACK_LINE(118)
		result1[(int)3] = ((((tm0 * om3) + (tm1 * om7)) + (tm2 * om11)) + (tm3 * om15));
		HX_STACK_LINE(118)
		result1[(int)4] = ((((tm4 * om0) + (tm5 * om4)) + (tm6 * om8)) + (tm7 * om12));
		HX_STACK_LINE(118)
		result1[(int)5] = ((((tm4 * om1) + (tm5 * om5)) + (tm6 * om9)) + (tm7 * om13));
		HX_STACK_LINE(118)
		result1[(int)6] = ((((tm4 * om2) + (tm5 * om6)) + (tm6 * om10)) + (tm7 * om14));
		HX_STACK_LINE(118)
		result1[(int)7] = ((((tm4 * om3) + (tm5 * om7)) + (tm6 * om11)) + (tm7 * om15));
		HX_STACK_LINE(118)
		result1[(int)8] = ((((tm8 * om0) + (tm9 * om4)) + (tm10 * om8)) + (tm11 * om12));
		HX_STACK_LINE(118)
		result1[(int)9] = ((((tm8 * om1) + (tm9 * om5)) + (tm10 * om9)) + (tm11 * om13));
		HX_STACK_LINE(118)
		result1[(int)10] = ((((tm8 * om2) + (tm9 * om6)) + (tm10 * om10)) + (tm11 * om14));
		HX_STACK_LINE(118)
		result1[(int)11] = ((((tm8 * om3) + (tm9 * om7)) + (tm10 * om11)) + (tm11 * om15));
		HX_STACK_LINE(118)
		result1[(int)12] = ((((tm12 * om0) + (tm13 * om4)) + (tm14 * om8)) + (tm15 * om12));
		HX_STACK_LINE(118)
		result1[(int)13] = ((((tm12 * om1) + (tm13 * om5)) + (tm14 * om9)) + (tm15 * om13));
		HX_STACK_LINE(118)
		result1[(int)14] = ((((tm12 * om2) + (tm13 * om6)) + (tm14 * om10)) + (tm15 * om14));
		HX_STACK_LINE(118)
		result1[(int)15] = ((((tm12 * om3) + (tm13 * om7)) + (tm14 * om11)) + (tm15 * om15));
		HX_STACK_LINE(118)
		result1;
	}
	HX_STACK_LINE(119)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,multiply,return )

Void Matrix_obj::setTranslation( ::com::engine::math::Vector3 vector3){
{
		HX_STACK_PUSH("Matrix::setTranslation","com/engine/math/Matrix.hx",110);
		HX_STACK_THIS(this);
		HX_STACK_ARG(vector3,"vector3");
		HX_STACK_LINE(111)
		this->m[(int)12] = vector3->x;
		HX_STACK_LINE(112)
		this->m[(int)13] = vector3->y;
		HX_STACK_LINE(113)
		this->m[(int)14] = vector3->z;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,setTranslation,(void))

Void Matrix_obj::invertToRef( ::com::engine::math::Matrix other){
{
		HX_STACK_PUSH("Matrix::invertToRef","com/engine/math/Matrix.hx",51);
		HX_STACK_THIS(this);
		HX_STACK_ARG(other,"other");
		HX_STACK_LINE(52)
		Float l1 = this->m->__get((int)0);		HX_STACK_VAR(l1,"l1");
		HX_STACK_LINE(53)
		Float l2 = this->m->__get((int)1);		HX_STACK_VAR(l2,"l2");
		HX_STACK_LINE(54)
		Float l3 = this->m->__get((int)2);		HX_STACK_VAR(l3,"l3");
		HX_STACK_LINE(55)
		Float l4 = this->m->__get((int)3);		HX_STACK_VAR(l4,"l4");
		HX_STACK_LINE(56)
		Float l5 = this->m->__get((int)4);		HX_STACK_VAR(l5,"l5");
		HX_STACK_LINE(57)
		Float l6 = this->m->__get((int)5);		HX_STACK_VAR(l6,"l6");
		HX_STACK_LINE(58)
		Float l7 = this->m->__get((int)6);		HX_STACK_VAR(l7,"l7");
		HX_STACK_LINE(59)
		Float l8 = this->m->__get((int)7);		HX_STACK_VAR(l8,"l8");
		HX_STACK_LINE(60)
		Float l9 = this->m->__get((int)8);		HX_STACK_VAR(l9,"l9");
		HX_STACK_LINE(61)
		Float l10 = this->m->__get((int)9);		HX_STACK_VAR(l10,"l10");
		HX_STACK_LINE(62)
		Float l11 = this->m->__get((int)10);		HX_STACK_VAR(l11,"l11");
		HX_STACK_LINE(63)
		Float l12 = this->m->__get((int)11);		HX_STACK_VAR(l12,"l12");
		HX_STACK_LINE(64)
		Float l13 = this->m->__get((int)12);		HX_STACK_VAR(l13,"l13");
		HX_STACK_LINE(65)
		Float l14 = this->m->__get((int)13);		HX_STACK_VAR(l14,"l14");
		HX_STACK_LINE(66)
		Float l15 = this->m->__get((int)14);		HX_STACK_VAR(l15,"l15");
		HX_STACK_LINE(67)
		Float l16 = this->m->__get((int)15);		HX_STACK_VAR(l16,"l16");
		HX_STACK_LINE(68)
		Float l17 = ((l11 * l16) - (l12 * l15));		HX_STACK_VAR(l17,"l17");
		HX_STACK_LINE(69)
		Float l18 = ((l10 * l16) - (l12 * l14));		HX_STACK_VAR(l18,"l18");
		HX_STACK_LINE(70)
		Float l19 = ((l10 * l15) - (l11 * l14));		HX_STACK_VAR(l19,"l19");
		HX_STACK_LINE(71)
		Float l20 = ((l9 * l16) - (l12 * l13));		HX_STACK_VAR(l20,"l20");
		HX_STACK_LINE(72)
		Float l21 = ((l9 * l15) - (l11 * l13));		HX_STACK_VAR(l21,"l21");
		HX_STACK_LINE(73)
		Float l22 = ((l9 * l14) - (l10 * l13));		HX_STACK_VAR(l22,"l22");
		HX_STACK_LINE(74)
		Float l23 = (((l6 * l17) - (l7 * l18)) + (l8 * l19));		HX_STACK_VAR(l23,"l23");
		HX_STACK_LINE(75)
		Float l24 = -(((((l5 * l17) - (l7 * l20)) + (l8 * l21))));		HX_STACK_VAR(l24,"l24");
		HX_STACK_LINE(76)
		Float l25 = (((l5 * l18) - (l6 * l20)) + (l8 * l22));		HX_STACK_VAR(l25,"l25");
		HX_STACK_LINE(77)
		Float l26 = -(((((l5 * l19) - (l6 * l21)) + (l7 * l22))));		HX_STACK_VAR(l26,"l26");
		HX_STACK_LINE(78)
		Float l27 = (Float(1.0) / Float((((((l1 * l23) + (l2 * l24)) + (l3 * l25)) + (l4 * l26)))));		HX_STACK_VAR(l27,"l27");
		HX_STACK_LINE(79)
		Float l28 = ((l7 * l16) - (l8 * l15));		HX_STACK_VAR(l28,"l28");
		HX_STACK_LINE(80)
		Float l29 = ((l6 * l16) - (l8 * l14));		HX_STACK_VAR(l29,"l29");
		HX_STACK_LINE(81)
		Float l30 = ((l6 * l15) - (l7 * l14));		HX_STACK_VAR(l30,"l30");
		HX_STACK_LINE(82)
		Float l31 = ((l5 * l16) - (l8 * l13));		HX_STACK_VAR(l31,"l31");
		HX_STACK_LINE(83)
		Float l32 = ((l5 * l15) - (l7 * l13));		HX_STACK_VAR(l32,"l32");
		HX_STACK_LINE(84)
		Float l33 = ((l5 * l14) - (l6 * l13));		HX_STACK_VAR(l33,"l33");
		HX_STACK_LINE(85)
		Float l34 = ((l7 * l12) - (l8 * l11));		HX_STACK_VAR(l34,"l34");
		HX_STACK_LINE(86)
		Float l35 = ((l6 * l12) - (l8 * l10));		HX_STACK_VAR(l35,"l35");
		HX_STACK_LINE(87)
		Float l36 = ((l6 * l11) - (l7 * l10));		HX_STACK_VAR(l36,"l36");
		HX_STACK_LINE(88)
		Float l37 = ((l5 * l12) - (l8 * l9));		HX_STACK_VAR(l37,"l37");
		HX_STACK_LINE(89)
		Float l38 = ((l5 * l11) - (l7 * l9));		HX_STACK_VAR(l38,"l38");
		HX_STACK_LINE(90)
		Float l39 = ((l5 * l10) - (l6 * l9));		HX_STACK_VAR(l39,"l39");
		HX_STACK_LINE(92)
		other->m[(int)0] = (l23 * l27);
		HX_STACK_LINE(93)
		other->m[(int)4] = (l24 * l27);
		HX_STACK_LINE(94)
		other->m[(int)8] = (l25 * l27);
		HX_STACK_LINE(95)
		other->m[(int)12] = (l26 * l27);
		HX_STACK_LINE(96)
		other->m[(int)1] = (-(((((l2 * l17) - (l3 * l18)) + (l4 * l19)))) * l27);
		HX_STACK_LINE(97)
		other->m[(int)5] = (((((l1 * l17) - (l3 * l20)) + (l4 * l21))) * l27);
		HX_STACK_LINE(98)
		other->m[(int)9] = (-(((((l1 * l18) - (l2 * l20)) + (l4 * l22)))) * l27);
		HX_STACK_LINE(99)
		other->m[(int)13] = (((((l1 * l19) - (l2 * l21)) + (l3 * l22))) * l27);
		HX_STACK_LINE(100)
		other->m[(int)2] = (((((l2 * l28) - (l3 * l29)) + (l4 * l30))) * l27);
		HX_STACK_LINE(101)
		other->m[(int)6] = (-(((((l1 * l28) - (l3 * l31)) + (l4 * l32)))) * l27);
		HX_STACK_LINE(102)
		other->m[(int)10] = (((((l1 * l29) - (l2 * l31)) + (l4 * l33))) * l27);
		HX_STACK_LINE(103)
		other->m[(int)14] = (-(((((l1 * l30) - (l2 * l32)) + (l3 * l33)))) * l27);
		HX_STACK_LINE(104)
		other->m[(int)3] = (-(((((l2 * l34) - (l3 * l35)) + (l4 * l36)))) * l27);
		HX_STACK_LINE(105)
		other->m[(int)7] = (((((l1 * l34) - (l3 * l37)) + (l4 * l38))) * l27);
		HX_STACK_LINE(106)
		other->m[(int)11] = (-(((((l1 * l35) - (l2 * l37)) + (l4 * l39)))) * l27);
		HX_STACK_LINE(107)
		other->m[(int)15] = (((((l1 * l36) - (l2 * l38)) + (l3 * l39))) * l27);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,invertToRef,(void))

Void Matrix_obj::invert( ){
{
		HX_STACK_PUSH("Matrix::invert","com/engine/math/Matrix.hx",47);
		HX_STACK_THIS(this);
		HX_STACK_LINE(48)
		Float l1 = this->m->__get((int)0);		HX_STACK_VAR(l1,"l1");
		HX_STACK_LINE(48)
		Float l2 = this->m->__get((int)1);		HX_STACK_VAR(l2,"l2");
		HX_STACK_LINE(48)
		Float l3 = this->m->__get((int)2);		HX_STACK_VAR(l3,"l3");
		HX_STACK_LINE(48)
		Float l4 = this->m->__get((int)3);		HX_STACK_VAR(l4,"l4");
		HX_STACK_LINE(48)
		Float l5 = this->m->__get((int)4);		HX_STACK_VAR(l5,"l5");
		HX_STACK_LINE(48)
		Float l6 = this->m->__get((int)5);		HX_STACK_VAR(l6,"l6");
		HX_STACK_LINE(48)
		Float l7 = this->m->__get((int)6);		HX_STACK_VAR(l7,"l7");
		HX_STACK_LINE(48)
		Float l8 = this->m->__get((int)7);		HX_STACK_VAR(l8,"l8");
		HX_STACK_LINE(48)
		Float l9 = this->m->__get((int)8);		HX_STACK_VAR(l9,"l9");
		HX_STACK_LINE(48)
		Float l10 = this->m->__get((int)9);		HX_STACK_VAR(l10,"l10");
		HX_STACK_LINE(48)
		Float l11 = this->m->__get((int)10);		HX_STACK_VAR(l11,"l11");
		HX_STACK_LINE(48)
		Float l12 = this->m->__get((int)11);		HX_STACK_VAR(l12,"l12");
		HX_STACK_LINE(48)
		Float l13 = this->m->__get((int)12);		HX_STACK_VAR(l13,"l13");
		HX_STACK_LINE(48)
		Float l14 = this->m->__get((int)13);		HX_STACK_VAR(l14,"l14");
		HX_STACK_LINE(48)
		Float l15 = this->m->__get((int)14);		HX_STACK_VAR(l15,"l15");
		HX_STACK_LINE(48)
		Float l16 = this->m->__get((int)15);		HX_STACK_VAR(l16,"l16");
		HX_STACK_LINE(48)
		Float l17 = ((l11 * l16) - (l12 * l15));		HX_STACK_VAR(l17,"l17");
		HX_STACK_LINE(48)
		Float l18 = ((l10 * l16) - (l12 * l14));		HX_STACK_VAR(l18,"l18");
		HX_STACK_LINE(48)
		Float l19 = ((l10 * l15) - (l11 * l14));		HX_STACK_VAR(l19,"l19");
		HX_STACK_LINE(48)
		Float l20 = ((l9 * l16) - (l12 * l13));		HX_STACK_VAR(l20,"l20");
		HX_STACK_LINE(48)
		Float l21 = ((l9 * l15) - (l11 * l13));		HX_STACK_VAR(l21,"l21");
		HX_STACK_LINE(48)
		Float l22 = ((l9 * l14) - (l10 * l13));		HX_STACK_VAR(l22,"l22");
		HX_STACK_LINE(48)
		Float l23 = (((l6 * l17) - (l7 * l18)) + (l8 * l19));		HX_STACK_VAR(l23,"l23");
		HX_STACK_LINE(48)
		Float l24 = -(((((l5 * l17) - (l7 * l20)) + (l8 * l21))));		HX_STACK_VAR(l24,"l24");
		HX_STACK_LINE(48)
		Float l25 = (((l5 * l18) - (l6 * l20)) + (l8 * l22));		HX_STACK_VAR(l25,"l25");
		HX_STACK_LINE(48)
		Float l26 = -(((((l5 * l19) - (l6 * l21)) + (l7 * l22))));		HX_STACK_VAR(l26,"l26");
		HX_STACK_LINE(48)
		Float l27 = (Float(1.0) / Float((((((l1 * l23) + (l2 * l24)) + (l3 * l25)) + (l4 * l26)))));		HX_STACK_VAR(l27,"l27");
		HX_STACK_LINE(48)
		Float l28 = ((l7 * l16) - (l8 * l15));		HX_STACK_VAR(l28,"l28");
		HX_STACK_LINE(48)
		Float l29 = ((l6 * l16) - (l8 * l14));		HX_STACK_VAR(l29,"l29");
		HX_STACK_LINE(48)
		Float l30 = ((l6 * l15) - (l7 * l14));		HX_STACK_VAR(l30,"l30");
		HX_STACK_LINE(48)
		Float l31 = ((l5 * l16) - (l8 * l13));		HX_STACK_VAR(l31,"l31");
		HX_STACK_LINE(48)
		Float l32 = ((l5 * l15) - (l7 * l13));		HX_STACK_VAR(l32,"l32");
		HX_STACK_LINE(48)
		Float l33 = ((l5 * l14) - (l6 * l13));		HX_STACK_VAR(l33,"l33");
		HX_STACK_LINE(48)
		Float l34 = ((l7 * l12) - (l8 * l11));		HX_STACK_VAR(l34,"l34");
		HX_STACK_LINE(48)
		Float l35 = ((l6 * l12) - (l8 * l10));		HX_STACK_VAR(l35,"l35");
		HX_STACK_LINE(48)
		Float l36 = ((l6 * l11) - (l7 * l10));		HX_STACK_VAR(l36,"l36");
		HX_STACK_LINE(48)
		Float l37 = ((l5 * l12) - (l8 * l9));		HX_STACK_VAR(l37,"l37");
		HX_STACK_LINE(48)
		Float l38 = ((l5 * l11) - (l7 * l9));		HX_STACK_VAR(l38,"l38");
		HX_STACK_LINE(48)
		Float l39 = ((l5 * l10) - (l6 * l9));		HX_STACK_VAR(l39,"l39");
		HX_STACK_LINE(48)
		this->m[(int)0] = (l23 * l27);
		HX_STACK_LINE(48)
		this->m[(int)4] = (l24 * l27);
		HX_STACK_LINE(48)
		this->m[(int)8] = (l25 * l27);
		HX_STACK_LINE(48)
		this->m[(int)12] = (l26 * l27);
		HX_STACK_LINE(48)
		this->m[(int)1] = (-(((((l2 * l17) - (l3 * l18)) + (l4 * l19)))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)5] = (((((l1 * l17) - (l3 * l20)) + (l4 * l21))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)9] = (-(((((l1 * l18) - (l2 * l20)) + (l4 * l22)))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)13] = (((((l1 * l19) - (l2 * l21)) + (l3 * l22))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)2] = (((((l2 * l28) - (l3 * l29)) + (l4 * l30))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)6] = (-(((((l1 * l28) - (l3 * l31)) + (l4 * l32)))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)10] = (((((l1 * l29) - (l2 * l31)) + (l4 * l33))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)14] = (-(((((l1 * l30) - (l2 * l32)) + (l3 * l33)))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)3] = (-(((((l2 * l34) - (l3 * l35)) + (l4 * l36)))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)7] = (((((l1 * l34) - (l3 * l37)) + (l4 * l38))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)11] = (-(((((l1 * l35) - (l2 * l37)) + (l4 * l39)))) * l27);
		HX_STACK_LINE(48)
		this->m[(int)15] = (((((l1 * l36) - (l2 * l38)) + (l3 * l39))) * l27);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,invert,(void))

Array< Float > Matrix_obj::toArray( ){
	HX_STACK_PUSH("Matrix::toArray","com/engine/math/Matrix.hx",43);
	HX_STACK_THIS(this);
	HX_STACK_LINE(43)
	return this->m;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,toArray,return )

Float Matrix_obj::determinant( ){
	HX_STACK_PUSH("Matrix::determinant","com/engine/math/Matrix.hx",29);
	HX_STACK_THIS(this);
	HX_STACK_LINE(30)
	Float temp1 = ((this->m->__get((int)10) * this->m->__get((int)15)) - (this->m->__get((int)11) * this->m->__get((int)14)));		HX_STACK_VAR(temp1,"temp1");
	HX_STACK_LINE(31)
	Float temp2 = ((this->m->__get((int)9) * this->m->__get((int)15)) - (this->m->__get((int)11) * this->m->__get((int)13)));		HX_STACK_VAR(temp2,"temp2");
	HX_STACK_LINE(32)
	Float temp3 = ((this->m->__get((int)9) * this->m->__get((int)14)) - (this->m->__get((int)10) * this->m->__get((int)13)));		HX_STACK_VAR(temp3,"temp3");
	HX_STACK_LINE(33)
	Float temp4 = ((this->m->__get((int)8) * this->m->__get((int)15)) - (this->m->__get((int)11) * this->m->__get((int)12)));		HX_STACK_VAR(temp4,"temp4");
	HX_STACK_LINE(34)
	Float temp5 = ((this->m->__get((int)8) * this->m->__get((int)14)) - (this->m->__get((int)10) * this->m->__get((int)12)));		HX_STACK_VAR(temp5,"temp5");
	HX_STACK_LINE(35)
	Float temp6 = ((this->m->__get((int)8) * this->m->__get((int)13)) - (this->m->__get((int)9) * this->m->__get((int)12)));		HX_STACK_VAR(temp6,"temp6");
	HX_STACK_LINE(37)
	return ((((this->m->__get((int)0) * ((((this->m->__get((int)5) * temp1) - (this->m->__get((int)6) * temp2)) + (this->m->__get((int)7) * temp3)))) - (this->m->__get((int)1) * ((((this->m->__get((int)4) * temp1) - (this->m->__get((int)6) * temp4)) + (this->m->__get((int)7) * temp5))))) + (this->m->__get((int)2) * ((((this->m->__get((int)4) * temp2) - (this->m->__get((int)5) * temp4)) + (this->m->__get((int)7) * temp6))))) - (this->m->__get((int)3) * ((((this->m->__get((int)4) * temp3) - (this->m->__get((int)5) * temp5)) + (this->m->__get((int)6) * temp6)))));
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,determinant,return )

bool Matrix_obj::isIdentity( ){
	HX_STACK_PUSH("Matrix::isIdentity","com/engine/math/Matrix.hx",15);
	HX_STACK_THIS(this);
	HX_STACK_LINE(16)
	bool ret = true;		HX_STACK_VAR(ret,"ret");
	HX_STACK_LINE(17)
	if (((bool((bool((bool((this->m->__get((int)0) != 1.0)) || bool((this->m->__get((int)5) != 1.0)))) || bool((this->m->__get((int)10) != 1.0)))) || bool((this->m->__get((int)15) != 1.0))))){
		HX_STACK_LINE(18)
		ret = false;
	}
	HX_STACK_LINE(20)
	if (((bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((bool((this->m->__get((int)1) != 0.0)) || bool((this->m->__get((int)2) != 0.0)))) || bool((this->m->__get((int)3) != 0.0)))) || bool((this->m->__get((int)4) != 0.0)))) || bool((this->m->__get((int)6) != 0.0)))) || bool((this->m->__get((int)7) != 0.0)))) || bool((this->m->__get((int)8) != 0.0)))) || bool((this->m->__get((int)9) != 0.0)))) || bool((this->m->__get((int)11) != 0.0)))) || bool((this->m->__get((int)12) != 0.0)))) || bool((this->m->__get((int)13) != 0.0)))) || bool((this->m->__get((int)14) != 0.0))))){
		HX_STACK_LINE(24)
		ret = false;
	}
	HX_STACK_LINE(26)
	return ret;
}


HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,isIdentity,return )

::com::engine::math::Matrix Matrix_obj::MatrixMultiply4x4( ::com::engine::math::Matrix A,::com::engine::math::Matrix B){
	HX_STACK_PUSH("Matrix::MatrixMultiply4x4","com/engine/math/Matrix.hx",132);
	HX_STACK_ARG(A,"A");
	HX_STACK_ARG(B,"B");
	HX_STACK_LINE(133)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(136)
	result->m[(int)0] = ((((A->m->__get((int)0) * B->m->__get((int)0)) + (A->m->__get((int)4) * B->m->__get((int)1))) + (A->m->__get((int)8) * B->m->__get((int)2))) + (A->m->__get((int)12) * B->m->__get((int)3)));
	HX_STACK_LINE(137)
	result->m[(int)1] = ((((A->m->__get((int)1) * B->m->__get((int)0)) + (A->m->__get((int)5) * B->m->__get((int)1))) + (A->m->__get((int)9) * B->m->__get((int)2))) + (A->m->__get((int)13) * B->m->__get((int)3)));
	HX_STACK_LINE(138)
	result->m[(int)2] = ((((A->m->__get((int)2) * B->m->__get((int)0)) + (A->m->__get((int)6) * B->m->__get((int)1))) + (A->m->__get((int)10) * B->m->__get((int)2))) + (A->m->__get((int)14) * B->m->__get((int)3)));
	HX_STACK_LINE(139)
	result->m[(int)3] = ((((A->m->__get((int)3) * B->m->__get((int)0)) + (A->m->__get((int)7) * B->m->__get((int)1))) + (A->m->__get((int)11) * B->m->__get((int)2))) + (A->m->__get((int)15) * B->m->__get((int)3)));
	HX_STACK_LINE(141)
	result->m[(int)4] = ((((A->m->__get((int)0) * B->m->__get((int)4)) + (A->m->__get((int)4) * B->m->__get((int)5))) + (A->m->__get((int)8) * B->m->__get((int)6))) + (A->m->__get((int)12) * B->m->__get((int)7)));
	HX_STACK_LINE(142)
	result->m[(int)5] = ((((A->m->__get((int)1) * B->m->__get((int)4)) + (A->m->__get((int)5) * B->m->__get((int)5))) + (A->m->__get((int)9) * B->m->__get((int)6))) + (A->m->__get((int)13) * B->m->__get((int)7)));
	HX_STACK_LINE(143)
	result->m[(int)6] = ((((A->m->__get((int)2) * B->m->__get((int)4)) + (A->m->__get((int)6) * B->m->__get((int)5))) + (A->m->__get((int)10) * B->m->__get((int)6))) + (A->m->__get((int)14) * B->m->__get((int)7)));
	HX_STACK_LINE(144)
	result->m[(int)7] = ((((A->m->__get((int)3) * B->m->__get((int)4)) + (A->m->__get((int)7) * B->m->__get((int)5))) + (A->m->__get((int)11) * B->m->__get((int)6))) + (A->m->__get((int)15) * B->m->__get((int)7)));
	HX_STACK_LINE(146)
	result->m[(int)8] = ((((A->m->__get((int)0) * B->m->__get((int)8)) + (A->m->__get((int)4) * B->m->__get((int)9))) + (A->m->__get((int)8) * B->m->__get((int)10))) + (A->m->__get((int)12) * B->m->__get((int)11)));
	HX_STACK_LINE(147)
	result->m[(int)9] = ((((A->m->__get((int)1) * B->m->__get((int)8)) + (A->m->__get((int)5) * B->m->__get((int)9))) + (A->m->__get((int)9) * B->m->__get((int)10))) + (A->m->__get((int)13) * B->m->__get((int)11)));
	HX_STACK_LINE(148)
	result->m[(int)10] = ((((A->m->__get((int)2) * B->m->__get((int)8)) + (A->m->__get((int)6) * B->m->__get((int)9))) + (A->m->__get((int)10) * B->m->__get((int)10))) + (A->m->__get((int)14) * B->m->__get((int)11)));
	HX_STACK_LINE(149)
	result->m[(int)11] = ((((A->m->__get((int)3) * B->m->__get((int)8)) + (A->m->__get((int)7) * B->m->__get((int)9))) + (A->m->__get((int)11) * B->m->__get((int)10))) + (A->m->__get((int)15) * B->m->__get((int)11)));
	HX_STACK_LINE(151)
	result->m[(int)12] = ((((A->m->__get((int)0) * B->m->__get((int)12)) + (A->m->__get((int)4) * B->m->__get((int)13))) + (A->m->__get((int)8) * B->m->__get((int)14))) + (A->m->__get((int)12) * B->m->__get((int)15)));
	HX_STACK_LINE(152)
	result->m[(int)13] = ((((A->m->__get((int)1) * B->m->__get((int)12)) + (A->m->__get((int)5) * B->m->__get((int)13))) + (A->m->__get((int)9) * B->m->__get((int)14))) + (A->m->__get((int)13) * B->m->__get((int)15)));
	HX_STACK_LINE(153)
	result->m[(int)14] = ((((A->m->__get((int)2) * B->m->__get((int)12)) + (A->m->__get((int)6) * B->m->__get((int)13))) + (A->m->__get((int)10) * B->m->__get((int)14))) + (A->m->__get((int)14) * B->m->__get((int)15)));
	HX_STACK_LINE(154)
	result->m[(int)15] = ((((A->m->__get((int)3) * B->m->__get((int)12)) + (A->m->__get((int)7) * B->m->__get((int)13))) + (A->m->__get((int)11) * B->m->__get((int)14))) + (A->m->__get((int)15) * B->m->__get((int)15)));
	HX_STACK_LINE(156)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,MatrixMultiply4x4,return )

::com::engine::math::Matrix Matrix_obj::FromArray( Array< Float > array,hx::Null< int >  __o_offset){
int offset = __o_offset.Default(0);
	HX_STACK_PUSH("Matrix::FromArray","com/engine/math/Matrix.hx",234);
	HX_STACK_ARG(array,"array");
	HX_STACK_ARG(offset,"offset");
{
		HX_STACK_LINE(235)
		::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(236)
		{
			HX_STACK_LINE(236)
			{
				HX_STACK_LINE(236)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(236)
				while(((_g < (int)16))){
					HX_STACK_LINE(236)
					int index = (_g)++;		HX_STACK_VAR(index,"index");
					HX_STACK_LINE(236)
					result->m[index] = array->__get((index + offset));
				}
			}
			HX_STACK_LINE(236)
			result;
		}
		HX_STACK_LINE(237)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,FromArray,return )

::com::engine::math::Matrix Matrix_obj::FromArrayToRef( Array< Float > array,hx::Null< int >  __o_offset,::com::engine::math::Matrix result){
int offset = __o_offset.Default(0);
	HX_STACK_PUSH("Matrix::FromArrayToRef","com/engine/math/Matrix.hx",240);
	HX_STACK_ARG(array,"array");
	HX_STACK_ARG(offset,"offset");
	HX_STACK_ARG(result,"result");
{
		HX_STACK_LINE(241)
		{
			HX_STACK_LINE(241)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(241)
			while(((_g < (int)16))){
				HX_STACK_LINE(241)
				int index = (_g)++;		HX_STACK_VAR(index,"index");
				HX_STACK_LINE(242)
				result->m[index] = array->__get((index + offset));
			}
		}
		HX_STACK_LINE(244)
		return result;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,FromArrayToRef,return )

::com::engine::math::Matrix Matrix_obj::FromValues( Float m11,Float m12,Float m13,Float m14,Float m21,Float m22,Float m23,Float m24,Float m31,Float m32,Float m33,Float m34,Float m41,Float m42,Float m43,Float m44){
	HX_STACK_PUSH("Matrix::FromValues","com/engine/math/Matrix.hx",250);
	HX_STACK_ARG(m11,"m11");
	HX_STACK_ARG(m12,"m12");
	HX_STACK_ARG(m13,"m13");
	HX_STACK_ARG(m14,"m14");
	HX_STACK_ARG(m21,"m21");
	HX_STACK_ARG(m22,"m22");
	HX_STACK_ARG(m23,"m23");
	HX_STACK_ARG(m24,"m24");
	HX_STACK_ARG(m31,"m31");
	HX_STACK_ARG(m32,"m32");
	HX_STACK_ARG(m33,"m33");
	HX_STACK_ARG(m34,"m34");
	HX_STACK_ARG(m41,"m41");
	HX_STACK_ARG(m42,"m42");
	HX_STACK_ARG(m43,"m43");
	HX_STACK_ARG(m44,"m44");
	HX_STACK_LINE(252)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(254)
	result->m[(int)0] = m11;
	HX_STACK_LINE(255)
	result->m[(int)1] = m12;
	HX_STACK_LINE(256)
	result->m[(int)2] = m13;
	HX_STACK_LINE(257)
	result->m[(int)3] = m14;
	HX_STACK_LINE(258)
	result->m[(int)4] = m21;
	HX_STACK_LINE(259)
	result->m[(int)5] = m22;
	HX_STACK_LINE(260)
	result->m[(int)6] = m23;
	HX_STACK_LINE(261)
	result->m[(int)7] = m24;
	HX_STACK_LINE(262)
	result->m[(int)8] = m31;
	HX_STACK_LINE(263)
	result->m[(int)9] = m32;
	HX_STACK_LINE(264)
	result->m[(int)10] = m33;
	HX_STACK_LINE(265)
	result->m[(int)11] = m34;
	HX_STACK_LINE(266)
	result->m[(int)12] = m41;
	HX_STACK_LINE(267)
	result->m[(int)13] = m42;
	HX_STACK_LINE(268)
	result->m[(int)14] = m43;
	HX_STACK_LINE(269)
	result->m[(int)15] = m44;
	HX_STACK_LINE(271)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC16(Matrix_obj,FromValues,return )

::com::engine::math::Matrix Matrix_obj::FromValuesToRef( Float m11,Float m12,Float m13,Float m14,Float m21,Float m22,Float m23,Float m24,Float m31,Float m32,Float m33,Float m34,Float m41,Float m42,Float m43,Float m44,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::FromValuesToRef","com/engine/math/Matrix.hx",277);
	HX_STACK_ARG(m11,"m11");
	HX_STACK_ARG(m12,"m12");
	HX_STACK_ARG(m13,"m13");
	HX_STACK_ARG(m14,"m14");
	HX_STACK_ARG(m21,"m21");
	HX_STACK_ARG(m22,"m22");
	HX_STACK_ARG(m23,"m23");
	HX_STACK_ARG(m24,"m24");
	HX_STACK_ARG(m31,"m31");
	HX_STACK_ARG(m32,"m32");
	HX_STACK_ARG(m33,"m33");
	HX_STACK_ARG(m34,"m34");
	HX_STACK_ARG(m41,"m41");
	HX_STACK_ARG(m42,"m42");
	HX_STACK_ARG(m43,"m43");
	HX_STACK_ARG(m44,"m44");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(279)
	result->m[(int)0] = m11;
	HX_STACK_LINE(280)
	result->m[(int)1] = m12;
	HX_STACK_LINE(281)
	result->m[(int)2] = m13;
	HX_STACK_LINE(282)
	result->m[(int)3] = m14;
	HX_STACK_LINE(283)
	result->m[(int)4] = m21;
	HX_STACK_LINE(284)
	result->m[(int)5] = m22;
	HX_STACK_LINE(285)
	result->m[(int)6] = m23;
	HX_STACK_LINE(286)
	result->m[(int)7] = m24;
	HX_STACK_LINE(287)
	result->m[(int)8] = m31;
	HX_STACK_LINE(288)
	result->m[(int)9] = m32;
	HX_STACK_LINE(289)
	result->m[(int)10] = m33;
	HX_STACK_LINE(290)
	result->m[(int)11] = m34;
	HX_STACK_LINE(291)
	result->m[(int)12] = m41;
	HX_STACK_LINE(292)
	result->m[(int)13] = m42;
	HX_STACK_LINE(293)
	result->m[(int)14] = m43;
	HX_STACK_LINE(294)
	result->m[(int)15] = m44;
	HX_STACK_LINE(296)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC17(Matrix_obj,FromValuesToRef,return )

::com::engine::math::Matrix Matrix_obj::Identity( ){
	HX_STACK_PUSH("Matrix::Identity","com/engine/math/Matrix.hx",299);
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",300);
			{
				HX_STACK_LINE(300)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(300)
				result->m[(int)0] = 1.0;
				HX_STACK_LINE(300)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)5] = 1.0;
				HX_STACK_LINE(300)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)10] = 1.0;
				HX_STACK_LINE(300)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(300)
				result->m[(int)15] = 1.0;
				HX_STACK_LINE(300)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(299)
	return _Function_1_1::Block();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,Identity,return )

::com::engine::math::Matrix Matrix_obj::IdentityToRef( ::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::IdentityToRef","com/engine/math/Matrix.hx",308);
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(309)
	{
		HX_STACK_LINE(309)
		result->m[(int)0] = 1.0;
		HX_STACK_LINE(309)
		result->m[(int)1] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)2] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)3] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)4] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)5] = 1.0;
		HX_STACK_LINE(309)
		result->m[(int)6] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)7] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)8] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)9] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)10] = 1.0;
		HX_STACK_LINE(309)
		result->m[(int)11] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)12] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)13] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)14] = (int)0;
		HX_STACK_LINE(309)
		result->m[(int)15] = 1.0;
		HX_STACK_LINE(313)
		result;
	}
	HX_STACK_LINE(316)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,IdentityToRef,return )

::com::engine::math::Matrix Matrix_obj::Zero( ){
	HX_STACK_PUSH("Matrix::Zero","com/engine/math/Matrix.hx",319);
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",320);
			{
				HX_STACK_LINE(320)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(320)
				result->m[(int)0] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)5] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)10] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(320)
				result->m[(int)15] = (int)0;
				HX_STACK_LINE(320)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(319)
	return _Function_1_1::Block();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC0(Matrix_obj,Zero,return )

::com::engine::math::Matrix Matrix_obj::RotationX( Float angle){
	HX_STACK_PUSH("Matrix::RotationX","com/engine/math/Matrix.hx",328);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_LINE(329)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(330)
	{
		HX_STACK_LINE(330)
		Float s = ::Math_obj::sin(angle);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(330)
		Float c = ::Math_obj::cos(angle);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(330)
		result->m[(int)0] = 1.0;
		HX_STACK_LINE(330)
		result->m[(int)15] = 1.0;
		HX_STACK_LINE(330)
		result->m[(int)5] = c;
		HX_STACK_LINE(330)
		result->m[(int)10] = c;
		HX_STACK_LINE(330)
		result->m[(int)9] = -(s);
		HX_STACK_LINE(330)
		result->m[(int)6] = s;
		HX_STACK_LINE(330)
		result->m[(int)1] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)2] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)3] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)4] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)7] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)8] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)11] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)12] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)13] = (int)0;
		HX_STACK_LINE(330)
		result->m[(int)14] = (int)0;
		HX_STACK_LINE(330)
		result;
	}
	HX_STACK_LINE(332)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,RotationX,return )

::com::engine::math::Matrix Matrix_obj::RotationXToRef( Float angle,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::RotationXToRef","com/engine/math/Matrix.hx",335);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(336)
	Float s = ::Math_obj::sin(angle);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(337)
	Float c = ::Math_obj::cos(angle);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(339)
	result->m[(int)0] = 1.0;
	HX_STACK_LINE(340)
	result->m[(int)15] = 1.0;
	HX_STACK_LINE(342)
	result->m[(int)5] = c;
	HX_STACK_LINE(343)
	result->m[(int)10] = c;
	HX_STACK_LINE(344)
	result->m[(int)9] = -(s);
	HX_STACK_LINE(345)
	result->m[(int)6] = s;
	HX_STACK_LINE(347)
	result->m[(int)1] = (int)0;
	HX_STACK_LINE(348)
	result->m[(int)2] = (int)0;
	HX_STACK_LINE(349)
	result->m[(int)3] = (int)0;
	HX_STACK_LINE(350)
	result->m[(int)4] = (int)0;
	HX_STACK_LINE(351)
	result->m[(int)7] = (int)0;
	HX_STACK_LINE(352)
	result->m[(int)8] = (int)0;
	HX_STACK_LINE(353)
	result->m[(int)11] = (int)0;
	HX_STACK_LINE(354)
	result->m[(int)12] = (int)0;
	HX_STACK_LINE(355)
	result->m[(int)13] = (int)0;
	HX_STACK_LINE(356)
	result->m[(int)14] = (int)0;
	HX_STACK_LINE(358)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,RotationXToRef,return )

::com::engine::math::Matrix Matrix_obj::RotationY( Float angle){
	HX_STACK_PUSH("Matrix::RotationY","com/engine/math/Matrix.hx",361);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_LINE(362)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(363)
	{
		HX_STACK_LINE(363)
		Float s = ::Math_obj::sin(angle);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(363)
		Float c = ::Math_obj::cos(angle);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(363)
		result->m[(int)5] = 1.0;
		HX_STACK_LINE(363)
		result->m[(int)15] = 1.0;
		HX_STACK_LINE(363)
		result->m[(int)0] = c;
		HX_STACK_LINE(363)
		result->m[(int)2] = -(s);
		HX_STACK_LINE(363)
		result->m[(int)8] = s;
		HX_STACK_LINE(363)
		result->m[(int)10] = c;
		HX_STACK_LINE(363)
		result->m[(int)1] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)3] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)4] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)6] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)7] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)9] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)11] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)12] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)13] = (int)0;
		HX_STACK_LINE(363)
		result->m[(int)14] = (int)0;
		HX_STACK_LINE(363)
		result;
	}
	HX_STACK_LINE(365)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,RotationY,return )

::com::engine::math::Matrix Matrix_obj::RotationYToRef( Float angle,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::RotationYToRef","com/engine/math/Matrix.hx",368);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(369)
	Float s = ::Math_obj::sin(angle);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(370)
	Float c = ::Math_obj::cos(angle);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(372)
	result->m[(int)5] = 1.0;
	HX_STACK_LINE(373)
	result->m[(int)15] = 1.0;
	HX_STACK_LINE(375)
	result->m[(int)0] = c;
	HX_STACK_LINE(376)
	result->m[(int)2] = -(s);
	HX_STACK_LINE(377)
	result->m[(int)8] = s;
	HX_STACK_LINE(378)
	result->m[(int)10] = c;
	HX_STACK_LINE(380)
	result->m[(int)1] = (int)0;
	HX_STACK_LINE(381)
	result->m[(int)3] = (int)0;
	HX_STACK_LINE(382)
	result->m[(int)4] = (int)0;
	HX_STACK_LINE(383)
	result->m[(int)6] = (int)0;
	HX_STACK_LINE(384)
	result->m[(int)7] = (int)0;
	HX_STACK_LINE(385)
	result->m[(int)9] = (int)0;
	HX_STACK_LINE(386)
	result->m[(int)11] = (int)0;
	HX_STACK_LINE(387)
	result->m[(int)12] = (int)0;
	HX_STACK_LINE(388)
	result->m[(int)13] = (int)0;
	HX_STACK_LINE(389)
	result->m[(int)14] = (int)0;
	HX_STACK_LINE(391)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,RotationYToRef,return )

::com::engine::math::Matrix Matrix_obj::RotationZ( Float angle){
	HX_STACK_PUSH("Matrix::RotationZ","com/engine/math/Matrix.hx",394);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_LINE(395)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(396)
	{
		HX_STACK_LINE(396)
		Float s = ::Math_obj::sin(angle);		HX_STACK_VAR(s,"s");
		HX_STACK_LINE(396)
		Float c = ::Math_obj::cos(angle);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(396)
		result->m[(int)10] = 1.0;
		HX_STACK_LINE(396)
		result->m[(int)15] = 1.0;
		HX_STACK_LINE(396)
		result->m[(int)0] = c;
		HX_STACK_LINE(396)
		result->m[(int)1] = s;
		HX_STACK_LINE(396)
		result->m[(int)4] = -(s);
		HX_STACK_LINE(396)
		result->m[(int)5] = c;
		HX_STACK_LINE(396)
		result->m[(int)2] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)3] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)6] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)7] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)8] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)9] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)11] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)12] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)13] = (int)0;
		HX_STACK_LINE(396)
		result->m[(int)14] = (int)0;
		HX_STACK_LINE(396)
		result;
	}
	HX_STACK_LINE(398)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,RotationZ,return )

::com::engine::math::Matrix Matrix_obj::RotationZToRef( Float angle,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::RotationZToRef","com/engine/math/Matrix.hx",401);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(402)
	Float s = ::Math_obj::sin(angle);		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(403)
	Float c = ::Math_obj::cos(angle);		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(405)
	result->m[(int)10] = 1.0;
	HX_STACK_LINE(406)
	result->m[(int)15] = 1.0;
	HX_STACK_LINE(408)
	result->m[(int)0] = c;
	HX_STACK_LINE(409)
	result->m[(int)1] = s;
	HX_STACK_LINE(410)
	result->m[(int)4] = -(s);
	HX_STACK_LINE(411)
	result->m[(int)5] = c;
	HX_STACK_LINE(413)
	result->m[(int)2] = (int)0;
	HX_STACK_LINE(414)
	result->m[(int)3] = (int)0;
	HX_STACK_LINE(415)
	result->m[(int)6] = (int)0;
	HX_STACK_LINE(416)
	result->m[(int)7] = (int)0;
	HX_STACK_LINE(417)
	result->m[(int)8] = (int)0;
	HX_STACK_LINE(418)
	result->m[(int)9] = (int)0;
	HX_STACK_LINE(419)
	result->m[(int)11] = (int)0;
	HX_STACK_LINE(420)
	result->m[(int)12] = (int)0;
	HX_STACK_LINE(421)
	result->m[(int)13] = (int)0;
	HX_STACK_LINE(422)
	result->m[(int)14] = (int)0;
	HX_STACK_LINE(424)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,RotationZToRef,return )

::com::engine::math::Matrix Matrix_obj::RotationAxis( ::com::engine::math::Vector3 axis,Float angle){
	HX_STACK_PUSH("Matrix::RotationAxis","com/engine/math/Matrix.hx",427);
	HX_STACK_ARG(axis,"axis");
	HX_STACK_ARG(angle,"angle");
	HX_STACK_LINE(428)
	Float s = ::Math_obj::sin(-(angle));		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(429)
	Float c = ::Math_obj::cos(-(angle));		HX_STACK_VAR(c,"c");
	HX_STACK_LINE(430)
	Float c1 = ((int)1 - c);		HX_STACK_VAR(c1,"c1");
	HX_STACK_LINE(432)
	{
		HX_STACK_LINE(432)
		Float len = ::Math_obj::sqrt((((axis->x * axis->x) + (axis->y * axis->y)) + (axis->z * axis->z)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(432)
		if (((len != (int)0))){
			HX_STACK_LINE(432)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(432)
			hx::MultEq(axis->x,num);
			HX_STACK_LINE(432)
			hx::MultEq(axis->y,num);
			HX_STACK_LINE(432)
			hx::MultEq(axis->z,num);
		}
	}
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",433);
			{
				HX_STACK_LINE(433)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(433)
				result->m[(int)0] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)5] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)10] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(433)
				result->m[(int)15] = (int)0;
				HX_STACK_LINE(433)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(433)
	::com::engine::math::Matrix result = _Function_1_1::Block();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(435)
	result->m[(int)0] = (((axis->x * axis->x) * c1) + c);
	HX_STACK_LINE(436)
	result->m[(int)1] = (((axis->x * axis->y) * c1) - (axis->z * s));
	HX_STACK_LINE(437)
	result->m[(int)2] = (((axis->x * axis->z) * c1) + (axis->y * s));
	HX_STACK_LINE(438)
	result->m[(int)3] = 0.0;
	HX_STACK_LINE(440)
	result->m[(int)4] = (((axis->y * axis->x) * c1) + (axis->z * s));
	HX_STACK_LINE(441)
	result->m[(int)5] = (((axis->y * axis->y) * c1) + c);
	HX_STACK_LINE(442)
	result->m[(int)6] = (((axis->y * axis->z) * c1) - (axis->x * s));
	HX_STACK_LINE(443)
	result->m[(int)7] = 0.0;
	HX_STACK_LINE(445)
	result->m[(int)8] = (((axis->z * axis->x) * c1) - (axis->y * s));
	HX_STACK_LINE(446)
	result->m[(int)9] = (((axis->z * axis->y) * c1) + (axis->x * s));
	HX_STACK_LINE(447)
	result->m[(int)10] = (((axis->z * axis->z) * c1) + c);
	HX_STACK_LINE(448)
	result->m[(int)11] = 0.0;
	HX_STACK_LINE(450)
	result->m[(int)15] = 1.0;
	HX_STACK_LINE(452)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,RotationAxis,return )

::com::engine::math::Matrix Matrix_obj::RotationYawPitchRoll( Float yaw,Float pitch,Float roll){
	HX_STACK_PUSH("Matrix::RotationYawPitchRoll","com/engine/math/Matrix.hx",455);
	HX_STACK_ARG(yaw,"yaw");
	HX_STACK_ARG(pitch,"pitch");
	HX_STACK_ARG(roll,"roll");
	HX_STACK_LINE(456)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(457)
	{
		HX_STACK_LINE(457)
		::com::engine::math::Quaternion tempQuaternion = ::com::engine::math::Quaternion_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(tempQuaternion,"tempQuaternion");
		struct _Function_2_1{
			inline static ::com::engine::math::Quaternion Block( Float &pitch,::com::engine::math::Quaternion &tempQuaternion,Float &yaw,Float &roll){
				HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",457);
				{
					HX_STACK_LINE(457)
					Float halfRoll = (roll * 0.5);		HX_STACK_VAR(halfRoll,"halfRoll");
					HX_STACK_LINE(457)
					Float halfPitch = (pitch * 0.5);		HX_STACK_VAR(halfPitch,"halfPitch");
					HX_STACK_LINE(457)
					Float halfYaw = (yaw * 0.5);		HX_STACK_VAR(halfYaw,"halfYaw");
					HX_STACK_LINE(457)
					Float sinRoll = ::Math_obj::sin(halfRoll);		HX_STACK_VAR(sinRoll,"sinRoll");
					HX_STACK_LINE(457)
					Float cosRoll = ::Math_obj::cos(halfRoll);		HX_STACK_VAR(cosRoll,"cosRoll");
					HX_STACK_LINE(457)
					Float sinPitch = ::Math_obj::sin(halfPitch);		HX_STACK_VAR(sinPitch,"sinPitch");
					HX_STACK_LINE(457)
					Float cosPitch = ::Math_obj::cos(halfPitch);		HX_STACK_VAR(cosPitch,"cosPitch");
					HX_STACK_LINE(457)
					Float sinYaw = ::Math_obj::sin(halfYaw);		HX_STACK_VAR(sinYaw,"sinYaw");
					HX_STACK_LINE(457)
					Float cosYaw = ::Math_obj::cos(halfYaw);		HX_STACK_VAR(cosYaw,"cosYaw");
					HX_STACK_LINE(457)
					tempQuaternion->x = (((cosYaw * sinPitch) * cosRoll) + ((sinYaw * cosPitch) * sinRoll));
					HX_STACK_LINE(457)
					tempQuaternion->y = (((sinYaw * cosPitch) * cosRoll) - ((cosYaw * sinPitch) * sinRoll));
					HX_STACK_LINE(457)
					tempQuaternion->z = (((cosYaw * cosPitch) * sinRoll) - ((sinYaw * sinPitch) * cosRoll));
					HX_STACK_LINE(457)
					tempQuaternion->w = (((cosYaw * cosPitch) * cosRoll) + ((sinYaw * sinPitch) * sinRoll));
					HX_STACK_LINE(457)
					return tempQuaternion;
				}
				return null();
			}
		};
		HX_STACK_LINE(457)
		tempQuaternion = _Function_2_1::Block(pitch,tempQuaternion,yaw,roll);
		HX_STACK_LINE(457)
		{
			HX_STACK_LINE(457)
			Float xx = (tempQuaternion->x * tempQuaternion->x);		HX_STACK_VAR(xx,"xx");
			HX_STACK_LINE(457)
			Float yy = (tempQuaternion->y * tempQuaternion->y);		HX_STACK_VAR(yy,"yy");
			HX_STACK_LINE(457)
			Float zz = (tempQuaternion->z * tempQuaternion->z);		HX_STACK_VAR(zz,"zz");
			HX_STACK_LINE(457)
			Float xy = (tempQuaternion->x * tempQuaternion->y);		HX_STACK_VAR(xy,"xy");
			HX_STACK_LINE(457)
			Float zw = (tempQuaternion->z * tempQuaternion->w);		HX_STACK_VAR(zw,"zw");
			HX_STACK_LINE(457)
			Float zx = (tempQuaternion->z * tempQuaternion->x);		HX_STACK_VAR(zx,"zx");
			HX_STACK_LINE(457)
			Float yw = (tempQuaternion->y * tempQuaternion->w);		HX_STACK_VAR(yw,"yw");
			HX_STACK_LINE(457)
			Float yz = (tempQuaternion->y * tempQuaternion->z);		HX_STACK_VAR(yz,"yz");
			HX_STACK_LINE(457)
			Float xw = (tempQuaternion->x * tempQuaternion->w);		HX_STACK_VAR(xw,"xw");
			HX_STACK_LINE(457)
			result->m[(int)0] = (1.0 - (2.0 * ((yy + zz))));
			HX_STACK_LINE(457)
			result->m[(int)1] = (2.0 * ((xy + zw)));
			HX_STACK_LINE(457)
			result->m[(int)2] = (2.0 * ((zx - yw)));
			HX_STACK_LINE(457)
			result->m[(int)3] = (int)0;
			HX_STACK_LINE(457)
			result->m[(int)4] = (2.0 * ((xy - zw)));
			HX_STACK_LINE(457)
			result->m[(int)5] = (1.0 - (2.0 * ((zz + xx))));
			HX_STACK_LINE(457)
			result->m[(int)6] = (2.0 * ((yz + xw)));
			HX_STACK_LINE(457)
			result->m[(int)7] = (int)0;
			HX_STACK_LINE(457)
			result->m[(int)8] = (2.0 * ((zx + yw)));
			HX_STACK_LINE(457)
			result->m[(int)9] = (2.0 * ((yz - xw)));
			HX_STACK_LINE(457)
			result->m[(int)10] = (1.0 - (2.0 * ((yy + xx))));
			HX_STACK_LINE(457)
			result->m[(int)11] = (int)0;
			HX_STACK_LINE(457)
			result->m[(int)12] = (int)0;
			HX_STACK_LINE(457)
			result->m[(int)13] = (int)0;
			HX_STACK_LINE(457)
			result->m[(int)14] = (int)0;
			HX_STACK_LINE(457)
			result->m[(int)15] = 1.0;
			HX_STACK_LINE(457)
			result;
		}
	}
	HX_STACK_LINE(459)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,RotationYawPitchRoll,return )

::com::engine::math::Matrix Matrix_obj::RotationYawPitchRollToRef( Float yaw,Float pitch,Float roll,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::RotationYawPitchRollToRef","com/engine/math/Matrix.hx",462);
	HX_STACK_ARG(yaw,"yaw");
	HX_STACK_ARG(pitch,"pitch");
	HX_STACK_ARG(roll,"roll");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(463)
	::com::engine::math::Quaternion tempQuaternion = ::com::engine::math::Quaternion_obj::__new(null(),null(),null(),null());		HX_STACK_VAR(tempQuaternion,"tempQuaternion");
	struct _Function_1_1{
		inline static ::com::engine::math::Quaternion Block( Float &pitch,::com::engine::math::Quaternion &tempQuaternion,Float &yaw,Float &roll){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",464);
			{
				HX_STACK_LINE(464)
				Float halfRoll = (roll * 0.5);		HX_STACK_VAR(halfRoll,"halfRoll");
				HX_STACK_LINE(464)
				Float halfPitch = (pitch * 0.5);		HX_STACK_VAR(halfPitch,"halfPitch");
				HX_STACK_LINE(464)
				Float halfYaw = (yaw * 0.5);		HX_STACK_VAR(halfYaw,"halfYaw");
				HX_STACK_LINE(464)
				Float sinRoll = ::Math_obj::sin(halfRoll);		HX_STACK_VAR(sinRoll,"sinRoll");
				HX_STACK_LINE(464)
				Float cosRoll = ::Math_obj::cos(halfRoll);		HX_STACK_VAR(cosRoll,"cosRoll");
				HX_STACK_LINE(464)
				Float sinPitch = ::Math_obj::sin(halfPitch);		HX_STACK_VAR(sinPitch,"sinPitch");
				HX_STACK_LINE(464)
				Float cosPitch = ::Math_obj::cos(halfPitch);		HX_STACK_VAR(cosPitch,"cosPitch");
				HX_STACK_LINE(464)
				Float sinYaw = ::Math_obj::sin(halfYaw);		HX_STACK_VAR(sinYaw,"sinYaw");
				HX_STACK_LINE(464)
				Float cosYaw = ::Math_obj::cos(halfYaw);		HX_STACK_VAR(cosYaw,"cosYaw");
				HX_STACK_LINE(464)
				tempQuaternion->x = (((cosYaw * sinPitch) * cosRoll) + ((sinYaw * cosPitch) * sinRoll));
				HX_STACK_LINE(464)
				tempQuaternion->y = (((sinYaw * cosPitch) * cosRoll) - ((cosYaw * sinPitch) * sinRoll));
				HX_STACK_LINE(464)
				tempQuaternion->z = (((cosYaw * cosPitch) * sinRoll) - ((sinYaw * sinPitch) * cosRoll));
				HX_STACK_LINE(464)
				tempQuaternion->w = (((cosYaw * cosPitch) * cosRoll) + ((sinYaw * sinPitch) * sinRoll));
				HX_STACK_LINE(464)
				return tempQuaternion;
			}
			return null();
		}
	};
	HX_STACK_LINE(464)
	tempQuaternion = _Function_1_1::Block(pitch,tempQuaternion,yaw,roll);
	struct _Function_1_2{
		inline static ::com::engine::math::Matrix Block( ::com::engine::math::Quaternion &tempQuaternion,::com::engine::math::Matrix &result){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",466);
			{
				HX_STACK_LINE(466)
				Float xx = (tempQuaternion->x * tempQuaternion->x);		HX_STACK_VAR(xx,"xx");
				HX_STACK_LINE(466)
				Float yy = (tempQuaternion->y * tempQuaternion->y);		HX_STACK_VAR(yy,"yy");
				HX_STACK_LINE(466)
				Float zz = (tempQuaternion->z * tempQuaternion->z);		HX_STACK_VAR(zz,"zz");
				HX_STACK_LINE(466)
				Float xy = (tempQuaternion->x * tempQuaternion->y);		HX_STACK_VAR(xy,"xy");
				HX_STACK_LINE(466)
				Float zw = (tempQuaternion->z * tempQuaternion->w);		HX_STACK_VAR(zw,"zw");
				HX_STACK_LINE(466)
				Float zx = (tempQuaternion->z * tempQuaternion->x);		HX_STACK_VAR(zx,"zx");
				HX_STACK_LINE(466)
				Float yw = (tempQuaternion->y * tempQuaternion->w);		HX_STACK_VAR(yw,"yw");
				HX_STACK_LINE(466)
				Float yz = (tempQuaternion->y * tempQuaternion->z);		HX_STACK_VAR(yz,"yz");
				HX_STACK_LINE(466)
				Float xw = (tempQuaternion->x * tempQuaternion->w);		HX_STACK_VAR(xw,"xw");
				HX_STACK_LINE(466)
				result->m[(int)0] = (1.0 - (2.0 * ((yy + zz))));
				HX_STACK_LINE(466)
				result->m[(int)1] = (2.0 * ((xy + zw)));
				HX_STACK_LINE(466)
				result->m[(int)2] = (2.0 * ((zx - yw)));
				HX_STACK_LINE(466)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(466)
				result->m[(int)4] = (2.0 * ((xy - zw)));
				HX_STACK_LINE(466)
				result->m[(int)5] = (1.0 - (2.0 * ((zz + xx))));
				HX_STACK_LINE(466)
				result->m[(int)6] = (2.0 * ((yz + xw)));
				HX_STACK_LINE(466)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(466)
				result->m[(int)8] = (2.0 * ((zx + yw)));
				HX_STACK_LINE(466)
				result->m[(int)9] = (2.0 * ((yz - xw)));
				HX_STACK_LINE(466)
				result->m[(int)10] = (1.0 - (2.0 * ((yy + xx))));
				HX_STACK_LINE(466)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(466)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(466)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(466)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(466)
				result->m[(int)15] = 1.0;
				HX_STACK_LINE(466)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(466)
	return _Function_1_2::Block(tempQuaternion,result);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,RotationYawPitchRollToRef,return )

::com::engine::math::Matrix Matrix_obj::Scaling( Float x,Float y,Float z){
	HX_STACK_PUSH("Matrix::Scaling","com/engine/math/Matrix.hx",469);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",470);
			{
				HX_STACK_LINE(470)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(470)
				result->m[(int)0] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)5] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)10] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(470)
				result->m[(int)15] = (int)0;
				HX_STACK_LINE(470)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(470)
	::com::engine::math::Matrix result = _Function_1_1::Block();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(471)
	{
		HX_STACK_LINE(471)
		result->m[(int)0] = x;
		HX_STACK_LINE(471)
		result->m[(int)1] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)2] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)3] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)4] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)5] = y;
		HX_STACK_LINE(471)
		result->m[(int)6] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)7] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)8] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)9] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)10] = z;
		HX_STACK_LINE(471)
		result->m[(int)11] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)12] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)13] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)14] = (int)0;
		HX_STACK_LINE(471)
		result->m[(int)15] = 1.0;
		HX_STACK_LINE(471)
		result;
	}
	HX_STACK_LINE(473)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,Scaling,return )

::com::engine::math::Matrix Matrix_obj::ScalingToRef( Float x,Float y,Float z,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::ScalingToRef","com/engine/math/Matrix.hx",476);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(477)
	result->m[(int)0] = x;
	HX_STACK_LINE(478)
	result->m[(int)1] = (int)0;
	HX_STACK_LINE(479)
	result->m[(int)2] = (int)0;
	HX_STACK_LINE(480)
	result->m[(int)3] = (int)0;
	HX_STACK_LINE(481)
	result->m[(int)4] = (int)0;
	HX_STACK_LINE(482)
	result->m[(int)5] = y;
	HX_STACK_LINE(483)
	result->m[(int)6] = (int)0;
	HX_STACK_LINE(484)
	result->m[(int)7] = (int)0;
	HX_STACK_LINE(485)
	result->m[(int)8] = (int)0;
	HX_STACK_LINE(486)
	result->m[(int)9] = (int)0;
	HX_STACK_LINE(487)
	result->m[(int)10] = z;
	HX_STACK_LINE(488)
	result->m[(int)11] = (int)0;
	HX_STACK_LINE(489)
	result->m[(int)12] = (int)0;
	HX_STACK_LINE(490)
	result->m[(int)13] = (int)0;
	HX_STACK_LINE(491)
	result->m[(int)14] = (int)0;
	HX_STACK_LINE(492)
	result->m[(int)15] = 1.0;
	HX_STACK_LINE(494)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,ScalingToRef,return )

::com::engine::math::Matrix Matrix_obj::Translation( Float x,Float y,Float z){
	HX_STACK_PUSH("Matrix::Translation","com/engine/math/Matrix.hx",497);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",498);
			{
				HX_STACK_LINE(498)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(498)
				result->m[(int)0] = 1.0;
				HX_STACK_LINE(498)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)5] = 1.0;
				HX_STACK_LINE(498)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)10] = 1.0;
				HX_STACK_LINE(498)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(498)
				result->m[(int)15] = 1.0;
				HX_STACK_LINE(498)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(498)
	::com::engine::math::Matrix result = _Function_1_1::Block();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(499)
	{
		HX_STACK_LINE(499)
		result->m[(int)0] = 1.0;
		HX_STACK_LINE(499)
		result->m[(int)1] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)2] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)3] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)4] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)5] = 1.0;
		HX_STACK_LINE(499)
		result->m[(int)6] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)7] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)8] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)9] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)10] = 1.0;
		HX_STACK_LINE(499)
		result->m[(int)11] = (int)0;
		HX_STACK_LINE(499)
		result->m[(int)12] = x;
		HX_STACK_LINE(499)
		result->m[(int)13] = y;
		HX_STACK_LINE(499)
		result->m[(int)14] = z;
		HX_STACK_LINE(499)
		result->m[(int)15] = 1.0;
		HX_STACK_LINE(499)
		result;
	}
	HX_STACK_LINE(501)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,Translation,return )

Void Matrix_obj::TranslationToRef( Float x,Float y,Float z,::com::engine::math::Matrix result){
{
		HX_STACK_PUSH("Matrix::TranslationToRef","com/engine/math/Matrix.hx",504);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(z,"z");
		HX_STACK_ARG(result,"result");
		HX_STACK_LINE(505)
		result->m[(int)0] = 1.0;
		HX_STACK_LINE(505)
		result->m[(int)1] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)2] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)3] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)4] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)5] = 1.0;
		HX_STACK_LINE(505)
		result->m[(int)6] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)7] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)8] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)9] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)10] = 1.0;
		HX_STACK_LINE(505)
		result->m[(int)11] = (int)0;
		HX_STACK_LINE(505)
		result->m[(int)12] = x;
		HX_STACK_LINE(505)
		result->m[(int)13] = y;
		HX_STACK_LINE(505)
		result->m[(int)14] = z;
		HX_STACK_LINE(505)
		result->m[(int)15] = 1.0;
		HX_STACK_LINE(509)
		result;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,TranslationToRef,(void))

::com::engine::math::Matrix Matrix_obj::LookAtLH( ::com::engine::math::Vector3 eye,::com::engine::math::Vector3 target,::com::engine::math::Vector3 up){
	HX_STACK_PUSH("Matrix::LookAtLH","com/engine/math/Matrix.hx",513);
	HX_STACK_ARG(eye,"eye");
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(up,"up");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",514);
			{
				HX_STACK_LINE(514)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(514)
				result->m[(int)0] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)5] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)10] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(514)
				result->m[(int)15] = (int)0;
				HX_STACK_LINE(514)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(514)
	::com::engine::math::Matrix result = _Function_1_1::Block();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(515)
	{
		HX_STACK_LINE(515)
		::com::engine::math::Vector3 xAxis = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(xAxis,"xAxis");
		HX_STACK_LINE(515)
		::com::engine::math::Vector3 yAxis = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(yAxis,"yAxis");
		HX_STACK_LINE(515)
		::com::engine::math::Vector3 zAxis = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(zAxis,"zAxis");
		HX_STACK_LINE(515)
		{
			HX_STACK_LINE(515)
			zAxis->x = (target->x - eye->x);
			HX_STACK_LINE(515)
			zAxis->y = (target->y - eye->y);
			HX_STACK_LINE(515)
			zAxis->z = (target->z - eye->z);
		}
		HX_STACK_LINE(515)
		{
			HX_STACK_LINE(515)
			Float len = ::Math_obj::sqrt((((zAxis->x * zAxis->x) + (zAxis->y * zAxis->y)) + (zAxis->z * zAxis->z)));		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(515)
			if (((len != (int)0))){
				HX_STACK_LINE(515)
				Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
				HX_STACK_LINE(515)
				hx::MultEq(zAxis->x,num);
				HX_STACK_LINE(515)
				hx::MultEq(zAxis->y,num);
				HX_STACK_LINE(515)
				hx::MultEq(zAxis->z,num);
			}
		}
		HX_STACK_LINE(515)
		{
			HX_STACK_LINE(515)
			xAxis->x = ((up->y * zAxis->z) - (up->z * zAxis->y));
			HX_STACK_LINE(515)
			xAxis->y = ((up->z * zAxis->x) - (up->x * zAxis->z));
			HX_STACK_LINE(515)
			xAxis->z = ((up->x * zAxis->y) - (up->y * zAxis->x));
		}
		HX_STACK_LINE(515)
		{
			HX_STACK_LINE(515)
			Float len = ::Math_obj::sqrt((((xAxis->x * xAxis->x) + (xAxis->y * xAxis->y)) + (xAxis->z * xAxis->z)));		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(515)
			if (((len != (int)0))){
				HX_STACK_LINE(515)
				Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
				HX_STACK_LINE(515)
				hx::MultEq(xAxis->x,num);
				HX_STACK_LINE(515)
				hx::MultEq(xAxis->y,num);
				HX_STACK_LINE(515)
				hx::MultEq(xAxis->z,num);
			}
		}
		HX_STACK_LINE(515)
		{
			HX_STACK_LINE(515)
			yAxis->x = ((zAxis->y * xAxis->z) - (zAxis->z * xAxis->y));
			HX_STACK_LINE(515)
			yAxis->y = ((zAxis->z * xAxis->x) - (zAxis->x * xAxis->z));
			HX_STACK_LINE(515)
			yAxis->z = ((zAxis->x * xAxis->y) - (zAxis->y * xAxis->x));
		}
		HX_STACK_LINE(515)
		{
			HX_STACK_LINE(515)
			Float len = ::Math_obj::sqrt((((yAxis->x * yAxis->x) + (yAxis->y * yAxis->y)) + (yAxis->z * yAxis->z)));		HX_STACK_VAR(len,"len");
			HX_STACK_LINE(515)
			if (((len != (int)0))){
				HX_STACK_LINE(515)
				Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
				HX_STACK_LINE(515)
				hx::MultEq(yAxis->x,num);
				HX_STACK_LINE(515)
				hx::MultEq(yAxis->y,num);
				HX_STACK_LINE(515)
				hx::MultEq(yAxis->z,num);
			}
		}
		HX_STACK_LINE(515)
		Float ex = -(((((xAxis->x * eye->x) + (xAxis->y * eye->y)) + (xAxis->z * eye->z))));		HX_STACK_VAR(ex,"ex");
		HX_STACK_LINE(515)
		Float ey = -(((((yAxis->x * eye->x) + (yAxis->y * eye->y)) + (yAxis->z * eye->z))));		HX_STACK_VAR(ey,"ey");
		HX_STACK_LINE(515)
		Float ez = -(((((zAxis->x * eye->x) + (zAxis->y * eye->y)) + (zAxis->z * eye->z))));		HX_STACK_VAR(ez,"ez");
		HX_STACK_LINE(515)
		{
			HX_STACK_LINE(515)
			result->m[(int)0] = xAxis->x;
			HX_STACK_LINE(515)
			result->m[(int)1] = yAxis->x;
			HX_STACK_LINE(515)
			result->m[(int)2] = zAxis->x;
			HX_STACK_LINE(515)
			result->m[(int)3] = (int)0;
			HX_STACK_LINE(515)
			result->m[(int)4] = xAxis->y;
			HX_STACK_LINE(515)
			result->m[(int)5] = yAxis->y;
			HX_STACK_LINE(515)
			result->m[(int)6] = zAxis->y;
			HX_STACK_LINE(515)
			result->m[(int)7] = (int)0;
			HX_STACK_LINE(515)
			result->m[(int)8] = xAxis->z;
			HX_STACK_LINE(515)
			result->m[(int)9] = yAxis->z;
			HX_STACK_LINE(515)
			result->m[(int)10] = zAxis->z;
			HX_STACK_LINE(515)
			result->m[(int)11] = (int)0;
			HX_STACK_LINE(515)
			result->m[(int)12] = ex;
			HX_STACK_LINE(515)
			result->m[(int)13] = ey;
			HX_STACK_LINE(515)
			result->m[(int)14] = ez;
			HX_STACK_LINE(515)
			result->m[(int)15] = (int)1;
			HX_STACK_LINE(515)
			result;
		}
	}
	HX_STACK_LINE(517)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Matrix_obj,LookAtLH,return )

::com::engine::math::Matrix Matrix_obj::LookAtLHToRef( ::com::engine::math::Vector3 eye,::com::engine::math::Vector3 target,::com::engine::math::Vector3 up,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::LookAtLHToRef","com/engine/math/Matrix.hx",520);
	HX_STACK_ARG(eye,"eye");
	HX_STACK_ARG(target,"target");
	HX_STACK_ARG(up,"up");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(521)
	::com::engine::math::Vector3 xAxis = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(xAxis,"xAxis");
	HX_STACK_LINE(522)
	::com::engine::math::Vector3 yAxis = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(yAxis,"yAxis");
	HX_STACK_LINE(523)
	::com::engine::math::Vector3 zAxis = ::com::engine::math::Vector3_obj::Zero();		HX_STACK_VAR(zAxis,"zAxis");
	HX_STACK_LINE(526)
	{
		HX_STACK_LINE(526)
		zAxis->x = (target->x - eye->x);
		HX_STACK_LINE(526)
		zAxis->y = (target->y - eye->y);
		HX_STACK_LINE(526)
		zAxis->z = (target->z - eye->z);
	}
	HX_STACK_LINE(527)
	{
		HX_STACK_LINE(527)
		Float len = ::Math_obj::sqrt((((zAxis->x * zAxis->x) + (zAxis->y * zAxis->y)) + (zAxis->z * zAxis->z)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(527)
		if (((len != (int)0))){
			HX_STACK_LINE(527)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(527)
			hx::MultEq(zAxis->x,num);
			HX_STACK_LINE(527)
			hx::MultEq(zAxis->y,num);
			HX_STACK_LINE(527)
			hx::MultEq(zAxis->z,num);
		}
	}
	HX_STACK_LINE(530)
	{
		HX_STACK_LINE(530)
		xAxis->x = ((up->y * zAxis->z) - (up->z * zAxis->y));
		HX_STACK_LINE(530)
		xAxis->y = ((up->z * zAxis->x) - (up->x * zAxis->z));
		HX_STACK_LINE(530)
		xAxis->z = ((up->x * zAxis->y) - (up->y * zAxis->x));
	}
	HX_STACK_LINE(531)
	{
		HX_STACK_LINE(531)
		Float len = ::Math_obj::sqrt((((xAxis->x * xAxis->x) + (xAxis->y * xAxis->y)) + (xAxis->z * xAxis->z)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(531)
		if (((len != (int)0))){
			HX_STACK_LINE(531)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(531)
			hx::MultEq(xAxis->x,num);
			HX_STACK_LINE(531)
			hx::MultEq(xAxis->y,num);
			HX_STACK_LINE(531)
			hx::MultEq(xAxis->z,num);
		}
	}
	HX_STACK_LINE(534)
	{
		HX_STACK_LINE(534)
		yAxis->x = ((zAxis->y * xAxis->z) - (zAxis->z * xAxis->y));
		HX_STACK_LINE(534)
		yAxis->y = ((zAxis->z * xAxis->x) - (zAxis->x * xAxis->z));
		HX_STACK_LINE(534)
		yAxis->z = ((zAxis->x * xAxis->y) - (zAxis->y * xAxis->x));
	}
	HX_STACK_LINE(535)
	{
		HX_STACK_LINE(535)
		Float len = ::Math_obj::sqrt((((yAxis->x * yAxis->x) + (yAxis->y * yAxis->y)) + (yAxis->z * yAxis->z)));		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(535)
		if (((len != (int)0))){
			HX_STACK_LINE(535)
			Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
			HX_STACK_LINE(535)
			hx::MultEq(yAxis->x,num);
			HX_STACK_LINE(535)
			hx::MultEq(yAxis->y,num);
			HX_STACK_LINE(535)
			hx::MultEq(yAxis->z,num);
		}
	}
	HX_STACK_LINE(538)
	Float ex = -(((((xAxis->x * eye->x) + (xAxis->y * eye->y)) + (xAxis->z * eye->z))));		HX_STACK_VAR(ex,"ex");
	HX_STACK_LINE(539)
	Float ey = -(((((yAxis->x * eye->x) + (yAxis->y * eye->y)) + (yAxis->z * eye->z))));		HX_STACK_VAR(ey,"ey");
	HX_STACK_LINE(540)
	Float ez = -(((((zAxis->x * eye->x) + (zAxis->y * eye->y)) + (zAxis->z * eye->z))));		HX_STACK_VAR(ez,"ez");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ::com::engine::math::Matrix &result,Float &ez,::com::engine::math::Vector3 &zAxis,Float &ey,::com::engine::math::Vector3 &yAxis,Float &ex,::com::engine::math::Vector3 &xAxis){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",542);
			{
				HX_STACK_LINE(542)
				result->m[(int)0] = xAxis->x;
				HX_STACK_LINE(542)
				result->m[(int)1] = yAxis->x;
				HX_STACK_LINE(542)
				result->m[(int)2] = zAxis->x;
				HX_STACK_LINE(542)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(542)
				result->m[(int)4] = xAxis->y;
				HX_STACK_LINE(542)
				result->m[(int)5] = yAxis->y;
				HX_STACK_LINE(542)
				result->m[(int)6] = zAxis->y;
				HX_STACK_LINE(542)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(542)
				result->m[(int)8] = xAxis->z;
				HX_STACK_LINE(542)
				result->m[(int)9] = yAxis->z;
				HX_STACK_LINE(542)
				result->m[(int)10] = zAxis->z;
				HX_STACK_LINE(542)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(542)
				result->m[(int)12] = ex;
				HX_STACK_LINE(542)
				result->m[(int)13] = ey;
				HX_STACK_LINE(542)
				result->m[(int)14] = ez;
				HX_STACK_LINE(542)
				result->m[(int)15] = (int)1;
				HX_STACK_LINE(545)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(542)
	return _Function_1_1::Block(result,ez,zAxis,ey,yAxis,ex,xAxis);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,LookAtLHToRef,return )

::com::engine::math::Matrix Matrix_obj::OrthoLH( Float width,Float height,Float znear,Float zfar){
	HX_STACK_PUSH("Matrix::OrthoLH","com/engine/math/Matrix.hx",548);
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(height,"height");
	HX_STACK_ARG(znear,"znear");
	HX_STACK_ARG(zfar,"zfar");
	HX_STACK_LINE(549)
	Float hw = (Float(2.0) / Float(width));		HX_STACK_VAR(hw,"hw");
	HX_STACK_LINE(550)
	Float hh = (Float(2.0) / Float(height));		HX_STACK_VAR(hh,"hh");
	HX_STACK_LINE(551)
	Float id = (Float(1.0) / Float(((zfar - znear))));		HX_STACK_VAR(id,"id");
	HX_STACK_LINE(552)
	Float nid = (Float(znear) / Float(((znear - zfar))));		HX_STACK_VAR(nid,"nid");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( Float &hw,Float &hh,Float &id,Float &nid){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",554);
			{
				HX_STACK_LINE(554)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(554)
				result->m[(int)0] = hw;
				HX_STACK_LINE(554)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)5] = hh;
				HX_STACK_LINE(554)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)10] = id;
				HX_STACK_LINE(554)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(554)
				result->m[(int)14] = nid;
				HX_STACK_LINE(554)
				result->m[(int)15] = (int)1;
				HX_STACK_LINE(554)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(554)
	return _Function_1_1::Block(hw,hh,id,nid);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,OrthoLH,return )

::com::engine::math::Matrix Matrix_obj::OrthoOffCenterLH( Float left,Float right,Float bottom,Float top,Float znear,Float zfar){
	HX_STACK_PUSH("Matrix::OrthoOffCenterLH","com/engine/math/Matrix.hx",562);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_ARG(bottom,"bottom");
	HX_STACK_ARG(top,"top");
	HX_STACK_ARG(znear,"znear");
	HX_STACK_ARG(zfar,"zfar");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",563);
			{
				HX_STACK_LINE(563)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(563)
				result->m[(int)0] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)5] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)10] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(563)
				result->m[(int)15] = (int)0;
				HX_STACK_LINE(563)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(563)
	::com::engine::math::Matrix matrix = _Function_1_1::Block();		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(564)
	{
		HX_STACK_LINE(564)
		matrix->m[(int)0] = (Float(2.0) / Float(((right - left))));
		HX_STACK_LINE(564)
		matrix->m[(int)1] = matrix->m[(int)2] = matrix->m[(int)3] = matrix->m[(int)4] = (int)0;
		HX_STACK_LINE(564)
		matrix->m[(int)5] = (Float(2.0) / Float(((top - bottom))));
		HX_STACK_LINE(564)
		matrix->m[(int)6] = matrix->m[(int)7] = (int)0;
		HX_STACK_LINE(564)
		matrix->m[(int)8] = matrix->m[(int)9] = (int)0;
		HX_STACK_LINE(564)
		matrix->m[(int)10] = (Float((int)-1) / Float(((znear - zfar))));
		HX_STACK_LINE(564)
		matrix->m[(int)11] = (int)0;
		HX_STACK_LINE(564)
		matrix->m[(int)12] = (Float(((left + right))) / Float(((left - right))));
		HX_STACK_LINE(564)
		matrix->m[(int)13] = (Float(((top + bottom))) / Float(((bottom - top))));
		HX_STACK_LINE(564)
		matrix->m[(int)14] = (Float(znear) / Float(((znear - zfar))));
		HX_STACK_LINE(564)
		matrix->m[(int)15] = 1.0;
		HX_STACK_LINE(564)
		matrix;
	}
	HX_STACK_LINE(566)
	return matrix;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC6(Matrix_obj,OrthoOffCenterLH,return )

::com::engine::math::Matrix Matrix_obj::OrthoOffCenterLHToRef( Float left,Float right,Float bottom,Float top,Float znear,Float zfar,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::OrthoOffCenterLHToRef","com/engine/math/Matrix.hx",569);
	HX_STACK_ARG(left,"left");
	HX_STACK_ARG(right,"right");
	HX_STACK_ARG(bottom,"bottom");
	HX_STACK_ARG(top,"top");
	HX_STACK_ARG(znear,"znear");
	HX_STACK_ARG(zfar,"zfar");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(570)
	result->m[(int)0] = (Float(2.0) / Float(((right - left))));
	HX_STACK_LINE(571)
	result->m[(int)1] = result->m[(int)2] = result->m[(int)3] = result->m[(int)4] = (int)0;
	HX_STACK_LINE(572)
	result->m[(int)5] = (Float(2.0) / Float(((top - bottom))));
	HX_STACK_LINE(573)
	result->m[(int)6] = result->m[(int)7] = (int)0;
	HX_STACK_LINE(574)
	result->m[(int)8] = result->m[(int)9] = (int)0;
	HX_STACK_LINE(575)
	result->m[(int)10] = (Float((int)-1) / Float(((znear - zfar))));
	HX_STACK_LINE(576)
	result->m[(int)11] = (int)0;
	HX_STACK_LINE(577)
	result->m[(int)12] = (Float(((left + right))) / Float(((left - right))));
	HX_STACK_LINE(578)
	result->m[(int)13] = (Float(((top + bottom))) / Float(((bottom - top))));
	HX_STACK_LINE(579)
	result->m[(int)14] = (Float(znear) / Float(((znear - zfar))));
	HX_STACK_LINE(580)
	result->m[(int)15] = 1.0;
	HX_STACK_LINE(583)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Matrix_obj,OrthoOffCenterLHToRef,return )

::com::engine::math::Matrix Matrix_obj::PerspectiveLH( Float width,Float height,Float znear,Float zfar){
	HX_STACK_PUSH("Matrix::PerspectiveLH","com/engine/math/Matrix.hx",586);
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(height,"height");
	HX_STACK_ARG(znear,"znear");
	HX_STACK_ARG(zfar,"zfar");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",587);
			{
				HX_STACK_LINE(587)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(587)
				result->m[(int)0] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)5] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)10] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(587)
				result->m[(int)15] = (int)0;
				HX_STACK_LINE(587)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(587)
	::com::engine::math::Matrix matrix = _Function_1_1::Block();		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(589)
	matrix->m[(int)0] = (Float((2.0 * znear)) / Float(width));
	HX_STACK_LINE(590)
	matrix->m[(int)1] = matrix->m[(int)2] = matrix->m[(int)3] = 0.0;
	HX_STACK_LINE(591)
	matrix->m[(int)5] = (Float((2.0 * znear)) / Float(height));
	HX_STACK_LINE(592)
	matrix->m[(int)4] = matrix->m[(int)6] = matrix->m[(int)7] = 0.0;
	HX_STACK_LINE(593)
	matrix->m[(int)10] = (Float(-(zfar)) / Float(((znear - zfar))));
	HX_STACK_LINE(594)
	matrix->m[(int)8] = matrix->m[(int)9] = 0.0;
	HX_STACK_LINE(595)
	matrix->m[(int)11] = 1.0;
	HX_STACK_LINE(596)
	matrix->m[(int)12] = matrix->m[(int)13] = matrix->m[(int)15] = 0.0;
	HX_STACK_LINE(597)
	matrix->m[(int)14] = (Float((znear * zfar)) / Float(((znear - zfar))));
	HX_STACK_LINE(599)
	return matrix;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,PerspectiveLH,return )

::com::engine::math::Matrix Matrix_obj::PerspectiveFovLH( Float fov,Float aspect,Float znear,Float zfar){
	HX_STACK_PUSH("Matrix::PerspectiveFovLH","com/engine/math/Matrix.hx",602);
	HX_STACK_ARG(fov,"fov");
	HX_STACK_ARG(aspect,"aspect");
	HX_STACK_ARG(znear,"znear");
	HX_STACK_ARG(zfar,"zfar");
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",603);
			{
				HX_STACK_LINE(603)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(603)
				result->m[(int)0] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)5] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)10] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(603)
				result->m[(int)15] = (int)0;
				HX_STACK_LINE(603)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(603)
	::com::engine::math::Matrix matrix = _Function_1_1::Block();		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(604)
	{
		HX_STACK_LINE(604)
		Float tan = (Float(1.0) / Float(::Math_obj::tan((fov * 0.5))));		HX_STACK_VAR(tan,"tan");
		HX_STACK_LINE(604)
		matrix->m[(int)0] = (Float(tan) / Float(aspect));
		HX_STACK_LINE(604)
		matrix->m[(int)1] = matrix->m[(int)2] = matrix->m[(int)3] = 0.0;
		HX_STACK_LINE(604)
		matrix->m[(int)5] = tan;
		HX_STACK_LINE(604)
		matrix->m[(int)4] = matrix->m[(int)6] = matrix->m[(int)7] = 0.0;
		HX_STACK_LINE(604)
		matrix->m[(int)8] = matrix->m[(int)9] = 0.0;
		HX_STACK_LINE(604)
		matrix->m[(int)10] = (Float(-(zfar)) / Float(((znear - zfar))));
		HX_STACK_LINE(604)
		matrix->m[(int)11] = 1.0;
		HX_STACK_LINE(604)
		matrix->m[(int)12] = matrix->m[(int)13] = matrix->m[(int)15] = 0.0;
		HX_STACK_LINE(604)
		matrix->m[(int)14] = (Float((znear * zfar)) / Float(((znear - zfar))));
		HX_STACK_LINE(604)
		matrix;
	}
	HX_STACK_LINE(606)
	return matrix;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,PerspectiveFovLH,return )

::com::engine::math::Matrix Matrix_obj::PerspectiveFovLHToRef( Float fov,Float aspect,Float znear,Float zfar,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::PerspectiveFovLHToRef","com/engine/math/Matrix.hx",609);
	HX_STACK_ARG(fov,"fov");
	HX_STACK_ARG(aspect,"aspect");
	HX_STACK_ARG(znear,"znear");
	HX_STACK_ARG(zfar,"zfar");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(610)
	Float tan = (Float(1.0) / Float(::Math_obj::tan((fov * 0.5))));		HX_STACK_VAR(tan,"tan");
	HX_STACK_LINE(612)
	result->m[(int)0] = (Float(tan) / Float(aspect));
	HX_STACK_LINE(613)
	result->m[(int)1] = result->m[(int)2] = result->m[(int)3] = 0.0;
	HX_STACK_LINE(614)
	result->m[(int)5] = tan;
	HX_STACK_LINE(615)
	result->m[(int)4] = result->m[(int)6] = result->m[(int)7] = 0.0;
	HX_STACK_LINE(616)
	result->m[(int)8] = result->m[(int)9] = 0.0;
	HX_STACK_LINE(617)
	result->m[(int)10] = (Float(-(zfar)) / Float(((znear - zfar))));
	HX_STACK_LINE(618)
	result->m[(int)11] = 1.0;
	HX_STACK_LINE(619)
	result->m[(int)12] = result->m[(int)13] = result->m[(int)15] = 0.0;
	HX_STACK_LINE(620)
	result->m[(int)14] = (Float((znear * zfar)) / Float(((znear - zfar))));
	HX_STACK_LINE(622)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC5(Matrix_obj,PerspectiveFovLHToRef,return )

::com::engine::math::Matrix Matrix_obj::Transpose( ::com::engine::math::Matrix matrix){
	HX_STACK_PUSH("Matrix::Transpose","com/engine/math/Matrix.hx",643);
	HX_STACK_ARG(matrix,"matrix");
	HX_STACK_LINE(644)
	::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(646)
	result->m[(int)0] = matrix->m->__get((int)0);
	HX_STACK_LINE(647)
	result->m[(int)1] = matrix->m->__get((int)4);
	HX_STACK_LINE(648)
	result->m[(int)2] = matrix->m->__get((int)8);
	HX_STACK_LINE(649)
	result->m[(int)3] = matrix->m->__get((int)12);
	HX_STACK_LINE(651)
	result->m[(int)4] = matrix->m->__get((int)1);
	HX_STACK_LINE(652)
	result->m[(int)5] = matrix->m->__get((int)5);
	HX_STACK_LINE(653)
	result->m[(int)6] = matrix->m->__get((int)9);
	HX_STACK_LINE(654)
	result->m[(int)7] = matrix->m->__get((int)13);
	HX_STACK_LINE(656)
	result->m[(int)8] = matrix->m->__get((int)2);
	HX_STACK_LINE(657)
	result->m[(int)9] = matrix->m->__get((int)6);
	HX_STACK_LINE(658)
	result->m[(int)10] = matrix->m->__get((int)10);
	HX_STACK_LINE(659)
	result->m[(int)11] = matrix->m->__get((int)14);
	HX_STACK_LINE(661)
	result->m[(int)12] = matrix->m->__get((int)3);
	HX_STACK_LINE(662)
	result->m[(int)13] = matrix->m->__get((int)7);
	HX_STACK_LINE(663)
	result->m[(int)14] = matrix->m->__get((int)11);
	HX_STACK_LINE(664)
	result->m[(int)15] = matrix->m->__get((int)15);
	HX_STACK_LINE(666)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,Transpose,return )

::com::engine::math::Matrix Matrix_obj::Reflection( ::com::engine::math::Plane plane){
	HX_STACK_PUSH("Matrix::Reflection","com/engine/math/Matrix.hx",669);
	HX_STACK_ARG(plane,"plane");
	HX_STACK_LINE(670)
	::com::engine::math::Matrix matrix = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(matrix,"matrix");
	HX_STACK_LINE(671)
	{
		HX_STACK_LINE(671)
		{
			HX_STACK_LINE(671)
			Float norm = ::Math_obj::sqrt((((plane->normal->x * plane->normal->x) + (plane->normal->y * plane->normal->y)) + (plane->normal->z * plane->normal->z)));		HX_STACK_VAR(norm,"norm");
			HX_STACK_LINE(671)
			Float magnitude = (int)0;		HX_STACK_VAR(magnitude,"magnitude");
			HX_STACK_LINE(671)
			if (((norm != (int)0))){
				HX_STACK_LINE(671)
				magnitude = (Float(1.0) / Float(norm));
			}
			HX_STACK_LINE(671)
			hx::MultEq(plane->normal->x,magnitude);
			HX_STACK_LINE(671)
			hx::MultEq(plane->normal->y,magnitude);
			HX_STACK_LINE(671)
			hx::MultEq(plane->normal->z,magnitude);
			HX_STACK_LINE(671)
			hx::MultEq(plane->d,magnitude);
		}
		HX_STACK_LINE(671)
		Float x = plane->normal->x;		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(671)
		Float y = plane->normal->y;		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(671)
		Float z = plane->normal->z;		HX_STACK_VAR(z,"z");
		HX_STACK_LINE(671)
		Float temp = ((int)-2 * x);		HX_STACK_VAR(temp,"temp");
		HX_STACK_LINE(671)
		Float temp2 = ((int)-2 * y);		HX_STACK_VAR(temp2,"temp2");
		HX_STACK_LINE(671)
		Float temp3 = ((int)-2 * z);		HX_STACK_VAR(temp3,"temp3");
		HX_STACK_LINE(671)
		matrix->m[(int)0] = ((temp * x) + (int)1);
		HX_STACK_LINE(671)
		matrix->m[(int)1] = (temp2 * x);
		HX_STACK_LINE(671)
		matrix->m[(int)2] = (temp3 * x);
		HX_STACK_LINE(671)
		matrix->m[(int)3] = 0.0;
		HX_STACK_LINE(671)
		matrix->m[(int)4] = (temp * y);
		HX_STACK_LINE(671)
		matrix->m[(int)5] = ((temp2 * y) + (int)1);
		HX_STACK_LINE(671)
		matrix->m[(int)6] = (temp3 * y);
		HX_STACK_LINE(671)
		matrix->m[(int)7] = 0.0;
		HX_STACK_LINE(671)
		matrix->m[(int)8] = (temp * z);
		HX_STACK_LINE(671)
		matrix->m[(int)9] = (temp2 * z);
		HX_STACK_LINE(671)
		matrix->m[(int)10] = ((temp3 * z) + (int)1);
		HX_STACK_LINE(671)
		matrix->m[(int)11] = 0.0;
		HX_STACK_LINE(671)
		matrix->m[(int)12] = (temp * plane->d);
		HX_STACK_LINE(671)
		matrix->m[(int)13] = (temp2 * plane->d);
		HX_STACK_LINE(671)
		matrix->m[(int)14] = (temp3 * plane->d);
		HX_STACK_LINE(671)
		matrix->m[(int)15] = 1.0;
		HX_STACK_LINE(671)
		matrix;
	}
	HX_STACK_LINE(673)
	return matrix;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Matrix_obj,Reflection,return )

::com::engine::math::Matrix Matrix_obj::create2D( Float x,Float y,hx::Null< Float >  __o_scale,hx::Null< Float >  __o_rotation){
Float scale = __o_scale.Default(1);
Float rotation = __o_rotation.Default(0);
	HX_STACK_PUSH("Matrix::create2D","com/engine/math/Matrix.hx",677);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(scale,"scale");
	HX_STACK_ARG(rotation,"rotation");
{
		HX_STACK_LINE(678)
		Float theta = (Float((rotation * ::Math_obj::PI)) / Float(180.0));		HX_STACK_VAR(theta,"theta");
		HX_STACK_LINE(679)
		Float c = ::Math_obj::cos(theta);		HX_STACK_VAR(c,"c");
		HX_STACK_LINE(680)
		Float s = ::Math_obj::sin(theta);		HX_STACK_VAR(s,"s");
		struct _Function_1_1{
			inline static ::com::engine::math::Matrix Block( Float &scale,Float &s,Float &y,Float &c,Float &x){
				HX_STACK_PUSH("*::closure","com/engine/math/Matrix.hx",682);
				{
					HX_STACK_LINE(682)
					Array< Float > array = Array_obj< Float >::__new().Add((c * scale)).Add((-(s) * scale)).Add((int)0).Add((int)0).Add((s * scale)).Add((c * scale)).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add(x).Add(y).Add((int)0).Add((int)1);		HX_STACK_VAR(array,"array");
					int offset = (int)0;		HX_STACK_VAR(offset,"offset");
					HX_STACK_LINE(682)
					::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
					HX_STACK_LINE(682)
					{
						HX_STACK_LINE(682)
						{
							HX_STACK_LINE(682)
							int _g = (int)0;		HX_STACK_VAR(_g,"_g");
							HX_STACK_LINE(682)
							while(((_g < (int)16))){
								HX_STACK_LINE(682)
								int index = (_g)++;		HX_STACK_VAR(index,"index");
								HX_STACK_LINE(682)
								result->m[index] = array->__get((index + offset));
							}
						}
						HX_STACK_LINE(682)
						result;
					}
					HX_STACK_LINE(682)
					return result;
				}
				return null();
			}
		};
		HX_STACK_LINE(682)
		return _Function_1_1::Block(scale,s,y,c,x);
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Matrix_obj,create2D,return )

::com::engine::math::Matrix Matrix_obj::ReflectionToRef( ::com::engine::math::Plane plane,::com::engine::math::Matrix result){
	HX_STACK_PUSH("Matrix::ReflectionToRef","com/engine/math/Matrix.hx",697);
	HX_STACK_ARG(plane,"plane");
	HX_STACK_ARG(result,"result");
	HX_STACK_LINE(698)
	{
		HX_STACK_LINE(698)
		Float norm = ::Math_obj::sqrt((((plane->normal->x * plane->normal->x) + (plane->normal->y * plane->normal->y)) + (plane->normal->z * plane->normal->z)));		HX_STACK_VAR(norm,"norm");
		HX_STACK_LINE(698)
		Float magnitude = (int)0;		HX_STACK_VAR(magnitude,"magnitude");
		HX_STACK_LINE(698)
		if (((norm != (int)0))){
			HX_STACK_LINE(698)
			magnitude = (Float(1.0) / Float(norm));
		}
		HX_STACK_LINE(698)
		hx::MultEq(plane->normal->x,magnitude);
		HX_STACK_LINE(698)
		hx::MultEq(plane->normal->y,magnitude);
		HX_STACK_LINE(698)
		hx::MultEq(plane->normal->z,magnitude);
		HX_STACK_LINE(698)
		hx::MultEq(plane->d,magnitude);
	}
	HX_STACK_LINE(699)
	Float x = plane->normal->x;		HX_STACK_VAR(x,"x");
	HX_STACK_LINE(700)
	Float y = plane->normal->y;		HX_STACK_VAR(y,"y");
	HX_STACK_LINE(701)
	Float z = plane->normal->z;		HX_STACK_VAR(z,"z");
	HX_STACK_LINE(702)
	Float temp = ((int)-2 * x);		HX_STACK_VAR(temp,"temp");
	HX_STACK_LINE(703)
	Float temp2 = ((int)-2 * y);		HX_STACK_VAR(temp2,"temp2");
	HX_STACK_LINE(704)
	Float temp3 = ((int)-2 * z);		HX_STACK_VAR(temp3,"temp3");
	HX_STACK_LINE(705)
	result->m[(int)0] = ((temp * x) + (int)1);
	HX_STACK_LINE(706)
	result->m[(int)1] = (temp2 * x);
	HX_STACK_LINE(707)
	result->m[(int)2] = (temp3 * x);
	HX_STACK_LINE(708)
	result->m[(int)3] = 0.0;
	HX_STACK_LINE(709)
	result->m[(int)4] = (temp * y);
	HX_STACK_LINE(710)
	result->m[(int)5] = ((temp2 * y) + (int)1);
	HX_STACK_LINE(711)
	result->m[(int)6] = (temp3 * y);
	HX_STACK_LINE(712)
	result->m[(int)7] = 0.0;
	HX_STACK_LINE(713)
	result->m[(int)8] = (temp * z);
	HX_STACK_LINE(714)
	result->m[(int)9] = (temp2 * z);
	HX_STACK_LINE(715)
	result->m[(int)10] = ((temp3 * z) + (int)1);
	HX_STACK_LINE(716)
	result->m[(int)11] = 0.0;
	HX_STACK_LINE(717)
	result->m[(int)12] = (temp * plane->d);
	HX_STACK_LINE(718)
	result->m[(int)13] = (temp2 * plane->d);
	HX_STACK_LINE(719)
	result->m[(int)14] = (temp3 * plane->d);
	HX_STACK_LINE(720)
	result->m[(int)15] = 1.0;
	HX_STACK_LINE(722)
	return result;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Matrix_obj,ReflectionToRef,return )


Matrix_obj::Matrix_obj()
{
}

void Matrix_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Matrix);
	HX_MARK_MEMBER_NAME(m,"m");
	HX_MARK_END_CLASS();
}

void Matrix_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(m,"m");
}

Dynamic Matrix_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"m") ) { return m; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"Zero") ) { return Zero_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clone") ) { return clone_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"equals") ) { return equals_dyn(); }
		if (HX_FIELD_EQ(inName,"invert") ) { return invert_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Scaling") ) { return Scaling_dyn(); }
		if (HX_FIELD_EQ(inName,"OrthoLH") ) { return OrthoLH_dyn(); }
		if (HX_FIELD_EQ(inName,"toArray") ) { return toArray_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Identity") ) { return Identity_dyn(); }
		if (HX_FIELD_EQ(inName,"LookAtLH") ) { return LookAtLH_dyn(); }
		if (HX_FIELD_EQ(inName,"create2D") ) { return create2D_dyn(); }
		if (HX_FIELD_EQ(inName,"copyFrom") ) { return copyFrom_dyn(); }
		if (HX_FIELD_EQ(inName,"multiply") ) { return multiply_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"FromArray") ) { return FromArray_dyn(); }
		if (HX_FIELD_EQ(inName,"RotationX") ) { return RotationX_dyn(); }
		if (HX_FIELD_EQ(inName,"RotationY") ) { return RotationY_dyn(); }
		if (HX_FIELD_EQ(inName,"RotationZ") ) { return RotationZ_dyn(); }
		if (HX_FIELD_EQ(inName,"Transpose") ) { return Transpose_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"FromValues") ) { return FromValues_dyn(); }
		if (HX_FIELD_EQ(inName,"Reflection") ) { return Reflection_dyn(); }
		if (HX_FIELD_EQ(inName,"isIdentity") ) { return isIdentity_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"Translation") ) { return Translation_dyn(); }
		if (HX_FIELD_EQ(inName,"invertToRef") ) { return invertToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"determinant") ) { return determinant_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"RotationAxis") ) { return RotationAxis_dyn(); }
		if (HX_FIELD_EQ(inName,"ScalingToRef") ) { return ScalingToRef_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"IdentityToRef") ) { return IdentityToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"LookAtLHToRef") ) { return LookAtLHToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"PerspectiveLH") ) { return PerspectiveLH_dyn(); }
		if (HX_FIELD_EQ(inName,"multiplyToRef") ) { return multiplyToRef_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"FromArrayToRef") ) { return FromArrayToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"RotationXToRef") ) { return RotationXToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"RotationYToRef") ) { return RotationYToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"RotationZToRef") ) { return RotationZToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"setTranslation") ) { return setTranslation_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"FromValuesToRef") ) { return FromValuesToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"ReflectionToRef") ) { return ReflectionToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"multiplyToArray") ) { return multiplyToArray_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"TranslationToRef") ) { return TranslationToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"OrthoOffCenterLH") ) { return OrthoOffCenterLH_dyn(); }
		if (HX_FIELD_EQ(inName,"PerspectiveFovLH") ) { return PerspectiveFovLH_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"MatrixMultiply4x4") ) { return MatrixMultiply4x4_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"RotationYawPitchRoll") ) { return RotationYawPitchRoll_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"OrthoOffCenterLHToRef") ) { return OrthoOffCenterLHToRef_dyn(); }
		if (HX_FIELD_EQ(inName,"PerspectiveFovLHToRef") ) { return PerspectiveFovLHToRef_dyn(); }
		break;
	case 25:
		if (HX_FIELD_EQ(inName,"RotationYawPitchRollToRef") ) { return RotationYawPitchRollToRef_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Matrix_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"m") ) { m=inValue.Cast< Array< Float > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Matrix_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("m"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("MatrixMultiply4x4"),
	HX_CSTRING("FromArray"),
	HX_CSTRING("FromArrayToRef"),
	HX_CSTRING("FromValues"),
	HX_CSTRING("FromValuesToRef"),
	HX_CSTRING("Identity"),
	HX_CSTRING("IdentityToRef"),
	HX_CSTRING("Zero"),
	HX_CSTRING("RotationX"),
	HX_CSTRING("RotationXToRef"),
	HX_CSTRING("RotationY"),
	HX_CSTRING("RotationYToRef"),
	HX_CSTRING("RotationZ"),
	HX_CSTRING("RotationZToRef"),
	HX_CSTRING("RotationAxis"),
	HX_CSTRING("RotationYawPitchRoll"),
	HX_CSTRING("RotationYawPitchRollToRef"),
	HX_CSTRING("Scaling"),
	HX_CSTRING("ScalingToRef"),
	HX_CSTRING("Translation"),
	HX_CSTRING("TranslationToRef"),
	HX_CSTRING("LookAtLH"),
	HX_CSTRING("LookAtLHToRef"),
	HX_CSTRING("OrthoLH"),
	HX_CSTRING("OrthoOffCenterLH"),
	HX_CSTRING("OrthoOffCenterLHToRef"),
	HX_CSTRING("PerspectiveLH"),
	HX_CSTRING("PerspectiveFovLH"),
	HX_CSTRING("PerspectiveFovLHToRef"),
	HX_CSTRING("Transpose"),
	HX_CSTRING("Reflection"),
	HX_CSTRING("create2D"),
	HX_CSTRING("ReflectionToRef"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("clone"),
	HX_CSTRING("equals"),
	HX_CSTRING("multiplyToArray"),
	HX_CSTRING("multiplyToRef"),
	HX_CSTRING("copyFrom"),
	HX_CSTRING("multiply"),
	HX_CSTRING("setTranslation"),
	HX_CSTRING("invertToRef"),
	HX_CSTRING("invert"),
	HX_CSTRING("toArray"),
	HX_CSTRING("determinant"),
	HX_CSTRING("isIdentity"),
	HX_CSTRING("m"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Matrix_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Matrix_obj::__mClass,"__mClass");
};

Class Matrix_obj::__mClass;

void Matrix_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.math.Matrix"), hx::TCanCast< Matrix_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Matrix_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace math
