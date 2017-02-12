/**
@file Attribute.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/
#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"


#include "Attribute.h"


namespace sw
{



// ================================ //
//
bool		Attribute::IsValid() const
{
	if( m_attribPtr )
		return true;
	return false;
}

}	// sw
