#ifndef INCLUDED_com_engine_render_BlendMode
#define INCLUDED_com_engine_render_BlendMode

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,render,BlendMode)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  BlendMode_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef BlendMode_obj OBJ_;
		BlendMode_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< BlendMode_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~BlendMode_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("BlendMode"); }

		static int NORMAL;
		static int ADD;
		static int MULTIPLY;
		static int SCREEN;
		static Void setBlend( int mode);
		static Dynamic setBlend_dyn();

};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_BlendMode */ 
