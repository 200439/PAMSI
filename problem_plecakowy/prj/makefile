__start__: plecak
	./plecak

plecak: plecak.o main.o
	c++ main.o plecak.o -o plecak

main.o: main.cpp
	c++ -c main.cpp -o main.o

plecak.o: plecak.cpp
	c++ -c plecak.cpp -o plecak.o

clean:
	rm -f *.o
