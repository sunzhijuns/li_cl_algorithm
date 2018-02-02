//
// Created by sunzhijun on 18-2-2.
//

#ifndef SUANFA_QUICKSORT_H
#define SUANFA_QUICKSORT_H

#include<iostream>
#include "InsertionSort.h"

template<typename T>
int __Partition(T arr[], int left, int right){

    T partition = arr[left];
    int less_equal_index = left;
    for (int i = left+1; i <= right; ++i) {
        if(arr[i] > partition){
            continue;
        }else{
            std::swap(arr[i],arr[less_equal_index+1]);
            less_equal_index++;
        }
    }

    std::swap(arr[left],arr[less_equal_index]);

    return less_equal_index;

}

template<typename T>
void __QuickSort(T arr[], int left, int right){

    if(right - left <= 15){
        InsertionSort(arr, left, right);
        return;
    }

    int p = __Partition(arr,left,right);

    __QuickSort(arr,left,p-1);
    __QuickSort(arr,p+1,right);

}

template<typename T>
void QuickSort(T arr[], int n){

    __QuickSort(arr, 0, n-1);

}

#endif //SUANFA_QUICKSORT_H
