#ifndef INCLUDED_com_engine_direct_Animation
#define INCLUDED_com_engine_direct_Animation

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

HX_DECLARE_CLASS3(com,engine,direct,Animation)
namespace com{
namespace engine{
namespace direct{


class HXCPP_CLASS_ATTRIBUTES  Animation_obj : public hx::Object{
	public:
		typedef hx::Object super;
		typedef Animation_obj OBJ_;
		Animation_obj();
		Void __construct(::String name,Array< int > frames,hx::Null< Float >  __o_frameRate,hx::Null< bool >  __o_loop);

	public:
		static hx::ObjectPtr< Animation_obj > __new(::String name,Array< int > frames,hx::Null< Float >  __o_frameRate,hx::Null< bool >  __o_loop);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Animation_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Animation"); }

		bool loop;
		int frameCount;
		Float frameRate;
		Array< int > frames;
		::String name;
};

} // end namespace com
} // end namespace engine
} // end namespace direct

#endif /* INCLUDED_com_engine_direct_Animation */ 
