#ifndef INCLUDED_com_engine_render_SpriteBatch
#define INCLUDED_com_engine_render_SpriteBatch

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/render/Buffer.h>
HX_DECLARE_CLASS3(com,engine,render,Buffer)
HX_DECLARE_CLASS3(com,engine,render,Clip)
HX_DECLARE_CLASS3(com,engine,render,Image)
HX_DECLARE_CLASS3(com,engine,render,SpriteBatch)
HX_DECLARE_CLASS3(com,engine,render,SpriteShader)
HX_DECLARE_CLASS3(com,engine,render,Texture)
HX_DECLARE_CLASS2(openfl,gl,GLBuffer)
HX_DECLARE_CLASS2(openfl,gl,GLObject)
HX_DECLARE_CLASS2(openfl,utils,ArrayBufferView)
HX_DECLARE_CLASS2(openfl,utils,Float32Array)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  SpriteBatch_obj : public ::com::engine::render::Buffer_obj{
	public:
		typedef ::com::engine::render::Buffer_obj super;
		typedef SpriteBatch_obj OBJ_;
		SpriteBatch_obj();
		Void __construct(int capacity);

	public:
		static hx::ObjectPtr< SpriteBatch_obj > __new(int capacity);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SpriteBatch_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SpriteBatch"); }

		virtual Void dispose( );

		virtual Void setBlendMode( int blendMode);
		Dynamic setBlendMode_dyn();

		virtual Void switchTexture( ::com::engine::render::Texture texture);
		Dynamic switchTexture_dyn();

		virtual Void flush( );
		Dynamic flush_dyn();

		virtual Void start( );
		Dynamic start_dyn();

		virtual Void End( );
		Dynamic End_dyn();

		virtual Void Begin( );
		Dynamic Begin_dyn();

		virtual Void RenderNormal( ::com::engine::render::Texture texture,Float x,Float y,int blendMode);
		Dynamic RenderNormal_dyn();

		virtual Void drawImage( ::com::engine::render::Image img);
		Dynamic drawImage_dyn();

		virtual Void RenderClip( ::com::engine::render::Texture texture,Float x,Float y,::com::engine::render::Clip c,bool flipX,bool flipY,int blendMode);
		Dynamic RenderClip_dyn();

		virtual Void Blt( ::com::engine::render::Texture texture,::com::engine::render::Clip src,::com::engine::render::Clip dst,bool flipX,bool flipY,int blendMode);
		Dynamic Blt_dyn();

		virtual Void RenderTile( ::com::engine::render::Texture texture,Float x,Float y,Float width,Float height,::com::engine::render::Clip clip,bool flipx,bool flipy,int blendMode);
		Dynamic RenderTile_dyn();

		virtual Void Render( ::com::engine::render::Texture texture,Float x,Float y,int srcX,int srcY,int srcWidth,int srcHeight,int blendMode);
		Dynamic Render_dyn();

		::com::engine::render::SpriteShader shader;
		int vertexStrideSize;
		Array< int > vertexDeclaration;
		Float invTexHeight;
		Float invTexWidth;
		::openfl::gl::GLBuffer indexBuffer;
		::openfl::gl::GLBuffer vertexBuffer;
		int numBlend;
		int numTex;
		::com::engine::render::Texture currentBaseTexture;
		int currentBlendMode;
		int currentBatchSize;
		bool drawing;
		int lastIndexCount;
		::openfl::utils::Float32Array vertices;
		int numIndices;
		int numVerts;
		int capacity;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_SpriteBatch */ 
