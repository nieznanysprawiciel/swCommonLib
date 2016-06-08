#pragma once

// Windows.h header often defines theese macros adn causes conflicts
#undef max
#undef min

#include "Tools/Reflection/RTTR.h"

/**@brief Typy metadanych widoczne z poziomu edytora.*/
enum class MetaDataType
{
	Category,			///< Kategoria do jakiej nale¿y przypisaæ w³aœciwoœæ w edytorze.
	Serialize,			///< Wartoœæ true oznacza, ¿e w³aœciwoœæ zostanie zserializowana do pliku z map¹. Domyœlnie: true.
	AllowInSaveFile,	///< Serializuje wartoœæ do pliku z zapisanym stanem gry. Domyœlnie: true.
	ShowInEditor,		///< Umo¿liwia odczytywanie i modyfikowanie wartoœci z edytora. Domyœlnie: true. @todo Zaimplementowaæ filtrowanie w edytorze propertiesów.
	EditorName			///< Nazwa wyœwietlana w edytorze. @todo Zaimplementowaæ.
};



/**@defgroup Reflection Mechanizm refleksji
@ingroup Tools
@brief Biblioteka zapewnia dynamiczn¹ kontrolê typów obiektów oraz mechanizmy rejestrowania
metainformacji.

Silnik wykorzystuje bibliotekê RTTR autorstwa Axela Menzela udostêpnian¹ na licencji
MIT z ma³ymi przeróbkami.
Dokumentacja i przyk³ady znajduj¹ siê na stronie:
http://www.rttr.org/


@section CreatingOwnClasses Tworzenie w³asnych klas


Przy tworzeniu w³asnych klas nale¿y dodawaæ do nich metainformacje,
aby edytor móg³ je poprawnie wyœwietliæ. Wszystkie klasy powinny mieæ na samym
szczycie hierarchi dziedziczenia obiekt @ref EngineObject. Je¿eli dziedziczy siê po jakiejœ
silnikowej klasie aktora, to EngineObject w tej hierarchi na pewno siê znajduje.

Pamiêtaæ o tym nale¿y tylko wtedy, gdy tworzy siê jak¹œ strukturê lub klasê, która bêdzie
polem w klasie aktora. Aby edytor móg³ wyœwietlaæ propertisy takiej zagnie¿d¿onej klasy
trzeba jawnie odziedziczyæ po EngineObject.

Nale¿y mieæ na uwadze, ¿e klasa EngineObject deklaruje metody virtualne biblioteki RTTR, w zwi¹zku
z czym wszystkie klasy dziedzicz¹ce bêd¹ mia³y dodatkowe pole ze wskaŸnikiem na vtable, co zwiêkszy
rozmiar takiej struktury.
Z tego powodu lepiej jest, gdy aktorzy nie maj¹ p³ask¹ strukturê i takich zagnie¿d¿onych strutkur
siê nie u¿ywa, ale nikt nie zabrania.


@subsection DeklaringRTTRTypes Deklarowanie typów obiektów


Biblioteka RTTR wymaga deklarowania nowych typów dla które maj¹ byæ przez ni¹ obs³ugiwane.
Typy proste, które nie maj¹ byæ wyœwietlane w edytorze, ale ma byæ dla nich u¿ywana statyczna
kontrola typu, mog¹ zostaæ zadeklarowane w nastêpuj¹cy sposób:

@code
// Plik .h

struct NewType
{};

//Plik .cpp
RTTR_REGISTRATION
{
    using namespace rttr;
	RTTR_REGISTRATION_STANDARD_TYPE_VARIANTS( NewType )
}
@endcode

Je¿eli dla klasy ma byæ u¿ywana dynamiczna kontrola typów, trzeba zadeklarowaæ
hierarchiê dziedziczenia w ka¿dej z klas. Robi siê to w nastêpuj¹cy sposób:

@code
// Plik .h
class StaticActor : public EngineObject
{
	RTTR_ENABLE( EngineObject )
	//...
};
@endcode

Nastêpnie w pliku .cpp mo¿na dodaæ metadane klasy. Nazwy w³asciwoœci nie powinny zawieraæ
bia³ych znaków, poniewa¿ to mo¿e powodowaæ problemy przy serializacji do XMLa.

@code

RTTR_REGISTRATION
{
	rttr::registration::class_< StaticActor >( "StaticActor" )
		.property( "Position", &StaticActor::position )
		(
			rttr::metadata( MetaDataType::Category, "Transformation" ),
			rttr::policy::prop::BindAsPtr()
		)
		.property( "Orientation", &StaticActor::orientation )
		(
			rttr::metadata( MetaDataType::Category, "Transformation" ),
			rttr::policy::prop::BindAsPtr()
		);
}

@endcode

@subsection RTTRNestedClasses Aktorzy z klasami zagnie¿d¿onymi

Typy z³o¿one jak DirectX::XMFLOAT3 powinny byæ deklarowane z polityk¹ rttr::policy::prop::BindAsPtr()
(Tak jak w przyk³adzie powy¿ej). W przeciwnym razie edytor nie bêdzie móg³ ich odczytywaæ i zapisywaæ.
Podobnie sprawa ma siê ze strutkurami wewn¹trz klasy np:

@code

struct Nested : public EngineObject
{
	int variable1;
	int variable2;
};

class Actor : public StaticActor
{
	Nested		nestedField;
}

@endcode

W takim przypadku trzeba dodaæ informacjê o propertisach równie¿ dla klasy Nested.

Typy podstawowe jak
- int
- float
- double
- bool
nie mog¹ byæ deklarowane z polityk¹ BindAsPtr.

@subsection PrivateMembers Prywatne sk³adowe klasy

W przypadku prywatnych sk³adowych, deklaracja metadanych nie skompiluje siê, poniewa¿ prywatne pola s¹ niedostêpne
na zewn¹trz klasy. Aby móc je zadeklarowaæ nale¿y dodaæ makro RTTR_REGISTRATION_FRIEND.

@code

class StaticActor : public EngineObject
{
	RTTR_ENABLE( EngineObject )
	RTTR_REGISTRATION_FRIEND
	//...
};
@endcode

*/
