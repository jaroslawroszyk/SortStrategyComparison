#pragma once
#include <vector>

namespace strategy
{
    class SortStrategy
    {
    public:
        virtual void sort(std::vector<int> &) = 0;
        virtual ~SortStrategy() = default;
    };
} // namespace strategy
