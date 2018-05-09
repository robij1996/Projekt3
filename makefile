
LIBS=-lsfml-graphics -lsfml-window -lsfml-system
CXXFLAGS= -g -Iinc -Wall -pedantic -std=c++11

__start__:a.out
	./a.out 



a.out: obj obj/main.o  obj/Plansza.o 
           
	g++ -g -Wall -pedantic -std=c++11   obj/main.o obj/Plansza.o -lsfml-graphics -lsfml-window -lsfml-system
                      
obj/main.o: src/main.cpp inc/Plansza.hh
	g++ -c ${CXXFLAGS} -o  obj/main.o src/main.cpp 

obj/Plansza.o: src/Plansza.cpp inc/Plansza.hh
	g++ -c ${CXXFLAGS} -o  obj/Plansza.o src/Plansza.cpp 