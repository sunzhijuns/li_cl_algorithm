//
// Created by sunzhijun on 18-2-1.
//

#ifndef SUANFA_SORTTESTHELPER_H
#define SUANFA_SORTTESTHELPER_H

#include <iostream>
#include <cassert>

using namespace std;

namespace SortTestHelper{
    int* GenerateRandomArray(int n, int range_l, int range_r){

        assert(range_l <= range_r);

        int *arr = new int[n];

        srand(time(NULL));

        for (int i = 0; i < n; i++)
            arr[i] = rand() % (range_r - range_l + 1) + range_l;
        return arr;
    }

    int* GenerateNearlyOrderedArray(int n, int swap_times){
        int* arr = new int[n];
        for (int i = 0; i < n; ++i) {
            arr[i] = i;
        }
        srand(time(NULL));
        for (int j = 0; j < swap_times; ++j) {
            int pos_x = rand()%n;
            int pos_y = rand()%n;
            swap(arr[pos_x],arr[pos_y]);
        }
        return arr;
    }

    template<typename T>
    void PrintArray(T arr[], int n){
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    template<typename T>
    bool IsSorted(T arr[], int n){
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]){
                return false;
            }
        }
        return true;
    }

    template<typename T>
    void TestSort(const string& sort_name, void(* sort)(T[], int), T arr[], int n){

        clock_t start_time = clock();
        sort(arr,n);
        clock_t end_time = clock();
        assert(IsSorted(arr, n));
        cout << sort_name << " : " << double(end_time - start_time) / CLOCKS_PER_SEC << " s" << endl;
        return;

    }

    int* CopyIntArray(int a[], int n){
        int * arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }


}

#endif //SUANFA_SORTTESTHELPER_H
