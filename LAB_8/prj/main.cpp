#include "graf.hh"

using namespace std;

/* \file
 * \brief Plik z funkcja main
 */
int main()
{
graf pierwszy;

int roz;
int V;

cout<<"Jaki rozmiar grafu?: "<<endl;
cin>>roz;

for (int i=0; i<roz; i++)
{	cout<<"Podaj wierzcholek: "<<endl;
cin>>V;
pierwszy.dodaj_wierzcholek(V);
}

int vv1, vv2, ww;
cout<<"Podaj krawedz: "<<endl;
cout<<"Wierzcholek 1: "<<endl;
cin>>vv1;
cout<<"Wierzcholek 2: "<<endl;
cin>>vv2;
cout<<"Waga: "<<endl;
cin>>ww;
pierwszy.dodaj_krawedz(vv1, vv2, ww);

int V1, V2;
cout<<"Czy wierzcholki sa polaczone? Podaj pierwszy: "<<endl;
cin>>V1;
cout<<"Podaj drugi: "<<endl;
cin>>V2;

if(pierwszy.czy_polaczone(V1, V2)==1) 
	{cout<<"Niepolaczone"<<endl;}
else cout<<"Polaczone"<<endl;

return 0;
}
