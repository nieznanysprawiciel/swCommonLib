#pragma once
/**
@file IInterpolator.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "Common/TypesDefinitions.h"

template< typename KeyType >
struct Key;


/**@brief */
template< typename KeyType >
class IInterpolator
{
private:
protected:
public:
	explicit		IInterpolator() = default;
	virtual			~IInterpolator() = default;

	virtual KeyType			Interpolate		( TimeType time, Key< KeyType >& left, Key< KeyType >& right )	= 0;
};

