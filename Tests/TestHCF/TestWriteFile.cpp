#include "swCommonLib/Tests/TestHCF/stdafx.h"
#include "swCommonLib/HierarchicalChunkedFormat/HCF.h"

#include "swCommonLib/External/Catch/catch.hpp"


#include <numeric>


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

template<>
sw::AttributeType	GetAttributeTypeID< ExampleRealFormatHeader >() { return 0x10000;  }


using namespace sw;

TEST_CASE( "HCF - Simple write test" )
{
	std::vector< int > writeData( 2000 );
	std::iota( writeData.begin(), writeData.end(), 1 );

	sw::HCF hcf;
	bool openResult = hcf.OpenFile( "HCF/SimpleWriteTest.hcf", HCF::WriteMode::DirectToFile );
	REQUIRE( openResult );

	Attribute topAttribute = hcf.AddAttribute( ExampleRealFormatHeader() );
	CHECK( topAttribute.IsValid() );
	CHECK( topAttribute.GetType() == GetAttributeTypeID< ExampleRealFormatHeader >() );

	Chunk rootChunk = hcf.CreateRootChunk();
	REQUIRE( rootChunk.IsValid() );

	std::string rootChunkName = "rootChunk";
	Attribute attrib = rootChunk.AddAttribute( AttributeTypeBuiltIn::ChunkName, (const DataPtr)rootChunkName.c_str(), rootChunkName.length() + 1 );

	REQUIRE( attrib.IsValid() );

	Chunk chunk1 = rootChunk.CreateChunk();
	REQUIRE( chunk1.IsValid() );

	Chunk nested1 = chunk1.CreateChunk();
	REQUIRE( nested1.IsValid() );

	nested1.Fill( (const DataPtr)writeData.data(), sizeof( int ) * writeData.size() );


	Chunk nested2 = chunk1.CreateChunk();
	REQUIRE( nested2.IsValid() );
	
	nested2.Fill( (const DataPtr)writeData.data(), sizeof( int ) * writeData.size() );



	Chunk chunk2 = rootChunk.CreateChunk();
	REQUIRE( chunk2.IsValid() );

	chunk2.Fill( (const DataPtr)writeData.data(), sizeof( int ) * writeData.size() );

	bool result = hcf.WriteFile( "HCF/WriteTest.hcf" );

	CHECK( result );
}

