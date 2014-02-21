#ifndef INCLUDED_com_engine_direct_SpriteClip
#define INCLUDED_com_engine_direct_SpriteClip

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,direct,SpriteClip)
namespace com{
namespace engine{
namespace direct{


class HXCPP_CLASS_ATTRIBUTES  SpriteClip_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef SpriteClip_obj OBJ_;
		SpriteClip_obj();
		Void __construct(int x,int y,int width,int height,int offsetX,int offsetY);

	public:
		static hx::ObjectPtr< SpriteClip_obj > __new(int x,int y,int width,int height,int offsetX,int offsetY);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~SpriteClip_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("SpriteClip"); }

		int y;
		int x;
		int width;
		int offsetY;
		int offsetX;
		int height;
};

} // end namespace com
} // end namespace engine
} // end namespace direct

#endif /* INCLUDED_com_engine_direct_SpriteClip */ 
