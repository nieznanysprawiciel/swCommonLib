#pragma once
/**
@file ChunkHeader.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Common/TypesDefinitions.h"


/**@brief */
struct ChunkHeader
{
	Size			DataOffset;		///< Data or nested chunks.
	Size			NextChunk;		///< Offset to Next chunk on the same level.
};

