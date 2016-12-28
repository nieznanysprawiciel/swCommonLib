#pragma once

#include "Common/EngineObject.h"
#include "Common/RTTR.h"


class Properties
{
private:
public:


	static std::pair< rttr::variant, rttr::property >		GetProperty	( EngineObject* object, const std::string& propertyPath, char separator = '/' );
	static std::pair< rttr::variant, rttr::property >		GetProperty	( rttr::variant object, const std::string& propertyPath, Size offset = 0, char separator = '/' );

	static rttr::property			EmptyProperty	();
};


