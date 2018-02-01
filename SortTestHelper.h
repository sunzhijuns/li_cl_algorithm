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

    template<typename T>
    void PrintArray(T arr[], int n){
        for (int i = 0; i < n; ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

#endif //SUANFA_SORTTESTHELPER_H
