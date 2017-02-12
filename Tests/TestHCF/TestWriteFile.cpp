#include "swCommonLib/Tests/TestHCF/stdafx.h"
#include "swCommonLib/HierarchicalChunkedFormat/HCF.h"

#include "swCommonLib/External/Catch/catch.hpp"


TEST_CASE( "HCF - Write test" )
{
	sw::HCF hcf;

	//Chunk rootChunk = hcf.CreateChunk();
	//rootChunk.AddAttribute()

	//rootChunk.CreateChunk()
	//rootChunk.CreateChunk()

	hcf.WriteFile( "HCF/WriteTest.hcf" );
}

