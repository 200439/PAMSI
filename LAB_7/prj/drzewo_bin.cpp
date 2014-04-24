#include "drzewo_bin.hh"

/*!
* \file
* \brief Metody klasy drzewo_bin
*
*/

using namespace std;

/*! 
 * \brief Wstawia nowe wezly
 *
 * Aby zachowac strukture drzewa binarnego nowe wezly sa wstawiane tak, by po prawej stronie dodanego wezla znajdowaly sie tylko wezly o
 * wiekszej wartosci, a po lewej o mniejszej.
 */
void drzewo_bin::wstaw_wezel(wezel*& drzewo, int v) {
    if (!drzewo) {
        drzewo = new wezel(v);
        return;
    }

    if (drzewo->wartosc == v)
        return;
    
    if (v < drzewo->wartosc) {
        wstaw_wezel(drzewo->lewa, v);
    }
    
	else
        wstaw_wezel(drzewo->prawa, v);
}

/*! 
 * \brief Dodaje element do drzewa binarnego
 *
 */
void drzewo_bin::dodaj(int v) {
    wstaw_wezel(korzen, v);
}

/*! 
 * \brief Znajduje dany wezel
 *
 */
int drzewo_bin::znajdz(int v) {
    wezel* drzewo = korzen;
    
    while (drzewo) {
        if (drzewo->wartosc == v)
            return drzewo->wartosc;
        
        else if(v < drzewo->wartosc)
            drzewo = drzewo->lewa;
        
        else
            drzewo = drzewo->prawa;
    }
	return -999999; // sygnalizacja bledu (nieistnienie podanej wartosci do znalezienia)
}

/*!
 * \brief Wyswietla wartosc
 */
void drzewo_bin::wyswietl(int v) {
	cout<<"Wartosc: "<<znajdz(v)<<endl;
}
