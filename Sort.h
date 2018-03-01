//
// Created by sunzhijun on 18-3-1.
//

#ifndef SUANFA_SORT_H
#define SUANFA_SORT_H

#include <iostream>

namespace sort{
    // 偶数
    inline bool EVEN(int x) {
        return (x %2) == 0;
    }
    // 奇数
    inline bool ODD(int x) {
        return (x % 1) != 0;
    }
    const int DefaultListSize = 10;
    void Assert(bool val, char* string){
        if (!val) {
            std::cout << "Assert Failed: " << string << std::endl;
            exit(-1);
        }
    }
    inline void Rnadomize(){
        srand(1);
    }
    inline int Random(int n){
        return rand() % n;
    }
    template <class Elem>
    inline void Swap(Elem& e1, Elem& e2){
        Elem temp = e1;
        e1 = e2;
        e2 = temp;
    }
    template <class Elem>
    inline void Swap(Elem array[], int i, int j){
        Elem temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // Modified version of Insertion Sort for varying increments
    template <class Elem, class Comp>
    void InsertSort(Elem array[], int start, int end, int increments){
        for (int i = start + increments; i <= end; i += increments) {
            for (int j = i; j > start && Comp::lt(array[j], array[j-increments]);
                 j -= increments) {
                Swap(array, j, j-increments);
            }
        }
    };
    template <class Elem, class Comp>
    void ShellSort(Elem array[], int n){
        for (int i = n/2; i >= 1; i /= 2) {
            for (int j = 0; j < i; ++j) {
                InsertSort<Elem, Comp>(array, j, n, i);
            }
        }
    };

    namespace szj_quick{
        template <class Elem, class Comp>
        int __Partition(Elem arr[], int left, int right){
            //  left < right
            Elem temp = arr[left];
            int mid = left;
            for (int i = left + 1; i <= right; ++i) {
                if (Comp::lt(arr[i], temp)){
                    mid ++;
                    Swap(arr, mid, i);
                }
            }
            Swap(arr, left, mid);
            return mid;
        };
        template <class Elem, class Comp>
        void __QuickSort(Elem arr[], int left, int right){

            if (right - left < 3) {
                InsertSort<Elem, Comp>(arr,left,right,1);
                return;
            }
//            if (left >= right) return ;

            int mid = __Partition<Elem, Comp>(arr, left, right);
            __QuickSort<Elem, Comp>(arr, left, mid - 1);
            __QuickSort<Elem, Comp>(arr, mid + 1, right);
        };
        template <class Elem, class Comp>
        void QuickSort(Elem arr[], int n){
            __QuickSort<Elem, Comp>(arr, 0, n-1);
        };
    }

}

#endif //SUANFA_SORT_H
