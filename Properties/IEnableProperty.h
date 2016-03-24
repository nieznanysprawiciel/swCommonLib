#pragma once

class IProperty;


class IEnableProperty
{
public:
	
	IProperty*		GetProperty( const char* propertyName );

};