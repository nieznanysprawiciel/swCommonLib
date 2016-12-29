#pragma once
/**
@file AnimEvaluator.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/EngineObject.h"

#include "Common/ParameterAnimation/KeySet.h"
#include "Common/ParameterAnimation/Timelines/TimelineBase.h"



/**@brief */
template< typename KeyType, typename AddressType >
class AnimEvaluator
{
public:
	typedef IInterpolator< KeyType > Interpolator;
private:
	KeySet< KeyType >			m_keys;
	AddressType					m_param;

protected:
public:
	/// Constructor for serialization only.
	explicit		AnimEvaluator	() = default;
	explicit		AnimEvaluator	( EngineObject* object, const std::string& propertyPath );
					~AnimEvaluator	() = default;


	void				Evaluate	( EngineObject* object, TimeType time );
	void				Evaluate	( EngineObject* object, TimelineBase* timeline );


	/**@brief Adds key and sets default interpolator.
	@return False if key already exists.*/
	bool	AddKey			( TimeType time, const KeyType& value );
	/**@brief Adds key and sets given interpolator.
	@return False if key already exists.*/
	bool	AddKey			( TimeType time, const KeyType& value, UPtr< Interpolator >&& interpolator );
	/**@brief Udates key given by time. Sets new interpolator.
	@return False if There's no key in given time.*/
	bool	UpdateKey		( TimeType time, const KeyType& newValue, UPtr< Interpolator >&& interpolator );
	/**@brief Updates key. Leaves interpolator unchanged.
	@return False if There's no key in given time.*/
	bool	UpdateKey		( TimeType time, const KeyType& newValue );
	/**@brief Removes key in given time.
	@return False if There's no key in given time.*/
	bool	RemoveKey		( TimeType time );

	/**@brief Updates interpolator. Key remains unchanged.
	@return False if There's no key in given time.*/
	bool	UpdateInterpolator	( UPtr< Interpolator >&& interpolator );

	/**@brief Return key in given time.*/
	const Key< KeyType >*		GetKey	( TimeType time );
};



//====================================================================================//
//			Implementation	
//====================================================================================//

// ================================ //
//
template< typename KeyType, typename AddressType >
inline				AnimEvaluator< KeyType, AddressType >::AnimEvaluator( EngineObject* object, const std::string& propertyPath )
	:	m_param( object, propertyPath )
{
	//static_assert( std::is_member_function_pointer< &AddressType::GetValue >::value, "Template parameter AddressType must implement GetValue function." );
	//static_assert( std::is_member_function_pointer< &AddressType::SetValue >::value, "Template parameter AddressType must implement SetValue function." );

	KeyType curValue = m_param.GetValue( object );
	
	Key< KeyType > firstKey;
	firstKey.Time = TimeType( 0.0 );
	firstKey.Param.Value = curValue;
	//firstKey.Value.Interpolator = 
	m_keys.Keys.push_back( std::move( firstKey ) );
}


// ================================ //
//
template< typename KeyType, typename AddressType >
inline void			AnimEvaluator< KeyType, AddressType >::Evaluate		( EngineObject* object, TimeType time )
{

}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline void			AnimEvaluator< KeyType, AddressType >::Evaluate		( EngineObject* object, TimelineBase* timeline )
{
	Evaluate( object, timeline->GetTime() );
}

// ================================ //
//
template<typename KeyType, typename AddressType>
inline bool AnimEvaluator<KeyType, AddressType>::AddKey( TimeType time, const KeyType & value )
{
	return false;
}

// ================================ //
//
template<typename KeyType, typename AddressType>
inline bool AnimEvaluator<KeyType, AddressType>::AddKey( TimeType time, const KeyType & value, UPtr<Interpolator>&& interpolator )
{
	return false;
}

// ================================ //
//
template<typename KeyType, typename AddressType>
inline bool AnimEvaluator<KeyType, AddressType>::UpdateKey( TimeType time, const KeyType & newValue, UPtr<Interpolator>&& interpolator )
{
	return false;
}

// ================================ //
//
template<typename KeyType, typename AddressType>
inline bool AnimEvaluator<KeyType, AddressType>::UpdateKey( TimeType time, const KeyType & newValue )
{
	return false;
}

// ================================ //
//
template<typename KeyType, typename AddressType>
inline bool AnimEvaluator<KeyType, AddressType>::RemoveKey( TimeType time )
{
	return false;
}

// ================================ //
//
template<typename KeyType, typename AddressType>
inline bool AnimEvaluator<KeyType, AddressType>::UpdateInterpolator( UPtr<Interpolator>&& interpolator )
{
	return false;
}

// ================================ //
//
template< typename KeyType, typename AddressType >
inline const Key< KeyType >*			AnimEvaluator< KeyType, AddressType >::GetKey( TimeType time )
{
	return nullptr;
}
