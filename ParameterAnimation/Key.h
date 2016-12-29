#pragma once
/**
@file Key.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/TypesDefinitions.h"
#include "Interpolators/IInterpolator.h"

/**@defgroup Animation Animation
@ingroup EngineCore*/


/**@brief Key parameters.

Consist of key parameter value for and other key parameters like interpolator.
@ingroup Animation*/
template< typename ValueType >
struct KeyParam
{
	ValueType							Value;
	UPtr< IInterpolator< ValueType > >	Interpolator;
};



/**@brief Animation key.
@ingroup Animation*/
template< typename ValueType >
struct Key
{
	TimeType				Time;
	KeyParam< ValueType >	Param;
};
