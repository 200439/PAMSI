#include "tablica_hasz.hh"

/*!
* \file
* \brief Metody klasy tablica_hasz
*
*/

using namespace std;

/*! \brief Funkcja haszujaca
 *
 * Wykorzystuje funkcje hash z biblioteki STL, a nastepnie wygenerowana liczbe dzieli modulo przez rozmiar tablicy, tak by nr indeksu 
 * zmiescil sie w tablicy haszujacej.
 */
int tablica_hasz::haszuj(string k) {	
	int indeks;
	hash <string> haszujTekst;
    indeks=(haszujTekst( k )) % 167;
    return indeks;
}

/*! 
 * \brief Dodaje element do tablicy
 *
 * Za pomoca funkcji haszuj oblicza indeks tablicy, gdzie nastepnie dodawany jest klucz razem z wartoscia.
 *
 */
void tablica_hasz::dodaj(string k, int v) {
    int indeks=haszuj(k);
    tablica[indeks].push_back(make_pair(k, v));
}

/*! 
 * \brief Znajduje dany klucz
 *
 */
int tablica_hasz::znajdz(string k) {
    int n=haszuj(k);
    list< pair<string,int> >::iterator itr=tablica[n].begin(); //iterator ustawiony na poczatek tablicy
    if(!tablica[n].empty()) {
        while(itr!=tablica[n].end()) {
            if( (*itr).first==k ) { 				//kiedy klucz (czyli pierwszy element pary pair) zostaje znaleziony, 
			return (*itr).second; 					//jego wartosc zostaje zwrocona
			}
		itr++;
        }
    }
    else return -99999; // sygnalizacja bledu (nieistnienie podanej wartosci do znalezienia)
}

/*! 
 * \brief Wyswietla wartosc na podstawie klucza
 *
 */
void tablica_hasz::wyswietl(string k) {
	cout<<"Wartosc: "<<znajdz(k)<<endl;
}
