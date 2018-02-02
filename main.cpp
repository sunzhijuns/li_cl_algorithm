#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

#include "MergeSort.h"



int main11(){
    int n = 100;
    int * a = SortTestHelper::GenerateRandomArray(n,0,10);
    QuickSort3Ways(a,n);
    SortTestHelper::PrintArray(a,100);
    delete[] a;
    return 0;
}

int main() {
    int n = 100*10000;
    int print_n = 100;
    {
        cout<<"--一般的随机数组---random array, size = "<<n << ", range = [" <<"0,"<<n<<"]"<<endl;
        int * arr = SortTestHelper::GenerateRandomArray(n,0,n);
//    int * arr = SortTestHelper::GenerateNearlyOrderedArray(n,1000);
        int * arr1 = SortTestHelper::CopyIntArray(arr,n);
        int * arr2 = SortTestHelper::CopyIntArray(arr,n);
        int * arr3 = SortTestHelper::CopyIntArray(arr,n);

        SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);

        SortTestHelper::TestSort("QuickSort", QuickSort, arr1, n);

        SortTestHelper::TestSort("QuickSort3Ways", QuickSort3Ways, arr2, n);

        SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr3, n);

        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

        cout << endl<<endl;
    }

    {
        cout<<"--大量重复键值的随机数组--random array, size = "<<n << ", range = [" <<"0,"<<100<<"]"<<endl;
        int * arr = SortTestHelper::GenerateRandomArray(n,0,100);
//    int * arr = SortTestHelper::GenerateNearlyOrderedArray(n,1000);
        int * arr1 = SortTestHelper::CopyIntArray(arr,n);
        int * arr2 = SortTestHelper::CopyIntArray(arr,n);
        int * arr3 = SortTestHelper::CopyIntArray(arr,n);

        SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);

        SortTestHelper::TestSort("QuickSort", QuickSort, arr1, n);

        SortTestHelper::TestSort("QuickSort3Ways", QuickSort3Ways, arr2, n);

        SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr3, n);

        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;

        cout << endl<<endl;
    }


    {
        int swap_times = 1000;
        cout<<"--几乎有序数组--nearly ordered array, size = "<<n << ", swap = "<<swap_times<<endl;
//        int * arr = SortTestHelper::GenerateRandomArray(n,0,100);
    int * arr = SortTestHelper::GenerateNearlyOrderedArray(n,swap_times);
        int * arr1 = SortTestHelper::CopyIntArray(arr,n);
        int * arr2 = SortTestHelper::CopyIntArray(arr,n);
        int * arr3 = SortTestHelper::CopyIntArray(arr,n);

        SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);

        SortTestHelper::TestSort("QuickSort", QuickSort, arr1, n);

        SortTestHelper::TestSort("QuickSort3Ways", QuickSort3Ways, arr2, n);

        SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr3, n);

        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
    }


    return 0;
}