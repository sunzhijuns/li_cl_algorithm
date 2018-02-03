cmake_minimum_required(VERSION 3.9)
project(SuanFa)

set(CMAKE_CXX_STANDARD 11)

add_executable(SuanFa main.cpp Student.h SortTestHelper.h SelectionSort.h InsertionSort.h MergeSort.h QuickSort.h MaxHeap.h HeapSort.h IndexMaxHeap.h)