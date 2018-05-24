#pragma once

#include "swCommonLib/TestUtils/TestClassHierarchy/SerializationPrimitives/BaseObject.h"


namespace sw
{

// ================================ //
//
class PolymorphicObjectContainer
{
public:

	BaseObject*			ObjectPtr;

public:

	// ================================ //
	//
	explicit			PolymorphicObjectContainer()
		:	ObjectPtr( nullptr )
	{}

	// ================================ //
	//
	~PolymorphicObjectContainer()
	{
		delete ObjectPtr;
	}

};


}	// sw

