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
	pojemnosc_plecaka=pojemnosc; cout<<"POJEMNOSC PLECAKA: "<<pojemnosc_plecaka<<endl;
	ilosc_przedmiotow=ilosc; cout<<"ILOSC RODZAJOW PRZEDMIOTOW: "<<ilosc_przedmiotow<<endl;

	przedmioty=new rzecz [ilosc_przedmiotow];
	
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
	delete [] przedmioty;

	for(int i=0; i<ilosc_przedmiotow+1; i++) delete [] P[i];
	delete [] P;
	
	for(int i=0; i<ilosc_przedmiotow+1; i++) delete [] Q[i];
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
        cin>>przedmioty[i].nazwa;
        cout<<"WAGA: ";
        cin>>przedmioty[i].waga;
        cout<<"WARTOSC: ";
        cin>>przedmioty[i].cena;
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
        przedmioty[i].nazwa=nazwy[i];
		cout<<przedmioty[i].nazwa<<endl;
        cout<<"WAGA: ";
        przedmioty[i].waga=wagi[i];
		cout<<przedmioty[i].waga<<endl;
        cout<<"WARTOSC: ";
        przedmioty[i].cena=ceny[i];
		cout<<przedmioty[i].cena<<endl;
        cout<<endl;
    }
}

/* \brief Funkcja realizujaca algorytm dynamicznego wybierania optymalnego zapakowania plecaka
 *
 */
void plecak::algorytm_dynamiczny() {
	for(int i=1; i<=ilosc_przedmiotow; ++i ) {
        for(int j=1; j<=pojemnosc_plecaka; ++j ) {
            if((j>=przedmioty[i-1].waga)&&(P[i-1][j]<(P[i][j-przedmioty[i-1].waga]+przedmioty[i-1].cena))) {
                P[i][j]=P[i][j-przedmioty[i-1].waga]+przedmioty[i-1].cena;
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
 * Ostatni element tej tablicy, to szukane rozwiazanie.
 */
void plecak::wypisz_tablice() {
	cout<<" Tablica wartosci upakowan plecaka: "<<endl;
   	for(int i=1; i<=ilosc_przedmiotow; ++i) {
        for(int j=1; j<=pojemnosc_plecaka; ++j ) cout<<P[i][j]<<" ";
        cout<<endl;
    }
}

/* \brief Funkcja wypisujaca wynik dzialania algorytmu dynamicznego
 *
 * Wypisuje na ekran obliczona maksymalna laczna wartosc przedmiotow mieszczacych sie w plecaku. Ponadto wylistowuje jakie poszczegolne 
 * przedmioty znalazly sie w plecaku i jaka maja wartosc.
 */
void plecak::wynik_dynamiczny() {
    cout<<endl<<"Maksymalna wartosc przedmiotow, ktore mieszcza sie w plecaku wg algorytmu dynamicznego: "<<P[ilosc_przedmiotow][pojemnosc_plecaka]<<endl;

	cout<<"Przedmioty znajdujace sie w plecaku i ich wartosci:"<<endl;
	
	int lp=1;
	int zapis_pojemnosc=pojemnosc_plecaka;
    while(pojemnosc_plecaka) {
        cout<<lp<<". "<<przedmioty[Q[ilosc_przedmiotow][pojemnosc_plecaka]-1].nazwa<<", wartosc: "<<przedmioty[Q[ilosc_przedmiotow][pojemnosc_plecaka]-1].cena<<", waga: "<<przedmioty[Q[ilosc_przedmiotow][pojemnosc_plecaka]-1].waga<<endl;
        pojemnosc_plecaka-=przedmioty[Q[ilosc_przedmiotow][pojemnosc_plecaka]-1].waga;
		lp++;
    }
	pojemnosc_plecaka=zapis_pojemnosc;
}

/* \brief Funkcja realizujaca algorytm zachlannego wybierania optymalnego zapakowania plecaka
 *
 */
void plecak::algorytm_zachlanny() {
	//WYLICZANIE WARTOSCI: cena/waga
	for(int i=0; i<ilosc_przedmiotow; ++i) przedmioty[i].cena_waga=(float)przedmioty[i].cena/(float)przedmioty[i].waga;
	
	//SORTOWANIE PRZEDMIOTOW WG WARTOSCI cena/waga
	rzecz tmp;
	for(int i=0; i<ilosc_przedmiotow-1; i++) {
		for(int j=0; j<ilosc_przedmiotow-1; j++) {
			if(przedmioty[j+1].cena_waga>przedmioty[j].cena_waga) {
   	                tmp=przedmioty[j];
   	                przedmioty[j]=przedmioty[j+1] ;
                    przedmioty[j+1]=tmp;
			}
		}
	} 

	//PAKOWANIE PLECAKA
	int licznik=pojemnosc_plecaka;
	for(int i=0; i<ilosc_przedmiotow; ++i) {
		if(przedmioty[i].ilosc*przedmioty[i].waga+przedmioty[i].waga<=licznik) {
			przedmioty[i].ilosc=1;
			while (przedmioty[i].ilosc*przedmioty[i].waga+przedmioty[i].waga<=licznik) {
				przedmioty[i].ilosc++;
			}
		licznik=licznik-przedmioty[i].ilosc*przedmioty[i].waga;
		}
	}
}

/* \brief Funkcja wypisujaca wynik dzialania algorytmu zachlannego
 *
 * Wypisuje na ekran obliczona maksymalna laczna wartosc przedmiotow mieszczacych sie w plecaku. Ponadto wylistowuje jakie poszczegolne 
 * przedmioty znalazly sie w plecaku i jaka maja wartosc.
 */
void plecak::wynik_zachlanny() {
	int wartosc=0;
	for(int i=0; i<ilosc_przedmiotow; ++i) {
		wartosc=wartosc+przedmioty[i].ilosc*przedmioty[i].cena;
	}
	cout<<endl<<"Maksymalna wartosc przedmiotow, ktore mieszcza sie w plecaku wg algorytmu zachlannego: "<< wartosc <<endl;

	cout<<"Przedmioty znajdujace sie w plecaku i ich wartosci:"<<endl;
	
	int lp=1;
	for(int i=0; i<ilosc_przedmiotow; ++i) {
		int ilosc_zapis=przedmioty[i].ilosc;
		while(przedmioty[i].ilosc) {
			cout<<lp<<". "<<przedmioty[i].nazwa<<", wartosc: "<<przedmioty[i].cena<<", waga: "<<przedmioty[i].waga<<endl;
			przedmioty[i].ilosc--;
			lp++;
		}
		przedmioty[i].ilosc=ilosc_zapis;
	}
}
