#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

#include "MergeSort.h"



int main11(){
    int n = 100;
    int * a = SortTestHelper::GenerateRandomArray(n,0,10);
    QuickSort3Ways(a,n);
    SortTestHelper::PrintArray(a,100);
    delete[] a;
    return 0;
}

int main() {
    int n = 100*10000;
    int print_n = 100;
//    int * arr = SortTestHelper::GenerateRandomArray(n,0,n);
    int * arr = SortTestHelper::GenerateNearlyOrderedArray(n,1000);
    int * arr1 = SortTestHelper::CopyIntArray(arr,n);
    int * arr2 = SortTestHelper::CopyIntArray(arr,n);
    int * arr3 = SortTestHelper::CopyIntArray(arr,n);


//    SortTestHelper::PrintArray(arr,print_n);
    SortTestHelper::PrintArray(arr1,print_n);
    SortTestHelper::PrintArray(arr2,print_n);

    SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);
    SortTestHelper::PrintArray(arr,print_n);

    SortTestHelper::TestSort("QuickSort", QuickSort, arr1, n);
    SortTestHelper::PrintArray(arr1,print_n);


    SortTestHelper::TestSort("QuickSort3Ways", QuickSort3Ways, arr2, n);
    SortTestHelper::PrintArray(arr2,print_n);

    SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr3, n);
    SortTestHelper::PrintArray(arr3,print_n);

    delete[] arr;
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;

    return 0;
}