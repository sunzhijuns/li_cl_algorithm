//
// Created by sunzhijun on 18-2-6.
//
/* floor example */
#include <stdio.h>      /* printf */
#include <math.h>       /* floor */
#include "Sort.h"

template <class Elem>
class ElemComp{
public:
    inline static bool lt(Elem& a, Elem& b){
        return a < b;
    }
    inline static bool eq(Elem& a, Elem& b){
        return a == b;
    }
    inline static bool gt(Elem& a, Elem& b){
        return a > b;
    }
};
int main ()
{
    int a[] = {12, 13, 0, 5,11,11,3233,5,6,4,4,56565,44};
    int n = sizeof(a)/ sizeof(a[0]);

    printf("< ");
    for (int i = 0; i < n; ++i) {
        printf ("%d ",a[i]);
    }
    printf(">\n");

    sort::szj_merge_sort::MergeSort<int, ElemComp<int>>(a, n);
    printf("< ");
    for (int i = 0; i < n; ++i) {
        printf ("%d ",a[i]);
    }
    printf(">\n");

    return 0;
}