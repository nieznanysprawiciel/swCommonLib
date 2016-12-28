#pragma once
/**
@file DirectProperty.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/RTTR.h"
#include "Common/EngineObject.h"

#include "Common/Properties/Properties.h"


/**@brief */
template< typename KeyType >
class DirectProperty
{
private:
	rttr::property		m_property;
	EngineObject*		m_object;		///< @todo Change to typed pointer some way.

protected:
public:
	/// Constructor for serialization.
	explicit		DirectProperty	();
	explicit		DirectProperty	( EngineObject* object, const std::string& propertyPath );
					~DirectProperty	() = default;

};

//====================================================================================//
//			Implementation	
//====================================================================================//

// ================================ //
//
template< typename KeyType >
inline			DirectProperty< KeyType >::DirectProperty()
	:	m_property( Properties::EmptyProperty() )
	,	m_object( nullptr )
{}


// ================================ //
//
template< typename KeyType >
inline			DirectProperty< KeyType >::DirectProperty	( EngineObject* object, const std::string& propertyPath )
	:	
{ }

