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
class ChunkRepr : public std::enable_shared_from_this< ChunkRepr >
{
private:
	ImplHCF*		m_hcf;

	ChunkHeader		m_header;

	Size			m_absolutOffset;	///< Offset from beginning of file.

	ChunkReprWPtr	m_parent;			///< Parent chunk.
	ChunkReprPtr	m_nextChunk;		///< Next chunk on the same nesting level.
	ChunkReprPtr	m_childChunk;		///< First child chunk.

	AttributeReprPtr	m_firstAttrib;	///< Attributes list.

private:
	/// Write only constructor.
	ChunkRepr					( ImplHCF* hcf, ChunkReprPtr& parent );
	/// Read constructor.
	ChunkRepr					( ImplHCF* hcf, ChunkReprPtr& parent, Size fileOffset );

public:
	static ChunkReprPtr		CreateFromFile	( ImplHCF* hcf, ChunkReprPtr parent, Size fileOffset );
	static ChunkReprPtr		Create			( ImplHCF* hcf, ChunkReprPtr parent );


	Chunk		CreateChunk		();

	/**@brief Gets next chunk on the same nesting level.
	@return Returns invalid chunk if there's no next chunk.*/
	Chunk		NextChunk		();

	/**@brief Gets first child chunk of this chunk.
	@return Returns invalid chunk if there's no children.*/
	Chunk		FirstChild		();

	/**@brief Check if you should call FirstChild or AccessData.*/
	bool		HasChildren		();

	/**@brief Get Chunks parent.
	@return Returned chunk can be invalid if this chunk is invalid or there's no parent.*/
	Chunk		ParentChunk		();


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
	void		UpdateHeader	();							///< Updates header in file using current info from m_header field.
};


}	// sw
