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
	explicit		Chunk	() = default;
	explicit		Chunk	( ChunkReprPtr chunkRepr );
	~Chunk() = default;


	/**@brief Create child chunk.*/
	Chunk		CreateChunk		();


	/**@brief Fills chunk with data.
	You can fill only chunks without children. One filled chunk, can't add children anymore.*/
	bool		Fill			( const DataPtr data, Size dataSize );

	/**@brief Checks if you can use this attribute properly.*/
	bool		IsValid			() const;

	///@name Attributes manipulation
	///@{
	/**@brief Adds attribute and fills it with data.*/
	Attribute		AddAttribute	( AttributeType type, const DataPtr data, Size dataSize );

	/**@brief Adds attribute and creates content from POD structure.
	@param[in] type You must provide type of attribute by yourself. Use second spetialization if struct
	defines attribute type getter.*/
	template< typename AttributeStruct >
	Attribute		AddAttribute	( AttributeType type, const AttributeStruct& content );

	/**@brief Adds attribute and creates content from POD structure.
	Attribute type will be taken from struct. Specialize GetAttributeTypeID template.*/
	template< typename AttributeStruct >
	Attribute		AddAttribute	( const AttributeStruct& content );
	///@}
};

//====================================================================================//
//			Implementation	
//====================================================================================//


// ================================ //
//
template< typename AttributeStruct >
inline Attribute			Chunk::AddAttribute	( AttributeType type, const AttributeStruct& content )
{
	if( IsValid() )
		return m_chunkPtr->AddAttribute( type, (const DataPtr)&content, sizeof( AttributeStruct ) );
	return Attribute( nullptr );
}

// ================================ //
//
template< typename AttributeStruct >
inline Attribute			Chunk::AddAttribute	( const AttributeStruct& content )
{
	if( IsValid() )
		return AddAttribute( GetAttributeTypeID< AttributeStruct >(), content );
	return Attribute( nullptr );
}


}	// sw
