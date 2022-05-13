#include <vector>

template <typename T>
void bubbleSort(std::vector<T> &array)
{
    for (int i = array.size(); i > 0; i--)
    {
        for (int j = 0; j < i - 1; j++)
        {
            if (array[j + 1] < array[j])
            {
                T el = array[j];
                array[j] = array[j + 1];
                array[j + 1] = el;
            }
        }
    }
}

template <typename T>
void selectionSort(std::vector<T> &array)
{
    int min;
    for (auto i = 0; i < array.size() - 1; i++)
    {
        min = i;
        for (auto j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        std::swap(array[i], array[min]);
    }
}

template <typename T>
void merge(std::vector<T> &array, unsigned int left, unsigned int middle, unsigned int right)
{
    unsigned int leftLength = middle - left + 1;
    unsigned int rightLength = right - middle;
    std::vector<T> lArray(leftLength);
    std::vector<T> rArray(rightLength);
    for (unsigned int i = 0; i < leftLength; i++)
    {
        lArray[i] = array[i + left];
    }
    for (unsigned int j = 0; j < rightLength; j++)
    {
        rArray[j] = array[j + middle + 1];
    }
    unsigned int l = 0;
    unsigned int r = 0;
    unsigned int k = left;
    while (l < leftLength && r < rightLength)
    {
        if (lArray[l] < rArray[r])
        {
            array[k] = lArray[l];
            l++;
        }
        else
        {
            array[k] = rArray[r];
            r++;
        }
        k++;
    }
    while (l < leftLength)
    {
        array[k] = lArray[l];
        l++;
        k++;
    }
    while (r < rightLength)
    {
        array[k] = rArray[r];
        r++;
        k++;
    }
}

template <typename T>
void mergeSort_help(std::vector<T> &array, unsigned int left, unsigned int right)
{
    if (left < right)
    {
        unsigned int middle = (left + right) / 2;
        mergeSort_help(array, left, middle);
        mergeSort_help(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}

template <typename T>
void mergeSort(std::vector<T> &array)
{
    mergeSort_help(array, 0, array.size() - 1);
}
