#include"quick_sort.hh"
using namespace std;

/*! \brief Dzieli tablice
 *
 * Dzieli tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x. Kiedy i >= j
 * zwracamy j jako punkt podzialu tablicy
 * 
 */
int quick_sort::podzial(int *tablica, int m, int n) {
	int x = tablica[m]; 
	int i = m; 
	int j = n;
	int tmp; 
	
	while (1) {
		
		while (tablica[j] > x) j--;
		while (tablica[i] < x) i++;
		if (i < j) {
		  tmp = tablica[i];
		  tablica[i]=tablica[j];
		  tablica[j]=tmp;
		  i++;
		  j--;
		}
		else return j;
	}
}

/*! \brief Sortuje tablice algorytmem quick_sort
 *
 * Dzieli tablice na dwie czesci; pivot to punkt srodkowy. Wywoluje rekurencyjnie quick_sort dla pierwszej czesci tablicy oraz dla drugiej.
 */
void quick_sort::sortowanie(int *tablica, int m, int n) {
	int pivot;
	//cout<<"Pivot dla sort1: "<<pivot<<endl;
	if (m < n) {  
	  pivot = podzial(tablica, m, n);
	  sortowanie(tablica, m, pivot);
	  sortowanie(tablica, pivot+1, n);
	}
}
