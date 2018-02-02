//
// Created by sunzhijun on 18-2-1.
//

#ifndef SUANFA_MERGESORT_H
#define SUANFA_MERGESORT_H

#include "InsertionSort.h"

template <typename T>
void __Merge(T arr[], int left, int mid, int right){

    T temp[right - left + 1];
    for (int i = left; i <= right; ++i) {
        temp[i-left] = arr[i];
    }
    int i = left, j = mid+1;
    for (int k = left; k <= right; ++k) {
        if(i > mid){
            arr[k] = temp[j-left];
            j++;
        }else if(j > right){
            arr[k] = temp[i-left];
            i++;
        }else if(temp[i-left] <= temp[j-left]){
            arr[k] = temp[i-left];
            i++;
        }else{
            arr[k] = temp[j-left];
            j++;
        }
    }

}


template <typename T>
void __MergeOptimizeMemory(T arr[],T auxiliary_array[], int left, int mid, int right){

    T* temp = auxiliary_array;
    for (int i = left; i <= right; ++i) {
        temp[i] = arr[i];
    }
    int i = left, j = mid+1;
    for (int k = left; k <= right; ++k) {
        if(i > mid){
            arr[k] = temp[j];
            j++;
        }else if(j > right){
            arr[k] = temp[i];
            i++;
        }else if(temp[i] <= temp[j]){
            arr[k] = temp[i];
            i++;
        }else{
            arr[k] = temp[j];
            j++;
        }
    }

}

template<typename T>
void __MergeSort(T arr[], int left, int right){
    if(right - left <= 15){
        InsertionSort(arr, left, right);
        return;
    }
    int mid = (right - left) / 2 + left;
    __MergeSort(arr, left, mid);
    __MergeSort(arr, mid+1, right);
    if(arr[mid] > arr[mid+1]){
        __Merge(arr, left, mid, right);
    }

}

template<typename T>
void __MergeSortOptimizeMemory(T arr[],T auxiliary_array[], int left, int right){
    if(right - left <= 15){
        InsertionSort(arr, left, right);
        return;
    }
    int mid = (right - left) / 2 + left;
    __MergeSortOptimizeMemory(arr,auxiliary_array, left, mid);
    __MergeSortOptimizeMemory(arr,auxiliary_array, mid+1, right);
    if(arr[mid] > arr[mid+1]){
        __MergeOptimizeMemory(arr,auxiliary_array, left, mid, right);
    }

}


template<typename T>
void MergeSort(T arr[], int n){
    __MergeSort(arr, 0, n-1);
}

template<typename T>
void MergeSortOptimizeMemory(T arr[], int n){
    T* auxiliary_array = new T[n];
    __MergeSortOptimizeMemory(arr,auxiliary_array,0,n-1);
    delete[] auxiliary_array;

}

template<typename T>
void MergeSortBottomToUp(T arr[], int n){
    for (int size = 1; size < n; size += size) {
        for (int i = 0; i + size < n; i += size + size) {
            __Merge(arr,i,i+size-1,min(i+size+size-1,n-1));
        }
    }
}

template<typename T>
void MergeSortBottomToUpOptimized(T arr[], int n){

    for (int i = 0; i < n; i += 16) {
        InsertionSort(arr,i, min(i+15, n-1));
    }

    T* auxiliary_array = new T[n];
    for (int size = 16; size <= n; size += 16) {
        for (int i = 0; i < n-size; i += size + size) {
            if(arr[i+size - 1] > arr[i+size]){
                __MergeOptimizeMemory(arr,auxiliary_array,i, i+size-1, min(i+size+size-1,n-1));
            }
        }
    }
    delete[] auxiliary_array;

}

#endif //SUANFA_MERGESORT_H
