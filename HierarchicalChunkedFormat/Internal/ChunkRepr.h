#pragma once
/**
@file ChunkRepr.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/HierarchicalChunkedFormat/Headers/ChunkHeader.h"
#include "swCommonLib/HierarchicalChunkedFormat/Chunk.h"
#include "swCommonLib/HierarchicalChunkedFormat/Internal/AttributeRepr.h"
#include "swCommonLib/HierarchicalChunkedFormat/Attribute.h"


namespace sw
{

class ChunkRepr;
DEFINE_PTR_TYPE( ChunkRepr );
DEFINE_WPTR_TYPE( ChunkRepr );

class ImplHCF;


/**@brief */
class ChunkRepr
{
private:
	ImplHCF*		m_hcf;

	ChunkHeader		m_header;

	Size			m_absolutOffset;	///< Offset from beginning of file.

	ChunkRepr*		m_parent;			///< Parent chunk.
	ChunkReprPtr	m_nextChunk;		///< Next chunk on the same nesting level.
	ChunkReprPtr	m_childChunk;		///< First child chunk.

	AttributeReprPtr	m_firstAttrib;	///< Attributes list.

public:
	/// Write only constructor.
	ChunkRepr					( ImplHCF* hcf, ChunkRepr* parent );
	/// Read constructor.
	ChunkRepr					( ImplHCF* hcf, ChunkRepr* parent, Size fileOffset );

	Chunk		CreateChunk		();
	Attribute	AddAttribute	( AttributeType type, const DataPtr data, Size dataSize );
	bool		Fill			( const DataPtr data, Size dataSize );

	void		AddNextChunk	( ChunkReprPtr& newChunk );


	bool		CheckValidity	() const;

private:
	bool		CanAddAttribute	() const;
	bool		CanCreateChunk	() const;
	bool		CanFillData		() const;

	void		WriteHeader		( Size revertOffset );
	void		LoadHeader		( Size revertOffset );
};


}	// sw
