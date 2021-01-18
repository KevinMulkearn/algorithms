/**
 * Collection of functions used to perform
 * different types of sorting algorithms
 * on a vector of integers
 */

#if !defined(SORTING_ALGORITHMS_H)
#define SORTING_ALGORITHMS_H

#include <iostream>
#include <vector>

class Sorting
{
public:
    Sorting() = default;

    void print(std::vector<int> const& vec)
    {
        for (auto const& num : vec)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    void insertion(std::vector<int>& /*vec*/);

    void selection(std::vector<int>& /*vec*/);

    void heap(std::vector<int>& /*vec*/);

    void quick(std::vector<int>& /*vec*/);

    void bucket(std::vector<int>& /*vec*/);

    void merge(std::vector<int>& /*vec*/);

private:
    void quick(std::vector<int>& /*vec*/, int /*left*/, int /*right*/);
    void merge(std::vector<int>& /*vec*/, int /*left*/, int /*right*/);
};

#endif // SORTING_ALGORITHMS_H