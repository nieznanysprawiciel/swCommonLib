#pragma once
/**
@file StringPropertyPath.h
@author nieznanysprawiciel
@copyright File is part of graphic engine SWEngine.
*/

#include "ParamAddress.h"

#include "Common/System/Path.h"


/**@brief */
template< typename KeyType >
class StringPropertyPath
{
private:
	filesystem::Path		m_path;

protected:
public:
	explicit		StringPropertyPath() = default;
	~StringPropertyPath() = default;

};

template< typename KeyType >
using StringPathAddress = ParamAddress< KeyType, StringPropertyPath< KeyType > >;
