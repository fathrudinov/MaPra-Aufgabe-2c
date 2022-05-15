CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2 -fno-inline -fPIC -fPIE

test: unit.o student.o Hauptprogramm.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

student.o: student.cpp student.h
	$(CXX) $(CXXFLAGS) -c $<

Hauptprogramm.o: Hauptprogramm.cpp sort.h mapra_test.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f student.o Hauptprogramm.o test

