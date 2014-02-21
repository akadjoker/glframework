#include <hxcpp.h>

#ifndef INCLUDED_com_djoker_glteste_TesteCloudTiles
#include <com/djoker/glteste/TesteCloudTiles.h>
#endif
#ifndef INCLUDED_com_engine_game_Game
#include <com/engine/game/Game.h>
#endif
#ifndef INCLUDED_com_engine_game_Screen
#include <com/engine/game/Screen.h>
#endif
#ifndef INCLUDED_com_engine_game_Transform
#include <com/engine/game/Transform.h>
#endif
#ifndef INCLUDED_com_engine_math_Vector2
#include <com/engine/math/Vector2.h>
#endif
#ifndef INCLUDED_com_engine_math_Vector3
#include <com/engine/math/Vector3.h>
#endif
#ifndef INCLUDED_com_engine_render_BatchPrimitives
#include <com/engine/render/BatchPrimitives.h>
#endif
#ifndef INCLUDED_com_engine_render_Buffer
#include <com/engine/render/Buffer.h>
#endif
#ifndef INCLUDED_com_engine_render_Clip
#include <com/engine/render/Clip.h>
#endif
#ifndef INCLUDED_com_engine_render_SpriteCloud
#include <com/engine/render/SpriteCloud.h>
#endif
#ifndef INCLUDED_com_engine_render_Texture
#include <com/engine/render/Texture.h>
#endif
#ifndef INCLUDED_com_engine_render_TileMap
#include <com/engine/render/TileMap.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_text_TextFormat
#include <flash/text/TextFormat.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_Assets
#include <openfl/Assets.h>
#endif
#ifndef INCLUDED_openfl_display_DirectRenderer
#include <openfl/display/DirectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_OpenGLView
#include <openfl/display/OpenGLView.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void TesteCloudTiles_obj::__construct()
{
HX_STACK_PUSH("TesteCloudTiles::new","com/djoker/glteste/TesteCloudTiles.hx",28);
{
	HX_STACK_LINE(28)
	super::__construct();
}
;
	return null();
}

TesteCloudTiles_obj::~TesteCloudTiles_obj() { }

Dynamic TesteCloudTiles_obj::__CreateEmpty() { return  new TesteCloudTiles_obj; }
hx::ObjectPtr< TesteCloudTiles_obj > TesteCloudTiles_obj::__new()
{  hx::ObjectPtr< TesteCloudTiles_obj > result = new TesteCloudTiles_obj();
	result->__construct();
	return result;}

Dynamic TesteCloudTiles_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TesteCloudTiles_obj > result = new TesteCloudTiles_obj();
	result->__construct();
	return result;}

Void TesteCloudTiles_obj::mouseUp( Float mousex,Float mousey){
{
		HX_STACK_PUSH("TesteCloudTiles::mouseUp","com/djoker/glteste/TesteCloudTiles.hx",146);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
		HX_STACK_LINE(146)
		this->toutch = false;
	}
return null();
}


Void TesteCloudTiles_obj::mouseMove( Float mousex,Float mousey){
{
		HX_STACK_PUSH("TesteCloudTiles::mouseMove","com/djoker/glteste/TesteCloudTiles.hx",126);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
		HX_STACK_LINE(126)
		if (((this->toutch == true))){
			HX_STACK_LINE(131)
			this->Toutch->x = mousex;
			HX_STACK_LINE(132)
			this->Toutch->y = mousey;
			HX_STACK_LINE(136)
			::com::engine::math::Vector3 dir = ::com::engine::math::Vector3_obj::Sub(this->Toutch,this->lastToutch);		HX_STACK_VAR(dir,"dir");
			HX_STACK_LINE(137)
			{
				HX_STACK_LINE(137)
				Float len = ::Math_obj::sqrt((((dir->x * dir->x) + (dir->y * dir->y)) + (dir->z * dir->z)));		HX_STACK_VAR(len,"len");
				HX_STACK_LINE(137)
				if (((len != (int)0))){
					HX_STACK_LINE(137)
					Float num = (Float(1.0) / Float(len));		HX_STACK_VAR(num,"num");
					HX_STACK_LINE(137)
					hx::MultEq(dir->x,num);
					HX_STACK_LINE(137)
					hx::MultEq(dir->y,num);
					HX_STACK_LINE(137)
					hx::MultEq(dir->z,num);
				}
			}
			HX_STACK_LINE(140)
			hx::AddEq(this->batch->position->x,((dir->x * this->game->deltaTime) * (int)1000));
			HX_STACK_LINE(141)
			hx::AddEq(this->batch->position->y,((dir->y * this->game->deltaTime) * (int)1000));
		}
	}
return null();
}


Void TesteCloudTiles_obj::mouseDown( Float mousex,Float mousey){
{
		HX_STACK_PUSH("TesteCloudTiles::mouseDown","com/djoker/glteste/TesteCloudTiles.hx",117);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
		HX_STACK_LINE(118)
		this->toutch = true;
		HX_STACK_LINE(119)
		this->lastToutch->x = mousex;
		HX_STACK_LINE(120)
		this->lastToutch->y = mousey;
	}
return null();
}


Void TesteCloudTiles_obj::render( Float dt){
{
		HX_STACK_PUSH("TesteCloudTiles::render","com/djoker/glteste/TesteCloudTiles.hx",98);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(103)
		this->batch->render();
		HX_STACK_LINE(105)
		this->primitives->begin();
		HX_STACK_LINE(106)
		this->primitives->renderMode(false);
		HX_STACK_LINE(108)
		this->primitives->line(this->lastToutch->x,this->lastToutch->y,this->Toutch->x,this->Toutch->y,(int)1,(int)0,(int)0,null());
		HX_STACK_LINE(110)
		this->primitives->render();
		HX_STACK_LINE(111)
		this->primitives->end_dyn();
	}
return null();
}


Void TesteCloudTiles_obj::show( ){
{
		HX_STACK_PUSH("TesteCloudTiles::show","com/djoker/glteste/TesteCloudTiles.hx",48);
		HX_STACK_THIS(this);
		HX_STACK_LINE(52)
		this->primitives = ::com::engine::render::BatchPrimitives_obj::__new((int)100);
		HX_STACK_LINE(54)
		this->tilemap = ::com::engine::render::TileMap_obj::__new(::openfl::Assets_obj::getText(HX_CSTRING("assets/map.tmx")));
		HX_STACK_LINE(58)
		this->batch = ::com::engine::render::SpriteCloud_obj::__new(this->tilemap->image,(int)3000);
		HX_STACK_LINE(62)
		int tw = this->tilemap->tileWidth;		HX_STACK_VAR(tw,"tw");
		HX_STACK_LINE(63)
		int th = this->tilemap->tileHeight;		HX_STACK_VAR(th,"th");
		HX_STACK_LINE(66)
		{
			HX_STACK_LINE(66)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->tilemap->heightInTiles;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(66)
			while(((_g1 < _g))){
				HX_STACK_LINE(66)
				int y = (_g1)++;		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(68)
				{
					HX_STACK_LINE(68)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					int _g2 = this->tilemap->widthInTiles;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(68)
					while(((_g3 < _g2))){
						HX_STACK_LINE(68)
						int x = (_g3)++;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(72)
						int id = this->tilemap->getCell(x,y);		HX_STACK_VAR(id,"id");
						HX_STACK_LINE(73)
						if (((id >= (int)1))){
							HX_STACK_LINE(75)
							::com::engine::render::Clip t = this->tilemap->getClip((id - (int)1));		HX_STACK_VAR(t,"t");
							HX_STACK_LINE(76)
							this->batch->addTile((x * tw),(y * th),tw,th,t,false,true);
						}
					}
				}
			}
		}
		HX_STACK_LINE(83)
		::flash::text::TextField caption = ::flash::text::TextField_obj::__new();		HX_STACK_VAR(caption,"caption");
		HX_STACK_LINE(84)
		caption->set_x(((Float(this->game->screenWidth) / Float((int)2)) - (int)100));
		HX_STACK_LINE(85)
		caption->set_y((int)20);
		HX_STACK_LINE(86)
		caption->set_width((int)200);
		HX_STACK_LINE(87)
		caption->set_defaultTextFormat(::flash::text::TextFormat_obj::__new(HX_CSTRING("_sans"),(int)12,(int)16776960,null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
		HX_STACK_LINE(88)
		caption->set_text(((HX_CSTRING("Test ") + this->batch->currentBatchSize) + HX_CSTRING(" statics sprites ")));
		HX_STACK_LINE(89)
		this->game->addChild(caption);
		HX_STACK_LINE(91)
		this->Toutch = ::com::engine::math::Vector3_obj::__new((int)0,(int)0,null());
		HX_STACK_LINE(92)
		this->lastToutch = ::com::engine::math::Vector3_obj::__new((int)0,(int)0,null());
	}
return null();
}



TesteCloudTiles_obj::TesteCloudTiles_obj()
{
}

void TesteCloudTiles_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TesteCloudTiles);
	HX_MARK_MEMBER_NAME(lastToutch,"lastToutch");
	HX_MARK_MEMBER_NAME(Toutch,"Toutch");
	HX_MARK_MEMBER_NAME(disty,"disty");
	HX_MARK_MEMBER_NAME(distx,"distx");
	HX_MARK_MEMBER_NAME(toutch,"toutch");
	HX_MARK_MEMBER_NAME(mouseY,"mouseY");
	HX_MARK_MEMBER_NAME(mouseX,"mouseX");
	HX_MARK_MEMBER_NAME(lastmouseY,"lastmouseY");
	HX_MARK_MEMBER_NAME(lastmouseX,"lastmouseX");
	HX_MARK_MEMBER_NAME(tilemap,"tilemap");
	HX_MARK_MEMBER_NAME(primitives,"primitives");
	HX_MARK_MEMBER_NAME(batch,"batch");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TesteCloudTiles_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(lastToutch,"lastToutch");
	HX_VISIT_MEMBER_NAME(Toutch,"Toutch");
	HX_VISIT_MEMBER_NAME(disty,"disty");
	HX_VISIT_MEMBER_NAME(distx,"distx");
	HX_VISIT_MEMBER_NAME(toutch,"toutch");
	HX_VISIT_MEMBER_NAME(mouseY,"mouseY");
	HX_VISIT_MEMBER_NAME(mouseX,"mouseX");
	HX_VISIT_MEMBER_NAME(lastmouseY,"lastmouseY");
	HX_VISIT_MEMBER_NAME(lastmouseX,"lastmouseX");
	HX_VISIT_MEMBER_NAME(tilemap,"tilemap");
	HX_VISIT_MEMBER_NAME(primitives,"primitives");
	HX_VISIT_MEMBER_NAME(batch,"batch");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TesteCloudTiles_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"disty") ) { return disty; }
		if (HX_FIELD_EQ(inName,"distx") ) { return distx; }
		if (HX_FIELD_EQ(inName,"batch") ) { return batch; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"Toutch") ) { return Toutch; }
		if (HX_FIELD_EQ(inName,"toutch") ) { return toutch; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { return mouseY; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { return mouseX; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"mouseUp") ) { return mouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"tilemap") ) { return tilemap; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseMove") ) { return mouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lastToutch") ) { return lastToutch; }
		if (HX_FIELD_EQ(inName,"lastmouseY") ) { return lastmouseY; }
		if (HX_FIELD_EQ(inName,"lastmouseX") ) { return lastmouseX; }
		if (HX_FIELD_EQ(inName,"primitives") ) { return primitives; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TesteCloudTiles_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"disty") ) { disty=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"distx") ) { distx=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"batch") ) { batch=inValue.Cast< ::com::engine::render::SpriteCloud >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"Toutch") ) { Toutch=inValue.Cast< ::com::engine::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"toutch") ) { toutch=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseY") ) { mouseY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mouseX") ) { mouseX=inValue.Cast< Float >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"tilemap") ) { tilemap=inValue.Cast< ::com::engine::render::TileMap >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"lastToutch") ) { lastToutch=inValue.Cast< ::com::engine::math::Vector3 >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lastmouseY") ) { lastmouseY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"lastmouseX") ) { lastmouseX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"primitives") ) { primitives=inValue.Cast< ::com::engine::render::BatchPrimitives >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TesteCloudTiles_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("lastToutch"));
	outFields->push(HX_CSTRING("Toutch"));
	outFields->push(HX_CSTRING("disty"));
	outFields->push(HX_CSTRING("distx"));
	outFields->push(HX_CSTRING("toutch"));
	outFields->push(HX_CSTRING("mouseY"));
	outFields->push(HX_CSTRING("mouseX"));
	outFields->push(HX_CSTRING("lastmouseY"));
	outFields->push(HX_CSTRING("lastmouseX"));
	outFields->push(HX_CSTRING("tilemap"));
	outFields->push(HX_CSTRING("primitives"));
	outFields->push(HX_CSTRING("batch"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mouseUp"),
	HX_CSTRING("mouseMove"),
	HX_CSTRING("mouseDown"),
	HX_CSTRING("render"),
	HX_CSTRING("show"),
	HX_CSTRING("lastToutch"),
	HX_CSTRING("Toutch"),
	HX_CSTRING("disty"),
	HX_CSTRING("distx"),
	HX_CSTRING("toutch"),
	HX_CSTRING("mouseY"),
	HX_CSTRING("mouseX"),
	HX_CSTRING("lastmouseY"),
	HX_CSTRING("lastmouseX"),
	HX_CSTRING("tilemap"),
	HX_CSTRING("primitives"),
	HX_CSTRING("batch"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TesteCloudTiles_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TesteCloudTiles_obj::__mClass,"__mClass");
};

Class TesteCloudTiles_obj::__mClass;

void TesteCloudTiles_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.TesteCloudTiles"), hx::TCanCast< TesteCloudTiles_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TesteCloudTiles_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
