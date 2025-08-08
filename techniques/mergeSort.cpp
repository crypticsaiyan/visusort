#include "techniques.hpp"

std::vector<std::vector<int32_t>> storage;

void mergeSortHelper(std::vector<std::vector<int32_t>> &storage)
{
    while (storage.size() > 1)
    {
        std::vector<std::vector<int32_t>> newStorage;

        // Merge adjacent pairs
        for (size_t i = 0; i < storage.size(); i += 2)
        {
            if (i + 1 < storage.size())
            {
                // Merge storage[i] and storage[i+1]
                std::vector<int32_t> merged;
                std::vector<int32_t> &left = storage[i];
                std::vector<int32_t> &right = storage[i + 1];

                size_t l = 0, r = 0;
                while (l < left.size() && r < right.size())
                {
                    comparisons++; // Count the comparison
                    if (left[l] <= right[r])
                    {
                        merged.push_back(left[l++]);
                    }
                    else
                    {
                        merged.push_back(right[r++]);
                    }
                }

                while (l < left.size())
                    merged.push_back(left[l++]);
                while (r < right.size())
                    merged.push_back(right[r++]);

                newStorage.push_back(merged);
            }
            else
            {
                // Odd number of elements, carry forward the last one
                newStorage.push_back(storage[i]);
            }
        }

        storage = newStorage;
        printStorage(storage);
    }
}

void mergeSort(std::vector<int32_t> &v)
{
    storage.clear();
    std::vector<int32_t> temp(1);
    for (size_t i = 0; i < v.size(); i++)
    {
        temp[0] = v[i];
        storage.push_back(temp);
    }
    printStorage(storage);
    mergeSortHelper(storage);
    std::cout << std::endl;
    resetGlobals();
}