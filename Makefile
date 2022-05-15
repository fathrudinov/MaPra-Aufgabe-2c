CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2 -fno-inline -fPIC -fPIE

test: unit.o student.o main.o
	$(CXX) $(CXXFLAGS) $^ -o $@ 

student.o: student.cpp student.h
	$(CXX) $(CXXFLAGS) -c $<

main.o: main.cpp sort_template.h mapra_test.h sort_template_tests.h
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f student.o main.o test

