#ifndef INCLUDED_com_djoker_glteste_Particle
#define INCLUDED_com_djoker_glteste_Particle

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/render/Image.h>
HX_DECLARE_CLASS3(com,djoker,glteste,Particle)
HX_DECLARE_CLASS3(com,engine,render,Image)
HX_DECLARE_CLASS3(com,engine,render,Texture)
namespace com{
namespace djoker{
namespace glteste{


class HXCPP_CLASS_ATTRIBUTES  Particle_obj : public ::com::engine::render::Image_obj{
	public:
		typedef ::com::engine::render::Image_obj super;
		typedef Particle_obj OBJ_;
		Particle_obj();
		Void __construct(::com::engine::render::Texture Tex);

	public:
		static hx::ObjectPtr< Particle_obj > __new(::com::engine::render::Texture Tex);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Particle_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Particle"); }

		virtual Void move( Float dt);
		Dynamic move_dyn();

		virtual Void Init( );
		Dynamic Init_dyn();

		Float da;
		Float dy;
		Float dx;
};

} // end namespace com
} // end namespace djoker
} // end namespace glteste

#endif /* INCLUDED_com_djoker_glteste_Particle */ 
