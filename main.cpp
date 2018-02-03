#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"

#include "MergeSort.h"
#include "MaxHeap.h"
#include "HeapSort.h"


int main11(){
    MaxHeap<int> max_heap = MaxHeap<int>(1);
    cout<<max_heap.Size()<< endl;
    srand(time(NULL));

    int n = 5;

    for (int i = 0; i < n; ++i) {
        max_heap.Insert(rand()%50);
    }
    for (int j = 0; j < n; ++j) {

        max_heap.TestPrint();
        cout<<"------------------------  取出 "<<max_heap.ExtractMax()<<endl;
        cout<<endl;
    }

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
        int * arr4 = SortTestHelper::CopyIntArray(arr,n);
        int * arr5 = SortTestHelper::CopyIntArray(arr,n);

        SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);

        SortTestHelper::TestSort("QuickSort", QuickSort, arr1, n);

        SortTestHelper::TestSort("QuickSort3Ways", QuickSort3Ways, arr2, n);

        SortTestHelper::TestSort("HeapSort", HeapSort, arr3, n);

        SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr4, n);

        SortTestHelper::TestSort("HeapSort1", HeapSort1, arr5, n);

        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;

        cout << endl<<endl;
    }

    {
        cout<<"--大量重复键值的随机数组--random array, size = "<<n << ", range = [" <<"0,"<<100<<"]"<<endl;
        int * arr = SortTestHelper::GenerateRandomArray(n,0,100);
//    int * arr = SortTestHelper::GenerateNearlyOrderedArray(n,1000);
        int * arr1 = SortTestHelper::CopyIntArray(arr,n);
        int * arr2 = SortTestHelper::CopyIntArray(arr,n);
        int * arr3 = SortTestHelper::CopyIntArray(arr,n);
        int * arr4 = SortTestHelper::CopyIntArray(arr,n);
        int * arr5 = SortTestHelper::CopyIntArray(arr,n);

        SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);

        SortTestHelper::TestSort("QuickSort", QuickSort, arr1, n);

        SortTestHelper::TestSort("QuickSort3Ways", QuickSort3Ways, arr2, n);

        SortTestHelper::TestSort("HeapSort", HeapSort, arr3, n);

        SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr4, n);

        SortTestHelper::TestSort("HeapSort1", HeapSort1, arr5, n);

        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;

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
        int * arr4 = SortTestHelper::CopyIntArray(arr,n);
        int * arr5 = SortTestHelper::CopyIntArray(arr,n);

        SortTestHelper::TestSort("MergeSortOptimizeMemory", MergeSortOptimizeMemory, arr, n);

        SortTestHelper::TestSort("QuickSort", QuickSort, arr1, n);

        SortTestHelper::TestSort("QuickSort3Ways", QuickSort3Ways, arr2, n);

        SortTestHelper::TestSort("HeapSort", HeapSort, arr3, n);

        SortTestHelper::TestSort("MergeSortBottomToUpOptimized", MergeSortBottomToUpOptimized, arr4, n);

        SortTestHelper::TestSort("HeapSort1", HeapSort1, arr5, n);

        delete[] arr;
        delete[] arr1;
        delete[] arr2;
        delete[] arr3;
        delete[] arr4;
        delete[] arr5;

    }


    return 0;
}