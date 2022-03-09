CXX = g++
CXXFLAGS = -std=c++17

fecha.o: fechav2.cpp fecha.hpp
	$(CXX) -c $(CXXFLAGS) fechav2.cpp
main.o: main.cpp fecha.hpp
	$(CXX) -c $(CXXFLAGS) main.cpp
fecha-cadenaconsola.o:
	$(CXX) -c $(CXXFLAGS) fecha-cadenaconsola.cpp
test-fechacadena-consola.o: test-fechacadena-consola.cpp fecha.hpp
	$(CXX) -c $(CXXFLAGS) main.cpp
pruebaFecha: fecha.o test-fechacadena-consola.o
	$(CXX) -o pruebaFecha fecha.o main.o
clean:
	rm -rf main.o fechav2.o pruebaFecha test.o core*~