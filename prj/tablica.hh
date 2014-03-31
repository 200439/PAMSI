#ifndef TABLICA_HH
#define TABLICA_HH
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

/*!
 * \file
 * \brief Definicja klasy tablica
 *
 */

/*! \brief Definicja klasy tablica
 * 
 */
class tablica {
	public:
	int ilosc;
	int ilosc_pocz;
	int pojemnosc;
	int top;
	int *tab_1;	
	const char * nazwa;
	fstream plik;

	int elementy(const char * name);
	
	int zwroc_ilosc();
	void wypelnij();
	void wyswietl();
	void mnozenie();
	void zamien_elementy(int i, int j);
	void odwroc_kolejnosc();	
	void dodaj_element(int e);
	void dodaj_elementy(tablica& tab);
	bool operator ==(tablica& Arg2);
	tablica& operator+(tablica& tab2);
	tablica& operator=(tablica& tab2);

	tablica(const char * name) {nazwa=name, pojemnosc=0, top=-1, ilosc_pocz=elementy(nazwa), ilosc=ilosc_pocz, tab_1=new int [ilosc], wypelnij();}
	tablica() {nazwa="tablica", pojemnosc=0, top=-1, ilosc_pocz=elementy(nazwa), ilosc=ilosc_pocz, tab_1=new int [ilosc], wypelnij();}
	~tablica() {delete [] tab_1;}
};

#endif
