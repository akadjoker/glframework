#ifndef INCLUDED_com_engine_render_Buffer
#define INCLUDED_com_engine_render_Buffer

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,math,Matrix)
HX_DECLARE_CLASS3(com,engine,math,Vector2)
HX_DECLARE_CLASS3(com,engine,render,Buffer)
namespace com{
namespace engine{
namespace render{


class HXCPP_CLASS_ATTRIBUTES  Buffer_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Buffer_obj OBJ_;
		Buffer_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Buffer_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Buffer_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Buffer"); }

		virtual Void dispose( );
		Dynamic dispose_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual Void combineMatrix( ::com::engine::math::Matrix m);
		Dynamic combineMatrix_dyn();

		virtual ::com::engine::math::Matrix getMatrix( );
		Dynamic getMatrix_dyn();

		Float rotation;
		Float scale;
		::com::engine::math::Vector2 position;
		::com::engine::math::Matrix viewMatrix;
};

} // end namespace com
} // end namespace engine
} // end namespace render

#endif /* INCLUDED_com_engine_render_Buffer */ 
