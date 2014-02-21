#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_com_engine_direct_Animation
#include <com/engine/direct/Animation.h>
#endif
#ifndef INCLUDED_com_engine_direct_TileImage
#include <com/engine/direct/TileImage.h>
#endif
#ifndef INCLUDED_com_engine_direct_Util
#include <com/engine/direct/Util.h>
#endif
#ifndef INCLUDED_flash_geom_Matrix
#include <flash/geom/Matrix.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
#endif
namespace com{
namespace engine{
namespace direct{

Void TileImage_obj::__construct(Float x,Float y,int graph)
{
HX_STACK_PUSH("TileImage::new","com/engine/direct/TileImage.hx",61);
{
	HX_STACK_LINE(62)
	this->x = this->y = this->PivotX = this->PivotY = this->Rotation = this->SkewX = this->SkewY = 0.0;
	HX_STACK_LINE(63)
	this->ScaleX = this->ScaleY = this->Alpha = this->Red = this->Green = this->Blue = 1.0;
	HX_STACK_LINE(64)
	this->Visible = true;
	HX_STACK_LINE(65)
	this->Layer = (int)0;
	HX_STACK_LINE(66)
	this->x = x;
	HX_STACK_LINE(67)
	this->y = y;
	HX_STACK_LINE(68)
	this->Graph = graph;
	HX_STACK_LINE(69)
	this->mTransformationMatrix = ::flash::geom::Matrix_obj::__new(null(),null(),null(),null(),null(),null());
	HX_STACK_LINE(70)
	this->complete = true;
	HX_STACK_LINE(71)
	this->rate = (int)1;
	HX_STACK_LINE(72)
	this->callbackFunc = null();
	HX_STACK_LINE(73)
	this->_anims = ::haxe::ds::StringMap_obj::__new();
	HX_STACK_LINE(74)
	this->originX = this->originY = (int)0;
	HX_STACK_LINE(75)
	this->width = this->height = (int)0;
}
;
	return null();
}

TileImage_obj::~TileImage_obj() { }

Dynamic TileImage_obj::__CreateEmpty() { return  new TileImage_obj; }
hx::ObjectPtr< TileImage_obj > TileImage_obj::__new(Float x,Float y,int graph)
{  hx::ObjectPtr< TileImage_obj > result = new TileImage_obj();
	result->__construct(x,y,graph);
	return result;}

Dynamic TileImage_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TileImage_obj > result = new TileImage_obj();
	result->__construct(inArgs[0],inArgs[1],inArgs[2]);
	return result;}

::String TileImage_obj::get_currentAnim( ){
	HX_STACK_PUSH("TileImage::get_currentAnim","com/engine/direct/TileImage.hx",212);
	HX_STACK_THIS(this);
	HX_STACK_LINE(212)
	return (  (((this->_anim != null()))) ? ::String(this->_anim->name) : ::String(HX_CSTRING("")) );
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,get_currentAnim,return )

int TileImage_obj::get_frameCount( ){
	HX_STACK_PUSH("TileImage::get_frameCount","com/engine/direct/TileImage.hx",210);
	HX_STACK_THIS(this);
	HX_STACK_LINE(210)
	return this->_frameCount;
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,get_frameCount,return )

int TileImage_obj::set_frame( int value){
	HX_STACK_PUSH("TileImage::set_frame","com/engine/direct/TileImage.hx",201);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(202)
	this->_anim = null();
	HX_STACK_LINE(203)
	hx::ModEq(value,this->_frameCount);
	HX_STACK_LINE(204)
	if (((value < (int)0))){
		HX_STACK_LINE(204)
		value = (this->_frameCount + value);
	}
	HX_STACK_LINE(205)
	if (((this->_frame == value))){
		HX_STACK_LINE(205)
		return this->_frame;
	}
	HX_STACK_LINE(206)
	this->_frame = value;
	HX_STACK_LINE(207)
	return this->_frame;
}


HX_DEFINE_DYNAMIC_FUNC1(TileImage_obj,set_frame,return )

int TileImage_obj::get_frame( ){
	HX_STACK_PUSH("TileImage::get_frame","com/engine/direct/TileImage.hx",199);
	HX_STACK_THIS(this);
	HX_STACK_LINE(199)
	return this->_frame;
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,get_frame,return )

Void TileImage_obj::updateAnim( Float elapsed){
{
		HX_STACK_PUSH("TileImage::updateAnim","com/engine/direct/TileImage.hx",167);
		HX_STACK_THIS(this);
		HX_STACK_ARG(elapsed,"elapsed");
		HX_STACK_LINE(167)
		if (((bool((this->_anim != null())) && bool(!(this->complete))))){
			HX_STACK_LINE(170)
			hx::AddEq(this->_timer,((this->_anim->frameRate * elapsed) * this->rate));
			HX_STACK_LINE(171)
			if (((this->_timer >= (int)1))){
				HX_STACK_LINE(173)
				while(((this->_timer >= (int)1))){
					HX_STACK_LINE(175)
					(this->_timer)--;
					HX_STACK_LINE(176)
					(this->_index)++;
					HX_STACK_LINE(177)
					if (((this->_index == this->_anim->frameCount))){
						HX_STACK_LINE(178)
						if ((this->_anim->loop)){
							HX_STACK_LINE(181)
							this->_index = (int)0;
							HX_STACK_LINE(182)
							if (((this->callbackFunc_dyn() != null()))){
								HX_STACK_LINE(182)
								this->callbackFunc();
							}
						}
						else{
							HX_STACK_LINE(186)
							this->_index = (this->_anim->frameCount - (int)1);
							HX_STACK_LINE(187)
							this->complete = true;
							HX_STACK_LINE(188)
							if (((this->callbackFunc_dyn() != null()))){
								HX_STACK_LINE(188)
								this->callbackFunc();
							}
							HX_STACK_LINE(189)
							break;
						}
					}
				}
				HX_STACK_LINE(193)
				if (((this->_anim != null()))){
					HX_STACK_LINE(193)
					this->_frame = ::Std_obj::_int(this->_anim->frames->__get(this->_index));
				}
				HX_STACK_LINE(194)
				this->Graph = this->_frame;
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TileImage_obj,updateAnim,(void))

::com::engine::direct::Animation TileImage_obj::play( ::String __o_name,hx::Null< bool >  __o_reset){
::String name = __o_name.Default(HX_CSTRING(""));
bool reset = __o_reset.Default(false);
	HX_STACK_PUSH("TileImage::play","com/engine/direct/TileImage.hx",148);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(reset,"reset");
{
		HX_STACK_LINE(149)
		if (((bool((bool(!(reset)) && bool((this->_anim != null())))) && bool((this->_anim->name == name))))){
			HX_STACK_LINE(149)
			return this->_anim;
		}
		HX_STACK_LINE(150)
		if ((this->_anims->exists(name))){
			HX_STACK_LINE(152)
			this->_anim = this->_anims->get(name);
			HX_STACK_LINE(153)
			this->_timer = this->_index = (int)0;
			HX_STACK_LINE(154)
			this->_frame = this->_anim->frames->__get((int)0);
			HX_STACK_LINE(155)
			this->complete = false;
		}
		else{
			HX_STACK_LINE(159)
			this->_anim = null();
			HX_STACK_LINE(160)
			this->_frame = this->_index = (int)0;
			HX_STACK_LINE(161)
			this->complete = true;
		}
		HX_STACK_LINE(164)
		return this->_anim;
	}
}


HX_DEFINE_DYNAMIC_FUNC2(TileImage_obj,play,return )

::com::engine::direct::Animation TileImage_obj::addFrames( ::String name,int minf,int maxf,hx::Null< Float >  __o_frameRate,hx::Null< bool >  __o_loop){
Float frameRate = __o_frameRate.Default(0);
bool loop = __o_loop.Default(true);
	HX_STACK_PUSH("TileImage::addFrames","com/engine/direct/TileImage.hx",135);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(minf,"minf");
	HX_STACK_ARG(maxf,"maxf");
	HX_STACK_ARG(frameRate,"frameRate");
	HX_STACK_ARG(loop,"loop");
{
		HX_STACK_LINE(136)
		if (((this->_anims->get(name) != null()))){
			HX_STACK_LINE(136)
			return null();
		}
		HX_STACK_LINE(137)
		Array< int > frames = Array_obj< int >::__new();		HX_STACK_VAR(frames,"frames");
		HX_STACK_LINE(138)
		{
			HX_STACK_LINE(138)
			int _g = minf;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(138)
			while(((_g < maxf))){
				HX_STACK_LINE(138)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(140)
				frames->push(i);
			}
		}
		HX_STACK_LINE(142)
		::com::engine::direct::Animation anim = ::com::engine::direct::Animation_obj::__new(name,frames,frameRate,loop);		HX_STACK_VAR(anim,"anim");
		HX_STACK_LINE(143)
		this->_anims->set(name,anim);
		HX_STACK_LINE(144)
		this->_frameCount = anim->frameCount;
		HX_STACK_LINE(145)
		return anim;
	}
}


HX_DEFINE_DYNAMIC_FUNC5(TileImage_obj,addFrames,return )

::com::engine::direct::Animation TileImage_obj::add( ::String name,Array< int > frames,hx::Null< Float >  __o_frameRate,hx::Null< bool >  __o_loop){
Float frameRate = __o_frameRate.Default(0);
bool loop = __o_loop.Default(true);
	HX_STACK_PUSH("TileImage::add","com/engine/direct/TileImage.hx",122);
	HX_STACK_THIS(this);
	HX_STACK_ARG(name,"name");
	HX_STACK_ARG(frames,"frames");
	HX_STACK_ARG(frameRate,"frameRate");
	HX_STACK_ARG(loop,"loop");
{
		HX_STACK_LINE(123)
		if (((this->_anims->get(name) != null()))){
			HX_STACK_LINE(123)
			return null();
		}
		HX_STACK_LINE(124)
		{
			HX_STACK_LINE(124)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = frames->length;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(124)
			while(((_g1 < _g))){
				HX_STACK_LINE(125)
				int i = (_g1)++;		HX_STACK_VAR(i,"i");
			}
		}
		HX_STACK_LINE(129)
		::com::engine::direct::Animation anim = ::com::engine::direct::Animation_obj::__new(name,frames,frameRate,loop);		HX_STACK_VAR(anim,"anim");
		HX_STACK_LINE(130)
		this->_anims->set(name,anim);
		HX_STACK_LINE(131)
		this->_frameCount = anim->frameCount;
		HX_STACK_LINE(132)
		return anim;
	}
}


HX_DEFINE_DYNAMIC_FUNC4(TileImage_obj,add,return )

::flash::geom::Matrix TileImage_obj::getMatrix( ){
	HX_STACK_PUSH("TileImage::getMatrix","com/engine/direct/TileImage.hx",93);
	HX_STACK_THIS(this);
	HX_STACK_LINE(96)
	this->mTransformationMatrix->identity();
	HX_STACK_LINE(98)
	this->mTransformationMatrix->scale(this->ScaleX,this->ScaleY);
	HX_STACK_LINE(100)
	if (((bool((this->SkewX != 0.0)) && bool((this->SkewY != 0.0))))){
		HX_STACK_LINE(101)
		::com::engine::direct::Util_obj::skew(this->mTransformationMatrix,this->SkewX,this->SkewY);
	}
	HX_STACK_LINE(104)
	this->mTransformationMatrix->rotate(this->Rotation);
	HX_STACK_LINE(105)
	this->mTransformationMatrix->translate(this->x,this->y);
	HX_STACK_LINE(107)
	if (((bool((this->PivotX != 0.0)) || bool((this->PivotY != 0.0))))){
		HX_STACK_LINE(110)
		this->mTransformationMatrix->tx = ((this->x - (this->mTransformationMatrix->a * this->PivotX)) - (this->mTransformationMatrix->c * this->PivotY));
		HX_STACK_LINE(112)
		this->mTransformationMatrix->ty = ((this->y - (this->mTransformationMatrix->b * this->PivotX)) - (this->mTransformationMatrix->d * this->PivotY));
	}
	HX_STACK_LINE(118)
	return this->mTransformationMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,getMatrix,return )

Void TileImage_obj::kill( ){
{
		HX_STACK_PUSH("TileImage::kill","com/engine/direct/TileImage.hx",88);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,kill,(void))

Void TileImage_obj::update( ){
{
		HX_STACK_PUSH("TileImage::update","com/engine/direct/TileImage.hx",84);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,update,(void))

Void TileImage_obj::destroy( ){
{
		HX_STACK_PUSH("TileImage::destroy","com/engine/direct/TileImage.hx",80);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,destroy,(void))

::String TileImage_obj::set_name( ::String value){
	HX_STACK_PUSH("TileImage::set_name","com/engine/direct/TileImage.hx",56);
	HX_STACK_THIS(this);
	HX_STACK_ARG(value,"value");
	HX_STACK_LINE(56)
	this->mName = value;
	HX_STACK_LINE(56)
	return this->mName;
}


HX_DEFINE_DYNAMIC_FUNC1(TileImage_obj,set_name,return )

::String TileImage_obj::get_name( ){
	HX_STACK_PUSH("TileImage::get_name","com/engine/direct/TileImage.hx",55);
	HX_STACK_THIS(this);
	HX_STACK_LINE(55)
	return this->mName;
}


HX_DEFINE_DYNAMIC_FUNC0(TileImage_obj,get_name,return )


TileImage_obj::TileImage_obj()
{
}

void TileImage_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TileImage);
	HX_MARK_MEMBER_NAME(currentAnim,"currentAnim");
	HX_MARK_MEMBER_NAME(frameCount,"frameCount");
	HX_MARK_MEMBER_NAME(Graph,"Graph");
	HX_MARK_MEMBER_NAME(Layer,"Layer");
	HX_MARK_MEMBER_NAME(mTransformationMatrix,"mTransformationMatrix");
	HX_MARK_MEMBER_NAME(mParent,"mParent");
	HX_MARK_MEMBER_NAME(mName,"mName");
	HX_MARK_MEMBER_NAME(Visible,"Visible");
	HX_MARK_MEMBER_NAME(Blue,"Blue");
	HX_MARK_MEMBER_NAME(Green,"Green");
	HX_MARK_MEMBER_NAME(Red,"Red");
	HX_MARK_MEMBER_NAME(Alpha,"Alpha");
	HX_MARK_MEMBER_NAME(Rotation,"Rotation");
	HX_MARK_MEMBER_NAME(SkewY,"SkewY");
	HX_MARK_MEMBER_NAME(SkewX,"SkewX");
	HX_MARK_MEMBER_NAME(ScaleY,"ScaleY");
	HX_MARK_MEMBER_NAME(ScaleX,"ScaleX");
	HX_MARK_MEMBER_NAME(PivotY,"PivotY");
	HX_MARK_MEMBER_NAME(PivotX,"PivotX");
	HX_MARK_MEMBER_NAME(y,"y");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_MEMBER_NAME(_timer,"_timer");
	HX_MARK_MEMBER_NAME(_frame,"_frame");
	HX_MARK_MEMBER_NAME(_index,"_index");
	HX_MARK_MEMBER_NAME(_anim,"_anim");
	HX_MARK_MEMBER_NAME(_anims,"_anims");
	HX_MARK_MEMBER_NAME(_frameCount,"_frameCount");
	HX_MARK_MEMBER_NAME(rate,"rate");
	HX_MARK_MEMBER_NAME(callbackFunc,"callbackFunc");
	HX_MARK_MEMBER_NAME(complete,"complete");
	HX_MARK_MEMBER_NAME(originY,"originY");
	HX_MARK_MEMBER_NAME(originX,"originX");
	HX_MARK_MEMBER_NAME(height,"height");
	HX_MARK_MEMBER_NAME(width,"width");
	HX_MARK_END_CLASS();
}

void TileImage_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(currentAnim,"currentAnim");
	HX_VISIT_MEMBER_NAME(frameCount,"frameCount");
	HX_VISIT_MEMBER_NAME(Graph,"Graph");
	HX_VISIT_MEMBER_NAME(Layer,"Layer");
	HX_VISIT_MEMBER_NAME(mTransformationMatrix,"mTransformationMatrix");
	HX_VISIT_MEMBER_NAME(mParent,"mParent");
	HX_VISIT_MEMBER_NAME(mName,"mName");
	HX_VISIT_MEMBER_NAME(Visible,"Visible");
	HX_VISIT_MEMBER_NAME(Blue,"Blue");
	HX_VISIT_MEMBER_NAME(Green,"Green");
	HX_VISIT_MEMBER_NAME(Red,"Red");
	HX_VISIT_MEMBER_NAME(Alpha,"Alpha");
	HX_VISIT_MEMBER_NAME(Rotation,"Rotation");
	HX_VISIT_MEMBER_NAME(SkewY,"SkewY");
	HX_VISIT_MEMBER_NAME(SkewX,"SkewX");
	HX_VISIT_MEMBER_NAME(ScaleY,"ScaleY");
	HX_VISIT_MEMBER_NAME(ScaleX,"ScaleX");
	HX_VISIT_MEMBER_NAME(PivotY,"PivotY");
	HX_VISIT_MEMBER_NAME(PivotX,"PivotX");
	HX_VISIT_MEMBER_NAME(y,"y");
	HX_VISIT_MEMBER_NAME(x,"x");
	HX_VISIT_MEMBER_NAME(_timer,"_timer");
	HX_VISIT_MEMBER_NAME(_frame,"_frame");
	HX_VISIT_MEMBER_NAME(_index,"_index");
	HX_VISIT_MEMBER_NAME(_anim,"_anim");
	HX_VISIT_MEMBER_NAME(_anims,"_anims");
	HX_VISIT_MEMBER_NAME(_frameCount,"_frameCount");
	HX_VISIT_MEMBER_NAME(rate,"rate");
	HX_VISIT_MEMBER_NAME(callbackFunc,"callbackFunc");
	HX_VISIT_MEMBER_NAME(complete,"complete");
	HX_VISIT_MEMBER_NAME(originY,"originY");
	HX_VISIT_MEMBER_NAME(originX,"originX");
	HX_VISIT_MEMBER_NAME(height,"height");
	HX_VISIT_MEMBER_NAME(width,"width");
}

Dynamic TileImage_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { return y; }
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"add") ) { return add_dyn(); }
		if (HX_FIELD_EQ(inName,"Red") ) { return Red; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"play") ) { return play_dyn(); }
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		if (HX_FIELD_EQ(inName,"name") ) { return get_name(); }
		if (HX_FIELD_EQ(inName,"Blue") ) { return Blue; }
		if (HX_FIELD_EQ(inName,"rate") ) { return rate; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"frame") ) { return get_frame(); }
		if (HX_FIELD_EQ(inName,"Graph") ) { return Graph; }
		if (HX_FIELD_EQ(inName,"Layer") ) { return Layer; }
		if (HX_FIELD_EQ(inName,"mName") ) { return mName; }
		if (HX_FIELD_EQ(inName,"Green") ) { return Green; }
		if (HX_FIELD_EQ(inName,"Alpha") ) { return Alpha; }
		if (HX_FIELD_EQ(inName,"SkewY") ) { return SkewY; }
		if (HX_FIELD_EQ(inName,"SkewX") ) { return SkewX; }
		if (HX_FIELD_EQ(inName,"_anim") ) { return _anim; }
		if (HX_FIELD_EQ(inName,"width") ) { return width; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"ScaleY") ) { return ScaleY; }
		if (HX_FIELD_EQ(inName,"ScaleX") ) { return ScaleX; }
		if (HX_FIELD_EQ(inName,"PivotY") ) { return PivotY; }
		if (HX_FIELD_EQ(inName,"PivotX") ) { return PivotX; }
		if (HX_FIELD_EQ(inName,"_timer") ) { return _timer; }
		if (HX_FIELD_EQ(inName,"_frame") ) { return _frame; }
		if (HX_FIELD_EQ(inName,"_index") ) { return _index; }
		if (HX_FIELD_EQ(inName,"_anims") ) { return _anims; }
		if (HX_FIELD_EQ(inName,"height") ) { return height; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		if (HX_FIELD_EQ(inName,"mParent") ) { return mParent; }
		if (HX_FIELD_EQ(inName,"Visible") ) { return Visible; }
		if (HX_FIELD_EQ(inName,"originY") ) { return originY; }
		if (HX_FIELD_EQ(inName,"originX") ) { return originX; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"set_name") ) { return set_name_dyn(); }
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		if (HX_FIELD_EQ(inName,"Rotation") ) { return Rotation; }
		if (HX_FIELD_EQ(inName,"complete") ) { return complete; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"set_frame") ) { return set_frame_dyn(); }
		if (HX_FIELD_EQ(inName,"get_frame") ) { return get_frame_dyn(); }
		if (HX_FIELD_EQ(inName,"addFrames") ) { return addFrames_dyn(); }
		if (HX_FIELD_EQ(inName,"getMatrix") ) { return getMatrix_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { return inCallProp ? get_frameCount() : frameCount; }
		if (HX_FIELD_EQ(inName,"updateAnim") ) { return updateAnim_dyn(); }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentAnim") ) { return inCallProp ? get_currentAnim() : currentAnim; }
		if (HX_FIELD_EQ(inName,"_frameCount") ) { return _frameCount; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callbackFunc") ) { return callbackFunc; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"get_frameCount") ) { return get_frameCount_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"get_currentAnim") ) { return get_currentAnim_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mTransformationMatrix") ) { return mTransformationMatrix; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TileImage_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"y") ) { y=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< Float >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"Red") ) { Red=inValue.Cast< Float >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"name") ) { return set_name(inValue); }
		if (HX_FIELD_EQ(inName,"Blue") ) { Blue=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rate") ) { rate=inValue.Cast< Float >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"frame") ) { return set_frame(inValue); }
		if (HX_FIELD_EQ(inName,"Graph") ) { Graph=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Layer") ) { Layer=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mName") ) { mName=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Green") ) { Green=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Alpha") ) { Alpha=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SkewY") ) { SkewY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"SkewX") ) { SkewX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_anim") ) { _anim=inValue.Cast< ::com::engine::direct::Animation >(); return inValue; }
		if (HX_FIELD_EQ(inName,"width") ) { width=inValue.Cast< int >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"ScaleY") ) { ScaleY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"ScaleX") ) { ScaleX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PivotY") ) { PivotY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"PivotX") ) { PivotX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_timer") ) { _timer=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_frame") ) { _frame=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_index") ) { _index=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_anims") ) { _anims=inValue.Cast< ::haxe::ds::StringMap >(); return inValue; }
		if (HX_FIELD_EQ(inName,"height") ) { height=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mParent") ) { mParent=inValue.Cast< ::com::engine::direct::TileImage >(); return inValue; }
		if (HX_FIELD_EQ(inName,"Visible") ) { Visible=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"originY") ) { originY=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"originX") ) { originX=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"Rotation") ) { Rotation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"complete") ) { complete=inValue.Cast< bool >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"frameCount") ) { frameCount=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"currentAnim") ) { currentAnim=inValue.Cast< ::String >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_frameCount") ) { _frameCount=inValue.Cast< int >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"callbackFunc") ) { callbackFunc=inValue.Cast< Dynamic >(); return inValue; }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"mTransformationMatrix") ) { mTransformationMatrix=inValue.Cast< ::flash::geom::Matrix >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TileImage_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("currentAnim"));
	outFields->push(HX_CSTRING("frameCount"));
	outFields->push(HX_CSTRING("frame"));
	outFields->push(HX_CSTRING("name"));
	outFields->push(HX_CSTRING("Graph"));
	outFields->push(HX_CSTRING("Layer"));
	outFields->push(HX_CSTRING("mTransformationMatrix"));
	outFields->push(HX_CSTRING("mParent"));
	outFields->push(HX_CSTRING("mName"));
	outFields->push(HX_CSTRING("Visible"));
	outFields->push(HX_CSTRING("Blue"));
	outFields->push(HX_CSTRING("Green"));
	outFields->push(HX_CSTRING("Red"));
	outFields->push(HX_CSTRING("Alpha"));
	outFields->push(HX_CSTRING("Rotation"));
	outFields->push(HX_CSTRING("SkewY"));
	outFields->push(HX_CSTRING("SkewX"));
	outFields->push(HX_CSTRING("ScaleY"));
	outFields->push(HX_CSTRING("ScaleX"));
	outFields->push(HX_CSTRING("PivotY"));
	outFields->push(HX_CSTRING("PivotX"));
	outFields->push(HX_CSTRING("y"));
	outFields->push(HX_CSTRING("x"));
	outFields->push(HX_CSTRING("_timer"));
	outFields->push(HX_CSTRING("_frame"));
	outFields->push(HX_CSTRING("_index"));
	outFields->push(HX_CSTRING("_anim"));
	outFields->push(HX_CSTRING("_anims"));
	outFields->push(HX_CSTRING("_frameCount"));
	outFields->push(HX_CSTRING("rate"));
	outFields->push(HX_CSTRING("complete"));
	outFields->push(HX_CSTRING("originY"));
	outFields->push(HX_CSTRING("originX"));
	outFields->push(HX_CSTRING("height"));
	outFields->push(HX_CSTRING("width"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_currentAnim"),
	HX_CSTRING("currentAnim"),
	HX_CSTRING("get_frameCount"),
	HX_CSTRING("frameCount"),
	HX_CSTRING("set_frame"),
	HX_CSTRING("get_frame"),
	HX_CSTRING("updateAnim"),
	HX_CSTRING("play"),
	HX_CSTRING("addFrames"),
	HX_CSTRING("add"),
	HX_CSTRING("getMatrix"),
	HX_CSTRING("kill"),
	HX_CSTRING("update"),
	HX_CSTRING("destroy"),
	HX_CSTRING("set_name"),
	HX_CSTRING("get_name"),
	HX_CSTRING("Graph"),
	HX_CSTRING("Layer"),
	HX_CSTRING("mTransformationMatrix"),
	HX_CSTRING("mParent"),
	HX_CSTRING("mName"),
	HX_CSTRING("Visible"),
	HX_CSTRING("Blue"),
	HX_CSTRING("Green"),
	HX_CSTRING("Red"),
	HX_CSTRING("Alpha"),
	HX_CSTRING("Rotation"),
	HX_CSTRING("SkewY"),
	HX_CSTRING("SkewX"),
	HX_CSTRING("ScaleY"),
	HX_CSTRING("ScaleX"),
	HX_CSTRING("PivotY"),
	HX_CSTRING("PivotX"),
	HX_CSTRING("y"),
	HX_CSTRING("x"),
	HX_CSTRING("_timer"),
	HX_CSTRING("_frame"),
	HX_CSTRING("_index"),
	HX_CSTRING("_anim"),
	HX_CSTRING("_anims"),
	HX_CSTRING("_frameCount"),
	HX_CSTRING("rate"),
	HX_CSTRING("callbackFunc"),
	HX_CSTRING("complete"),
	HX_CSTRING("originY"),
	HX_CSTRING("originX"),
	HX_CSTRING("height"),
	HX_CSTRING("width"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TileImage_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TileImage_obj::__mClass,"__mClass");
};

Class TileImage_obj::__mClass;

void TileImage_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.direct.TileImage"), hx::TCanCast< TileImage_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TileImage_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace direct
