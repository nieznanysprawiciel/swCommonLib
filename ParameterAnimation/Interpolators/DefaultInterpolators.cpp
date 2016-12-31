/**
@file DefaultInterpolators.cpp
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "DefaultInterpolators.h"
#include "DefaultInterpolators.inl"

#include "LinearInterpolator.h"
#include "PointInterpolator.h"

namespace DefaultInterpolators
{

//====================================================================================//
//			Instantiantions	
//====================================================================================//

template
UPtr< IInterpolator< float > >		CreateLinear< float >( const Key< float >& leftKey,
														   const Key< float >& rightKey,
														   UPtr< const IInterpolator< float > >& leftInterpolator,
														   UPtr< const IInterpolator< float > >& rightInterpolator );

template
UPtr< IInterpolator< double > >		CreateLinear< double >( const Key< double >& leftKey,
															const Key< double >& rightKey,
															UPtr< const IInterpolator< double > >& leftInterpolator,
															UPtr< const IInterpolator< double > >& rightInterpolator );




}	// DefaultInterpolators

