#ifndef INCLUDED_openfl_utils_Int16Array
#define INCLUDED_openfl_utils_Int16Array

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <openfl/utils/ArrayBufferView.h>
HX_DECLARE_CLASS2(openfl,utils,ArrayBufferView)
HX_DECLARE_CLASS2(openfl,utils,IMemoryRange)
HX_DECLARE_CLASS2(openfl,utils,Int16Array)
namespace openfl{
namespace utils{


class HXCPP_CLASS_ATTRIBUTES  Int16Array_obj : public ::openfl::utils::ArrayBufferView_obj{
	public:
		typedef ::openfl::utils::ArrayBufferView_obj super;
		typedef Int16Array_obj OBJ_;
		Int16Array_obj();
		Void __construct(Dynamic bufferOrArray,hx::Null< int >  __o_start,Dynamic length);

	public:
		static hx::ObjectPtr< Int16Array_obj > __new(Dynamic bufferOrArray,hx::Null< int >  __o_start,Dynamic length);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		~Int16Array_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Int16Array"); }

		typedef int __array_access;
		virtual Void __set( int index,int value);
		Dynamic __set_dyn();

		virtual int __get( int index);
		Dynamic __get_dyn();

		int length;
		int BYTES_PER_ELEMENT;
		static int SBYTES_PER_ELEMENT;
};

} // end namespace openfl
} // end namespace utils

#endif /* INCLUDED_openfl_utils_Int16Array */ 
