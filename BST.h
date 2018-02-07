//
// Created by sunzhijun on 18-2-5.
//

#ifndef SUANFA_BST_H
#define SUANFA_BST_H

#include <iostream>
#include <queue>


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

    bool __Contain(Node* node, Key key){
        if(node == NULL){
            return false;
        }
        if(node->key == key){
            return true;
        }
        else if(key < node->key){
            return __Contain(node->left, key);
        }
        else{
            return __Contain(node->right, key);
        }
    }

    Value* __Search(Node* node, Key key){
        if(node == NULL){
            return NULL;
        }

        if(node->key == key){
            return &(node->value);
        }
        else if(key < node->key){
            return __Search(node->left, key);
        }
        else{
            return __Search(node->right, key);
        }
    }

    void __PreOrder(Node* node){

        if(node == NULL) return;

        Visit(node);
        __PreOrder(node->left);
        __PreOrder(node->right);

    }

    void __InOrder(Node* node){

        if(node == NULL) return;

        __InOrder(node->left);
        Visit(node);
        __InOrder(node->right);

    }

    void __PostOrder(Node* node){

        if(node == NULL) return;

        __PostOrder(node->left);
        __PostOrder(node->right);
        Visit(node);

    }

    void __Destroy(Node* node){
        if(node != NULL){
            __Destroy(node->left);
            __Destroy(node->right);
            delete node;
            _count--;
        }
    }

public:

    BST(){
        _root = NULL;
        _count = 0;
    }
    ~BST(){
        __Destroy(_root);
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
    bool Contain(Key key){
        return __Contain(_root, key);
    }
    Value* Search(Key key){
        return __Search(_root, key);
    }
    void PreOrder(){
        __PreOrder(_root);
    }

    void InOrder(){
        __InOrder(_root);
    }
    void PostOrder(){
        __PostOrder(_root);
    }

    void LevelOrder(){

        std::queue<Node*> queue;
        queue.push(_root);
        while(!queue.empty()){
            Node* node = queue.front();
            queue.pop();

            Visit(node);

            if(node->left != NULL){
                queue.push(node->left);
            }
            if(node->right != NULL){
                queue.push(node->right);
            }
        }

    }

    void Visit(Node* node){
        if(node == NULL) return;

        std::cout<<node->key<<":"<<node->value<<";"<<std::endl;
    }
};

#endif //SUANFA_BST_H
