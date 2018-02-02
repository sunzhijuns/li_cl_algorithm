#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

#include "MergeSort.h"

int main11(){
    int a[10] = {2,43,4,2,3};
    InsertionSort(a,0,9);
    SortTestHelper::PrintArray(a,10);
    return 0;
}


int main() {
    int n = 100*10000;
    int print_n = 100;
    int * arr = SortTestHelper::GenerateRandomArray(n,0,n);
//    int * arr = SortTestHelper::GenerateNearlyOrderedArray(n,10);
    int * arr1 = SortTestHelper::CopyIntArray(arr,n);
    int * arr2 = SortTestHelper::CopyIntArray(arr,n);

//    SortTestHelper::PrintArray(arr,print_n);
    SortTestHelper::PrintArray(arr1,print_n);
    SortTestHelper::PrintArray(arr2,print_n);

    SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);
    SortTestHelper::PrintArray(arr,print_n);

    SortTestHelper::TestSort("MergeSortBottomToUp", MergeSortBottomToUp, arr1, n);
    SortTestHelper::PrintArray(arr1,print_n);

    SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr2, n);
    SortTestHelper::PrintArray(arr2,print_n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;

    return 0;
}