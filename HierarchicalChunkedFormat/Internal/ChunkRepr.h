#pragma once
/**
@file ChunkRepr.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/HierarchicalChunkedFormat/Headers/ChunkHeader.h"
#include "swCommonLib/HierarchicalChunkedFormat/Internal/AttributeRepr.h"


namespace sw
{

class ChunkRepr;
DEFINE_PTR_TYPE( ChunkRepr );
DEFINE_WPTR_TYPE( ChunkRepr );


/**@brief */
class ChunkRepr
{
private:
	ChunkHeader		m_header;

	Size			m_absolutOffset;	///< Offset from beginning of file.

	ChunkReprWPtr	m_parent;			///< Parent chunk.
	ChunkReprPtr	m_nextChunk;		///< Next chunk on the same nesting level.
	ChunkReprPtr	m_childChunk;		///< First child chunk.

	AttributeReprPtr	m_firstAttrib;	///< Attributes list.

public:
};


}	// sw
