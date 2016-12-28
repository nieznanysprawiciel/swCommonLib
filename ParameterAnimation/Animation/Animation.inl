#pragma once
#include "Animation.h"


//====================================================================================//
//			Constructor	
//====================================================================================//

template<  typename KeyType, typename AddressType  >
inline		AnimationImpl<  KeyType, AddressType  >::AnimationImpl( EngineObject* object, const std::string& propertyPath )
	:	Evaluator( object, propertyPath )
{}


//====================================================================================//
//			Keys manipulation	
//====================================================================================//

// ================================ //
//
template<  typename KeyType, typename AddressType  >
inline bool			AnimationImpl<  KeyType, AddressType  >::AddKey		( TimeType time, const KeyType& value )
{
	return false;
}

// ================================ //
//
template<  typename KeyType, typename AddressType  >
inline bool			AnimationImpl< KeyType, AddressType >::AddKey		( TimeType time, const KeyType& value, UPtr< Interpolator >&& interpolator )
{
	return false;
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::UpdateKey	( TimeType time, const KeyType& newValue, UPtr< Interpolator >&& interpolator )
{
	return false;
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::UpdateKey	( TimeType time, const KeyType& newValue )
{
	return false;
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::RemoveKey	( TimeType time )
{
	return false;
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline bool			AnimationImpl< KeyType, AddressType >::UpdateInterpolator	( UPtr< Interpolator >&& interpolator )
{
	return false;
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline const Key< KeyType >*	AnimationImpl< KeyType, AddressType >::GetKey	( TimeType time )
{
	return nullptr;
}

