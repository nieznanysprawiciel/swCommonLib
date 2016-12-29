#pragma once
/**
@file KeySet.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/


#include "Key.h"

#include <vector>
#include <algorithm>


/**@brief Set of animation keys.
@ingroup Animation*/
template< typename KeyType >
struct KeySet
{
public:
	typedef IInterpolator< KeyType > Interpolator;
public:
	std::vector< Key< KeyType > >		Keys;
	//std::vector< UPtr< Interpolator >	Interpolators;

public:
	explicit		KeySet	();

	Key< KeyType >&			GetKey	( TimeType time );
	void					AddKey	( TimeType time, KeyType& value );
};


//====================================================================================//
//			Implementation	
//====================================================================================//

// ================================ //
//
template< typename KeyType >
inline					KeySet< KeyType >::KeySet()
{
	Key< KeyType > firstKey;
	firstKey.Time = TimeType( 0.0 );
	firstKey.Param.Value = KeyType();

	Keys.push_back( std::move( firstKey ) );
}

// ================================ //
//
template< typename KeyType >
Key< KeyType >&			KeySet< KeyType >::GetKey	( TimeType time )
{
	std::binary_search( Keys.begin(), Keys.end(), )
}

// ================================ //
//
template< typename KeyType >
void					KeySet< KeyType >::AddKey	( TimeType time, KeyType& value )
{

}

