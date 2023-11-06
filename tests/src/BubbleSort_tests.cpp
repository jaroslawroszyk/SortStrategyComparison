#include "gtest/gtest.h"
#include "Sort/BubbleSort.hpp"
#include "SortingContext.hpp"
#include <memory>
#include <vector>
#include <utility>

using namespace ::testing;
using namespace context;

struct BubbleSortTests : public ::testing::TestWithParam<std::pair<std::vector<int>, std::vector<int>>>
{
    std::unique_ptr<algorithm::BubbleSort> bubbleSort;
    SortingContext sortingContext;

    void SetUp() override
    {
        bubbleSort = std::make_unique<algorithm::BubbleSort>();
        sortingContext = SortingContext(std::move(bubbleSort));
    }
};

TEST_P(BubbleSortTests, SortVector)
{
    std::vector<int> data = GetParam().first;
    std::vector<int> expected = GetParam().second;

    sortingContext.sortData(data);
    EXPECT_EQ(data, expected);
}

INSTANTIATE_TEST_SUITE_P(
    SortTestCases,
    BubbleSortTests,
    ::testing::Values(
        std::make_pair(std::vector<int>(), std::vector<int>()),
        std::make_pair(std::vector<int>{1, 2, 3, 4, 5}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_pair(std::vector<int>{5, 4, 3, 2, 1}, std::vector<int>{1, 2, 3, 4, 5}),
        std::make_pair(std::vector<int>{9, 7, 2, 1, 5, 4, 9}, std::vector<int>{1, 2, 4, 5, 7, 9, 9}),
        std::make_pair(std::vector<int>{9, 7, 2, 1, 5, 5, 4, 9}, std::vector<int>{1, 2, 4, 5, 5, 7, 9, 9})));
