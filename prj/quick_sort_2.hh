#ifndef QUICK_SORT_2_HH
#define QUICK_SORT_2_HH
#include <iostream>
#include <cstdlib>
#include <ctime>
#include"tablica.hh"

using namespace std;

/*!
 * \file
 * \brief Definicja klasy quick_sort (sortowanie szybkie)
 *
 */

/*! \brief Definicja klasy quick_sort
 * 
 */
class quick_sort_2 {
	public:
	void zamien(int *wartosc1, int *wartosc2);
	int podzial(int *tab, int dlugosc);
	void sortowanie(int *tab, int dlugosc);
	int dlugosc;

	quick_sort_2(tablica &Tab) {dlugosc=Tab.ilosc, sortowanie(Tab.tab_1, dlugosc);}
};
#endif
