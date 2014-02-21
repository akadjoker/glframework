#include <hxcpp.h>

#ifndef INCLUDED_com_engine_direct_Util
#include <com/engine/direct/Util.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace engine{
namespace direct{

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

Float Util_obj::EPSILON;

int Util_obj::WHITE;

int Util_obj::SILVER;

int Util_obj::GRAY;

int Util_obj::BLACK;

int Util_obj::RED;

int Util_obj::MAROON;

int Util_obj::YELLOW;

int Util_obj::OLIVE;

int Util_obj::LIME;

int Util_obj::GREEN;

int Util_obj::AQUA;

int Util_obj::TEAL;

int Util_obj::BLUE;

int Util_obj::NAVY;

int Util_obj::FUCHSIA;

int Util_obj::PURPLE;

Void Util_obj::matrixsetTo( ::flash::geom::Matrix matrix,Float aa,Float ba,Float ca,Float da,Float txa,Float tya){
{
		HX_STACK_PUSH("Util::matrixsetTo","com/engine/direct/Util.hx",31);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(aa,"aa");
		HX_STACK_ARG(ba,"ba");
		HX_STACK_ARG(ca,"ca");
		HX_STACK_ARG(da,"da");
		HX_STACK_ARG(txa,"txa");
		HX_STACK_ARG(tya,"tya");
		HX_STACK_LINE(32)
		matrix->a = aa;
		HX_STACK_LINE(33)
		matrix->b = ba;
		HX_STACK_LINE(34)
		matrix->c = ca;
		HX_STACK_LINE(35)
		matrix->d = da;
		HX_STACK_LINE(36)
		matrix->tx = txa;
		HX_STACK_LINE(37)
		matrix->ty = tya;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(Util_obj,matrixsetTo,(void))

Void Util_obj::skew( ::flash::geom::Matrix matrix,Float skewX,Float skewY){
{
		HX_STACK_PUSH("Util::skew","com/engine/direct/Util.hx",42);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(skewX,"skewX");
		HX_STACK_ARG(skewY,"skewY");
		HX_STACK_LINE(43)
		Float sinX = ::Math_obj::sin(skewX);		HX_STACK_VAR(sinX,"sinX");
		HX_STACK_LINE(44)
		Float cosX = ::Math_obj::cos(skewX);		HX_STACK_VAR(cosX,"cosX");
		HX_STACK_LINE(45)
		Float sinY = ::Math_obj::sin(skewY);		HX_STACK_VAR(sinY,"sinY");
		HX_STACK_LINE(46)
		Float cosY = ::Math_obj::cos(skewY);		HX_STACK_VAR(cosY,"cosY");
		HX_STACK_LINE(48)
		::com::engine::direct::Util_obj::matrixsetTo(matrix,((matrix->a * cosY) - (matrix->b * sinX)),((matrix->a * sinY) + (matrix->b * cosX)),((matrix->c * cosY) - (matrix->d * sinX)),((matrix->c * sinY) + (matrix->d * cosX)),((matrix->tx * cosY) - (matrix->ty * sinX)),((matrix->tx * sinY) + (matrix->ty * cosX)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,skew,(void))

bool Util_obj::isEquivalent( Float a,Float b,hx::Null< Float >  __o_epsilon){
Float epsilon = __o_epsilon.Default(0.0001);
	HX_STACK_PUSH("Util::isEquivalent","com/engine/direct/Util.hx",57);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(epsilon,"epsilon");
{
		HX_STACK_LINE(57)
		return (bool(((a - epsilon) < b)) && bool(((a + epsilon) > b)));
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,isEquivalent,return )

Float Util_obj::normalizeAngle( Float angle){
	HX_STACK_PUSH("Util::normalizeAngle","com/engine/direct/Util.hx",62);
	HX_STACK_ARG(angle,"angle");
	HX_STACK_LINE(64)
	while(((angle < -(::Math_obj::PI)))){
		HX_STACK_LINE(64)
		hx::AddEq(angle,(::Math_obj::PI * 2.0));
	}
	HX_STACK_LINE(65)
	while(((angle > ::Math_obj::PI))){
		HX_STACK_LINE(65)
		hx::SubEq(angle,(::Math_obj::PI * 2.0));
	}
	HX_STACK_LINE(66)
	return angle;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,normalizeAngle,return )

int Util_obj::getAlpha( int color){
	HX_STACK_PUSH("Util::getAlpha","com/engine/direct/Util.hx",69);
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(69)
	return (int((int(color) >> int((int)24))) & int((int)255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,getAlpha,return )

int Util_obj::getRed( int color){
	HX_STACK_PUSH("Util::getRed","com/engine/direct/Util.hx",70);
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(70)
	return (int((int(color) >> int((int)16))) & int((int)255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,getRed,return )

int Util_obj::getGreen( int color){
	HX_STACK_PUSH("Util::getGreen","com/engine/direct/Util.hx",71);
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(71)
	return (int((int(color) >> int((int)8))) & int((int)255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,getGreen,return )

int Util_obj::getBlue( int color){
	HX_STACK_PUSH("Util::getBlue","com/engine/direct/Util.hx",72);
	HX_STACK_ARG(color,"color");
	HX_STACK_LINE(72)
	return (int(color) & int((int)255));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC1(Util_obj,getBlue,return )

int Util_obj::rgb( int red,int green,int blue){
	HX_STACK_PUSH("Util::rgb","com/engine/direct/Util.hx",74);
	HX_STACK_ARG(red,"red");
	HX_STACK_ARG(green,"green");
	HX_STACK_ARG(blue,"blue");
	HX_STACK_LINE(74)
	return (int((int((int(red) << int((int)16))) | int((int(green) << int((int)8))))) | int(blue));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,rgb,return )

int Util_obj::argb( int alpha,int red,int green,int blue){
	HX_STACK_PUSH("Util::argb","com/engine/direct/Util.hx",78);
	HX_STACK_ARG(alpha,"alpha");
	HX_STACK_ARG(red,"red");
	HX_STACK_ARG(green,"green");
	HX_STACK_ARG(blue,"blue");
	HX_STACK_LINE(78)
	return (int((int((int((int(alpha) << int((int)24))) | int((int(red) << int((int)16))))) | int((int(green) << int((int)8))))) | int(blue));
}


STATIC_HX_DEFINE_DYNAMIC_FUNC4(Util_obj,argb,return )

::flash::geom::Rectangle Util_obj::intersect( ::flash::geom::Rectangle rect1,::flash::geom::Rectangle rect2,::flash::geom::Rectangle resultRect){
	HX_STACK_PUSH("Util::intersect","com/engine/direct/Util.hx",83);
	HX_STACK_ARG(rect1,"rect1");
	HX_STACK_ARG(rect2,"rect2");
	HX_STACK_ARG(resultRect,"resultRect");
	HX_STACK_LINE(84)
	if (((resultRect == null()))){
		HX_STACK_LINE(84)
		resultRect = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(86)
	Float left = (  (((rect1->x > rect2->x))) ? Float(rect1->x) : Float(rect2->x) );		HX_STACK_VAR(left,"left");
	HX_STACK_LINE(87)
	Float right = (  (((rect1->get_right() < rect2->get_right()))) ? Float(rect1->get_right()) : Float(rect2->get_right()) );		HX_STACK_VAR(right,"right");
	HX_STACK_LINE(88)
	Float top = (  (((rect1->y > rect2->y))) ? Float(rect1->y) : Float(rect2->y) );		HX_STACK_VAR(top,"top");
	HX_STACK_LINE(89)
	Float bottom = (  (((rect1->get_bottom() < rect2->get_bottom()))) ? Float(rect1->get_bottom()) : Float(rect2->get_bottom()) );		HX_STACK_VAR(bottom,"bottom");
	HX_STACK_LINE(91)
	if (((bool((left > right)) || bool((top > bottom))))){
		HX_STACK_LINE(92)
		resultRect->setEmpty();
	}
	HX_STACK_LINE(96)
	return resultRect;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,intersect,return )

::flash::geom::Rectangle Util_obj::fit( ::flash::geom::Rectangle rectangle,::flash::geom::Rectangle into,::flash::geom::Rectangle resultRect){
	HX_STACK_PUSH("Util::fit","com/engine/direct/Util.hx",101);
	HX_STACK_ARG(rectangle,"rectangle");
	HX_STACK_ARG(into,"into");
	HX_STACK_ARG(resultRect,"resultRect");
	HX_STACK_LINE(103)
	if (((resultRect == null()))){
		HX_STACK_LINE(103)
		resultRect = ::flash::geom::Rectangle_obj::__new(null(),null(),null(),null());
	}
	HX_STACK_LINE(105)
	Float width = rectangle->width;		HX_STACK_VAR(width,"width");
	HX_STACK_LINE(106)
	Float height = rectangle->height;		HX_STACK_VAR(height,"height");
	HX_STACK_LINE(107)
	Float factorX = (Float(into->width) / Float(width));		HX_STACK_VAR(factorX,"factorX");
	HX_STACK_LINE(108)
	Float factorY = (Float(into->height) / Float(height));		HX_STACK_VAR(factorY,"factorY");
	HX_STACK_LINE(109)
	Float factor = 1.0;		HX_STACK_VAR(factor,"factor");
	HX_STACK_LINE(112)
	hx::MultEq(width,factor);
	HX_STACK_LINE(113)
	hx::MultEq(height,factor);
	HX_STACK_LINE(120)
	return resultRect;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,fit,return )

Void Util_obj::setLength( Dynamic array,int newLength){
{
		HX_STACK_PUSH("Util::setLength","com/engine/direct/Util.hx",124);
		HX_STACK_ARG(array,"array");
		HX_STACK_ARG(newLength,"newLength");
		HX_STACK_LINE(125)
		if (((newLength < (int)0))){
			HX_STACK_LINE(125)
			return null();
		}
		HX_STACK_LINE(126)
		int oldLength = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(oldLength,"oldLength");
		HX_STACK_LINE(127)
		int diff = (newLength - oldLength);		HX_STACK_VAR(diff,"diff");
		HX_STACK_LINE(128)
		if (((diff < (int)0))){
			HX_STACK_LINE(133)
			diff = -(diff);
			HX_STACK_LINE(134)
			{
				HX_STACK_LINE(134)
				int _g = (int)0;		HX_STACK_VAR(_g,"_g");
				HX_STACK_LINE(134)
				while(((_g < diff))){
					HX_STACK_LINE(134)
					int i = (_g)++;		HX_STACK_VAR(i,"i");
					HX_STACK_LINE(136)
					array->__Field(HX_CSTRING("pop"),true)();
				}
			}
		}
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(Util_obj,setLength,(void))

int Util_obj::indexOf( Dynamic array,Dynamic whatToFind,hx::Null< int >  __o_fromIndex){
int fromIndex = __o_fromIndex.Default(0);
	HX_STACK_PUSH("Util::indexOf","com/engine/direct/Util.hx",142);
	HX_STACK_ARG(array,"array");
	HX_STACK_ARG(whatToFind,"whatToFind");
	HX_STACK_ARG(fromIndex,"fromIndex");
{
		HX_STACK_LINE(146)
		int index = (int)-1;		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(147)
		int len = array->__Field(HX_CSTRING("length"),true);		HX_STACK_VAR(len,"len");
		HX_STACK_LINE(148)
		{
			HX_STACK_LINE(148)
			int _g = fromIndex;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(148)
			while(((_g < len))){
				HX_STACK_LINE(148)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(150)
				if (((array->__GetItem(i) == whatToFind))){
					HX_STACK_LINE(152)
					index = i;
					HX_STACK_LINE(153)
					break;
				}
			}
		}
		HX_STACK_LINE(156)
		return index;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(Util_obj,indexOf,return )


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
		if (HX_FIELD_EQ(inName,"RED") ) { return RED; }
		if (HX_FIELD_EQ(inName,"rgb") ) { return rgb_dyn(); }
		if (HX_FIELD_EQ(inName,"fit") ) { return fit_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"GRAY") ) { return GRAY; }
		if (HX_FIELD_EQ(inName,"LIME") ) { return LIME; }
		if (HX_FIELD_EQ(inName,"AQUA") ) { return AQUA; }
		if (HX_FIELD_EQ(inName,"TEAL") ) { return TEAL; }
		if (HX_FIELD_EQ(inName,"BLUE") ) { return BLUE; }
		if (HX_FIELD_EQ(inName,"NAVY") ) { return NAVY; }
		if (HX_FIELD_EQ(inName,"skew") ) { return skew_dyn(); }
		if (HX_FIELD_EQ(inName,"argb") ) { return argb_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"WHITE") ) { return WHITE; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { return BLACK; }
		if (HX_FIELD_EQ(inName,"OLIVE") ) { return OLIVE; }
		if (HX_FIELD_EQ(inName,"GREEN") ) { return GREEN; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SILVER") ) { return SILVER; }
		if (HX_FIELD_EQ(inName,"MAROON") ) { return MAROON; }
		if (HX_FIELD_EQ(inName,"YELLOW") ) { return YELLOW; }
		if (HX_FIELD_EQ(inName,"PURPLE") ) { return PURPLE; }
		if (HX_FIELD_EQ(inName,"getRed") ) { return getRed_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EPSILON") ) { return EPSILON; }
		if (HX_FIELD_EQ(inName,"FUCHSIA") ) { return FUCHSIA; }
		if (HX_FIELD_EQ(inName,"getBlue") ) { return getBlue_dyn(); }
		if (HX_FIELD_EQ(inName,"indexOf") ) { return indexOf_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"getAlpha") ) { return getAlpha_dyn(); }
		if (HX_FIELD_EQ(inName,"getGreen") ) { return getGreen_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"intersect") ) { return intersect_dyn(); }
		if (HX_FIELD_EQ(inName,"setLength") ) { return setLength_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"matrixsetTo") ) { return matrixsetTo_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"isEquivalent") ) { return isEquivalent_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"normalizeAngle") ) { return normalizeAngle_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Util_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"RED") ) { RED=inValue.Cast< int >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"GRAY") ) { GRAY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"LIME") ) { LIME=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"AQUA") ) { AQUA=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"TEAL") ) { TEAL=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BLUE") ) { BLUE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"NAVY") ) { NAVY=inValue.Cast< int >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"WHITE") ) { WHITE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"BLACK") ) { BLACK=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"OLIVE") ) { OLIVE=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"GREEN") ) { GREEN=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"SILVER") ) { SILVER=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"MAROON") ) { MAROON=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"YELLOW") ) { YELLOW=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PURPLE") ) { PURPLE=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"EPSILON") ) { EPSILON=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"FUCHSIA") ) { FUCHSIA=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Util_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("EPSILON"),
	HX_CSTRING("WHITE"),
	HX_CSTRING("SILVER"),
	HX_CSTRING("GRAY"),
	HX_CSTRING("BLACK"),
	HX_CSTRING("RED"),
	HX_CSTRING("MAROON"),
	HX_CSTRING("YELLOW"),
	HX_CSTRING("OLIVE"),
	HX_CSTRING("LIME"),
	HX_CSTRING("GREEN"),
	HX_CSTRING("AQUA"),
	HX_CSTRING("TEAL"),
	HX_CSTRING("BLUE"),
	HX_CSTRING("NAVY"),
	HX_CSTRING("FUCHSIA"),
	HX_CSTRING("PURPLE"),
	HX_CSTRING("matrixsetTo"),
	HX_CSTRING("skew"),
	HX_CSTRING("isEquivalent"),
	HX_CSTRING("normalizeAngle"),
	HX_CSTRING("getAlpha"),
	HX_CSTRING("getRed"),
	HX_CSTRING("getGreen"),
	HX_CSTRING("getBlue"),
	HX_CSTRING("rgb"),
	HX_CSTRING("argb"),
	HX_CSTRING("intersect"),
	HX_CSTRING("fit"),
	HX_CSTRING("setLength"),
	HX_CSTRING("indexOf"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Util_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Util_obj::EPSILON,"EPSILON");
	HX_MARK_MEMBER_NAME(Util_obj::WHITE,"WHITE");
	HX_MARK_MEMBER_NAME(Util_obj::SILVER,"SILVER");
	HX_MARK_MEMBER_NAME(Util_obj::GRAY,"GRAY");
	HX_MARK_MEMBER_NAME(Util_obj::BLACK,"BLACK");
	HX_MARK_MEMBER_NAME(Util_obj::RED,"RED");
	HX_MARK_MEMBER_NAME(Util_obj::MAROON,"MAROON");
	HX_MARK_MEMBER_NAME(Util_obj::YELLOW,"YELLOW");
	HX_MARK_MEMBER_NAME(Util_obj::OLIVE,"OLIVE");
	HX_MARK_MEMBER_NAME(Util_obj::LIME,"LIME");
	HX_MARK_MEMBER_NAME(Util_obj::GREEN,"GREEN");
	HX_MARK_MEMBER_NAME(Util_obj::AQUA,"AQUA");
	HX_MARK_MEMBER_NAME(Util_obj::TEAL,"TEAL");
	HX_MARK_MEMBER_NAME(Util_obj::BLUE,"BLUE");
	HX_MARK_MEMBER_NAME(Util_obj::NAVY,"NAVY");
	HX_MARK_MEMBER_NAME(Util_obj::FUCHSIA,"FUCHSIA");
	HX_MARK_MEMBER_NAME(Util_obj::PURPLE,"PURPLE");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Util_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Util_obj::EPSILON,"EPSILON");
	HX_VISIT_MEMBER_NAME(Util_obj::WHITE,"WHITE");
	HX_VISIT_MEMBER_NAME(Util_obj::SILVER,"SILVER");
	HX_VISIT_MEMBER_NAME(Util_obj::GRAY,"GRAY");
	HX_VISIT_MEMBER_NAME(Util_obj::BLACK,"BLACK");
	HX_VISIT_MEMBER_NAME(Util_obj::RED,"RED");
	HX_VISIT_MEMBER_NAME(Util_obj::MAROON,"MAROON");
	HX_VISIT_MEMBER_NAME(Util_obj::YELLOW,"YELLOW");
	HX_VISIT_MEMBER_NAME(Util_obj::OLIVE,"OLIVE");
	HX_VISIT_MEMBER_NAME(Util_obj::LIME,"LIME");
	HX_VISIT_MEMBER_NAME(Util_obj::GREEN,"GREEN");
	HX_VISIT_MEMBER_NAME(Util_obj::AQUA,"AQUA");
	HX_VISIT_MEMBER_NAME(Util_obj::TEAL,"TEAL");
	HX_VISIT_MEMBER_NAME(Util_obj::BLUE,"BLUE");
	HX_VISIT_MEMBER_NAME(Util_obj::NAVY,"NAVY");
	HX_VISIT_MEMBER_NAME(Util_obj::FUCHSIA,"FUCHSIA");
	HX_VISIT_MEMBER_NAME(Util_obj::PURPLE,"PURPLE");
};

Class Util_obj::__mClass;

void Util_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.direct.Util"), hx::TCanCast< Util_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Util_obj::__boot()
{
	EPSILON= 0.00000001;
	WHITE= (int)16777215;
	SILVER= (int)12632256;
	GRAY= (int)8421504;
	BLACK= (int)0;
	RED= (int)16711680;
	MAROON= (int)8388608;
	YELLOW= (int)16776960;
	OLIVE= (int)8421376;
	LIME= (int)65280;
	GREEN= (int)32768;
	AQUA= (int)65535;
	TEAL= (int)32896;
	BLUE= (int)255;
	NAVY= (int)128;
	FUCHSIA= (int)16711935;
	PURPLE= (int)8388736;
}

} // end namespace com
} // end namespace engine
} // end namespace direct
