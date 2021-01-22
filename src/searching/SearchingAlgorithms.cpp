#include "SearchingAlgorithms.h"

/**
 * Sequential Search
 * Best O(1), Average, Worst O(n)
 * Brute-force approach to locate target value by
 * checking the first value in the container and
 * continuing until found.
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

