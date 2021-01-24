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

/**
 * Hash Search helper function
 * Generate an appropriate hash value.
 */
int hash_code(int num, int num_of_buckets)
{
    // Note: this example is for demonstaration purposes only
    auto hash{num/num_of_buckets};
    if (hash >= num_of_buckets)
    {
        hash = num_of_buckets-1;
    }
    return hash;
}

/**
 * Hash Search helper function
 * Populates hash table with hash values of each element.
 * A 2-dimensional vector is used here to demonstrate this
 * a linked-list would be a better choice.
 */
std::vector<std::vector<int>> LoadHashTable(std::vector<int>& vec)
{
    // Create n empty buckets
    const auto num_of_bin{vec.size()};
    std::vector<std::vector<int>> bins(num_of_bin);

    // Put elements in different buckets based on "hash" value
    for (auto const& num : vec)
    {
        auto hash = hash_code(num, num_of_bin);
        bins[hash].push_back(num);
    }
    return bins;
}

/**
 * Hash Search
 * Best O(1), Average, Worst O(n)
 * Used when very large, unordered, collections. Before a
 * search can happen the elements of the collection are
 * loaded into hash table with bins structured into
 * an array. Once pre-loaded the search now takes place
 * on the matching hash bin instead of whole container.
 */
bool Searching::Hash(std::vector<int>& vec, int value)
{
    if (vec.empty())
    {
        return false;
    }

    // Genereate hash table (the action would happen before
    // hash search is called, it is here for demonstration purpose)
    auto hash_table{LoadHashTable(vec)};

    // Get has of search element
    const auto num_of_bin{vec.size()};
    auto hash{hash_code(value, num_of_bin)};

    // Search hash bin reletive to search hash value
    if (hash_table[hash].empty())
    {
        return false;
    }
    return Sequential(hash_table[hash], value);
}