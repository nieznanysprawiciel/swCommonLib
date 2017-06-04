#include "swCommonLib/External/Catch/catch.hpp"

#include "swCommonLib/System/Path.h"







TEST_CASE( "Path - Comparision operator" )
{
	filesystem::Path reference( "assets/wombat.jpg" );
	filesystem::Path difference( "assets/wombat2.jpg" );

	filesystem::Path newPath( reference );

	CHECK( reference == newPath );
	CHECK( reference.String() == newPath.String() );
	CHECK( reference.WString() == newPath.WString() );

	CHECK( difference != newPath );
	CHECK( difference.String() != newPath.String() );
	CHECK( difference.WString() != newPath.WString() );
}
