#ifndef INCLUDED_com_engine_render_BatchPrimitives
#define INCLUDED_com_engine_render_BatchPrimitives

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/render/Buffer.h>
HX_DECLARE_CLASS3(com,engine,render,BatchPrimitives)
HX_DECLARE_CLASS3(com,engine,render,Buffer)
HX_DECLARE_CLASS3(com,engine,render,PrimitiveShader)
HX_DECLARE_CLASS2(openfl,gl,GLBuffer)
HX_DECLARE_CLASS2(openfl,gl,GLObject)
HX_DECLARE_CLASS2(openfl,utils,ArrayBufferView)
HX_DECLARE_CLASS2(openfl,utils,Float32Array)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  BatchPrimitives_obj : public ::com::engine::render::Buffer_obj{
	public:
		typedef ::com::engine::render::Buffer_obj super;
		typedef BatchPrimitives_obj OBJ_;
		BatchPrimitives_obj();
		Void __construct(int capacity);

	public:
		static hx::ObjectPtr< BatchPrimitives_obj > __new(int capacity);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BatchPrimitives_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BatchPrimitives"); }

		virtual Void dispose( );

		virtual Void fillrect( Float x,Float y,Float width,Float height,Float r,Float g,Float b,Dynamic a);
		Dynamic fillrect_dyn();

		virtual Void rect( Float x,Float y,Float width,Float height,Float r,Float g,Float b,Dynamic a);
		Dynamic rect_dyn();

		virtual Void line( Float x1,Float y1,Float x2,Float y2,Float r,Float g,Float b,Dynamic a);
		Dynamic line_dyn();

		virtual Void fillellipse( Float x,Float y,Float width,Float height,int segments,Float r,Float g,Float b,Dynamic a);
		Dynamic fillellipse_dyn();

		virtual Void ellipse( Float x,Float y,Float width,Float height,int segments,Float r,Float g,Float b,Dynamic a);
		Dynamic ellipse_dyn();

		virtual Void fillcircle( Float x,Float y,Float radius,int segments,Float r,Float g,Float b,Dynamic a);
		Dynamic fillcircle_dyn();

		virtual Void circle( Float x,Float y,Float radius,int segments,Float r,Float g,Float b,Dynamic a);
		Dynamic circle_dyn();

		virtual Void end( );
		Dynamic end_dyn();

		virtual Void begin( );
		Dynamic begin_dyn();

		virtual Void render( );
		Dynamic render_dyn();

		virtual Void renderMode( hx::Null< bool >  fill);
		Dynamic renderMode_dyn();

		virtual Void color( Float r,Float g,Float b,Dynamic a);
		Dynamic color_dyn();

		virtual Void vertex( Float x,Float y,Dynamic z);
		Dynamic vertex_dyn();

		int vertexStrideSize;
		Array< int > vertexDeclaration;
		::com::engine::render::PrimitiveShader shader;
		int numVertices;
		int idxPos;
		int idxCols;
		int currentBlendMode;
		bool fillMode;
		int capacity;
		::openfl::utils::Float32Array vertices;
		::openfl::gl::GLBuffer vertexBuffer;
		::openfl::utils::Float32Array colors;
		int colorIndex;
		::openfl::gl::GLBuffer colorBuffer;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_BatchPrimitives */ 
