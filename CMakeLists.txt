cmake_minimum_required(VERSION 3.9)
project(SuanFa)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(SuanFa main.cpp
        Student.h
        SortTestHelper.h
        SelectionSort.h
        InsertionSort.h
        MergeSort.h
        QuickSort.h
        MaxHeap.h
        HeapSort.h
        IndexMaxHeap.h
        BinarySearch.h
        BST.h
        SequenceST.h
        FileOps.h
        test_main.cpp
        AStar.h
        TestFunc.h
        Sort.h)