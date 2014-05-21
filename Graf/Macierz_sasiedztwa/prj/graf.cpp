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
void graf::dodaj_wierzcholek(int v) {	
	wierzcholek nowy;
	wierzcholki.push_back(nowy);
	wierzcholki[v].wartosc=v;

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

/* \brief Funkcja wypisujaca sasiadow podanego wierzcholka v
 *
 */
void graf::sasiedztwo(int v) {
	bool sasiad=false;
	cout<<"Sasiedzi wierzcholka "<<v<<": ";
	for(int i=0; i<wierzcholki.size(); i++) {
		if(macierz_sasiedztwa[v][i]==1) {
		cout<<i<<" ";
		sasiad=true;
		}
	}
	if(sasiad=false)
	cout<<"Brak sasiadow."<<endl;
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
