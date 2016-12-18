#pragma once
/**
@file KeySet.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/


#include "Key.h"

#include <vector>


/**@brief Set of animation keys.
@ingroup Animation*/
template< typename ValueType >
struct KeySet
{
	std::vector< Key< ValueType > >		Keys;
};

