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
	,	m_file( nullptr )
	,	m_writePtr( 0 )
	,	m_attributesWritten( false )
{}

// ================================ //
//
ImplHCF::~ImplHCF()
{
	if( m_file )
		fclose( m_file );
	m_file = nullptr;
}

// ================================ //
//
Chunk			ImplHCF::GetRootChunk()
{
	return Chunk( m_rootChunk );
}

// ================================ //
//
bool			ImplHCF::OpenFile	( const filesystem::Path& filePath, bool writeDirect )
{
	m_file = fopen( filePath.String().c_str(), "wb" );
	
	if( m_file != nullptr )
	{
		m_directWrite = writeDirect;
		if( m_directWrite )
		{
			ReserveMemory( sizeof( FileHeader ) );
			m_header.FileSize = sizeof( FileHeader );
			m_header.RootChunkOffset = m_writePtr;

			// Write header to file. Header must be modified in future.
			fwrite( (void*)&m_header, sizeof( FileHeader ), 1, m_file );	// Should check result for safety.
		}

		return true;
	}
	
	return false;
}

// ================================ //
//
bool			ImplHCF::WriteFile	( const filesystem::Path& filePath )
{
	if( m_directWrite )
	{
		m_header.FileSize = m_writePtr;

		fseek( m_file, (long)0, SEEK_SET );
		fwrite( (void*)&m_header, sizeof( FileHeader ), 1, m_file );

		return true;
	}
	else
	{

	}

	return false;
}


// ================================ //
//
Chunk			ImplHCF::CreateRootChunk()
{
	if( !m_rootChunk )
	{
		if( m_directWrite )
		{
			m_header.RootChunkOffset = ReserveMemory( 0 );
			m_attributesWritten = true;
		}

		m_rootChunk = MakePtr< ChunkRepr >( this, nullptr );
		return Chunk( m_rootChunk );
	}
	else
		return Chunk( m_rootChunk );
}

// ================================ //
//
Attribute		ImplHCF::AddGlobalAttribute	( AttributeType type, const DataPtr data, Size dataSize )
{
	if( !m_rootChunk )
	{
		Attribute newAttribute = AddAttribute( m_fileAttributes, type, data, dataSize );

		// Move offset in file header.
		Size size = ComputeWholeSize( newAttribute );
		ReserveMemory( size );

		m_header.RootChunkOffset += size;
		m_header.FileSize += size;

		return newAttribute;
	}
	return Attribute();
}

// ================================ //
//
Attribute		ImplHCF::AddAttribute	( AttributeReprPtr& list, AttributeType type, const DataPtr data, Size dataSize )
{
	AttributeReprPtr attribRepr = MakePtr< AttributeRepr >( this, type );

	// Add attribute to list
	if( list )
		list->AddNextAttribute( attribRepr );
	else
		list = attribRepr;

	attribRepr->FillAttribute( data, dataSize );

	return Attribute( attribRepr );
}

// ================================ //
//
Size			ImplHCF::ComputeWholeSize	( Attribute attrib )
{
	return attrib.GetSize() + sizeof( AttributeHeader );
}


// ================================ //
//
Size			ImplHCF::ReserveMemory		( Size dataSize )
{
	Size curPtr = m_writePtr;
	m_writePtr += dataSize;
	
	return curPtr;
}

}	// sw
