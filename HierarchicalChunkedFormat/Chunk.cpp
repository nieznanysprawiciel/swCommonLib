/**
@file Chunk.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"

#include "swCommonLib/HierarchicalChunkedFormat/Chunk.h"
#include "swCommonLib/HierarchicalChunkedFormat/Internal/ChunkRepr.h"

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
	return m_chunkPtr->CreateChunk();
}

// ================================ //
//
Attribute		Chunk::AddAttribute		( AttributeType type, const DataPtr data, Size dataSize )
{
	return m_chunkPtr->AddAttribute( type, data, dataSize );
}

// ================================ //
//
bool			Chunk::Fill				( const DataPtr data, Size dataSize )
{
	return m_chunkPtr->Fill( data, dataSize );
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
