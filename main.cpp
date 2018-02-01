#include <iostream>
#include "Student.h"

using namespace std;

template <typename T>

void SelectionSort(T arr[], int n){
    for (int i = 0; i < n; ++i) {
        int min_index = i;
        for (int j = i+1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr[i], arr[min_index]);
    }
}

int main() {
    int a[10] = {1,3,3,44};
    SelectionSort(a,10);
    for (int i = 0; i < 10; ++i) {
        cout<<a[i]<<"-";
    }
    cout << endl;

    float b[10] = {1.0,3.3,3.1,44.1};
    SelectionSort(b,10);
    for (int i = 0; i < 10; ++i) {
        cout<<b[i]<<"-";
    }
    cout << endl;

    string c[4] = {"d","a","c","e"};
    SelectionSort(c,4);
    for (int i = 0; i < 4; ++i) {
        cout<<c[i]<<"-";
    }
    cout << endl;

    Student students[4]={
            {"d3e3d",90},{"cddc",23},{"bcfd",22},{"fdddd",100}
    };
    SelectionSort(students,4);
    for (int i = 0; i < 4; ++i) {
        cout<<students[i]<<"-";
    }
    cout << endl;

    return 0;
}