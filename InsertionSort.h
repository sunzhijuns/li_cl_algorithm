//
// Created by sunzhijun on 18-2-1.
//

#ifndef SUANFA_INSERTIONSORT_H
#define SUANFA_INSERTIONSORT_H

template <typename T>

void InsertionSort(T arr[], int n){
    for (int i = 1; i < n; ++i) {

        T temp = arr[i];

        int j = i-1;
        for (; j >= 0; --j) {
            if(arr[j] > temp){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}


#endif //SUANFA_INSERTIONSORT_H
