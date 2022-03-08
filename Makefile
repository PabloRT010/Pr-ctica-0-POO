CXX = g++
CXXFLAGS = -std=c++17

fecha.o: fecha.cpp fecha.hpp
	$(CXX) -c $(CXXFLAGS) fecha.cpp
main.o: main.cpp fecha.hpp
	$(CXX) -c $(CXXFLAGS) main.cpp
pruebaFecha: fecha.o main.o
	$(CXX) -o pruebaFecha fecha.o main.o
clean:
	rm -rf main.o fecha.o pruebaFecha core*~