#include "tablica_asoc.hh"

/*!
 * \file
 * \brief Metody klasy tablica_asoc
 */

/*!
 * \brief Metoda, ktora zwraca numer elementu tablicy asocjacyjnej
 *
 * W petli szuka elementu o kluczu k podanym jako argument wywolania funkcji. Zwraca numer indeksu tego elementu.
 */
int tablica_asoc::nr_elementu(string k) {
	int i=0;
	while(tablica[i].klucz != k) {
		i++;
	}
	return i;
}

/*!
 * \brief Metoda dodajaca element (pare klucz typu string i wartosc int) do tablicy asocjacyjnej.
 * 
 * Dodaje element bedacy struktura para, a nastepnie dodaje go do wektora tablica.
 */
void tablica_asoc::dodaj(string k, int v) {
	para parka;
	parka.klucz=k;
	parka.wartosc=v;
	tablica.push_back(parka);
}

/*!
 * \brief Metoda usuwajaca element tablicy asocjacyjnej
 *
 * Uzywa funkcji nr_elementu, by znalezc indeks wektora. Ten indeks wskazuje metodzie erase (wbudowanej do struktury vector) ktory element wektora usunac.
 */
void tablica_asoc::usun(string k) {
	tablica.erase(tablica.begin()+nr_elementu(k));
}

/*!
 * \brief Metoda pobierajaca element o podanym w argumencie wywolania funkcji kluczu
 *
 * Zwraca wartosc elementu o indeksie wyznaczonym za pomoca funkcji nr_elementu.
 */
int tablica_asoc::pobierz(string k) {
	return tablica[nr_elementu(k)].wartosc;
}

/*!
 * \brief Metoda zamieniajaca dotychczasowa wartosc elementu na nowa
 *
 * Do klucza podanego jako argument wywolania funkcji przypisywana jest nowa wartosc. 
 */
void tablica_asoc::zmien(string k, int new_v) {
	tablica[nr_elementu(k)].wartosc=new_v;
}

/*!
 * \brief Metoda sprawdzajaca czy tablica jest pusta
 *
 */
bool tablica_asoc::czyPusta() {
	if (tablica.size()==0) return true;
	else return false;
}

/*!
 * \brief Metoda zwracajaca ilosc elementow tablicy asocjacyjnej
 *
 * Uzywa metody size(), wbudowanej do struktury vector
 */
int tablica_asoc::ileElementow() {
	return tablica.size();
}

/*!
 * \brief Metoda wyswietlajaca zawartosc tablicy
 *
 * Jest to metoda pomocnicza, pozwalajaca na podglad zawartosci tablicy na ekranie.
 */
void tablica_asoc::wyswietl() {
	if (czyPusta()==true) cout<<"Tablica pusta, nie ma elementow do wyswietlenia."<<endl;
		else {
	cout<<endl<<"Zawartosc tablicy:"<<endl;
	for (int i = 0; i < ileElementow(); i++) 
	cout<</*"Klucz: "<<tablica[i].klucz<<", */"Wartosc: "<<tablica[i].wartosc<<endl;
		}
}
