#include <iostream>
#include "sort_template_tests.h"

// wurde mit VIM bearbeitet


 int main()
{
    unsigned int algo;

    std::cout << "Select sorting algorithm\n1)bubbleSort\n2)selectionSort\n3)mergeSort\n";
    std::cin >> algo;
    sort_template_tests test = sort_template_tests();

    switch (algo)
    {
    case 1:
        test.bubbleSort_Template_Tests();
    case 2:
        test.selectionSort_Template_Tests();
    case 3:
        test.mergeSort_Template_Tests();
    }
}
