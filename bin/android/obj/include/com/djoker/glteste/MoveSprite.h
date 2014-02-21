#ifndef INCLUDED_com_djoker_glteste_MoveSprite
#define INCLUDED_com_djoker_glteste_MoveSprite

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <com/engine/direct/TileImage.h>
HX_DECLARE_CLASS3(com,djoker,glteste,MoveSprite)
HX_DECLARE_CLASS3(com,engine,direct,TileImage)
namespace com{
namespace djoker{
namespace glteste{


class HXCPP_CLASS_ATTRIBUTES  MoveSprite_obj : public ::com::engine::direct::TileImage_obj{
	public:
		typedef ::com::engine::direct::TileImage_obj super;
		typedef MoveSprite_obj OBJ_;
		MoveSprite_obj();
		Void __construct(Float x,Float y,int graph);

	public:
		static hx::ObjectPtr< MoveSprite_obj > __new(Float x,Float y,int graph);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~MoveSprite_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("MoveSprite"); }

		virtual Void move( Float dt);
		Dynamic move_dyn();

		virtual Void update( );

		virtual Void init( );
		Dynamic init_dyn();

		Float da;
		Float dy;
		Float dx;
};

} // end namespace com
} // end namespace djoker
} // end namespace glteste

#endif /* INCLUDED_com_djoker_glteste_MoveSprite */ 
