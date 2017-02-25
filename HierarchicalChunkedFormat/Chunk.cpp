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
	if( IsValid() )
		return m_chunkPtr->CreateChunk();
	return Chunk( nullptr );
}

// ================================ //
//
Attribute		Chunk::AddAttribute		( AttributeType type, const DataPtr data, Size dataSize )
{
	if( IsValid() )
		return m_chunkPtr->AddAttribute( type, data, dataSize );
	return Attribute( nullptr );
}

// ================================ //
//
bool			Chunk::Fill				( const DataPtr data, Size dataSize )
{
	if( IsValid() )
		return m_chunkPtr->Fill( data, dataSize );
	return false;
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
