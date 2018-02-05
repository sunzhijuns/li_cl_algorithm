//
// Created by sunzhijun on 18-2-5.
//

#ifndef SUANFA_BST_H
#define SUANFA_BST_H

#include <iostream>


template<typename Key, typename Value>
class BST{
private:
    struct Node{
        Key key;
        Value value;
        Node * left;
        Node * right;

        Node(Key key, Value value){
            this->key=key;
            this->value=value;
            this->left = this->right = NULL;
        }
    };
    Node * _root;
    int _count;

private:
    //返回子树根节点
    Node* __Insert(Node* node, Key key, Value value){
        if(node == NULL){
            _count++;
            return new Node(key, value);
        }
        else if(key < node->key){
            node->left = __Insert(node->left,key, value);
        }
        else if(key == node->key){
            node->value = value;
        }
        else{
            node->right = __Insert(node->right,key,value);
        }

        return node;
    }
public:
    BST(){
        _root = NULL;
        _count = 0;
    }
    ~BST(){
        //TODO:~BST()
    }
    int Size(){
        return _count;
    }
    bool IsEmpty(){
        return _count == 0;//|| _root == NULL;
    }
    void Insert(Key key, Value value){
        _root = __Insert(_root, key, value);
    }
};

#endif //SUANFA_BST_H
