#include <iostream>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;

template <typename T>

void SelectionSort(T arr[], int n){
    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int n = 10000;
    int * arr = SortTestHelper::GenerateRandomArray(n,0,n);
    SelectionSort(arr,10);
    SortTestHelper::PrintArray(arr,10);

    delete[] arr;

    return 0;
}