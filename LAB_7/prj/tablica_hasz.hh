#ifndef TABLICA_HASZ_HH
#define TABLICA_HASZ_HH
#include <list>
#include <iostream>

/*!
 * \file
 * \brief Definicja klasy tablica_hasz i jej metod
 */

using namespace std;

/*!
 * \brief Definicja klasy tablica_hasz
 *
 * Klasa ta odpowiedzialna jest za stworzenie tablicy mieszajacej, ktorej kazdym elementem jest struktura list,
 * zawierajaca pare: klucz typu string oraz wartosc typu int.
 */
class tablica_hasz {
    list < pair<string,int> > tablica[167]; //tablica ma wielkosc 167, jest to liczba pierwsza
    int haszuj(string k);
	
	public:
	void dodaj(string k, int v);
	int znajdz(string k);
	void wyswietl(string k);
};
#endif
