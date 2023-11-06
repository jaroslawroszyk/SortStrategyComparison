#include "Sort/BubbleSort.hpp"
#include <vector>

namespace algorithm
{
void BubbleSort::sort(std::vector<int> &data)
{
    int size = data.size();
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}
} // namespace algorithm
