#pragma once
/**@file ActorBase.h
@author nieznanysprawiciel
@copyright Plik jest czêœci¹ silnika graficznego SWEngine.

@brief */

#include "Common/RTTR.h"


/**@brief Klasa bazowa dla obiektów, które maj¹ byæ dostêpne w edytorze
poprzez rttr. Nale¿y po niej odziedziczyæ i dodaæ odpowiednie deklaracje.

@ingroup Reflection*/
class EngineObject
{
	RTTR_ENABLE()
};
