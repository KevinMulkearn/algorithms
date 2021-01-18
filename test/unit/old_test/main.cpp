#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

#include "SortingAlgorithms.h"
#include "Timing.h"

std::vector<int> random_nums(int low, int high, int size)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(low, high);
 
    std::vector<int> vec(size);
    std::generate(vec.begin(), vec.end(), [&distrib, &gen] () { return distrib(gen);});
    
    return vec;
}

int main()
{
    int low{0}, high{0}, size{0}, choice{0};

    std::cout << "How many numbers would you like to sort? " << std::endl;
    std::cin >> size;

    std::cout << "What is number range lower bound? " << std::endl;
    std::cin >> low;

    std::cout << "What is number range upper bound? " << std::endl;
    std::cin >> high;
    
    auto test_data = random_nums(low, high, size);

    std::cout << "Created array of " << size << " randoms integers" << std::endl;


    std::cout << "which sorting algorithm would you like to try? " << std::endl;

    std::cout << "1. Insertion sort" << std::endl;
    std::cout << "2. Selection sort" << std::endl;
    std::cout << "3. Heap sort" << std::endl;
    std::cout << "4. Quick sort" << std::endl;
    std::cout << "5. Bucket sort" << std::endl;
    std::cout << "6. Merge sort" << std::endl;
    
    std::cin >> choice;
    std::cout << "Sorting ..." << std::endl;

    Sorting sort;
    // namespace used start and stop timer i.e. ctor and dtor
    {
        Timer timer;
        switch (choice)
        {
            case 1:
                sort.insertion(test_data);
                break;
            case 2:
                sort.selection(test_data);
                break;
            case 3:
                sort.heap(test_data);
                break;
            case 4:
                sort.quick(test_data);
                break;
            case 5:
                sort.bucket(test_data);
                break;
            case 6:
                sort.merge(test_data);
                break;
            default:
                break;
        }
    }
    std::cout << "Sorted!" << std::endl;

    system("pause"); // stop terminal from closing early
}