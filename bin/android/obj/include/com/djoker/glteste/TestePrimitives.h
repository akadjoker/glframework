#ifndef INCLUDED_com_djoker_glteste_TestePrimitives
#define INCLUDED_com_djoker_glteste_TestePrimitives

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/game/Screen.h>
HX_DECLARE_CLASS3(com,djoker,glteste,TestePrimitives)
HX_DECLARE_CLASS3(com,engine,game,Screen)
HX_DECLARE_CLASS3(com,engine,game,Transform)
HX_DECLARE_CLASS3(com,engine,render,BatchPrimitives)
HX_DECLARE_CLASS3(com,engine,render,Buffer)
namespace com{
namespace djoker{
namespace glteste{


class HXCPP_CLASS_ATTRIBUTES  TestePrimitives_obj : public ::com::engine::game::Screen_obj{
	public:
		typedef ::com::engine::game::Screen_obj super;
		typedef TestePrimitives_obj OBJ_;
		TestePrimitives_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< TestePrimitives_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TestePrimitives_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TestePrimitives"); }

		virtual Void render( Float dt);

		virtual Void show( );

		::com::engine::render::BatchPrimitives batch;
};

} // end namespace com
} // end namespace djoker
} // end namespace glteste

#endif /* INCLUDED_com_djoker_glteste_TestePrimitives */ 
