#pragma once
/**
@file Chunk.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/


class ChunkRepr;


/**@brief */
class Chunk
{
private:

	ChunkRepr*		m_chunkPtr;

protected:
public:
	explicit		Chunk() = default;
	~Chunk() = default;

};

