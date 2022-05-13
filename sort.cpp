#include "sort.h"

void bubbleSort(std::vector<unsigned int>& array)
{
	for(int i = array.size(); i > 0; i--)
		for(int j = 0; j < i; j++)
			if(array[j] > array[j + 1])
				std::swap(array[j], array[j + 1]);

}

void selectionSort(std::vector<unsigned int>& array)
{
    int min;
	for(int i = 0; i < array.size() - 1; i++)
        {
            min = i;
            for(int j = i + 1; j < array.size(); j++)
            {
                if(array[j] < array[min]) min = j;
            }
            std::swap(array[i],array[min]);
        }
}

void insertionSort(std::vector<unsigned int>& array)
{
	for(int i = 1; i < array.size(); i++)
            for(int j = i - 1; j >= 0; j--)
            {
                if(array[j + 1] < array[j])
                {
                    std::swap(array[j],array[j + 1]);
                    continue;
                }
            }
}

void heapify(std::vector<unsigned int>& array, int length, int i)   // length ist die Länge des Vektors ohne schon sortierten Elementen
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < length && array[l] > array[largest])
		largest = l;

	if (r < length && array[r] > array[largest])
		largest = r;

	if (largest != i)
	{
		std::swap(array[i], array[largest]);
		heapify(array, length, largest);
	}
}

void heapSort(std::vector<unsigned int>& array)
{
    for (int i = array.size() / 2 - 1; i >= 0; i--)     // durchlaufe alle Knoten, die keine Blätter sind, levelweise vom zweithöchsten Level3 bis zur Wurzel auf Level 0
        heapify(array, array.size(), i);                              // wende auf den jeweiligen Knoten 𝑖 die Funktion Heapify(i) an, um den ganzen Heap sortieren

	for (int i = array.size()  - 1; i > 0; i--)
	{
		std::swap(array[0], array[i]);
		heapify(array, i, 0);
	}
}

int partition(std::vector<unsigned int>& array, int min, int max)
{
	int pivot = array[max];
	int i = (min - 1);
	for (int j = min; j <= max; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i + 1], array[max]);
	return (i + 1);
}

void quickSort_Help(std::vector<unsigned int>& array, int min, int max)
{
	if (min < max)
	{
		int i = partition(array, min, max);
		quickSort_Help(array, min, i - 1);
		quickSort_Help(array, i + 1, max);
	}
}

void quickSort(std::vector<unsigned int>& array)
{
    quickSort_Help(array, 0, array.size() - 1);
}

void medianQuickSort_Help(std::vector<unsigned int>& array, int min, int max)
{
    if (min < max)
	{
		int middle = (max + min) / 2;
		if (array[middle] < array[min])
		{
			std::swap(array[middle], array[min]);
		}
		if (array[max] < array[min])
		{
			std::swap(array[min], array[max]);
		}
		if (array[max] < array[middle])
		{
			std::swap(array[middle], array[max]);
		}
		int i = partition(array, min, max);
		medianQuickSort_Help(array, min, i - 1);
		medianQuickSort_Help(array, i + 1, max);
	}
}

void medianQuickSort(std::vector<unsigned int>& array)
{
    medianQuickSort_Help(array, 0, array.size() - 1);
}


void merge(std::vector<unsigned int>& array, int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	unsigned int *L = new unsigned int[n1];
	unsigned int *R = new unsigned int[n2];
	for (i = 0; i < n1; i++)
		L[i] = array[l + i];
	for (j = 0; j < n2; j++)
		R[j] = array[m + 1 + j];
	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}
	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}
}
void merger(std::vector<unsigned int>& array, int l, int r)
{
	int len = r - l + 1;
	int m = int((r + l) / 2);
	if (len > 1)
	{
		merger(array, l, m);
		merger(array, m + 1, r);
		merge(array, l, m, r);
	}
}
void mergeSort(std::vector<unsigned int>& array)
{
    int length = array.size();
	int m = int(length / 2);
	merger(array, 0, m);
	merger(array, m + 1, length - 1);
	merge(array, 0, m, length - 1);
}
