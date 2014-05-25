#include "plecak.hh"

using namespace std;
/* \file
 * \brief Plik zawierajacy glowna funkcje programu.
 *
 * Testuje algorytm wyszukiwania dynamicznego optymalnego rozwiazania problemu plecakowego dla przykladow: zlodzieja, ktory ukrasc mial 
 * jak najkosztowniejsze przedmioty, oraz biwakowicza, ktory mial wziac najpotrzebniejsze przedmioty.
 */

/* \brief Funkcja glowna programu
 *
 */
int main() {
	
	int pojemnosc_zlodziej=20, ilosc_zlodziej=4;
	string nazwy_zlodziej[]={"naszyjnik", "pierscionek", "sztabka zlota", "diament"};
	int wagi_zlodziej[]={7, 3, 11, 2};
	int ceny_zlodziej[]={5000, 2100, 25000, 2000};
	
	plecak zlodziej(pojemnosc_zlodziej, ilosc_zlodziej);
	zlodziej.dodaj_przedmioty(nazwy_zlodziej, wagi_zlodziej, ceny_zlodziej);
	zlodziej.algorytm_dynamiczny();
	zlodziej.wypisz_tablice();
	zlodziej.wynik();

	/*int pojemnosc_biwak=24, ilosc_biwak=5;
	string nazwy_biwak[]={"ubrania", "namiot", "prowiant", "wedka", "lornetka"};
	int wagi_biwak[]={14, 8, 5, 2, 10};
	int ceny_biwak[]={20, 5, 7, 1, 14};

	plecak biwak(pojemnosc_biwak, ilosc_biwak);
	biwak.dodaj_przedmioty(nazwy_biwak, wagi_biwak, ceny_biwak);
	biwak.algorytm_dynamiczny();
	biwak.wypisz_tablice();
	biwak.wynik();*/
	
return 0;
}