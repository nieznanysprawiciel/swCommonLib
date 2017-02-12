#pragma once
/**
@file Attribute.h
@author nieznanysprawiciel
@copyright File is part of Sleeping Wombat Libraries.
*/

#include "swCommonLib/Common/TypesDefinitions.h"


namespace sw
{


class AttributeRepr;
DEFINE_PTR_TYPE( AttributeRepr );


/**@brief */
class Attribute
{
private:

	AttributeReprPtr		m_attribPtr;

protected:
public:
	explicit		Attribute() = default;
	~Attribute() = default;


	bool			IsValid		() const;
};


}	// sw
