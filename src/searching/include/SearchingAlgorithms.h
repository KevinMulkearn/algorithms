/**
 * Collection of functions used to perform
 * different types of searching algorithms
 * on a vector of integers
 */

#if !defined(SEARCHING_ALGORITHMS_H)
#define SEARCHING_ALGORITHMS_H

#include <vector>

class Searching
{
public:
    Searching() = default;

    bool Sequential(std::vector<int>& /*vec*/, int /*value*/);

    bool Binary(std::vector<int>& /*vec*/, int /*value*/);

    bool Hash(std::vector<int>& /*vec*/, int /*value*/);

    // bool BloomFilter(std::vector<int>& /*vec*/, int /*value*/);

    // bool BinaryTree(std::vector<int>& /*vec*/, int /*value*/);
};

#endif // SEARCHING_ALGORITHMS_H