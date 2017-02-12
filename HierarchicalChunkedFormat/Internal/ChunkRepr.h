#pragma once
/**
@file ChunkRepr.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/HierarchicalChunkedFormat/Headers/ChunkHeader.h"


namespace sw
{

class ChunkRepr;
DEFINE_PTR_TYPE( ChunkRepr );
DEFINE_WPTR_TYPE( ChunkRepr );


/**@brief */
class ChunkRepr
{
	ChunkHeader		m_header;

	ChunkReprWPtr	m_parent;			///< Parent chunk.
	ChunkReprPtr	m_nextChunk;		///< Next chunk on the same nesting level.
	ChunkReprPtr	m_childChunk;		///<
};


}	// sw
