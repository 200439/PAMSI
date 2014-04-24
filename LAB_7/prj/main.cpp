#include <iostream>
#include <string>
#include "tablica_asoc.hh"
#include "tablica_hasz.hh"
#include "drzewo_bin.hh"
#include "zegar.hh"

using namespace std;

/*!
 * \file
 * \brief Plik zawierajacy funkcje main
 */

/*!
 * \brief Funkcja main
 * 
 */
int main() {
	int ilosc=20000;
int ilosc_asoc, ilosc_hasz, ilosc_bin;
ilosc_asoc=ilosc_hasz=ilosc_bin=ilosc;

cout<<endl<<endl<<"TABLICA ASOCJACYJNA:"<<endl;
zegar watch_asoc;
	/*int ilosc_asoc;
	cout<<"Ile elementow dodac?: ";
	cin>>ilosc_asoc;*/
	string klucz_asoc="klucz";
	string kopia_asoc=klucz_asoc;
	
	tablica_asoc Tab_a;
	
watch_asoc.start();
	for(int i=0; i<ilosc_asoc; i++) {
		Tab_a.dodaj(klucz_asoc+="A", 1+i);
	}
watch_asoc.stop();
	/*Tab_a.wyswietl();*/
watch_asoc.zapisz_wynik("wynik_asoc.csv");
watch_asoc.wyswietl();

watch_asoc.start();
Tab_a.pobierz(klucz_asoc);
watch_asoc.stop();
watch_asoc.zapisz_wynik("wynik_asoc2.csv");
watch_asoc.wyswietl();

//////////////////////////////////////////////////////////////////////////////////////
cout<<endl<<endl<<"TABLICA HASZUJACA:"<<endl;
zegar watch_hasz;
	/*int ilosc_hasz;
	cout<<"Ile elementow dodac?: ";
	cin>>ilosc_hasz;*/
	string klucz="klucz";
	string kopia=klucz;
	
	tablica_hasz Tab;

watch_hasz.start();	
	for(int i=0; i<ilosc_hasz; i++) {
		Tab.dodaj(klucz+="A", 1+i);
	}
watch_hasz.stop();

	/*for(int i=0; i<ilosc_hasz; i++) {
		Tab.wyswietl(kopia+="A");
	}*/
watch_hasz.zapisz_wynik("wynik_hasz.csv");
watch_hasz.wyswietl();

watch_hasz.start();	
Tab.znajdz(klucz);
watch_hasz.stop();
watch_hasz.zapisz_wynik("wynik_hasz2.csv");
watch_hasz.wyswietl();

//////////////////////////////////////////////////////////////////////////////////////
cout<<endl<<endl<<"DRZEWO BINARNE:"<<endl;
zegar watch_bin;
	/*int ilosc_bin;
	cout<<"Ile elementow dodac?: ";
	cin>>ilosc_bin;*/
	
	drzewo_bin Drzewo;

watch_bin.start();
	for(int i=0; i<ilosc_bin; i++) {
		Drzewo.dodaj(1+i);
	}
watch_bin.stop();
	/*for(int i=0; i<ilosc_bin; i++) {
		Drzewo.wyswietl(1+i);
	}*/

watch_bin.zapisz_wynik("wynik_bin.csv");
watch_bin.wyswietl();

watch_bin.start();
	Drzewo.znajdz(ilosc_bin);
watch_bin.stop();
watch_bin.zapisz_wynik("wynik_bin2.csv");
watch_bin.wyswietl();
return 0;
}
