#include "swCommonLib/Tests/TestHCF/stdafx.h"
#include "swCommonLib/HierarchicalChunkedFormat/HCF.h"

#include "swCommonLib/External/Catch/catch.hpp"


using namespace sw;

TEST_CASE( "HCF - Write test" )
{
	sw::HCF hcf;

	Chunk rootChunk = hcf.GetRootChunk();
	Attribute attrib = rootChunk.AddAttribute( AttributeTypeBuiltIn::ChunkName );

	Chunk chunk1 = rootChunk.CreateChunk();
	Chunk chunk2 = rootChunk.CreateChunk();

	Chunk nested1 = chunk1.CreateChunk();
	Chunk nested2 = chunk1.CreateChunk();

	//chunk2.FillData( )

	hcf.WriteFile( "HCF/WriteTest.hcf" );
}

