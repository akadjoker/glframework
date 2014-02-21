#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_engine_game_Game
#include <com/engine/game/Game.h>
#endif
#ifndef INCLUDED_com_engine_math_Matrix
#include <com/engine/math/Matrix.h>
#endif
#ifndef INCLUDED_com_engine_render_BatchPrimitives
#include <com/engine/render/BatchPrimitives.h>
#endif
#ifndef INCLUDED_com_engine_render_BlendMode
#include <com/engine/render/BlendMode.h>
#endif
#ifndef INCLUDED_com_engine_render_Buffer
#include <com/engine/render/Buffer.h>
#endif
#ifndef INCLUDED_com_engine_render_PrimitiveShader
#include <com/engine/render/PrimitiveShader.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_display_DirectRenderer
#include <openfl/display/DirectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_OpenGLView
#include <openfl/display/OpenGLView.h>
#endif
#ifndef INCLUDED_openfl_gl_GL
#include <openfl/gl/GL.h>
#endif
#ifndef INCLUDED_openfl_gl_GLBuffer
#include <openfl/gl/GLBuffer.h>
#endif
#ifndef INCLUDED_openfl_gl_GLObject
#include <openfl/gl/GLObject.h>
#endif
#ifndef INCLUDED_openfl_utils_ArrayBufferView
#include <openfl/utils/ArrayBufferView.h>
#endif
#ifndef INCLUDED_openfl_utils_Float32Array
#include <openfl/utils/Float32Array.h>
#endif
#ifndef INCLUDED_openfl_utils_IMemoryRange
#include <openfl/utils/IMemoryRange.h>
#endif
namespace com{
namespace engine{
namespace render{

Void BatchPrimitives_obj::__construct(int capacity)
{
HX_STACK_PUSH("BatchPrimitives::new","com/engine/render/BatchPrimitives.hx",56);
{
	HX_STACK_LINE(57)
	super::__construct();
	HX_STACK_LINE(58)
	this->vertexBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(59)
	this->colorBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(60)
	this->capacity = capacity;
	HX_STACK_LINE(62)
	this->idxPos = (int)0;
	HX_STACK_LINE(63)
	this->idxCols = (int)0;
	HX_STACK_LINE(64)
	this->numVertices = (int)0;
	HX_STACK_LINE(67)
	this->vertices = ::openfl::utils::Float32Array_obj::__new(((capacity * (int)3) * (int)4),null(),null());
	HX_STACK_LINE(68)
	::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
	HX_STACK_LINE(69)
	::openfl::gl::GL_obj::bufferData((int)34962,this->vertices,(int)35048);
	HX_STACK_LINE(70)
	this->colors = ::openfl::utils::Float32Array_obj::__new(((capacity * (int)4) * (int)4),null(),null());
	HX_STACK_LINE(71)
	::openfl::gl::GL_obj::bindBuffer((int)34962,this->colorBuffer);
	HX_STACK_LINE(72)
	::openfl::gl::GL_obj::bufferData((int)34962,this->colors,(int)35048);
	HX_STACK_LINE(73)
	this->fillMode = false;
	HX_STACK_LINE(74)
	this->currentBlendMode = ::com::engine::render::BlendMode_obj::NORMAL;
	HX_STACK_LINE(75)
	this->shader = ::com::engine::render::PrimitiveShader_obj::__new();
}
;
	return null();
}

BatchPrimitives_obj::~BatchPrimitives_obj() { }

Dynamic BatchPrimitives_obj::__CreateEmpty() { return  new BatchPrimitives_obj; }
hx::ObjectPtr< BatchPrimitives_obj > BatchPrimitives_obj::__new(int capacity)
{  hx::ObjectPtr< BatchPrimitives_obj > result = new BatchPrimitives_obj();
	result->__construct(capacity);
	return result;}

Dynamic BatchPrimitives_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< BatchPrimitives_obj > result = new BatchPrimitives_obj();
	result->__construct(inArgs[0]);
	return result;}

Void BatchPrimitives_obj::dispose( ){
{
		HX_STACK_PUSH("BatchPrimitives::dispose","com/engine/render/BatchPrimitives.hx",288);
		HX_STACK_THIS(this);
		HX_STACK_LINE(289)
		this->vertices = ::openfl::utils::Float32Array_obj::__new(Dynamic( Array_obj<Dynamic>::__new()),null(),null());
		HX_STACK_LINE(290)
		this->colors = ::openfl::utils::Float32Array_obj::__new(Dynamic( Array_obj<Dynamic>::__new()),null(),null());
		HX_STACK_LINE(291)
		::openfl::gl::GL_obj::deleteBuffer(this->vertexBuffer);
		HX_STACK_LINE(292)
		::openfl::gl::GL_obj::deleteBuffer(this->colorBuffer);
		HX_STACK_LINE(294)
		this->super::dispose();
	}
return null();
}


Void BatchPrimitives_obj::fillrect( Float x,Float y,Float width,Float height,Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(1);
	HX_STACK_PUSH("BatchPrimitives::fillrect","com/engine/render/BatchPrimitives.hx",278);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(height,"height");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(280)
		this->vertex(x,y,(int)0);
		HX_STACK_LINE(280)
		this->color(r,g,b,a);
		HX_STACK_LINE(281)
		this->vertex((x + width),y,(int)0);
		HX_STACK_LINE(281)
		this->color(r,g,b,a);
		HX_STACK_LINE(282)
		this->vertex((x + width),(y + height),(int)0);
		HX_STACK_LINE(282)
		this->color(r,g,b,a);
		HX_STACK_LINE(283)
		this->vertex((x + width),(y + height),(int)0);
		HX_STACK_LINE(283)
		this->color(r,g,b,a);
		HX_STACK_LINE(284)
		this->vertex(x,(y + height),(int)0);
		HX_STACK_LINE(284)
		this->color(r,g,b,a);
		HX_STACK_LINE(285)
		this->vertex(x,y,(int)0);
		HX_STACK_LINE(285)
		this->color(r,g,b,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(BatchPrimitives_obj,fillrect,(void))

Void BatchPrimitives_obj::rect( Float x,Float y,Float width,Float height,Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(1);
	HX_STACK_PUSH("BatchPrimitives::rect","com/engine/render/BatchPrimitives.hx",266);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(height,"height");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(267)
		this->vertex(x,y,(int)0);
		HX_STACK_LINE(267)
		this->color(r,g,b,a);
		HX_STACK_LINE(268)
		this->vertex((x + width),y,(int)0);
		HX_STACK_LINE(268)
		this->color(r,g,b,a);
		HX_STACK_LINE(269)
		this->vertex((x + width),y,(int)0);
		HX_STACK_LINE(269)
		this->color(r,g,b,a);
		HX_STACK_LINE(270)
		this->vertex((x + width),(y + height),(int)0);
		HX_STACK_LINE(270)
		this->color(r,g,b,a);
		HX_STACK_LINE(271)
		this->vertex((x + width),(y + height),(int)0);
		HX_STACK_LINE(271)
		this->color(r,g,b,a);
		HX_STACK_LINE(272)
		this->vertex(x,(y + height),(int)0);
		HX_STACK_LINE(272)
		this->color(r,g,b,a);
		HX_STACK_LINE(273)
		this->vertex(x,(y + height),(int)0);
		HX_STACK_LINE(273)
		this->color(r,g,b,a);
		HX_STACK_LINE(274)
		this->vertex(x,y,(int)0);
		HX_STACK_LINE(274)
		this->color(r,g,b,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(BatchPrimitives_obj,rect,(void))

Void BatchPrimitives_obj::line( Float x1,Float y1,Float x2,Float y2,Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(1);
	HX_STACK_PUSH("BatchPrimitives::line","com/engine/render/BatchPrimitives.hx",257);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x1,"x1");
	HX_STACK_ARG(y1,"y1");
	HX_STACK_ARG(x2,"x2");
	HX_STACK_ARG(y2,"y2");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(259)
		this->vertex(x1,y1,null());
		HX_STACK_LINE(260)
		this->color(r,g,b,a);
		HX_STACK_LINE(261)
		this->vertex(x2,y2,null());
		HX_STACK_LINE(262)
		this->color(r,g,b,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(BatchPrimitives_obj,line,(void))

Void BatchPrimitives_obj::fillellipse( Float x,Float y,Float width,Float height,int segments,Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(1);
	HX_STACK_PUSH("BatchPrimitives::fillellipse","com/engine/render/BatchPrimitives.hx",234);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(height,"height");
	HX_STACK_ARG(segments,"segments");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(236)
		Float angle = (Float(6.2831852) / Float(segments));		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(238)
		Float cx = (x + (Float(width) / Float((int)2)));		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(239)
		Float cy = (y + (Float(height) / Float((int)2)));		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(242)
		{
			HX_STACK_LINE(242)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(242)
			while(((_g < segments))){
				HX_STACK_LINE(242)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(245)
				this->vertex((cx + ((width * 0.5) * ::Math_obj::cos((i * angle)))),(cy + ((height * 0.5) * ::Math_obj::sin((i * angle)))),(int)0);
				HX_STACK_LINE(246)
				this->color(r,g,b,a);
				HX_STACK_LINE(248)
				this->vertex(cx,cy,(int)0);
				HX_STACK_LINE(249)
				this->color(r,g,b,a);
				HX_STACK_LINE(251)
				this->vertex((cx + ((width * 0.5) * ::Math_obj::cos((((i + (int)1)) * angle)))),(cy + ((height * 0.5) * ::Math_obj::sin((((i + (int)1)) * angle)))),(int)0);
				HX_STACK_LINE(252)
				this->color(r,g,b,a);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(BatchPrimitives_obj,fillellipse,(void))

Void BatchPrimitives_obj::ellipse( Float x,Float y,Float width,Float height,int segments,Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(1);
	HX_STACK_PUSH("BatchPrimitives::ellipse","com/engine/render/BatchPrimitives.hx",213);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(width,"width");
	HX_STACK_ARG(height,"height");
	HX_STACK_ARG(segments,"segments");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(215)
		Float angle = (Float(6.2831852) / Float(segments));		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(217)
		Float cx = (x + (Float(width) / Float((int)2)));		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(218)
		Float cy = (y + (Float(height) / Float((int)2)));		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(221)
		{
			HX_STACK_LINE(221)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(221)
			while(((_g < segments))){
				HX_STACK_LINE(221)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(224)
				this->vertex((cx + ((width * 0.5) * ::Math_obj::cos((i * angle)))),(cy + ((height * 0.5) * ::Math_obj::sin((i * angle)))),(int)0);
				HX_STACK_LINE(225)
				this->color(r,g,b,a);
				HX_STACK_LINE(228)
				this->vertex((cx + ((width * 0.5) * ::Math_obj::cos((((i + (int)1)) * angle)))),(cy + ((height * 0.5) * ::Math_obj::sin((((i + (int)1)) * angle)))),(int)0);
				HX_STACK_LINE(229)
				this->color(r,g,b,a);
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(BatchPrimitives_obj,ellipse,(void))

Void BatchPrimitives_obj::fillcircle( Float x,Float y,Float radius,int segments,Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(1);
	HX_STACK_PUSH("BatchPrimitives::fillcircle","com/engine/render/BatchPrimitives.hx",179);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(radius,"radius");
	HX_STACK_ARG(segments,"segments");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(181)
		Float angle = (Float(6.2831852) / Float(segments));		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(182)
		Float cos = ::Math_obj::cos(angle);		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(183)
		Float sin = ::Math_obj::sin(angle);		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(184)
		Float cx = radius;		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(185)
		Float cy = (int)0;		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(186)
		(segments)--;
		HX_STACK_LINE(187)
		{
			HX_STACK_LINE(187)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(187)
			while(((_g < segments))){
				HX_STACK_LINE(187)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(189)
				this->vertex(x,y,(int)0);
				HX_STACK_LINE(189)
				this->color(r,g,b,a);
				HX_STACK_LINE(190)
				this->vertex((x + cx),(y + cy),(int)0);
				HX_STACK_LINE(190)
				this->color(r,g,b,a);
				HX_STACK_LINE(191)
				Float temp = cx;		HX_STACK_VAR(temp,"temp");
				HX_STACK_LINE(192)
				cx = ((cos * cx) - (sin * cy));
				HX_STACK_LINE(193)
				cy = ((sin * temp) + (cos * cy));
				HX_STACK_LINE(195)
				this->vertex((x + cx),(y + cy),(int)0);
				HX_STACK_LINE(195)
				this->color(r,g,b,a);
			}
		}
		HX_STACK_LINE(201)
		this->vertex(x,y,(int)0);
		HX_STACK_LINE(201)
		this->color(r,g,b,a);
		HX_STACK_LINE(202)
		this->vertex((x + cx),(y + cy),(int)0);
		HX_STACK_LINE(202)
		this->color(r,g,b,a);
		HX_STACK_LINE(205)
		Float temp = cx;		HX_STACK_VAR(temp,"temp");
		HX_STACK_LINE(206)
		cx = radius;
		HX_STACK_LINE(207)
		cy = (int)0;
		HX_STACK_LINE(209)
		this->vertex((x + cx),(y + cy),(int)0);
		HX_STACK_LINE(209)
		this->color(r,g,b,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(BatchPrimitives_obj,fillcircle,(void))

Void BatchPrimitives_obj::circle( Float x,Float y,Float radius,int segments,Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(1);
	HX_STACK_PUSH("BatchPrimitives::circle","com/engine/render/BatchPrimitives.hx",147);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(radius,"radius");
	HX_STACK_ARG(segments,"segments");
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(149)
		Float angle = (Float(6.2831852) / Float(segments));		HX_STACK_VAR(angle,"angle");
		HX_STACK_LINE(150)
		Float cos = ::Math_obj::cos(angle);		HX_STACK_VAR(cos,"cos");
		HX_STACK_LINE(151)
		Float sin = ::Math_obj::sin(angle);		HX_STACK_VAR(sin,"sin");
		HX_STACK_LINE(152)
		Float cx = radius;		HX_STACK_VAR(cx,"cx");
		HX_STACK_LINE(153)
		Float cy = (int)0;		HX_STACK_VAR(cy,"cy");
		HX_STACK_LINE(154)
		{
			HX_STACK_LINE(154)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(154)
			while(((_g < segments))){
				HX_STACK_LINE(154)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(157)
				this->vertex((x + cx),(y + cy),(int)0);
				HX_STACK_LINE(157)
				this->color(r,g,b,a);
				HX_STACK_LINE(158)
				Float temp = cx;		HX_STACK_VAR(temp,"temp");
				HX_STACK_LINE(159)
				cx = ((cos * cx) - (sin * cy));
				HX_STACK_LINE(160)
				cy = ((sin * temp) + (cos * cy));
				HX_STACK_LINE(162)
				this->vertex((x + cx),(y + cy),(int)0);
				HX_STACK_LINE(162)
				this->color(r,g,b,a);
			}
		}
		HX_STACK_LINE(165)
		this->vertex((x + cx),(y + cy),(int)0);
		HX_STACK_LINE(165)
		this->color(r,g,b,a);
		HX_STACK_LINE(167)
		this->vertex(x,y,(int)0);
		HX_STACK_LINE(167)
		this->color(r,g,b,a);
		HX_STACK_LINE(169)
		this->vertex((x + cx),(y + cy),(int)0);
		HX_STACK_LINE(169)
		this->color(r,g,b,a);
		HX_STACK_LINE(172)
		Float temp = cx;		HX_STACK_VAR(temp,"temp");
		HX_STACK_LINE(173)
		cx = radius;
		HX_STACK_LINE(174)
		cy = (int)0;
		HX_STACK_LINE(176)
		this->vertex((x + cx),(y + cy),(int)0);
		HX_STACK_LINE(176)
		this->color(r,g,b,a);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(BatchPrimitives_obj,circle,(void))

Void BatchPrimitives_obj::end( ){
{
		HX_STACK_PUSH("BatchPrimitives::end","com/engine/render/BatchPrimitives.hx",138);
		HX_STACK_THIS(this);
		HX_STACK_LINE(138)
		this->shader->Disable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BatchPrimitives_obj,end,(void))

Void BatchPrimitives_obj::begin( ){
{
		HX_STACK_PUSH("BatchPrimitives::begin","com/engine/render/BatchPrimitives.hx",131);
		HX_STACK_THIS(this);
		HX_STACK_LINE(132)
		this->shader->Enable();
		HX_STACK_LINE(133)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->projectionMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(::com::engine::game::Game_obj::projMatrix->m,null(),null()));
		HX_STACK_LINE(134)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->modelViewMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(this->viewMatrix->m,null(),null()));
		HX_STACK_LINE(135)
		::com::engine::render::BlendMode_obj::setBlend(this->currentBlendMode);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BatchPrimitives_obj,begin,(void))

Void BatchPrimitives_obj::render( ){
{
		HX_STACK_PUSH("BatchPrimitives::render","com/engine/render/BatchPrimitives.hx",108);
		HX_STACK_THIS(this);
		HX_STACK_LINE(111)
		::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
		HX_STACK_LINE(112)
		::openfl::gl::GL_obj::bufferSubData((int)34962,(int)0,this->vertices);
		HX_STACK_LINE(113)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->vertexAttribute,(int)3,(int)5126,false,(int)0,(int)0);
		HX_STACK_LINE(114)
		::openfl::gl::GL_obj::bindBuffer((int)34962,this->colorBuffer);
		HX_STACK_LINE(115)
		::openfl::gl::GL_obj::bufferSubData((int)34962,(int)0,this->colors);
		HX_STACK_LINE(116)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->colorAttribute,(int)4,(int)5126,false,(int)0,(int)0);
		HX_STACK_LINE(118)
		if (((this->fillMode == true))){
			HX_STACK_LINE(119)
			::openfl::gl::GL_obj::drawArrays((int)4,(int)0,::Std_obj::_int((Float(this->idxPos) / Float((int)3))));
		}
		else{
			HX_STACK_LINE(122)
			::openfl::gl::GL_obj::drawArrays((int)1,(int)0,::Std_obj::_int((Float(this->idxPos) / Float((int)3))));
		}
		HX_STACK_LINE(126)
		this->idxPos = (int)0;
		HX_STACK_LINE(127)
		this->idxCols = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(BatchPrimitives_obj,render,(void))

Void BatchPrimitives_obj::renderMode( hx::Null< bool >  __o_fill){
bool fill = __o_fill.Default(false);
	HX_STACK_PUSH("BatchPrimitives::renderMode","com/engine/render/BatchPrimitives.hx",100);
	HX_STACK_THIS(this);
	HX_STACK_ARG(fill,"fill");
{
		HX_STACK_LINE(101)
		this->idxPos = (int)0;
		HX_STACK_LINE(102)
		this->idxCols = (int)0;
		HX_STACK_LINE(103)
		this->numVertices = (int)0;
		HX_STACK_LINE(104)
		this->fillMode = fill;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(BatchPrimitives_obj,renderMode,(void))

Void BatchPrimitives_obj::color( Float r,Float g,Float b,Dynamic __o_a){
Dynamic a = __o_a.Default(0.0);
	HX_STACK_PUSH("BatchPrimitives::color","com/engine/render/BatchPrimitives.hx",90);
	HX_STACK_THIS(this);
	HX_STACK_ARG(r,"r");
	HX_STACK_ARG(g,"g");
	HX_STACK_ARG(b,"b");
	HX_STACK_ARG(a,"a");
{
		HX_STACK_LINE(91)
		hx::__ArrayImplRef(this->colors,(this->idxCols)++) = r;
		HX_STACK_LINE(92)
		hx::__ArrayImplRef(this->colors,(this->idxCols)++) = g;
		HX_STACK_LINE(93)
		hx::__ArrayImplRef(this->colors,(this->idxCols)++) = b;
		HX_STACK_LINE(94)
		hx::__ArrayImplRef(this->colors,(this->idxCols)++) = a;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(BatchPrimitives_obj,color,(void))

Void BatchPrimitives_obj::vertex( Float x,Float y,Dynamic __o_z){
Dynamic z = __o_z.Default(0.0);
	HX_STACK_PUSH("BatchPrimitives::vertex","com/engine/render/BatchPrimitives.hx",83);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_ARG(z,"z");
{
		HX_STACK_LINE(84)
		hx::__ArrayImplRef(this->vertices,(this->idxPos)++) = x;
		HX_STACK_LINE(85)
		hx::__ArrayImplRef(this->vertices,(this->idxPos)++) = y;
		HX_STACK_LINE(86)
		hx::__ArrayImplRef(this->vertices,(this->idxPos)++) = z;
		HX_STACK_LINE(87)
		(this->numVertices)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(BatchPrimitives_obj,vertex,(void))


BatchPrimitives_obj::BatchPrimitives_obj()
{
}

void BatchPrimitives_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(BatchPrimitives);
	HX_MARK_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_MARK_MEMBER_NAME(vertexDeclaration,"vertexDeclaration");
	HX_MARK_MEMBER_NAME(shader,"shader");
	HX_MARK_MEMBER_NAME(numVertices,"numVertices");
	HX_MARK_MEMBER_NAME(idxPos,"idxPos");
	HX_MARK_MEMBER_NAME(idxCols,"idxCols");
	HX_MARK_MEMBER_NAME(currentBlendMode,"currentBlendMode");
	HX_MARK_MEMBER_NAME(fillMode,"fillMode");
	HX_MARK_MEMBER_NAME(capacity,"capacity");
	HX_MARK_MEMBER_NAME(vertices,"vertices");
	HX_MARK_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_MARK_MEMBER_NAME(colors,"colors");
	HX_MARK_MEMBER_NAME(colorIndex,"colorIndex");
	HX_MARK_MEMBER_NAME(colorBuffer,"colorBuffer");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void BatchPrimitives_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_VISIT_MEMBER_NAME(vertexDeclaration,"vertexDeclaration");
	HX_VISIT_MEMBER_NAME(shader,"shader");
	HX_VISIT_MEMBER_NAME(numVertices,"numVertices");
	HX_VISIT_MEMBER_NAME(idxPos,"idxPos");
	HX_VISIT_MEMBER_NAME(idxCols,"idxCols");
	HX_VISIT_MEMBER_NAME(currentBlendMode,"currentBlendMode");
	HX_VISIT_MEMBER_NAME(fillMode,"fillMode");
	HX_VISIT_MEMBER_NAME(capacity,"capacity");
	HX_VISIT_MEMBER_NAME(vertices,"vertices");
	HX_VISIT_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_VISIT_MEMBER_NAME(colors,"colors");
	HX_VISIT_MEMBER_NAME(colorIndex,"colorIndex");
	HX_VISIT_MEMBER_NAME(colorBuffer,"colorBuffer");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic BatchPrimitives_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { return end_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"rect") ) { return rect_dyn(); }
		if (HX_FIELD_EQ(inName,"line") ) { return line_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"begin") ) { return begin_dyn(); }
		if (HX_FIELD_EQ(inName,"color") ) { return color_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"circle") ) { return circle_dyn(); }
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"vertex") ) { return vertex_dyn(); }
		if (HX_FIELD_EQ(inName,"shader") ) { return shader; }
		if (HX_FIELD_EQ(inName,"idxPos") ) { return idxPos; }
		if (HX_FIELD_EQ(inName,"colors") ) { return colors; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"ellipse") ) { return ellipse_dyn(); }
		if (HX_FIELD_EQ(inName,"idxCols") ) { return idxCols; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fillrect") ) { return fillrect_dyn(); }
		if (HX_FIELD_EQ(inName,"fillMode") ) { return fillMode; }
		if (HX_FIELD_EQ(inName,"capacity") ) { return capacity; }
		if (HX_FIELD_EQ(inName,"vertices") ) { return vertices; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"fillcircle") ) { return fillcircle_dyn(); }
		if (HX_FIELD_EQ(inName,"renderMode") ) { return renderMode_dyn(); }
		if (HX_FIELD_EQ(inName,"colorIndex") ) { return colorIndex; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"fillellipse") ) { return fillellipse_dyn(); }
		if (HX_FIELD_EQ(inName,"numVertices") ) { return numVertices; }
		if (HX_FIELD_EQ(inName,"colorBuffer") ) { return colorBuffer; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { return vertexBuffer; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"vertexStrideSize") ) { return vertexStrideSize; }
		if (HX_FIELD_EQ(inName,"currentBlendMode") ) { return currentBlendMode; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"vertexDeclaration") ) { return vertexDeclaration; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic BatchPrimitives_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { shader=inValue.Cast< ::com::engine::render::PrimitiveShader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"idxPos") ) { idxPos=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"colors") ) { colors=inValue.Cast< ::openfl::utils::Float32Array >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"idxCols") ) { idxCols=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"fillMode") ) { fillMode=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"capacity") ) { capacity=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vertices") ) { vertices=inValue.Cast< ::openfl::utils::Float32Array >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"colorIndex") ) { colorIndex=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"numVertices") ) { numVertices=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"colorBuffer") ) { colorBuffer=inValue.Cast< ::openfl::gl::GLBuffer >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { vertexBuffer=inValue.Cast< ::openfl::gl::GLBuffer >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"vertexStrideSize") ) { vertexStrideSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentBlendMode") ) { currentBlendMode=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"vertexDeclaration") ) { vertexDeclaration=inValue.Cast< Array< int > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void BatchPrimitives_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("vertexStrideSize"));
	outFields->push(HX_CSTRING("vertexDeclaration"));
	outFields->push(HX_CSTRING("shader"));
	outFields->push(HX_CSTRING("numVertices"));
	outFields->push(HX_CSTRING("idxPos"));
	outFields->push(HX_CSTRING("idxCols"));
	outFields->push(HX_CSTRING("currentBlendMode"));
	outFields->push(HX_CSTRING("fillMode"));
	outFields->push(HX_CSTRING("capacity"));
	outFields->push(HX_CSTRING("vertices"));
	outFields->push(HX_CSTRING("vertexBuffer"));
	outFields->push(HX_CSTRING("colors"));
	outFields->push(HX_CSTRING("colorIndex"));
	outFields->push(HX_CSTRING("colorBuffer"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("fillrect"),
	HX_CSTRING("rect"),
	HX_CSTRING("line"),
	HX_CSTRING("fillellipse"),
	HX_CSTRING("ellipse"),
	HX_CSTRING("fillcircle"),
	HX_CSTRING("circle"),
	HX_CSTRING("end"),
	HX_CSTRING("begin"),
	HX_CSTRING("render"),
	HX_CSTRING("renderMode"),
	HX_CSTRING("color"),
	HX_CSTRING("vertex"),
	HX_CSTRING("vertexStrideSize"),
	HX_CSTRING("vertexDeclaration"),
	HX_CSTRING("shader"),
	HX_CSTRING("numVertices"),
	HX_CSTRING("idxPos"),
	HX_CSTRING("idxCols"),
	HX_CSTRING("currentBlendMode"),
	HX_CSTRING("fillMode"),
	HX_CSTRING("capacity"),
	HX_CSTRING("vertices"),
	HX_CSTRING("vertexBuffer"),
	HX_CSTRING("colors"),
	HX_CSTRING("colorIndex"),
	HX_CSTRING("colorBuffer"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(BatchPrimitives_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(BatchPrimitives_obj::__mClass,"__mClass");
};

Class BatchPrimitives_obj::__mClass;

void BatchPrimitives_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.BatchPrimitives"), hx::TCanCast< BatchPrimitives_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void BatchPrimitives_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
