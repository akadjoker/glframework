#ifndef INCLUDED_com_engine_game_Transform
#define INCLUDED_com_engine_game_Transform

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(List)
HX_DECLARE_CLASS3(com,engine,game,Transform)
HX_DECLARE_CLASS2(flash,geom,Matrix)
namespace com{
namespace engine{
namespace game{


class HXCPP_CLASS_ATTRIBUTES  Transform_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Transform_obj OBJ_;
		Transform_obj();
		Void __construct();

	public:
		static hx::ObjectPtr< Transform_obj > __new();
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Transform_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Transform"); }

		virtual ::flash::geom::Matrix getLocalToWorldMatrix( );
		Dynamic getLocalToWorldMatrix_dyn();

		virtual ::flash::geom::Matrix getTransformationMatrix( );
		Dynamic getTransformationMatrix_dyn();

		virtual Void remove( ::com::engine::game::Transform child);
		Dynamic remove_dyn();

		virtual Void add( ::com::engine::game::Transform child);
		Dynamic add_dyn();

		Float scrollFactorY;
		Float scrollFactorX;
		Float y;
		Float x;
		Float pivotY;
		Float pivotX;
		Float skewY;
		Float skewX;
		Float scaleY;
		Float scaleX;
		Float rotation;
		bool isDirty;
		::List children;
		::com::engine::game::Transform parent;
		::flash::geom::Matrix mTransformationMatrix;
};

} // end namespace com
} // end namespace engine
} // end namespace game

#endif /* INCLUDED_com_engine_game_Transform */ 
