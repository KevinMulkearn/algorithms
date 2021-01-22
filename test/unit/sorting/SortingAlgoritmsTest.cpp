#include <vector>

#include "SortingAlgorithms.h"

#include <gtest/gtest.h>

TEST(InsertionSort, insertionSort)
{
    Sorting sort;
    std::vector<int> data{5,4,99,2,1,3,10,6,7,15,44,8,66,20,9};
    std::vector<int> sorted{1,2,3,4,5,6,7,8,9,10,15,20,44,66,99};
    sort.insertion(data);
    EXPECT_EQ(sorted, data);
}

TEST(InsertionSort, insertionSortEmpty)
{
    Sorting sort;
    std::vector<int> data{};
    std::vector<int> sorted{};
    sort.insertion(data);
    EXPECT_EQ(sorted, data);
}

TEST(InsertionSort, insertionSortOneElement)
{
    Sorting sort;
    std::vector<int> data{5};
    std::vector<int> sorted{5};
    sort.insertion(data);
    EXPECT_EQ(sorted, data);
}


TEST(SelectionSort, selectionSort)
{
    Sorting sort;
    std::vector<int> data{5,4,99,2,1,3,10,6,7,15,44,8,66,20,9};
    std::vector<int> sorted{1,2,3,4,5,6,7,8,9,10,15,20,44,66,99};
    sort.selection(data);
    EXPECT_EQ(sorted, data);
}

TEST(SelectionSort, selectionSortEmpty)
{
    Sorting sort;
    std::vector<int> data{};
    std::vector<int> sorted{};
    sort.selection(data);
    EXPECT_EQ(sorted, data);
}

TEST(SelectionSort, selectionSortOneElement)
{
    Sorting sort;
    std::vector<int> data{5};
    std::vector<int> sorted{5};
    sort.selection(data);
    EXPECT_EQ(sorted, data);
}


TEST(HeapSort, heapSort)
{
    Sorting sort;
    std::vector<int> data{5,4,99,2,1,3,10,6,7,15,44,8,66,20,9};
    std::vector<int> sorted{1,2,3,4,5,6,7,8,9,10,15,20,44,66,99};
    sort.heap(data);
    EXPECT_EQ(sorted, data);
}

TEST(HeapSort, heapSortEmpty)
{
    Sorting sort;
    std::vector<int> data{};
    std::vector<int> sorted{};
    sort.heap(data);
    EXPECT_EQ(sorted, data);
}

TEST(HeapSort, heapSortOneElement)
{
    Sorting sort;
    std::vector<int> data{5};
    std::vector<int> sorted{5};
    sort.heap(data);
    EXPECT_EQ(sorted, data);
}


TEST(QuickSort, quickSort)
{
    Sorting sort;
    std::vector<int> data{5,4,99,2,1,3,10,6,7,15,44,8,66,20,9};
    std::vector<int> sorted{1,2,3,4,5,6,7,8,9,10,15,20,44,66,99};
    sort.quick(data);
    EXPECT_EQ(sorted, data);
}

TEST(QuickSort, quickSortEmpty)
{
    Sorting sort;
    std::vector<int> data{};
    std::vector<int> sorted{};
    sort.quick(data);
    EXPECT_EQ(sorted, data);
}

TEST(QuickSort, quickSortOneElement)
{
    Sorting sort;
    std::vector<int> data{5};
    std::vector<int> sorted{5};
    sort.quick(data);
    EXPECT_EQ(sorted, data);
}


TEST(BucketSort, bucketSort)
{
    Sorting sort;
    std::vector<int> data{5,4,99,2,1,3,10,6,7,15,44,8,66,20,9};
    std::vector<int> sorted{1,2,3,4,5,6,7,8,9,10,15,20,44,66,99};
    sort.bucket(data);
    EXPECT_EQ(sorted, data);
}

TEST(BucketSort, bucketSortEmpty)
{
    Sorting sort;
    std::vector<int> data{};
    std::vector<int> sorted{};
    sort.bucket(data);
    EXPECT_EQ(sorted, data);
}

TEST(BucketSort, bucketSortOneElement)
{
    Sorting sort;
    std::vector<int> data{5};
    std::vector<int> sorted{5};
    sort.bucket(data);
    EXPECT_EQ(sorted, data);
}


TEST(MergeSort, mergeSort)
{
    Sorting sort;
    std::vector<int> data{5,4,99,2,1,3,10,6,7,15,44,8,66,20,9};
    std::vector<int> sorted{1,2,3,4,5,6,7,8,9,10,15,20,44,66,99};
    sort.merge(data);
    EXPECT_EQ(sorted, data);
}

TEST(MergeSort, mergeSortEmpty)
{
    Sorting sort;
    std::vector<int> data{};
    std::vector<int> sorted{};
    sort.merge(data);
    EXPECT_EQ(sorted, data);
}

TEST(MergeSort, mergeSortOneElement)
{
    Sorting sort;
    std::vector<int> data{5};
    std::vector<int> sorted{5};
    sort.merge(data);
    EXPECT_EQ(sorted, data);
}