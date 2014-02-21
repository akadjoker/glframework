#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_com_engine_direct_SpriteClip
#include <com/engine/direct/SpriteClip.h>
#endif
#ifndef INCLUDED_com_engine_direct_TileBatch
#include <com/engine/direct/TileBatch.h>
#endif
#ifndef INCLUDED_com_engine_direct_TileImage
#include <com/engine/direct/TileImage.h>
#endif
#ifndef INCLUDED_com_engine_direct_Util
#include <com/engine/direct/Util.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash__Vector_Vector_Impl_
#include <flash/_Vector/Vector_Impl_.h>
#endif
#ifndef INCLUDED_flash_display_BitmapData
#include <flash/display/BitmapData.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_Graphics
#include <flash/display/Graphics.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_events_Event
#include <flash/events/Event.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
#ifndef INCLUDED_haxe_xml_Fast
#include <haxe/xml/Fast.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_display_Tilesheet
#include <openfl/display/Tilesheet.h>
#endif
namespace com{
namespace engine{
namespace direct{

Void TileBatch_obj::__construct(::flash::display::BitmapData image)
{
HX_STACK_PUSH("TileBatch::new","com/engine/direct/TileBatch.hx",33);
{
	HX_STACK_LINE(34)
	super::__construct();
	HX_STACK_LINE(35)
	this->tilesheet = ::openfl::display::Tilesheet_obj::__new(image);
	HX_STACK_LINE(36)
	this->tileData = Array_obj< Float >::__new();
	HX_STACK_LINE(37)
	this->sprites = Array_obj< ::Dynamic >::__new();
	HX_STACK_LINE(38)
	this->clips = ::flash::_Vector::Vector_Impl__obj::_new(null(),null());
	HX_STACK_LINE(39)
	this->length = (int)0;
	HX_STACK_LINE(40)
	this->addEventListener(::flash::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null(),null(),null());
	HX_STACK_LINE(41)
	this->sort = false;
	HX_STACK_LINE(42)
	this->maxSize = (int)1000;
	HX_STACK_LINE(43)
	this->numTile = (int)0;
	HX_STACK_LINE(44)
	this->previousTime = ::flash::Lib_obj::getTimer();
}
;
	return null();
}

TileBatch_obj::~TileBatch_obj() { }

Dynamic TileBatch_obj::__CreateEmpty() { return  new TileBatch_obj; }
hx::ObjectPtr< TileBatch_obj > TileBatch_obj::__new(::flash::display::BitmapData image)
{  hx::ObjectPtr< TileBatch_obj > result = new TileBatch_obj();
	result->__construct(image);
	return result;}

Dynamic TileBatch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TileBatch_obj > result = new TileBatch_obj();
	result->__construct(inArgs[0]);
	return result;}

int TileBatch_obj::set_numTiles( int v){
	HX_STACK_PUSH("TileBatch::set_numTiles","com/engine/direct/TileBatch.hx",406);
	HX_STACK_THIS(this);
	HX_STACK_ARG(v,"v");
	HX_STACK_LINE(406)
	this->numTile = v;
	HX_STACK_LINE(406)
	return this->numTile;
}


HX_DEFINE_DYNAMIC_FUNC1(TileBatch_obj,set_numTiles,return )

int TileBatch_obj::get_numTiles( ){
	HX_STACK_PUSH("TileBatch::get_numTiles","com/engine/direct/TileBatch.hx",405);
	HX_STACK_THIS(this);
	HX_STACK_LINE(405)
	return this->numTile;
}


HX_DEFINE_DYNAMIC_FUNC0(TileBatch_obj,get_numTiles,return )

Void TileBatch_obj::renderTile( Array< Float > data,int tile,Float mX,Float mY,Float mPivotX,Float mPivotY,Float mScaleX,Float mScaleY,Float mSkewX,Float mSkewY,Float mRotation,Float red,Float green,Float blue,Float alpha){
{
		HX_STACK_PUSH("TileBatch::renderTile","com/engine/direct/TileBatch.hx",341);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(tile,"tile");
		HX_STACK_ARG(mX,"mX");
		HX_STACK_ARG(mY,"mY");
		HX_STACK_ARG(mPivotX,"mPivotX");
		HX_STACK_ARG(mPivotY,"mPivotY");
		HX_STACK_ARG(mScaleX,"mScaleX");
		HX_STACK_ARG(mScaleY,"mScaleY");
		HX_STACK_ARG(mSkewX,"mSkewX");
		HX_STACK_ARG(mSkewY,"mSkewY");
		HX_STACK_ARG(mRotation,"mRotation");
		HX_STACK_ARG(red,"red");
		HX_STACK_ARG(green,"green");
		HX_STACK_ARG(blue,"blue");
		HX_STACK_ARG(alpha,"alpha");
		HX_STACK_LINE(343)
		::flash::geom::Matrix mTransformationMatrix = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());		HX_STACK_VAR(mTransformationMatrix,"mTransformationMatrix");
		HX_STACK_LINE(344)
		mTransformationMatrix->identity();
		HX_STACK_LINE(346)
		if (((bool((mSkewX == 0.0)) && bool((mSkewY == 0.0))))){
			HX_STACK_LINE(347)
			if (((mRotation == 0.0))){
				HX_STACK_LINE(350)
				::com::engine::direct::Util_obj::matrixsetTo(mTransformationMatrix,mScaleX,0.0,0.0,mScaleY,(mX - (mPivotX * mScaleX)),(mY - (mPivotY * mScaleY)));
			}
			else{
				HX_STACK_LINE(356)
				Float cos = ::Math_obj::cos((Float((mRotation * ::Math_obj::PI)) / Float((int)-180)));		HX_STACK_VAR(cos,"cos");
				HX_STACK_LINE(357)
				Float sin = ::Math_obj::sin((Float((mRotation * ::Math_obj::PI)) / Float((int)-180)));		HX_STACK_VAR(sin,"sin");
				HX_STACK_LINE(359)
				Float a = (mScaleX * cos);		HX_STACK_VAR(a,"a");
				HX_STACK_LINE(360)
				Float b = (mScaleX * sin);		HX_STACK_VAR(b,"b");
				HX_STACK_LINE(361)
				Float c = (mScaleY * -(sin));		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(362)
				Float d = (mScaleY * cos);		HX_STACK_VAR(d,"d");
				HX_STACK_LINE(363)
				Float tx = ((mX - (mPivotX * a)) - (mPivotY * c));		HX_STACK_VAR(tx,"tx");
				HX_STACK_LINE(364)
				Float ty = ((mY - (mPivotX * b)) - (mPivotY * d));		HX_STACK_VAR(ty,"ty");
				HX_STACK_LINE(366)
				::com::engine::direct::Util_obj::matrixsetTo(mTransformationMatrix,a,b,c,d,tx,ty);
			}
		}
		else{
			HX_STACK_LINE(371)
			mTransformationMatrix->identity();
			HX_STACK_LINE(372)
			mTransformationMatrix->scale(mScaleX,mScaleY);
			HX_STACK_LINE(373)
			::com::engine::direct::Util_obj::skew(mTransformationMatrix,mSkewX,mSkewY);
			HX_STACK_LINE(374)
			mTransformationMatrix->rotate(mRotation);
			HX_STACK_LINE(375)
			mTransformationMatrix->translate(mX,mY);
			HX_STACK_LINE(377)
			if (((bool((mPivotX != 0.0)) || bool((mPivotY != 0.0))))){
				HX_STACK_LINE(380)
				mTransformationMatrix->tx = ((mX - (mTransformationMatrix->a * mPivotX)) - (mTransformationMatrix->c * mPivotY));
				HX_STACK_LINE(382)
				mTransformationMatrix->ty = ((mY - (mTransformationMatrix->b * mPivotX)) - (mTransformationMatrix->d * mPivotY));
			}
		}
		HX_STACK_LINE(388)
		data->push(mTransformationMatrix->tx);
		HX_STACK_LINE(389)
		data->push(mTransformationMatrix->ty);
		HX_STACK_LINE(390)
		data->push(tile);
		HX_STACK_LINE(391)
		data->push(mTransformationMatrix->a);
		HX_STACK_LINE(392)
		data->push(mTransformationMatrix->b);
		HX_STACK_LINE(393)
		data->push(mTransformationMatrix->c);
		HX_STACK_LINE(394)
		data->push(mTransformationMatrix->d);
		HX_STACK_LINE(398)
		data->push(red);
		HX_STACK_LINE(399)
		data->push(green);
		HX_STACK_LINE(400)
		data->push(blue);
		HX_STACK_LINE(401)
		data->push(alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC15(TileBatch_obj,renderTile,(void))

Void TileBatch_obj::renderObject( Array< Float > data,::com::engine::direct::TileImage obj){
{
		HX_STACK_PUSH("TileBatch::renderObject","com/engine/direct/TileBatch.hx",321);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_ARG(obj,"obj");
		HX_STACK_LINE(322)
		::flash::geom::Matrix mTransformationMatrix = obj->getMatrix();		HX_STACK_VAR(mTransformationMatrix,"mTransformationMatrix");
		HX_STACK_LINE(323)
		data->push(mTransformationMatrix->tx);
		HX_STACK_LINE(324)
		data->push(mTransformationMatrix->ty);
		HX_STACK_LINE(325)
		data->push(obj->Graph);
		HX_STACK_LINE(326)
		data->push(mTransformationMatrix->a);
		HX_STACK_LINE(327)
		data->push(mTransformationMatrix->b);
		HX_STACK_LINE(328)
		data->push(mTransformationMatrix->c);
		HX_STACK_LINE(329)
		data->push(mTransformationMatrix->d);
		HX_STACK_LINE(330)
		data->push(obj->Red);
		HX_STACK_LINE(331)
		data->push(obj->Green);
		HX_STACK_LINE(332)
		data->push(obj->Blue);
		HX_STACK_LINE(333)
		data->push(obj->Alpha);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TileBatch_obj,renderObject,(void))

Void TileBatch_obj::onEnterFrame( ::flash::events::Event e){
{
		HX_STACK_PUSH("TileBatch::onEnterFrame","com/engine/direct/TileBatch.hx",290);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(291)
		int currentTime = ::flash::Lib_obj::getTimer();		HX_STACK_VAR(currentTime,"currentTime");
		HX_STACK_LINE(292)
		int deltaTime = (currentTime - this->previousTime);		HX_STACK_VAR(deltaTime,"deltaTime");
		HX_STACK_LINE(294)
		this->get_graphics()->clear();
		HX_STACK_LINE(295)
		int flags = (int)28;		HX_STACK_VAR(flags,"flags");
		HX_STACK_LINE(296)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(297)
		::com::engine::direct::TileImage basic = null();		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(298)
		while(((i < this->sprites->length))){
			HX_STACK_LINE(300)
			basic = this->sprites->__get((i)++).StaticCast< ::com::engine::direct::TileImage >();
			HX_STACK_LINE(302)
			if (((bool((basic != null())) && bool(basic->Visible)))){
				HX_STACK_LINE(304)
				basic->updateAnim((Float(deltaTime) / Float((int)100)));
				HX_STACK_LINE(305)
				basic->update();
				HX_STACK_LINE(306)
				this->renderObject(this->tileData,basic);
			}
		}
		HX_STACK_LINE(310)
		this->tilesheet->drawTiles(this->get_graphics(),this->tileData,false,flags);
		HX_STACK_LINE(311)
		this->tileData = Array_obj< Float >::__new();
		HX_STACK_LINE(312)
		if ((this->sort)){
			HX_STACK_LINE(314)
			this->sprites->sort(this->sortObjects_dyn());
			HX_STACK_LINE(315)
			this->sort = false;
		}
		HX_STACK_LINE(318)
		this->previousTime = currentTime;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TileBatch_obj,onEnterFrame,(void))

Void TileBatch_obj::render( ){
{
		HX_STACK_PUSH("TileBatch::render","com/engine/direct/TileBatch.hx",258);
		HX_STACK_THIS(this);
		HX_STACK_LINE(259)
		int currentTime = ::flash::Lib_obj::getTimer();		HX_STACK_VAR(currentTime,"currentTime");
		HX_STACK_LINE(260)
		int deltaTime = (currentTime - this->previousTime);		HX_STACK_VAR(deltaTime,"deltaTime");
		HX_STACK_LINE(262)
		this->get_graphics()->clear();
		HX_STACK_LINE(263)
		int flags = (int)28;		HX_STACK_VAR(flags,"flags");
		HX_STACK_LINE(264)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(265)
		::com::engine::direct::TileImage basic = null();		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(266)
		while(((i < this->sprites->length))){
			HX_STACK_LINE(268)
			basic = this->sprites->__get((i)++).StaticCast< ::com::engine::direct::TileImage >();
			HX_STACK_LINE(270)
			if (((bool((basic != null())) && bool(basic->Visible)))){
				HX_STACK_LINE(272)
				basic->updateAnim((Float(deltaTime) / Float((int)100)));
				HX_STACK_LINE(273)
				basic->update();
				HX_STACK_LINE(274)
				this->renderObject(this->tileData,basic);
			}
		}
		HX_STACK_LINE(278)
		this->tilesheet->drawTiles(this->get_graphics(),this->tileData,false,flags);
		HX_STACK_LINE(279)
		this->tileData = Array_obj< Float >::__new();
		HX_STACK_LINE(280)
		if ((this->sort)){
			HX_STACK_LINE(282)
			this->sprites->sort(this->sortObjects_dyn());
			HX_STACK_LINE(283)
			this->sort = false;
		}
		HX_STACK_LINE(286)
		this->previousTime = currentTime;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileBatch_obj,render,(void))

Void TileBatch_obj::dispose( ){
{
		HX_STACK_PUSH("TileBatch::dispose","com/engine/direct/TileBatch.hx",253);
		HX_STACK_THIS(this);
		HX_STACK_LINE(253)
		this->removeEventListener(::flash::events::Event_obj::ENTER_FRAME,this->onEnterFrame_dyn(),null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileBatch_obj,dispose,(void))

::com::engine::direct::TileImage TileBatch_obj::remove( ::com::engine::direct::TileImage obj,hx::Null< bool >  __o_Splice){
bool Splice = __o_Splice.Default(false);
	HX_STACK_PUSH("TileBatch::remove","com/engine/direct/TileBatch.hx",229);
	HX_STACK_THIS(this);
	HX_STACK_ARG(obj,"obj");
	HX_STACK_ARG(Splice,"Splice");
{
		HX_STACK_LINE(230)
		if (((this->sprites == null()))){
			HX_STACK_LINE(231)
			return null();
		}
		HX_STACK_LINE(235)
		int index = ::com::engine::direct::Util_obj::indexOf(this->sprites,obj,null());		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(237)
		if (((bool((index < (int)0)) || bool((index >= this->sprites->length))))){
			HX_STACK_LINE(238)
			return null();
		}
		HX_STACK_LINE(241)
		if ((Splice)){
			HX_STACK_LINE(242)
			this->sprites->splice(index,(int)1);
		}
		else{
			HX_STACK_LINE(246)
			this->sprites[index] = null();
		}
		HX_STACK_LINE(250)
		return obj;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(TileBatch_obj,remove,return )

Void TileBatch_obj::destroy( ){
{
		HX_STACK_PUSH("TileBatch::destroy","com/engine/direct/TileBatch.hx",203);
		HX_STACK_THIS(this);
		HX_STACK_LINE(203)
		if (((this->sprites != null()))){
			HX_STACK_LINE(206)
			int i = (int)0;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(207)
			::com::engine::direct::TileImage basic = null();		HX_STACK_VAR(basic,"basic");
			HX_STACK_LINE(209)
			while(((i < this->length))){
				HX_STACK_LINE(211)
				basic = this->sprites->__get((i)++).StaticCast< ::com::engine::direct::TileImage >();
				HX_STACK_LINE(213)
				if (((basic != null()))){
					HX_STACK_LINE(214)
					basic->destroy();
				}
			}
			HX_STACK_LINE(220)
			this->sprites = null();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileBatch_obj,destroy,(void))

int TileBatch_obj::numObjects( ){
	HX_STACK_PUSH("TileBatch::numObjects","com/engine/direct/TileBatch.hx",199);
	HX_STACK_THIS(this);
	HX_STACK_LINE(199)
	return this->length;
}


HX_DEFINE_DYNAMIC_FUNC0(TileBatch_obj,numObjects,return )

::com::engine::direct::TileImage TileBatch_obj::add( ::com::engine::direct::TileImage Object){
	HX_STACK_PUSH("TileBatch::add","com/engine/direct/TileBatch.hx",137);
	HX_STACK_THIS(this);
	HX_STACK_ARG(Object,"Object");
	HX_STACK_LINE(138)
	if (((Object == null()))){
		HX_STACK_LINE(139)
		return null();
	}
	HX_STACK_LINE(144)
	if (((::com::engine::direct::Util_obj::indexOf(this->sprites,Object,null()) >= (int)0))){
		HX_STACK_LINE(146)
		this->sort = true;
		HX_STACK_LINE(147)
		return Object;
	}
	HX_STACK_LINE(151)
	int i = (int)0;		HX_STACK_VAR(i,"i");
	HX_STACK_LINE(152)
	int l = this->sprites->length;		HX_STACK_VAR(l,"l");
	HX_STACK_LINE(154)
	while(((i < l))){
		HX_STACK_LINE(156)
		if (((this->sprites->__get(i).StaticCast< ::com::engine::direct::TileImage >() == null()))){
			HX_STACK_LINE(158)
			this->sprites[i] = Object;
			HX_STACK_LINE(160)
			if (((i >= this->length))){
				HX_STACK_LINE(161)
				this->length = (i + (int)1);
			}
			HX_STACK_LINE(164)
			this->sort = true;
			HX_STACK_LINE(165)
			return Object;
		}
		HX_STACK_LINE(167)
		(i)++;
	}
	HX_STACK_LINE(171)
	if (((this->maxSize > (int)0))){
		HX_STACK_LINE(172)
		if (((this->sprites->length >= this->maxSize))){
			HX_STACK_LINE(175)
			this->sort = true;
			HX_STACK_LINE(176)
			return Object;
		}
		else{
			HX_STACK_LINE(178)
			if ((((this->sprites->length * (int)2) <= this->maxSize))){
				HX_STACK_LINE(179)
				::com::engine::direct::Util_obj::setLength(this->sprites,(this->sprites->length * (int)2));
			}
			else{
				HX_STACK_LINE(183)
				::com::engine::direct::Util_obj::setLength(this->sprites,this->maxSize);
			}
		}
	}
	else{
		HX_STACK_LINE(188)
		::com::engine::direct::Util_obj::setLength(this->sprites,(this->sprites->length * (int)2));
	}
	HX_STACK_LINE(192)
	this->sprites[i] = Object;
	HX_STACK_LINE(193)
	this->sort = true;
	HX_STACK_LINE(194)
	this->length = (i + (int)1);
	HX_STACK_LINE(196)
	return Object;
}


HX_DEFINE_DYNAMIC_FUNC1(TileBatch_obj,add,return )

Void TileBatch_obj::kill( ){
{
		HX_STACK_PUSH("TileBatch::kill","com/engine/direct/TileBatch.hx",119);
		HX_STACK_THIS(this);
		HX_STACK_LINE(120)
		int i = (int)0;		HX_STACK_VAR(i,"i");
		HX_STACK_LINE(121)
		::com::engine::direct::TileImage basic = null();		HX_STACK_VAR(basic,"basic");
		HX_STACK_LINE(123)
		while(((i < this->length))){
			HX_STACK_LINE(125)
			basic = this->sprites->__get((i)++).StaticCast< ::com::engine::direct::TileImage >();
			HX_STACK_LINE(127)
			if (((basic != null()))){
				HX_STACK_LINE(128)
				basic->kill();
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileBatch_obj,kill,(void))

Void TileBatch_obj::clear( ){
{
		HX_STACK_PUSH("TileBatch::clear","com/engine/direct/TileBatch.hx",114);
		HX_STACK_THIS(this);
		HX_STACK_LINE(115)
		this->length = (int)0;
		HX_STACK_LINE(116)
		this->sprites->splice((int)0,this->sprites->length);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileBatch_obj,clear,(void))

int TileBatch_obj::sortObjects( ::com::engine::direct::TileImage a,::com::engine::direct::TileImage b){
	HX_STACK_PUSH("TileBatch::sortObjects","com/engine/direct/TileBatch.hx",105);
	HX_STACK_THIS(this);
	HX_STACK_ARG(a,"a");
	HX_STACK_ARG(b,"b");
	HX_STACK_LINE(106)
	if (((a->Layer == b->Layer))){
		HX_STACK_LINE(107)
		return (int)0;
	}
	HX_STACK_LINE(108)
	if (((a->Layer > b->Layer))){
		HX_STACK_LINE(109)
		return (int)1;
	}
	else{
		HX_STACK_LINE(111)
		return (int)-1;
	}
	HX_STACK_LINE(108)
	return (int)0;
}


HX_DEFINE_DYNAMIC_FUNC2(TileBatch_obj,sortObjects,return )

int TileBatch_obj::addTileRect( ::flash::geom::Rectangle rectangle,::flash::geom::Point centerPoint){
	HX_STACK_PUSH("TileBatch::addTileRect","com/engine/direct/TileBatch.hx",97);
	HX_STACK_THIS(this);
	HX_STACK_ARG(rectangle,"rectangle");
	HX_STACK_ARG(centerPoint,"centerPoint");
	HX_STACK_LINE(98)
	(this->numTile)++;
	HX_STACK_LINE(99)
	return this->tilesheet->addTileRect(rectangle,centerPoint);
}


HX_DEFINE_DYNAMIC_FUNC2(TileBatch_obj,addTileRect,return )

::com::engine::direct::SpriteClip TileBatch_obj::getClip( int index){
	HX_STACK_PUSH("TileBatch::getClip","com/engine/direct/TileBatch.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_ARG(index,"index");
	HX_STACK_LINE(93)
	return this->clips->__get(index).StaticCast< ::com::engine::direct::SpriteClip >();
}


HX_DEFINE_DYNAMIC_FUNC1(TileBatch_obj,getClip,return )

Void TileBatch_obj::parseXML( ::String data){
{
		HX_STACK_PUSH("TileBatch::parseXML","com/engine/direct/TileBatch.hx",48);
		HX_STACK_THIS(this);
		HX_STACK_ARG(data,"data");
		HX_STACK_LINE(49)
		::haxe::ds::StringMap frameIndex = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(frameIndex,"frameIndex");
		HX_STACK_LINE(51)
		::Xml xml = ::Xml_obj::parse(data);		HX_STACK_VAR(xml,"xml");
		HX_STACK_LINE(52)
		::Xml spriteSheetNode = xml->firstElement();		HX_STACK_VAR(spriteSheetNode,"spriteSheetNode");
		HX_STACK_LINE(54)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(spriteSheetNode->elements());  __it->hasNext(); ){
			::Xml behaviorNode = __it->next();
			{
				HX_STACK_LINE(56)
				::haxe::xml::Fast behaviorNodeFast = ::haxe::xml::Fast_obj::__new(behaviorNode);		HX_STACK_VAR(behaviorNodeFast,"behaviorNodeFast");
				HX_STACK_LINE(57)
				Array< int > behaviorFrames = Array_obj< int >::__new();		HX_STACK_VAR(behaviorFrames,"behaviorFrames");
				HX_STACK_LINE(59)
				::String allFramesText = behaviorNodeFast->get_innerData();		HX_STACK_VAR(allFramesText,"allFramesText");
				HX_STACK_LINE(60)
				Array< ::String > framesText = allFramesText.split(HX_CSTRING(";"));		HX_STACK_VAR(framesText,"framesText");
				HX_STACK_LINE(62)
				{
					HX_STACK_LINE(62)
					int _g = (int)0;		HX_STACK_VAR(_g,"_g");
					HX_STACK_LINE(62)
					while(((_g < framesText->length))){
						HX_STACK_LINE(62)
						::String frameText = framesText->__get(_g);		HX_STACK_VAR(frameText,"frameText");
						HX_STACK_LINE(62)
						++(_g);
						HX_STACK_LINE(64)
						if ((!(frameIndex->exists(frameText)))){
							HX_STACK_LINE(67)
							Array< ::String > components = frameText.split(HX_CSTRING(","));		HX_STACK_VAR(components,"components");
							HX_STACK_LINE(69)
							this->addTileRect(::flash::geom::Rectangle_obj::__new(::Std_obj::parseInt(components->__get((int)0)),::Std_obj::parseInt(components->__get((int)1)),::Std_obj::parseInt(components->__get((int)2)),::Std_obj::parseInt(components->__get((int)3))),::flash::geom::Point_obj::__new(-(::Std_obj::parseInt(components->__get((int)4))),-(::Std_obj::parseInt(components->__get((int)5)))));
							HX_STACK_LINE(79)
							::com::engine::direct::SpriteClip frame = ::com::engine::direct::SpriteClip_obj::__new(::Std_obj::parseInt(components->__get((int)0)),::Std_obj::parseInt(components->__get((int)1)),::Std_obj::parseInt(components->__get((int)2)),::Std_obj::parseInt(components->__get((int)3)),-(::Std_obj::parseInt(components->__get((int)4))),-(::Std_obj::parseInt(components->__get((int)5))));		HX_STACK_VAR(frame,"frame");
							HX_STACK_LINE(80)
							this->clips->__Field(HX_CSTRING("push"),true)(frame);
						}
					}
				}
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TileBatch_obj,parseXML,(void))


TileBatch_obj::TileBatch_obj()
{
}

void TileBatch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TileBatch);
	HX_MARK_MEMBER_NAME(previousTime,"previousTime");
	HX_MARK_MEMBER_NAME(currentTime,"currentTime");
	HX_MARK_MEMBER_NAME(numTile,"numTile");
	HX_MARK_MEMBER_NAME(maxSize,"maxSize");
	HX_MARK_MEMBER_NAME(length,"length");
	HX_MARK_MEMBER_NAME(sort,"sort");
	HX_MARK_MEMBER_NAME(clips,"clips");
	HX_MARK_MEMBER_NAME(sprites,"sprites");
	HX_MARK_MEMBER_NAME(tileData,"tileData");
	HX_MARK_MEMBER_NAME(tilesheet,"tilesheet");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TileBatch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(previousTime,"previousTime");
	HX_VISIT_MEMBER_NAME(currentTime,"currentTime");
	HX_VISIT_MEMBER_NAME(numTile,"numTile");
	HX_VISIT_MEMBER_NAME(maxSize,"maxSize");
	HX_VISIT_MEMBER_NAME(length,"length");
	HX_VISIT_MEMBER_NAME(sort,"sort");
	HX_VISIT_MEMBER_NAME(clips,"clips");
	HX_VISIT_MEMBER_NAME(sprites,"sprites");
	HX_VISIT_MEMBER_NAME(tileData,"tileData");
	HX_VISIT_MEMBER_NAME(tilesheet,"tilesheet");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TileBatch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		if (HX_FIELD_EQ(inName,"sort") ) { return sort; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clear") ) { return clear_dyn(); }
		if (HX_FIELD_EQ(inName,"clips") ) { return clips; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"remove") ) { return remove_dyn(); }
		if (HX_FIELD_EQ(inName,"length") ) { return length; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"getClip") ) { return getClip_dyn(); }
		if (HX_FIELD_EQ(inName,"numTile") ) { return numTile; }
		if (HX_FIELD_EQ(inName,"maxSize") ) { return maxSize; }
		if (HX_FIELD_EQ(inName,"sprites") ) { return sprites; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"numTiles") ) { return get_numTiles(); }
		if (HX_FIELD_EQ(inName,"parseXML") ) { return parseXML_dyn(); }
		if (HX_FIELD_EQ(inName,"tileData") ) { return tileData; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tilesheet") ) { return tilesheet; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"renderTile") ) { return renderTile_dyn(); }
		if (HX_FIELD_EQ(inName,"numObjects") ) { return numObjects_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"sortObjects") ) { return sortObjects_dyn(); }
		if (HX_FIELD_EQ(inName,"addTileRect") ) { return addTileRect_dyn(); }
		if (HX_FIELD_EQ(inName,"currentTime") ) { return currentTime; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"set_numTiles") ) { return set_numTiles_dyn(); }
		if (HX_FIELD_EQ(inName,"get_numTiles") ) { return get_numTiles_dyn(); }
		if (HX_FIELD_EQ(inName,"renderObject") ) { return renderObject_dyn(); }
		if (HX_FIELD_EQ(inName,"onEnterFrame") ) { return onEnterFrame_dyn(); }
		if (HX_FIELD_EQ(inName,"previousTime") ) { return previousTime; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TileBatch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"sort") ) { sort=inValue.Cast< bool >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"clips") ) { clips=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"length") ) { length=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"numTile") ) { numTile=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"maxSize") ) { maxSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"sprites") ) { sprites=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"numTiles") ) { return set_numTiles(inValue); }
		if (HX_FIELD_EQ(inName,"tileData") ) { tileData=inValue.Cast< Array< Float > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tilesheet") ) { tilesheet=inValue.Cast< ::openfl::display::Tilesheet >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentTime") ) { currentTime=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"previousTime") ) { previousTime=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TileBatch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("numTiles"));
	outFields->push(HX_CSTRING("previousTime"));
	outFields->push(HX_CSTRING("currentTime"));
	outFields->push(HX_CSTRING("numTile"));
	outFields->push(HX_CSTRING("maxSize"));
	outFields->push(HX_CSTRING("length"));
	outFields->push(HX_CSTRING("sort"));
	outFields->push(HX_CSTRING("clips"));
	outFields->push(HX_CSTRING("sprites"));
	outFields->push(HX_CSTRING("tileData"));
	outFields->push(HX_CSTRING("tilesheet"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("set_numTiles"),
	HX_CSTRING("get_numTiles"),
	HX_CSTRING("renderTile"),
	HX_CSTRING("renderObject"),
	HX_CSTRING("onEnterFrame"),
	HX_CSTRING("render"),
	HX_CSTRING("dispose"),
	HX_CSTRING("remove"),
	HX_CSTRING("destroy"),
	HX_CSTRING("numObjects"),
	HX_CSTRING("add"),
	HX_CSTRING("kill"),
	HX_CSTRING("clear"),
	HX_CSTRING("sortObjects"),
	HX_CSTRING("addTileRect"),
	HX_CSTRING("getClip"),
	HX_CSTRING("parseXML"),
	HX_CSTRING("previousTime"),
	HX_CSTRING("currentTime"),
	HX_CSTRING("numTile"),
	HX_CSTRING("maxSize"),
	HX_CSTRING("length"),
	HX_CSTRING("sort"),
	HX_CSTRING("clips"),
	HX_CSTRING("sprites"),
	HX_CSTRING("tileData"),
	HX_CSTRING("tilesheet"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TileBatch_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TileBatch_obj::__mClass,"__mClass");
};

Class TileBatch_obj::__mClass;

void TileBatch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.direct.TileBatch"), hx::TCanCast< TileBatch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TileBatch_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace direct
