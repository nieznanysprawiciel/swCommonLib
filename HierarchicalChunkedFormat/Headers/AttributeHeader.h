#pragma once
/**
@file AttributeHeader.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Common/TypesDefinitions.h"


namespace sw
{

typedef uint64 AttributeType;


/**@brief */
struct AttributeHeader
{
	Size			AttribSize;		///< Size of attribute including this field.
	AttributeType	AttribType;		///< Attribute type. Low 16 bits are reserved fo built in attributes.
};


}	// sw
