#pragma once
#include "SortStrategy.hpp"
#include <memory>

namespace context
{
    class SortingContext
    {
    public:
        SortingContext(std::unique_ptr<strategy::SortStrategy>);
        SortingContext() = default;

        void setSortStrategy(std::unique_ptr<strategy::SortStrategy>);
        void sortData(std::vector<int> &);

    private:
        std::unique_ptr<strategy::SortStrategy> sortStrategy;
    };
} // namespace context
