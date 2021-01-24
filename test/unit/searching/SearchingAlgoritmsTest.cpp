#include <algorithm>
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


TEST(BinarySearch, binarySearchFound)
{
    Searching search;
    std::vector<int> haystack{1,2,3,4,5,6,7,8,9,0,10,11,12,13};
    int needle{11};

    std::sort(haystack.begin(), haystack.end());
    auto found = search.Binary(haystack, needle);

    EXPECT_EQ(found, true);
}

TEST(BinarySearch, binarySearchNotFound)
{
    Searching search;
    std::vector<int> haystack{1,2,3,4,5,6,7,8,9,0,10,11,12,13};
    int needle{40};

    std::sort(haystack.begin(), haystack.end());
    auto found = search.Binary(haystack, needle);

    EXPECT_EQ(found, false);
}

TEST(BinarySearch, noContainerElements)
{
    Searching search;
    std::vector<int> haystack{};
    int needle{40};

    auto found = search.Binary(haystack, needle);

    EXPECT_EQ(found, false);
}


TEST(HashSearch, hashSearchSearchFound)
{
    Searching search;
    std::vector<int> haystack{13,52,73,34,65,46,7,38,99,0,10,15,15,13};
    int needle{7};

    auto found = search.Hash(haystack, needle);

    EXPECT_EQ(found, true);
}

TEST(HashSearch, hashSearchNotFound)
{
    Searching search;
    std::vector<int> haystack{13,52,73,34,65,46,7,38,99,0,10,15,15,13};
    int needle{40};

    auto found = search.Hash(haystack, needle);

    EXPECT_EQ(found, false);
}

TEST(HashSearch, noContainerElements)
{
    Searching search;
    std::vector<int> haystack{};
    int needle{40};

    auto found = search.Hash(haystack, needle);

    EXPECT_EQ(found, false);
}