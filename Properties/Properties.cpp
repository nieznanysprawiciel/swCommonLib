#include "Properties.h"




// ================================ //
//
std::pair< rttr::variant, rttr::property >		Properties::GetProperty		( EngineObject* object, const std::string& propertyPath, char separator )
{
	return GetProperty( rttr::variant( object ), propertyPath, 0, separator );
}

// ================================ //
//
std::pair< rttr::variant, rttr::property >		Properties::GetProperty		( rttr::variant object, const std::string& propertyPath, Size offset, char separator )
{
	TypeID realType = object.get_type();
	if( realType.is_derived_from< EngineObject >() )
		realType = object.get_value< EngineObject* >()->GetType();

	Size propertyEnd = propertyPath.find_first_of( separator, offset );
	if( propertyEnd != std::string::npos )
	{
		std::string propName = std::string( propertyPath.begin() + offset, propertyPath.begin() + propertyEnd );
		rttr::property resultProperty = realType.get_property( propName.c_str() );

		auto childObject = resultProperty.get_value( object );
		return GetProperty( childObject, propertyPath, propertyEnd + 1, separator );
	}
	else
	{
		std::string propName = std::string( propertyPath.begin() + offset, propertyPath.end() );
		rttr::property resultProperty = realType.get_property( propName.c_str() );

		if( !resultProperty.is_valid() )
			return std::make_pair( rttr::variant(), resultProperty );

		object.unsafe_convert_void( resultProperty.get_declaring_type_ptr() );

		return std::make_pair( object, resultProperty );
	}
}

// ================================ //
//
rttr::property			Properties::EmptyProperty()
{
	TypeID nullType = TypeID::get< void >();
	auto prop = nullType.get_property( "" );

	return prop;
}
