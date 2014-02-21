#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
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
#ifndef INCLUDED_com_engine_math_Matrix
#include <com/engine/math/Matrix.h>
#endif
#ifndef INCLUDED_flash_Lib
#include <flash/Lib.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObject
#include <flash/display/DisplayObject.h>
#endif
#ifndef INCLUDED_flash_display_DisplayObjectContainer
#include <flash/display/DisplayObjectContainer.h>
#endif
#ifndef INCLUDED_flash_display_IBitmapDrawable
#include <flash/display/IBitmapDrawable.h>
#endif
#ifndef INCLUDED_flash_display_InteractiveObject
#include <flash/display/InteractiveObject.h>
#endif
#ifndef INCLUDED_flash_display_MovieClip
#include <flash/display/MovieClip.h>
#endif
#ifndef INCLUDED_flash_display_Sprite
#include <flash/display/Sprite.h>
#endif
#ifndef INCLUDED_flash_display_Stage
#include <flash/display/Stage.h>
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
#ifndef INCLUDED_flash_events_KeyboardEvent
#include <flash/events/KeyboardEvent.h>
#endif
#ifndef INCLUDED_flash_events_MouseEvent
#include <flash/events/MouseEvent.h>
#endif
#ifndef INCLUDED_flash_events_TouchEvent
#include <flash/events/TouchEvent.h>
#endif
#ifndef INCLUDED_flash_geom_Rectangle
#include <flash/geom/Rectangle.h>
#endif
#ifndef INCLUDED_flash_text_TextField
#include <flash/text/TextField.h>
#endif
#ifndef INCLUDED_flash_ui_Multitouch
#include <flash/ui/Multitouch.h>
#endif
#ifndef INCLUDED_flash_ui_MultitouchInputMode
#include <flash/ui/MultitouchInputMode.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
#ifndef INCLUDED_openfl_display_DirectRenderer
#include <openfl/display/DirectRenderer.h>
#endif
#ifndef INCLUDED_openfl_display_FPS
#include <openfl/display/FPS.h>
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
#ifndef INCLUDED_openfl_gl_GLProgram
#include <openfl/gl/GLProgram.h>
#endif
namespace com{
namespace engine{
namespace game{

Void Game_obj::__construct()
{
HX_STACK_PUSH("Game::new","com/engine/game/Game.hx",44);
{
	HX_STACK_LINE(62)
	this->rescale = false;
	HX_STACK_LINE(61)
	this->gameHeight = (int)0;
	HX_STACK_LINE(60)
	this->gameWidth = (int)0;
	HX_STACK_LINE(59)
	this->screenHeight = (int)0;
	HX_STACK_LINE(58)
	this->screenWidth = (int)0;
	HX_STACK_LINE(52)
	this->screen = null();
	HX_STACK_LINE(81)
	super::__construct();
	HX_STACK_LINE(82)
	this->ready = false;
	HX_STACK_LINE(83)
	this->render = this->renderView_dyn();
	HX_STACK_LINE(84)
	this->viewPort = ::flash::geom::Rectangle_obj::__new((int)0,(int)0,::flash::Lib_obj::get_current()->get_stage()->get_stageWidth(),::flash::Lib_obj::get_current()->get_stage()->get_stageHeight());
	HX_STACK_LINE(86)
	this->screenWidth = ::flash::Lib_obj::get_current()->get_stage()->get_stageWidth();
	HX_STACK_LINE(87)
	this->screenHeight = ::flash::Lib_obj::get_current()->get_stage()->get_stageHeight();
	HX_STACK_LINE(88)
	::com::engine::game::Game_obj::viewWidth = this->screenHeight;
	HX_STACK_LINE(89)
	::com::engine::game::Game_obj::viewHeight = this->screenHeight;
	HX_STACK_LINE(90)
	this->gameWidth = this->screenWidth;
	HX_STACK_LINE(91)
	this->gameHeight = this->screenHeight;
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ::com::engine::game::Game_obj *__this){
			HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",95);
			{
				HX_STACK_LINE(95)
				Float right = __this->gameWidth;		HX_STACK_VAR(right,"right");
				Float bottom = __this->gameHeight;		HX_STACK_VAR(bottom,"bottom");
				struct _Function_2_1{
					inline static ::com::engine::math::Matrix Block( ){
						HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",95);
						{
							HX_STACK_LINE(95)
							::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
							HX_STACK_LINE(95)
							result->m[(int)0] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)1] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)2] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)3] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)4] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)5] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)6] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)7] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)8] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)9] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)10] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)11] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)12] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)13] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)14] = (int)0;
							HX_STACK_LINE(95)
							result->m[(int)15] = (int)0;
							HX_STACK_LINE(95)
							return result;
						}
						return null();
					}
				};
				HX_STACK_LINE(95)
				::com::engine::math::Matrix matrix = _Function_2_1::Block();		HX_STACK_VAR(matrix,"matrix");
				HX_STACK_LINE(95)
				{
					HX_STACK_LINE(95)
					matrix->m[(int)0] = (Float(2.0) / Float(right));
					HX_STACK_LINE(95)
					matrix->m[(int)1] = matrix->m[(int)2] = matrix->m[(int)3] = matrix->m[(int)4] = (int)0;
					HX_STACK_LINE(95)
					matrix->m[(int)5] = (Float(2.0) / Float((((int)0 - bottom))));
					HX_STACK_LINE(95)
					matrix->m[(int)6] = matrix->m[(int)7] = (int)0;
					HX_STACK_LINE(95)
					matrix->m[(int)8] = matrix->m[(int)9] = (int)0;
					HX_STACK_LINE(95)
					matrix->m[(int)10] = 0.5;
					HX_STACK_LINE(95)
					matrix->m[(int)11] = (int)0;
					HX_STACK_LINE(95)
					matrix->m[(int)12] = (Float(right) / Float((((int)0 - right))));
					HX_STACK_LINE(95)
					matrix->m[(int)13] = (Float(bottom) / Float(bottom));
					HX_STACK_LINE(95)
					matrix->m[(int)14] = 0.5;
					HX_STACK_LINE(95)
					matrix->m[(int)15] = 1.0;
					HX_STACK_LINE(95)
					matrix;
				}
				HX_STACK_LINE(95)
				return matrix;
			}
			return null();
		}
	};
	HX_STACK_LINE(95)
	::com::engine::game::Game_obj::projMatrix = _Function_1_1::Block(this);
	struct _Function_1_2{
		inline static ::com::engine::math::Matrix Block( ){
			HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",96);
			{
				HX_STACK_LINE(96)
				::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
				HX_STACK_LINE(96)
				result->m[(int)0] = 1.0;
				HX_STACK_LINE(96)
				result->m[(int)1] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)2] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)3] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)4] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)5] = 1.0;
				HX_STACK_LINE(96)
				result->m[(int)6] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)7] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)8] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)9] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)10] = 1.0;
				HX_STACK_LINE(96)
				result->m[(int)11] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)12] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)13] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)14] = (int)0;
				HX_STACK_LINE(96)
				result->m[(int)15] = 1.0;
				HX_STACK_LINE(96)
				return result;
			}
			return null();
		}
	};
	HX_STACK_LINE(96)
	::com::engine::game::Game_obj::viewMatrix = _Function_1_2::Block();
	HX_STACK_LINE(99)
	this->get_stage()->addEventListener(::flash::events::Event_obj::RESIZE,this->onResize_dyn(),null(),null(),null());
	HX_STACK_LINE(100)
	this->get_stage()->addEventListener(::flash::events::Event_obj::ADDED,this->focusGained_dyn(),null(),null(),null());
	HX_STACK_LINE(101)
	this->get_stage()->addEventListener(::flash::events::Event_obj::DEACTIVATE,this->focusLost_dyn(),null(),null(),null());
	HX_STACK_LINE(104)
	this->container = ::flash::display::Sprite_obj::__new();
	HX_STACK_LINE(105)
	this->container->addEventListener(::flash::events::Event_obj::ADDED_TO_STAGE,this->addedToStage_dyn(),null(),null(),null());
	HX_STACK_LINE(106)
	this->get_stage()->addChild(this->container);
	HX_STACK_LINE(107)
	this->addChild(::openfl::display::FPS_obj::__new((int)10,(int)10,(int)1044735));
	HX_STACK_LINE(108)
	this->prevFrame = ::flash::Lib_obj::getTimer();
	HX_STACK_LINE(114)
	::openfl::gl::GL_obj::disable((int)2884);
	HX_STACK_LINE(115)
	::openfl::gl::GL_obj::enable((int)2929);
	HX_STACK_LINE(116)
	::openfl::gl::GL_obj::depthFunc((int)515);
}
;
	return null();
}

Game_obj::~Game_obj() { }

Dynamic Game_obj::__CreateEmpty() { return  new Game_obj; }
hx::ObjectPtr< Game_obj > Game_obj::__new()
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Dynamic Game_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Game_obj > result = new Game_obj();
	result->__construct();
	return result;}

Void Game_obj::renderView( ::flash::geom::Rectangle rect){
{
		HX_STACK_PUSH("Game::renderView","com/engine/game/Game.hx",266);
		HX_STACK_THIS(this);
		HX_STACK_ARG(rect,"rect");
		HX_STACK_LINE(267)
		::com::engine::game::Game_obj::viewWidth = rect->width;
		HX_STACK_LINE(268)
		::com::engine::game::Game_obj::viewHeight = rect->height;
		HX_STACK_LINE(270)
		if (((this->rescale == true))){
			HX_STACK_LINE(272)
			Float ar_origin = (Float(this->gameWidth) / Float(this->gameHeight));		HX_STACK_VAR(ar_origin,"ar_origin");
			HX_STACK_LINE(273)
			Float ar_new = (Float(this->screenWidth) / Float(this->screenHeight));		HX_STACK_VAR(ar_new,"ar_new");
			HX_STACK_LINE(275)
			Float scale_w = (Float(this->screenWidth) / Float(this->gameWidth));		HX_STACK_VAR(scale_w,"scale_w");
			HX_STACK_LINE(276)
			Float scale_h = (Float(this->screenHeight) / Float(this->gameHeight));		HX_STACK_VAR(scale_h,"scale_h");
			HX_STACK_LINE(277)
			if (((ar_new > ar_origin))){
				HX_STACK_LINE(278)
				scale_w = scale_h;
			}
			else{
				HX_STACK_LINE(280)
				scale_h = scale_w;
			}
			HX_STACK_LINE(284)
			Float margin_x = (Float(((this->screenWidth - (this->gameWidth * scale_w)))) / Float((int)2));		HX_STACK_VAR(margin_x,"margin_x");
			HX_STACK_LINE(285)
			Float margin_y = (Float(((this->screenHeight - (this->gameHeight * scale_h)))) / Float((int)2));		HX_STACK_VAR(margin_y,"margin_y");
			HX_STACK_LINE(287)
			::openfl::gl::GL_obj::viewport(::Std_obj::_int(margin_x),::Std_obj::_int(margin_y),::Std_obj::_int((this->gameWidth * scale_w)),::Std_obj::_int((this->gameHeight * scale_h)));
			struct _Function_2_1{
				inline static ::com::engine::math::Matrix Block( ::com::engine::game::Game_obj *__this,Float &ar_origin){
					HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",288);
					{
						HX_STACK_LINE(288)
						Float right = (Float(__this->gameWidth) / Float(ar_origin));		HX_STACK_VAR(right,"right");
						Float bottom = (Float(__this->gameHeight) / Float(ar_origin));		HX_STACK_VAR(bottom,"bottom");
						struct _Function_3_1{
							inline static ::com::engine::math::Matrix Block( ){
								HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",288);
								{
									HX_STACK_LINE(288)
									::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
									HX_STACK_LINE(288)
									result->m[(int)0] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)1] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)2] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)3] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)4] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)5] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)6] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)7] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)8] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)9] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)10] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)11] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)12] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)13] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)14] = (int)0;
									HX_STACK_LINE(288)
									result->m[(int)15] = (int)0;
									HX_STACK_LINE(288)
									return result;
								}
								return null();
							}
						};
						HX_STACK_LINE(288)
						::com::engine::math::Matrix matrix = _Function_3_1::Block();		HX_STACK_VAR(matrix,"matrix");
						HX_STACK_LINE(288)
						{
							HX_STACK_LINE(288)
							matrix->m[(int)0] = (Float(2.0) / Float(right));
							HX_STACK_LINE(288)
							matrix->m[(int)1] = matrix->m[(int)2] = matrix->m[(int)3] = matrix->m[(int)4] = (int)0;
							HX_STACK_LINE(288)
							matrix->m[(int)5] = (Float(2.0) / Float((((int)0 - bottom))));
							HX_STACK_LINE(288)
							matrix->m[(int)6] = matrix->m[(int)7] = (int)0;
							HX_STACK_LINE(288)
							matrix->m[(int)8] = matrix->m[(int)9] = (int)0;
							HX_STACK_LINE(288)
							matrix->m[(int)10] = 0.0005;
							HX_STACK_LINE(288)
							matrix->m[(int)11] = (int)0;
							HX_STACK_LINE(288)
							matrix->m[(int)12] = (Float(right) / Float((((int)0 - right))));
							HX_STACK_LINE(288)
							matrix->m[(int)13] = (Float(bottom) / Float(bottom));
							HX_STACK_LINE(288)
							matrix->m[(int)14] = 0.5;
							HX_STACK_LINE(288)
							matrix->m[(int)15] = 1.0;
							HX_STACK_LINE(288)
							matrix;
						}
						HX_STACK_LINE(288)
						return matrix;
					}
					return null();
				}
			};
			HX_STACK_LINE(288)
			::com::engine::game::Game_obj::projMatrix = _Function_2_1::Block(this,ar_origin);
		}
		else{
			HX_STACK_LINE(291)
			::openfl::gl::GL_obj::viewport(::Std_obj::_int(rect->x),::Std_obj::_int(rect->y),::Std_obj::_int(rect->width),::Std_obj::_int(rect->height));
			struct _Function_2_1{
				inline static ::com::engine::math::Matrix Block( ::com::engine::game::Game_obj *__this){
					HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",293);
					{
						HX_STACK_LINE(293)
						Float right = __this->gameWidth;		HX_STACK_VAR(right,"right");
						Float bottom = __this->gameHeight;		HX_STACK_VAR(bottom,"bottom");
						struct _Function_3_1{
							inline static ::com::engine::math::Matrix Block( ){
								HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",293);
								{
									HX_STACK_LINE(293)
									::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
									HX_STACK_LINE(293)
									result->m[(int)0] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)1] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)2] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)3] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)4] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)5] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)6] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)7] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)8] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)9] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)10] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)11] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)12] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)13] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)14] = (int)0;
									HX_STACK_LINE(293)
									result->m[(int)15] = (int)0;
									HX_STACK_LINE(293)
									return result;
								}
								return null();
							}
						};
						HX_STACK_LINE(293)
						::com::engine::math::Matrix matrix = _Function_3_1::Block();		HX_STACK_VAR(matrix,"matrix");
						HX_STACK_LINE(293)
						{
							HX_STACK_LINE(293)
							matrix->m[(int)0] = (Float(2.0) / Float(right));
							HX_STACK_LINE(293)
							matrix->m[(int)1] = matrix->m[(int)2] = matrix->m[(int)3] = matrix->m[(int)4] = (int)0;
							HX_STACK_LINE(293)
							matrix->m[(int)5] = (Float(2.0) / Float((((int)0 - bottom))));
							HX_STACK_LINE(293)
							matrix->m[(int)6] = matrix->m[(int)7] = (int)0;
							HX_STACK_LINE(293)
							matrix->m[(int)8] = matrix->m[(int)9] = (int)0;
							HX_STACK_LINE(293)
							matrix->m[(int)10] = 0.5;
							HX_STACK_LINE(293)
							matrix->m[(int)11] = (int)0;
							HX_STACK_LINE(293)
							matrix->m[(int)12] = (Float(right) / Float((((int)0 - right))));
							HX_STACK_LINE(293)
							matrix->m[(int)13] = (Float(bottom) / Float(bottom));
							HX_STACK_LINE(293)
							matrix->m[(int)14] = 0.5;
							HX_STACK_LINE(293)
							matrix->m[(int)15] = 1.0;
							HX_STACK_LINE(293)
							matrix;
						}
						HX_STACK_LINE(293)
						return matrix;
					}
					return null();
				}
			};
			HX_STACK_LINE(293)
			::com::engine::game::Game_obj::projMatrix = _Function_2_1::Block(this);
		}
		struct _Function_1_1{
			inline static ::com::engine::math::Matrix Block( ){
				HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",296);
				{
					HX_STACK_LINE(296)
					Float theta = (Float(((int)0 * ::Math_obj::PI)) / Float(180.0));		HX_STACK_VAR(theta,"theta");
					HX_STACK_LINE(296)
					Float c = ::Math_obj::cos(theta);		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(296)
					Float s = ::Math_obj::sin(theta);		HX_STACK_VAR(s,"s");
					struct _Function_2_1{
						inline static ::com::engine::math::Matrix Block( Float &c,Float &s){
							HX_STACK_PUSH("*::closure","com/engine/game/Game.hx",296);
							{
								HX_STACK_LINE(296)
								Array< Float > array = Array_obj< Float >::__new().Add(c).Add(-(s)).Add((int)0).Add((int)0).Add(s).Add(c).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1);		HX_STACK_VAR(array,"array");
								int offset = (int)0;		HX_STACK_VAR(offset,"offset");
								HX_STACK_LINE(296)
								::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
								HX_STACK_LINE(296)
								{
									HX_STACK_LINE(296)
									{
										HX_STACK_LINE(296)
										int _g = (int)0;		HX_STACK_VAR(_g,"_g");
										HX_STACK_LINE(296)
										while(((_g < (int)16))){
											HX_STACK_LINE(296)
											int index = (_g)++;		HX_STACK_VAR(index,"index");
											HX_STACK_LINE(296)
											result->m[index] = array->__get((index + offset));
										}
									}
									HX_STACK_LINE(296)
									result;
								}
								HX_STACK_LINE(296)
								return result;
							}
							return null();
						}
					};
					HX_STACK_LINE(296)
					return _Function_2_1::Block(c,s);
				}
				return null();
			}
		};
		HX_STACK_LINE(296)
		::com::engine::game::Game_obj::viewMatrix = _Function_1_1::Block();
		HX_STACK_LINE(301)
		this->nextFrame = ::flash::Lib_obj::getTimer();
		HX_STACK_LINE(302)
		this->deltaTime = (((this->nextFrame - this->prevFrame)) * 0.001);
		HX_STACK_LINE(303)
		::openfl::gl::GL_obj::clearColor((int)1,(int)0,(int)1,(int)1);
		HX_STACK_LINE(304)
		::openfl::gl::GL_obj::clearDepth((int)1);
		HX_STACK_LINE(306)
		::openfl::gl::GL_obj::clear((int)16640);
		HX_STACK_LINE(310)
		if ((this->ready)){
			HX_STACK_LINE(311)
			this->update(this->deltaTime);
		}
		HX_STACK_LINE(314)
		::openfl::gl::GL_obj::bindBuffer((int)34962,null());
		HX_STACK_LINE(315)
		::openfl::gl::GL_obj::useProgram(null());
		HX_STACK_LINE(316)
		::openfl::gl::GL_obj::blendFunc((int)770,(int)772);
		HX_STACK_LINE(317)
		this->prevFrame = this->nextFrame;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,renderView,(void))

Void Game_obj::setScreen( ::com::engine::game::Screen screen){
{
		HX_STACK_PUSH("Game::setScreen","com/engine/game/Game.hx",253);
		HX_STACK_THIS(this);
		HX_STACK_ARG(screen,"screen");
		HX_STACK_LINE(254)
		if (((this->screen != null()))){
			HX_STACK_LINE(254)
			this->screen->dispose();
		}
		HX_STACK_LINE(255)
		this->screen = screen;
		HX_STACK_LINE(256)
		this->screen->game = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(257)
		if (((this->screen != null()))){
			HX_STACK_LINE(259)
			this->screen->show();
			HX_STACK_LINE(260)
			this->screen->resize(::Std_obj::_int(::com::engine::game::Game_obj::viewWidth),::Std_obj::_int(::com::engine::game::Game_obj::viewHeight));
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,setScreen,(void))

Void Game_obj::mouseDown( Float mousex,Float mousey){
{
		HX_STACK_PUSH("Game::mouseDown","com/engine/game/Game.hx",250);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Game_obj,mouseDown,(void))

Void Game_obj::mouseUp( Float mousex,Float mousey){
{
		HX_STACK_PUSH("Game::mouseUp","com/engine/game/Game.hx",249);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Game_obj,mouseUp,(void))

Void Game_obj::mouseMove( Float mousex,Float mousey){
{
		HX_STACK_PUSH("Game::mouseMove","com/engine/game/Game.hx",248);
		HX_STACK_THIS(this);
		HX_STACK_ARG(mousex,"mousex");
		HX_STACK_ARG(mousey,"mousey");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Game_obj,mouseMove,(void))

Void Game_obj::keyUp( int key){
{
		HX_STACK_PUSH("Game::keyUp","com/engine/game/Game.hx",246);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,keyUp,(void))

Void Game_obj::keyDown( int key){
{
		HX_STACK_PUSH("Game::keyDown","com/engine/game/Game.hx",245);
		HX_STACK_THIS(this);
		HX_STACK_ARG(key,"key");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,keyDown,(void))

Void Game_obj::update( Float dt){
{
		HX_STACK_PUSH("Game::update","com/engine/game/Game.hx",242);
		HX_STACK_THIS(this);
		HX_STACK_ARG(dt,"dt");
		HX_STACK_LINE(242)
		if (((this->screen != null()))){
			HX_STACK_LINE(243)
			this->screen->render(dt);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,update,(void))

Void Game_obj::resize( int width,int height){
{
		HX_STACK_PUSH("Game::resize","com/engine/game/Game.hx",237);
		HX_STACK_THIS(this);
		HX_STACK_ARG(width,"width");
		HX_STACK_ARG(height,"height");
		HX_STACK_LINE(237)
		if (((this->screen != null()))){
			HX_STACK_LINE(239)
			this->screen->resize(width,height);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Game_obj,resize,(void))

Void Game_obj::end( ){
{
		HX_STACK_PUSH("Game::end","com/engine/game/Game.hx",235);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Game_obj,end,(void))

Void Game_obj::begin( ){
{
		HX_STACK_PUSH("Game::begin","com/engine/game/Game.hx",234);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Game_obj,begin,(void))

Void Game_obj::onResize( ::flash::events::Event e){
{
		HX_STACK_PUSH("Game::onResize","com/engine/game/Game.hx",227);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(228)
		this->screenWidth = ::flash::Lib_obj::get_current()->get_stage()->get_stageWidth();
		HX_STACK_LINE(229)
		this->screenHeight = ::flash::Lib_obj::get_current()->get_stage()->get_stageHeight();
		HX_STACK_LINE(231)
		this->resize(this->screenWidth,this->screenHeight);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,onResize,(void))

Void Game_obj::focusLost( ::flash::events::Event e){
{
		HX_STACK_PUSH("Game::focusLost","com/engine/game/Game.hx",225);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(225)
		::haxe::Log_obj::trace(HX_CSTRING("end game"),hx::SourceInfo(HX_CSTRING("Game.hx"),225,HX_CSTRING("com.engine.game.Game"),HX_CSTRING("focusLost")));
		HX_STACK_LINE(225)
		this->ready = false;
		HX_STACK_LINE(225)
		this->end();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,focusLost,(void))

Void Game_obj::doTouchMove( ::flash::events::TouchEvent event){
{
		HX_STACK_PUSH("Game::doTouchMove","com/engine/game/Game.hx",220);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,doTouchMove,(void))

Void Game_obj::doTouchUp( ::flash::events::TouchEvent event){
{
		HX_STACK_PUSH("Game::doTouchUp","com/engine/game/Game.hx",216);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,doTouchUp,(void))

Void Game_obj::doTouchDown( ::flash::events::TouchEvent event){
{
		HX_STACK_PUSH("Game::doTouchDown","com/engine/game/Game.hx",212);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,doTouchDown,(void))

Void Game_obj::doMouseMove( ::flash::events::MouseEvent event){
{
		HX_STACK_PUSH("Game::doMouseMove","com/engine/game/Game.hx",205);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(206)
		this->mouseMove(event->localX,event->localY);
		HX_STACK_LINE(207)
		if (((this->screen != null()))){
			HX_STACK_LINE(207)
			this->screen->mouseMove(event->localX,event->localY);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,doMouseMove,(void))

Void Game_obj::doMouseUp( ::flash::events::MouseEvent event){
{
		HX_STACK_PUSH("Game::doMouseUp","com/engine/game/Game.hx",200);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(201)
		this->mouseUp(event->localX,event->localY);
		HX_STACK_LINE(202)
		if (((this->screen != null()))){
			HX_STACK_LINE(202)
			this->screen->mouseUp(event->localX,event->localY);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,doMouseUp,(void))

Void Game_obj::doMouseDown( ::flash::events::MouseEvent event){
{
		HX_STACK_PUSH("Game::doMouseDown","com/engine/game/Game.hx",195);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(196)
		this->mouseDown(event->localX,event->localY);
		HX_STACK_LINE(197)
		if (((this->screen != null()))){
			HX_STACK_LINE(197)
			this->screen->mouseDown(event->localX,event->localY);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,doMouseDown,(void))

Void Game_obj::stage_onKeyUp( ::flash::events::KeyboardEvent event){
{
		HX_STACK_PUSH("Game::stage_onKeyUp","com/engine/game/Game.hx",188);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(190)
		this->keyUp(event->keyCode);
		HX_STACK_LINE(191)
		if (((this->screen != null()))){
			HX_STACK_LINE(191)
			this->screen->keyUp(event->keyCode);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,stage_onKeyUp,(void))

Void Game_obj::stage_onKeyDown( ::flash::events::KeyboardEvent event){
{
		HX_STACK_PUSH("Game::stage_onKeyDown","com/engine/game/Game.hx",180);
		HX_STACK_THIS(this);
		HX_STACK_ARG(event,"event");
		HX_STACK_LINE(182)
		this->keyDown(event->keyCode);
		HX_STACK_LINE(183)
		if (((this->screen != null()))){
			HX_STACK_LINE(183)
			this->screen->keyDown(event->keyCode);
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,stage_onKeyDown,(void))

Void Game_obj::focusGained( ::flash::events::Event e){
{
		HX_STACK_PUSH("Game::focusGained","com/engine/game/Game.hx",172);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,focusGained,(void))

Void Game_obj::addedToStage( ::flash::events::Event e){
{
		HX_STACK_PUSH("Game::addedToStage","com/engine/game/Game.hx",134);
		HX_STACK_THIS(this);
		HX_STACK_ARG(e,"e");
		HX_STACK_LINE(136)
		this->mMultiTouch = ::flash::ui::Multitouch_obj::get_supportsTouchEvents();
		HX_STACK_LINE(137)
		if ((this->mMultiTouch)){
			HX_STACK_LINE(137)
			::flash::ui::Multitouch_obj::set_inputMode(::flash::ui::MultitouchInputMode_obj::TOUCH_POINT);
		}
		HX_STACK_LINE(142)
		::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_DOWN,this->doMouseDown_dyn(),null(),null(),null());
		HX_STACK_LINE(143)
		::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_MOVE,this->doMouseMove_dyn(),null(),null(),null());
		HX_STACK_LINE(144)
		::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::MouseEvent_obj::MOUSE_UP,this->doMouseUp_dyn(),null(),null(),null());
		HX_STACK_LINE(145)
		::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_DOWN,this->stage_onKeyDown_dyn(),null(),null(),null());
		HX_STACK_LINE(146)
		::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::KeyboardEvent_obj::KEY_UP,this->stage_onKeyUp_dyn(),null(),null(),null());
		HX_STACK_LINE(149)
		if ((this->mMultiTouch)){
			HX_STACK_LINE(151)
			::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::TouchEvent_obj::TOUCH_BEGIN,this->doTouchDown_dyn(),null(),null(),null());
			HX_STACK_LINE(152)
			::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::TouchEvent_obj::TOUCH_MOVE,this->doTouchMove_dyn(),null(),null(),null());
			HX_STACK_LINE(153)
			::flash::Lib_obj::get_current()->get_stage()->addEventListener(::flash::events::TouchEvent_obj::TOUCH_END,this->doTouchUp_dyn(),null(),null(),null());
		}
		HX_STACK_LINE(156)
		::openfl::gl::GL_obj::disable((int)2929);
		HX_STACK_LINE(157)
		::openfl::gl::GL_obj::disable((int)2884);
		HX_STACK_LINE(158)
		::openfl::gl::GL_obj::enable((int)3042);
		HX_STACK_LINE(159)
		::openfl::gl::GL_obj::pixelStorei((int)3333,(int)2);
		HX_STACK_LINE(160)
		::openfl::gl::GL_obj::depthMask(true);
		HX_STACK_LINE(167)
		this->begin();
		HX_STACK_LINE(168)
		this->ready = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,addedToStage,(void))

Void Game_obj::addChild( ::flash::display::DisplayObject child){
{
		HX_STACK_PUSH("Game::addChild","com/engine/game/Game.hx",129);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(129)
		this->container->addChild(child);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,addChild,(void))

Void Game_obj::removeChild( ::flash::display::DisplayObject child){
{
		HX_STACK_PUSH("Game::removeChild","com/engine/game/Game.hx",124);
		HX_STACK_THIS(this);
		HX_STACK_ARG(child,"child");
		HX_STACK_LINE(124)
		this->container->removeChild(child);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Game_obj,removeChild,(void))

Void Game_obj::fixRatio( int w,int h){
{
		HX_STACK_PUSH("Game::fixRatio","com/engine/game/Game.hx",73);
		HX_STACK_THIS(this);
		HX_STACK_ARG(w,"w");
		HX_STACK_ARG(h,"h");
		HX_STACK_LINE(74)
		this->rescale = true;
		HX_STACK_LINE(75)
		this->gameWidth = w;
		HX_STACK_LINE(76)
		this->gameHeight = h;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(Game_obj,fixRatio,(void))

Float Game_obj::scrollX;

Float Game_obj::scrollY;

Float Game_obj::viewWidth;

Float Game_obj::viewHeight;

::com::engine::math::Matrix Game_obj::projMatrix;

::com::engine::math::Matrix Game_obj::viewMatrix;


Game_obj::Game_obj()
{
}

void Game_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Game);
	HX_MARK_MEMBER_NAME(rescale,"rescale");
	HX_MARK_MEMBER_NAME(gameHeight,"gameHeight");
	HX_MARK_MEMBER_NAME(gameWidth,"gameWidth");
	HX_MARK_MEMBER_NAME(screenHeight,"screenHeight");
	HX_MARK_MEMBER_NAME(screenWidth,"screenWidth");
	HX_MARK_MEMBER_NAME(container,"container");
	HX_MARK_MEMBER_NAME(screen,"screen");
	HX_MARK_MEMBER_NAME(mMultiTouch,"mMultiTouch");
	HX_MARK_MEMBER_NAME(nextFrame,"nextFrame");
	HX_MARK_MEMBER_NAME(prevFrame,"prevFrame");
	HX_MARK_MEMBER_NAME(deltaTime,"deltaTime");
	HX_MARK_MEMBER_NAME(ready,"ready");
	HX_MARK_MEMBER_NAME(viewPort,"viewPort");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void Game_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rescale,"rescale");
	HX_VISIT_MEMBER_NAME(gameHeight,"gameHeight");
	HX_VISIT_MEMBER_NAME(gameWidth,"gameWidth");
	HX_VISIT_MEMBER_NAME(screenHeight,"screenHeight");
	HX_VISIT_MEMBER_NAME(screenWidth,"screenWidth");
	HX_VISIT_MEMBER_NAME(container,"container");
	HX_VISIT_MEMBER_NAME(screen,"screen");
	HX_VISIT_MEMBER_NAME(mMultiTouch,"mMultiTouch");
	HX_VISIT_MEMBER_NAME(nextFrame,"nextFrame");
	HX_VISIT_MEMBER_NAME(prevFrame,"prevFrame");
	HX_VISIT_MEMBER_NAME(deltaTime,"deltaTime");
	HX_VISIT_MEMBER_NAME(ready,"ready");
	HX_VISIT_MEMBER_NAME(viewPort,"viewPort");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic Game_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"end") ) { return end_dyn(); }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"keyUp") ) { return keyUp_dyn(); }
		if (HX_FIELD_EQ(inName,"begin") ) { return begin_dyn(); }
		if (HX_FIELD_EQ(inName,"ready") ) { return ready; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		if (HX_FIELD_EQ(inName,"resize") ) { return resize_dyn(); }
		if (HX_FIELD_EQ(inName,"screen") ) { return screen; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollX") ) { return scrollX; }
		if (HX_FIELD_EQ(inName,"scrollY") ) { return scrollY; }
		if (HX_FIELD_EQ(inName,"mouseUp") ) { return mouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"keyDown") ) { return keyDown_dyn(); }
		if (HX_FIELD_EQ(inName,"rescale") ) { return rescale; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"onResize") ) { return onResize_dyn(); }
		if (HX_FIELD_EQ(inName,"addChild") ) { return addChild_dyn(); }
		if (HX_FIELD_EQ(inName,"fixRatio") ) { return fixRatio_dyn(); }
		if (HX_FIELD_EQ(inName,"viewPort") ) { return viewPort; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"viewWidth") ) { return viewWidth; }
		if (HX_FIELD_EQ(inName,"setScreen") ) { return setScreen_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseDown") ) { return mouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"mouseMove") ) { return mouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"focusLost") ) { return focusLost_dyn(); }
		if (HX_FIELD_EQ(inName,"doTouchUp") ) { return doTouchUp_dyn(); }
		if (HX_FIELD_EQ(inName,"doMouseUp") ) { return doMouseUp_dyn(); }
		if (HX_FIELD_EQ(inName,"gameWidth") ) { return gameWidth; }
		if (HX_FIELD_EQ(inName,"container") ) { return container; }
		if (HX_FIELD_EQ(inName,"nextFrame") ) { return nextFrame; }
		if (HX_FIELD_EQ(inName,"prevFrame") ) { return prevFrame; }
		if (HX_FIELD_EQ(inName,"deltaTime") ) { return deltaTime; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"viewHeight") ) { return viewHeight; }
		if (HX_FIELD_EQ(inName,"projMatrix") ) { return projMatrix; }
		if (HX_FIELD_EQ(inName,"viewMatrix") ) { return viewMatrix; }
		if (HX_FIELD_EQ(inName,"renderView") ) { return renderView_dyn(); }
		if (HX_FIELD_EQ(inName,"gameHeight") ) { return gameHeight; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"doTouchMove") ) { return doTouchMove_dyn(); }
		if (HX_FIELD_EQ(inName,"doTouchDown") ) { return doTouchDown_dyn(); }
		if (HX_FIELD_EQ(inName,"doMouseMove") ) { return doMouseMove_dyn(); }
		if (HX_FIELD_EQ(inName,"doMouseDown") ) { return doMouseDown_dyn(); }
		if (HX_FIELD_EQ(inName,"focusGained") ) { return focusGained_dyn(); }
		if (HX_FIELD_EQ(inName,"removeChild") ) { return removeChild_dyn(); }
		if (HX_FIELD_EQ(inName,"screenWidth") ) { return screenWidth; }
		if (HX_FIELD_EQ(inName,"mMultiTouch") ) { return mMultiTouch; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"addedToStage") ) { return addedToStage_dyn(); }
		if (HX_FIELD_EQ(inName,"screenHeight") ) { return screenHeight; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"stage_onKeyUp") ) { return stage_onKeyUp_dyn(); }
		break;
	case 15:
		if (HX_FIELD_EQ(inName,"stage_onKeyDown") ) { return stage_onKeyDown_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Game_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"ready") ) { ready=inValue.Cast< bool >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"screen") ) { screen=inValue.Cast< ::com::engine::game::Screen >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"scrollX") ) { scrollX=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"scrollY") ) { scrollY=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"rescale") ) { rescale=inValue.Cast< bool >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"viewPort") ) { viewPort=inValue.Cast< ::flash::geom::Rectangle >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"viewWidth") ) { viewWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameWidth") ) { gameWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"container") ) { container=inValue.Cast< ::flash::display::Sprite >(); return inValue; }
		if (HX_FIELD_EQ(inName,"nextFrame") ) { nextFrame=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"prevFrame") ) { prevFrame=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"deltaTime") ) { deltaTime=inValue.Cast< Float >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"viewHeight") ) { viewHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"projMatrix") ) { projMatrix=inValue.Cast< ::com::engine::math::Matrix >(); return inValue; }
		if (HX_FIELD_EQ(inName,"viewMatrix") ) { viewMatrix=inValue.Cast< ::com::engine::math::Matrix >(); return inValue; }
		if (HX_FIELD_EQ(inName,"gameHeight") ) { gameHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"screenWidth") ) { screenWidth=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"mMultiTouch") ) { mMultiTouch=inValue.Cast< bool >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"screenHeight") ) { screenHeight=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Game_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rescale"));
	outFields->push(HX_CSTRING("gameHeight"));
	outFields->push(HX_CSTRING("gameWidth"));
	outFields->push(HX_CSTRING("screenHeight"));
	outFields->push(HX_CSTRING("screenWidth"));
	outFields->push(HX_CSTRING("container"));
	outFields->push(HX_CSTRING("screen"));
	outFields->push(HX_CSTRING("mMultiTouch"));
	outFields->push(HX_CSTRING("nextFrame"));
	outFields->push(HX_CSTRING("prevFrame"));
	outFields->push(HX_CSTRING("deltaTime"));
	outFields->push(HX_CSTRING("ready"));
	outFields->push(HX_CSTRING("viewPort"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	HX_CSTRING("scrollX"),
	HX_CSTRING("scrollY"),
	HX_CSTRING("viewWidth"),
	HX_CSTRING("viewHeight"),
	HX_CSTRING("projMatrix"),
	HX_CSTRING("viewMatrix"),
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("renderView"),
	HX_CSTRING("setScreen"),
	HX_CSTRING("mouseDown"),
	HX_CSTRING("mouseUp"),
	HX_CSTRING("mouseMove"),
	HX_CSTRING("keyUp"),
	HX_CSTRING("keyDown"),
	HX_CSTRING("update"),
	HX_CSTRING("resize"),
	HX_CSTRING("end"),
	HX_CSTRING("begin"),
	HX_CSTRING("onResize"),
	HX_CSTRING("focusLost"),
	HX_CSTRING("doTouchMove"),
	HX_CSTRING("doTouchUp"),
	HX_CSTRING("doTouchDown"),
	HX_CSTRING("doMouseMove"),
	HX_CSTRING("doMouseUp"),
	HX_CSTRING("doMouseDown"),
	HX_CSTRING("stage_onKeyUp"),
	HX_CSTRING("stage_onKeyDown"),
	HX_CSTRING("focusGained"),
	HX_CSTRING("addedToStage"),
	HX_CSTRING("addChild"),
	HX_CSTRING("removeChild"),
	HX_CSTRING("fixRatio"),
	HX_CSTRING("rescale"),
	HX_CSTRING("gameHeight"),
	HX_CSTRING("gameWidth"),
	HX_CSTRING("screenHeight"),
	HX_CSTRING("screenWidth"),
	HX_CSTRING("container"),
	HX_CSTRING("screen"),
	HX_CSTRING("mMultiTouch"),
	HX_CSTRING("nextFrame"),
	HX_CSTRING("prevFrame"),
	HX_CSTRING("deltaTime"),
	HX_CSTRING("ready"),
	HX_CSTRING("viewPort"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Game_obj::__mClass,"__mClass");
	HX_MARK_MEMBER_NAME(Game_obj::scrollX,"scrollX");
	HX_MARK_MEMBER_NAME(Game_obj::scrollY,"scrollY");
	HX_MARK_MEMBER_NAME(Game_obj::viewWidth,"viewWidth");
	HX_MARK_MEMBER_NAME(Game_obj::viewHeight,"viewHeight");
	HX_MARK_MEMBER_NAME(Game_obj::projMatrix,"projMatrix");
	HX_MARK_MEMBER_NAME(Game_obj::viewMatrix,"viewMatrix");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Game_obj::__mClass,"__mClass");
	HX_VISIT_MEMBER_NAME(Game_obj::scrollX,"scrollX");
	HX_VISIT_MEMBER_NAME(Game_obj::scrollY,"scrollY");
	HX_VISIT_MEMBER_NAME(Game_obj::viewWidth,"viewWidth");
	HX_VISIT_MEMBER_NAME(Game_obj::viewHeight,"viewHeight");
	HX_VISIT_MEMBER_NAME(Game_obj::projMatrix,"projMatrix");
	HX_VISIT_MEMBER_NAME(Game_obj::viewMatrix,"viewMatrix");
};

Class Game_obj::__mClass;

void Game_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.game.Game"), hx::TCanCast< Game_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Game_obj::__boot()
{
	scrollX= (int)0;
	scrollY= (int)0;
	viewWidth= (int)0;
	viewHeight= (int)0;
}

} // end namespace com
} // end namespace engine
} // end namespace game
