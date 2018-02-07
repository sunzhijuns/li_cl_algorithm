#include <string>
#include <vector>
#include "FileOps.h"
#include "BST.h"
#include "SequenceST.h"

int main(){

    BST<int,int> bst = BST<int,int>();
    bst.Insert(1,1);
    bst.Insert(2,2);
    bst.Insert(6,6);
    bst.Insert(5,5);
    bst.Insert(3,3);
    bst.Insert(7,7);
    bst.Insert(100,100);

    bst.LevelOrder();

    int* floor = bst.Floor(99);
    if(floor != NULL){
        std::cout<<*floor<<std::endl;
    }

    int * ceil = bst.Ceil(4);
    if(ceil != NULL){
        std::cout << *ceil<<std::endl;
    }



    return 0;
}

