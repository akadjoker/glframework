#ifndef INCLUDED_com_engine_render_Clip
#define INCLUDED_com_engine_render_Clip

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,render,Clip)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  Clip_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Clip_obj OBJ_;
		Clip_obj();
		Void __construct(Dynamic __o_x,Dynamic __o_y,Dynamic __o_width,Dynamic __o_height);

	public:
		static hx::ObjectPtr< Clip_obj > __new(Dynamic __o_x,Dynamic __o_y,Dynamic __o_width,Dynamic __o_height);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Clip_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Clip"); }

		virtual Void set( int x,int y,int width,int height);
		Dynamic set_dyn();

		int height;
		int width;
		int y;
		int x;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_Clip */ 
