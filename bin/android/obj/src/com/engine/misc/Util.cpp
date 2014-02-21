#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_engine_misc_Util
#include <com/engine/misc/Util.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace engine{
namespace misc{

Void Util_obj::__construct()
{
	return null();
}

Util_obj::~Util_obj() { }

Dynamic Util_obj::__CreateEmpty() { return  new Util_obj; }
hx::ObjectPtr< Util_obj > Util_obj::__new()
{  hx::ObjectPtr< Util_obj > result = new Util_obj();
	result->__construct();
	return result;}

Dynamic Util_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Util_obj > result = new Util_obj();
	result->__construct();
	return result;}

int Util_obj::getExponantOfTwo( int value,int max){
	HX_STACK_PUSH("Util::getExponantOfTwo","com/engine/misc/Util.hx",75);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_ARG(max,"max");
	HX_STACK_LINE(76)
	int count = (int)1;		HX_STACK_VAR(count,"count");
	HX_STACK_LINE(78)
	do{
		HX_STACK_LINE(78)
		hx::MultEq(count,(int)2);
	}
while(((count < value)));
	HX_STACK_LINE(82)
	if (((count > max))){
		HX_STACK_LINE(83)
		count = max;
	}
	HX_STACK_LINE(85)
	return count;
}


HX_DEFINE_DYNAMIC_FUNC2(Util_obj,getExponantOfTwo,return )

Float Util_obj::rad2deg( Float rad){
	HX_STACK_PUSH("Util::rad2deg","com/engine/misc/Util.hx",50);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rad,"rad");
	HX_STACK_LINE(50)
	return ((Float(rad) / Float(::Math_obj::PI)) * 180.0);
}


HX_DEFINE_DYNAMIC_FUNC1(Util_obj,rad2deg,return )

Float Util_obj::DEG;

Float Util_obj::RAD;

Float Util_obj::EPSILON;

Float Util_obj::randf( Float max,Float min){
	HX_STACK_PUSH("Util::randf","com/engine/misc/Util.hx",22);
	HX_STACK_ARG(max,"max");
	HX_STACK_ARG(min,"min");
	HX_STACK_LINE(22)
	return ((::Math_obj::random() * ((max - min))) + min);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,randf,return )

int Util_obj::randi( int max,int min){
	HX_STACK_PUSH("Util::randi","com/engine/misc/Util.hx",26);
	HX_STACK_ARG(max,"max");
	HX_STACK_ARG(min,"min");
	HX_STACK_LINE(26)
	return ::Std_obj::_int(((::Math_obj::random() * ((max - min))) + min));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,randi,return )

bool Util_obj::WithinEpsilon( Float a,Float b){
	HX_STACK_PUSH("Util::WithinEpsilon","com/engine/misc/Util.hx",31);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(32)
	Float num = (a - b);		HX_STACK_VAR(num,"num");
	HX_STACK_LINE(33)
	return (bool((-1.401298e-045 <= num)) && bool((num <= 1.401298E-45)));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,WithinEpsilon,return )

Float Util_obj::getColorValue( int color){
	HX_STACK_PUSH("Util::getColorValue","com/engine/misc/Util.hx",36);
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(37)
	int h = (int((int(color) >> int((int)16))) & int((int)255));		HX_STACK_VAR(h,"h");
	HX_STACK_LINE(38)
	int s = (int((int(color) >> int((int)8))) & int((int)255));		HX_STACK_VAR(s,"s");
	HX_STACK_LINE(39)
	int v = (int(color) & int((int)255));		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(41)
	return (Float(::Std_obj::_int(::Math_obj::max(h,::Math_obj::max(s,v)))) / Float((int)255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,getColorValue,return )

Float Util_obj::deg2rad( Float deg){
	HX_STACK_PUSH("Util::deg2rad","com/engine/misc/Util.hx",46);
	HX_STACK_ARG(deg,"deg");
	HX_STACK_LINE(46)
	return ((Float(deg) / Float(180.0)) * ::Math_obj::PI);
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,deg2rad,return )

Void Util_obj::print( Dynamic s){
{
		HX_STACK_PUSH("Util::print","com/engine/misc/Util.hx",57);
		HX_STACK_ARG(s,"s");
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,print,(void))

Dynamic Util_obj::deepCopy( Dynamic arr){
	HX_STACK_PUSH("Util::deepCopy","com/engine/misc/Util.hx",62);
	HX_STACK_ARG(arr,"arr");
	HX_STACK_LINE(63)
	Dynamic r = Dynamic( Array_obj<Dynamic>::__new() );		HX_STACK_VAR(r,"r");
	HX_STACK_LINE(64)
	{
		HX_STACK_LINE(64)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = arr->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(64)
		while(((_g1 < _g))){
			HX_STACK_LINE(64)
			int i = (_g1)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(65)
			r->__Field(HX_CSTRING("push"),true)(::com::engine::misc::Util_obj::copy(arr->__GetItem(i)));
		}
	}
	HX_STACK_LINE(66)
	return r;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,deepCopy,return )

Dynamic Util_obj::copy( Dynamic value){
	HX_STACK_PUSH("Util::copy","com/engine/misc/Util.hx",69);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(69)
	if ((::Std_obj::is(value,hx::ClassOf< Array<int> >()))){
		HX_STACK_LINE(71)
		return ::com::engine::misc::Util_obj::deepCopy(value);
	}
	else{
		HX_STACK_LINE(73)
		return value;
	}
	HX_STACK_LINE(69)
	return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,copy,return )

int Util_obj::getNextPowerOfTwo( int number){
	HX_STACK_PUSH("Util::getNextPowerOfTwo","com/engine/misc/Util.hx",89);
	HX_STACK_ARG(number,"number");
	HX_STACK_LINE(89)
	if (((bool((number > (int)0)) && bool((((int(number) & int((number - (int)1)))) == (int)0))))){
		HX_STACK_LINE(91)
		return number;
	}
	else{
		HX_STACK_LINE(94)
		int result = (int)1;		HX_STACK_VAR(result,"result");
		HX_STACK_LINE(95)
		while(((result < number))){
			HX_STACK_LINE(95)
			hx::ShlEq(result,(int)1);
		}
		HX_STACK_LINE(96)
		return result;
	}
	HX_STACK_LINE(89)
	return (int)0;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,getNextPowerOfTwo,return )


Util_obj::Util_obj()
{
}

void Util_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Util);
	HX_MARK_END_CLASS();
}

void Util_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic Util_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"DEG") ) { return DEG; }
		if (HX_FIELD_EQ(inName,"RAD") ) { return RAD; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"copy") ) { return copy_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"randf") ) { return randf_dyn(); }
		if (HX_FIELD_EQ(inName,"randi") ) { return randi_dyn(); }
		if (HX_FIELD_EQ(inName,"print") ) { return print_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EPSILON") ) { return EPSILON; }
		if (HX_FIELD_EQ(inName,"deg2rad") ) { return deg2rad_dyn(); }
		if (HX_FIELD_EQ(inName,"rad2deg") ) { return rad2deg_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"deepCopy") ) { return deepCopy_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"WithinEpsilon") ) { return WithinEpsilon_dyn(); }
		if (HX_FIELD_EQ(inName,"getColorValue") ) { return getColorValue_dyn(); }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"getExponantOfTwo") ) { return getExponantOfTwo_dyn(); }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"getNextPowerOfTwo") ) { return getNextPowerOfTwo_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Util_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"DEG") ) { DEG=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"RAD") ) { RAD=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EPSILON") ) { EPSILON=inValue.Cast< Float >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Util_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("DEG"),
	HX_CSTRING("RAD"),
	HX_CSTRING("EPSILON"),
	HX_CSTRING("randf"),
	HX_CSTRING("randi"),
	HX_CSTRING("WithinEpsilon"),
	HX_CSTRING("getColorValue"),
	HX_CSTRING("deg2rad"),
	HX_CSTRING("print"),
	HX_CSTRING("deepCopy"),
	HX_CSTRING("copy"),
	HX_CSTRING("getNextPowerOfTwo"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("getExponantOfTwo"),
	HX_CSTRING("rad2deg"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Util_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Util_obj::DEG,"DEG");
	HX_MARK_MEMBER_NAME(Util_obj::RAD,"RAD");
	HX_MARK_MEMBER_NAME(Util_obj::EPSILON,"EPSILON");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Util_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Util_obj::DEG,"DEG");
	HX_VISIT_MEMBER_NAME(Util_obj::RAD,"RAD");
	HX_VISIT_MEMBER_NAME(Util_obj::EPSILON,"EPSILON");
};

Class Util_obj::__mClass;

void Util_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.misc.Util"), hx::TCanCast< Util_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Util_obj::__boot()
{
	DEG= (Float((int)-180) / Float(::Math_obj::PI));
	RAD= (Float(::Math_obj::PI) / Float((int)-180));
	EPSILON= 0.00000001;
}

} // end namespace com
} // end namespace engine
} // end namespace misc
