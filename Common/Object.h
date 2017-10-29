#pragma once
/**@file Object.h
@author nieznanysprawiciel
@copyright Plik jest czêœci¹ silnika graficznego SWEngine.

@brief */

#include "swCommonLib/Common/RTTR.h"
#include "swCommonLib/Common/TypesDefinitions.h"



/**@brief Base clas for all objects in sleeping wombat libraries.

Serialization functionality was moved to EngineObject class from Serialization library.

@todo Move to sw namespace.

@ingroup Reflection*/
class Object
{
	RTTR_ENABLE()

public:

	inline TypeID		GetType			() const		{ return this->get_type(); }
	inline std::string	GetTypeName		() const		{ return std::string( this->get_type().get_name() ); }


	/**@brief Returns memory size possesed by this class and all it's nested objects.
	Result shoulb be computed recursivly.*/
	virtual Size		MemorySize		() const;

	template< typename TargetType >
	TargetType*			DynamicCast		()							{ return rttr::rttr_cast< TargetType* >( this ); }
};

