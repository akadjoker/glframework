#include <hxcpp.h>

#ifndef INCLUDED_com_djoker_glteste_Particle
#include <com/djoker/glteste/Particle.h>
#endif
#ifndef INCLUDED_com_djoker_glteste_TesteBatch
#include <com/djoker/glteste/TesteBatch.h>
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
#ifndef INCLUDED_com_engine_render_BlendMode
#include <com/engine/render/BlendMode.h>
#endif
#ifndef INCLUDED_com_engine_render_Buffer
#include <com/engine/render/Buffer.h>
#endif
#ifndef INCLUDED_com_engine_render_Image
#include <com/engine/render/Image.h>
#endif
#ifndef INCLUDED_com_engine_render_SpriteBatch
#include <com/engine/render/SpriteBatch.h>
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
#ifndef INCLUDED_openfl_display_DirectRenderer
#include <openfl/display/DirectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_OpenGLView
#include <openfl/display/OpenGLView.h>
#endif
namespace com{
namespace djoker{
namespace glteste{

Void TesteBatch_obj::__construct()
{
HX_STACK_PUSH("TesteBatch::new","com/djoker/glteste/TesteBatch.hx",16);
{
	HX_STACK_LINE(16)
	super::__construct();
}
;
	return null();
}

TesteBatch_obj::~TesteBatch_obj() { }

Dynamic TesteBatch_obj::__CreateEmpty() { return  new TesteBatch_obj; }
hx::ObjectPtr< TesteBatch_obj > TesteBatch_obj::__new()
{  hx::ObjectPtr< TesteBatch_obj > result = new TesteBatch_obj();
	result->__construct();
	return result;}

Dynamic TesteBatch_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TesteBatch_obj > result = new TesteBatch_obj();
	result->__construct();
	return result;}

Void TesteBatch_obj::mouseDown( Float mousex,Float mousey){
{
		HX_STACK_PUSH("TesteBatch::mouseDown","com/djoker/glteste/TesteBatch.hx",84);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
		HX_STACK_LINE(84)
		this->addParticle2(mousex,mousey);
	}
return null();
}


Void TesteBatch_obj::addParticle2( Float x,Float y){
{
		HX_STACK_PUSH("TesteBatch::addParticle2","com/djoker/glteste/TesteBatch.hx",74);
		HX_STACK_THIS(this);
		HX_STACK_ARG(x,"x");
		HX_STACK_ARG(y,"y");
		HX_STACK_LINE(75)
		::com::djoker::glteste::Particle particle = ::com::djoker::glteste::Particle_obj::__new(this->tex);		HX_STACK_VAR(particle,"particle");
		HX_STACK_LINE(76)
		particle->Init();
		HX_STACK_LINE(77)
		particle->x = x;
		HX_STACK_LINE(78)
		particle->y = y;
		HX_STACK_LINE(79)
		particle->blendMode = ::com::engine::render::BlendMode_obj::NORMAL;
		HX_STACK_LINE(80)
		this->particles->push(particle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TesteBatch_obj,addParticle2,(void))

Void TesteBatch_obj::addParticle( ){
{
		HX_STACK_PUSH("TesteBatch::addParticle","com/djoker/glteste/TesteBatch.hx",67);
		HX_STACK_THIS(this);
		HX_STACK_LINE(68)
		::com::djoker::glteste::Particle particle = ::com::djoker::glteste::Particle_obj::__new(this->tex);		HX_STACK_VAR(particle,"particle");
		HX_STACK_LINE(69)
		particle->Init();
		HX_STACK_LINE(70)
		particle->blendMode = ::com::engine::render::BlendMode_obj::NORMAL;
		HX_STACK_LINE(71)
		this->particles->push(particle);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TesteBatch_obj,addParticle,(void))

Void TesteBatch_obj::render( Float dt){
{
		HX_STACK_PUSH("TesteBatch::render","com/djoker/glteste/TesteBatch.hx",50);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(52)
		this->batch->Begin();
		HX_STACK_LINE(54)
		{
			HX_STACK_LINE(54)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			Array< ::Dynamic > _g1 = this->particles;		HX_STACK_VAR(_g1,"_g1");
			HX_STACK_LINE(54)
			while(((_g < _g1->length))){
				HX_STACK_LINE(54)
				::com::djoker::glteste::Particle p = _g1->__get(_g).StaticCast< ::com::djoker::glteste::Particle >();		HX_STACK_VAR(p,"p");
				HX_STACK_LINE(54)
				++(_g);
				HX_STACK_LINE(56)
				p->move(dt);
				HX_STACK_LINE(58)
				this->batch->drawImage(p);
			}
		}
		HX_STACK_LINE(60)
		this->batch->End();
	}
return null();
}


Void TesteBatch_obj::show( ){
{
		HX_STACK_PUSH("TesteBatch::show","com/djoker/glteste/TesteBatch.hx",29);
		HX_STACK_THIS(this);
		HX_STACK_LINE(31)
		this->tex = ::com::engine::render::Texture_obj::__new(HX_CSTRING("assets/texture.png"));
		HX_STACK_LINE(32)
		this->batch = ::com::engine::render::SpriteBatch_obj::__new((int)500);
		HX_STACK_LINE(33)
		this->particles = Array_obj< ::Dynamic >::__new();
		HX_STACK_LINE(34)
		{
			HX_STACK_LINE(34)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(34)
			while(((_g < (int)200))){
				HX_STACK_LINE(34)
				int i = (_g)++;		HX_STACK_VAR(i,"i");
				HX_STACK_LINE(35)
				this->addParticle();
			}
		}
		HX_STACK_LINE(38)
		::flash::text::TextField caption = ::flash::text::TextField_obj::__new();		HX_STACK_VAR(caption,"caption");
		HX_STACK_LINE(39)
		caption->set_x(((Float(this->game->gameWidth) / Float((int)2)) - (int)100));
		HX_STACK_LINE(40)
		caption->set_y((int)20);
		HX_STACK_LINE(41)
		caption->set_width((int)200);
		HX_STACK_LINE(42)
		caption->set_defaultTextFormat(::flash::text::TextFormat_obj::__new(HX_CSTRING("_sans"),(int)12,(int)16776960,null(),null(),null(),null(),null(),null(),null(),null(),null(),null()));
		HX_STACK_LINE(43)
		caption->set_text(HX_CSTRING("Test 200 sprites with  SpriteBatch "));
		HX_STACK_LINE(44)
		this->game->addChild(caption);
	}
return null();
}



TesteBatch_obj::TesteBatch_obj()
{
}

void TesteBatch_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TesteBatch);
	HX_MARK_MEMBER_NAME(particles,"particles");
	HX_MARK_MEMBER_NAME(batch,"batch");
	HX_MARK_MEMBER_NAME(tex,"tex");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TesteBatch_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(particles,"particles");
	HX_VISIT_MEMBER_NAME(batch,"batch");
	HX_VISIT_MEMBER_NAME(tex,"tex");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TesteBatch_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tex") ) { return tex; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"show") ) { return show_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"batch") ) { return batch; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"particles") ) { return particles; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"addParticle") ) { return addParticle_dyn(); }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"addParticle2") ) { return addParticle2_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TesteBatch_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"tex") ) { tex=inValue.Cast< ::com::engine::render::Texture >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"batch") ) { batch=inValue.Cast< ::com::engine::render::SpriteBatch >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"particles") ) { particles=inValue.Cast< Array< ::Dynamic > >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TesteBatch_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("particles"));
	outFields->push(HX_CSTRING("batch"));
	outFields->push(HX_CSTRING("tex"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("mouseDown"),
	HX_CSTRING("addParticle2"),
	HX_CSTRING("addParticle"),
	HX_CSTRING("render"),
	HX_CSTRING("show"),
	HX_CSTRING("particles"),
	HX_CSTRING("batch"),
	HX_CSTRING("tex"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TesteBatch_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TesteBatch_obj::__mClass,"__mClass");
};

Class TesteBatch_obj::__mClass;

void TesteBatch_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.djoker.glteste.TesteBatch"), hx::TCanCast< TesteBatch_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TesteBatch_obj::__boot()
{
}

} // end namespace com
} // end namespace djoker
} // end namespace glteste
