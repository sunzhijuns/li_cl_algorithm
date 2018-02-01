#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"


int main() {
    int n = 10000;
//    int * arr = SortTestHelper::GenerateRandomArray(n,0,10);
    int * arr = SortTestHelper::GenerateNearlyOrderedArray(n,0);
    int * arr1 = SortTestHelper::CopyIntArray(arr,n);

    SortTestHelper::PrintArray(arr,10);
    SortTestHelper::PrintArray(arr1,10);

    SortTestHelper::TestSort("SelectionSort", SelectionSort, arr, n);
    SortTestHelper::PrintArray(arr,10);

    SortTestHelper::TestSort("InsertionSort", InsertionSort, arr1, n);
    SortTestHelper::PrintArray(arr1,10);

    delete[] arr;
    delete[] arr1;

    return 0;
}