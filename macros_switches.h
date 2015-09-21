#pragma once
/**
@file macros_switches.h
@author nieznanysprawiciel
@copyright Plik jest czêœci¹ silnika graficznego SWEngine.

@brief Ten plik zawiera makrodefinicje bêd¹ce prze³¹cznikami miêdzy ró¿nymi opcjami kompilacji.
Wiêkszoœæ z tych makrodefinicji pozwala na wybór jednej z opcji tylko tymczasowo,
w docelowej wersji silnika trzeba bêdzie siê zdecydowaæ na któr¹œ z nich.*/

#include "Common/TypesDefinitions.h"

///Co tyle sekund aktualizujemy frames_per_sec.
static const unsigned int FRAMES_PER_SEC_UPDATE = 10;			

///@def _INTERPOLATE_POSITIONS
///@brief W³¹cza do kodu funkcje interpoluj¹ca po³o¿enia obiektów.
#define _INTERPOLATE_POSITIONS

//#define _QUATERNION_SPEED			//@def _QUATERNION_SPEED
/*	Predkoœæ obrotowa jest wyra¿ona kwaternionem
Je¿eli to makro nie jest zdefiniowane, to prêdkoœæ obrotowa jest wyra¿ona jako wektor
4-elementowy, w którym pierwsze 3 sk³adowe opisuj¹ wektor obrotu, a sk³adowa w k¹t obrotu*/

///@def __TEST
///@brief W³¹cza funkcje testuj¹ce silnika.
///Funkcje testuj¹ce maj¹ na celu umo¿liwienie wczytywania modeli i ustawiania stanów obiektów,
///mimo ¿e nie s¹ stworzone docelowe mechanizmy, których ma u¿ywaæ silnik.
#define __TEST

#define _SCALEABLE_OBJECTS			///<Umo¿liwia ustawienie skalowania dla meshy.

/**@def ENGINE_MAX_TEXTURES
@brief Maksymalna liczba tekstur w silniku.
*/
#define ENGINE_MAX_TEXTURES		8
/**@def ENGINE_MAX_LIGHTS
@brief Maksymalna liczba œwiate³ w silniku.
*/
#define ENGINE_MAX_LIGHTS		2


///@todo Stworzyæ mechanizmy pozwalaj¹ce na wybieranie buforów indeksów 8, 16 i 32 bitowych
//#define INDEX_BUFFER_UINT8
//#define INDEX_BUFFER_UINT16		// Definiujemy czy chcemy mieæ bufor indeksów 16-bitowy czy 32-bitowy
#define INDEX_BUFFER_UINT32			// Wybraæ tylko jedno, inaczej bêdzie b³¹d kompilacji

#if defined(INDEX_BUFFER_UINT16)
	static const unsigned int VERTICIES_MAX_COUNT = 0xFFFF;
#elif defined(INDEX_BUFFER_UINT32)
	static const unsigned int VERTICIES_MAX_COUNT = 0xFFFFFFFF;
#else
	static const unsigned int VERTICIES_MAX_COUNT = 0xFFFFFFFF;
#endif

/**@brief Œcie¿ka do pliku, do którego bêd¹ trafia³y pomiary wydajnoœci.*/
static const char* PERFORMANCE_STATISTICS_FILE_PATH = "logs/performance.txt";

///@typedef VERT_INDEX
///@brief Definiujemy typ w buforze indeksów.

///W zale¿noœci od tego czy wybierzemy bufor 16 bitowy czy 32 bitowy VERT_INDEX jest ustawiany jako UINT16 lub UINT32.
#if defined(INDEX_BUFFER_UINT16)
	typedef uint16 VERT_INDEX;
#elif defined(INDEX_BUFFER_UINT32)
	typedef uint32 VERT_INDEX;
#else
	typedef uint32 VERT_INDEX;
#endif


/**@def PERFORMANCE_CHECK
@brief W³¹cza funkcje klasy @ref PerformanceCheck do kodu silnika. Mierzy wydajnoœæ wybranych fragmentów kodu.
*/
#define PERFORMANCE_CHECK

#ifdef _DEBUG
	/**@def SHOW_MEMORY_LEAKS
	@brief W³¹cza do kodu wszystkie elementy niezbêdne do wykrywania wycieków
	*/
	#define SHOW_MEMORY_LEAKS
#endif
