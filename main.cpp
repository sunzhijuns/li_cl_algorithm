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

    bst.Remove(6);

    std::cout << std::endl;
    bst.LevelOrder();


    return 0;
}

