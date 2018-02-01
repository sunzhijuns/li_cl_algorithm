//
// Created by sunzhijun on 18-2-1.
//

#ifndef SUANFA_MERGESORT_H
#define SUANFA_MERGESORT_H

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

template<typename T>
void __MergeSort(T arr[], int left, int right){
    if(left >= right){
        return;
    }
    int mid = (right - left) / 2 + left;
    __MergeSort(arr, left, mid);
    __MergeSort(arr, mid+1, right);
    __Merge(arr, left, mid, right);

}

template<typename T>
void MergeSort(T arr[], int n){
    __MergeSort(arr, 0, n-1);
}

#endif //SUANFA_MERGESORT_H
