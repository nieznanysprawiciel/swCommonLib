#pragma once
/**
@file PointInterpolator.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "IInterpolator.h"



/**@brief 

@ingroup Interpolators*/
template< typename KeyType >
class PointInterpolator : public IInterpolator< KeyType >
{
private:
protected:
public:
	explicit		PointInterpolator() = default;
					~PointInterpolator() = default;

	/**@brief Interpolates value.*/
	virtual KeyType			Interpolate		( TimeType time, Key< KeyType >& left, Key< KeyType >& right ) override;
};

//====================================================================================//
//			Implementation	
//====================================================================================//


// ================================ //
//
template< typename KeyType >
inline KeyType		PointInterpolator< KeyType >::Interpolate( TimeType time, Key< KeyType >& left, Key< KeyType >& right )
{
	return left.Value.Value;
}
