#pragma once
#include "SortStrategy.hpp"
#include <vector>

namespace algorithm
{
    class QuickSort : public strategy::SortStrategy
    {
    public:
        void sort(std::vector<int> &) override;

    private:
        void quickSort(std::vector<int> &, int low, int high);

        int partition(std::vector<int> &, int low, int high);
    };
} // namespace algorithm
