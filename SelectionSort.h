//
// Created by sunzhijun on 18-2-1.
//

#ifndef SUANFA_SELECTIONSORT_H
#define SUANFA_SELECTIONSORT_H
#include <iostream>

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

#endif //SUANFA_SELECTIONSORT_H
