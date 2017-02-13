#pragma once

#include "HCF.h"


namespace sw
{

// ================================ //
//
template< typename AttributeStruct >
inline Attribute			HCF::AddAttribute	( AttributeType type, const AttributeStruct& content )
{
	return Attribute();
}

// ================================ //
//
template< typename AttributeStruct >
inline Attribute			HCF::AddAttribute	( const AttributeStruct& content )
{
	return Attribute();
}



}	// sw

