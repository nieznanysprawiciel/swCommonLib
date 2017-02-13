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
	return Chunk();
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
			m_header.FileSize = sizeof( FileHeader );
			m_writePtr = sizeof( FileHeader );
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
Attribute		ImplHCF::AddAttribute	( AttributeType type, const DataPtr data, Size dataSize )
{
	AttributeReprPtr attribRepr = MakePtr< AttributeRepr >( type );
	attribRepr->AccessHeader().AttribSize = dataSize + sizeof( AttributeHeader );

	// Add attribute to list
	if( m_fileAttributes )
		m_fileAttributes->AddNextAttribute( attribRepr );
	else
		m_fileAttributes = attribRepr;


	if( m_directWrite )
	{
		if( !m_file )
			throw std::runtime_error( "No file opened for writing." );

		fwrite( (void*)&attribRepr->AccessHeader(), sizeof( AttributeHeader ), 1, m_file );
		fwrite( data, dataSize, 1, m_file );
	}
	else
	{

	}

	return Attribute( attribRepr );
}


}	// sw
