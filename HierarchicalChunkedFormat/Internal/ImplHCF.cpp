/**
@file ImplHCF.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/


#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"
#include "ImplHCF.h"


namespace sw
{

const Version currentVersion = "1.0.0.0";

// ================================ //
//
ImplHCF::ImplHCF()
	:	m_header( currentVersion )
{}

// ================================ //
//
Chunk			ImplHCF::GetRootChunk()
{
	return Chunk();
}

// ================================ //
//
Chunk			ImplHCF::CreateRootChunk()
{
	if( !m_rootChunk )
	{
		m_rootChunk = MakePtr< ChunkRepr >( this );
		return Chunk( m_rootChunk );
	}
	else
		return Chunk( m_rootChunk );
}

// ================================ //
//
Attribute		ImplHCF::AddAttribute	( AttributeType type, DataPtr data, Size dataSize )
{
	return Attribute();
}


}	// sw
