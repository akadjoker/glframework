#ifndef INCLUDED_com_engine_render_Texture
#define INCLUDED_com_engine_render_Texture

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,render,Texture)
HX_DECLARE_CLASS2(flash,display,BitmapData)
HX_DECLARE_CLASS2(flash,display,IBitmapDrawable)
HX_DECLARE_CLASS2(openfl,gl,GLObject)
HX_DECLARE_CLASS2(openfl,gl,GLTexture)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  Texture_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Texture_obj OBJ_;
		Texture_obj();
		Void __construct(::String url);

	public:
		static hx::ObjectPtr< Texture_obj > __new(::String url);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Texture_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Texture"); }

		virtual Void Bind( );
		Dynamic Bind_dyn();

		int texWidth;
		int texHeight;
		int height;
		int width;
		::flash::display::BitmapData bitmapData;
		::openfl::gl::GLTexture data;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_Texture */ 
