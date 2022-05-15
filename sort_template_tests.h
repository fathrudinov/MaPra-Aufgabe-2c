#include <fstream>
#include "unit.h"
#include "student.h"
#include "mapra_test.h"
#include "sort_template.h"

using namespace mapra;

class sort_template_tests
{
private:
    std::vector<std::string> vect;
    std::vector<double> vect1;
    std::vector<Student> vect2;

public:
    sort_template_tests()
    {
        std::ifstream file("strings.txt");
        std::ifstream file1("doubles.txt");
        std::ifstream file2("studenten.txt");
        Read(file, vect);
        Read(file1, vect1);
        Read(file2, vect2);
    }
    void bubbleSort_Template_Tests()
    {
        std::cout << "strings";
        bubbleSort(vect);
        CheckSolution(vect);

        std::cout << "doubles";
        bubbleSort(vect1);
        CheckSolution(vect1);
        
        std::cout << "student";
        bubbleSort(vect2);
        CheckSolution(vect2);
    };
    void selectionSort_Template_Tests()
    {
        std::cout << "strings";
        selectionSort(vect);
        CheckSolution(vect);

        std::cout << "doubles";
        selectionSort(vect1);
        CheckSolution(vect1);
        
        std::cout << "student";
        selectionSort(vect2);
        CheckSolution(vect2);
    };
    void mergeSort_Template_Tests()
    {
        std::cout << "strings";
        mergeSort(vect);
        CheckSolution(vect);

        std::cout << "doubles";
        mergeSort(vect1);
        CheckSolution(vect1);
        
        std::cout << "student";
        mergeSort(vect2);
        CheckSolution(vect2);
    };
};