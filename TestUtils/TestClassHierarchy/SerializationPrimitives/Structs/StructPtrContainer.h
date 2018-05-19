#pragma once

#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/StructWithSimpleTypes.h"



namespace sw
{

// ================================ //
//
class StructPtrContainer
{
public:

	StructWithSimpleTypes*		SimpleStruct;

public:

	explicit		StructPtrContainer	();
					~StructPtrContainer	();

	void			Replace				( StructWithSimpleTypes* simpleStruct );
};

//====================================================================================//
//			Implementation	
//====================================================================================//

// ================================ //
//
inline StructPtrContainer::StructPtrContainer()
	:	SimpleStruct( new StructWithSimpleTypes )
{}

// ================================ //
//
inline StructPtrContainer::~StructPtrContainer()
{
	delete SimpleStruct;
}

// ================================ //
//
inline void			StructPtrContainer::Replace		( StructWithSimpleTypes* simpleStruct )
{
	delete SimpleStruct;
	SimpleStruct = simpleStruct;
}

}	// sw

