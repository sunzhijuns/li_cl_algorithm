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
    inline void Swap(Elem array[], const int& i, const int& j){
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

    namespace szj_heap_sort{
        template <class Elem, class Comp>
        class MaxHeapForSort{
        private:
            Elem* _data;
            int _count;
            void ShiftDown(int pos);
        public:
            MaxHeapForSort(Elem* data, const int& num);
            void RemoveMax();
            inline bool IsLeaf(const int& pos) const {
                return (pos >= _count/2) && (pos < _count);
            }
            inline int Left(const int& pos) const {
                return 2*pos + 1;
            }
            inline int Right(const int& pos) const {
                return 2*pos + 2;
            }
            inline int Parent(const int& pos) const {
                return (pos - 1) / 2;
            }
        };

        template <class Elem, class Comp>
        MaxHeapForSort<Elem, Comp>::
        MaxHeapForSort(Elem* data,const int& num){
            _data = data; _count = num;
            for (int i = _count/2 - 1; i >= 0; --i) {
                ShiftDown(i);
            }
        }

        template <class Elem, class Comp>
        void
        MaxHeapForSort<Elem, Comp>::
        RemoveMax(){
//            if ( _count == 0) return false;
            --_count;
            Swap(_data,0,_count); //Swap max with last value
            if (_count != 0) ShiftDown(0);
        };

        template <class Elem, class Comp>
        void
        MaxHeapForSort<Elem, Comp>::
        ShiftDown(int pos) {
            while(!IsLeaf(pos)){
                int max = Left(pos);
                int right = Right(pos);
                if (right < _count && Comp::gt(_data[right], _data[max])){
                    max = right;
                }
                if (Comp::gt(_data[pos], _data[max])) return;
                Swap(_data, pos, max);
                pos = max;
            }
        }

        template <class Elem, class Comp>
        void HeapSort(Elem arr[], int n){

            MaxHeapForSort<Elem,Comp> heap(arr,n);
            for (int i = 0; i < n-1; ++i) {
                heap.RemoveMax();   // RemoveMax places max at end
            }

        };
    }

    namespace szj_merge_sort{
        template <class Elem, class Comp>
        void __Merge(Elem arr[], Elem* aux, int left ,int mid ,int right){
            for (int i = left; i <= right; ++i) {
                aux[i] = arr[i];
            }
            int i1 = left;
            int i2 = mid+1;
            for (int i = left; i <= right; ++i) {
                if (i1 > mid){
                    arr[i] = aux[i2];
                    i2++;
                } else if (i2 > right){
                    arr[i] = aux[i1];
                    i1++;
                }
                else if (Comp::gt(aux[i2], aux[i1])){
                    arr[i] = aux[i1];
                    i1++;
                } else {
                    arr[i] = aux[i2];
                    i2++;
                }
            }
        };
        template <class Elem, class Comp>
        void __MergeSort(Elem arr[],Elem* aux, int left, int right){
            if (right - left > 3) {
                InsertSort<Elem, Comp>(arr, left, right, 1);
                return;
            }
//            if (left >= right) return;
            int mid = left + (right - left) / 2;
            __MergeSort<Elem, Comp>(arr,aux,left,mid);
            __MergeSort<Elem, Comp>(arr,aux,mid+1,right);
            if (Comp::gt(arr[mid], arr[mid+1])){
                __Merge<Elem, Comp>(arr,aux,left,mid,right);
            }
        };
        template <class Elem, class Comp>
        void MergeSort(Elem arr[], int n){
            Elem* aux = new Elem[n];
            __MergeSort<Elem, Comp>(arr,aux, 0, n-1);
            delete aux;
        };


    }

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
//                InsertSort<Elem, Comp>(arr,left,right,1);
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
            InsertSort<Elem, Comp>(arr,0,n-1,1);
        };
    }


}

#endif //SUANFA_SORT_H
