#include <vector>

#include "SearchingAlgorithms.h"

#include <gtest/gtest.h>

TEST(SequentialSearch, sequentialSearchFound)
{
    Searching search;
    std::vector<int> haystack{1,2,3,4,5,6,7,8,9,0,10,11,12,13};
    int needle{6};

    auto found = search.Sequential(haystack, needle);

    EXPECT_EQ(found, true);
}

TEST(SequentialSearch, sequentialSearchNotFound)
{
    Searching search;
    std::vector<int> haystack{1,2,3,4,5,6,7,8,9,0,10,11,12,13};
    int needle{40};

    auto found = search.Sequential(haystack, needle);

    EXPECT_EQ(found, false);
}

TEST(SequentialSearch, noContainerElements)
{
    Searching search;
    std::vector<int> haystack{};
    int needle{40};

    auto found = search.Sequential(haystack, needle);

    EXPECT_EQ(found, false);
}
