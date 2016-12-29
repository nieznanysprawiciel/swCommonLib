#pragma once
/**
@file LinearInterpolator.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "IInterpolator.h"

/**@brief 

@ingroup Interpolators*/
template< typename KeyType >
class LinearInterpolator : public IInterpolator< KeyType >
{
private:
protected:
public:
	explicit		LinearInterpolator() = default;
					~LinearInterpolator() = default;


	virtual KeyType			Interpolate		( TimeType time, Key< KeyType >& left, Key< KeyType >& right ) override;
};

//====================================================================================//
//			Implementation	
//====================================================================================//


// ================================ //
//
template< typename KeyType >
inline KeyType		LinearInterpolator< KeyType >::Interpolate( TimeType time, Key< KeyType >& left, Key< KeyType >& right )
{
	return KeyType();
}
