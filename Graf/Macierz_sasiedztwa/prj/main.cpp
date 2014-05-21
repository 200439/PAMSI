#include "graf.hh"

/* \file
 * \brief Plik glowny programu
 *
 * Pozwala na przetestowanie struktury grafu opartego na macierzy sasiedztwa
 */

/* \brief Funkcja glowna programu
 */
int main() {
	graf pierwszy;
	int roz;

cout<<"Jaki rozmiar grafu?: "<<endl;
cin>>roz;

int wierzcholki[roz];
int wagi[roz];

for (int i=0; i<roz; i++) {
	wierzcholki[i] = i;
	pierwszy.dodaj_wierzcholek(wierzcholki[i]);
}

cout<<"Dodaje wierzcholki:"<<endl;
for (int i=0; i<roz; i++) {
	cout<<wierzcholki[i]<<" ";
}
cout<<endl;

cout<<"Dodaje krawedzie:"<<endl;
for (int i=0, j=1; i<roz, j<roz-1; i++, j++) {
	wagi[i] = i;
	pierwszy.dodaj_krawedz(wierzcholki[i], wierzcholki[j], wagi[i]);
}

cout<<"Sasiedztwo:"<<endl;
for (int i=0; i<roz; i++) {
	pierwszy.sasiedztwo(i);
}

cout<<"DFS - start"<<endl;
pierwszy.w_glab(0, roz);
cout<<"DFS - end"<<endl;

cout<<"BFS - start"<<endl;
pierwszy.wszerz(0, roz);
cout<<"BFS - end"<<endl;

return 0;
} 
