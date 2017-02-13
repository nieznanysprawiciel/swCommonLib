#include "swCommonLib/Tests/TestHCF/stdafx.h"
#include "swCommonLib/HierarchicalChunkedFormat/HCF.h"

#include "swCommonLib/External/Catch/catch.hpp"



struct ExampleRealFormatHeader
{
	char			HeaderLetters[ 3 ];
	Version			Version;

// ================================ //
//
	ExampleRealFormatHeader()
	{
		HeaderLetters[ 0 ] = 'B';
		HeaderLetters[ 1 ] = 'L';
		HeaderLetters[ 2 ] = 'A';

		Version.Major = 3;
		Version.Minor = 123;
		Version.Revision = 1111;
		Version.Build = 120542;
	}
};



using namespace sw;

TEST_CASE( "HCF - Write test" )
{
	sw::HCF hcf;
	bool openResult = hcf.OpenFile( "", HCF::WriteMode::DirectToFile );
	REQUIRE( openResult );

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

