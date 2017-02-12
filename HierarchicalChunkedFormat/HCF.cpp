/**
@file HCF.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/
#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"

#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"
#include "HCF.h"


namespace sw
{

//====================================================================================//
//			Loading and saving	
//====================================================================================//


// ================================ //
//
bool		HCF::LoadFile		( const filesystem::Path& filePath )
{
	return false;
}

// ================================ //
//
bool		HCF::Load			( DataPtr data, Size size )
{
	return false;
}

// ================================ //
//
bool		HCF::WriteFile		( const filesystem::Path& filePath )
{
	return false;
}

// ================================ //
//
Chunk		HCF::GetRootChunk	()
{
	return Chunk();
}


}	// sw
