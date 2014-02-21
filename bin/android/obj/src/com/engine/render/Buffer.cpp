#include <hxcpp.h>

#ifndef INCLUDED_com_engine_math_Matrix
#include <com/engine/math/Matrix.h>
#endif
#ifndef INCLUDED_com_engine_math_Vector2
#include <com/engine/math/Vector2.h>
#endif
#ifndef INCLUDED_com_engine_render_Buffer
#include <com/engine/render/Buffer.h>
#endif
#ifndef INCLUDED_hxMath
#include <hxMath.h>
#endif
namespace com{
namespace engine{
namespace render{

Void Buffer_obj::__construct()
{
HX_STACK_PUSH("Buffer::new","com/engine/render/Buffer.hx",20);
{
	HX_STACK_LINE(21)
	this->position = ::com::engine::math::Vector2_obj::__new((int)0,(int)0);
	HX_STACK_LINE(22)
	this->rotation = (int)0;
	HX_STACK_LINE(23)
	this->scale = (int)1;
	struct _Function_1_1{
		inline static ::com::engine::math::Matrix Block( ::com::engine::render::Buffer_obj *__this){
			HX_STACK_PUSH("*::closure","com/engine/render/Buffer.hx",24);
			{
				HX_STACK_LINE(24)
				Float scale = __this->scale;		HX_STACK_VAR(scale,"scale");
				HX_STACK_LINE(24)
				Float theta = (Float((__this->rotation * ::Math_obj::PI)) / Float(180.0));		HX_STACK_VAR(theta,"theta");
				HX_STACK_LINE(24)
				Float c = ::Math_obj::cos(theta);		HX_STACK_VAR(c,"c");
				HX_STACK_LINE(24)
				Float s = ::Math_obj::sin(theta);		HX_STACK_VAR(s,"s");
				struct _Function_2_1{
					inline static ::com::engine::math::Matrix Block( ::com::engine::render::Buffer_obj *__this,Float &scale,Float &s,Float &c){
						HX_STACK_PUSH("*::closure","com/engine/render/Buffer.hx",24);
						{
							HX_STACK_LINE(24)
							Array< Float > array = Array_obj< Float >::__new().Add((c * scale)).Add((-(s) * scale)).Add((int)0).Add((int)0).Add((s * scale)).Add((c * scale)).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add(__this->position->x).Add(__this->position->y).Add((int)0).Add((int)1);		HX_STACK_VAR(array,"array");
							int offset = (int)0;		HX_STACK_VAR(offset,"offset");
							HX_STACK_LINE(24)
							::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
							HX_STACK_LINE(24)
							{
								HX_STACK_LINE(24)
								{
									HX_STACK_LINE(24)
									int _g = (int)0;		HX_STACK_VAR(_g,"_g");
									HX_STACK_LINE(24)
									while(((_g < (int)16))){
										HX_STACK_LINE(24)
										int index = (_g)++;		HX_STACK_VAR(index,"index");
										HX_STACK_LINE(24)
										result->m[index] = array->__get((index + offset));
									}
								}
								HX_STACK_LINE(24)
								result;
							}
							HX_STACK_LINE(24)
							return result;
						}
						return null();
					}
				};
				HX_STACK_LINE(24)
				return _Function_2_1::Block(__this,scale,s,c);
			}
			return null();
		}
	};
	HX_STACK_LINE(24)
	this->viewMatrix = _Function_1_1::Block(this);
}
;
	return null();
}

Buffer_obj::~Buffer_obj() { }

Dynamic Buffer_obj::__CreateEmpty() { return  new Buffer_obj; }
hx::ObjectPtr< Buffer_obj > Buffer_obj::__new()
{  hx::ObjectPtr< Buffer_obj > result = new Buffer_obj();
	result->__construct();
	return result;}

Dynamic Buffer_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Buffer_obj > result = new Buffer_obj();
	result->__construct();
	return result;}

Void Buffer_obj::dispose( ){
{
		HX_STACK_PUSH("Buffer::dispose","com/engine/render/Buffer.hx",40);
		HX_STACK_THIS(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,dispose,(void))

Void Buffer_obj::update( ){
{
		HX_STACK_PUSH("Buffer::update","com/engine/render/Buffer.hx",35);
		HX_STACK_THIS(this);
		struct _Function_1_1{
			inline static ::com::engine::math::Matrix Block( ::com::engine::render::Buffer_obj *__this){
				HX_STACK_PUSH("*::closure","com/engine/render/Buffer.hx",36);
				{
					HX_STACK_LINE(36)
					Float scale = __this->scale;		HX_STACK_VAR(scale,"scale");
					HX_STACK_LINE(36)
					Float theta = (Float((__this->rotation * ::Math_obj::PI)) / Float(180.0));		HX_STACK_VAR(theta,"theta");
					HX_STACK_LINE(36)
					Float c = ::Math_obj::cos(theta);		HX_STACK_VAR(c,"c");
					HX_STACK_LINE(36)
					Float s = ::Math_obj::sin(theta);		HX_STACK_VAR(s,"s");
					struct _Function_2_1{
						inline static ::com::engine::math::Matrix Block( ::com::engine::render::Buffer_obj *__this,Float &scale,Float &s,Float &c){
							HX_STACK_PUSH("*::closure","com/engine/render/Buffer.hx",36);
							{
								HX_STACK_LINE(36)
								Array< Float > array = Array_obj< Float >::__new().Add((c * scale)).Add((-(s) * scale)).Add((int)0).Add((int)0).Add((s * scale)).Add((c * scale)).Add((int)0).Add((int)0).Add((int)0).Add((int)0).Add((int)1).Add((int)0).Add(__this->position->x).Add(__this->position->y).Add((int)0).Add((int)1);		HX_STACK_VAR(array,"array");
								int offset = (int)0;		HX_STACK_VAR(offset,"offset");
								HX_STACK_LINE(36)
								::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
								HX_STACK_LINE(36)
								{
									HX_STACK_LINE(36)
									{
										HX_STACK_LINE(36)
										int _g = (int)0;		HX_STACK_VAR(_g,"_g");
										HX_STACK_LINE(36)
										while(((_g < (int)16))){
											HX_STACK_LINE(36)
											int index = (_g)++;		HX_STACK_VAR(index,"index");
											HX_STACK_LINE(36)
											result->m[index] = array->__get((index + offset));
										}
									}
									HX_STACK_LINE(36)
									result;
								}
								HX_STACK_LINE(36)
								return result;
							}
							return null();
						}
					};
					HX_STACK_LINE(36)
					return _Function_2_1::Block(__this,scale,s,c);
				}
				return null();
			}
		};
		HX_STACK_LINE(35)
		this->viewMatrix = _Function_1_1::Block(this);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,update,(void))

Void Buffer_obj::combineMatrix( ::com::engine::math::Matrix m){
{
		HX_STACK_PUSH("Buffer::combineMatrix","com/engine/render/Buffer.hx",31);
		HX_STACK_THIS(this);
		HX_STACK_ARG(m,"m");
		struct _Function_1_1{
			inline static ::com::engine::math::Matrix Block( ::com::engine::render::Buffer_obj *__this,::com::engine::math::Matrix &m){
				HX_STACK_PUSH("*::closure","com/engine/render/Buffer.hx",32);
				{
					HX_STACK_LINE(32)
					::com::engine::math::Matrix A = __this->viewMatrix;		HX_STACK_VAR(A,"A");
					HX_STACK_LINE(32)
					::com::engine::math::Matrix result = ::com::engine::math::Matrix_obj::__new();		HX_STACK_VAR(result,"result");
					HX_STACK_LINE(32)
					result->m[(int)0] = ((((A->m->__get((int)0) * m->m->__get((int)0)) + (A->m->__get((int)4) * m->m->__get((int)1))) + (A->m->__get((int)8) * m->m->__get((int)2))) + (A->m->__get((int)12) * m->m->__get((int)3)));
					HX_STACK_LINE(32)
					result->m[(int)1] = ((((A->m->__get((int)1) * m->m->__get((int)0)) + (A->m->__get((int)5) * m->m->__get((int)1))) + (A->m->__get((int)9) * m->m->__get((int)2))) + (A->m->__get((int)13) * m->m->__get((int)3)));
					HX_STACK_LINE(32)
					result->m[(int)2] = ((((A->m->__get((int)2) * m->m->__get((int)0)) + (A->m->__get((int)6) * m->m->__get((int)1))) + (A->m->__get((int)10) * m->m->__get((int)2))) + (A->m->__get((int)14) * m->m->__get((int)3)));
					HX_STACK_LINE(32)
					result->m[(int)3] = ((((A->m->__get((int)3) * m->m->__get((int)0)) + (A->m->__get((int)7) * m->m->__get((int)1))) + (A->m->__get((int)11) * m->m->__get((int)2))) + (A->m->__get((int)15) * m->m->__get((int)3)));
					HX_STACK_LINE(32)
					result->m[(int)4] = ((((A->m->__get((int)0) * m->m->__get((int)4)) + (A->m->__get((int)4) * m->m->__get((int)5))) + (A->m->__get((int)8) * m->m->__get((int)6))) + (A->m->__get((int)12) * m->m->__get((int)7)));
					HX_STACK_LINE(32)
					result->m[(int)5] = ((((A->m->__get((int)1) * m->m->__get((int)4)) + (A->m->__get((int)5) * m->m->__get((int)5))) + (A->m->__get((int)9) * m->m->__get((int)6))) + (A->m->__get((int)13) * m->m->__get((int)7)));
					HX_STACK_LINE(32)
					result->m[(int)6] = ((((A->m->__get((int)2) * m->m->__get((int)4)) + (A->m->__get((int)6) * m->m->__get((int)5))) + (A->m->__get((int)10) * m->m->__get((int)6))) + (A->m->__get((int)14) * m->m->__get((int)7)));
					HX_STACK_LINE(32)
					result->m[(int)7] = ((((A->m->__get((int)3) * m->m->__get((int)4)) + (A->m->__get((int)7) * m->m->__get((int)5))) + (A->m->__get((int)11) * m->m->__get((int)6))) + (A->m->__get((int)15) * m->m->__get((int)7)));
					HX_STACK_LINE(32)
					result->m[(int)8] = ((((A->m->__get((int)0) * m->m->__get((int)8)) + (A->m->__get((int)4) * m->m->__get((int)9))) + (A->m->__get((int)8) * m->m->__get((int)10))) + (A->m->__get((int)12) * m->m->__get((int)11)));
					HX_STACK_LINE(32)
					result->m[(int)9] = ((((A->m->__get((int)1) * m->m->__get((int)8)) + (A->m->__get((int)5) * m->m->__get((int)9))) + (A->m->__get((int)9) * m->m->__get((int)10))) + (A->m->__get((int)13) * m->m->__get((int)11)));
					HX_STACK_LINE(32)
					result->m[(int)10] = ((((A->m->__get((int)2) * m->m->__get((int)8)) + (A->m->__get((int)6) * m->m->__get((int)9))) + (A->m->__get((int)10) * m->m->__get((int)10))) + (A->m->__get((int)14) * m->m->__get((int)11)));
					HX_STACK_LINE(32)
					result->m[(int)11] = ((((A->m->__get((int)3) * m->m->__get((int)8)) + (A->m->__get((int)7) * m->m->__get((int)9))) + (A->m->__get((int)11) * m->m->__get((int)10))) + (A->m->__get((int)15) * m->m->__get((int)11)));
					HX_STACK_LINE(32)
					result->m[(int)12] = ((((A->m->__get((int)0) * m->m->__get((int)12)) + (A->m->__get((int)4) * m->m->__get((int)13))) + (A->m->__get((int)8) * m->m->__get((int)14))) + (A->m->__get((int)12) * m->m->__get((int)15)));
					HX_STACK_LINE(32)
					result->m[(int)13] = ((((A->m->__get((int)1) * m->m->__get((int)12)) + (A->m->__get((int)5) * m->m->__get((int)13))) + (A->m->__get((int)9) * m->m->__get((int)14))) + (A->m->__get((int)13) * m->m->__get((int)15)));
					HX_STACK_LINE(32)
					result->m[(int)14] = ((((A->m->__get((int)2) * m->m->__get((int)12)) + (A->m->__get((int)6) * m->m->__get((int)13))) + (A->m->__get((int)10) * m->m->__get((int)14))) + (A->m->__get((int)14) * m->m->__get((int)15)));
					HX_STACK_LINE(32)
					result->m[(int)15] = ((((A->m->__get((int)3) * m->m->__get((int)12)) + (A->m->__get((int)7) * m->m->__get((int)13))) + (A->m->__get((int)11) * m->m->__get((int)14))) + (A->m->__get((int)15) * m->m->__get((int)15)));
					HX_STACK_LINE(32)
					return result;
				}
				return null();
			}
		};
		HX_STACK_LINE(31)
		this->viewMatrix = _Function_1_1::Block(this,m);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Buffer_obj,combineMatrix,(void))

::com::engine::math::Matrix Buffer_obj::getMatrix( ){
	HX_STACK_PUSH("Buffer::getMatrix","com/engine/render/Buffer.hx",27);
	HX_STACK_THIS(this);
	HX_STACK_LINE(27)
	return this->viewMatrix;
}


HX_DEFINE_DYNAMIC_FUNC0(Buffer_obj,getMatrix,return )


Buffer_obj::Buffer_obj()
{
}

void Buffer_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Buffer);
	HX_MARK_MEMBER_NAME(rotation,"rotation");
	HX_MARK_MEMBER_NAME(scale,"scale");
	HX_MARK_MEMBER_NAME(position,"position");
	HX_MARK_MEMBER_NAME(viewMatrix,"viewMatrix");
	HX_MARK_END_CLASS();
}

void Buffer_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(rotation,"rotation");
	HX_VISIT_MEMBER_NAME(scale,"scale");
	HX_VISIT_MEMBER_NAME(position,"position");
	HX_VISIT_MEMBER_NAME(viewMatrix,"viewMatrix");
}

Dynamic Buffer_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { return scale; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"dispose") ) { return dispose_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { return rotation; }
		if (HX_FIELD_EQ(inName,"position") ) { return position; }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"getMatrix") ) { return getMatrix_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"viewMatrix") ) { return viewMatrix; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"combineMatrix") ) { return combineMatrix_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Buffer_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 5:
		if (HX_FIELD_EQ(inName,"scale") ) { scale=inValue.Cast< Float >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"rotation") ) { rotation=inValue.Cast< Float >(); return inValue; }
		if (HX_FIELD_EQ(inName,"position") ) { position=inValue.Cast< ::com::engine::math::Vector2 >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"viewMatrix") ) { viewMatrix=inValue.Cast< ::com::engine::math::Matrix >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Buffer_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("rotation"));
	outFields->push(HX_CSTRING("scale"));
	outFields->push(HX_CSTRING("position"));
	outFields->push(HX_CSTRING("viewMatrix"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("dispose"),
	HX_CSTRING("update"),
	HX_CSTRING("combineMatrix"),
	HX_CSTRING("getMatrix"),
	HX_CSTRING("rotation"),
	HX_CSTRING("scale"),
	HX_CSTRING("position"),
	HX_CSTRING("viewMatrix"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Buffer_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Buffer_obj::__mClass,"__mClass");
};

Class Buffer_obj::__mClass;

void Buffer_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("com.engine.render.Buffer"), hx::TCanCast< Buffer_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Buffer_obj::__boot()
{
}

} // end namespace com
} // end namespace engine
} // end namespace render
