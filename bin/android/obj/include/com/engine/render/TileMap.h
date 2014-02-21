#ifndef INCLUDED_com_engine_render_TileMap
#define INCLUDED_com_engine_render_TileMap

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/render/Buffer.h>
HX_DECLARE_CLASS0(Xml)
HX_DECLARE_CLASS3(com,engine,render,Buffer)
HX_DECLARE_CLASS3(com,engine,render,Clip)
HX_DECLARE_CLASS3(com,engine,render,SpriteShader)
HX_DECLARE_CLASS3(com,engine,render,Texture)
HX_DECLARE_CLASS3(com,engine,render,TileMap)
HX_DECLARE_CLASS2(openfl,gl,GLBuffer)
HX_DECLARE_CLASS2(openfl,gl,GLObject)
HX_DECLARE_CLASS2(openfl,utils,ArrayBufferView)
HX_DECLARE_CLASS2(openfl,utils,Float32Array)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
HX_DECLARE_CLASS2(openfl,utils,Int16Array)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  TileMap_obj : public ::com::engine::render::Buffer_obj{
	public:
		typedef ::com::engine::render::Buffer_obj super;
		typedef TileMap_obj OBJ_;
		TileMap_obj();
		Void __construct(::String xml);

	public:
		static hx::ObjectPtr< TileMap_obj > __new(::String xml);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TileMap_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TileMap"); }

		virtual Void dispose( );

		virtual ::String toCSV( Dynamic width);
		Dynamic toCSV_dyn();

		virtual Void layerfromGenericXml( ::Xml xml);
		Dynamic layerfromGenericXml_dyn();

		virtual Array< int > csvToArray( ::String input);
		Dynamic csvToArray_dyn();

		virtual Void tilesfromGenericXml( ::String content);
		Dynamic tilesfromGenericXml_dyn();

		virtual ::String getText( ::String assetPath);
		Dynamic getText_dyn();

		virtual bool isValidElement( ::Xml element);
		Dynamic isValidElement_dyn();

		virtual Void objectsfromGenericXml( ::Xml xml);
		Dynamic objectsfromGenericXml_dyn();

		virtual Void objectfromGenericXml( ::Xml xml);
		Dynamic objectfromGenericXml_dyn();

		virtual Void loadFromString( ::String str,::String columnSep,::String rowSep);
		Dynamic loadFromString_dyn();

		virtual Void addClips( );
		Dynamic addClips_dyn();

		virtual ::com::engine::render::Clip getClip( int num);
		Dynamic getClip_dyn();

		virtual int getCell( int x,int y);
		Dynamic getCell_dyn();

		virtual Void renderDinamic( Float posx,Float posy);
		Dynamic renderDinamic_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		virtual Void addQuad( ::com::engine::render::Clip srcrect,::com::engine::render::Clip dstrect);
		Dynamic addQuad_dyn();

		virtual Void build( );
		Dynamic build_dyn();

		int vertexStrideSize;
		::com::engine::render::SpriteShader shader;
		Float invTexHeight;
		Float invTexWidth;
		::openfl::gl::GLBuffer indexBuffer;
		::openfl::gl::GLBuffer vertexBuffer;
		::com::engine::render::Texture currentBaseTexture;
		int currentBlendMode;
		int currentBatchSize;
		bool drawing;
		int lastIndexCount;
		::openfl::utils::Int16Array indices;
		::openfl::utils::Float32Array vertices;
		int numIndices;
		int numVerts;
		int capacity;
		bool isBuild;
		::com::engine::render::Texture image;
		int columns;
		Array< int > tilesIDs;
		int spacing;
		int margin;
		int tileHeight;
		int tileWidth;
		int heightInTiles;
		int widthInTiles;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_TileMap */ 
