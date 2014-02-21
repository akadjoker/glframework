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
#ifndef INCLUDED_com_engine_render_BlendMode
#include <com/engine/render/BlendMode.h>
#endif
#ifndef INCLUDED_com_engine_render_Buffer
#include <com/engine/render/Buffer.h>
#endif
#ifndef INCLUDED_com_engine_render_Clip
#include <com/engine/render/Clip.h>
#endif
#ifndef INCLUDED_com_engine_render_Image
#include <com/engine/render/Image.h>
#endif
#ifndef INCLUDED_com_engine_render_SpriteCloud
#include <com/engine/render/SpriteCloud.h>
#endif
#ifndef INCLUDED_com_engine_render_SpriteShader
#include <com/engine/render/SpriteShader.h>
#endif
#ifndef INCLUDED_com_engine_render_Texture
#include <com/engine/render/Texture.h>
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
#ifndef INCLUDED_openfl_utils_Int16Array
#include <openfl/utils/Int16Array.h>
#endif
namespace com{
namespace engine{
namespace render{

Void SpriteCloud_obj::__construct(::com::engine::render::Texture texture,int capacity)
{
HX_STACK_PUSH("SpriteCloud::new","com/engine/render/SpriteCloud.hx",25);
{
	HX_STACK_LINE(42)
	this->invTexHeight = (int)0;
	HX_STACK_LINE(41)
	this->invTexWidth = (int)0;
	HX_STACK_LINE(54)
	super::__construct();
	HX_STACK_LINE(55)
	this->capacity = capacity;
	HX_STACK_LINE(60)
	this->vertexDeclaration = Array_obj< int >::__new().Add((int)3).Add((int)2).Add((int)4);
	HX_STACK_LINE(61)
	this->vertexStrideSize = (int)36;
	HX_STACK_LINE(64)
	this->index = (int)0;
	HX_STACK_LINE(66)
	this->tmpVertices = ::openfl::utils::Float32Array_obj::__new((capacity * this->vertexStrideSize),null(),null());
	HX_STACK_LINE(69)
	this->drawing = false;
	HX_STACK_LINE(70)
	this->currentBatchSize = (int)0;
	HX_STACK_LINE(71)
	this->currentBlendMode = ::com::engine::render::BlendMode_obj::NORMAL;
	HX_STACK_LINE(72)
	this->currentBaseTexture = texture;
	HX_STACK_LINE(73)
	this->invTexWidth = (Float(1.0) / Float(texture->width));
	HX_STACK_LINE(74)
	this->invTexHeight = (Float(1.0) / Float(texture->height));
	HX_STACK_LINE(79)
	this->vertexBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(80)
	this->indexBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(83)
	this->shader = ::com::engine::render::SpriteShader_obj::__new();
	HX_STACK_LINE(85)
	this->rebuid = false;
}
;
	return null();
}

SpriteCloud_obj::~SpriteCloud_obj() { }

Dynamic SpriteCloud_obj::__CreateEmpty() { return  new SpriteCloud_obj; }
hx::ObjectPtr< SpriteCloud_obj > SpriteCloud_obj::__new(::com::engine::render::Texture texture,int capacity)
{  hx::ObjectPtr< SpriteCloud_obj > result = new SpriteCloud_obj();
	result->__construct(texture,capacity);
	return result;}

Dynamic SpriteCloud_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SpriteCloud_obj > result = new SpriteCloud_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void SpriteCloud_obj::render( ){
{
		HX_STACK_PUSH("SpriteCloud::render","com/engine/render/SpriteCloud.hx",370);
		HX_STACK_THIS(this);
		HX_STACK_LINE(371)
		this->update();
		HX_STACK_LINE(372)
		if ((!(this->rebuid))){
			HX_STACK_LINE(374)
			this->rebuid = true;
			HX_STACK_LINE(375)
			this->build();
			HX_STACK_LINE(376)
			return null();
		}
		HX_STACK_LINE(379)
		if (((this->currentBatchSize == (int)0))){
			HX_STACK_LINE(379)
			return null();
		}
		HX_STACK_LINE(380)
		this->shader->Enable();
		HX_STACK_LINE(383)
		::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
		HX_STACK_LINE(384)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->vertexAttribute,(int)3,(int)5126,false,this->vertexStrideSize,(int)0);
		HX_STACK_LINE(385)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->texCoordAttribute,(int)2,(int)5126,false,this->vertexStrideSize,(int)12);
		HX_STACK_LINE(386)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->colorAttribute,(int)4,(int)5126,false,this->vertexStrideSize,(int)20);
		HX_STACK_LINE(387)
		::com::engine::render::BlendMode_obj::setBlend(this->currentBlendMode);
		HX_STACK_LINE(388)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->modelViewMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(this->viewMatrix->m,null(),null()));
		HX_STACK_LINE(389)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->projectionMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(::com::engine::game::Game_obj::projMatrix->m,null(),null()));
		HX_STACK_LINE(390)
		::openfl::gl::GL_obj::activeTexture((int)33984);
		HX_STACK_LINE(391)
		this->currentBaseTexture->Bind();
		HX_STACK_LINE(392)
		::openfl::gl::GL_obj::uniform1i(this->shader->imageUniform,(int)0);
		HX_STACK_LINE(393)
		::openfl::gl::GL_obj::bindBuffer((int)34963,this->indexBuffer);
		HX_STACK_LINE(394)
		::openfl::gl::GL_obj::drawElements((int)4,(this->currentBatchSize * (int)6),(int)5123,(int)0);
		HX_STACK_LINE(395)
		this->shader->Disable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteCloud_obj,render,(void))

Void SpriteCloud_obj::addVertex( Float x,Float y,Float u,Float v){
{
		HX_STACK_PUSH("SpriteCloud::addVertex","com/engine/render/SpriteCloud.hx",359);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(u,"u");
		HX_STACK_ARG(v,"v");
		HX_STACK_LINE(360)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = x;
		HX_STACK_LINE(361)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = y;
		HX_STACK_LINE(362)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(363)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u;
		HX_STACK_LINE(363)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v;
		HX_STACK_LINE(364)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)1;
		HX_STACK_LINE(364)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)1;
		HX_STACK_LINE(364)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)1;
		HX_STACK_LINE(364)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)1;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SpriteCloud_obj,addVertex,(void))

Void SpriteCloud_obj::addTile( Float x,Float y,Float width,Float height,::com::engine::render::Clip clip,bool flipx,bool flipy){
{
		HX_STACK_PUSH("SpriteCloud::addTile","com/engine/render/SpriteCloud.hx",287);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_ARG(clip,"clip");
		HX_STACK_ARG(flipx,"flipx");
		HX_STACK_ARG(flipy,"flipy");
		HX_STACK_LINE(288)
		int r;		HX_STACK_VAR(r,"r");
		int g;		HX_STACK_VAR(g,"g");
		int b;		HX_STACK_VAR(b,"b");
		Float a;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(289)
		r = (int)1;
		HX_STACK_LINE(290)
		g = (int)1;
		HX_STACK_LINE(291)
		b = (int)1;
		HX_STACK_LINE(292)
		a = (int)1;
		HX_STACK_LINE(297)
		Float fx2 = (x + width);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(298)
		Float fy2 = (y + height);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(305)
		Float u = (clip->x * this->invTexWidth);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(306)
		Float u2 = (((clip->x + clip->width)) * this->invTexWidth);		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(308)
		Float v = (((clip->y + clip->height)) * this->invTexHeight);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(309)
		Float v2 = (clip->y * this->invTexHeight);		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(311)
		if ((flipx)){
			HX_STACK_LINE(313)
			Float tmp = u;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(314)
			u = u2;
			HX_STACK_LINE(315)
			u2 = tmp;
		}
		HX_STACK_LINE(318)
		if ((flipy)){
			HX_STACK_LINE(320)
			Float tmp = v;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(321)
			v = v2;
			HX_STACK_LINE(322)
			v2 = tmp;
		}
		HX_STACK_LINE(325)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = x;
		HX_STACK_LINE(326)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = y;
		HX_STACK_LINE(327)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(328)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u;
		HX_STACK_LINE(328)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v;
		HX_STACK_LINE(329)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(329)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(329)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(329)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(331)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = x;
		HX_STACK_LINE(332)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = fy2;
		HX_STACK_LINE(333)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(334)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u;
		HX_STACK_LINE(334)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v2;
		HX_STACK_LINE(335)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(335)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(335)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(335)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(337)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = fx2;
		HX_STACK_LINE(338)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = fy2;
		HX_STACK_LINE(339)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(340)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u2;
		HX_STACK_LINE(340)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v2;
		HX_STACK_LINE(341)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(341)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(341)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(341)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(343)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = fx2;
		HX_STACK_LINE(344)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = y;
		HX_STACK_LINE(345)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(346)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u2;
		HX_STACK_LINE(346)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v;
		HX_STACK_LINE(347)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(347)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(347)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(347)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(354)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(SpriteCloud_obj,addTile,(void))

Void SpriteCloud_obj::add( ){
{
		HX_STACK_PUSH("SpriteCloud::add","com/engine/render/SpriteCloud.hx",283);
		HX_STACK_THIS(this);
		HX_STACK_LINE(283)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteCloud_obj,add,(void))

Void SpriteCloud_obj::addImage( ::com::engine::render::Image img){
{
		HX_STACK_PUSH("SpriteCloud::addImage","com/engine/render/SpriteCloud.hx",147);
		HX_STACK_THIS(this);
		HX_STACK_ARG(img,"img");
		HX_STACK_LINE(148)
		Float r;		HX_STACK_VAR(r,"r");
		Float g;		HX_STACK_VAR(g,"g");
		Float b;		HX_STACK_VAR(b,"b");
		Float a;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(149)
		r = img->red;
		HX_STACK_LINE(150)
		g = img->green;
		HX_STACK_LINE(151)
		b = img->blue;
		HX_STACK_LINE(152)
		a = img->alpha;
		HX_STACK_LINE(157)
		Float worldOriginX = (img->x + img->originX);		HX_STACK_VAR(worldOriginX,"worldOriginX");
		HX_STACK_LINE(158)
		Float worldOriginY = (img->y + img->originY);		HX_STACK_VAR(worldOriginY,"worldOriginY");
		HX_STACK_LINE(159)
		Float fx = -(img->originX);		HX_STACK_VAR(fx,"fx");
		HX_STACK_LINE(160)
		Float fy = -(img->originY);		HX_STACK_VAR(fy,"fy");
		HX_STACK_LINE(161)
		Float fx2 = (img->width - img->originX);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(162)
		Float fy2 = (img->height - img->originY);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(164)
		if (((bool((img->scaleX != (int)1)) || bool((img->scaleY != (int)1))))){
			HX_STACK_LINE(166)
			hx::MultEq(fx,img->scaleX);
			HX_STACK_LINE(167)
			hx::MultEq(fy,img->scaleY);
			HX_STACK_LINE(168)
			hx::MultEq(fx2,img->scaleX);
			HX_STACK_LINE(169)
			hx::MultEq(fy2,img->scaleY);
		}
		HX_STACK_LINE(172)
		Float p1x = fx;		HX_STACK_VAR(p1x,"p1x");
		HX_STACK_LINE(173)
		Float p1y = fy;		HX_STACK_VAR(p1y,"p1y");
		HX_STACK_LINE(174)
		Float p2x = fx;		HX_STACK_VAR(p2x,"p2x");
		HX_STACK_LINE(175)
		Float p2y = fy2;		HX_STACK_VAR(p2y,"p2y");
		HX_STACK_LINE(176)
		Float p3x = fx2;		HX_STACK_VAR(p3x,"p3x");
		HX_STACK_LINE(177)
		Float p3y = fy2;		HX_STACK_VAR(p3y,"p3y");
		HX_STACK_LINE(178)
		Float p4x = fx2;		HX_STACK_VAR(p4x,"p4x");
		HX_STACK_LINE(179)
		Float p4y = fy;		HX_STACK_VAR(p4y,"p4y");
		HX_STACK_LINE(181)
		Float x1;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(182)
		Float y1;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(183)
		Float x2;		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(184)
		Float y2;		HX_STACK_VAR(y2,"y2");
		HX_STACK_LINE(185)
		Float x3;		HX_STACK_VAR(x3,"x3");
		HX_STACK_LINE(186)
		Float y3;		HX_STACK_VAR(y3,"y3");
		HX_STACK_LINE(187)
		Float x4;		HX_STACK_VAR(x4,"x4");
		HX_STACK_LINE(188)
		Float y4;		HX_STACK_VAR(y4,"y4");
		HX_STACK_LINE(192)
		if (((img->angle != (int)0))){
			HX_STACK_LINE(195)
			Float angle = (Float((img->angle * ::Math_obj::PI)) / Float((int)180));		HX_STACK_VAR(angle,"angle");
			HX_STACK_LINE(196)
			Float cos = ::Math_obj::cos(angle);		HX_STACK_VAR(cos,"cos");
			HX_STACK_LINE(197)
			Float sin = ::Math_obj::sin(angle);		HX_STACK_VAR(sin,"sin");
			HX_STACK_LINE(199)
			x1 = ((cos * p1x) - (sin * p1y));
			HX_STACK_LINE(200)
			y1 = ((sin * p1x) + (cos * p1y));
			HX_STACK_LINE(202)
			x2 = ((cos * p2x) - (sin * p2y));
			HX_STACK_LINE(203)
			y2 = ((sin * p2x) + (cos * p2y));
			HX_STACK_LINE(205)
			x3 = ((cos * p3x) - (sin * p3y));
			HX_STACK_LINE(206)
			y3 = ((sin * p3x) + (cos * p3y));
			HX_STACK_LINE(208)
			x4 = (x1 + ((x3 - x2)));
			HX_STACK_LINE(209)
			y4 = (y3 - ((y2 - y1)));
		}
		else{
			HX_STACK_LINE(211)
			x1 = p1x;
			HX_STACK_LINE(212)
			y1 = p1y;
			HX_STACK_LINE(214)
			x2 = p2x;
			HX_STACK_LINE(215)
			y2 = p2y;
			HX_STACK_LINE(217)
			x3 = p3x;
			HX_STACK_LINE(218)
			y3 = p3y;
			HX_STACK_LINE(220)
			x4 = p4x;
			HX_STACK_LINE(221)
			y4 = p4y;
		}
		HX_STACK_LINE(224)
		hx::AddEq(x1,worldOriginX);
		HX_STACK_LINE(225)
		hx::AddEq(y1,worldOriginY);
		HX_STACK_LINE(226)
		hx::AddEq(x2,worldOriginX);
		HX_STACK_LINE(227)
		hx::AddEq(y2,worldOriginY);
		HX_STACK_LINE(228)
		hx::AddEq(x3,worldOriginX);
		HX_STACK_LINE(229)
		hx::AddEq(y3,worldOriginY);
		HX_STACK_LINE(230)
		hx::AddEq(x4,worldOriginX);
		HX_STACK_LINE(231)
		hx::AddEq(y4,worldOriginY);
		HX_STACK_LINE(234)
		Float u = (img->clip->x * this->invTexWidth);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(235)
		Float u2 = (((img->clip->x + img->clip->width)) * this->invTexWidth);		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(237)
		Float v = (((img->clip->y + img->clip->height)) * this->invTexHeight);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(238)
		Float v2 = (img->clip->y * this->invTexHeight);		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(241)
		if ((img->flipX)){
			HX_STACK_LINE(242)
			Float tmp = u;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(243)
			u = u2;
			HX_STACK_LINE(244)
			u2 = tmp;
		}
		HX_STACK_LINE(247)
		if ((img->flipY)){
			HX_STACK_LINE(248)
			Float tmp = v;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(249)
			v = v2;
			HX_STACK_LINE(250)
			v2 = tmp;
		}
		HX_STACK_LINE(253)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = x1;
		HX_STACK_LINE(254)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = y1;
		HX_STACK_LINE(255)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(256)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u;
		HX_STACK_LINE(256)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v;
		HX_STACK_LINE(257)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(257)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(257)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(257)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(259)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = x2;
		HX_STACK_LINE(260)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = y2;
		HX_STACK_LINE(261)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(262)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u;
		HX_STACK_LINE(262)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v2;
		HX_STACK_LINE(263)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(263)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(263)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(263)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(265)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = x3;
		HX_STACK_LINE(266)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = y3;
		HX_STACK_LINE(267)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(268)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u2;
		HX_STACK_LINE(268)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v2;
		HX_STACK_LINE(269)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(269)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(269)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(269)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(271)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = x4;
		HX_STACK_LINE(272)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = y4;
		HX_STACK_LINE(273)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = (int)0;
		HX_STACK_LINE(274)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = u2;
		HX_STACK_LINE(274)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = v;
		HX_STACK_LINE(275)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = r;
		HX_STACK_LINE(275)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = g;
		HX_STACK_LINE(275)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = b;
		HX_STACK_LINE(275)
		hx::__ArrayImplRef(this->tmpVertices,(this->index)++) = a;
		HX_STACK_LINE(278)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SpriteCloud_obj,addImage,(void))

Void SpriteCloud_obj::dispose( ){
{
		HX_STACK_PUSH("SpriteCloud::dispose","com/engine/render/SpriteCloud.hx",135);
		HX_STACK_THIS(this);
		HX_STACK_LINE(136)
		this->indices = null();
		HX_STACK_LINE(137)
		this->vertices = null();
		HX_STACK_LINE(138)
		::openfl::gl::GL_obj::deleteBuffer(this->indexBuffer);
		HX_STACK_LINE(139)
		::openfl::gl::GL_obj::deleteBuffer(this->vertexBuffer);
		HX_STACK_LINE(140)
		this->super::dispose();
	}
return null();
}


Void SpriteCloud_obj::build( ){
{
		HX_STACK_PUSH("SpriteCloud::build","com/engine/render/SpriteCloud.hx",89);
		HX_STACK_THIS(this);
		HX_STACK_LINE(91)
		this->numVerts = ((this->tmpVertices->length * this->vertexStrideSize) * (int)4);
		HX_STACK_LINE(92)
		this->numIndices = (this->tmpVertices->length * (int)6);
		HX_STACK_LINE(95)
		this->vertices = ::openfl::utils::Float32Array_obj::__new(this->numVerts,null(),null());
		HX_STACK_LINE(97)
		{
			HX_STACK_LINE(97)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->tmpVertices->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(97)
			while(((_g1 < _g))){
				HX_STACK_LINE(97)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(99)
				hx::__ArrayImplRef(this->vertices,i) = this->tmpVertices->__get(i);
			}
		}
		HX_STACK_LINE(101)
		this->tmpVertices = null();
		HX_STACK_LINE(105)
		this->indices = ::openfl::utils::Int16Array_obj::__new(this->numIndices,null(),null());
		HX_STACK_LINE(106)
		int length = ::Std_obj::_int((Float(this->indices->length) / Float((int)6)));		HX_STACK_VAR(length,"length");
		HX_STACK_LINE(108)
		{
			HX_STACK_LINE(108)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(108)
			while(((_g < length))){
				HX_STACK_LINE(108)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(110)
				int index2 = (i * (int)6);		HX_STACK_VAR(index2,"index2");
				HX_STACK_LINE(111)
				int index3 = (i * (int)4);		HX_STACK_VAR(index3,"index3");
				HX_STACK_LINE(112)
				hx::__ArrayImplRef(this->indices,index2) = index3;
				HX_STACK_LINE(113)
				hx::__ArrayImplRef(this->indices,(index2 + (int)1)) = (index3 + (int)1);
				HX_STACK_LINE(114)
				hx::__ArrayImplRef(this->indices,(index2 + (int)2)) = (index3 + (int)2);
				HX_STACK_LINE(115)
				hx::__ArrayImplRef(this->indices,(index2 + (int)3)) = index3;
				HX_STACK_LINE(116)
				hx::__ArrayImplRef(this->indices,(index2 + (int)4)) = (index3 + (int)2);
				HX_STACK_LINE(117)
				hx::__ArrayImplRef(this->indices,(index2 + (int)5)) = (index3 + (int)3);
			}
		}
		HX_STACK_LINE(123)
		::openfl::gl::GL_obj::bindBuffer((int)34963,this->indexBuffer);
		HX_STACK_LINE(124)
		::openfl::gl::GL_obj::bufferData((int)34963,this->indices,(int)35044);
		HX_STACK_LINE(125)
		::openfl::gl::GL_obj::bindBuffer((int)34963,null());
		HX_STACK_LINE(127)
		::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
		HX_STACK_LINE(128)
		::openfl::gl::GL_obj::bufferData((int)34962,this->vertices,(int)35044);
		HX_STACK_LINE(129)
		::openfl::gl::GL_obj::bindBuffer((int)34962,null());
		HX_STACK_LINE(130)
		this->rebuid = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteCloud_obj,build,(void))


SpriteCloud_obj::SpriteCloud_obj()
{
}

void SpriteCloud_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SpriteCloud);
	HX_MARK_MEMBER_NAME(rebuid,"rebuid");
	HX_MARK_MEMBER_NAME(index,"index");
	HX_MARK_MEMBER_NAME(shader,"shader");
	HX_MARK_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_MARK_MEMBER_NAME(vertexDeclaration,"vertexDeclaration");
	HX_MARK_MEMBER_NAME(invTexHeight,"invTexHeight");
	HX_MARK_MEMBER_NAME(invTexWidth,"invTexWidth");
	HX_MARK_MEMBER_NAME(indexBuffer,"indexBuffer");
	HX_MARK_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_MARK_MEMBER_NAME(currentBaseTexture,"currentBaseTexture");
	HX_MARK_MEMBER_NAME(currentBlendMode,"currentBlendMode");
	HX_MARK_MEMBER_NAME(currentBatchSize,"currentBatchSize");
	HX_MARK_MEMBER_NAME(drawing,"drawing");
	HX_MARK_MEMBER_NAME(lastIndexCount,"lastIndexCount");
	HX_MARK_MEMBER_NAME(indices,"indices");
	HX_MARK_MEMBER_NAME(vertices,"vertices");
	HX_MARK_MEMBER_NAME(tmpVertices,"tmpVertices");
	HX_MARK_MEMBER_NAME(numIndices,"numIndices");
	HX_MARK_MEMBER_NAME(numVerts,"numVerts");
	HX_MARK_MEMBER_NAME(capacity,"capacity");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SpriteCloud_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rebuid,"rebuid");
	HX_VISIT_MEMBER_NAME(index,"index");
	HX_VISIT_MEMBER_NAME(shader,"shader");
	HX_VISIT_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_VISIT_MEMBER_NAME(vertexDeclaration,"vertexDeclaration");
	HX_VISIT_MEMBER_NAME(invTexHeight,"invTexHeight");
	HX_VISIT_MEMBER_NAME(invTexWidth,"invTexWidth");
	HX_VISIT_MEMBER_NAME(indexBuffer,"indexBuffer");
	HX_VISIT_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_VISIT_MEMBER_NAME(currentBaseTexture,"currentBaseTexture");
	HX_VISIT_MEMBER_NAME(currentBlendMode,"currentBlendMode");
	HX_VISIT_MEMBER_NAME(currentBatchSize,"currentBatchSize");
	HX_VISIT_MEMBER_NAME(drawing,"drawing");
	HX_VISIT_MEMBER_NAME(lastIndexCount,"lastIndexCount");
	HX_VISIT_MEMBER_NAME(indices,"indices");
	HX_VISIT_MEMBER_NAME(vertices,"vertices");
	HX_VISIT_MEMBER_NAME(tmpVertices,"tmpVertices");
	HX_VISIT_MEMBER_NAME(numIndices,"numIndices");
	HX_VISIT_MEMBER_NAME(numVerts,"numVerts");
	HX_VISIT_MEMBER_NAME(capacity,"capacity");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SpriteCloud_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"build") ) { return build_dyn(); }
		if (HX_FIELD_EQ(inName,"index") ) { return index; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"rebuid") ) { return rebuid; }
		if (HX_FIELD_EQ(inName,"shader") ) { return shader; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"addTile") ) { return addTile_dyn(); }
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"drawing") ) { return drawing; }
		if (HX_FIELD_EQ(inName,"indices") ) { return indices; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addImage") ) { return addImage_dyn(); }
		if (HX_FIELD_EQ(inName,"vertices") ) { return vertices; }
		if (HX_FIELD_EQ(inName,"numVerts") ) { return numVerts; }
		if (HX_FIELD_EQ(inName,"capacity") ) { return capacity; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addVertex") ) { return addVertex_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"numIndices") ) { return numIndices; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"invTexWidth") ) { return invTexWidth; }
		if (HX_FIELD_EQ(inName,"indexBuffer") ) { return indexBuffer; }
		if (HX_FIELD_EQ(inName,"tmpVertices") ) { return tmpVertices; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"invTexHeight") ) { return invTexHeight; }
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { return vertexBuffer; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"lastIndexCount") ) { return lastIndexCount; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"vertexStrideSize") ) { return vertexStrideSize; }
		if (HX_FIELD_EQ(inName,"currentBlendMode") ) { return currentBlendMode; }
		if (HX_FIELD_EQ(inName,"currentBatchSize") ) { return currentBatchSize; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"vertexDeclaration") ) { return vertexDeclaration; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"currentBaseTexture") ) { return currentBaseTexture; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic SpriteCloud_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"index") ) { index=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"rebuid") ) { rebuid=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"shader") ) { shader=inValue.Cast< ::com::engine::render::SpriteShader >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"drawing") ) { drawing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indices") ) { indices=inValue.Cast< ::openfl::utils::Int16Array >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"vertices") ) { vertices=inValue.Cast< ::openfl::utils::Float32Array >(); return inValue; }
		if (HX_FIELD_EQ(inName,"numVerts") ) { numVerts=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"capacity") ) { capacity=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"numIndices") ) { numIndices=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"invTexWidth") ) { invTexWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexBuffer") ) { indexBuffer=inValue.Cast< ::openfl::gl::GLBuffer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tmpVertices") ) { tmpVertices=inValue.Cast< ::openfl::utils::Float32Array >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"invTexHeight") ) { invTexHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { vertexBuffer=inValue.Cast< ::openfl::gl::GLBuffer >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"lastIndexCount") ) { lastIndexCount=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"vertexStrideSize") ) { vertexStrideSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentBlendMode") ) { currentBlendMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentBatchSize") ) { currentBatchSize=inValue.Cast< int >(); return inValue; }
		break;
	case 17:
		if (HX_FIELD_EQ(inName,"vertexDeclaration") ) { vertexDeclaration=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"currentBaseTexture") ) { currentBaseTexture=inValue.Cast< ::com::engine::render::Texture >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void SpriteCloud_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rebuid"));
	outFields->push(HX_CSTRING("index"));
	outFields->push(HX_CSTRING("shader"));
	outFields->push(HX_CSTRING("vertexStrideSize"));
	outFields->push(HX_CSTRING("vertexDeclaration"));
	outFields->push(HX_CSTRING("invTexHeight"));
	outFields->push(HX_CSTRING("invTexWidth"));
	outFields->push(HX_CSTRING("indexBuffer"));
	outFields->push(HX_CSTRING("vertexBuffer"));
	outFields->push(HX_CSTRING("currentBaseTexture"));
	outFields->push(HX_CSTRING("currentBlendMode"));
	outFields->push(HX_CSTRING("currentBatchSize"));
	outFields->push(HX_CSTRING("drawing"));
	outFields->push(HX_CSTRING("lastIndexCount"));
	outFields->push(HX_CSTRING("indices"));
	outFields->push(HX_CSTRING("vertices"));
	outFields->push(HX_CSTRING("tmpVertices"));
	outFields->push(HX_CSTRING("numIndices"));
	outFields->push(HX_CSTRING("numVerts"));
	outFields->push(HX_CSTRING("capacity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("render"),
	HX_CSTRING("addVertex"),
	HX_CSTRING("addTile"),
	HX_CSTRING("add"),
	HX_CSTRING("addImage"),
	HX_CSTRING("dispose"),
	HX_CSTRING("build"),
	HX_CSTRING("rebuid"),
	HX_CSTRING("index"),
	HX_CSTRING("shader"),
	HX_CSTRING("vertexStrideSize"),
	HX_CSTRING("vertexDeclaration"),
	HX_CSTRING("invTexHeight"),
	HX_CSTRING("invTexWidth"),
	HX_CSTRING("indexBuffer"),
	HX_CSTRING("vertexBuffer"),
	HX_CSTRING("currentBaseTexture"),
	HX_CSTRING("currentBlendMode"),
	HX_CSTRING("currentBatchSize"),
	HX_CSTRING("drawing"),
	HX_CSTRING("lastIndexCount"),
	HX_CSTRING("indices"),
	HX_CSTRING("vertices"),
	HX_CSTRING("tmpVertices"),
	HX_CSTRING("numIndices"),
	HX_CSTRING("numVerts"),
	HX_CSTRING("capacity"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpriteCloud_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SpriteCloud_obj::__mClass,"__mClass");
};

Class SpriteCloud_obj::__mClass;

void SpriteCloud_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.SpriteCloud"), hx::TCanCast< SpriteCloud_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SpriteCloud_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
