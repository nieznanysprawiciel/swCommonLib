#pragma once

#include "Property.h"


class IEnableProperty
{
private:

	virtual IMetaProperty*		GetMetaProperty	( const char* propertyName ) = 0;

public:
	
	inline IProperty			GetProperty		( const char* propertyName )
	{
		IMetaProperty* metaProperty = GetMetaProperty( propertyName );
		return IProperty( metaProperty, this );
	}

	template< typename PropertyType >
	inline Property< PropertyType >		GetTypedProperty		( const char* propertyName )
	{
		IMetaProperty* metaProperty = GetMetaProperty( propertyName );
		// @todo Check types compatibility.

		return Property< PropertyType >( metaProperty, this );
	}
};