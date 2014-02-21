#include <hxcpp.h>

#ifndef INCLUDED_Std
#include <Std.h>
#endif
#ifndef INCLUDED_StringTools
#include <StringTools.h>
#endif
#ifndef INCLUDED_Xml
#include <Xml.h>
#endif
#ifndef INCLUDED_XmlType
#include <XmlType.h>
#endif
#ifndef INCLUDED_haxe_xml_Fast
#include <haxe/xml/Fast.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_AttribAccess
#include <haxe/xml/_Fast/AttribAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_HasAttribAccess
#include <haxe/xml/_Fast/HasAttribAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_HasNodeAccess
#include <haxe/xml/_Fast/HasNodeAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeAccess
#include <haxe/xml/_Fast/NodeAccess.h>
#endif
#ifndef INCLUDED_haxe_xml__Fast_NodeListAccess
#include <haxe/xml/_Fast/NodeListAccess.h>
#endif
namespace haxe{
namespace xml{

Void Fast_obj::__construct(::Xml x)
{
HX_STACK_PUSH("Fast::new","C:\\HaxeToolkit\\haxe/std/haxe/xml/Fast.hx",122);
{
	HX_STACK_LINE(123)
	if (((bool((x->nodeType != ::Xml_obj::Document)) && bool((x->nodeType != ::Xml_obj::Element))))){
		HX_STACK_LINE(124)
		hx::Throw ((HX_CSTRING("Invalid nodeType ") + ::Std_obj::string(x->nodeType)));
	}
	HX_STACK_LINE(125)
	this->x = x;
	HX_STACK_LINE(126)
	this->node = ::haxe::xml::_Fast::NodeAccess_obj::__new(x);
	HX_STACK_LINE(127)
	this->nodes = ::haxe::xml::_Fast::NodeListAccess_obj::__new(x);
	HX_STACK_LINE(128)
	this->att = ::haxe::xml::_Fast::AttribAccess_obj::__new(x);
	HX_STACK_LINE(129)
	this->has = ::haxe::xml::_Fast::HasAttribAccess_obj::__new(x);
	HX_STACK_LINE(130)
	this->hasNode = ::haxe::xml::_Fast::HasNodeAccess_obj::__new(x);
}
;
	return null();
}

Fast_obj::~Fast_obj() { }

Dynamic Fast_obj::__CreateEmpty() { return  new Fast_obj; }
hx::ObjectPtr< Fast_obj > Fast_obj::__new(::Xml x)
{  hx::ObjectPtr< Fast_obj > result = new Fast_obj();
	result->__construct(x);
	return result;}

Dynamic Fast_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Fast_obj > result = new Fast_obj();
	result->__construct(inArgs[0]);
	return result;}

::String Fast_obj::get_innerData( ){
	HX_STACK_PUSH("Fast::get_innerData","C:\\HaxeToolkit\\haxe/std/haxe/xml/Fast.hx",137);
	HX_STACK_THIS(this);
	HX_STACK_LINE(138)
	Dynamic it = this->x->iterator();		HX_STACK_VAR(it,"it");
	HX_STACK_LINE(139)
	if ((!(it->__Field(HX_CSTRING("hasNext"),true)()))){
		HX_STACK_LINE(140)
		hx::Throw ((this->get_name() + HX_CSTRING(" does not have data")));
	}
	HX_STACK_LINE(141)
	::Xml v = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(v,"v");
	HX_STACK_LINE(142)
	::Xml n = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(n,"n");
	HX_STACK_LINE(143)
	if (((n != null()))){
		HX_STACK_LINE(145)
		if (((bool((bool((v->nodeType == ::Xml_obj::PCData)) && bool((n->nodeType == ::Xml_obj::CData)))) && bool((::StringTools_obj::trim(v->get_nodeValue()) == HX_CSTRING("")))))){
			HX_STACK_LINE(146)
			::Xml n2 = it->__Field(HX_CSTRING("next"),true)();		HX_STACK_VAR(n2,"n2");
			HX_STACK_LINE(147)
			if (((bool((n2 == null())) || bool((bool((bool((n2->nodeType == ::Xml_obj::PCData)) && bool((::StringTools_obj::trim(n2->get_nodeValue()) == HX_CSTRING(""))))) && bool((it->__Field(HX_CSTRING("next"),true)() == null()))))))){
				HX_STACK_LINE(148)
				return n->get_nodeValue();
			}
		}
		HX_STACK_LINE(150)
		hx::Throw ((this->get_name() + HX_CSTRING(" does not only have data")));
	}
	HX_STACK_LINE(152)
	if (((bool((v->nodeType != ::Xml_obj::PCData)) && bool((v->nodeType != ::Xml_obj::CData))))){
		HX_STACK_LINE(153)
		hx::Throw ((this->get_name() + HX_CSTRING(" does not have data")));
	}
	HX_STACK_LINE(154)
	return v->get_nodeValue();
}


HX_DEFINE_DYNAMIC_FUNC0(Fast_obj,get_innerData,return )

::String Fast_obj::get_name( ){
	HX_STACK_PUSH("Fast::get_name","C:\\HaxeToolkit\\haxe/std/haxe/xml/Fast.hx",133);
	HX_STACK_THIS(this);
	HX_STACK_LINE(133)
	return (  (((this->x->nodeType == ::Xml_obj::Document))) ? ::String(HX_CSTRING("Document")) : ::String(this->x->get_nodeName()) );
}


HX_DEFINE_DYNAMIC_FUNC0(Fast_obj,get_name,return )


Fast_obj::Fast_obj()
{
}

void Fast_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(Fast);
	HX_MARK_MEMBER_NAME(hasNode,"hasNode");
	HX_MARK_MEMBER_NAME(has,"has");
	HX_MARK_MEMBER_NAME(att,"att");
	HX_MARK_MEMBER_NAME(nodes,"nodes");
	HX_MARK_MEMBER_NAME(node,"node");
	HX_MARK_MEMBER_NAME(x,"x");
	HX_MARK_END_CLASS();
}

void Fast_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(hasNode,"hasNode");
	HX_VISIT_MEMBER_NAME(has,"has");
	HX_VISIT_MEMBER_NAME(att,"att");
	HX_VISIT_MEMBER_NAME(nodes,"nodes");
	HX_VISIT_MEMBER_NAME(node,"node");
	HX_VISIT_MEMBER_NAME(x,"x");
}

Dynamic Fast_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { return x; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"has") ) { return has; }
		if (HX_FIELD_EQ(inName,"att") ) { return att; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { return node; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nodes") ) { return nodes; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasNode") ) { return hasNode; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"get_name") ) { return get_name_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"get_innerData") ) { return get_innerData_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Fast_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 1:
		if (HX_FIELD_EQ(inName,"x") ) { x=inValue.Cast< ::Xml >(); return inValue; }
		break;
	case 3:
		if (HX_FIELD_EQ(inName,"has") ) { has=inValue.Cast< ::haxe::xml::_Fast::HasAttribAccess >(); return inValue; }
		if (HX_FIELD_EQ(inName,"att") ) { att=inValue.Cast< ::haxe::xml::_Fast::AttribAccess >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"node") ) { node=inValue.Cast< ::haxe::xml::_Fast::NodeAccess >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"nodes") ) { nodes=inValue.Cast< ::haxe::xml::_Fast::NodeListAccess >(); return inValue; }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"hasNode") ) { hasNode=inValue.Cast< ::haxe::xml::_Fast::HasNodeAccess >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Fast_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("hasNode"));
	outFields->push(HX_CSTRING("has"));
	outFields->push(HX_CSTRING("att"));
	outFields->push(HX_CSTRING("nodes"));
	outFields->push(HX_CSTRING("node"));
	outFields->push(HX_CSTRING("x"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

static ::String sMemberFields[] = {
	HX_CSTRING("get_innerData"),
	HX_CSTRING("get_name"),
	HX_CSTRING("hasNode"),
	HX_CSTRING("has"),
	HX_CSTRING("att"),
	HX_CSTRING("nodes"),
	HX_CSTRING("node"),
	HX_CSTRING("x"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Fast_obj::__mClass,"__mClass");
};

static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Fast_obj::__mClass,"__mClass");
};

Class Fast_obj::__mClass;

void Fast_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("haxe.xml.Fast"), hx::TCanCast< Fast_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics, sVisitStatics);
}

void Fast_obj::__boot()
{
}

} // end namespace haxe
} // end namespace xml
