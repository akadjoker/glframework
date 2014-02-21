#include <hxcpp.h>

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
#ifndef INCLUDED_com_engine_render_SpriteBatch
#include <com/engine/render/SpriteBatch.h>
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

Void SpriteBatch_obj::__construct(int capacity)
{
HX_STACK_PUSH("SpriteBatch::new","com/engine/render/SpriteBatch.hx",21);
{
	HX_STACK_LINE(42)
	this->invTexHeight = (int)0;
	HX_STACK_LINE(41)
	this->invTexWidth = (int)0;
	HX_STACK_LINE(36)
	this->numBlend = (int)0;
	HX_STACK_LINE(35)
	this->numTex = (int)0;
	HX_STACK_LINE(54)
	super::__construct();
	HX_STACK_LINE(55)
	this->capacity = capacity;
	HX_STACK_LINE(56)
	this->vertexStrideSize = (int)36;
	HX_STACK_LINE(57)
	this->numVerts = ((capacity * this->vertexStrideSize) * (int)4);
	HX_STACK_LINE(58)
	this->numIndices = (capacity * (int)6);
	HX_STACK_LINE(59)
	this->vertices = ::openfl::utils::Float32Array_obj::__new(this->numVerts,null(),null());
	HX_STACK_LINE(65)
	Array< int > indices = Array_obj< int >::__new();		HX_STACK_VAR(indices,"indices");
	HX_STACK_LINE(66)
	int index = (int)0;		HX_STACK_VAR(index,"index");
	HX_STACK_LINE(67)
	{
		HX_STACK_LINE(67)
		int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
		int _g = this->numIndices;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(67)
		while(((_g1 < _g))){
			HX_STACK_LINE(67)
			int count = (_g1)++;		HX_STACK_VAR(count,"count");
			HX_STACK_LINE(68)
			indices->push(index);
			HX_STACK_LINE(69)
			indices->push((index + (int)1));
			HX_STACK_LINE(70)
			indices->push((index + (int)2));
			HX_STACK_LINE(71)
			indices->push(index);
			HX_STACK_LINE(72)
			indices->push((index + (int)2));
			HX_STACK_LINE(73)
			indices->push((index + (int)3));
			HX_STACK_LINE(74)
			hx::AddEq(index,(int)4);
		}
	}
	HX_STACK_LINE(78)
	this->drawing = false;
	HX_STACK_LINE(79)
	this->currentBatchSize = (int)0;
	HX_STACK_LINE(80)
	this->currentBlendMode = ::com::engine::render::BlendMode_obj::NORMAL;
	HX_STACK_LINE(82)
	this->currentBaseTexture = null();
	HX_STACK_LINE(86)
	this->vertexBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(87)
	this->indexBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(91)
	::openfl::gl::GL_obj::bindBuffer((int)34963,this->indexBuffer);
	HX_STACK_LINE(92)
	::openfl::gl::GL_obj::bufferData((int)34963,::openfl::utils::Int16Array_obj::__new(indices,null(),null()),(int)35044);
	HX_STACK_LINE(95)
	::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
	HX_STACK_LINE(96)
	::openfl::gl::GL_obj::bufferData((int)34962,this->vertices,(int)35048);
	HX_STACK_LINE(100)
	this->shader = ::com::engine::render::SpriteShader_obj::__new();
	HX_STACK_LINE(101)
	this->start();
}
;
	return null();
}

SpriteBatch_obj::~SpriteBatch_obj() { }

Dynamic SpriteBatch_obj::__CreateEmpty() { return  new SpriteBatch_obj; }
hx::ObjectPtr< SpriteBatch_obj > SpriteBatch_obj::__new(int capacity)
{  hx::ObjectPtr< SpriteBatch_obj > result = new SpriteBatch_obj();
	result->__construct(capacity);
	return result;}

Dynamic SpriteBatch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< SpriteBatch_obj > result = new SpriteBatch_obj();
	result->__construct(inArgs[0]);
	return result;}

Void SpriteBatch_obj::dispose( ){
{
		HX_STACK_PUSH("SpriteBatch::dispose","com/engine/render/SpriteBatch.hx",682);
		HX_STACK_THIS(this);
		HX_STACK_LINE(683)
		this->vertices = null();
		HX_STACK_LINE(684)
		::openfl::gl::GL_obj::deleteBuffer(this->indexBuffer);
		HX_STACK_LINE(685)
		::openfl::gl::GL_obj::deleteBuffer(this->vertexBuffer);
		HX_STACK_LINE(686)
		this->super::dispose();
	}
return null();
}


Void SpriteBatch_obj::setBlendMode( int blendMode){
{
		HX_STACK_PUSH("SpriteBatch::setBlendMode","com/engine/render/SpriteBatch.hx",674);
		HX_STACK_THIS(this);
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_LINE(675)
		this->flush();
		HX_STACK_LINE(676)
		this->currentBlendMode = blendMode;
		HX_STACK_LINE(677)
		::com::engine::render::BlendMode_obj::setBlend(this->currentBlendMode);
		HX_STACK_LINE(678)
		(this->numBlend)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SpriteBatch_obj,setBlendMode,(void))

Void SpriteBatch_obj::switchTexture( ::com::engine::render::Texture texture){
{
		HX_STACK_PUSH("SpriteBatch::switchTexture","com/engine/render/SpriteBatch.hx",665);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texture,"texture");
		HX_STACK_LINE(666)
		this->flush();
		HX_STACK_LINE(667)
		this->currentBaseTexture = texture;
		HX_STACK_LINE(668)
		this->invTexWidth = (Float(1.0) / Float(texture->width));
		HX_STACK_LINE(669)
		this->invTexHeight = (Float(1.0) / Float(texture->height));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SpriteBatch_obj,switchTexture,(void))

Void SpriteBatch_obj::flush( ){
{
		HX_STACK_PUSH("SpriteBatch::flush","com/engine/render/SpriteBatch.hx",649);
		HX_STACK_THIS(this);
		HX_STACK_LINE(650)
		if (((this->currentBatchSize == (int)0))){
			HX_STACK_LINE(650)
			return null();
		}
		HX_STACK_LINE(651)
		this->update();
		HX_STACK_LINE(652)
		this->currentBaseTexture->Bind();
		HX_STACK_LINE(653)
		(this->numTex)++;
		HX_STACK_LINE(654)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->projectionMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(::com::engine::game::Game_obj::projMatrix->m,null(),null()));
		HX_STACK_LINE(655)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->modelViewMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(this->viewMatrix->m,null(),null()));
		HX_STACK_LINE(657)
		::openfl::gl::GL_obj::uniform1i(this->shader->imageUniform,(int)0);
		HX_STACK_LINE(658)
		::openfl::gl::GL_obj::bufferSubData((int)34962,(int)0,this->vertices);
		HX_STACK_LINE(659)
		::openfl::gl::GL_obj::bindBuffer((int)34963,this->indexBuffer);
		HX_STACK_LINE(660)
		::openfl::gl::GL_obj::drawElements((int)4,(this->currentBatchSize * (int)6),(int)5123,(int)0);
		HX_STACK_LINE(662)
		this->currentBatchSize = (int)0;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteBatch_obj,flush,(void))

Void SpriteBatch_obj::start( ){
{
		HX_STACK_PUSH("SpriteBatch::start","com/engine/render/SpriteBatch.hx",635);
		HX_STACK_THIS(this);
		HX_STACK_LINE(636)
		this->shader->Enable();
		HX_STACK_LINE(637)
		::openfl::gl::GL_obj::activeTexture((int)33984);
		HX_STACK_LINE(638)
		::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
		HX_STACK_LINE(639)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->vertexAttribute,(int)3,(int)5126,false,this->vertexStrideSize,(int)0);
		HX_STACK_LINE(640)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->texCoordAttribute,(int)2,(int)5126,false,this->vertexStrideSize,(int)12);
		HX_STACK_LINE(641)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->colorAttribute,(int)4,(int)5126,false,this->vertexStrideSize,(int)20);
		HX_STACK_LINE(642)
		if (((this->currentBlendMode != ::com::engine::render::BlendMode_obj::NORMAL))){
			HX_STACK_LINE(643)
			this->setBlendMode(this->currentBlendMode);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteBatch_obj,start,(void))

Void SpriteBatch_obj::End( ){
{
		HX_STACK_PUSH("SpriteBatch::End","com/engine/render/SpriteBatch.hx",629);
		HX_STACK_THIS(this);
		HX_STACK_LINE(630)
		this->flush();
		HX_STACK_LINE(631)
		this->shader->Disable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteBatch_obj,End,(void))

Void SpriteBatch_obj::Begin( ){
{
		HX_STACK_PUSH("SpriteBatch::Begin","com/engine/render/SpriteBatch.hx",622);
		HX_STACK_THIS(this);
		HX_STACK_LINE(623)
		this->numTex = (int)0;
		HX_STACK_LINE(624)
		this->numBlend = (int)0;
		HX_STACK_LINE(625)
		this->currentBatchSize = (int)0;
		HX_STACK_LINE(626)
		this->start();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(SpriteBatch_obj,Begin,(void))

Void SpriteBatch_obj::RenderNormal( ::com::engine::render::Texture texture,Float x,Float y,int blendMode){
{
		HX_STACK_PUSH("SpriteBatch::RenderNormal","com/engine/render/SpriteBatch.hx",566);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texture,"texture");
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_LINE(567)
		if (((bool((texture != this->currentBaseTexture)) || bool((this->currentBatchSize >= this->capacity))))){
			HX_STACK_LINE(568)
			this->switchTexture(texture);
		}
		HX_STACK_LINE(574)
		if (((blendMode != this->currentBlendMode))){
			HX_STACK_LINE(575)
			this->setBlendMode(blendMode);
		}
		HX_STACK_LINE(579)
		Float u = (int)0;		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(580)
		Float v = (int)1;		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(581)
		Float u2 = (int)1;		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(582)
		Float v2 = (int)0;		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(583)
		Float fx2 = (x + texture->width);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(584)
		Float fy2 = (y + texture->height);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(590)
		int index = (this->currentBatchSize * this->vertexStrideSize);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(592)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(593)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(594)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(595)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(595)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(596)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(596)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(596)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(596)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(598)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(599)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(600)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(601)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(601)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(602)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(602)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(602)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(602)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(604)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(605)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(606)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(607)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(607)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(608)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(608)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(608)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(608)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(610)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(611)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(612)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(613)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(613)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(614)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(614)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(614)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(614)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(617)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC4(SpriteBatch_obj,RenderNormal,(void))

Void SpriteBatch_obj::drawImage( ::com::engine::render::Image img){
{
		HX_STACK_PUSH("SpriteBatch::drawImage","com/engine/render/SpriteBatch.hx",412);
		HX_STACK_THIS(this);
		HX_STACK_ARG(img,"img");
		HX_STACK_LINE(413)
		if (((bool((img->texture != this->currentBaseTexture)) || bool((this->currentBatchSize >= this->capacity))))){
			HX_STACK_LINE(414)
			this->switchTexture(img->texture);
		}
		HX_STACK_LINE(420)
		if (((img->blendMode != this->currentBlendMode))){
			HX_STACK_LINE(421)
			this->setBlendMode(img->blendMode);
		}
		HX_STACK_LINE(428)
		Float r;		HX_STACK_VAR(r,"r");
		Float g;		HX_STACK_VAR(g,"g");
		Float b;		HX_STACK_VAR(b,"b");
		Float a;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(429)
		r = img->red;
		HX_STACK_LINE(430)
		g = img->green;
		HX_STACK_LINE(431)
		b = img->blue;
		HX_STACK_LINE(432)
		a = img->alpha;
		HX_STACK_LINE(437)
		int index = (this->currentBatchSize * this->vertexStrideSize);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(440)
		Float worldOriginX = (img->x + img->originX);		HX_STACK_VAR(worldOriginX,"worldOriginX");
		HX_STACK_LINE(441)
		Float worldOriginY = (img->y + img->originY);		HX_STACK_VAR(worldOriginY,"worldOriginY");
		HX_STACK_LINE(442)
		Float fx = -(img->originX);		HX_STACK_VAR(fx,"fx");
		HX_STACK_LINE(443)
		Float fy = -(img->originY);		HX_STACK_VAR(fy,"fy");
		HX_STACK_LINE(444)
		Float fx2 = (img->width - img->originX);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(445)
		Float fy2 = (img->height - img->originY);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(447)
		if (((bool((img->scaleX != (int)1)) || bool((img->scaleY != (int)1))))){
			HX_STACK_LINE(449)
			hx::MultEq(fx,img->scaleX);
			HX_STACK_LINE(450)
			hx::MultEq(fy,img->scaleY);
			HX_STACK_LINE(451)
			hx::MultEq(fx2,img->scaleX);
			HX_STACK_LINE(452)
			hx::MultEq(fy2,img->scaleY);
		}
		HX_STACK_LINE(455)
		Float p1x = fx;		HX_STACK_VAR(p1x,"p1x");
		HX_STACK_LINE(456)
		Float p1y = fy;		HX_STACK_VAR(p1y,"p1y");
		HX_STACK_LINE(457)
		Float p2x = fx;		HX_STACK_VAR(p2x,"p2x");
		HX_STACK_LINE(458)
		Float p2y = fy2;		HX_STACK_VAR(p2y,"p2y");
		HX_STACK_LINE(459)
		Float p3x = fx2;		HX_STACK_VAR(p3x,"p3x");
		HX_STACK_LINE(460)
		Float p3y = fy2;		HX_STACK_VAR(p3y,"p3y");
		HX_STACK_LINE(461)
		Float p4x = fx2;		HX_STACK_VAR(p4x,"p4x");
		HX_STACK_LINE(462)
		Float p4y = fy;		HX_STACK_VAR(p4y,"p4y");
		HX_STACK_LINE(464)
		Float x1;		HX_STACK_VAR(x1,"x1");
		HX_STACK_LINE(465)
		Float y1;		HX_STACK_VAR(y1,"y1");
		HX_STACK_LINE(466)
		Float x2;		HX_STACK_VAR(x2,"x2");
		HX_STACK_LINE(467)
		Float y2;		HX_STACK_VAR(y2,"y2");
		HX_STACK_LINE(468)
		Float x3;		HX_STACK_VAR(x3,"x3");
		HX_STACK_LINE(469)
		Float y3;		HX_STACK_VAR(y3,"y3");
		HX_STACK_LINE(470)
		Float x4;		HX_STACK_VAR(x4,"x4");
		HX_STACK_LINE(471)
		Float y4;		HX_STACK_VAR(y4,"y4");
		HX_STACK_LINE(475)
		if (((img->angle != (int)0))){
			HX_STACK_LINE(478)
			Float angle = (Float((img->angle * ::Math_obj::PI)) / Float((int)180));		HX_STACK_VAR(angle,"angle");
			HX_STACK_LINE(479)
			Float cos = ::Math_obj::cos(angle);		HX_STACK_VAR(cos,"cos");
			HX_STACK_LINE(480)
			Float sin = ::Math_obj::sin(angle);		HX_STACK_VAR(sin,"sin");
			HX_STACK_LINE(482)
			x1 = ((cos * p1x) - (sin * p1y));
			HX_STACK_LINE(483)
			y1 = ((sin * p1x) + (cos * p1y));
			HX_STACK_LINE(485)
			x2 = ((cos * p2x) - (sin * p2y));
			HX_STACK_LINE(486)
			y2 = ((sin * p2x) + (cos * p2y));
			HX_STACK_LINE(488)
			x3 = ((cos * p3x) - (sin * p3y));
			HX_STACK_LINE(489)
			y3 = ((sin * p3x) + (cos * p3y));
			HX_STACK_LINE(491)
			x4 = (x1 + ((x3 - x2)));
			HX_STACK_LINE(492)
			y4 = (y3 - ((y2 - y1)));
		}
		else{
			HX_STACK_LINE(494)
			x1 = p1x;
			HX_STACK_LINE(495)
			y1 = p1y;
			HX_STACK_LINE(497)
			x2 = p2x;
			HX_STACK_LINE(498)
			y2 = p2y;
			HX_STACK_LINE(500)
			x3 = p3x;
			HX_STACK_LINE(501)
			y3 = p3y;
			HX_STACK_LINE(503)
			x4 = p4x;
			HX_STACK_LINE(504)
			y4 = p4y;
		}
		HX_STACK_LINE(507)
		hx::AddEq(x1,worldOriginX);
		HX_STACK_LINE(508)
		hx::AddEq(y1,worldOriginY);
		HX_STACK_LINE(509)
		hx::AddEq(x2,worldOriginX);
		HX_STACK_LINE(510)
		hx::AddEq(y2,worldOriginY);
		HX_STACK_LINE(511)
		hx::AddEq(x3,worldOriginX);
		HX_STACK_LINE(512)
		hx::AddEq(y3,worldOriginY);
		HX_STACK_LINE(513)
		hx::AddEq(x4,worldOriginX);
		HX_STACK_LINE(514)
		hx::AddEq(y4,worldOriginY);
		HX_STACK_LINE(517)
		Float u = (img->clip->x * this->invTexWidth);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(518)
		Float u2 = (((img->clip->x + img->clip->width)) * this->invTexWidth);		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(520)
		Float v = (((img->clip->y + img->clip->height)) * this->invTexHeight);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(521)
		Float v2 = (img->clip->y * this->invTexHeight);		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(524)
		if ((img->flipX)){
			HX_STACK_LINE(525)
			Float tmp = u;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(526)
			u = u2;
			HX_STACK_LINE(527)
			u2 = tmp;
		}
		HX_STACK_LINE(530)
		if ((img->flipY)){
			HX_STACK_LINE(531)
			Float tmp = v;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(532)
			v = v2;
			HX_STACK_LINE(533)
			v2 = tmp;
		}
		HX_STACK_LINE(536)
		hx::__ArrayImplRef(this->vertices,(index)++) = x1;
		HX_STACK_LINE(537)
		hx::__ArrayImplRef(this->vertices,(index)++) = y1;
		HX_STACK_LINE(538)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(539)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(539)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(540)
		hx::__ArrayImplRef(this->vertices,(index)++) = r;
		HX_STACK_LINE(540)
		hx::__ArrayImplRef(this->vertices,(index)++) = g;
		HX_STACK_LINE(540)
		hx::__ArrayImplRef(this->vertices,(index)++) = b;
		HX_STACK_LINE(540)
		hx::__ArrayImplRef(this->vertices,(index)++) = a;
		HX_STACK_LINE(542)
		hx::__ArrayImplRef(this->vertices,(index)++) = x2;
		HX_STACK_LINE(543)
		hx::__ArrayImplRef(this->vertices,(index)++) = y2;
		HX_STACK_LINE(544)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(545)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(545)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(546)
		hx::__ArrayImplRef(this->vertices,(index)++) = r;
		HX_STACK_LINE(546)
		hx::__ArrayImplRef(this->vertices,(index)++) = g;
		HX_STACK_LINE(546)
		hx::__ArrayImplRef(this->vertices,(index)++) = b;
		HX_STACK_LINE(546)
		hx::__ArrayImplRef(this->vertices,(index)++) = a;
		HX_STACK_LINE(548)
		hx::__ArrayImplRef(this->vertices,(index)++) = x3;
		HX_STACK_LINE(549)
		hx::__ArrayImplRef(this->vertices,(index)++) = y3;
		HX_STACK_LINE(550)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(551)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(551)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(552)
		hx::__ArrayImplRef(this->vertices,(index)++) = r;
		HX_STACK_LINE(552)
		hx::__ArrayImplRef(this->vertices,(index)++) = g;
		HX_STACK_LINE(552)
		hx::__ArrayImplRef(this->vertices,(index)++) = b;
		HX_STACK_LINE(552)
		hx::__ArrayImplRef(this->vertices,(index)++) = a;
		HX_STACK_LINE(554)
		hx::__ArrayImplRef(this->vertices,(index)++) = x4;
		HX_STACK_LINE(555)
		hx::__ArrayImplRef(this->vertices,(index)++) = y4;
		HX_STACK_LINE(556)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(557)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(557)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(558)
		hx::__ArrayImplRef(this->vertices,(index)++) = r;
		HX_STACK_LINE(558)
		hx::__ArrayImplRef(this->vertices,(index)++) = g;
		HX_STACK_LINE(558)
		hx::__ArrayImplRef(this->vertices,(index)++) = b;
		HX_STACK_LINE(558)
		hx::__ArrayImplRef(this->vertices,(index)++) = a;
		HX_STACK_LINE(561)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(SpriteBatch_obj,drawImage,(void))

Void SpriteBatch_obj::RenderClip( ::com::engine::render::Texture texture,Float x,Float y,::com::engine::render::Clip c,bool flipX,bool flipY,int blendMode){
{
		HX_STACK_PUSH("SpriteBatch::RenderClip","com/engine/render/SpriteBatch.hx",335);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texture,"texture");
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(c,"c");
		HX_STACK_ARG(flipX,"flipX");
		HX_STACK_ARG(flipY,"flipY");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_LINE(336)
		if (((bool((texture != this->currentBaseTexture)) || bool((this->currentBatchSize >= this->capacity))))){
			HX_STACK_LINE(337)
			this->switchTexture(texture);
		}
		HX_STACK_LINE(343)
		if (((blendMode != this->currentBlendMode))){
			HX_STACK_LINE(344)
			this->setBlendMode(blendMode);
		}
		HX_STACK_LINE(348)
		Float u = (c->x * this->invTexWidth);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(349)
		Float u2 = (((c->x + c->width)) * this->invTexWidth);		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(351)
		Float v = (((c->y + c->height)) * this->invTexHeight);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(352)
		Float v2 = (c->y * this->invTexHeight);		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(357)
		Float fx2 = (x + c->width);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(358)
		Float fy2 = (y + c->height);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(361)
		if ((flipX)){
			HX_STACK_LINE(362)
			Float tmp = u;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(363)
			u = u2;
			HX_STACK_LINE(364)
			u2 = tmp;
		}
		HX_STACK_LINE(367)
		if ((flipY)){
			HX_STACK_LINE(368)
			Float tmp = v;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(369)
			v = v2;
			HX_STACK_LINE(370)
			v2 = tmp;
		}
		HX_STACK_LINE(376)
		int index = (this->currentBatchSize * this->vertexStrideSize);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(379)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(380)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(381)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(382)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(382)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(383)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(383)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(383)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(383)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(385)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(386)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(387)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(388)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(388)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(389)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(389)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(389)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(389)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(391)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(392)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(393)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(394)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(394)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(395)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(395)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(395)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(395)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(397)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(398)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(399)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(400)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(400)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(401)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(401)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(401)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(401)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(405)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC7(SpriteBatch_obj,RenderClip,(void))

Void SpriteBatch_obj::Blt( ::com::engine::render::Texture texture,::com::engine::render::Clip src,::com::engine::render::Clip dst,bool flipX,bool flipY,int blendMode){
{
		HX_STACK_PUSH("SpriteBatch::Blt","com/engine/render/SpriteBatch.hx",253);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texture,"texture");
		HX_STACK_ARG(src,"src");
		HX_STACK_ARG(dst,"dst");
		HX_STACK_ARG(flipX,"flipX");
		HX_STACK_ARG(flipY,"flipY");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_LINE(254)
		if (((bool((texture != this->currentBaseTexture)) || bool((this->currentBatchSize >= this->capacity))))){
			HX_STACK_LINE(255)
			this->switchTexture(texture);
		}
		HX_STACK_LINE(260)
		if (((blendMode != this->currentBlendMode))){
			HX_STACK_LINE(261)
			this->setBlendMode(blendMode);
		}
		HX_STACK_LINE(268)
		Float fx2 = (src->x + src->width);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(269)
		Float fy2 = (src->y + src->height);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(276)
		Float u = (dst->x * this->invTexWidth);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(277)
		Float u2 = (((dst->x + dst->width)) * this->invTexWidth);		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(279)
		Float v = (((dst->y + dst->height)) * this->invTexHeight);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(280)
		Float v2 = (dst->y * this->invTexHeight);		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(282)
		if ((flipX)){
			HX_STACK_LINE(284)
			Float tmp = u;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(285)
			u = u2;
			HX_STACK_LINE(286)
			u2 = tmp;
		}
		HX_STACK_LINE(289)
		if ((flipY)){
			HX_STACK_LINE(291)
			Float tmp = v;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(292)
			v = v2;
			HX_STACK_LINE(293)
			v2 = tmp;
		}
		HX_STACK_LINE(298)
		int index = (this->currentBatchSize * this->vertexStrideSize);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(300)
		hx::__ArrayImplRef(this->vertices,(index)++) = src->x;
		HX_STACK_LINE(301)
		hx::__ArrayImplRef(this->vertices,(index)++) = src->y;
		HX_STACK_LINE(302)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(303)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(303)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(304)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(304)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(304)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(304)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(306)
		hx::__ArrayImplRef(this->vertices,(index)++) = src->x;
		HX_STACK_LINE(307)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(308)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(309)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(309)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(310)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(310)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(310)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(310)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(312)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(313)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(314)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(315)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(315)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(316)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(316)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(316)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(316)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(318)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(319)
		hx::__ArrayImplRef(this->vertices,(index)++) = src->y;
		HX_STACK_LINE(320)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(321)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(321)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(322)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(322)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(322)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(322)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(328)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC6(SpriteBatch_obj,Blt,(void))

Void SpriteBatch_obj::RenderTile( ::com::engine::render::Texture texture,Float x,Float y,Float width,Float height,::com::engine::render::Clip clip,bool flipx,bool flipy,int blendMode){
{
		HX_STACK_PUSH("SpriteBatch::RenderTile","com/engine/render/SpriteBatch.hx",171);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texture,"texture");
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_ARG(clip,"clip");
		HX_STACK_ARG(flipx,"flipx");
		HX_STACK_ARG(flipy,"flipy");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_LINE(172)
		if (((bool((texture != this->currentBaseTexture)) || bool((this->currentBatchSize >= this->capacity))))){
			HX_STACK_LINE(173)
			this->switchTexture(texture);
		}
		HX_STACK_LINE(179)
		if (((blendMode != this->currentBlendMode))){
			HX_STACK_LINE(180)
			this->setBlendMode(blendMode);
		}
		HX_STACK_LINE(189)
		Float fx2 = (x + width);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(190)
		Float fy2 = (y + height);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(197)
		Float u = (clip->x * this->invTexWidth);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(198)
		Float u2 = (((clip->x + clip->width)) * this->invTexWidth);		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(200)
		Float v = (((clip->y + clip->height)) * this->invTexHeight);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(201)
		Float v2 = (clip->y * this->invTexHeight);		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(203)
		if ((flipx)){
			HX_STACK_LINE(205)
			Float tmp = u;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(206)
			u = u2;
			HX_STACK_LINE(207)
			u2 = tmp;
		}
		HX_STACK_LINE(210)
		if ((flipy)){
			HX_STACK_LINE(212)
			Float tmp = v;		HX_STACK_VAR(tmp,"tmp");
			HX_STACK_LINE(213)
			v = v2;
			HX_STACK_LINE(214)
			v2 = tmp;
		}
		HX_STACK_LINE(218)
		int index = (this->currentBatchSize * this->vertexStrideSize);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(220)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(221)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(222)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(223)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(223)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(224)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(224)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(224)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(224)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(226)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(227)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(228)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(229)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(229)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(230)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(230)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(230)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(230)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(232)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(233)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(234)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(235)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(235)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(236)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(236)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(236)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(236)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(238)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(239)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(240)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(241)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(241)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(242)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(242)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(242)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(242)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(247)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC9(SpriteBatch_obj,RenderTile,(void))

Void SpriteBatch_obj::Render( ::com::engine::render::Texture texture,Float x,Float y,int srcX,int srcY,int srcWidth,int srcHeight,int blendMode){
{
		HX_STACK_PUSH("SpriteBatch::Render","com/engine/render/SpriteBatch.hx",106);
		HX_STACK_THIS(this);
		HX_STACK_ARG(texture,"texture");
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_ARG(srcX,"srcX");
		HX_STACK_ARG(srcY,"srcY");
		HX_STACK_ARG(srcWidth,"srcWidth");
		HX_STACK_ARG(srcHeight,"srcHeight");
		HX_STACK_ARG(blendMode,"blendMode");
		HX_STACK_LINE(107)
		if (((bool((texture != this->currentBaseTexture)) || bool((this->currentBatchSize >= this->capacity))))){
			HX_STACK_LINE(108)
			this->switchTexture(texture);
		}
		HX_STACK_LINE(114)
		if (((blendMode != this->currentBlendMode))){
			HX_STACK_LINE(115)
			this->setBlendMode(blendMode);
		}
		HX_STACK_LINE(119)
		Float u = (srcX * this->invTexWidth);		HX_STACK_VAR(u,"u");
		HX_STACK_LINE(120)
		Float v = (((srcY + srcHeight)) * this->invTexHeight);		HX_STACK_VAR(v,"v");
		HX_STACK_LINE(121)
		Float u2 = (((srcX + srcWidth)) * this->invTexWidth);		HX_STACK_VAR(u2,"u2");
		HX_STACK_LINE(122)
		Float v2 = (srcY * this->invTexHeight);		HX_STACK_VAR(v2,"v2");
		HX_STACK_LINE(123)
		Float fx2 = (x + srcWidth);		HX_STACK_VAR(fx2,"fx2");
		HX_STACK_LINE(124)
		Float fy2 = (y + srcHeight);		HX_STACK_VAR(fy2,"fy2");
		HX_STACK_LINE(127)
		int r;		HX_STACK_VAR(r,"r");
		int g;		HX_STACK_VAR(g,"g");
		int b;		HX_STACK_VAR(b,"b");
		Float a;		HX_STACK_VAR(a,"a");
		HX_STACK_LINE(128)
		r = (int)1;
		HX_STACK_LINE(129)
		g = (int)1;
		HX_STACK_LINE(130)
		b = (int)1;
		HX_STACK_LINE(131)
		a = (int)1;
		HX_STACK_LINE(136)
		int index = (this->currentBatchSize * this->vertexStrideSize);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(138)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(139)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(140)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(141)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(141)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(142)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(142)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(142)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(142)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(144)
		hx::__ArrayImplRef(this->vertices,(index)++) = x;
		HX_STACK_LINE(145)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(146)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(147)
		hx::__ArrayImplRef(this->vertices,(index)++) = u;
		HX_STACK_LINE(147)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(148)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(148)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(148)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(148)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(150)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(151)
		hx::__ArrayImplRef(this->vertices,(index)++) = fy2;
		HX_STACK_LINE(152)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(153)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(153)
		hx::__ArrayImplRef(this->vertices,(index)++) = v2;
		HX_STACK_LINE(154)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(154)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(154)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(154)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(156)
		hx::__ArrayImplRef(this->vertices,(index)++) = fx2;
		HX_STACK_LINE(157)
		hx::__ArrayImplRef(this->vertices,(index)++) = y;
		HX_STACK_LINE(158)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(159)
		hx::__ArrayImplRef(this->vertices,(index)++) = u2;
		HX_STACK_LINE(159)
		hx::__ArrayImplRef(this->vertices,(index)++) = v;
		HX_STACK_LINE(160)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(160)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(160)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(160)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(165)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC8(SpriteBatch_obj,Render,(void))


SpriteBatch_obj::SpriteBatch_obj()
{
}

void SpriteBatch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(SpriteBatch);
	HX_MARK_MEMBER_NAME(shader,"shader");
	HX_MARK_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_MARK_MEMBER_NAME(vertexDeclaration,"vertexDeclaration");
	HX_MARK_MEMBER_NAME(invTexHeight,"invTexHeight");
	HX_MARK_MEMBER_NAME(invTexWidth,"invTexWidth");
	HX_MARK_MEMBER_NAME(indexBuffer,"indexBuffer");
	HX_MARK_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_MARK_MEMBER_NAME(numBlend,"numBlend");
	HX_MARK_MEMBER_NAME(numTex,"numTex");
	HX_MARK_MEMBER_NAME(currentBaseTexture,"currentBaseTexture");
	HX_MARK_MEMBER_NAME(currentBlendMode,"currentBlendMode");
	HX_MARK_MEMBER_NAME(currentBatchSize,"currentBatchSize");
	HX_MARK_MEMBER_NAME(drawing,"drawing");
	HX_MARK_MEMBER_NAME(lastIndexCount,"lastIndexCount");
	HX_MARK_MEMBER_NAME(vertices,"vertices");
	HX_MARK_MEMBER_NAME(numIndices,"numIndices");
	HX_MARK_MEMBER_NAME(numVerts,"numVerts");
	HX_MARK_MEMBER_NAME(capacity,"capacity");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void SpriteBatch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(shader,"shader");
	HX_VISIT_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_VISIT_MEMBER_NAME(vertexDeclaration,"vertexDeclaration");
	HX_VISIT_MEMBER_NAME(invTexHeight,"invTexHeight");
	HX_VISIT_MEMBER_NAME(invTexWidth,"invTexWidth");
	HX_VISIT_MEMBER_NAME(indexBuffer,"indexBuffer");
	HX_VISIT_MEMBER_NAME(vertexBuffer,"vertexBuffer");
	HX_VISIT_MEMBER_NAME(numBlend,"numBlend");
	HX_VISIT_MEMBER_NAME(numTex,"numTex");
	HX_VISIT_MEMBER_NAME(currentBaseTexture,"currentBaseTexture");
	HX_VISIT_MEMBER_NAME(currentBlendMode,"currentBlendMode");
	HX_VISIT_MEMBER_NAME(currentBatchSize,"currentBatchSize");
	HX_VISIT_MEMBER_NAME(drawing,"drawing");
	HX_VISIT_MEMBER_NAME(lastIndexCount,"lastIndexCount");
	HX_VISIT_MEMBER_NAME(vertices,"vertices");
	HX_VISIT_MEMBER_NAME(numIndices,"numIndices");
	HX_VISIT_MEMBER_NAME(numVerts,"numVerts");
	HX_VISIT_MEMBER_NAME(capacity,"capacity");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic SpriteBatch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"End") ) { return End_dyn(); }
		if (HX_FIELD_EQ(inName,"Blt") ) { return Blt_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"flush") ) { return flush_dyn(); }
		if (HX_FIELD_EQ(inName,"start") ) { return start_dyn(); }
		if (HX_FIELD_EQ(inName,"Begin") ) { return Begin_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Render") ) { return Render_dyn(); }
		if (HX_FIELD_EQ(inName,"shader") ) { return shader; }
		if (HX_FIELD_EQ(inName,"numTex") ) { return numTex; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"drawing") ) { return drawing; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"numBlend") ) { return numBlend; }
		if (HX_FIELD_EQ(inName,"vertices") ) { return vertices; }
		if (HX_FIELD_EQ(inName,"numVerts") ) { return numVerts; }
		if (HX_FIELD_EQ(inName,"capacity") ) { return capacity; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"drawImage") ) { return drawImage_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"RenderClip") ) { return RenderClip_dyn(); }
		if (HX_FIELD_EQ(inName,"RenderTile") ) { return RenderTile_dyn(); }
		if (HX_FIELD_EQ(inName,"numIndices") ) { return numIndices; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"invTexWidth") ) { return invTexWidth; }
		if (HX_FIELD_EQ(inName,"indexBuffer") ) { return indexBuffer; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"setBlendMode") ) { return setBlendMode_dyn(); }
		if (HX_FIELD_EQ(inName,"RenderNormal") ) { return RenderNormal_dyn(); }
		if (HX_FIELD_EQ(inName,"invTexHeight") ) { return invTexHeight; }
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { return vertexBuffer; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"switchTexture") ) { return switchTexture_dyn(); }
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

Dynamic SpriteBatch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { shader=inValue.Cast< ::com::engine::render::SpriteShader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"numTex") ) { numTex=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"drawing") ) { drawing=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"numBlend") ) { numBlend=inValue.Cast< int >(); return inValue; }
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

void SpriteBatch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("shader"));
	outFields->push(HX_CSTRING("vertexStrideSize"));
	outFields->push(HX_CSTRING("vertexDeclaration"));
	outFields->push(HX_CSTRING("invTexHeight"));
	outFields->push(HX_CSTRING("invTexWidth"));
	outFields->push(HX_CSTRING("indexBuffer"));
	outFields->push(HX_CSTRING("vertexBuffer"));
	outFields->push(HX_CSTRING("numBlend"));
	outFields->push(HX_CSTRING("numTex"));
	outFields->push(HX_CSTRING("currentBaseTexture"));
	outFields->push(HX_CSTRING("currentBlendMode"));
	outFields->push(HX_CSTRING("currentBatchSize"));
	outFields->push(HX_CSTRING("drawing"));
	outFields->push(HX_CSTRING("lastIndexCount"));
	outFields->push(HX_CSTRING("vertices"));
	outFields->push(HX_CSTRING("numIndices"));
	outFields->push(HX_CSTRING("numVerts"));
	outFields->push(HX_CSTRING("capacity"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("setBlendMode"),
	HX_CSTRING("switchTexture"),
	HX_CSTRING("flush"),
	HX_CSTRING("start"),
	HX_CSTRING("End"),
	HX_CSTRING("Begin"),
	HX_CSTRING("RenderNormal"),
	HX_CSTRING("drawImage"),
	HX_CSTRING("RenderClip"),
	HX_CSTRING("Blt"),
	HX_CSTRING("RenderTile"),
	HX_CSTRING("Render"),
	HX_CSTRING("shader"),
	HX_CSTRING("vertexStrideSize"),
	HX_CSTRING("vertexDeclaration"),
	HX_CSTRING("invTexHeight"),
	HX_CSTRING("invTexWidth"),
	HX_CSTRING("indexBuffer"),
	HX_CSTRING("vertexBuffer"),
	HX_CSTRING("numBlend"),
	HX_CSTRING("numTex"),
	HX_CSTRING("currentBaseTexture"),
	HX_CSTRING("currentBlendMode"),
	HX_CSTRING("currentBatchSize"),
	HX_CSTRING("drawing"),
	HX_CSTRING("lastIndexCount"),
	HX_CSTRING("vertices"),
	HX_CSTRING("numIndices"),
	HX_CSTRING("numVerts"),
	HX_CSTRING("capacity"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(SpriteBatch_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(SpriteBatch_obj::__mClass,"__mClass");
};

Class SpriteBatch_obj::__mClass;

void SpriteBatch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.SpriteBatch"), hx::TCanCast< SpriteBatch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void SpriteBatch_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
