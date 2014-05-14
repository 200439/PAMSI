#ifndef GRAF_HH
#define GRAF_HH
#include <iostream>
#include <vector>
#include <cstdlib>
#include <list>


/*!
 * \file 
 * \brief Plik zawierajacy definicje klasy graf
 */

using namespace std;

class wierzcholek {
	public:    
	int waga;
	int sasiad;
    
    wierzcholek(){waga=0; sasiad=0;};
};

/*!
 * \brief Klasa graf definiujaca abstrakcyjny typ danych - graf
 */
class graf {
	vector<wierzcholek> *lista_sasiadujaca;
    vector<int> *lista_sasiedztwa;
	int liczba_wierzcholkow, liczba_krawedzi;
	int rozmiar;

	public:
		void dodaj_wierzcholek(int v);
		void dodaj_krawedz(int v1, int v2, int w);
		void usun_wierzcholek(int v);
		void usun_krawedz(int v1, int v2);
		bool czy_polaczone(int v1, int v2);
		void sasiedztwo(int v);

		void wyswietl();

		// Przeszukiwanie:
		void DFSUnreach(int v1, int v2, bool odwiedzone[]);
		void w_glab(int v1, int v2); //DFS - deapth first search
		void wszerz(int v1, int v2); //BFS - breadth first search

	graf() { rozmiar=20; lista_sasiadujaca=new vector<wierzcholek>[rozmiar]; lista_sasiedztwa=new vector<int>[rozmiar]; };
	graf(int r) { rozmiar=r; };
	~graf() { delete[] lista_sasiadujaca;};
};

#endif
