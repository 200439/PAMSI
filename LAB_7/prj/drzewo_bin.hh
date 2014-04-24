#ifndef DRZEWO_BIN_HH
#define DRZEWO_BIN_HH
#include <iostream>

using namespace std;

/*!
 * \file
 * \brief Definicja klasy drzewo_bin tworzace drzewo binarne
 */

/*!
 * \brief Definicja klasy drzewo_bin
 *
 * Klasa ta odpowiedzialna jest za stworzenie drzewa binarnego, ktorego kazdym elementem jest obiekt typu int.
 */
class drzewo_bin {

	/*!
	 * \brief Definicja struktury wezel
	 * 
	 * Wezel zawiera wartosc oraz wskazniki na prawy i lewy wezel drzewa binarnego.
	 */
	struct wezel {
        int wartosc;
        wezel* lewa;
        wezel* prawa;

        wezel(int v, wezel* l = NULL, wezel* p = NULL) { wartosc=v, lewa=l, prawa=p; }; //konstruktor 
    };

	wezel* korzen;
    void wstaw_wezel(wezel* &drzewo, int v);
	

	public:
    void dodaj(int v);
	void wyswietl(int v);
	int znajdz(int v);

	drzewo_bin() { korzen = NULL; }; //konstruktor
};

#endif
