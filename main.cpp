#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

#include "MergeSort.h"
#include "MaxHeap.h"
#include "HeapSort.h"
#include "IndexMaxHeap.h"
#include "BinarySearch.h"


int main(){
    int n = 500*10000;
    int * a = new int[n];
    for (int i = 0; i < n; ++i) {
        a[i] = i;
    }

    {

        clock_t start_time = clock();

        for (int i = 0; i < 2 * n; ++i) {
            int v = BinarySearch(a, n, i);
            if(i < n){
                assert(v==i);
            }
            else{
                assert(v == -1);
            }
        }
        clock_t end_time = clock();
        std::cout<<"Binary Search(Without Recursion): "
                 <<double(end_time - start_time)/CLOCKS_PER_SEC
                 <<" s" << std::endl;

    }
    {

        clock_t start_time = clock();

        for (int i = 0; i < 2 * n; ++i) {
            int v = BinarySearchRecursion(a, n, i);
            if(i < n){
                assert(v==i);
            }
            else{
                assert(v == -1);
            }
        }
        clock_t end_time = clock();
        std::cout<<"Binary Search(With Recursion): "
                 <<double(end_time - start_time)/CLOCKS_PER_SEC
                 <<" s" << std::endl;

    }
    return 0;
}

