#pragma once

#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/StructWithSimpleTypes.h"


namespace sw
{

// ================================ //
//
struct StructWithSimpleTypesShared : public StructWithSimpleTypes
{};

DEFINE_PTR_TYPE( StructWithSimpleTypesShared )

}	// sw

