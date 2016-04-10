#pragma once

// Windows.h header often defines theese macros adn causes conflicts
#undef max
#undef min

#include "Tools/Reflection/RTTR.h"


/**@defgroup Reflection Mechanizm refleksji.
@ingroup Tools
@brief Biblioteka zapewnia dynamiczn¹ kontrolê typów obiektów oraz mechanizmy rejestrowania
metainformacji.

Silnik wykorzystuje bibliotekê RTTR autorstwa Axela Menzela udostêpnian¹ na licencji
MIT z ma³ymi przeróbkami.
Dokumentacja i przyk³ady znajduj¹ siê na stronie:
http://www.rttr.org/ */
