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


	/**@brief Create child chunk.*/
	Chunk		CreateChunk		();
	/**@brief Adds attribute to list.*/
	Attribute	AddAttribute	( AttributeType type );

	/**@brief Checks if you can use this attribute properly.*/
	bool		IsValid			() const;
};


}	// sw