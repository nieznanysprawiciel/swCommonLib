#pragma once
/**
@file Chunk.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Common/TypesDefinitions.h"
#include "swCommonLib/HierarchicalChunkedFormat/Attribute.h"
#include "swCommonLib/HierarchicalChunkedFormat/Attributes/AttributeTypes.h"

namespace sw
{

class ChunkRepr;
DEFINE_PTR_TYPE( ChunkRepr );


/**@brief */
class Chunk
{
private:

	ChunkReprPtr		m_chunkPtr;

protected:
public:
	explicit		Chunk() = default;
	~Chunk() = default;


	Chunk		CreateChunk		();
	Attribute	AddAttribute	( AttributeType type );
};


}	// sw
