#include <algorithm>
#include <iostream>
#include <vector>

#include "SortingAlgorithms.h"

/**
 * Insertion Sort
 * Best O(n), Average, Worst O(n^2)
 * Moving through container, sorts one element at at time
 * moving each item into the correct position
 */
void Sorting::insertion(std::vector<int>& vec)
{
    for (size_t i = 1; i < vec.size(); ++i)
    {
        int current_value = vec[i];
        int j = i;
        while (j > 0 && vec[j-1] > current_value) 
        {
            vec[j] = vec[j-1]; // shift previous number up 
            j--;
        }
        vec[j] = current_value; // move back to correct postion (swap)
    }
}

/**
 * Selection Sort
 * Best, Average, Worst O(n^2)
 * Select largest value in the range and move it to the rightmost 
 * postion. Repeat on each suscessive smaller range 
 */
void Sorting::selection(std::vector<int>& vec)
{
    auto range_size{vec.size()};
    while (range_size > 1)
    {
        // Find largest number in range
        int largest_num{vec[0]}, largest_pos{0};
        for (size_t i = 1; i < range_size; ++i)
        {
            if (vec[i] > largest_num)
            {
                largest_pos = i;
                largest_num = vec[i];
            }
        }
        // Swap largest with end element
        vec[largest_pos] = vec[range_size - 1];
        vec[range_size - 1] = largest_num;
        range_size--;
    }
}

/**
 * Heap Sort helper function
 * Rearrange vector into a binary heap data structure
 * Starting at the bottom leaf node compare with its parent
 * and swap if child is larger than parent, repeat for all nodes
 */
void heapify(std::vector<int>& vec, int tree_size, int base_pos)
{
    int largest_pos = base_pos;
    int left_child_pos = 2*base_pos + 1;
    int right_child_pos = 2*base_pos + 2;

    if (left_child_pos < tree_size && vec[left_child_pos] > vec[largest_pos])
    {
        largest_pos = left_child_pos;
    }

    if (right_child_pos < tree_size && vec[right_child_pos] > vec[largest_pos])
    {
        largest_pos = right_child_pos;
    }
 
    // If largest is not root swap
    if (largest_pos != base_pos)
    {
        std::swap(vec[base_pos], vec[largest_pos]);

        // heapify the affected sub-tree
        heapify(vec, tree_size, largest_pos);
    }
}

/**
 * Heap Sort
 * Best, Average, Worst O(n log n)
 * Moving through container, sorts one element at at time
 * moving each item into the correct position
 */
void Sorting::heap(std::vector<int>& vec)
{
    // Build heap structure
    for (int base_pos = vec.size()/2 - 1; base_pos >= 0; --base_pos)
    {
        heapify(vec, vec.size(), base_pos);
    }

    // Sort heap
    for (int tree_size = vec.size()-1; tree_size > 0; --tree_size) 
    {      
        // Move largest to end of sub-vector
        std::swap(vec[0], vec[tree_size]);

        // Build new heap from sub-vector i.e. excluding largest number(s) at end
        heapify(vec, tree_size, 0);
    }
}

/**
 * Quick Sort helper function
 * move smallet numbers below partion index and larger numbers
 * above the index, and return partion index
 */
int partition(int& pivot, std::vector<int>& vec, int& left, int& right)
{
    int left_0_index = left -1;
    for (int i = left; i <= right; ++i)
    {
        if (vec[i] <= pivot)
        {
            // swap smaller numbers to front of sub-vector
            std::swap(vec[i], vec[++left_0_index]);
        }
    }
    return left_0_index;
}

/**
 * Quick Sort
 * Best, Average O(n log n), Worst O(n^2)
 * Divide and conquer: A pivot element is selected (this can be 
 * random but it may affect the perfomance), all smaller number 
 * are moved to the left of it, all larger are moved to the right of it.
 * The process repeats on each new sub vector until full sorted.
 */
void Sorting::quick(std::vector<int>& vec, int left, int right)
{
    // Choose pivot
    auto pivot = vec[right];

    // Partition vector range
    auto part = partition(pivot, vec, left, right);

    // Repeat until sorted
    if (left < right)
    {
        quick(vec, left, part-1);
        quick(vec, part+1, right);
    }
}

// fucntion overload with initial vector low and high values
void Sorting::quick(std::vector<int>& vec)
{
    if (vec.size() > 0)
    {
        quick(vec, 0, vec.size()-1);
    }
}

/**
 * Bucket Sort helper function
 * Returns an appropriate "hash" value which will be the 
 * bucket (index between 0 and n) that the number will
 * be pushed into. This function will be specific to the 
 * type of data being sorted.
 */
int bucket_hash(int num, int num_of_buckets)
{
    // Note: this example is for demonstaration purposes only
    int hash{num/num_of_buckets};
    if (hash >= num_of_buckets)
    {
        hash = num_of_buckets-1;
    }
    return hash;
}

/**
 * Bucket Sort
 * Best, Average, Worst O(n)
 * Construct a set of ordered buckets, partition elements
 * into buckets, sort using a simple sorting algorithm, 
 * and concatenate buckets.
 * 
 * Note: Requires O(nk) worst case extra space
 * Bucket sort should be used when:
 *  - Uniform distribution
 *  - Ordered Hash function
 */
void Sorting::bucket(std::vector<int>& vec)
{
    // Create n empty buckets
    const auto num_of_buckets{vec.size()};
    std::vector<std::vector<int>> buckets(num_of_buckets);
  
    // Put elements in different buckets based on "hash" value
    for (auto const& num : vec)
    {
        auto hash = bucket_hash(num, num_of_buckets);
        buckets[hash].push_back(num); 
    }

    // Sort individual buckets
    for (auto& bucket : buckets)
    {
        std::sort(bucket.begin(), bucket.end());  
    }

    // Append buckets back together
    vec.clear();
    for (auto const& bucket : buckets)
    {
        if (!buckets.empty())
        {
            vec.insert(vec.end(), bucket.begin(), bucket.end());
        }
    }
}

/**
 * Merge Sort helper function
 * "Merges" the two sub-arrays back together
 */
void rejoin(std::vector<int>& vec, int left, int middle, int right)
{
    // Find size of two sub arrays
    auto sub_left_size =  middle - left + 1;
    auto sub_right_size = right - middle;

    // Create temp arrays to store the data in
    std::vector<int> sub_left(sub_left_size);
    std::vector<int> sub_right(sub_right_size);

    // Copy data into new arrays
    for (auto i = 0; i < sub_left_size; ++i)
    {
        sub_left[i] = vec[left + i];
    }

    for (auto i = 0; i < sub_right_size; ++i)
    {
        sub_right[i] = vec[middle + 1 + i];
    }

    // Merge two sub arrays together in sorted order
    int left_index = 0, right_index = 0, vec_index = left;

    while (left_index < sub_left_size && right_index < sub_right_size) 
    {
        if (sub_left[left_index] <= sub_right[right_index]) 
        {
            vec[vec_index++] = sub_left[left_index++];
        }
        else 
        {
            vec[vec_index++] = sub_right[right_index++];
        }
    }

    // Copy remaining (if any) elements
    while (left_index < sub_left_size)
    {
        vec[vec_index++] = sub_left[left_index++];
    }

    while (right_index < sub_right_size)
    {
        vec[vec_index++] = sub_right[right_index++];
    }
}

/**
 * Merge Sort
 * Best, Average, Worst O(n log n)
 * Divide and conquer: Create a copy of the vector, divide the 
 * vector into two equal halves, repeat, then merge back in in sorted order
 * 
 * Note: Required O(n log n) extra space, in worst case
 */
void Sorting::merge(std::vector<int>& vec, int left, int right)
{
    if (left < right)
    {
        // Find middle point
        auto middle = (left + right)/2;

        // sort the left and right
        merge(vec, left, middle);
        merge(vec, middle + 1, right);

        // Merge two halves back together
        rejoin(vec, left, middle, right);
    }
}

// fucntion overload with initial vector low and high values
void Sorting::merge(std::vector<int>& vec)
{
    merge(vec, 0, vec.size()-1);
}