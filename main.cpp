#include <string>
#include <vector>
#include "FileOps.h"
#include "BST.h"
#include "SequenceST.h"

int main(){

    BST<int,std::string> bst = BST<int,std::string>();
    bst.Insert(1,"one");
    bst.Insert(20,"two");
    bst.Insert(3,"three");
    bst.Insert(40,"four");
    bst.Insert(5,"five");
    bst.Insert(60,"six");
    bst.Insert(7,"seven");

    bst.LevelOrder();

    return 0;
}

