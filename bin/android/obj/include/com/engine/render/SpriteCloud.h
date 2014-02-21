#ifndef INCLUDED_com_engine_render_SpriteCloud
#define INCLUDED_com_engine_render_SpriteCloud

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/render/Buffer.h>
HX_DECLARE_CLASS3(com,engine,render,Buffer)
HX_DECLARE_CLASS3(com,engine,render,Clip)
HX_DECLARE_CLASS3(com,engine,render,Image)
HX_DECLARE_CLASS3(com,engine,render,SpriteCloud)
HX_DECLARE_CLASS3(com,engine,render,SpriteShader)
HX_DECLARE_CLASS3(com,engine,render,Texture)
HX_DECLARE_CLASS2(openfl,gl,GLBuffer)
HX_DECLARE_CLASS2(openfl,gl,GLObject)
HX_DECLARE_CLASS2(openfl,utils,ArrayBufferView)
HX_DECLARE_CLASS2(openfl,utils,Float32Array)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
HX_DECLARE_CLASS2(openfl,utils,Int16Array)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  SpriteCloud_obj : public ::com::engine::render::Buffer_obj{
	public:
		typedef ::com::engine::render::Buffer_obj super;
		typedef SpriteCloud_obj OBJ_;
		SpriteCloud_obj();
		Void __construct(::com::engine::render::Texture texture,int capacity);

	public:
		static hx::ObjectPtr< SpriteCloud_obj > __new(::com::engine::render::Texture texture,int capacity);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SpriteCloud_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SpriteCloud"); }

		virtual Void render( );
		Dynamic render_dyn();

		virtual Void addVertex( Float x,Float y,Float u,Float v);
		Dynamic addVertex_dyn();

		virtual Void addTile( Float x,Float y,Float width,Float height,::com::engine::render::Clip clip,bool flipx,bool flipy);
		Dynamic addTile_dyn();

		virtual Void add( );
		Dynamic add_dyn();

		virtual Void addImage( ::com::engine::render::Image img);
		Dynamic addImage_dyn();

		virtual Void dispose( );

		virtual Void build( );
		Dynamic build_dyn();

		bool rebuid;
		int index;
		::com::engine::render::SpriteShader shader;
		int vertexStrideSize;
		Array< int > vertexDeclaration;
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
		::openfl::utils::Float32Array tmpVertices;
		int numIndices;
		int numVerts;
		int capacity;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_SpriteCloud */ 
