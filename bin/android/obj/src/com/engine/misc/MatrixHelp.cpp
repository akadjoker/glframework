#include <hxcpp.h>

#ifndef INCLUDED_com_engine_misc_MatrixHelp
#include <com/engine/misc/MatrixHelp.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_BlendMode
#include <flash/display/BlendMode.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_geom_ColorTransform
#include <flash/geom/ColorTransform.h>
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
namespace misc{

Void MatrixHelp_obj::__construct()
{
	return null();
}

MatrixHelp_obj::~MatrixHelp_obj() { }

Dynamic MatrixHelp_obj::__CreateEmpty() { return  new MatrixHelp_obj; }
hx::ObjectPtr< MatrixHelp_obj > MatrixHelp_obj::__new()
{  hx::ObjectPtr< MatrixHelp_obj > result = new MatrixHelp_obj();
	result->__construct();
	return result;}

Dynamic MatrixHelp_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< MatrixHelp_obj > result = new MatrixHelp_obj();
	result->__construct();
	return result;}

::flash::display::BitmapData MatrixHelp_obj::getScaled( ::flash::display::BitmapData source,int newWidth,int newHeight){
	HX_STACK_PUSH("MatrixHelp::getScaled","com/engine/misc/MatrixHelp.hx",17);
	HX_STACK_ARG(source,"source");
	HX_STACK_ARG(newWidth,"newWidth");
	HX_STACK_ARG(newHeight,"newHeight");
	HX_STACK_LINE(18)
	::flash::geom::Matrix m = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(m,"m");
	HX_STACK_LINE(19)
	m->scale((Float(newWidth) / Float(source->get_width())),(Float(newHeight) / Float(source->get_height())));
	HX_STACK_LINE(21)
	::flash::display::BitmapData bmp = ::flash::display::BitmapData_obj::__new(newWidth,newHeight,true,(int)255,null());		HX_STACK_VAR(bmp,"bmp");
	HX_STACK_LINE(23)
	bmp->draw(source,m,null(),null(),null(),null());
	HX_STACK_LINE(24)
	return bmp;
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(MatrixHelp_obj,getScaled,return )

::flash::display::BitmapData MatrixHelp_obj::flipBitmapData( ::flash::display::BitmapData original,::String __o_axis){
::String axis = __o_axis.Default(HX_CSTRING("y"));
	HX_STACK_PUSH("MatrixHelp::flipBitmapData","com/engine/misc/MatrixHelp.hx",28);
	HX_STACK_ARG(original,"original");
	HX_STACK_ARG(axis,"axis");
{
		HX_STACK_LINE(29)
		::flash::display::BitmapData flipped = ::flash::display::BitmapData_obj::__new(original->get_width(),original->get_height(),true,(int)0,null());		HX_STACK_VAR(flipped,"flipped");
		HX_STACK_LINE(30)
		::flash::geom::Matrix matrix;		HX_STACK_VAR(matrix,"matrix");
		HX_STACK_LINE(31)
		if (((axis == HX_CSTRING("x")))){
			HX_STACK_LINE(31)
			matrix = ::flash::geom::Matrix_obj::__new((int)-1,(int)0,(int)0,(int)1,original->get_width(),(int)0);
		}
		else{
			HX_STACK_LINE(33)
			matrix = ::flash::geom::Matrix_obj::__new((int)1,(int)0,(int)0,(int)-1,(int)0,original->get_height());
		}
		HX_STACK_LINE(36)
		flipped->draw(original,matrix,null(),null(),null(),true);
		HX_STACK_LINE(37)
		return flipped;
	}
}


STATIC_HX_DEFINE_DYNAMIC_FUNC2(MatrixHelp_obj,flipBitmapData,return )

Void MatrixHelp_obj::skew( ::flash::geom::Matrix matrix,Float skewX,Float skewY){
{
		HX_STACK_PUSH("MatrixHelp::skew","com/engine/misc/MatrixHelp.hx",41);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(skewX,"skewX");
		HX_STACK_ARG(skewY,"skewY");
		HX_STACK_LINE(42)
		Float sinX = ::Math_obj::sin(skewX);		HX_STACK_VAR(sinX,"sinX");
		HX_STACK_LINE(43)
		Float cosX = ::Math_obj::cos(skewX);		HX_STACK_VAR(cosX,"cosX");
		HX_STACK_LINE(44)
		Float sinY = ::Math_obj::sin(skewY);		HX_STACK_VAR(sinY,"sinY");
		HX_STACK_LINE(45)
		Float cosY = ::Math_obj::cos(skewY);		HX_STACK_VAR(cosY,"cosY");
		HX_STACK_LINE(47)
		::com::engine::misc::MatrixHelp_obj::setTo(matrix,((matrix->a * cosY) - (matrix->b * sinX)),((matrix->a * sinY) + (matrix->b * cosX)),((matrix->c * cosY) - (matrix->d * sinX)),((matrix->c * sinY) + (matrix->d * cosX)),((matrix->tx * cosY) - (matrix->ty * sinX)),((matrix->tx * sinY) + (matrix->ty * cosX)));
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC3(MatrixHelp_obj,skew,(void))

Void MatrixHelp_obj::setTo( ::flash::geom::Matrix matrix,Float a,Float b,Float c,Float d,Float tx,Float ty){
{
		HX_STACK_PUSH("MatrixHelp::setTo","com/engine/misc/MatrixHelp.hx",55);
		HX_STACK_ARG(matrix,"matrix");
		HX_STACK_ARG(a,"a");
		HX_STACK_ARG(b,"b");
		HX_STACK_ARG(c,"c");
		HX_STACK_ARG(d,"d");
		HX_STACK_ARG(tx,"tx");
		HX_STACK_ARG(ty,"ty");
		HX_STACK_LINE(57)
		matrix->a = a;
		HX_STACK_LINE(58)
		matrix->b = b;
		HX_STACK_LINE(59)
		matrix->c = c;
		HX_STACK_LINE(60)
		matrix->d = d;
		HX_STACK_LINE(61)
		matrix->tx = tx;
		HX_STACK_LINE(62)
		matrix->ty = ty;
	}
return null();
}


STATIC_HX_DEFINE_DYNAMIC_FUNC7(MatrixHelp_obj,setTo,(void))


MatrixHelp_obj::MatrixHelp_obj()
{
}

void MatrixHelp_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(MatrixHelp);
	HX_MARK_END_CLASS();
}

void MatrixHelp_obj::__Visit(HX_VISIT_PARAMS)
{
}

Dynamic MatrixHelp_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"skew") ) { return skew_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"setTo") ) { return setTo_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getScaled") ) { return getScaled_dyn(); }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"flipBitmapData") ) { return flipBitmapData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic MatrixHelp_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	return super::__SetField(inName,inValue,inCallProp);
}

void MatrixHelp_obj::__GetFields(Array< ::String> &outFields)
{
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("getScaled"),
	HX_CSTRING("flipBitmapData"),
	HX_CSTRING("skew"),
	HX_CSTRING("setTo"),
	String(null()) };

static ::String sMemberFields[] = {
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(MatrixHelp_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(MatrixHelp_obj::__mClass,"__mClass");
};

Class MatrixHelp_obj::__mClass;

void MatrixHelp_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.misc.MatrixHelp"), hx::TCanCast< MatrixHelp_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void MatrixHelp_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace misc
