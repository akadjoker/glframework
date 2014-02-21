#include <hxcpp.h>

#ifndef INCLUDED_com_engine_render_PrimitiveShader
#include <com/engine/render/PrimitiveShader.h>
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

Void PrimitiveShader_obj::__construct()
{
HX_STACK_PUSH("PrimitiveShader::new","com/engine/render/PrimitiveShader.hx",27);
{
	HX_STACK_LINE(30)
	::String vertexShaderSource = HX_CSTRING("\r\nattribute vec3 aVertexPosition;\r\nattribute vec4 aColor;\r\n\r\nvarying vec4 vColor;\r\n\r\nuniform mat4 uModelViewMatrix;\r\nuniform mat4 uProjectionMatrix;\r\nvoid main(void) \r\n{\r\nvColor = aColor;\r\ngl_Position = uProjectionMatrix * uModelViewMatrix * vec4 (aVertexPosition, 1.0);\r\n}");		HX_STACK_VAR(vertexShaderSource,"vertexShaderSource");
	HX_STACK_LINE(45)
	::openfl::gl::GLShader vertexShader = ::openfl::gl::GL_obj::createShader((int)35633);		HX_STACK_VAR(vertexShader,"vertexShader");
	HX_STACK_LINE(46)
	::openfl::gl::GL_obj::shaderSource(vertexShader,vertexShaderSource);
	HX_STACK_LINE(47)
	::openfl::gl::GL_obj::compileShader(vertexShader);
	HX_STACK_LINE(49)
	if (((::openfl::gl::GL_obj::getShaderParameter(vertexShader,(int)35713) == (int)0))){
		HX_STACK_LINE(50)
		hx::Throw (::openfl::gl::GL_obj::getShaderInfoLog(vertexShader));
	}
	HX_STACK_LINE(56)
	::String fragmentShaderSource = (HX_CSTRING("precision mediump float;") + HX_CSTRING("\r\n\r\nvarying vec4 vColor;\r\nvoid main(void)\r\n{\r\n\tgl_FragColor =  vColor;\r\n}"));		HX_STACK_VAR(fragmentShaderSource,"fragmentShaderSource");
	HX_STACK_LINE(69)
	::openfl::gl::GLShader fragmentShader = ::openfl::gl::GL_obj::createShader((int)35632);		HX_STACK_VAR(fragmentShader,"fragmentShader");
	HX_STACK_LINE(70)
	::openfl::gl::GL_obj::shaderSource(fragmentShader,fragmentShaderSource);
	HX_STACK_LINE(71)
	::openfl::gl::GL_obj::compileShader(fragmentShader);
	HX_STACK_LINE(73)
	if (((::openfl::gl::GL_obj::getShaderParameter(fragmentShader,(int)35713) == (int)0))){
		HX_STACK_LINE(73)
		hx::Throw (::openfl::gl::GL_obj::getShaderInfoLog(fragmentShader));
	}
	HX_STACK_LINE(79)
	this->shaderProgram = ::openfl::gl::GL_obj::createProgram();
	HX_STACK_LINE(80)
	::openfl::gl::GL_obj::attachShader(this->shaderProgram,vertexShader);
	HX_STACK_LINE(81)
	::openfl::gl::GL_obj::attachShader(this->shaderProgram,fragmentShader);
	HX_STACK_LINE(82)
	::openfl::gl::GL_obj::linkProgram(this->shaderProgram);
	HX_STACK_LINE(84)
	if (((::openfl::gl::GL_obj::getProgramParameter(this->shaderProgram,(int)35714) == (int)0))){
		HX_STACK_LINE(84)
		hx::Throw (HX_CSTRING("Unable to initialize the shader program."));
	}
	HX_STACK_LINE(90)
	this->vertexAttribute = ::openfl::gl::GL_obj::getAttribLocation(this->shaderProgram,HX_CSTRING("aVertexPosition"));
	HX_STACK_LINE(91)
	this->colorAttribute = ::openfl::gl::GL_obj::getAttribLocation(this->shaderProgram,HX_CSTRING("aColor"));
	HX_STACK_LINE(92)
	this->projectionMatrixUniform = ::openfl::gl::GL_obj::getUniformLocation(this->shaderProgram,HX_CSTRING("uProjectionMatrix"));
	HX_STACK_LINE(93)
	this->modelViewMatrixUniform = ::openfl::gl::GL_obj::getUniformLocation(this->shaderProgram,HX_CSTRING("uModelViewMatrix"));
}
;
	return null();
}

PrimitiveShader_obj::~PrimitiveShader_obj() { }

Dynamic PrimitiveShader_obj::__CreateEmpty() { return  new PrimitiveShader_obj; }
hx::ObjectPtr< PrimitiveShader_obj > PrimitiveShader_obj::__new()
{  hx::ObjectPtr< PrimitiveShader_obj > result = new PrimitiveShader_obj();
	result->__construct();
	return result;}

Dynamic PrimitiveShader_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PrimitiveShader_obj > result = new PrimitiveShader_obj();
	result->__construct();
	return result;}

Void PrimitiveShader_obj::Disable( ){
{
		HX_STACK_PUSH("PrimitiveShader::Disable","com/engine/render/PrimitiveShader.hx",107);
		HX_STACK_THIS(this);
		HX_STACK_LINE(108)
		::openfl::gl::GL_obj::disableVertexAttribArray(this->vertexAttribute);
		HX_STACK_LINE(109)
		::openfl::gl::GL_obj::disableVertexAttribArray(this->colorAttribute);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PrimitiveShader_obj,Disable,(void))

Void PrimitiveShader_obj::Enable( ){
{
		HX_STACK_PUSH("PrimitiveShader::Enable","com/engine/render/PrimitiveShader.hx",99);
		HX_STACK_THIS(this);
		HX_STACK_LINE(100)
		::openfl::gl::GL_obj::useProgram(this->shaderProgram);
		HX_STACK_LINE(101)
		::openfl::gl::GL_obj::enableVertexAttribArray(this->vertexAttribute);
		HX_STACK_LINE(102)
		::openfl::gl::GL_obj::enableVertexAttribArray(this->colorAttribute);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PrimitiveShader_obj,Enable,(void))


PrimitiveShader_obj::PrimitiveShader_obj()
{
}

void PrimitiveShader_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PrimitiveShader);
	HX_MARK_MEMBER_NAME(modelViewMatrixUniform,"modelViewMatrixUniform");
	HX_MARK_MEMBER_NAME(projectionMatrixUniform,"projectionMatrixUniform");
	HX_MARK_MEMBER_NAME(colorAttribute,"colorAttribute");
	HX_MARK_MEMBER_NAME(vertexAttribute,"vertexAttribute");
	HX_MARK_MEMBER_NAME(shaderProgram,"shaderProgram");
	HX_MARK_END_CLASS();
}

void PrimitiveShader_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(modelViewMatrixUniform,"modelViewMatrixUniform");
	HX_VISIT_MEMBER_NAME(projectionMatrixUniform,"projectionMatrixUniform");
	HX_VISIT_MEMBER_NAME(colorAttribute,"colorAttribute");
	HX_VISIT_MEMBER_NAME(vertexAttribute,"vertexAttribute");
	HX_VISIT_MEMBER_NAME(shaderProgram,"shaderProgram");
}

Dynamic PrimitiveShader_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"Enable") ) { return Enable_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"Disable") ) { return Disable_dyn(); }
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
	case 22:
		if (HX_FIELD_EQ(inName,"modelViewMatrixUniform") ) { return modelViewMatrixUniform; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"projectionMatrixUniform") ) { return projectionMatrixUniform; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PrimitiveShader_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 13:
		if (HX_FIELD_EQ(inName,"shaderProgram") ) { shaderProgram=inValue.Cast< ::openfl::gl::GLProgram >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"colorAttribute") ) { colorAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"vertexAttribute") ) { vertexAttribute=inValue.Cast< int >(); return inValue; }
		break;
	case 22:
		if (HX_FIELD_EQ(inName,"modelViewMatrixUniform") ) { modelViewMatrixUniform=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 23:
		if (HX_FIELD_EQ(inName,"projectionMatrixUniform") ) { projectionMatrixUniform=inValue.Cast< Dynamic >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PrimitiveShader_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("modelViewMatrixUniform"));
	outFields->push(HX_CSTRING("projectionMatrixUniform"));
	outFields->push(HX_CSTRING("colorAttribute"));
	outFields->push(HX_CSTRING("vertexAttribute"));
	outFields->push(HX_CSTRING("shaderProgram"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("Disable"),
	HX_CSTRING("Enable"),
	HX_CSTRING("modelViewMatrixUniform"),
	HX_CSTRING("projectionMatrixUniform"),
	HX_CSTRING("colorAttribute"),
	HX_CSTRING("vertexAttribute"),
	HX_CSTRING("shaderProgram"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PrimitiveShader_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PrimitiveShader_obj::__mClass,"__mClass");
};

Class PrimitiveShader_obj::__mClass;

void PrimitiveShader_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.PrimitiveShader"), hx::TCanCast< PrimitiveShader_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void PrimitiveShader_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
