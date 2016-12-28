#pragma once
/**
@file ParamAddress.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/




/**@brief */
template< typename KeyType >
class ParamAddress
{
public:

	static rttr::property		GetProperty	( EngineObject* object, const std::string& propertyPath, Size offset = 0, char separator = '/' );
	static rttr::property		GetProperty	( rttr::variant object, const std::string& propertyPath, Size offset = 0, char separator = '/' );
};



// ================================ //
//
template< typename KeyType >
inline rttr::property		ParamAddress< KeyType >::GetProperty( EngineObject* object, const std::string& propertyPath, Size offset, char separator )
{
	TypeID realType = object->GetType();

	Size propertyEnd = propertyPath.find_first_of( separator, offset );
	if( propertyEnd != std::string::npos )
	{
	
	}

	return rttr::property( nullptr );
}
