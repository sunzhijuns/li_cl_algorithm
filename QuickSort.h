//
// Created by sunzhijun on 18-2-2.
//

#ifndef SUANFA_QUICKSORT_H
#define SUANFA_QUICKSORT_H

#include<iostream>
#include "InsertionSort.h"

template<typename T>
int __Partition_2(T arr[], int left, int right){

    std::swap(arr[rand()%(right - left + 1) + left],arr[left]);

    T partition = arr[left];

    int less_equal_index = left+1;
    int great_equal_index = right;

    while(less_equal_index <= great_equal_index){
        while(less_equal_index <= great_equal_index && arr[less_equal_index] < partition ){
            less_equal_index++;
        }
        while(less_equal_index <= great_equal_index && arr[great_equal_index] > partition ){
            great_equal_index--;
        }
        if(less_equal_index <= great_equal_index){
            std::swap(arr[less_equal_index],arr[great_equal_index]);
            less_equal_index++;
            great_equal_index--;
        }else{
            break;
        }
    }
    std::swap(arr[left],arr[less_equal_index-1]);
    return less_equal_index-1;

}

template<typename T>
int __Partition(T arr[], int left, int right){

    std::swap(arr[rand()%(right - left + 1) + left],arr[left]);

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

    int p = __Partition_2(arr,left,right);

    __QuickSort(arr,left,p-1);
    __QuickSort(arr,p+1,right);

}

template<typename T>
void QuickSort(T arr[], int n){

    srand(time(NULL));
    __QuickSort(arr, 0, n-1);

}

template<typename T>
void __Partition_3(T arr[], int partition_indies[2], int left, int right){

    std::swap(arr[rand()%(right - left + 1) + left], arr[left]);

    T partition = arr[left];

    int less_index = left + 1;  // 待检查的
    int great_index = right;    // 待检查的
    int i = left + 1;
    while (i <= great_index) {
        if(arr[i] > partition){
            std::swap(arr[i], arr[great_index]);
            great_index--;
        }else if(arr[i] < partition){
            std::swap(arr[less_index], arr[i]);
            less_index ++;
            i++;
        }else{
            i++;
        }
    }
    std::swap(arr[left], arr[less_index-1]);

    partition_indies[0] = less_index-2;
    partition_indies[1] = great_index + 1;

}

template<typename T>
void __QuickSort3Ways(T arr[], int left, int right){

    if(right - left <= 15){
        InsertionSort(arr, left, right);
        return;
    }

    int p[2] = {0};

    __Partition_3(arr,p,left,right);

    __QuickSort3Ways(arr,left,p[0]);
    __QuickSort3Ways(arr,p[1],right);

}

template<typename T>
void QuickSort3Ways(T arr[], int n){
    srand(time(NULL));
    __QuickSort3Ways(arr,0,n-1);
}

#endif //SUANFA_QUICKSORT_H
