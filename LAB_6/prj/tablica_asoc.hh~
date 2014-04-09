#ifndef TABLICA_ASOC_HH
#define TABLICA_ASOC_HH
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*!
 * \file
 * \brief Definicja klasy tablica_asoc i jej metod
 */

/*!
 * \brief Definicja klasy tablica_asoc
 *
 * Klasa ta odpowiedzialna jest za stworzenie tablicy asocjacyjnej, ktorej kazdym elementem jest struktura para, 
 * zawierajaca klucz typu string oraz wartosc typu int.
 */
class tablica_asoc {
	
	struct para {
		string klucz;
		int wartosc;
		};
	
	vector<para> tablica;

	int nr_elementu(string k);
	
	public:
	void dodaj(string k, int v);
	void usun(string k);
	int pobierz(string k);
	void zmien(string k, int new_v);
	int ileElementow();
	bool czyPusta();
	
	void wyswietl();

};

#endif
