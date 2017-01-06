#pragma once
/**
@file Animation.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/EngineObject.h"

#include "IAnimation.h"
#include "Common/ParameterAnimation/Animation/AnimEvaluator.h"

#include "Common/ParameterAnimation/Parameters/DirectPropertyh.h"
#include "Common/ParameterAnimation/Parameters/PropertyPath.h"
#include "Common/ParameterAnimation/Parameters/StringPropertyPath.h"



//====================================================================================//
//			AnimationTyped	
//====================================================================================//


/**@brief Interface class for manipulating animation keys.

Inherit from this class to specialize parameter addressing method.
@ingroup KeyFrameAnimation*/
template< typename KeyType >
class AnimationTyped : public IAnimation
{
public:
	typedef IInterpolator< KeyType > Interpolator;

private:
protected:
public:
	virtual			~AnimationTyped	() = default;

	/**@brief Adds key and sets default interpolator.
	@return False if key already exists.*/
	virtual bool	AddKey			( TimeType time, const KeyType& value )											= 0;
	/**@brief Adds key and sets given interpolator.
	@return False if key already exists.*/
	virtual bool	AddKey			( TimeType time, const KeyType& value, UPtr< Interpolator >&& interpolator )	= 0;
	/**@brief Udates key given by time. Sets new interpolator.
	@return False if There's no key in given time.*/
	virtual bool	UpdateKey		( TimeType time, const KeyType& newValue, UPtr< Interpolator >&& interpolator )	= 0;
	/**@brief Updates key. Leaves interpolator unchanged.
	@return False if There's no key in given time.*/
	virtual bool	UpdateKey		( TimeType time, const KeyType& newValue )										= 0;
	/**@brief Removes key in given time.
	@return False if There's no key in given time.*/
	virtual bool	RemoveKey		( TimeType time )																= 0;

	/**@brief Updates interpolator. Key remains unchanged.
	@return False if There's no key in given time.*/
	virtual bool	UpdateInterpolator	( UPtr< Interpolator >&& interpolator )										= 0;

	/**@brief Return key in given time.*/
	virtual const Key< KeyType >*		GetKey	( TimeType time )													= 0;

	/**@brief Returns KeySet object.*/
	virtual KeySet< KeyType >&			GetKeySet	()																= 0;
};


//====================================================================================//
//			AnimationImpl	
//====================================================================================//

/**@brief 

@ingroup KeyFrameAnimation*/
template< typename KeyType, typename AddressType >
class AnimationImpl : public AnimationTyped< KeyType >
{
private:
protected:
public:
	AnimEvaluator< KeyType, AddressType >		Evaluator;

public:
					AnimationImpl	( EngineObject* object, const std::string& propertyPath );
	virtual			~AnimationImpl	() = default;


	/**@copydoc AnimationTyped::AddKey*/
	virtual bool	AddKey			( TimeType time, const KeyType& value )											override;
	/**@copydoc AnimationTyped::AddKey*/
	virtual bool	AddKey			( TimeType time, const KeyType& value, UPtr< Interpolator >&& interpolator )	override;
	/**@copydoc AnimationTyped::AddKey*/
	virtual bool	UpdateKey		( TimeType time, const KeyType& newValue, UPtr< Interpolator >&& interpolator ) override;
	/**@copydoc AnimationTyped::UpdateKey*/
	virtual bool	UpdateKey		( TimeType time, const KeyType& newValue )										override;
	/**@copydoc AnimationTyped::RemoveKey*/
	virtual bool	RemoveKey		( TimeType time )																override;

	/**@copydoc AnimationTyped::UpdateInterpolator*/
	virtual bool	UpdateInterpolator	( UPtr< Interpolator >&& interpolator )										override;

	/**@copydoc AnimationTyped::GetKey*/
	virtual const Key< KeyType >*		GetKey	( TimeType time )													override;
	/**@copydoc AnimationTyped::GetKeySet*/
	virtual KeySet< KeyType >&			GetKeySet	()																override;
};

typedef AnimationImpl< float, StringPropertyPath< float > > FloatAnimationStrPath;
typedef AnimationImpl< float, PropertyPath< float > > FloatAnimationPropPath;
typedef AnimationImpl< float, DirectProperty< float > > FloatAnimationDirect;

template< template< typename KeyType > class AddressType >
using FloatAnimation = AnimationImpl< float, AddressType< float > >;


#include "Animation.inl"

