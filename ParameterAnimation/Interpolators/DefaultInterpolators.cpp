/**
@file DefaultInterpolators.cpp
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "DefaultInterpolators.h"
#include "DefaultInterpolators.inl"

#include "LinearInterpolator.h"
#include "DiscreteInterpolator.h"

namespace DefaultInterpolators
{

//====================================================================================//
//			Instantiantions	
//====================================================================================//

#define DEFINE_SPECIALIZATION( type, Function )																	\
template																										\
UPtr< IInterpolator< type > >		Function< type >( const Key< type >& leftKey,								\
													  const Key< type >& rightKey,								\
													  UPtr< const IInterpolator< type > >& leftInterpolator,	\
													  UPtr< const IInterpolator< type > >& rightInterpolator );

DEFINE_SPECIALIZATION( float, CreateLinear );
DEFINE_SPECIALIZATION( double, CreateLinear );
DEFINE_SPECIALIZATION( char, CreateLinear );
DEFINE_SPECIALIZATION( uint8, CreateLinear );
DEFINE_SPECIALIZATION( int8, CreateLinear );
DEFINE_SPECIALIZATION( uint16, CreateLinear );
DEFINE_SPECIALIZATION( int16, CreateLinear );
DEFINE_SPECIALIZATION( uint32, CreateLinear );
DEFINE_SPECIALIZATION( int32, CreateLinear );
DEFINE_SPECIALIZATION( uint64, CreateLinear );
DEFINE_SPECIALIZATION( int64, CreateLinear );


}	// DefaultInterpolators

