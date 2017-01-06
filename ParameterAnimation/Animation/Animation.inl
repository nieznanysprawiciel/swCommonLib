#pragma once
#include "Animation.h"


//====================================================================================//
//			Constructor	
//====================================================================================//

template< typename KeyType, typename AddressType  >
inline		AnimationImpl<  KeyType, AddressType  >::AnimationImpl( EngineObject* object, const std::string& propertyPath )
	:	Evaluator( object, propertyPath )
{}


//====================================================================================//
//			Keys manipulation	
//====================================================================================//

// ================================ //
//
template< typename KeyType, typename AddressType  >
inline bool			AnimationImpl<  KeyType, AddressType  >::AddKey		( TimeType time, const KeyType& value )
{
	return Evaluator.AddKey( time, value );
}

// ================================ //
//
template< typename KeyType, typename AddressType  >
inline bool			AnimationImpl< KeyType, AddressType >::AddKey		( TimeType time, const KeyType& value, UPtr< Interpolator >&& interpolator )
{
	return Evaluator.AddKey( time, value, std::move( interpolator ) );
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::UpdateKey	( TimeType time, const KeyType& newValue, UPtr< Interpolator >&& interpolator )
{
	return Evaluator.UpdateKey( time, newValue, std::move( interpolator ) );
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::UpdateKey	( TimeType time, const KeyType& newValue )
{
	return Evaluator.UpdateKey( time, newValue );
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::RemoveKey	( TimeType time )
{
	return Evaluator.RemoveKey( time );
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::UpdateInterpolator	( UPtr< Interpolator >&& interpolator )
{
	return Evaluator.UpdateInterpolator( std::move( interpolator ) );
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline const Key< KeyType >*	AnimationImpl< KeyType, AddressType >::GetKey	( TimeType time )
{
	return Evaluator.GetKey( time );
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline KeySet< KeyType >&		AnimationImpl< KeyType, AddressType >::GetKeySet()
{
	return Evaluator.GetKeySet();
}

