//
// Created by sunzhijun on 18-2-3.
//

#ifndef SUANFA_HEAPSORT_H
#define SUANFA_HEAPSORT_H

#include "MaxHeap.h"

template<typename T>
void HeapSort(T arr[], int n){
    MaxHeap<T> max_heap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        max_heap.Insert(arr[i]);
    }
    for (int i = n-1; i >= 0; --i) {
        arr[i] = max_heap.ExtractMax();
    }
}


#endif //SUANFA_HEAPSORT_H
