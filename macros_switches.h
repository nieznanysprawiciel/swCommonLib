#pragma once
/**
@file macros_switches.h
@author nieznanysprawiciel
@copyright Plik jest czêœci¹ silnika graficznego SWEngine.

@brief Ten plik zawiera makrodefinicje bêd¹ce prze³¹cznikami miêdzy ró¿nymi opcjami kompilacji.
Wiêkszoœæ z tych makrodefinicji pozwala na wybór jednej z opcji tylko tymczasowo,
w docelowej wersji silnika trzeba bêdzie siê zdecydowaæ na któr¹œ z nich.*/

#include "Common/TypesDefinitions.h"

///Definicje Rendererów. Nale¿y przypisaæ sta³ej ENABLE_RENDERER jedn¹ z poni¿szych wartoœci. (DX12 na razie nie ma)
#define DX11	0
#define DX12	1


///@def ENABLE_RENDERER
///@brief Definiuje renderer, który bêdzie u¿ywany.
#define ENABLE_RENDERER DX11



static const unsigned int FRAMES_PER_SEC_UPDATE = 10;			///<Co tyle sekund aktualizujemy frames_per_sec.

///@def _INTERPOLATE_POSITIONS
///@brief W³¹cza funkcjê interpoluj¹ca po³o¿enia obiektów.
#define _INTERPOLATE_POSITIONS

//#define _QUATERNION_SPEED			//@def _QUATERNION_SPEED
/*	Predkoœæ obrotowa jest wyra¿ona kwaternionem
Je¿eli to makro nie jest zdefiniowane, to prêdkoœæ obrotowa jest wyra¿ona jako wektor
4-elementowy, w którym pierwsze 3 sk³adowe opisuj¹ wektor obrotu, a sk³adowa w k¹t obrotu*/

///@def __TEST
///@brief W³¹cza funkcje testuj¹ce
#define __TEST

#define _SCALEABLE_OBJECTS			///umo¿liwia ustawienie skalowania dla meshy
/**@def ENGINE_MAX_TEXTURES
@brief Maksymalna liczba tekstur w silniku
*/

#define ENGINE_MAX_TEXTURES		8
#define ENGINE_MAX_LIGHTS		2


//#define INDEX_BUFFER_UINT16		// Definiujemy czy chcemy mieæ bufor indeksów 16-bitowy czy 32-bitowy
#define INDEX_BUFFER_UINT32			// Wybraæ tylko jedno, inaczej bêdzie b³¹d kompilacji

#if defined(INDEX_BUFFER_UINT16)
	static const unsigned int VERTICIES_MAX_COUNT = 0xFFFF;
#elif defined(INDEX_BUFFER_UINT32)
	static const unsigned int VERTICIES_MAX_COUNT = 0xFFFFFFFF;
#else
	static const unsigned int VERTICIES_MAX_COUNT = 0xFFFFFFFF;
#endif


static const char* PERFORMANCE_STATISTICS_FILE_PATH = "logs/performance.txt";

///@typedef VERT_INDEX
///@brief Definiujemy typ w buforze indeksów.

///W zale¿noœci od tego czy wybierzemy bufor 16 bitowy czy 32 bitowy VERT_INDEX jest ustawiany jako UINT16 lub UINT32.
#if defined(INDEX_BUFFER_UINT16)
	typedef uint16 VERT_INDEX;
	#define INDEX_BUFFER_FORMAT DXGI_FORMAT_R16_UINT
#elif defined(INDEX_BUFFER_UINT32)
	typedef uint32 VERT_INDEX;
	#define INDEX_BUFFER_FORMAT DXGI_FORMAT_R32_UINT
#else
	typedef uint32 VERT_INDEX;
	#define INDEX_BUFFER_FORMAT DXGI_FORMAT_R32_UINT
#endif


/**@def PERFORMANCE_CHECK
@brief W³¹cza funkcje klasy PerformaceCheck do kodu silnika. Mierzy wydajnoœæ wybranych fragmentów kodu.
*/
#define PERFORMANCE_CHECK

#ifdef _DEBUG
	/**@def SHOW_MEMORY_LEAKS
	@brief W³¹cza do kodu wszystkie elementy niezbêdne do wykrywania wycieków
	*/
	#define SHOW_MEMORY_LEAKS
#endif
