#pragma once
/**
@file PropertyPath.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "ParamAddress.h"
#include "Common/RTTR.h"

#include <vector>


/**@brief */
template< typename KeyType >
class PropertyPath
{
private:
	std::vector< rttr::property >	m_path;

public:


};

template< typename KeyType >
using PropertyPathAddress = ParamAddress< KeyType, PropertyPath< KeyType > >;
