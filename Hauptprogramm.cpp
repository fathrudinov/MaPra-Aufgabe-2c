#include <fstream>
#include "unit.h"
#include "student.h"
#include "mapra_test.h"
#include "sort.h"

using namespace mapra;

int main()
{
    unsigned int algo;
    std::cout << "Select sorting algorithm\n1)bubbleSort\n2)selectionSort\n3)mergeSort\n";
    std::cin >> algo;

    std::vector<std::string> vect = {};
    std::vector<double> vect1;
    std::vector<Student> vect2;

    std::ifstream file("strings.txt");
    std::ifstream file1("doubles.txt");
    std::ifstream file2("studenten.txt");

    switch (algo)
    {
    case 1:
        std::cout << "########################################\ngegebene Liste:\n";
        Read(file, vect);
        Print(std::cout, vect);
        bubbleSort(vect);
        std::cout << "########################################\nsortierte Liste:\n";
        Print(std::cout, vect);
        CheckSolution(vect);
        Print(std::cout, vect);
        std::cout << "doubles";
        Read(file1, vect1);
        bubbleSort(vect1);
        CheckSolution(vect1);
        Print(std::cout, vect1);
        std::cout << "student";
        Read(file2, vect2);
        bubbleSort(vect2);
        CheckSolution(vect2);
        Print(std::cout, vect2);
        break;

    case 2:
        Read(file, vect);
        selectionSort(vect);
        CheckSolution(vect);
        Print(std::cout, vect);
        std::cout << "doubles";
        Read(file1, vect1);
        selectionSort(vect1);
        CheckSolution(vect1);
        Print(std::cout, vect1);
        std::cout << "student";
        Read(file2, vect2);
        selectionSort(vect2);
        CheckSolution(vect2);
        Print(std::cout, vect2);
        break;
    case 3:
        Read(file, vect);
        mergeSort(vect);
        CheckSolution(vect);
        Print(std::cout, vect);
        std::cout << "doubles";
        Read(file1, vect1);
        mergeSort(vect1);
        CheckSolution(vect1);
        Print(std::cout, vect1);
        std::cout << "student";
        Read(file2, vect2);
        mergeSort(vect2);
        CheckSolution(vect2);
        Print(std::cout, vect2);
        break;
    }
}
