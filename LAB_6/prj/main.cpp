#include <iostream>
#include <string>
#include "tablica_asoc.hh"

using namespace std;

/*!
 * \file
 * \brief Plik zawierajacy funkcje main
 */

/*!
 * \brief Funkcja main
 * 
 * Testuje wszystkie metody klasy tablica_asoc.
 */
int main() {

tablica_asoc pierwsza;

//przykladowe klucze i wartosci
string klucz[]={"pierwszy", "drugi", "trzeci", "czwarty"};
int wartosc[]={1,2,3,4};

	pierwsza.wyswietl(); //wyswietli komunikat, ze nie ma elementow tablicy

cout<<"Dodawanie 4 elementow do tablicy:"<<endl;
	for (int i = 0; i < 4; i++) {	
	pierwsza.dodaj(klucz[i], wartosc[i]);
	}
	pierwsza.wyswietl();

cout<<endl<<"Usuwanie elementu tablicy:"<<endl;
	pierwsza.usun("czwarty");
	cout<<"Klucz czwarty zostal usuniety"<<endl;
	pierwsza.wyswietl();

cout<<endl<<"Ilosc elementow tablicy: "<<pierwsza.ileElementow()<<endl;

cout<<endl<<"Pobieranie wartosci trzeciego elementu tablicy:"<<endl;
	cout<<pierwsza.pobierz("trzeci")<<endl;

cout<<endl<<"Zmiana wartosci trzeciego elementu tablicy z 3 na 300:"<<endl;
	pierwsza.zmien("trzeci", 300);
	pierwsza.wyswietl();

return 0;
}
