#include <vector>

template<typename T>
void bubbleSort(std::vector<T>& array);

template<typename T>
void selectionSort(std::vector<T>& array);

template<typename T>
void merge(std::vector<T>& array,unsigned int left,unsigned int middle,unsigned int right);

template <typename T>
void mergeSort_help(std::vector<T>& array,unsigned int left,unsigned int right);

template <typename T>
void mergeSort(std::vector<T>& array);
