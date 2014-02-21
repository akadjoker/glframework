#ifndef INCLUDED_com_engine_direct_TileImage
#define INCLUDED_com_engine_direct_TileImage

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS0(IMap)
HX_DECLARE_CLASS3(com,engine,direct,Animation)
HX_DECLARE_CLASS3(com,engine,direct,TileImage)
HX_DECLARE_CLASS2(flash,geom,Matrix)
HX_DECLARE_CLASS2(haxe,ds,StringMap)
namespace com{
namespace engine{
namespace direct{


class HXCPP_CLASS_ATTRIBUTES  TileImage_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef TileImage_obj OBJ_;
		TileImage_obj();
		Void __construct(Float x,Float y,int graph);

	public:
		static hx::ObjectPtr< TileImage_obj > __new(Float x,Float y,int graph);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~TileImage_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("TileImage"); }

		virtual ::String get_currentAnim( );
		Dynamic get_currentAnim_dyn();

		::String currentAnim;
		virtual int get_frameCount( );
		Dynamic get_frameCount_dyn();

		int frameCount;
		virtual int set_frame( int value);
		Dynamic set_frame_dyn();

		virtual int get_frame( );
		Dynamic get_frame_dyn();

		virtual Void updateAnim( Float elapsed);
		Dynamic updateAnim_dyn();

		virtual ::com::engine::direct::Animation play( ::String name,hx::Null< bool >  reset);
		Dynamic play_dyn();

		virtual ::com::engine::direct::Animation addFrames( ::String name,int minf,int maxf,hx::Null< Float >  frameRate,hx::Null< bool >  loop);
		Dynamic addFrames_dyn();

		virtual ::com::engine::direct::Animation add( ::String name,Array< int > frames,hx::Null< Float >  frameRate,hx::Null< bool >  loop);
		Dynamic add_dyn();

		virtual ::flash::geom::Matrix getMatrix( );
		Dynamic getMatrix_dyn();

		virtual Void kill( );
		Dynamic kill_dyn();

		virtual Void update( );
		Dynamic update_dyn();

		virtual Void destroy( );
		Dynamic destroy_dyn();

		virtual ::String set_name( ::String value);
		Dynamic set_name_dyn();

		virtual ::String get_name( );
		Dynamic get_name_dyn();

		int Graph;
		int Layer;
		::flash::geom::Matrix mTransformationMatrix;
		::com::engine::direct::TileImage mParent;
		::String mName;
		bool Visible;
		Float Blue;
		Float Green;
		Float Red;
		Float Alpha;
		Float Rotation;
		Float SkewY;
		Float SkewX;
		Float ScaleY;
		Float ScaleX;
		Float PivotY;
		Float PivotX;
		Float y;
		Float x;
		Float _timer;
		int _frame;
		int _index;
		::com::engine::direct::Animation _anim;
		::haxe::ds::StringMap _anims;
		int _frameCount;
		Float rate;
		Dynamic callbackFunc;
		Dynamic &callbackFunc_dyn() { return callbackFunc;}
		bool complete;
		int originY;
		int originX;
		int height;
		int width;
};

} // end namespace com
} // end namespace engine
} // end namespace direct

#endif /* INCLUDED_com_engine_direct_TileImage */ 
