__start__: graf
	./graf

graf: graf.o main.o
	c++ main.o graf.o -o graf

main.o: main.cpp
	c++ -c main.cpp -o main.o

clean:
	rm -f *.o
