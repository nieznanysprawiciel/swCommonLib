/**
@file HCF.cpp
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/
#include "swCommonLib/HierarchicalChunkedFormat/stdafx.h"

#include "HCF.h"




namespace sw
{

//====================================================================================//
//			Loading and saving	
//====================================================================================//

// ================================ //
//
			HCF::HCF			()
{}

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
bool		HCF::OpenFile		( const filesystem::Path& filePath, WriteMode mode )
{
	return false;
}

// ================================ //
//
Chunk		HCF::GetRootChunk	()
{
	return Chunk();
}

// ================================ //
//
Chunk		HCF::CreateRootChunk()
{
	return Chunk();
}

// ================================ //
//
Attribute	HCF::AddAttribute		( AttributeType type, DataPtr data, Size dataSize )
{
	return m_impl.AddAttribute( type, data, dataSize );
}


}	// sw
