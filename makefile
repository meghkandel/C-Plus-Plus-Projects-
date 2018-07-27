CXX = g++
CXXFLAGS = -Wall

proj2: Pokemon.o MyPokemon.o
	$(CXX) $(CXXGLAGS) Pokemon.o MyPokemon.o proj2.cpp -o proj2

Pokemon.o: Pokemon.cpp Pokemon.h
	$(CXX) $(CXXFLAGS) -c Pokemon.cpp

MyPokemon.o: MyPokemon.cpp MyPokemon.h
	$(CXX) $(CXXFLAGS) -c MyPokemon.cpp

clean:
	rm *.o
	rm *~

run:
	./proj2