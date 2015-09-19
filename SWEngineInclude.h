/**
@file MeshResources.h
@author nieznanysprawiciel
@copyright Plik jest czêœci¹ silnika graficznego SWEngine.

Ten plik s³u¿y do includowania najwa¿niejszych funkcjonalnoœci silnika w aplikacji koñcowej
Ponadto zawiera dokumentacjê uruchamiania, struktury projektu i innych elementów niezale¿nych od kodu.
*/

#include "EngineCore/GamePlay/IGamePlay.h"
#include "EngineCore/MainEngine/EngineInterface.h"
#include "EngineCore/Actors/ActorObjects.h"
#include "EngineCore/EventsManager/Event.h"


/**@defgroup ModulesStructure Modu³y silnika
@brief Modu³y silnika*/


/**@page LaunchInstruction Instrukcja uruchamiania

##Niezbêdne biblioteki i kompilacja

Aby skompilowaæ projekt, trzeba mieæ œci¹gniête DirectX SDK
(http://www.microsoft.com/en-us/download/details.aspx?id=6812)

Przy instalacji najczêœciej s¹ problemy.
Je¿eli wyst¹pi b³¹d S1023 nale¿y odinstalowaæ Visual C++ 2010 Redistributable (zarówno x86 jak i x64).
B³¹d jest podobno zwi¹zany z Service Packiem 1, dok³adniej mo¿na przeczytaæ w internecie co i jak.

Po dezinstalacji Visual C++ 2010 Redistributable, DirectX SDK daje siê zainstalowaæ poprawnie.
Potem nale¿y ponownie zainstalowaæ Visual C++ 2010 Redistributable, co nie powoduje ju¿ problemów,
a przynajmniej nic nie wiem.
(link: http://www.microsoft.com/en-us/download/details.aspx?displaylang=en&id=26999)

Slnik u¿ywa równie¿ FBX SDK do wczytywania modeli w tym formacie. Biblioteka znajduje siê
w folderze /External.

Kompilowanie wersji 32-bitowej poprzez Visual Studio odbywa siê normalnie BUILD->Build Solution.

##Kompilowanie wersji 64-bitowej

Wszystkie ustawienia projektu dla wersji 64-bitowej s¹ poprawnie ustawione.
Jedyne co nale¿y zrobiæ, to przestawiæ active solution platform z Win32 na x64.
Mo¿na to zrobiæ nastêpuj¹co:
-	Rozwijamy listê Solution Cofigurations po prawej od zielonego przycisku do w³¹czania projektu i kompilacji.
-	Wybieramy Configuration Manager
-	Po prawej stronie na górze zmieniamy Active Solution Platform na x64
-	Zamykamy okno
Od tej pory silnik bêdzie kompilowany do wersji 64-bitowej.

Katalogiem wynikowym pliku .exe jest GameRelease/binaries_x64.
Wersja 64-bitowa uruchamia siê w Visual Studio, ale poza nim nie, poniewa¿
jest w z³ym katalogu. Instrukcja uruchamiania znajduje siê w pliku 
GameRelease/binaries_x64/read_before_use.txt.

##Uruchamianie

Jedynym uruchamialnym w tej chwili projektem jest TestEngine.
Wywo³uje on funkje testuj¹ce silnika, które wczytuj¹ modele z katalogów GameRelease/tylko_do_testow.


##Dokumentacja

Dokumentacja jest dostêpna online pod linkiem:
http://nieznanysprawiciel.github.io/SWEngine/

Istnieje specjalny branch gh-pages, który zawiera tylko i wy³¹cznie dokumentacjê
w postaci html-ów.

@attention Aby móc generowaæ dokumentacjê do tego brancha, sklonowa³em ca³e repo tak,
¿eby nowy folder .git znajdowa³ siê w katalogu Documentation/html/.
Dziêki temu bêd¹c w branchu gh-pages mo¿na generowaæ dokumentacjê z plików Ÿród³owych projektu znajduj¹cych siê kilka katalogów wy¿ej.

Przez tak¹ strukturê nale¿y te¿ bardzo uwa¿aæ co siê gdzie commituje, pushuje i pulluje.
Branch gh-pages nie ma prawa mieæ nic oprócz dokumentacji, a pozosta³e branche nie maj¹ prawa
mieæ ¿adnego wygenerowanego przez doxygen pliku.

Najlepiej jest WOGÓLE nic nie commitowaæ, pushowaæ ani pullowaæ z brancha gh-pages.


##Generowanie dokumentacji

Dokumentacja jest generowana automatycznie na podstawie kodu Ÿród³owego w komentarzach.
Poza tym w katalogu SWEngine/EngineCode/documentation znajduj¹ siê pliki dodatkowe z opisem tematycznym
niektórych zagadnieñ.
Jak ktoœ bêdzie kiedyœ implementowa³ jakieœ funkcje, to musi na bie¿¹co komentowaæ
swoje osi¹gniêcia.

Aby wygenerowaæ dokumentacjê:

- Nale¿y œci¹gn¹æ program doxywizard ze strony: http://www.stack.nl/~dimitri/doxygen/download.html
- Ustawiæ working directory, ¿eby odpowiada³o temu, gdzie trzymasz projekt
- Wczytac plik konfiguracyjny doxywizarda
- Przejœæ do zak³adki Run i klikn¹æ Run doxygen

Plik konfiguracyjny silnika znajduje siê w katalogu:
SWEngine/EngineCode/documentation i nazywa siê Doxyfile

Dokumentacja zostanie wygenerowana w katalogu:
SWEngine/Documentation/html

Aby obejrzeæ j¹ w przegl¹darce offline mo¿na:
-	klikn¹æ na przycisk Show HTML output w programie doxywizard
-	poszukaæ pliu index.html w katalogu z dokumentacj¹
*/


/**@page ProjectSettings Konfigurowanie projektów

##Konfiguracje projektu

@note Zmian w konfiguracjach projektu raczej nie nale¿y wprowadzaæ bezpoœrednio dla konfiguracji
Debug i Release. Do tego s³u¿¹ pliki .props, które mo¿na zobaczyæ otwieraj¹c Property Manager dla
projektów C++.

U³atwia to zarz¹dzanie ustawieniami, poniewa¿ pliki te odnosz¹ siê do wszystkich konfiguracji projektu
na raz. Ponadto mo¿na je wspó³dzieliæ w wielu projektach jednoczeœnie.

Bezpoœrednio w konfiguracji mo¿na wprowadzaæ jedynie te zmiany, które odnosz¹ siê konkretnie do danej konfiguracji
(np. do Debug x86).

##Podstawowe pliki konfiguracyjne

Istniej¹ dwa pliki .props, których powinien u¿ywac ka¿dy projekt:
-	DebugConfig lub ReleaseConfig

Te pliki definiuj¹ makra ConfigTypeString, które zawieraj¹ napis "Debug" lub "Release" w zale¿noœci
od konfiguracji. Nastêpnie te makra s¹ u¿ywane do tworzenia nazw œcie¿ek i plików.

-	PathsMacros
Zawiera podstawowe œcie¿ki silnikowe, do których odwo³uj¹ siê póŸniej kolejne pliki .props.

Ka¿dy projekt ma dwa w³aœciwe tylko dla siebie pliki konfiguracyjne
-	[NazwaProjektu]PathMacros
-	[NazwaProjektu]Configuration

Pierwszy plik zawiera definicje makr, zawieraj¹cych podstawowe œcie¿ki i nazwy dla danego projektu.
Makra maj¹ pewien schemat i ka¿dy nowy projekt powinien siê go mniej wiêcej trzymaæ.
Najlepszym sposobem jest przekopiowanie i edytowanie pliku .props w edytorze tekstowym zamiast w Visual Studio.

Dla projektów kompiluj¹cych siê do biblioteki statycznej, plik ten zawiera równie¿ w sekcji Linker
komendy umo¿liwiaj¹ce zlinkowanie tej biblioteki. Projekt, który chce zlinkowaæ bibliotekê musi jedynie
dodaæ odpowiedni plik .props.

[NazwaProjektu]Configuration zawiera zasadnicze ustawienia projektu. W ¿adnym razie nie nale¿y ustawieñ umieszczaæ
w [NazwaProjektu]PathMacros, poniewa¿ ustawienia s¹ dziedziczone i mog¹ wp³ywaæ na inne projekty.

Wiêkszoœæ projektów umieszcza tu w Additional Include Directories œcie¿kê $( EngineSourceDir ).
*/

/**@page FolderStructure

Pod makrem $( RootDir ) znajduje siê œcie¿ka do katalogu SWEngine (chyba, ¿e ktoœ inaczej nazwa³ katalog z projektem).

-	Projects
Katalog zawiera plik Solution oraz w podfolderach wszystkie pliki projektów oraz konfiguracji (.props).

-	GameRelease
Zawiera strukturê katalogow¹ wynikowej aplikacji oraz modele testowe.

-	External
Zawiera biblioteki zewnetrzne. Nie wszystkie biblioteki tu trafiaj¹. DirectX SDK na przyk³ad
mo¿e znajdowaæ siê w dowolnym miejscu i ma zdefiniowan¹ zmienn¹ œrodowiskow¹ ze œcie¿k¹.

-	EngineBuildDir
Tu trafiaj¹ wyniki kompilacji, czyli ca³y œmietnik.

-	Documentation
Zawiera dokumentacjê projektu generowan¹ przez doxygen (w folderze /html).

-	EngineLib
Tutaj trafiaj¹ skompilowane biblioteki statyczne.

-	EngineCode
W tym katalogu znajduj¹ siê wszystkie pliki z kodem Ÿród³owym projektów.
Ka¿dy projekt powinien dodaæ œcie¿kê do tego katalogu w Additional Include Directories.

Zaleca siê, ¿eby includuj¹c pliki podawaæ wszystki œcie¿ki wzglêdem tego katalogu.
Trzeba to robiæ szczególnie wtedy, gdy projekt kompiluje siê do biblioteki statycznej.
W przeciwnym wypadku wszystkie projekty, które includuj¹ jakieœ headery biblioteczne, mog¹
siê nie kompilowaæ, ze wzglêdu na b³êdne œcie¿ki.

*/
