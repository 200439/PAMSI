#include <iostream>
#include <fstream>
#include <cstdlib>
#include "tablica.hh"
#include "quick_sort.hh"
#include "quick_sort_2.hh"
#include "zegar.hh"

using namespace std;
/*!
 * \file
 * \brief Plik glowny programu 
 *
 * Wczytuje tablice liczb z pliku "tablica" i sortuje je za pomoca dwoch algorytkow: sortowania przez kopcowanie oraz sortowania szybkiego.
 * Zapisuje czas dzialania algorytku do plikow wynik_tab.csv oraz wynik_tab_2.csv.
 */

int main() {
///////////////////////////
srand( time( NULL ) );
///////////////////////////

zegar watch;
	tablica T;
	//T.wyswietl();
	//cout<<endl;

watch.start();
	quick_sort pierwszy(T);
watch.stop();

watch.zapisz_wynik("wynik_tab.csv");
watch.wyswietl();
	//T.wyswietl();
////////////////////////////////////////
zegar watch2;
	tablica T2;
	//T2.wyswietl();
	//cout<<endl;

watch2.start();
	quick_sort_2 drugi(T2);
watch2.stop();

watch2.zapisz_wynik("wynik_tab_2.csv");
watch2.wyswietl();
	//T.wyswietl();

return 0;
}
