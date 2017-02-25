/**
@file ChunkRepr.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/
#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"

#include "swCommonLib/HierarchicalChunkedFormat/Internal/ImplHCF.h"
#include "ChunkRepr.h"


namespace sw
{

// ================================ //
//
ChunkRepr::ChunkRepr( ImplHCF* hcf, ChunkRepr* parent )
	:	m_hcf( hcf )
	,	m_parent( parent )
	,	m_absolutOffset( 0 )
{
	if( m_hcf->m_directWrite )
		m_absolutOffset = m_hcf->ReserveMemory( sizeof( ChunkHeader ) );
}

// ================================ //
//
ChunkRepr::ChunkRepr( ImplHCF* hcf, ChunkRepr* parent, Size fileOffset )
	:	m_hcf( hcf )
	,	m_parent( parent )
	,	m_absolutOffset( fileOffset )
{
	LoadHeader( m_absolutOffset );
}


// ================================ //
//
Chunk			ChunkRepr::CreateChunk		()
{
	if( CanCreateChunk() )
	{
		ChunkReprPtr newChunk = MakePtr< ChunkRepr >( m_hcf, this );

		m_header.HasChildren = true;

		if( m_childChunk )
			m_childChunk->AddNextChunk( newChunk );
		else
			m_childChunk = newChunk;

		return Chunk( newChunk );
	}
	return Chunk();
}

// ================================ //
//
Attribute		ChunkRepr::AddAttribute		( AttributeType type, const DataPtr data, Size dataSize )
{
	if( CanAddAttribute() )
	{
		Attribute newAttribute = m_hcf->AddAttribute( m_firstAttrib, type, data, dataSize );

		m_header.DataOffset += (uint32)m_hcf->ComputeWholeSize( newAttribute );
		m_header.NextChunk += m_hcf->ComputeWholeSize( newAttribute );

		return newAttribute;
	}

	// Return invalid attribute. Maybe exception ???
	return Attribute();
}

// ================================ //
//
bool			ChunkRepr::Fill				( const DataPtr data, Size dataSize )
{
	if( CanFillData() )
	{
		if( m_hcf->m_directWrite )
		{
			m_header.DataSize = dataSize;
			m_header.HasChildren = false;
			m_header.DataOffset = static_cast< uint32 >( m_hcf->ReserveMemory( dataSize ) - m_absolutOffset );

			auto file = m_hcf->GetFile();
			if( !file )
				throw std::runtime_error( "No file opened for writing." );

			fwrite( (void*)data, dataSize, 1, file );

			Size curPtr = m_hcf->ReserveMemory( 0 );
			WriteHeader( curPtr );

			return true;
		}
		else
		{

		}
	}

	return false;
}

// ================================ //
//
void			ChunkRepr::AddNextChunk		( ChunkReprPtr& newChunk )
{
	if( m_nextChunk )
		m_nextChunk->AddNextChunk( m_nextChunk );
	else
	{
		m_nextChunk = newChunk;
		m_header.NextChunk = newChunk->m_absolutOffset - m_absolutOffset;

		WriteHeader( newChunk->m_absolutOffset );
	}
}

// ================================ //
//
bool			ChunkRepr::CheckValidity	() const
{
	bool valid = true;

	if( !( m_header.ChunkHead[ 0 ] == 'C' &&
		m_header.ChunkHead[ 1 ] == 'H' && 
		m_header.ChunkHead[ 2 ] == 'N' ) )
	valid = false;

	return valid;
}


//====================================================================================//
//			Internal Helpers	
//====================================================================================//

// ================================ //
//
bool			ChunkRepr::CanAddAttribute	() const
{
	// You can always add attribute if we aren't in direct write mode.
	if( !m_hcf->m_directWrite )
		return true;

// In direct write mode:
	// Can't add attribute when child chunk or next chunk is already created.
	if( m_childChunk || m_nextChunk )
		return false;

	return true;
}

// ================================ //
//
bool			ChunkRepr::CanCreateChunk	() const
{
	// You can always create chunk if we aren't in direct write mode.
	if( !m_hcf->m_directWrite )
		return true;

	// Can't create child chunk if next chunk on the same level already exists.
	if( m_nextChunk )
		return false;

	return true;
}

// ================================ //
//
bool			ChunkRepr::CanFillData		() const
{
	// You can always create chunk if we aren't in direct write mode.
	if( !m_hcf->m_directWrite )
		return true;

	// Can't create child chunk if next chunk on the same level already exists.
	if( m_childChunk || m_nextChunk )
		return false;

	return true;
}

// ================================ //
//
void			ChunkRepr::WriteHeader		( Size revertOffset )
{
	auto file = m_hcf->GetFile();
	if( !file )
		throw std::runtime_error( "No file opened for writing." );

	fseek( file, (long)m_absolutOffset, SEEK_SET );
	fwrite( (void*)&m_header, sizeof( ChunkHeader ), 1, file );
	fseek( file, (long)revertOffset, SEEK_SET );
}

// ================================ //
//
void			ChunkRepr::LoadHeader		( Size revertOffset )
{
	auto file = m_hcf->GetFile();
	if( !file )
		throw std::runtime_error( "No file opened for reading." );

	fseek( file, (long)m_absolutOffset, SEEK_SET );
	fread( (void*)&m_header, sizeof( ChunkHeader ), 1, file );
	fseek( file, (long)revertOffset, SEEK_SET );
}

}	// sw
