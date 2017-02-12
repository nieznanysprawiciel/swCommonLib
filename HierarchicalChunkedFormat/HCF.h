#pragma once
/**
@file HCF.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Common/TypesDefinitions.h"
#include "swCommonLib/System/Path.h"

#include "swCommonLib/HierarchicalChunkedFormat/Attributes/IAttribute.h"
#include "Chunk.h"
#include "Attribute.h"

#include <string>


namespace sw
{


/**@brief Main class for loading and writing HCF files.*/
class HCF
{
private:
protected:
public:
	explicit		HCF	() = default;
					~HCF() = default;

///@name Loading and saving
///@{
	bool			LoadFile		( const filesystem::Path& filePath );
	bool			Load			( DataPtr data, Size size );

	bool			WriteFile		( const filesystem::Path& filePath );
	///@}

	Chunk			GetRootChunk	();

};


}	// sw
