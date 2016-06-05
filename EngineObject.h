#pragma once
/**@file ActorBase.h
@author nieznanysprawiciel
@copyright Plik jest czêœci¹ silnika graficznego SWEngine.

@brief */

#include "Common/RTTR.h"

class ISerializer;
class IDeserializer;


/**@brief Klasa bazowa dla obiektów, które maj¹ byæ dostêpne w edytorze
poprzez rttr. Nale¿y po niej odziedziczyæ i dodaæ odpowiednie deklaracje.

@todo Dobrze by by³o, gdyby EngineObject implementowa³ domyœln¹ serializacjê, ale wtedy jest problem,
¿e nie wiadomo, która z bibliotek powinna tê implementacjê kompilowaæ.

@ingroup Reflection*/
class EngineObject
{
	RTTR_ENABLE()

public:
	inline rttr::type	GetType			() const		{ return this->get_type(); }


	virtual void		Serialize		( ISerializer* ser ) const	{}
	virtual void		Deserialize		( IDeserializer* deser )	{}
};
