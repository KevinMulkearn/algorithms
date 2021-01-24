#include "SearchingAlgorithms.h"

/**
 * Sequential Search
 * Best O(1), Average, Worst O(n)
 * Brute-force approach to locate target value by
 * checking the first value in the container and
 * continuing until found. Elements do not
 * have to be ordered
 */
bool Searching::Sequential(std::vector<int>& vec, int value)
{
    auto it = vec.cbegin();
    while (it != vec.cend())
    {
        if (*it == value)
        {
            return true;
        }
        ++it;
    }
    return false;
}

/**
 * Binary Search
 * Best O(1), Average, Worst O(log n)
 * Container must be sorted. Repeatedly divides the
 * search area in half until the value is found
 */
bool Searching::Binary(std::vector<int>& vec, int value)
{
    if (vec.empty())
    {
        return false;
    }

    auto low =  0;
    auto high = vec.size() - 1;

    while (low <= high)
    {
        auto mid = (low + high)/2;
        auto pivot = vec[mid];

        if (pivot < value)
        {
            low = mid + 1;
        }
        else if (pivot > value)
        {
            high = mid - 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}
