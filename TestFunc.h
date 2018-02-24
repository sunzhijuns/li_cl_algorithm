//
// Created by sunzhijun on 18-2-17.
//

#ifndef SUANFA_TESTFUNC_H
#define SUANFA_TESTFUNC_H

#include <assert.h> /*assert*/
#include <iostream> /*cout*/


long fact(int n){
    assert(n >= 0 && n <= 12);
    if(n<=1) return 1;
    return n*fact(n-1);

}


template <typename Pole>
void move_pole(int n, Pole start, Pole goal){
    std::cout<<n << ":"<< start<<"->"<<goal<<std::endl;
}
template <typename Pole>
void TOH(int n, Pole start, Pole goal, Pole temp){
    if(n == 0) return;
    TOH(n-1, start, temp, goal);
    move_pole(n,start,goal);
    TOH(n-1, temp, goal, start);

}

#endif //SUANFA_TESTFUNC_H
