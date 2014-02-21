#ifndef INCLUDED_com_engine_render_Image
#define INCLUDED_com_engine_render_Image

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,render,Clip)
HX_DECLARE_CLASS3(com,engine,render,Image)
HX_DECLARE_CLASS3(com,engine,render,Texture)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  Image_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Image_obj OBJ_;
		Image_obj();
		Void __construct(::com::engine::render::Texture Tex);

	public:
		static hx::ObjectPtr< Image_obj > __new(::com::engine::render::Texture Tex);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Image_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Image"); }

		bool flipY;
		bool flipX;
		::com::engine::render::Clip clip;
		int blendMode;
		::com::engine::render::Texture texture;
		Float originY;
		Float originX;
		Float scaleY;
		Float scaleX;
		Float angle;
		Float alpha;
		Float blue;
		Float green;
		Float red;
		Float y;
		Float x;
		Float height;
		Float width;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_Image */ 
