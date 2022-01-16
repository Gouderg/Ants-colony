ants: main.o colony.o ant.o barrier.o pvector.o
	g++ $^ -o $@ -lsfml-graphics -lsfml-window -lsfml-system

main.o: src/main.cpp include/colony.hpp
	g++ -Wall -std=c++11 -c $<

colony.o: src/colony.cpp include/colony.hpp
	g++ -Wall -std=c++11 -c $<

ant.o: src/ant.cpp include/ant.hpp
	g++ -Wall -std=c++11 -c $<

barrier.o: src/barrier.cpp include/barrier.hpp
	g++ -Wall -std=c++11 -c $<

pvector.o: src/pvector.cpp include/pvector.hpp
	g++ -Wall -std=c++11 -c $<

clean:
	rm *.o ants

cleaner:
	rm *.o

r: ants cleaner
