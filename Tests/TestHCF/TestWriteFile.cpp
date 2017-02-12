#include "swCommonLib/Tests/TestHCF/stdafx.h"
#include "swCommonLib/HierarchicalChunkedFormat/HCF.h"

#include "swCommonLib/External/Catch/catch.hpp"


using namespace sw;

TEST_CASE( "HCF - Write test" )
{
	sw::HCF hcf;

	Chunk rootChunk = hcf.GetRootChunk();
	REQUIRE( rootChunk.IsValid() );

	Attribute attrib = rootChunk.AddAttribute( AttributeTypeBuiltIn::ChunkName );

	REQUIRE( attrib.IsValid() );

	Chunk chunk1 = rootChunk.CreateChunk();
	Chunk chunk2 = rootChunk.CreateChunk();

	REQUIRE( chunk1.IsValid() );
	REQUIRE( chunk2.IsValid() );

	Chunk nested1 = chunk1.CreateChunk();
	Chunk nested2 = chunk1.CreateChunk();

	REQUIRE( nested1.IsValid() );
	REQUIRE( nested2.IsValid() );

	//chunk2.FillData( )

	bool result = hcf.WriteFile( "HCF/WriteTest.hcf" );

	CHECK( result );
}

