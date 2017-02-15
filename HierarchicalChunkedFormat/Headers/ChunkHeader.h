#pragma once
/**
@file ChunkHeader.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Common/TypesDefinitions.h"


namespace sw
{


/**@brief */
struct ChunkHeader
{
	Size			DataOffset;		///< Data or nested chunks.
	Size			NextChunk;		///< Offset to Next chunk on the same level.

// ================================ //
//
	ChunkHeader()
		: DataOffset( 0 )
		, NextChunk( 0 )
	{ }

};

}	// sw
