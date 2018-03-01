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
};
int main ()
{
    int a[] = {12, 13, 0, 5,11};
    int n = sizeof(a)/ sizeof(a[0]);

    sort::szj_quick::QuickSort<int, ElemComp<int>>(a, n);
    printf("< ");
    for (int i = 0; i < n; ++i) {
        printf ("%d ",a[i]);
    }
    printf(">\n");

    return 0;
}