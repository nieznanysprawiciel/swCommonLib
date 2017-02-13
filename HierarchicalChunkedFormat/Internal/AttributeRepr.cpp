/**
@file AttributeRepr.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/
#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"

#include "AttributeRepr.h"

namespace sw
{

// ================================ //
//
AttributeRepr::AttributeRepr( AttributeType type )
	:	m_header( AttributeHeader( type ) )
{}

// ================================ //
//
void		AttributeRepr::AddNextAttribute		( AttributeReprPtr& attribPtr )
{
	if( m_nextAttrib )
		m_nextAttrib->AddNextAttribute( attribPtr );
	else
		m_nextAttrib = attribPtr;
}

}	// sw

