#include "graf.hh"

using namespace std;

/* \file
 * \brief Plik z funkcja main
 */
int main() {

	int roz;

cout<<"Jaki rozmiar grafu?: "<<endl;
cin>>roz;
graf pierwszy;

int wierzcholki[roz];
int wagi[roz];

for (int i=0; i<roz; i++) {
	wierzcholki[i] = i;
	pierwszy.dodaj_wierzcholek(wierzcholki[i]);
}

cout<<"Wierzcholki:"<<endl;
for (int i=0; i<roz; i++) {
	cout<<wierzcholki[i]<<" ";
}
cout<<endl;

for (int i=0, j=1; i<roz, j<roz-1; i++, j++) {
	wagi[i] = i;
	pierwszy.dodaj_krawedz(wierzcholki[i], wierzcholki[j], wagi[i]);
}
cout<<"DODALEM"<<endl;

pierwszy.w_glab(wierzcholki[0], wierzcholki[roz]);
cout<<"WYKONALEM"<<endl;

pierwszy.wszerz(wierzcholki[0], wierzcholki[roz]);
cout<<"TO TEZ WYKONALEM"<<endl;



return 0;
}

