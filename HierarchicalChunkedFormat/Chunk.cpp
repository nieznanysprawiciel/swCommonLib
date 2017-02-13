/**
@file Chunk.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"

#include "swCommonLib/HierarchicalChunkedFormat/Chunk.h"

namespace sw
{

// ================================ //
//
Chunk::Chunk		( ChunkReprPtr chunkRepr )
	:	m_chunkPtr( chunkRepr )
{}

// ================================ //
//
Chunk			Chunk::CreateChunk		()
{
	return Chunk();
}

// ================================ //
//
Attribute		Chunk::AddAttribute		( AttributeType type )
{
	return Attribute();
}

// ================================ //
//
bool			Chunk::IsValid() const
{
	if( m_chunkPtr )
		return true;
	return false;
}

}	// sw
