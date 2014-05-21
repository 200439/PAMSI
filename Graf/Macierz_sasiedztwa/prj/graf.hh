#ifndef GRAF_HH
#define GRAF_HH
#include <iostream>
#include <vector>
#include <cstdlib>
#include <stack>

/*!
 * \file 
 * \brief Plik zawierajacy definicje klasy graf opartej na macierzy sasiedztwa
 */

using namespace std;

/*!
 * \brief Klasa graf definiujaca abstrakcyjny typ danych - graf
 */
class graf {
	char ** macierz_sasiedztwa;

	/* \brief Struktura definiujaca wierzcholek grafu
	 *
	 */
	struct wierzcholek {
		wierzcholek * sasiad;
		int wartosc;

		bool odwiedzony;
	};

	/* \brief Struktura definiujaca krawedz grafu
	 *
	 */
	struct krawedz {
		wierzcholek * v1;
		wierzcholek * v2;
		int waga;
	};

	/* \brief Struktura definiujaca jeden wezel listy potrzebnej przy przeszukiwaniu wszerz
	 *
	 */
	class wezel_wszerz {
		public:
		wezel_wszerz * nastepny;
		int wartosc;
		wezel_wszerz() {nastepny=NULL;};
	};

	public:		

	vector<wierzcholek> wierzcholki;
	vector<krawedz> krawedzie;
		
		void stworz_macierz(char ** macierz);										
		void dodaj_wierzcholek(int v);		
		void dodaj_krawedz(int v1, int v2, int w);				
		void usun_wierzcholek(int v);						
		void usun_krawedz(int v1, int v2);							
		bool czy_polaczone(int v1, int v2);							
		void sasiedztwo(int v);
	
		// Przeszukiwanie:
		stack<int> stos_w_glab;
		int nastepny_w_glab(int v);
		void w_glab(int v1, int v2); 	//DFS - deapth first search
		void wszerz(int v1, int v2); 	//BFS - breadth first search

	~graf() { delete[] macierz_sasiedztwa;};
};

#endif
