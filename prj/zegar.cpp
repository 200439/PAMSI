#include"zegar.hh"

using namespace std;

/*!
 * \file
 * \brief Definicje funkcji klasy zegar
 *
 */

/*!
 * \brief Pobiera czas i zapisuje w zmiennej t1
 */
void zegar::start() {
		gettimeofday(&stoper, NULL);
		t1=stoper.tv_usec; }

/*!
 * \brief Pobiera czas i zapisuje w zmiennej t2 oraz wylicza roznice t2-t1
 */
void zegar::stop() {
		gettimeofday(&stoper, NULL);
		t2=stoper.tv_usec;
		czas=t2-t1; }

/*!
 * \brief Wyswietla czas na ekranie
 */
void zegar::wyswietl() {
		cout<<"Czas dzialania algorytmu: "<<czas<<"us."<<endl; }

/*!
 * \brief Zapisuje czas do pliku "wynik.csv"
 */
void zegar::zapisz_wynik(){
		wynik.open("wynik.csv", ios::app);
		wynik<<czas<<endl; }

void zegar::zapisz_wynik(const char* nazwa){
		wynik.open(nazwa, ios::app);
		wynik<<czas<<endl; }
