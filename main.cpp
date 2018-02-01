#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"

using namespace std;

template <typename T>

void InsertionSort(T arr[], int n){
    for (int i = 1; i < n; ++i) {

        for (int j = i-1; j >= 0; --j) {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }else{
                break;
            }
        }

    }
}

int main() {
    int n = 10000;
    int * arr = SortTestHelper::GenerateRandomArray(n,0,n);
    int * arr1 = SortTestHelper::CopyIntArray(arr,n);

    SortTestHelper::TestSort("SelectionSort", SelectionSort, arr, n);
    SortTestHelper::PrintArray(arr,10);

    SortTestHelper::TestSort("InsertionSort", InsertionSort, arr1, n);
    SortTestHelper::PrintArray(arr1,10);




    delete[] arr;
    delete[] arr1;

    return 0;
}