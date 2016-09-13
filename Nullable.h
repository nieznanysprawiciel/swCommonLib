#pragma once

#include <string>




template< typename ResultType >
struct Nullable
{
	ResultType		Value;
	bool			IsValid;
	std::string		ErrorString;



	/**@brief Creates invalid object. Value fieled is default contructed.*/
	Nullable()
		:	IsValid( false )
		,	Value( ResultType() )
	{}


	/**@brief Creates invalid object and sets error string. Value fieled is default contructed.*/
	Nullable( std::string&& error )
		:	ErrorString( std::move( error ) )
		,	IsValid( false )
		,	Value( ResultType() )
	{}

	/**@brief Creates valid object.*/
	Nullable( ResultType&& result )
		:	Value( std::move( result ) )
		,	IsValid( true )
	{}

	bool operator!()
	{
		return !IsValid;
	}
};

#define ReturnIfInvalid( nullable )		if( !nullable.IsValid ) return std::move( nullable.ErrorString );

