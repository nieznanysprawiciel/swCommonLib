#pragma once
/**
@file DefaultInterpolators.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/


#include "IInterpolator.h"
#include "Common/ParameterAnimation/Key.h"


/**@brief Interpolators helpers functions.*/
namespace DefaultInterpolators
{

	template< typename KeyType >
	UPtr< IInterpolator< KeyType > >	CreateLinear	( const Key< KeyType >& leftKey,
														  const Key< KeyType >& rightKey,
														  UPtr< const IInterpolator< KeyType > >& leftInterpolator,
														  UPtr< const IInterpolator< KeyType > >& rightInterpolator );

	template< typename KeyType >
	UPtr< IInterpolator< KeyType > >	CreatePoint		( const Key< KeyType >& leftKey,
														  const Key< KeyType >& rightKey,
														  UPtr< const IInterpolator< KeyType > >& leftInterpolator,
														  UPtr< const IInterpolator< KeyType > >& rightInterpolator );

	/**@brief Function for creating default interpolators for different types of keys.
	Specialize this template in .cpp file.
	
	@note Left or right interpolator can be nullptr, but keys always exist.*/
	template< typename KeyType >
	UPtr< IInterpolator< typename std::enable_if< !std::is_floating_point< KeyType >::value, KeyType >::type > >
		Create		( const Key< KeyType >& leftKey,
					  const Key< KeyType >& rightKey,
					  UPtr< const IInterpolator< KeyType > >& leftInterpolator,
					  UPtr< const IInterpolator< KeyType > >& rightInterpolator );

	template< typename KeyType >
	UPtr< IInterpolator< typename std::enable_if< std::is_floating_point< KeyType >::value, KeyType >::type > >
		Create		( const Key< KeyType >& leftKey,
					  const Key< KeyType >& rightKey,
					  UPtr< const IInterpolator< KeyType > >& leftInterpolator,
					  UPtr< const IInterpolator< KeyType > >& rightInterpolator );


//====================================================================================//
//			Specialization declarations	
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

//====================================================================================//
//			Implementation	
//====================================================================================//

// ================================ //
//
template< typename KeyType >
inline UPtr< IInterpolator< typename std::enable_if< !std::is_floating_point< KeyType >::value, KeyType >::type > >
	Create		( const Key< KeyType >& leftKey,
					const Key<KeyType>& rightKey,
					UPtr< const IInterpolator< KeyType > >& leftInterpolator,
					UPtr< const IInterpolator< KeyType > >& rightInterpolator )
{
	static_assert( false, "Implement specialization" );
	return UPtr<IInterpolator<KeyType>>();
}


// ================================ //
//
template< typename KeyType >
inline UPtr< IInterpolator< typename std::enable_if< std::is_floating_point< KeyType >::value, KeyType >::type > >
	Create		( const Key< KeyType >& leftKey,
					const Key<KeyType>& rightKey,
					UPtr< const IInterpolator< KeyType > >& leftInterpolator,
					UPtr< const IInterpolator< KeyType > >& rightInterpolator )
{
	return CreateLinear( leftKey, rightKey, leftInterpolator, rightInterpolator );
}



}	// DefaultInterpolators
