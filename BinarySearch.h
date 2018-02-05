//
// Created by sunzhijun on 18-2-5.
//

#ifndef SUANFA_BINARYSEARCH_H
#define SUANFA_BINARYSEARCH_H

#include <iostream>


template<typename T>
int __BinarySearchRecursion(T arr[], int left, int right, T target){

//    std::cout<<"Search from arr["<<left<<","<<right<<"]"<<std::endl;

    if(left > right){
        return -1;
    }

    int middle = left + (right - left) / 2;

    if(arr[middle] == target){
        return middle;
    }
    else if(arr[middle] > target){
        return __BinarySearchRecursion(arr, left, middle-1,target);
    }else{
        return __BinarySearchRecursion(arr, middle + 1, right, target);
    }
}

template<typename T>
int __BinarySearch(T arr[], int left, int right, T target){

    int middle = 0;
    while(left <= right){

//        std::cout<<"Search from arr["<<left<<","<<right<<"]"<<std::endl;

        middle = left + (right - left)/2;
        if(arr[middle] == target){
            return middle;
        }
        else if(arr[middle] > target){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
    return -1;
}

template<typename T>
//如果没有，返回-1
int BinarySearch(T arr[], int n, T target){

    return __BinarySearch(arr,0, n-1,target);
}

template<typename T>
int BinarySearchRecursion(T arr[], int n, T target){
    return __BinarySearchRecursion(arr,0,n-1,target);
}

#endif //SUANFA_BINARYSEARCH_H
