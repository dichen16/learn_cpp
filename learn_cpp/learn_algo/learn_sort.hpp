#pragma once
#include <iostream>
#include <vector>

void insertionSort(int * arr, int capacity);
void insertionSort(int * arr, int capacity)
{
    if (capacity <= 1) 
        return;

    for (int i = 1; i < capacity; ++i) 
    
    {
        int value = arr[i];
        int j = i - 1;
        //find the position to insert
        for (; j >= 0; --j)
        {
            if (arr[j] > value)
            {
                arr[j + 1] = arr[j];  // data movement
            }
            else 
            {
                break;
            }
        }
        arr[j + 1] = value; // insert the data
    }
}
void insertionSort(std::vector<int> &vec);
void insertionSort(std::vector<int> &vec)
{
    if (vec.size() <= 1)
    {
        return;
    }
    for (size_t i = 1; i < vec.size(); ++i)
    {
        int value = vec[i];
        auto j = i - 1;
        //the loop is to find the position to insert data
        for (; j >= 0; --j)
        {
            if (vec[j] > value)
            {
                //the j data will be move forward
                vec[j + 1] = vec[j];
            }
            else
            {
                break;
            }
        }
        vec[j + 1] = value;
    }

}