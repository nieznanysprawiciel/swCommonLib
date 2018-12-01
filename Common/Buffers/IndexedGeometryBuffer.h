#pragma once
/**
@file IndexedGeometryBuffer.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/


#include "swCommonLib/Common/Buffers/BufferTyped.h"


namespace sw {
namespace geom
{


/**@brief Structure for storing indexed geometry in memory buffer.
Structure uses BufferTyped to store both index and vertex buffers.

@todo In future buffers should support custom allocators.*/
template< typename VertexType, typename IndexType >
struct IndexedGeometryBuffer
{
	BufferTyped< VertexType >		Verticies;
	BufferTyped< IndexType >		Indicies;



	// ================================ //
	//
	explicit IndexedGeometryBuffer	( Size numVerticies, Size numIndicies )
		: Verticies( numVerticies )
		, Indicies( numIndicies )
	{}
};



}	// geom
}	// sw

