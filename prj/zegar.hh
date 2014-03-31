#ifndef ZEGAR_HH
#define ZEGAR_HH
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <cstdlib>
using namespace std;

/*!
 * \file
 * \brief Definicja klasy zegar
 *
 */


/*! \brief Definicja klasy zegar
 * 
 */
class zegar {
	public:	
	timeval stoper;	
	long double t1, t2, czas, sekundy;	
	ofstream wynik;

	void start();
	void stop();
	void wyswietl();
	void zapisz_wynik();
	void zapisz_wynik(const char* nazwa);
	
};
#endif
