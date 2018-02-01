#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n){
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
    return 0;
}