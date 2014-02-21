#include <hxcpp.h>

#ifndef INCLUDED_IMap
#include <IMap.h>
#endif
#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_XmlType
#include <XmlType.h>
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
#ifndef INCLUDED_com_engine_render_SpriteShader
#include <com/engine/render/SpriteShader.h>
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
#ifndef INCLUDED_flash_events_EventDispatcher
#include <flash/events/EventDispatcher.h>
#endif
#ifndef INCLUDED_flash_events_IEventDispatcher
#include <flash/events/IEventDispatcher.h>
#endif
#ifndef INCLUDED_flash_geom_Point
#include <flash/geom/Point.h>
#endif
#ifndef INCLUDED_haxe_Log
#include <haxe/Log.h>
#endif
#ifndef INCLUDED_haxe_ds_StringMap
#include <haxe/ds/StringMap.h>
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

Void TileMap_obj::__construct(::String xml)
{
HX_STACK_PUSH("TileMap::new","com/engine/render/TileMap.hx",28);
{
	HX_STACK_LINE(59)
	this->invTexHeight = (int)0;
	HX_STACK_LINE(58)
	this->invTexWidth = (int)0;
	HX_STACK_LINE(37)
	this->spacing = (int)0;
	HX_STACK_LINE(36)
	this->margin = (int)0;
	HX_STACK_LINE(69)
	super::__construct();
	HX_STACK_LINE(70)
	::Xml xml1 = ::Xml_obj::parse(xml)->firstElement();		HX_STACK_VAR(xml1,"xml1");
	HX_STACK_LINE(72)
	this->widthInTiles = ::Std_obj::parseInt(xml1->get(HX_CSTRING("width")));
	HX_STACK_LINE(73)
	this->heightInTiles = ::Std_obj::parseInt(xml1->get(HX_CSTRING("height")));
	HX_STACK_LINE(77)
	::haxe::ds::StringMap properties = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(properties,"properties");
	HX_STACK_LINE(79)
	for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(xml1->iterator());  __it->hasNext(); ){
		::Xml child = __it->next();
		if ((this->isValidElement(child))){
			HX_STACK_LINE(83)
			if (((child->get_nodeName() == HX_CSTRING("tileset")))){
				HX_STACK_LINE(86)
				if (((child->get(HX_CSTRING("source")) != null()))){
					HX_STACK_LINE(88)
					this->tilesfromGenericXml(this->getText(child->get(HX_CSTRING("source"))));
				}
				else{
					HX_STACK_LINE(91)
					this->tilesfromGenericXml(child->toString());
				}
			}
			else{
				HX_STACK_LINE(100)
				if (((child->get_nodeName() == HX_CSTRING("properties")))){
					HX_STACK_LINE(101)
					for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(child->iterator());  __it->hasNext(); ){
						::Xml property = __it->next();
						if ((!(this->isValidElement(property)))){
							HX_STACK_LINE(105)
							continue;
						}
;
					}
				}
				else{
					HX_STACK_LINE(110)
					if (((child->get_nodeName() == HX_CSTRING("layer")))){
						HX_STACK_LINE(111)
						this->layerfromGenericXml(child);
					}
					else{
						HX_STACK_LINE(115)
						if (((child->get_nodeName() == HX_CSTRING("objectgroup")))){
							HX_STACK_LINE(116)
							this->objectsfromGenericXml(child);
						}
					}
				}
			}
		}
;
	}
	HX_STACK_LINE(124)
	this->addClips();
	HX_STACK_LINE(126)
	this->capacity = (this->widthInTiles * this->heightInTiles);
	HX_STACK_LINE(129)
	this->vertexStrideSize = (int)36;
	HX_STACK_LINE(131)
	this->numVerts = ((this->capacity * this->vertexStrideSize) * (int)4);
	HX_STACK_LINE(132)
	this->numIndices = (this->capacity * (int)6);
	HX_STACK_LINE(136)
	this->vertices = ::openfl::utils::Float32Array_obj::__new(this->numVerts,null(),null());
	HX_STACK_LINE(142)
	this->indices = ::openfl::utils::Int16Array_obj::__new(this->numIndices,null(),null());
	HX_STACK_LINE(143)
	int length = ::Std_obj::_int((Float(this->indices->length) / Float((int)6)));		HX_STACK_VAR(length,"length");
	HX_STACK_LINE(145)
	{
		HX_STACK_LINE(145)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(145)
		while(((_g < length))){
			HX_STACK_LINE(145)
			int i = (_g)++;		HX_STACK_VAR(i,"i");
			HX_STACK_LINE(147)
			int index2 = (i * (int)6);		HX_STACK_VAR(index2,"index2");
			HX_STACK_LINE(148)
			int index3 = (i * (int)4);		HX_STACK_VAR(index3,"index3");
			HX_STACK_LINE(149)
			hx::__ArrayImplRef(this->indices,index2) = index3;
			HX_STACK_LINE(150)
			hx::__ArrayImplRef(this->indices,(index2 + (int)1)) = (index3 + (int)1);
			HX_STACK_LINE(151)
			hx::__ArrayImplRef(this->indices,(index2 + (int)2)) = (index3 + (int)2);
			HX_STACK_LINE(152)
			hx::__ArrayImplRef(this->indices,(index2 + (int)3)) = index3;
			HX_STACK_LINE(153)
			hx::__ArrayImplRef(this->indices,(index2 + (int)4)) = (index3 + (int)2);
			HX_STACK_LINE(154)
			hx::__ArrayImplRef(this->indices,(index2 + (int)5)) = (index3 + (int)3);
		}
	}
	HX_STACK_LINE(159)
	this->currentBatchSize = (int)0;
	HX_STACK_LINE(160)
	this->currentBlendMode = ::com::engine::render::BlendMode_obj::NORMAL;
	HX_STACK_LINE(161)
	this->invTexWidth = (Float(1.0) / Float(this->image->texWidth));
	HX_STACK_LINE(162)
	this->invTexHeight = (Float(1.0) / Float(this->image->texHeight));
	HX_STACK_LINE(166)
	this->vertexBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(167)
	this->indexBuffer = ::openfl::gl::GL_obj::createBuffer();
	HX_STACK_LINE(171)
	::openfl::gl::GL_obj::bindBuffer((int)34963,this->indexBuffer);
	HX_STACK_LINE(172)
	::openfl::gl::GL_obj::bufferData((int)34963,this->indices,(int)35044);
	HX_STACK_LINE(175)
	::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
	HX_STACK_LINE(176)
	::openfl::gl::GL_obj::bufferData((int)34962,this->vertices,(int)35048);
	HX_STACK_LINE(180)
	this->shader = ::com::engine::render::SpriteShader_obj::__new();
	HX_STACK_LINE(181)
	this->isBuild = false;
}
;
	return null();
}

TileMap_obj::~TileMap_obj() { }

Dynamic TileMap_obj::__CreateEmpty() { return  new TileMap_obj; }
hx::ObjectPtr< TileMap_obj > TileMap_obj::__new(::String xml)
{  hx::ObjectPtr< TileMap_obj > result = new TileMap_obj();
	result->__construct(xml);
	return result;}

Dynamic TileMap_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< TileMap_obj > result = new TileMap_obj();
	result->__construct(inArgs[0]);
	return result;}

Void TileMap_obj::dispose( ){
{
		HX_STACK_PUSH("TileMap::dispose","com/engine/render/TileMap.hx",724);
		HX_STACK_THIS(this);
		HX_STACK_LINE(725)
		::openfl::gl::GL_obj::deleteBuffer(this->indexBuffer);
		HX_STACK_LINE(726)
		::openfl::gl::GL_obj::deleteBuffer(this->vertexBuffer);
		HX_STACK_LINE(727)
		this->super::dispose();
	}
return null();
}


::String TileMap_obj::toCSV( Dynamic width){
	HX_STACK_PUSH("TileMap::toCSV","com/engine/render/TileMap.hx",688);
	HX_STACK_THIS(this);
	HX_STACK_ARG(width,"width");
	HX_STACK_LINE(689)
	if (((bool((width <= (int)0)) || bool((width == null()))))){
		HX_STACK_LINE(690)
		width = this->widthInTiles;
	}
	HX_STACK_LINE(694)
	int counter = (int)0;		HX_STACK_VAR(counter,"counter");
	HX_STACK_LINE(695)
	::String csv = HX_CSTRING("");		HX_STACK_VAR(csv,"csv");
	HX_STACK_LINE(697)
	{
		HX_STACK_LINE(697)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		Array< int > _g1 = this->tilesIDs;		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(697)
		while(((_g < _g1->length))){
			HX_STACK_LINE(697)
			int tile = _g1->__get(_g);		HX_STACK_VAR(tile,"tile");
			HX_STACK_LINE(697)
			++(_g);
			HX_STACK_LINE(699)
			int tileGID = tile;		HX_STACK_VAR(tileGID,"tileGID");
			HX_STACK_LINE(701)
			if (((counter >= width))){
				HX_STACK_LINE(704)
				csv = csv.substr((int)0,(csv.length - (int)1));
				HX_STACK_LINE(707)
				hx::AddEq(csv,HX_CSTRING("\n"));
				HX_STACK_LINE(708)
				counter = (int)0;
			}
			HX_STACK_LINE(711)
			hx::AddEq(csv,tileGID);
			HX_STACK_LINE(712)
			hx::AddEq(csv,HX_CSTRING(","));
			HX_STACK_LINE(714)
			(counter)++;
		}
	}
	HX_STACK_LINE(718)
	csv = csv.substr((int)0,(csv.length - (int)1));
	HX_STACK_LINE(720)
	return csv;
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,toCSV,return )

Void TileMap_obj::layerfromGenericXml( ::Xml xml){
{
		HX_STACK_PUSH("TileMap::layerfromGenericXml","com/engine/render/TileMap.hx",638);
		HX_STACK_THIS(this);
		HX_STACK_ARG(xml,"xml");
		HX_STACK_LINE(639)
		::String name = xml->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
		HX_STACK_LINE(640)
		int width = ::Std_obj::parseInt(xml->get(HX_CSTRING("width")));		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(641)
		int height = ::Std_obj::parseInt(xml->get(HX_CSTRING("height")));		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(642)
		Float opacity = ::Std_obj::parseFloat((  (((xml->get(HX_CSTRING("opacity")) != null()))) ? ::String(xml->get(HX_CSTRING("opacity"))) : ::String(HX_CSTRING("1.0")) ));		HX_STACK_VAR(opacity,"opacity");
		HX_STACK_LINE(644)
		this->tilesIDs = Array_obj< int >::__new();
		HX_STACK_LINE(646)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(xml->iterator());  __it->hasNext(); ){
			::Xml child = __it->next();
			if ((this->isValidElement(child))){
				HX_STACK_LINE(649)
				if (((child->get_nodeName() == HX_CSTRING("data")))){
					HX_STACK_LINE(652)
					::String encoding = HX_CSTRING("");		HX_STACK_VAR(encoding,"encoding");
					HX_STACK_LINE(653)
					if ((child->exists(HX_CSTRING("encoding")))){
						HX_STACK_LINE(654)
						encoding = child->get(HX_CSTRING("encoding"));
					}
					HX_STACK_LINE(657)
					::String chunk = HX_CSTRING("");		HX_STACK_VAR(chunk,"chunk");
					HX_STACK_LINE(658)
					::String _switch_1 = (encoding);
					if (  ( _switch_1==HX_CSTRING("base64"))){
						HX_STACK_LINE(659)
						chunk = child->firstChild()->get_nodeValue();
					}
					else if (  ( _switch_1==HX_CSTRING("csv"))){
						HX_STACK_LINE(666)
						chunk = child->firstChild()->get_nodeValue();
						HX_STACK_LINE(668)
						this->tilesIDs = this->csvToArray(chunk);
					}
					else  {
						HX_STACK_LINE(670)
						for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(child->iterator());  __it->hasNext(); ){
							::Xml tile = __it->next();
							if ((this->isValidElement(tile))){
								HX_STACK_LINE(677)
								Dynamic gid = ::Std_obj::parseInt(tile->get(HX_CSTRING("gid")));		HX_STACK_VAR(gid,"gid");
								HX_STACK_LINE(678)
								this->tilesIDs->push(gid);
							}
;
						}
					}
;
;
				}
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,layerfromGenericXml,(void))

Array< int > TileMap_obj::csvToArray( ::String input){
	HX_STACK_PUSH("TileMap::csvToArray","com/engine/render/TileMap.hx",611);
	HX_STACK_THIS(this);
	HX_STACK_ARG(input,"input");
	HX_STACK_LINE(612)
	Array< int > result = Array_obj< int >::__new();		HX_STACK_VAR(result,"result");
	HX_STACK_LINE(613)
	Array< ::String > rows = ::StringTools_obj::trim(input).split(HX_CSTRING("\n"));		HX_STACK_VAR(rows,"rows");
	HX_STACK_LINE(614)
	::String row;		HX_STACK_VAR(row,"row");
	HX_STACK_LINE(616)
	{
		HX_STACK_LINE(616)
		int _g = (int)0;		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(616)
		while(((_g < rows->length))){
			HX_STACK_LINE(616)
			::String row1 = rows->__get(_g);		HX_STACK_VAR(row1,"row1");
			HX_STACK_LINE(616)
			++(_g);
			HX_STACK_LINE(618)
			if (((row1 == HX_CSTRING("")))){
				HX_STACK_LINE(618)
				continue;
			}
			HX_STACK_LINE(622)
			Array< int > resultRow = Array_obj< int >::__new();		HX_STACK_VAR(resultRow,"resultRow");
			HX_STACK_LINE(623)
			Array< ::String > entries = row1.split(HX_CSTRING(","));		HX_STACK_VAR(entries,"entries");
			HX_STACK_LINE(624)
			::String entry;		HX_STACK_VAR(entry,"entry");
			HX_STACK_LINE(626)
			{
				HX_STACK_LINE(626)
				int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
				HX_STACK_LINE(626)
				while(((_g1 < entries->length))){
					HX_STACK_LINE(626)
					::String entry1 = entries->__get(_g1);		HX_STACK_VAR(entry1,"entry1");
					HX_STACK_LINE(626)
					++(_g1);
					HX_STACK_LINE(628)
					if (((entry1 != HX_CSTRING("")))){
						HX_STACK_LINE(628)
						result->push(::Std_obj::parseInt(entry1));
					}
				}
			}
		}
	}
	HX_STACK_LINE(633)
	return result;
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,csvToArray,return )

Void TileMap_obj::tilesfromGenericXml( ::String content){
{
		HX_STACK_PUSH("TileMap::tilesfromGenericXml","com/engine/render/TileMap.hx",506);
		HX_STACK_THIS(this);
		HX_STACK_ARG(content,"content");
		HX_STACK_LINE(507)
		::Xml xml = ::Xml_obj::parse(content)->firstElement();		HX_STACK_VAR(xml,"xml");
		HX_STACK_LINE(509)
		::String name = xml->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
		HX_STACK_LINE(510)
		this->tileWidth = ::Std_obj::parseInt(xml->get(HX_CSTRING("tilewidth")));
		HX_STACK_LINE(511)
		this->tileHeight = ::Std_obj::parseInt(xml->get(HX_CSTRING("tileheight")));
		HX_STACK_LINE(512)
		this->spacing = (  ((xml->exists(HX_CSTRING("spacing")))) ? int(::Std_obj::parseInt(xml->get(HX_CSTRING("spacing")))) : int((int)0) );
		HX_STACK_LINE(513)
		this->margin = (  ((xml->exists(HX_CSTRING("margin")))) ? int(::Std_obj::parseInt(xml->get(HX_CSTRING("margin")))) : int((int)0) );
		HX_STACK_LINE(515)
		::haxe::ds::StringMap properties = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(properties,"properties");
		HX_STACK_LINE(520)
		int tileOffsetX = (int)0;		HX_STACK_VAR(tileOffsetX,"tileOffsetX");
		HX_STACK_LINE(521)
		int tileOffsetY = (int)0;		HX_STACK_VAR(tileOffsetY,"tileOffsetY");
		HX_STACK_LINE(523)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(xml->elements());  __it->hasNext(); ){
			::Xml child = __it->next();
			if ((this->isValidElement(child))){
				HX_STACK_LINE(527)
				if (((child->get_nodeName() == HX_CSTRING("properties")))){
					HX_STACK_LINE(528)
					for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(child->iterator());  __it->hasNext(); ){
						::Xml property = __it->next();
						if ((this->isValidElement(property))){
							HX_STACK_LINE(531)
							::haxe::Log_obj::trace((((HX_CSTRING("tileHeight set name:") + property->get(HX_CSTRING("name"))) + HX_CSTRING(" - Value : ")) + property->get(HX_CSTRING("value"))),hx::SourceInfo(HX_CSTRING("TileMap.hx"),532,HX_CSTRING("com.engine.render.TileMap"),HX_CSTRING("tilesfromGenericXml")));
						}
;
					}
				}
				HX_STACK_LINE(538)
				if (((child->get_nodeName() == HX_CSTRING("tileoffset")))){
					HX_STACK_LINE(540)
					tileOffsetX = ::Std_obj::parseInt(child->get(HX_CSTRING("x")));
					HX_STACK_LINE(541)
					tileOffsetY = ::Std_obj::parseInt(child->get(HX_CSTRING("y")));
				}
				HX_STACK_LINE(544)
				if (((child->get_nodeName() == HX_CSTRING("image")))){
					HX_STACK_LINE(546)
					Dynamic width = ::Std_obj::parseInt(child->get(HX_CSTRING("width")));		HX_STACK_VAR(width,"width");
					HX_STACK_LINE(547)
					Dynamic height = ::Std_obj::parseInt(child->get(HX_CSTRING("height")));		HX_STACK_VAR(height,"height");
					HX_STACK_LINE(549)
					this->image = ::com::engine::render::Texture_obj::__new((HX_CSTRING("assets/") + child->get(HX_CSTRING("source"))));
					HX_STACK_LINE(550)
					if (((this->image != null()))){
						HX_STACK_LINE(551)
						this->columns = ::Std_obj::_int((Float(this->image->width) / Float(this->tileWidth)));
					}
				}
				HX_STACK_LINE(560)
				if (((child->get_nodeName() == HX_CSTRING("terraintypes")))){
					HX_STACK_LINE(561)
					for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(child->iterator());  __it->hasNext(); ){
						::Xml element = __it->next();
						if ((this->isValidElement(element))){
							HX_STACK_LINE(566)
							if (((element->get_nodeName() == HX_CSTRING("terrain")))){
							}
						}
;
					}
				}
				HX_STACK_LINE(576)
				if (((child->get_nodeName() == HX_CSTRING("tile")))){
					HX_STACK_LINE(579)
					int id = ::Std_obj::parseInt(child->get(HX_CSTRING("id")));		HX_STACK_VAR(id,"id");
					HX_STACK_LINE(580)
					::haxe::ds::StringMap properties1 = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(properties1,"properties1");
					HX_STACK_LINE(582)
					for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(child->iterator());  __it->hasNext(); ){
						::Xml element = __it->next();
						if ((this->isValidElement(element))){
							HX_STACK_LINE(586)
							if (((element->get_nodeName() == HX_CSTRING("properties")))){
								HX_STACK_LINE(588)
								for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(element->iterator());  __it->hasNext(); ){
									::Xml property = __it->next();
									if ((!(this->isValidElement(property)))){
										HX_STACK_LINE(590)
										continue;
									}
;
								}
							}
						}
;
					}
				}
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,tilesfromGenericXml,(void))

::String TileMap_obj::getText( ::String assetPath){
	HX_STACK_PUSH("TileMap::getText","com/engine/render/TileMap.hx",501);
	HX_STACK_THIS(this);
	HX_STACK_ARG(assetPath,"assetPath");
	HX_STACK_LINE(501)
	return ::openfl::Assets_obj::getText(assetPath);
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,getText,return )

bool TileMap_obj::isValidElement( ::Xml element){
	HX_STACK_PUSH("TileMap::isValidElement","com/engine/render/TileMap.hx",497);
	HX_STACK_THIS(this);
	HX_STACK_ARG(element,"element");
	HX_STACK_LINE(497)
	return (::Std_obj::string(element->nodeType) == HX_CSTRING("element"));
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,isValidElement,return )

Void TileMap_obj::objectsfromGenericXml( ::Xml xml){
{
		HX_STACK_PUSH("TileMap::objectsfromGenericXml","com/engine/render/TileMap.hx",465);
		HX_STACK_THIS(this);
		HX_STACK_ARG(xml,"xml");
		HX_STACK_LINE(466)
		::String name = xml->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
		HX_STACK_LINE(467)
		::String color = xml->get(HX_CSTRING("color"));		HX_STACK_VAR(color,"color");
		HX_STACK_LINE(468)
		Dynamic width = ::Std_obj::parseInt(xml->get(HX_CSTRING("width")));		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(469)
		Dynamic height = ::Std_obj::parseInt(xml->get(HX_CSTRING("height")));		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(470)
		::haxe::ds::StringMap properties = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(properties,"properties");
		HX_STACK_LINE(473)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(xml->iterator());  __it->hasNext(); ){
			::Xml child = __it->next();
			if ((this->isValidElement(child))){
				HX_STACK_LINE(476)
				if (((child->get_nodeName() == HX_CSTRING("properties")))){
					HX_STACK_LINE(476)
					for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(child->iterator());  __it->hasNext(); ){
						::Xml property = __it->next();
						if ((this->isValidElement(property))){
							HX_STACK_LINE(479)
							properties->set(property->get(HX_CSTRING("name")),property->get(HX_CSTRING("value")));
						}
;
					}
				}
				HX_STACK_LINE(485)
				if (((child->get_nodeName() == HX_CSTRING("object")))){
					HX_STACK_LINE(486)
					this->objectfromGenericXml(child);
				}
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,objectsfromGenericXml,(void))

Void TileMap_obj::objectfromGenericXml( ::Xml xml){
{
		HX_STACK_PUSH("TileMap::objectfromGenericXml","com/engine/render/TileMap.hx",409);
		HX_STACK_THIS(this);
		HX_STACK_ARG(xml,"xml");
		HX_STACK_LINE(410)
		int gid = (  (((xml->get(HX_CSTRING("gid")) != null()))) ? int(::Std_obj::parseInt(xml->get(HX_CSTRING("gid")))) : int((int)0) );		HX_STACK_VAR(gid,"gid");
		HX_STACK_LINE(411)
		::String name = xml->get(HX_CSTRING("name"));		HX_STACK_VAR(name,"name");
		HX_STACK_LINE(412)
		::String type = xml->get(HX_CSTRING("type"));		HX_STACK_VAR(type,"type");
		HX_STACK_LINE(413)
		int x = ::Std_obj::parseInt(xml->get(HX_CSTRING("x")));		HX_STACK_VAR(x,"x");
		HX_STACK_LINE(414)
		int y = ::Std_obj::parseInt(xml->get(HX_CSTRING("y")));		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(415)
		int width = ::Std_obj::parseInt(xml->get(HX_CSTRING("width")));		HX_STACK_VAR(width,"width");
		HX_STACK_LINE(416)
		int height = ::Std_obj::parseInt(xml->get(HX_CSTRING("height")));		HX_STACK_VAR(height,"height");
		HX_STACK_LINE(419)
		::haxe::ds::StringMap properties = ::haxe::ds::StringMap_obj::__new();		HX_STACK_VAR(properties,"properties");
		HX_STACK_LINE(421)
		for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(xml->iterator());  __it->hasNext(); ){
			::Xml child = __it->next();
			if ((this->isValidElement(child))){
				HX_STACK_LINE(425)
				if (((child->get_nodeName() == HX_CSTRING("properties")))){
					HX_STACK_LINE(426)
					for(::cpp::FastIterator_obj< ::Xml > *__it = ::cpp::CreateFastIterator< ::Xml >(child->iterator());  __it->hasNext(); ){
						::Xml property = __it->next();
						if ((this->isValidElement(property))){
							HX_STACK_LINE(430)
							properties->set(property->get(HX_CSTRING("name")),property->get(HX_CSTRING("value")));
						}
;
					}
				}
				HX_STACK_LINE(436)
				if (((bool((child->get_nodeName() == HX_CSTRING("polygon"))) || bool((child->get_nodeName() == HX_CSTRING("polyline")))))){
					HX_STACK_LINE(438)
					::flash::geom::Point origin = ::flash::geom::Point_obj::__new(x,y);		HX_STACK_VAR(origin,"origin");
					HX_STACK_LINE(439)
					Array< ::Dynamic > points = Array_obj< ::Dynamic >::__new();		HX_STACK_VAR(points,"points");
					HX_STACK_LINE(441)
					::String pointsAsString = child->get(HX_CSTRING("points"));		HX_STACK_VAR(pointsAsString,"pointsAsString");
					HX_STACK_LINE(443)
					Array< ::String > pointsAsStringArray = pointsAsString.split(HX_CSTRING(" "));		HX_STACK_VAR(pointsAsStringArray,"pointsAsStringArray");
					HX_STACK_LINE(445)
					{
						HX_STACK_LINE(445)
						int _g = (int)0;		HX_STACK_VAR(_g,"_g");
						HX_STACK_LINE(445)
						while(((_g < pointsAsStringArray->length))){
							HX_STACK_LINE(445)
							::String p = pointsAsStringArray->__get(_g);		HX_STACK_VAR(p,"p");
							HX_STACK_LINE(445)
							++(_g);
						}
					}
					HX_STACK_LINE(451)
					if (((child->get_nodeName() == HX_CSTRING("polygon")))){
					}
					else{
						HX_STACK_LINE(454)
						if (((child->get_nodeName() == HX_CSTRING("polyline")))){
						}
					}
				}
			}
;
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,objectfromGenericXml,(void))

Void TileMap_obj::loadFromString( ::String str,::String __o_columnSep,::String __o_rowSep){
::String columnSep = __o_columnSep.Default(HX_CSTRING(","));
::String rowSep = __o_rowSep.Default(HX_CSTRING("\n"));
	HX_STACK_PUSH("TileMap::loadFromString","com/engine/render/TileMap.hx",390);
	HX_STACK_THIS(this);
	HX_STACK_ARG(str,"str");
	HX_STACK_ARG(columnSep,"columnSep");
	HX_STACK_ARG(rowSep,"rowSep");
{
		HX_STACK_LINE(391)
		Array< ::String > row = str.split(rowSep);		HX_STACK_VAR(row,"row");
		int rows = row->length;		HX_STACK_VAR(rows,"rows");
		Array< ::String > col;		HX_STACK_VAR(col,"col");
		int cols;		HX_STACK_VAR(cols,"cols");
		int x;		HX_STACK_VAR(x,"x");
		int y;		HX_STACK_VAR(y,"y");
		HX_STACK_LINE(394)
		{
			HX_STACK_LINE(394)
			int _g = (int)0;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(394)
			while(((_g < rows))){
				HX_STACK_LINE(394)
				int y1 = (_g)++;		HX_STACK_VAR(y1,"y1");
				HX_STACK_LINE(396)
				if (((row->__get(y1) == HX_CSTRING("")))){
					HX_STACK_LINE(396)
					continue;
				}
				HX_STACK_LINE(397)
				col = row->__get(y1).split(columnSep);
				HX_STACK_LINE(398)
				cols = col->length;
				HX_STACK_LINE(399)
				{
					HX_STACK_LINE(399)
					int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
					HX_STACK_LINE(399)
					while(((_g1 < cols))){
						HX_STACK_LINE(399)
						int x1 = (_g1)++;		HX_STACK_VAR(x1,"x1");
						HX_STACK_LINE(401)
						if (((col->__get(x1) == HX_CSTRING("")))){
							HX_STACK_LINE(401)
							continue;
						}
					}
				}
			}
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC3(TileMap_obj,loadFromString,(void))

Void TileMap_obj::addClips( ){
{
		HX_STACK_PUSH("TileMap::addClips","com/engine/render/TileMap.hx",362);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileMap_obj,addClips,(void))

::com::engine::render::Clip TileMap_obj::getClip( int num){
	HX_STACK_PUSH("TileMap::getClip","com/engine/render/TileMap.hx",345);
	HX_STACK_THIS(this);
	HX_STACK_ARG(num,"num");
	HX_STACK_LINE(345)
	return ::com::engine::render::Clip_obj::__new((this->margin + (((this->tileWidth + this->spacing)) * (hx::Mod(num,this->columns)))),(this->margin + (((this->tileHeight + this->spacing)) * ::Std_obj::_int((Float(num) / Float(this->columns))))),this->tileWidth,this->tileHeight);
}


HX_DEFINE_DYNAMIC_FUNC1(TileMap_obj,getClip,return )

int TileMap_obj::getCell( int x,int y){
	HX_STACK_PUSH("TileMap::getCell","com/engine/render/TileMap.hx",340);
	HX_STACK_THIS(this);
	HX_STACK_ARG(x,"x");
	HX_STACK_ARG(y,"y");
	HX_STACK_LINE(340)
	return this->tilesIDs->__get(((y * this->widthInTiles) + x));
}


HX_DEFINE_DYNAMIC_FUNC2(TileMap_obj,getCell,return )

Void TileMap_obj::renderDinamic( Float posx,Float posy){
{
		HX_STACK_PUSH("TileMap::renderDinamic","com/engine/render/TileMap.hx",291);
		HX_STACK_THIS(this);
		HX_STACK_ARG(posx,"posx");
		HX_STACK_ARG(posy,"posy");
		HX_STACK_LINE(292)
		this->update();
		HX_STACK_LINE(293)
		this->isBuild = false;
		HX_STACK_LINE(294)
		this->currentBatchSize = (int)0;
		HX_STACK_LINE(295)
		this->shader->Enable();
		HX_STACK_LINE(296)
		::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
		HX_STACK_LINE(297)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->vertexAttribute,(int)3,(int)5126,false,this->vertexStrideSize,(int)0);
		HX_STACK_LINE(298)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->texCoordAttribute,(int)2,(int)5126,false,this->vertexStrideSize,(int)12);
		HX_STACK_LINE(299)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->colorAttribute,(int)4,(int)5126,false,this->vertexStrideSize,(int)20);
		HX_STACK_LINE(301)
		{
			HX_STACK_LINE(301)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->heightInTiles;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(301)
			while(((_g1 < _g))){
				HX_STACK_LINE(301)
				int y = (_g1)++;		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(303)
				{
					HX_STACK_LINE(303)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					int _g2 = this->widthInTiles;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(303)
					while(((_g3 < _g2))){
						HX_STACK_LINE(303)
						int x = (_g3)++;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(307)
						int id = this->getCell(x,y);		HX_STACK_VAR(id,"id");
						HX_STACK_LINE(308)
						if (((id >= (int)1))){
							HX_STACK_LINE(310)
							::com::engine::render::Clip t = this->getClip((id - (int)1));		HX_STACK_VAR(t,"t");
							HX_STACK_LINE(311)
							int DrawX = ::Std_obj::_int((posx + (x * this->tileWidth)));		HX_STACK_VAR(DrawX,"DrawX");
							HX_STACK_LINE(312)
							int DrawY = ::Std_obj::_int((posy + (y * this->tileHeight)));		HX_STACK_VAR(DrawY,"DrawY");
							HX_STACK_LINE(313)
							::com::engine::render::Clip dst = ::com::engine::render::Clip_obj::__new(DrawX,DrawY,this->tileWidth,this->tileHeight);		HX_STACK_VAR(dst,"dst");
							HX_STACK_LINE(314)
							if (((bool((bool((DrawX >= -(this->tileWidth))) && bool((DrawX <= (::com::engine::game::Game_obj::viewWidth + this->tileWidth))))) && bool(((bool((DrawY >= -(this->tileHeight))) && bool((DrawY < (::com::engine::game::Game_obj::viewHeight + this->tileHeight))))))))){
								HX_STACK_LINE(315)
								this->addQuad(t,dst);
							}
						}
					}
				}
			}
		}
		HX_STACK_LINE(323)
		if (((this->currentBatchSize == (int)0))){
			HX_STACK_LINE(323)
			return null();
		}
		HX_STACK_LINE(324)
		::openfl::gl::GL_obj::activeTexture((int)33984);
		HX_STACK_LINE(325)
		this->image->Bind();
		HX_STACK_LINE(326)
		::com::engine::render::BlendMode_obj::setBlend(this->currentBlendMode);
		HX_STACK_LINE(327)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->projectionMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(::com::engine::game::Game_obj::projMatrix->m,null(),null()));
		HX_STACK_LINE(328)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->modelViewMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(this->viewMatrix->m,null(),null()));
		HX_STACK_LINE(329)
		::openfl::gl::GL_obj::uniform1i(this->shader->imageUniform,(int)0);
		HX_STACK_LINE(330)
		::openfl::gl::GL_obj::bufferData((int)34962,this->vertices,(int)35048);
		HX_STACK_LINE(331)
		::openfl::gl::GL_obj::bindBuffer((int)34963,this->indexBuffer);
		HX_STACK_LINE(332)
		::openfl::gl::GL_obj::drawElements((int)4,(this->currentBatchSize * (int)6),(int)5123,(int)0);
		HX_STACK_LINE(333)
		this->currentBatchSize = (int)0;
		HX_STACK_LINE(334)
		this->shader->Disable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TileMap_obj,renderDinamic,(void))

Void TileMap_obj::render( ){
{
		HX_STACK_PUSH("TileMap::render","com/engine/render/TileMap.hx",255);
		HX_STACK_THIS(this);
		HX_STACK_LINE(256)
		this->update();
		HX_STACK_LINE(260)
		if ((!(this->isBuild))){
			HX_STACK_LINE(262)
			this->build();
			HX_STACK_LINE(263)
			return null();
		}
		HX_STACK_LINE(265)
		this->shader->Enable();
		HX_STACK_LINE(266)
		::openfl::gl::GL_obj::bindBuffer((int)34962,this->vertexBuffer);
		HX_STACK_LINE(267)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->vertexAttribute,(int)3,(int)5126,false,this->vertexStrideSize,(int)0);
		HX_STACK_LINE(268)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->texCoordAttribute,(int)2,(int)5126,false,this->vertexStrideSize,(int)12);
		HX_STACK_LINE(269)
		::openfl::gl::GL_obj::vertexAttribPointer(this->shader->colorAttribute,(int)4,(int)5126,false,this->vertexStrideSize,(int)20);
		HX_STACK_LINE(273)
		if (((this->currentBatchSize == (int)0))){
			HX_STACK_LINE(273)
			return null();
		}
		HX_STACK_LINE(277)
		::openfl::gl::GL_obj::activeTexture((int)33984);
		HX_STACK_LINE(278)
		this->image->Bind();
		HX_STACK_LINE(279)
		::com::engine::render::BlendMode_obj::setBlend(this->currentBlendMode);
		HX_STACK_LINE(280)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->projectionMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(::com::engine::game::Game_obj::projMatrix->m,null(),null()));
		HX_STACK_LINE(281)
		::openfl::gl::GL_obj::uniformMatrix4fv(this->shader->modelViewMatrixUniform,false,::openfl::utils::Float32Array_obj::__new(this->viewMatrix->m,null(),null()));
		HX_STACK_LINE(283)
		::openfl::gl::GL_obj::uniform1i(this->shader->imageUniform,(int)0);
		HX_STACK_LINE(284)
		::openfl::gl::GL_obj::bufferData((int)34962,this->vertices,(int)35048);
		HX_STACK_LINE(285)
		::openfl::gl::GL_obj::bindBuffer((int)34963,this->indexBuffer);
		HX_STACK_LINE(286)
		::openfl::gl::GL_obj::drawElements((int)4,(this->currentBatchSize * (int)6),(int)5123,(int)0);
		HX_STACK_LINE(287)
		this->shader->Disable();
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileMap_obj,render,(void))

Void TileMap_obj::addQuad( ::com::engine::render::Clip srcrect,::com::engine::render::Clip dstrect){
{
		HX_STACK_PUSH("TileMap::addQuad","com/engine/render/TileMap.hx",214);
		HX_STACK_THIS(this);
		HX_STACK_ARG(srcrect,"srcrect");
		HX_STACK_ARG(dstrect,"dstrect");
		HX_STACK_LINE(216)
		int index = (this->currentBatchSize * this->vertexStrideSize);		HX_STACK_VAR(index,"index");
		HX_STACK_LINE(218)
		int widthTex = this->image->width;		HX_STACK_VAR(widthTex,"widthTex");
		HX_STACK_LINE(219)
		int heightTex = this->image->height;		HX_STACK_VAR(heightTex,"heightTex");
		HX_STACK_LINE(224)
		hx::__ArrayImplRef(this->vertices,(index)++) = dstrect->x;
		HX_STACK_LINE(225)
		hx::__ArrayImplRef(this->vertices,(index)++) = dstrect->y;
		HX_STACK_LINE(226)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(227)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(srcrect->x) / Float(widthTex));
		HX_STACK_LINE(227)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(srcrect->y) / Float(heightTex));
		HX_STACK_LINE(228)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(228)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(228)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(228)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(230)
		hx::__ArrayImplRef(this->vertices,(index)++) = (dstrect->x + dstrect->width);
		HX_STACK_LINE(231)
		hx::__ArrayImplRef(this->vertices,(index)++) = dstrect->y;
		HX_STACK_LINE(232)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(233)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(((srcrect->x + srcrect->width))) / Float(widthTex));
		HX_STACK_LINE(233)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(srcrect->y) / Float(heightTex));
		HX_STACK_LINE(234)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(234)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(234)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(234)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(236)
		hx::__ArrayImplRef(this->vertices,(index)++) = (dstrect->x + dstrect->width);
		HX_STACK_LINE(237)
		hx::__ArrayImplRef(this->vertices,(index)++) = (dstrect->y + dstrect->height);
		HX_STACK_LINE(238)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(239)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(((srcrect->x + srcrect->width))) / Float(widthTex));
		HX_STACK_LINE(239)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(((srcrect->y + srcrect->height))) / Float(heightTex));
		HX_STACK_LINE(240)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(240)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(240)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(240)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(242)
		hx::__ArrayImplRef(this->vertices,(index)++) = dstrect->x;
		HX_STACK_LINE(243)
		hx::__ArrayImplRef(this->vertices,(index)++) = (dstrect->y + dstrect->height);
		HX_STACK_LINE(244)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)0;
		HX_STACK_LINE(245)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(srcrect->x) / Float(widthTex));
		HX_STACK_LINE(245)
		hx::__ArrayImplRef(this->vertices,(index)++) = (Float(((srcrect->y + srcrect->height))) / Float(heightTex));
		HX_STACK_LINE(246)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(246)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(246)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(246)
		hx::__ArrayImplRef(this->vertices,(index)++) = (int)1;
		HX_STACK_LINE(251)
		(this->currentBatchSize)++;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(TileMap_obj,addQuad,(void))

Void TileMap_obj::build( ){
{
		HX_STACK_PUSH("TileMap::build","com/engine/render/TileMap.hx",190);
		HX_STACK_THIS(this);
		HX_STACK_LINE(191)
		{
			HX_STACK_LINE(191)
			int _g1 = (int)0;		HX_STACK_VAR(_g1,"_g1");
			int _g = this->heightInTiles;		HX_STACK_VAR(_g,"_g");
			HX_STACK_LINE(191)
			while(((_g1 < _g))){
				HX_STACK_LINE(191)
				int y = (_g1)++;		HX_STACK_VAR(y,"y");
				HX_STACK_LINE(193)
				{
					HX_STACK_LINE(193)
					int _g3 = (int)0;		HX_STACK_VAR(_g3,"_g3");
					int _g2 = this->widthInTiles;		HX_STACK_VAR(_g2,"_g2");
					HX_STACK_LINE(193)
					while(((_g3 < _g2))){
						HX_STACK_LINE(193)
						int x = (_g3)++;		HX_STACK_VAR(x,"x");
						HX_STACK_LINE(197)
						int id = this->getCell(x,y);		HX_STACK_VAR(id,"id");
						HX_STACK_LINE(198)
						if (((id >= (int)1))){
							HX_STACK_LINE(201)
							::com::engine::render::Clip t = this->getClip((id - (int)1));		HX_STACK_VAR(t,"t");
							HX_STACK_LINE(202)
							int DrawX = ::Std_obj::_int((x * this->tileWidth));		HX_STACK_VAR(DrawX,"DrawX");
							HX_STACK_LINE(203)
							int DrawY = ::Std_obj::_int((y * this->tileHeight));		HX_STACK_VAR(DrawY,"DrawY");
							HX_STACK_LINE(204)
							::com::engine::render::Clip dst = ::com::engine::render::Clip_obj::__new(DrawX,DrawY,this->tileWidth,this->tileHeight);		HX_STACK_VAR(dst,"dst");
							HX_STACK_LINE(205)
							this->addQuad(t,dst);
						}
					}
				}
			}
		}
		HX_STACK_LINE(209)
		this->isBuild = true;
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(TileMap_obj,build,(void))


TileMap_obj::TileMap_obj()
{
}

void TileMap_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(TileMap);
	HX_MARK_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_MARK_MEMBER_NAME(shader,"shader");
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
	HX_MARK_MEMBER_NAME(numIndices,"numIndices");
	HX_MARK_MEMBER_NAME(numVerts,"numVerts");
	HX_MARK_MEMBER_NAME(capacity,"capacity");
	HX_MARK_MEMBER_NAME(isBuild,"isBuild");
	HX_MARK_MEMBER_NAME(image,"image");
	HX_MARK_MEMBER_NAME(columns,"columns");
	HX_MARK_MEMBER_NAME(tilesIDs,"tilesIDs");
	HX_MARK_MEMBER_NAME(spacing,"spacing");
	HX_MARK_MEMBER_NAME(margin,"margin");
	HX_MARK_MEMBER_NAME(tileHeight,"tileHeight");
	HX_MARK_MEMBER_NAME(tileWidth,"tileWidth");
	HX_MARK_MEMBER_NAME(heightInTiles,"heightInTiles");
	HX_MARK_MEMBER_NAME(widthInTiles,"widthInTiles");
	super::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void TileMap_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(vertexStrideSize,"vertexStrideSize");
	HX_VISIT_MEMBER_NAME(shader,"shader");
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
	HX_VISIT_MEMBER_NAME(numIndices,"numIndices");
	HX_VISIT_MEMBER_NAME(numVerts,"numVerts");
	HX_VISIT_MEMBER_NAME(capacity,"capacity");
	HX_VISIT_MEMBER_NAME(isBuild,"isBuild");
	HX_VISIT_MEMBER_NAME(image,"image");
	HX_VISIT_MEMBER_NAME(columns,"columns");
	HX_VISIT_MEMBER_NAME(tilesIDs,"tilesIDs");
	HX_VISIT_MEMBER_NAME(spacing,"spacing");
	HX_VISIT_MEMBER_NAME(margin,"margin");
	HX_VISIT_MEMBER_NAME(tileHeight,"tileHeight");
	HX_VISIT_MEMBER_NAME(tileWidth,"tileWidth");
	HX_VISIT_MEMBER_NAME(heightInTiles,"heightInTiles");
	HX_VISIT_MEMBER_NAME(widthInTiles,"widthInTiles");
	super::__Visit(HX_VISIT_ARG);
}

Dynamic TileMap_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"toCSV") ) { return toCSV_dyn(); }
		if (HX_FIELD_EQ(inName,"build") ) { return build_dyn(); }
		if (HX_FIELD_EQ(inName,"image") ) { return image; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"render") ) { return render_dyn(); }
		if (HX_FIELD_EQ(inName,"shader") ) { return shader; }
		if (HX_FIELD_EQ(inName,"margin") ) { return margin; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		if (HX_FIELD_EQ(inName,"getText") ) { return getText_dyn(); }
		if (HX_FIELD_EQ(inName,"getClip") ) { return getClip_dyn(); }
		if (HX_FIELD_EQ(inName,"getCell") ) { return getCell_dyn(); }
		if (HX_FIELD_EQ(inName,"addQuad") ) { return addQuad_dyn(); }
		if (HX_FIELD_EQ(inName,"drawing") ) { return drawing; }
		if (HX_FIELD_EQ(inName,"indices") ) { return indices; }
		if (HX_FIELD_EQ(inName,"isBuild") ) { return isBuild; }
		if (HX_FIELD_EQ(inName,"columns") ) { return columns; }
		if (HX_FIELD_EQ(inName,"spacing") ) { return spacing; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addClips") ) { return addClips_dyn(); }
		if (HX_FIELD_EQ(inName,"vertices") ) { return vertices; }
		if (HX_FIELD_EQ(inName,"numVerts") ) { return numVerts; }
		if (HX_FIELD_EQ(inName,"capacity") ) { return capacity; }
		if (HX_FIELD_EQ(inName,"tilesIDs") ) { return tilesIDs; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { return tileWidth; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"csvToArray") ) { return csvToArray_dyn(); }
		if (HX_FIELD_EQ(inName,"numIndices") ) { return numIndices; }
		if (HX_FIELD_EQ(inName,"tileHeight") ) { return tileHeight; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"invTexWidth") ) { return invTexWidth; }
		if (HX_FIELD_EQ(inName,"indexBuffer") ) { return indexBuffer; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"invTexHeight") ) { return invTexHeight; }
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { return vertexBuffer; }
		if (HX_FIELD_EQ(inName,"widthInTiles") ) { return widthInTiles; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"renderDinamic") ) { return renderDinamic_dyn(); }
		if (HX_FIELD_EQ(inName,"heightInTiles") ) { return heightInTiles; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"isValidElement") ) { return isValidElement_dyn(); }
		if (HX_FIELD_EQ(inName,"loadFromString") ) { return loadFromString_dyn(); }
		if (HX_FIELD_EQ(inName,"lastIndexCount") ) { return lastIndexCount; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"vertexStrideSize") ) { return vertexStrideSize; }
		if (HX_FIELD_EQ(inName,"currentBlendMode") ) { return currentBlendMode; }
		if (HX_FIELD_EQ(inName,"currentBatchSize") ) { return currentBatchSize; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"currentBaseTexture") ) { return currentBaseTexture; }
		break;
	case 19:
		if (HX_FIELD_EQ(inName,"layerfromGenericXml") ) { return layerfromGenericXml_dyn(); }
		if (HX_FIELD_EQ(inName,"tilesfromGenericXml") ) { return tilesfromGenericXml_dyn(); }
		break;
	case 20:
		if (HX_FIELD_EQ(inName,"objectfromGenericXml") ) { return objectfromGenericXml_dyn(); }
		break;
	case 21:
		if (HX_FIELD_EQ(inName,"objectsfromGenericXml") ) { return objectsfromGenericXml_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic TileMap_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"image") ) { image=inValue.Cast< ::com::engine::render::Texture >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"shader") ) { shader=inValue.Cast< ::com::engine::render::SpriteShader >(); return inValue; }
		if (HX_FIELD_EQ(inName,"margin") ) { margin=inValue.Cast< int >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"drawing") ) { drawing=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indices") ) { indices=inValue.Cast< ::openfl::utils::Int16Array >(); return inValue; }
		if (HX_FIELD_EQ(inName,"isBuild") ) { isBuild=inValue.Cast< bool >(); return inValue; }
		if (HX_FIELD_EQ(inName,"columns") ) { columns=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"spacing") ) { spacing=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"vertices") ) { vertices=inValue.Cast< ::openfl::utils::Float32Array >(); return inValue; }
		if (HX_FIELD_EQ(inName,"numVerts") ) { numVerts=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"capacity") ) { capacity=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tilesIDs") ) { tilesIDs=inValue.Cast< Array< int > >(); return inValue; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"tileWidth") ) { tileWidth=inValue.Cast< int >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"numIndices") ) { numIndices=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"tileHeight") ) { tileHeight=inValue.Cast< int >(); return inValue; }
		break;
	case 11:
		if (HX_FIELD_EQ(inName,"invTexWidth") ) { invTexWidth=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"indexBuffer") ) { indexBuffer=inValue.Cast< ::openfl::gl::GLBuffer >(); return inValue; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"invTexHeight") ) { invTexHeight=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"vertexBuffer") ) { vertexBuffer=inValue.Cast< ::openfl::gl::GLBuffer >(); return inValue; }
		if (HX_FIELD_EQ(inName,"widthInTiles") ) { widthInTiles=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"heightInTiles") ) { heightInTiles=inValue.Cast< int >(); return inValue; }
		break;
	case 14:
		if (HX_FIELD_EQ(inName,"lastIndexCount") ) { lastIndexCount=inValue.Cast< int >(); return inValue; }
		break;
	case 16:
		if (HX_FIELD_EQ(inName,"vertexStrideSize") ) { vertexStrideSize=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentBlendMode") ) { currentBlendMode=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"currentBatchSize") ) { currentBatchSize=inValue.Cast< int >(); return inValue; }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"currentBaseTexture") ) { currentBaseTexture=inValue.Cast< ::com::engine::render::Texture >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void TileMap_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("vertexStrideSize"));
	outFields->push(HX_CSTRING("shader"));
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
	outFields->push(HX_CSTRING("numIndices"));
	outFields->push(HX_CSTRING("numVerts"));
	outFields->push(HX_CSTRING("capacity"));
	outFields->push(HX_CSTRING("isBuild"));
	outFields->push(HX_CSTRING("image"));
	outFields->push(HX_CSTRING("columns"));
	outFields->push(HX_CSTRING("tilesIDs"));
	outFields->push(HX_CSTRING("spacing"));
	outFields->push(HX_CSTRING("margin"));
	outFields->push(HX_CSTRING("tileHeight"));
	outFields->push(HX_CSTRING("tileWidth"));
	outFields->push(HX_CSTRING("heightInTiles"));
	outFields->push(HX_CSTRING("widthInTiles"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("toCSV"),
	HX_CSTRING("layerfromGenericXml"),
	HX_CSTRING("csvToArray"),
	HX_CSTRING("tilesfromGenericXml"),
	HX_CSTRING("getText"),
	HX_CSTRING("isValidElement"),
	HX_CSTRING("objectsfromGenericXml"),
	HX_CSTRING("objectfromGenericXml"),
	HX_CSTRING("loadFromString"),
	HX_CSTRING("addClips"),
	HX_CSTRING("getClip"),
	HX_CSTRING("getCell"),
	HX_CSTRING("renderDinamic"),
	HX_CSTRING("render"),
	HX_CSTRING("addQuad"),
	HX_CSTRING("build"),
	HX_CSTRING("vertexStrideSize"),
	HX_CSTRING("shader"),
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
	HX_CSTRING("numIndices"),
	HX_CSTRING("numVerts"),
	HX_CSTRING("capacity"),
	HX_CSTRING("isBuild"),
	HX_CSTRING("image"),
	HX_CSTRING("columns"),
	HX_CSTRING("tilesIDs"),
	HX_CSTRING("spacing"),
	HX_CSTRING("margin"),
	HX_CSTRING("tileHeight"),
	HX_CSTRING("tileWidth"),
	HX_CSTRING("heightInTiles"),
	HX_CSTRING("widthInTiles"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(TileMap_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(TileMap_obj::__mClass,"__mClass");
};

Class TileMap_obj::__mClass;

void TileMap_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.TileMap"), hx::TCanCast< TileMap_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void TileMap_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
