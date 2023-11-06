#include "Sort/QuickSort.hpp"
#include <vector>

namespace algorithm
{
    void QuickSort::sort(std::vector<int> &data)
    {
        int low = 0;
        int high = data.size() - 1;
        quickSort(data, low, high);
    }

    void QuickSort::quickSort(std::vector<int> &data, int low, int high)
    {
        if (low < high)
        {
            int pivotIndex = partition(data, low, high);
            quickSort(data, low, pivotIndex - 1);
            quickSort(data, pivotIndex + 1, high);
        }
    }

    int QuickSort::partition(std::vector<int> &data, int low, int high)
    {
        int pivot = data[high];
        int i = low - 1;

        for (int j = low; j < high; j++)
        {
            if (data[j] < pivot)
            {
                i++;
                std::swap(data[i], data[j]);
            }
        }

        std::swap(data[i + 1], data[high]);
        return i + 1;
    }
} // namespace algorithm
