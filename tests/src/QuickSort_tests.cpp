#include "gtest/gtest.h"
#include "Sort/QuickSort.hpp"
#include "SortingContext.hpp"
#include <memory>
#include <vector>
#include <utility>

using namespace ::testing;
using namespace context;

struct QuickSortTests : public ::testing::TestWithParam<std::pair<std::vector<int>, std::vector<int>>>
{
    std::unique_ptr<algorithm::QuickSort> quickSort;
    SortingContext sortingContext;

    void SetUp() override
    {
        quickSort = std::make_unique<algorithm::QuickSort>();
        sortingContext = SortingContext(std::move(quickSort));
    }
};

TEST_P(QuickSortTests, SortVector)
{
    std::vector<int> data = GetParam().first;
    std::vector<int> expected = GetParam().second;

    sortingContext.sortData(data);
    EXPECT_EQ(data, expected);
}

INSTANTIATE_TEST_SUITE_P(
    SortTestCases,
    QuickSortTests,
    ::testing::Values(
        std::make_pair(std::vector<int>(), std::vector<int>()),
        std::make_pair(std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_pair(std::vector<int>{5, 4, 3, 2, 1}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_pair(std::vector<int>{9, 7, 2, 1, 5, 4, 9}, std::vector<int>{1, 2, 4, 5, 7, 9, 9}),
        std::make_pair(std::vector<int>{9, 7, 2, 1, 5, 5, 4, 9}, std::vector<int>{1, 2, 4, 5, 5, 7, 9, 9})));
