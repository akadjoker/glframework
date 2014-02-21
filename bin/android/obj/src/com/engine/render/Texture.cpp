#include <hxcpp.h>

#ifndef INCLUDED_com_engine_render_Texture
#include <com/engine/render/Texture.h>
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
#ifndef INCLUDED_flash_utils_ByteArray
#include <flash/utils/ByteArray.h>
#endif
#ifndef INCLUDED_flash_utils_IDataInput
#include <flash/utils/IDataInput.h>
#endif
#ifndef INCLUDED_flash_utils_IDataOutput
#include <flash/utils/IDataOutput.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_io_Bytes
#include <haxe/io/Bytes.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_gl_GL
#include <openfl/gl/GL.h>
#endif
#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
#ifndef INCLUDED_openfl_gl_GLTexture
#include <openfl/gl/GLTexture.h>
#endif
#ifndef INCLUDED_openfl_utils_ArrayBufferView
#include <openfl/utils/ArrayBufferView.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
#ifndef INCLUDED_openfl_utils_UInt8Array
#include <openfl/utils/UInt8Array.h>
#endif
namespace com{
namespace engine{
namespace render{

Void Texture_obj::__construct(::String url)
{
HX_STACK_PUSH("Texture::new","com/engine/render/Texture.hx",47);
{
	HX_STACK_LINE(51)
	this->bitmapData = ::openfl::Assets_obj::getBitmapData(url,null());
	HX_STACK_LINE(55)
	this->data = ::openfl::gl::GL_obj::createTexture();
	HX_STACK_LINE(56)
	::openfl::gl::GL_obj::bindTexture((int)3553,this->data);
	HX_STACK_LINE(61)
	this->width = this->bitmapData->get_width();
	HX_STACK_LINE(62)
	this->height = this->bitmapData->get_height();
	struct _Function_1_1{
		inline static int Block( ::com::engine::render::Texture_obj *__this){
			HX_STACK_PUSH("*::closure","com/engine/render/Texture.hx",64);
			{
				HX_STACK_LINE(64)
				int number = __this->width;		HX_STACK_VAR(number,"number");
				struct _Function_2_1{
					inline static int Block( int &number){
						HX_STACK_PUSH("*::closure","com/engine/render/Texture.hx",64);
						{
							HX_STACK_LINE(64)
							int result = (int)1;		HX_STACK_VAR(result,"result");
							HX_STACK_LINE(64)
							while(((result < number))){
								HX_STACK_LINE(64)
								hx::ShlEq(result,(int)1);
							}
							HX_STACK_LINE(64)
							return result;
						}
						return null();
					}
				};
				HX_STACK_LINE(64)
				return (  (((bool((number > (int)0)) && bool((((int(number) & int((number - (int)1)))) == (int)0))))) ? int(number) : int(_Function_2_1::Block(number)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(64)
	this->texWidth = _Function_1_1::Block(this);
	struct _Function_1_2{
		inline static int Block( ::com::engine::render::Texture_obj *__this){
			HX_STACK_PUSH("*::closure","com/engine/render/Texture.hx",65);
			{
				HX_STACK_LINE(65)
				int number = __this->height;		HX_STACK_VAR(number,"number");
				struct _Function_2_1{
					inline static int Block( int &number){
						HX_STACK_PUSH("*::closure","com/engine/render/Texture.hx",65);
						{
							HX_STACK_LINE(65)
							int result = (int)1;		HX_STACK_VAR(result,"result");
							HX_STACK_LINE(65)
							while(((result < number))){
								HX_STACK_LINE(65)
								hx::ShlEq(result,(int)1);
							}
							HX_STACK_LINE(65)
							return result;
						}
						return null();
					}
				};
				HX_STACK_LINE(65)
				return (  (((bool((number > (int)0)) && bool((((int(number) & int((number - (int)1)))) == (int)0))))) ? int(number) : int(_Function_2_1::Block(number)) );
			}
			return null();
		}
	};
	HX_STACK_LINE(65)
	this->texHeight = _Function_1_2::Block(this);
	HX_STACK_LINE(69)
	bool isPot = (bool((this->bitmapData->get_width() == this->texWidth)) && bool((this->bitmapData->get_height() == this->texHeight)));		HX_STACK_VAR(isPot,"isPot");
	HX_STACK_LINE(75)
	::openfl::gl::GL_obj::texParameteri((int)3553,(int)10242,(int)33071);
	HX_STACK_LINE(76)
	::openfl::gl::GL_obj::texParameteri((int)3553,(int)10243,(int)33071);
	HX_STACK_LINE(77)
	::openfl::gl::GL_obj::texParameteri((int)3553,(int)10240,(int)9728);
	HX_STACK_LINE(78)
	::openfl::gl::GL_obj::texParameteri((int)3553,(int)10241,(int)9728);
	HX_STACK_LINE(81)
	if ((!(isPot))){
		struct _Function_2_1{
			inline static ::flash::display::BitmapData Block( ::com::engine::render::Texture_obj *__this){
				HX_STACK_PUSH("*::closure","com/engine/render/Texture.hx",84);
				{
					HX_STACK_LINE(84)
					::flash::display::BitmapData source = __this->bitmapData;		HX_STACK_VAR(source,"source");
					int newWidth = __this->texWidth;		HX_STACK_VAR(newWidth,"newWidth");
					int newHeight = __this->texHeight;		HX_STACK_VAR(newHeight,"newHeight");
					HX_STACK_LINE(84)
					::flash::geom::Matrix m = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(m,"m");
					HX_STACK_LINE(84)
					m->scale((Float(newWidth) / Float(source->get_width())),(Float(newHeight) / Float(source->get_height())));
					HX_STACK_LINE(84)
					::flash::display::BitmapData bmp = ::flash::display::BitmapData_obj::__new(newWidth,newHeight,true,(int)255,null());		HX_STACK_VAR(bmp,"bmp");
					HX_STACK_LINE(84)
					bmp->draw(source,m,null(),null(),null(),null());
					HX_STACK_LINE(84)
					return bmp;
				}
				return null();
			}
		};
		HX_STACK_LINE(84)
		::flash::display::BitmapData workingCanvas = _Function_2_1::Block(this);		HX_STACK_VAR(workingCanvas,"workingCanvas");
		HX_STACK_LINE(85)
		this->bitmapData = null();
		struct _Function_2_2{
			inline static ::flash::utils::ByteArray Block( ::flash::display::BitmapData &workingCanvas){
				HX_STACK_PUSH("*::closure","com/engine/render/Texture.hx",90);
				{
					HX_STACK_LINE(90)
					::flash::utils::ByteArray data = workingCanvas->getPixels(::flash::geom::Rectangle_obj::__new((int)0,(int)0,workingCanvas->get_width(),workingCanvas->get_height()));		HX_STACK_VAR(data,"data");
					HX_STACK_LINE(90)
					int size = (workingCanvas->get_width() * workingCanvas->get_height());		HX_STACK_VAR(size,"size");
					HX_STACK_LINE(90)
					int alpha;		HX_STACK_VAR(alpha,"alpha");
					int red;		HX_STACK_VAR(red,"red");
					int green;		HX_STACK_VAR(green,"green");
					int blue;		HX_STACK_VAR(blue,"blue");
					HX_STACK_LINE(90)
					{
						HX_STACK_LINE(90)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(90)
						while(((_g < size))){
							HX_STACK_LINE(90)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(90)
							alpha = data->__get((i * (int)4));
							HX_STACK_LINE(90)
							red = data->__get(((i * (int)4) + (int)1));
							HX_STACK_LINE(90)
							green = data->__get(((i * (int)4) + (int)2));
							HX_STACK_LINE(90)
							blue = data->__get(((i * (int)4) + (int)3));
							HX_STACK_LINE(90)
							hx::__ArrayImplRef(data,(i * (int)4)) = red;
							HX_STACK_LINE(90)
							hx::__ArrayImplRef(data,((i * (int)4) + (int)1)) = green;
							HX_STACK_LINE(90)
							hx::__ArrayImplRef(data,((i * (int)4) + (int)2)) = blue;
							HX_STACK_LINE(90)
							hx::__ArrayImplRef(data,((i * (int)4) + (int)3)) = alpha;
						}
					}
					HX_STACK_LINE(90)
					return data;
				}
				return null();
			}
		};
		HX_STACK_LINE(90)
		::openfl::utils::UInt8Array pixelData = ::openfl::utils::UInt8Array_obj::__new(_Function_2_2::Block(workingCanvas),null(),null());		HX_STACK_VAR(pixelData,"pixelData");
		HX_STACK_LINE(92)
		::openfl::gl::GL_obj::texImage2D((int)3553,(int)0,(int)6408,workingCanvas->get_width(),workingCanvas->get_height(),(int)0,(int)6408,(int)5121,pixelData);
		HX_STACK_LINE(94)
		::haxe::Log_obj::trace(((workingCanvas->get_width() + HX_CSTRING("<>")) + workingCanvas->get_height()),hx::SourceInfo(HX_CSTRING("Texture.hx"),94,HX_CSTRING("com.engine.render.Texture"),HX_CSTRING("new")));
	}
	else{
		struct _Function_2_1{
			inline static ::flash::utils::ByteArray Block( ::com::engine::render::Texture_obj *__this){
				HX_STACK_PUSH("*::closure","com/engine/render/Texture.hx",112);
				{
					HX_STACK_LINE(112)
					::flash::display::BitmapData bitmapData = __this->bitmapData;		HX_STACK_VAR(bitmapData,"bitmapData");
					HX_STACK_LINE(112)
					::flash::utils::ByteArray data = bitmapData->getPixels(::flash::geom::Rectangle_obj::__new((int)0,(int)0,bitmapData->get_width(),bitmapData->get_height()));		HX_STACK_VAR(data,"data");
					HX_STACK_LINE(112)
					int size = (bitmapData->get_width() * bitmapData->get_height());		HX_STACK_VAR(size,"size");
					HX_STACK_LINE(112)
					int alpha;		HX_STACK_VAR(alpha,"alpha");
					int red;		HX_STACK_VAR(red,"red");
					int green;		HX_STACK_VAR(green,"green");
					int blue;		HX_STACK_VAR(blue,"blue");
					HX_STACK_LINE(112)
					{
						HX_STACK_LINE(112)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(112)
						while(((_g < size))){
							HX_STACK_LINE(112)
							int i = (_g)++;		HX_STACK_VAR(i,"i");
							HX_STACK_LINE(112)
							alpha = data->__get((i * (int)4));
							HX_STACK_LINE(112)
							red = data->__get(((i * (int)4) + (int)1));
							HX_STACK_LINE(112)
							green = data->__get(((i * (int)4) + (int)2));
							HX_STACK_LINE(112)
							blue = data->__get(((i * (int)4) + (int)3));
							HX_STACK_LINE(112)
							hx::__ArrayImplRef(data,(i * (int)4)) = red;
							HX_STACK_LINE(112)
							hx::__ArrayImplRef(data,((i * (int)4) + (int)1)) = green;
							HX_STACK_LINE(112)
							hx::__ArrayImplRef(data,((i * (int)4) + (int)2)) = blue;
							HX_STACK_LINE(112)
							hx::__ArrayImplRef(data,((i * (int)4) + (int)3)) = alpha;
						}
					}
					HX_STACK_LINE(112)
					return data;
				}
				return null();
			}
		};
		HX_STACK_LINE(112)
		::openfl::utils::UInt8Array pixelData = ::openfl::utils::UInt8Array_obj::__new(_Function_2_1::Block(this),null(),null());		HX_STACK_VAR(pixelData,"pixelData");
		HX_STACK_LINE(114)
		::openfl::gl::GL_obj::texImage2D((int)3553,(int)0,(int)6408,this->texWidth,this->texHeight,(int)0,(int)6408,(int)5121,pixelData);
	}
}
;
	return null();
}

Texture_obj::~Texture_obj() { }

Dynamic Texture_obj::__CreateEmpty() { return  new Texture_obj; }
hx::ObjectPtr< Texture_obj > Texture_obj::__new(::String url)
{  hx::ObjectPtr< Texture_obj > result = new Texture_obj();
	result->__construct(url);
	return result;}

Dynamic Texture_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Texture_obj > result = new Texture_obj();
	result->__construct(inArgs[0]);
	return result;}

Void Texture_obj::Bind( ){
{
		HX_STACK_PUSH("Texture::Bind","com/engine/render/Texture.hx",42);
		HX_STACK_THIS(this);
		HX_STACK_LINE(42)
		::openfl::gl::GL_obj::bindTexture((int)3553,this->data);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Texture_obj,Bind,(void))


Texture_obj::Texture_obj()
{
}

void Texture_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Texture);
	HX_MARK_MEMBER_NAME(texWidth,"texWidth");
	HX_MARK_MEMBER_NAME(texHeight,"texHeight");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_MEMBER_NAME(bitmapData,"bitmapData");
	HX_MARK_MEMBER_NAME(data,"data");
	HX_MARK_END_CLASS();
}

void Texture_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(texWidth,"texWidth");
	HX_VISIT_MEMBER_NAME(texHeight,"texHeight");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
	HX_VISIT_MEMBER_NAME(bitmapData,"bitmapData");
	HX_VISIT_MEMBER_NAME(data,"data");
}

Dynamic Texture_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"Bind") ) { return Bind_dyn(); }
		if (HX_FIELD_EQ(inName,"data") ) { return data; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"texWidth") ) { return texWidth; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"texHeight") ) { return texHeight; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { return bitmapData; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Texture_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"data") ) { data=inValue.Cast< ::openfl::gl::GLTexture >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"texWidth") ) { texWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"texHeight") ) { texHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"bitmapData") ) { bitmapData=inValue.Cast< ::flash::display::BitmapData >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Texture_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("texWidth"));
	outFields->push(HX_CSTRING("texHeight"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	outFields->push(HX_CSTRING("bitmapData"));
	outFields->push(HX_CSTRING("data"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("Bind"),
	HX_CSTRING("texWidth"),
	HX_CSTRING("texHeight"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	HX_CSTRING("bitmapData"),
	HX_CSTRING("data"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Texture_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Texture_obj::__mClass,"__mClass");
};

Class Texture_obj::__mClass;

void Texture_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.Texture"), hx::TCanCast< Texture_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Texture_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
