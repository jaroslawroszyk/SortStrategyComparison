#include "SortingContext.hpp"
#include "SortStrategy.hpp"
#include <iostream>
#include <memory>

namespace context
{
SortingContext::SortingContext(std::unique_ptr<strategy::SortStrategy> sortStrategy) : sortStrategy(std::move(sortStrategy))
{
}

void SortingContext::setSortStrategy(std::unique_ptr<strategy::SortStrategy> strategy)
{
    sortStrategy = std::move(strategy);
}

void SortingContext::sortData(std::vector<int> &data)
{
    if (sortStrategy)
    {
        sortStrategy->sort(data);
    }
    else
    {
        std::cout << "Sort strategy not set." << std::endl;
    }
}
} // namespace context
