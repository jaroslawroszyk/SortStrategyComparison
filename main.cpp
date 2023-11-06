#include "Sort/BubbleSort.hpp"
#include "Sort/QuickSort.hpp"
#include "SortingContext.hpp"
#include "SortStrategy.hpp"
#include "Utilities/utilities.hpp"
#include <iostream>
#include <memory>

auto main() -> int
{
  std::vector<int> data = {9, 7, 2, 1, 5, 4, 9};
  std::unique_ptr<algorithm::BubbleSort> bubbleSort = std::make_unique<algorithm::BubbleSort>();
  std::unique_ptr<algorithm::QuickSort> quickSort = std::make_unique<algorithm::QuickSort>();

  context::SortingContext sortingContext(std::move(bubbleSort));

  sortingContext.sortData(data);
  utils::print(data);

  data = {9, 7, 2, 1, 5, 4, 9};
  utils::print(data);

  sortingContext.setSortStrategy(std::move(quickSort));
  sortingContext.sortData(data);
  utils::print(data);

  return 0;
}
