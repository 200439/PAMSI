__start__: struktury
	./struktury

struktury: drzewo_bin.o tablica_asoc.o tablica_hasz.o zegar.o main.o
	c++ main.o zegar.o tablica_hasz.o tablica_asoc.o drzewo_bin.o -o struktury

tablica_asoc.o: tablica_asoc.cpp
	c++ -c tablica_asoc.cpp -o tablica_asoc.o

tablica_hasz.o: tablica_hasz.cpp
	c++ -c -std=c++0x tablica_hasz.cpp -o tablica_hasz.o

drzewo_bin.o: drzewo_bin.cpp
	c++ -c drzewo_bin.cpp -o drzewo_bin.o

zegar.o: zegar.cpp
	c++ -c zegar.cpp -o zegar.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o

