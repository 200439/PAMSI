#include "graf.hh"

/*!
 * \file
 * \brief Definicje metod klasy graf opartej na macierzy sasiedztwa.
 */

/* \brief Funkcja tworzaca nowa macierz
 *
 */
void graf::stworz_macierz(char ** macierz) {
	macierz=new char * [wierzcholki.size()];
		for(int i=0; i<wierzcholki.size(); i++) {
			macierz[i]=new char [wierzcholki.size()];
			for(int j=0; j<wierzcholki.size(); j++) macierz[i][j]=0;
		}
}

/* \brief Funkcja dodajaca wierzcholek do grafu
 *
 */
void graf::dodaj_wierzcholek(int v, int x, int y) {	
	wierzcholek nowy;
	wierzcholki.push_back(nowy);
	wierzcholki[v].wartosc=v;
	wierzcholki[v].wspolrzedna_x=x;
	wierzcholki[v].wspolrzedna_y=y;

	if(wierzcholki.size()==0) stworz_macierz(macierz_sasiedztwa);
	else {
		//pomocnicza macierz:
		char ** tmp;
		tmp=new char * [wierzcholki.size()];
		for(int i=0; i<wierzcholki.size(); i++) {
			tmp[i]=new char [wierzcholki.size()];
			for(int j=0; j<wierzcholki.size(); j++) tmp[i][j]=0;
		}
		//przepisanie starej macierzy do pomocniczej:
		for(int i=0; i<wierzcholki.size()-1; i++) {
			for(int j=0; j<wierzcholki.size()-1; j++) tmp[i][j]=macierz_sasiedztwa[i][j];
		}
		//nowa, wieksza macierz:
		macierz_sasiedztwa=new char * [wierzcholki.size()];
		for(int i=0; i<wierzcholki.size(); i++) {
			macierz_sasiedztwa[i]=new char [wierzcholki.size()];
			for(int j=0; j<wierzcholki.size(); j++) macierz_sasiedztwa[i][j]=tmp[i][j];
		}
		delete [] tmp;
	}
}

/* \brief Funkcja dodajaca krawedz o podanym poczatku v1, koncu v2 oraz wadze w.
 *
 */
void graf::dodaj_krawedz(int v1, int v2, int w) {
	krawedz nowa;
	macierz_sasiedztwa[v1][v2] = 1;
	macierz_sasiedztwa[v2][v1] = 1;

	nowa.v1=&wierzcholki[v1];
	nowa.v2=&wierzcholki[v2];
	nowa.waga=w;

	krawedzie.push_back(nowa);
}

/* \brief Funkcja usuwajaca krawedz
 *
 */
void graf::usun_krawedz(int v1, int v2)	{
	macierz_sasiedztwa[v1][v2]=0;
	macierz_sasiedztwa[v2][v1]=0;

	for(int i=0; i<krawedzie.size(); i++) {
		if((krawedzie[i].v1->wartosc==v1&&krawedzie[i].v2->wartosc==v2)||(krawedzie[i].v1->wartosc==v2&&krawedzie[i].v2->wartosc==v1)) {
		krawedzie.erase(krawedzie.begin()+i);
		}
	}
}

/* \brief Funkcja sprawdza, czy wierzcholki v1 i v2 sa polaczone.
 *
 * Wierzcholki sa polaczone krawedzia, gdy element macierzy sasiedztwa o indeksie [v1][v2] jest rowny 1.
 */
bool graf::czy_polaczone(int v1, int v2) {
	if(macierz_sasiedztwa[v1][v2]==1) return true;
	else return false;
}

/* \brief Funkcja zwracajaca wektor wierzcholkow, ktore sa sasiadami wierzcholka v
 *
 */
vector<int> graf::sasiedztwo(int v) {
	int sasiad=0;
	vector <int> tmp;
	for(int i=0; i<wierzcholki.size(); i++) {
		if(macierz_sasiedztwa[v][i]==1) {
			sasiad++;
			tmp.push_back(i);
		}
		if(sasiad){
			int tablica[sasiad];
			for(int i=0; i<sasiad; i++) {
				tablica[i]=tmp[i];
				return tmp;
			}
		}
	}
cout<<endl;
}

/* \brief Metoda wypisujaca na ekran wierzcholki, ktore sa sasiadami wierzcholka v podanego jako argument wywolania funkcji
 */
void graf::wypisz_sasiedztwo(int v) {
	bool sasiad=false;
	cout<<"Sasiedzi wierzcholka "<<v<<": ";
	for(int i=0; i<wierzcholki.size(); i++) {
		if(macierz_sasiedztwa[v][i]==1) {
			sasiad=true;
			cout<<i<<" ";
		}
		if(sasiad=false)
			cout<<"Brak sasiadow."<<endl;
	}
cout<<endl;
}

/* \brief Implementacja algorytmu przeszukiwania grafu w glab
 *
 */
int graf::nastepny_w_glab(int v) {
	int i;
 	
	for (i=wierzcholki.size()-1; i>=0; i--)
		if ((macierz_sasiedztwa[i][v]==1)&&(wierzcholki[i].odwiedzony==false)) {
			wierzcholki[i].odwiedzony=true;
	return i;
	}
	return -9999;
}

void graf::w_glab(int v1, int v2) {
	int tmp;
	int nastepny;

	if(v1==v2) {
		for(int i=0; i<wierzcholki.size(); i++)
		wierzcholki[i].odwiedzony=false;
	}

	else {
		wierzcholki[v1].odwiedzony=true;
		nastepny=nastepny_w_glab(v1);
		while (nastepny!=-9999) {
			stos_w_glab.push(nastepny);
			nastepny=nastepny_w_glab(v1);
		}

		if (!stos_w_glab.empty()) {
			tmp=stos_w_glab.top();
			stos_w_glab.pop();
			w_glab(tmp, v2);
		}
	}
}

/* \brief Implementacja algorytmu przeszukiwania grafu wszerz
 *
 */
void graf::wszerz(int v1, int v2) {
	wezel_wszerz *tmp, *poczatek, *koniec;

	tmp=new wezel_wszerz;
	tmp->wartosc=v1;
	poczatek=koniec=tmp;
	wierzcholki[v1].odwiedzony=true;

	while(poczatek) {
		if(poczatek->wartosc==v2) {
			for(int i=0; i<wierzcholki.size(); i++)
			wierzcholki[i].odwiedzony=false;
			poczatek=NULL;
		}

		else {
			v1=poczatek->wartosc;
			tmp=poczatek;
			poczatek=poczatek->nastepny;
			if(!poczatek) koniec=NULL;
			delete tmp;

			for(int i=0; i<(int)wierzcholki.size(); i++) {
				if(macierz_sasiedztwa[v1][i]==1 && wierzcholki[i].odwiedzony==false) {	
					tmp=new wezel_wszerz;
					tmp->wartosc=i;
					if(!koniec) poczatek=tmp;
				else koniec->nastepny=tmp;
					koniec=tmp;
					wierzcholki[i].odwiedzony=true;
				}
			}
		}	
	}
}

/* \brief Implementacja algorytmu A*
 */
void graf::A_star(int v1, int v2) {
	
	int koszt, koszt_min, aktualny;
	vector<int> lista_otwartych;
	vector<int> lista_zamknietych;

	lista_otwartych.push_back(v1);

	wierzcholki[v1].g=0;
	wierzcholki[v1].h=odleglosc(v1, v2); //heurystyka
	wierzcholki[v1].f=wierzcholki[v1].g+wierzcholki[v1].h;
	koszt_min=wierzcholki[v1].f;
	
	while(!lista_otwartych.empty()) {
		aktualny=lista_otwartych[0];
		koszt_min=wierzcholki[aktualny].f;
		for(int i=0; i<lista_otwartych.size(); i++) { 
			if(koszt_min>wierzcholki[lista_otwartych[i]].f) {	
				koszt_min=wierzcholki[lista_otwartych[i]].f;
				aktualny=lista_otwartych[i];
			}
		}
		if(aktualny==v2) {
			cout<<"Wierzcholek"<<aktualny<<"zostal odnaleziony"<<endl;
			cout<<endl;
			break;
		}

		lista_otwartych.erase(lista_otwartych.begin());
		lista_zamknietych.push_back(aktualny);

		for(int i=0; i<sasiedztwo(aktualny).size(); i++) {
			int sasiad=sasiedztwo(aktualny)[i];
			wierzcholki[sasiad].g=odszukaj_krawedz(aktualny, sasiad).waga + wierzcholki[aktualny].g;

			if(odszukaj_na_liscie(lista_zamknietych, sasiad)) continue;
			koszt=wierzcholki[aktualny].g + odszukaj_krawedz(aktualny, sasiad).waga;
			if(!odszukaj_na_liscie(lista_otwartych, sasiad) || koszt<wierzcholki[sasiad].g) {
				wierzcholki[sasiad].g=koszt;
				wierzcholki[sasiad].h=odleglosc(sasiad, v2);
				wierzcholki[sasiad].f=wierzcholki[sasiad].g + wierzcholki[sasiad].h;
				wierzcholki[sasiad].rodzic=&wierzcholki[aktualny];

				if(!odszukaj_na_liscie(lista_otwartych, sasiad)) lista_otwartych.push_back(sasiad); 
			}
		}
	}
}

/* \brief Metoda wypisujaca sciezke wyznaczona przez algorytm A*
 */
void graf::sciezka(int v1, int v2) {
	wierzcholek aktualny=wierzcholki[v2];
	vector<int> sciezka;

	sciezka.push_back(aktualny.wartosc);
	cout<<"Sciezka: "<<endl;
	while(aktualny.wartosc!=wierzcholki[v1].wartosc) {
		sciezka.push_back(aktualny.rodzic->wartosc);
		aktualny.rodzic=aktualny.rodzic->rodzic;
		aktualny.odwiedzony=aktualny.rodzic->odwiedzony;
		aktualny.wartosc=aktualny.rodzic->wartosc;
		aktualny.g=aktualny.rodzic->g;
		aktualny.h=aktualny.rodzic->h;
		aktualny.f=aktualny.rodzic->f;
	}

	sciezka.push_back(aktualny.wartosc);
	for(int i=sciezka.size()-1; i>=0; i--)
		cout<<sciezka[i]<<" ";
		cout<<endl;
}

/* \brief Metoda odnajdujaca element v w liscie podanych jako argumenty wywolania funkcji
 */
bool graf::odszukaj_na_liscie(vector <int> lista, int v) {
	if(!lista.empty())
		for(int i=0; i<lista.size(); i++)
			if(lista[i]==v) return true;
	return false;
}

/* \brief Metoda odnajdujaca krawedz
 */
graf::krawedz graf::odszukaj_krawedz(int v1, int v2) {
	for(int i=0; i<krawedzie.size(); i++) {
		if((krawedzie[i].v1->wartosc==v1&&krawedzie[i].v2->wartosc==v2)||(krawedzie[i].v1->wartosc==v2&&krawedzie[i].v2->wartosc==v1)) {
			return krawedzie[i];
		}
	}
	return krawedzie[1];
}

/* \brief Metoda obliczajaca odleglosc dwoch punktow. 
 * 
 * Jest to heurystyka potrzebna w algorytmie A*.
 */
int graf::odleglosc(int v1, int v2) {
	int x1, x2, y1, y2;
	x1=wierzcholki[v1].wspolrzedna_x;
	x2=wierzcholki[v2].wspolrzedna_x;

	y1=wierzcholki[v1].wspolrzedna_y;
	y2=wierzcholki[v2].wspolrzedna_y;

	return (sqrt((x1-x2)^2 + (y1-y2)^2));
}
