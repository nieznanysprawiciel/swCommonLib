#pragma once
/**
@file DefaultInterpolators.inl
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "DefaultInterpolators.h"

#include "LinearInterpolator.h"
#include "DiscreteInterpolator.h"


// ================================ //
//
template< typename KeyType >
inline UPtr< IInterpolator< KeyType > >			DefaultInterpolators::CreateLinear	( const Key< KeyType >& leftKey,
																					  const Key<KeyType>& rightKey,
																					  UPtr< const IInterpolator< KeyType > >& leftInterpolator,
																					  UPtr< const IInterpolator< KeyType > >& rightInterpolator )
{
	return UPtr< IInterpolator< KeyType > >( new LinearInterpolator< KeyType >( leftKey, rightKey, leftInterpolator, rightInterpolator ) );
}

