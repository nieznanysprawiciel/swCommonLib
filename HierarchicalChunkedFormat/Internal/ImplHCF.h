#pragma once
/**
@file ImplHCF.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/


#include "ChunkRepr.h"
#include "AttributeRepr.h"

#include "swCommonLib/HierarchicalChunkedFormat/Chunk.h"
#include "swCommonLib/HierarchicalChunkedFormat/Attribute.h"

#include "swCommonLib/HierarchicalChunkedFormat/Headers/FileHeader.h"


namespace sw
{

/**@brief */
class ImplHCF
{
private:

	FileHeader			m_header;

	ChunkReprPtr		m_rootChunk;			///< Main Chunk.
	AttributeReprPtr	m_fileAttributes;		///< Top level attributes.

public:

	bool				m_directWrite : 1;

protected:
public:
	explicit		ImplHCF		();
					~ImplHCF	() = default;


	Chunk			GetRootChunk	();
	Chunk			CreateRootChunk	();

	Attribute		AddAttribute	( AttributeType type, DataPtr data, Size dataSize );
};


}	// sw
