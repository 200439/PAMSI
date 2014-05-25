#ifndef PLECAK_HH
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
 
/* \file
 * \brief Plik zawierajacy definicje klasy plecak
 *
 */

using namespace std;

/* \brief Deklaracja klasy plecak
 *
 * Zawiera deklaracje struktury rzecz, ktora sklada sie z jej nazwy, wagi i ceny. Poza ta struktura zdefiniowana jest pojemnosc plecaka,
 * ilosc roznych przedmiotow mozliwych do zapakowania do plecaka, tablica przedmiotow, oraz tablice Q i P potrzebne przy algorytmie
 * dynamicznym.
 */
class plecak {
	
	struct rzecz {
		string * nazwa;
    	int * waga;
    	int * cena;
	};
		
	int pojemnosc_plecaka;
	int ilosc_przedmiotow;
	
	rzecz * przedmioty;
	int ** Q; //tablica numerow rzeczy wkladanych do plecaka jako ostatnie
	int ** P; //tablica wartosci upakowan plecaka

public:
	void dodaj_przedmioty();
	void dodaj_przedmioty(string nazwy[], int wagi[], int ceny[]);
	void algorytm_dynamiczny();
	void wypisz_tablice();
	void wynik();

	plecak(int pojemnosc, int ilosc);
	~plecak();
};
#endif
