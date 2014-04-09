__start__: tab_asocjacyjna
	./tab_asocjacyjna

tab_asocjacyjna: tablica_asoc.o main.o
	c++ main.o tablica_asoc.o -o tab_asocjacyjna

tablica_asoc.o: tablica_asoc.cpp
	c++ -c tablica_asoc.cpp -o tablica_asoc.o

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o

