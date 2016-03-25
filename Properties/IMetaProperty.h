#pragma once

#include "Common/RTTR.h"


class IEnableProperty;

typedef RTTR::TypeInfo TypeInfo;


class IMetaProperty
{
private:
	
	const char*		m_name;		///< Nazwa w³aœciwoœci, po której mo¿na siê do niej odwo³ywaæ.
	TypeInfo		m_type;		///< Typ w³aœciwoœci identyfikowany wskaŸnikiem na strukturê typeinfo. (mo¿e siê zmieniæ w przysz³oœci)

	bool			m_serializable;
	bool			m_showInEditor;

public:
	IMetaProperty( const char* name, TypeInfo type )
		:	m_name( name )
		,	m_type( type )
	{}


	const char*		GetPropertyName()		{ return m_name; }
	TypeInfo		GetPropertyType()		{ return m_type; }
};


template< typename PropertyType >
class MetaProperty	:	public IMetaProperty
{
private:

	PropertyType IEnableProperty::*		m_memberPtr;	

public:
	MetaProperty( const char* name, TypeInfo type, PropertyType IEnableProperty::* memberPtr )
		:	IMetaProperty( name, type )
		,	m_memberPtr( memberPtr )
	{}


	PropertyType IEnableProperty::*	GetPtr()	{ return m_memberPtr; }
};


