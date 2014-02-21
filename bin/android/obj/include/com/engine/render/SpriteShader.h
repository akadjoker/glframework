#ifndef INCLUDED_com_engine_render_SpriteShader
#define INCLUDED_com_engine_render_SpriteShader

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,render,SpriteShader)
HX_DECLARE_CLASS2(openfl,gl,GLObject)
HX_DECLARE_CLASS2(openfl,gl,GLProgram)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  SpriteShader_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SpriteShader_obj OBJ_;
		SpriteShader_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< SpriteShader_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SpriteShader_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SpriteShader"); }

		virtual Void Disable( );
		Dynamic Disable_dyn();

		virtual Void Enable( );
		Dynamic Enable_dyn();

		Dynamic imageUniform;
		Dynamic modelViewMatrixUniform;
		Dynamic projectionMatrixUniform;
		int colorAttribute;
		int texCoordAttribute;
		int vertexAttribute;
		::openfl::gl::GLProgram shaderProgram;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_SpriteShader */ 
