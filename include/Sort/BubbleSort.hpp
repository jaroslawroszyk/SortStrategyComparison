#pragma once
#include "SortStrategy.hpp"
#include <vector>

namespace algorithm
{
    class BubbleSort : public strategy::SortStrategy
    {
    public:
        void sort(std::vector<int> &) override;
    };
} // namespace algorithm
