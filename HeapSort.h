//
// Created by sunzhijun on 18-2-3.
//

#ifndef SUANFA_HEAPSORT_H
#define SUANFA_HEAPSORT_H

#include "MaxHeap.h"

template<typename T>
void HeapSort2(T arr[], int n){
    MaxHeap<T> max_heap = MaxHeap<T>(n);
    for (int i = 0; i < n; ++i) {
        max_heap.Insert(arr[i]);
    }
    for (int i = n-1; i >= 0; --i) {
        arr[i] = max_heap.ExtractMax();
    }
}

template<typename T>
void HeapSort1(T arr[], int n) {
    MaxHeap<T> max_heap = MaxHeap<T>(arr, n);

    for (int i = n - 1; i >= 0; --i) {
        arr[i] = max_heap.ExtractMax();
    }
}

template<typename T>
void __ShiftDown(T arr[], int count, int index){

    //count = 4, last_index = 3;
    while(2*index + 1 < count){

        int child_index = 2*index + 1;
        if((child_index + 1) < count &&
           arr[child_index] < arr[child_index + 1]){
            child_index = child_index + 1;
        }

        if(arr[index] >= arr[child_index]){
            break;
        }

        std::swap(arr[index], arr[child_index]);
        index = child_index;

    }
}

template<typename T>
void HeapSort(T arr[], int n){
    //Heapify
    for (int i = (n-1)/2; i >=0 ; --i) {
        __ShiftDown(arr, n, i);
    }

    for (int last_index = n-1; last_index > 0 ; --last_index) {
        std::swap(arr[0], arr[last_index]);
        __ShiftDown(arr, last_index, 0);
    }
}

#endif //SUANFA_HEAPSORT_H
