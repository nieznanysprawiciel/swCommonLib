#pragma once
/**
@file Key.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/TypesDefinitions.h"


/**@brief Animation key.
@ingroup KeyFrameAnimation*/
template< typename ValueType >
struct Key
{
	TimeType		Time;
	ValueType		Value;
};



const static TimeType epsilon = TimeType( 0.00001 );


// ================================ //
//
template< typename ValueType >
bool		operator<( const Key< ValueType >& first, const Key< ValueType >& second )
{
	if( first.Time < second.Time - epsilon )
		return true;
	return false;
}
