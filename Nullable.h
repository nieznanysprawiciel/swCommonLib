#pragma once

#include <string>


template< typename ResultType >
struct Nullable
{
	ResultType		Value;
	bool			IsValid;
	std::string		ErrorString;

	Nullable()
	{
		IsValid = false;
	}

	Nullable( std::string&& error )
		: ErrorString( std::move( error ) )
	{
		IsValid = false;
	}

	Nullable( ResultType&& result )
		: Value( std::move( result ) )
	{
		IsValid = true;
	}


};

