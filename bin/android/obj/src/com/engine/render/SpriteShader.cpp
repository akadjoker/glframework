#include <hxcpp.h>

#ifndef INCLUDED_com_engine_render_SpriteShader
#include <com/engine/render/SpriteShader.h>
#endif
#ifndef INCLUDED_openfl_gl_GL
#include <openfl/gl/GL.h>
#endif
#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
#ifndef INCLUDED_openfl_gl_GLProgram
#include <openfl/gl/GLProgram.h>
#endif
#ifndef INCLUDED_openfl_gl_GLShader
#include <openfl/gl/GLShader.h>
#endif
namespace com{
namespace engine{
namespace render{

Void SpriteShader_obj::__construct()
{
HX_STACK_PUSH("SpriteShader::new","com/engine/render/SpriteShader.hx",28);
{
	HX_STACK_LINE(31)
	::String vertexShaderSource = HX_CSTRING("\r\nattribute vec3 aVertexPosition;\r\nattribute vec2 aTexCoord;\r\nattribute vec4 aColor;\r\n\r\nvarying vec2 vTexCoord;\r\nvarying vec4 vColor;\r\n\r\nuniform mat4 uModelViewMatrix;\r\nuniform mat4 uProjectionMatrix;\r\nvoid main(void) \r\n{\r\nvTexCoord = aTexCoord;\r\nvColor = aColor;\r\ngl_Position = uProjectionMatrix * uModelViewMatrix *  vec4 (aVertexPosition, 1.0);\r\n\r\n}");		HX_STACK_VAR(vertexShaderSource,"vertexShaderSource");
	HX_STACK_LINE(53)
	::openfl::gl::GLShader vertexShader = ::openfl::gl::GL_obj::createShader((int)35633);		HX_STACK_VAR(vertexShader,"vertexShader");
	HX_STACK_LINE(54)
	::openfl::gl::GL_obj::shaderSource(vertexShader,vertexShaderSource);
	HX_STACK_LINE(55)
	::openfl::gl::GL_obj::compileShader(vertexShader);
	HX_STACK_LINE(57)
	if (((::openfl::gl::GL_obj::getShaderParameter(vertexShader,(int)35713) == (int)0))){
		HX_STACK_LINE(58)
		hx::Throw (::openfl::gl::GL_obj::getShaderInfoLog(vertexShader));
	}
	HX_STACK_LINE(64)
	::String fragmentShaderSource = (HX_CSTRING("precision mediump float;") + HX_CSTRING("\r\nvarying vec2 vTexCoord;\r\nvarying vec4 vColor;\r\nuniform sampler2D uImage0;\r\n\r\nvoid main(void)\r\n{\r\n\tgl_FragColor = texture2D (uImage0, vTexCoord) * vColor;\r\n\r\n}"));		HX_STACK_VAR(fragmentShaderSource,"fragmentShaderSource");
	HX_STACK_LINE(80)
	::openfl::gl::GLShader fragmentShader = ::openfl::gl::GL_obj::createShader((int)35632);		HX_STACK_VAR(fragmentShader,"fragmentShader");
	HX_STACK_LINE(81)
	::openfl::gl::GL_obj::shaderSource(fragmentShader,fragmentShaderSource);
	HX_STACK_LINE(82)
	::openfl::gl::GL_obj::compileShader(fragmentShader);
	HX_STACK_LINE(84)
	if (((::openfl::gl::GL_obj::getShaderParameter(fragmentShader,(int)35713) == (int)0))){
		HX_STACK_LINE(84)
		hx::Throw (::openfl::gl::GL_obj::getShaderInfoLog(fragmentShader));
	}
	HX_STACK_LINE(90)
	this->shaderProgram = ::openfl::gl::GL_obj::createProgram();
	HX_STACK_LINE(91)
	::openfl::gl::GL_obj::attachShader(this->shaderProgram,vertexShader);
	HX_STACK_LINE(92)
	::openfl::gl::GL_obj::attachShader(this->shaderProgram,fragmentShader);
	HX_STACK_LINE(93)
	::openfl::gl::GL_obj::linkProgram(this->shaderProgram);
	HX_STACK_LINE(95)
	if (((::openfl::gl::GL_obj::getProgramParameter(this->shaderProgram,(int)35714) == (int)0))){
		HX_STACK_LINE(95)
		hx::Throw (HX_CSTRING("Unable to initialize the shader program."));
	}
	HX_STACK_LINE(101)
	this->vertexAttribute = ::openfl::gl::GL_obj::getAttribLocation(this->shaderProgram,HX_CSTRING("aVertexPosition"));
	HX_STACK_LINE(102)
	this->texCoordAttribute = ::openfl::gl::GL_obj::getAttribLocation(this->shaderProgram,HX_CSTRING("aTexCoord"));
	HX_STACK_LINE(103)
	this->colorAttribute = ::openfl::gl::GL_obj::getAttribLocation(this->shaderProgram,HX_CSTRING("aColor"));
	HX_STACK_LINE(104)
	this->projectionMatrixUniform = ::openfl::gl::GL_obj::getUniformLocation(this->shaderProgram,HX_CSTRING("uProjectionMatrix"));
	HX_STACK_LINE(105)
	this->modelViewMatrixUniform = ::openfl::gl::GL_obj::getUniformLocation(this->shaderProgram,HX_CSTRING("uModelViewMatrix"));
	HX_STACK_LINE(106)
	this->imageUniform = ::openfl::gl::GL_obj::getUniformLocation(this->shaderProgram,HX_CSTRING("uImage0"));
}
;
	return null();
}

SpriteShader_obj::~SpriteShader_obj() { }

Dynamic SpriteShader_obj::__CreateEmpty() { return  new SpriteShader_obj; }
hx::ObjectPtr< SpriteShader_obj > SpriteShader_obj::__new()
{  hx::ObjectPtr< SpriteShader_obj > result = new SpriteShader_obj();
	result->__construct();
	return result;}

Dynamic SpriteShader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SpriteShader_obj > result = new SpriteShader_obj();
	result->__construct();
	return result;}

Void SpriteShader_obj::Disable( ){
{
		HX_STACK_PUSH("SpriteShader::Disable","com/engine/render/SpriteShader.hx",118);
		HX_STACK_THIS(this);
		HX_STACK_LINE(119)
		::openfl::gl::GL_obj::disableVertexAttribArray(this->vertexAttribute);
		HX_STACK_LINE(120)
		::openfl::gl::GL_obj::disableVertexAttribArray(this->texCoordAttribute);
		HX_STACK_LINE(121)
		::openfl::gl::GL_obj::disableVertexAttribArray(this->colorAttribute);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteShader_obj,Disable,(void))

Void SpriteShader_obj::Enable( ){
{
		HX_STACK_PUSH("SpriteShader::Enable","com/engine/render/SpriteShader.hx",111);
		HX_STACK_THIS(this);
		HX_STACK_LINE(112)
		::openfl::gl::GL_obj::useProgram(this->shaderProgram);
		HX_STACK_LINE(113)
		::openfl::gl::GL_obj::enableVertexAttribArray(this->vertexAttribute);
		HX_STACK_LINE(114)
		::openfl::gl::GL_obj::enableVertexAttribArray(this->texCoordAttribute);
		HX_STACK_LINE(115)
		::openfl::gl::GL_obj::enableVertexAttribArray(this->colorAttribute);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteShader_obj,Enable,(void))


SpriteShader_obj::SpriteShader_obj()
{
}

void SpriteShader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SpriteShader);
	HX_MARK_MEMBER_NAME(imageUniform,"imageUniform");
	HX_MARK_MEMBER_NAME(modelViewMatrixUniform,"modelViewMatrixUniform");
	HX_MARK_MEMBER_NAME(projectionMatrixUniform,"projectionMatrixUniform");
	HX_MARK_MEMBER_NAME(colorAttribute,"colorAttribute");
	HX_MARK_MEMBER_NAME(texCoordAttribute,"texCoordAttribute");
	HX_MARK_MEMBER_NAME(vertexAttribute,"vertexAttribute");
	HX_MARK_MEMBER_NAME(shaderProgram,"shaderProgram");
	HX_MARK_END_CLASS();
}

void SpriteShader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(imageUniform,"imageUniform");
	HX_VISIT_MEMBER_NAME(modelViewMatrixUniform,"modelViewMatrixUniform");
	HX_VISIT_MEMBER_NAME(projectionMatrixUniform,"projectionMatrixUniform");
	HX_VISIT_MEMBER_NAME(colorAttribute,"colorAttribute");
	HX_VISIT_MEMBER_NAME(texCoordAttribute,"texCoordAttribute");
	HX_VISIT_MEMBER_NAME(vertexAttribute,"vertexAttribute");
	HX_VISIT_MEMBER_NAME(shaderProgram,"shaderProgram");
}

Dynamic SpriteShader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"Enable") ) { return Enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Disable") ) { return Disable_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"imageUniform") ) { return imageUniform; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"shaderProgram") ) { return shaderProgram; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorAttribute") ) { return colorAttribute; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"vertexAttribute") ) { return vertexAttribute; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"texCoordAttribute") ) { return texCoordAttribute; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"modelViewMatrixUniform") ) { return modelViewMatrixUniform; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"projectionMatrixUniform") ) { return projectionMatrixUniform; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SpriteShader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 12:
		if (HX_FIELD_EQ(inName,"imageUniform") ) { imageUniform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"shaderProgram") ) { shaderProgram=inValue.Cast< ::openfl::gl::GLProgram >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorAttribute") ) { colorAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"vertexAttribute") ) { vertexAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"texCoordAttribute") ) { texCoordAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"modelViewMatrixUniform") ) { modelViewMatrixUniform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"projectionMatrixUniform") ) { projectionMatrixUniform=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SpriteShader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("imageUniform"));
	outFields->push(HX_CSTRING("modelViewMatrixUniform"));
	outFields->push(HX_CSTRING("projectionMatrixUniform"));
	outFields->push(HX_CSTRING("colorAttribute"));
	outFields->push(HX_CSTRING("texCoordAttribute"));
	outFields->push(HX_CSTRING("vertexAttribute"));
	outFields->push(HX_CSTRING("shaderProgram"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("Disable"),
	HX_CSTRING("Enable"),
	HX_CSTRING("imageUniform"),
	HX_CSTRING("modelViewMatrixUniform"),
	HX_CSTRING("projectionMatrixUniform"),
	HX_CSTRING("colorAttribute"),
	HX_CSTRING("texCoordAttribute"),
	HX_CSTRING("vertexAttribute"),
	HX_CSTRING("shaderProgram"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpriteShader_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SpriteShader_obj::__mClass,"__mClass");
};

Class SpriteShader_obj::__mClass;

void SpriteShader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.SpriteShader"), hx::TCanCast< SpriteShader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SpriteShader_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
