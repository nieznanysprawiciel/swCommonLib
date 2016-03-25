#pragma once

#include "IMetaProperty.h"


class IEnableProperty;



class IProperty
{
protected:

	IMetaProperty*		m_metaInfo;
	IEnableProperty*	m_ownerObj;

public:

	IProperty( IMetaProperty* metaInfo, IEnableProperty* object )
		:	m_metaInfo( metaInfo )
		,	m_ownerObj( object )
	{}

	const char*		GetPropertyName()		{ return m_metaInfo->GetPropertyName(); }
	TypeId			GetPropertyType()		{ return m_metaInfo->GetPropertyType(); }

	bool			IsValid()				{ return m_metaInfo && m_ownerObj; }
};

template< typename PropertyType >
class Property	:	public IProperty
{
private:
public:

	Property( IMetaProperty* metaInfo, IEnableProperty* object )
		:	IProperty( metaInfo, object )
	{}

	PropertyType&		operator()( void )
	{
		auto typedProperty = static_cast< MetaProperty< PropertyType >* >( m_metaInfo );
		return m_ownerObj->*typedProperty->GetPtr();
	}
};
