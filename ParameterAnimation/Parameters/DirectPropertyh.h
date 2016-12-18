#pragma once
/**
@file DirectProperty.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "ParamAddress.h"
#include "Common/RTTR.h"


/**@brief */
template< typename KeyType >
class DirectProperty
{
private:
	rttr::property		m_property;
	void*				m_object;		///< @todo Change to typed pointer some way.

protected:
public:
	explicit		DirectProperty() = default;
	~DirectProperty() = default;

};

template< typename KeyType >
using DirectAddress = ParamAddress< KeyType, DirectProperty< KeyType > >;
