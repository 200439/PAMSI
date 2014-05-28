#include "plecak.hh"

using namespace std;
/* \file
 * \brief Plik zawierajacy glowna funkcje programu.
 *
 * Testuje algorytm wyszukiwania dynamicznego oraz zachlannego optymalnego rozwiazania problemu plecakowego dla przykladow: podroznika, 
 * pakujacego najpotrzebniejsze rzeczy, zlodzieja, ktory ukrasc mial jak najkosztowniejsze przedmioty, oraz biwakowicza, ktory mial wziac 
 * najpotrzebniejsze przedmioty. Mozna takze zadac wlasne zadanie do rozwiazania. 
 */

/* \brief Funkcja glowna programu
 *
 */
int main() {

	cout<<endl<<"\tBIWAK:"<<endl;
	int pojemnosc_biwak=24, ilosc_biwak=5;
	string nazwy_biwak[]={"ubrania", "namiot", "prowiant", "wedka", "lornetka"};
	int wagi_biwak[]={14, 8, 5, 2, 10};
	int ceny_biwak[]={20, 5, 7, 1, 6};

	plecak biwak(pojemnosc_biwak, ilosc_biwak);
	biwak.dodaj_przedmioty(nazwy_biwak, wagi_biwak, ceny_biwak);
	
	biwak.algorytm_dynamiczny();
	biwak.wypisz_tablice();
	biwak.wynik_dynamiczny();

	biwak.algorytm_zachlanny();
	biwak.wynik_zachlanny();



	cout<<endl<<"\tZLODZIEJ:"<<endl;
	int pojemnosc_zlodziej=20, ilosc_zlodziej=4;
	string nazwy_zlodziej[]={"naszyjnik", "pierscionek", "sztabka zlota", "diament"};
	int wagi_zlodziej[]={7, 3, 11, 2};
	int ceny_zlodziej[]={5000, 2100, 25000, 2000};
	
	plecak zlodziej(pojemnosc_zlodziej, ilosc_zlodziej);
	zlodziej.dodaj_przedmioty(nazwy_zlodziej, wagi_zlodziej, ceny_zlodziej);
	
	zlodziej.algorytm_dynamiczny();
	zlodziej.wypisz_tablice();
	zlodziej.wynik_dynamiczny();

	zlodziej.algorytm_zachlanny();
	zlodziej.wynik_zachlanny();



	cout<<endl<<"\tWLASNY:"<<endl;
	int pojemnosc, ilosc;
	cout<<"Jak pojemny jest plecak?: ";
    cin>>pojemnosc;
    cout<<"Ile jest rodzajow przedmiotow?: ";
    cin>>ilosc;
    cout<<endl;

	plecak wlasny(pojemnosc, ilosc);
	wlasny.dodaj_przedmioty();

	wlasny.algorytm_dynamiczny();
	wlasny.wypisz_tablice();
	wlasny.wynik_dynamiczny();

	wlasny.algorytm_zachlanny();
	wlasny.wynik_zachlanny();

return 0;
}
