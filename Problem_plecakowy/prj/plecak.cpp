#include "plecak.hh"

/* \file
 * \brief Plik z definicjami metod klasy plecak
 * 
 */

using namespace std;

/* \brief Konstruktor obiektu klasy plecak.
 *
 * Tworzy tablice przechowujace dane o przedmiotach (nazwa, waga i cena) o wielkosciach podanych jako argument wywolania funkcji: ilosc.
 * Tworzone sa takze dwie tablice dwuwymiarowe, ktore przechowywac beda numery rzeczy wkladanych do plecaka jako ostatnie (Q) oraz wartosci
 * upakowan plecaka (P).
 */ 
plecak::plecak(int pojemnosc, int ilosc) {
	pojemnosc_plecaka=pojemnosc; 
	ilosc_przedmiotow=ilosc; 

	przedmioty->nazwa=new string[ilosc_przedmiotow];
   	przedmioty->waga=new int[ilosc_przedmiotow];
   	przedmioty->cena=new int[ilosc_przedmiotow];
	
	Q=new int *[ilosc_przedmiotow+1];
	   	for(int i=0; i<=ilosc_przedmiotow; ++i) {
			Q[i]=new int[pojemnosc_plecaka+1];
			Q[i][0]=0;
		}
 
   	P=new int *[ilosc_przedmiotow+1];
	   	for(int i=0; i<=ilosc_przedmiotow; ++i) {
			P[i]=new int[pojemnosc_plecaka+1];
			P[i][0]=0;
		}
}

/* \brief Destruktor obiektow klasy plecak.
 *
 * Usuwa wszystkie tablice dynamiczne.
 */
plecak::~plecak() {
	delete [] przedmioty->nazwa;
	delete [] przedmioty->waga;
	delete [] przedmioty->cena;
	for(int i=0; i<ilosc_przedmiotow+1; i++) delete [] P[i] ;
	delete [] P;
	
	for(int i=0; i<ilosc_przedmiotow+1; i++) delete [] Q[i] ;
	delete [] Q;
}

/* \brief Funkcja dodajaca przedmioty mozliwe do zapakowania do plecaka.
 *
 * Zapisuje kolejne dane dotyczace przedmiotow (nazwa, waga, cena).
 */
void plecak::dodaj_przedmioty() {
	for(int i=0; i<ilosc_przedmiotow; ++i) {
		cout<<i+1<<". przedmiot:"<<endl;
        cout<<"NAZWA: ";
        cin>>przedmioty->nazwa[i];
        cout<<"WAGA: ";
        cin>>przedmioty->waga[i];
        cout<<"WARTOSC: ";
        cin>>przedmioty->cena[i];
        cout<<endl;
    }
}

/* \brief Funkcja dodajaca przedmioty mozliwe do zapakowania do plecaka.
 *
 * Zapisuje kolejne dane dotyczace przedmiotow (nazwa, waga, cena) podane jako kolejne elementy tablic zadanych jako argumenty wywolania 
 * funkcji.
 */
void plecak::dodaj_przedmioty(string nazwy[], int wagi[], int ceny[]) {
	for(int i=0; i<ilosc_przedmiotow; ++i) {
		cout<<i+1<<". przedmiot:"<<endl;
        cout<<"NAZWA: ";
        przedmioty->nazwa[i]=nazwy[i];
		cout<<przedmioty->nazwa[i]<<endl;
        cout<<"WAGA: ";
        przedmioty->waga[i]=wagi[i];
		cout<<przedmioty->waga[i]<<endl;
        cout<<"WARTOSC: ";
        przedmioty->cena[i]=ceny[i];
		cout<<przedmioty->cena[i]<<endl;
        cout<<endl;
    }
}

/* \brief Funkcja realizujaca algorytm dynamicznego wybierania optymalnego zapakowania plecaka
 *
 * Jego dzialanie wyjasnione jest w sprawozdaniu.
 */
void plecak::algorytm_dynamiczny() {
	for(int i=1; i<=ilosc_przedmiotow; ++i ) {
        for(int j=1; j<=pojemnosc_plecaka; ++j ) {
            if((j>=przedmioty->waga[i-1])&&(P[i-1][j]<(P[i][j-przedmioty->waga[i-1]]+przedmioty->cena[i-1]))) {
                P[i][j]=P[i][j-przedmioty->waga[i-1]]+przedmioty->cena[i-1];
                Q[i][j]=i;
            }
            else {
                P[i][j]=P[i-1][j];
                Q[i][j]=Q[i-1][j];
            }
        }
	}
}

/* \brief Funkcja wypisujaca tablice wartosci upakowan plecaka
 *
 * Ostatni element tej tablicy, to szukane rozwiazanie.'
 */
void plecak::wypisz_tablice() {
	cout<<" Tablica wartosci upakowan plecaka: "<<endl;
   	for(int i=1; i<=ilosc_przedmiotow; ++i) {
        for(int j=1; j<=pojemnosc_plecaka; ++j ) cout<<P[i][j]<<" ";
        cout<<endl;
    }
}

/* \brief Funkcja wypisujaca wynik dzialania algorytmu
 *
 * Wypisuje na ekran obliczona maksymalna laczna wartosc przedmiotow mieszczacych sie w plecaku. Ponadto wylistowuje jakie poszczegolne 
 * przedmioty znalazly sie w plecaku i jaka maja wartosc.
 */
void plecak::wynik() {
    cout<<"Maksymalna wartosc przedmiotow, ktore mieszcza sie w plecaku: "<<P[ilosc_przedmiotow][pojemnosc_plecaka]<<endl;

	cout<<"Przedmioty znajdujace sie w plecaku i ich wartosci:"<<endl;
	
	int i=1;
    while(pojemnosc_plecaka) {
        cout<<i<<". "<<przedmioty->nazwa[Q[ilosc_przedmiotow][pojemnosc_plecaka]-1]<<", wartosc: "<<przedmioty->cena[Q[ilosc_przedmiotow][pojemnosc_plecaka]-1]<<endl;
        pojemnosc_plecaka-=przedmioty->waga[Q[ilosc_przedmiotow][pojemnosc_plecaka]-1];
		i++;
    }
}
