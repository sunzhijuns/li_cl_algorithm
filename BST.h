//
// Created by sunzhijun on 18-2-5.
//

#ifndef SUANFA_BST_H
#define SUANFA_BST_H

#include <iostream>
#include <queue>
#include <cassert>


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

        Node(Node * node){
            this->key = node->key;
            this->value = node->value;
            this->left = node->left;
            this->right = node->right;
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

    //node != NULL
    Node * __Minimum(Node * node){

        if(node->left != NULL){
            return __Minimum(node->left);
        }else{
            return node;
        }

    }

    Node* __Maximum(Node* node){

        if(node->right != NULL){
            return __Maximum(node->right);
        }
        else{
            return node;
        }
    }

    Node* __RemoveMin(Node* node){

        Node* pre_min_node = NULL;
        Node* min_node = node;
        while (min_node->left != NULL){
            pre_min_node = min_node;
            min_node = min_node->left;
        }

//        //删除根节点
//        if(pre_min_node == NULL){
//            node = node->right;
//        }
//        else{
//            pre_min_node->left = min_node->right;
//        }
//        delete min_node;
//        _count--;
//        return node;

        //删除根节点
        if(pre_min_node == NULL){

            node = node->right;

            delete min_node;
            _count--;
            return node;
        }
//        else if(min_node->right ==NULL){
//
//            //删除叶子节点
//            pre_min_node->left = NULL;
//            delete min_node;
//            _count--;
//            return node;
//        }
        else{
            //有右孩子，无左孩子
            pre_min_node->left = min_node->right;
            delete min_node;
            _count--;
            return node;
        }

//        return node;


    }

    Node* __RemoveMinRecursion(Node* node){

        if(node->left == NULL){

            Node * right_node = node->right;
            delete node;
            _count--;
            return right_node;
        }
        node->left = __RemoveMinRecursion(node->left);
        return node;
    }

    Node* __RemoveMaxRecursion(Node * node){

        if(node->right == NULL){
            Node* left_node = node->left;
            delete node;
            _count--;
            return left_node;
        }
        node->right = __RemoveMaxRecursion(node->right);
        return node;
    }

    //node != NULL
    Node* __Remove(Node * node, Key key){

        if(node->key == key){
            if(node->left == NULL){
                Node * right_node = node->right;
                delete node;
                _count--;
                return right_node;
            }
            else if(node->right == NULL){
                Node * left_node = node->left;
                delete node;
                _count--;
                return left_node;
            }
            else{

//                Node * right_min_node = __Minimum(node->right);
//                right_min_node->left = node->left;
//                delete node;
//                _count--;
//                return right_min_node;

                Node * successor = new Node(__Minimum(node->right));
                successor->right = __RemoveMinRecursion(node->right);
                _count++;
                successor->left = node->left;

                delete node;
                _count--;

                return successor;


            }
        }
        else if(key < node->key && node->left != NULL){
            node->left = __Remove(node->left, key);
            return node;
        }
        else if(key > node->key && node->right != NULL){
            node->right = __Remove(node->right, key);
            return node;
        }
        return node;
    }

    //后继
    Node * __Successor(Node* node){
        if(node != NULL){
            return __Minimum(node->right);
        }
        return NULL;
    }

    //前驱
    Node* __Preducessor(Node * node){
        if(node!= NULL){
            return __Maximum(node->left);
        }
        return NULL;
    }

    Node* __Floor(Node* node,Key key){

        if(node != NULL){
            if(node->key == key){
                return node;
            }
            else if(node->key < key){
                Node * right_floor = __Floor(node->right, key);
                if(right_floor != NULL){
                    return right_floor;
                }
                else{
                    return node;
                }

            }
            else{
                return __Floor(node->left, key);
            }
        }else{
            return NULL;
        }
    }

    Node* __Ceil(Node* node, Key key){

        if(node != NULL){

            if(node->key == key){
                return node;
            }
            else if(node->key > key){
                Node * left_ceil_node = __Ceil(node->left,key);
                if(left_ceil_node != NULL){
                    return left_ceil_node;
                }
                else{
                    return node;
                }
            }
            else{
                return __Ceil(node->right, key);
            }
        }
        else{
            return NULL;
        }
    }

    void Visit(Node* node){
        if(node == NULL) return;

        std::cout<<node->key<<":"<<node->value<<";"<<std::endl;
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

    Key Minimum(){
        assert(!IsEmpty());
        Node* minimum_node = __Minimum(_root);

        return minimum_node->key;
    }

    Key Maximum(){
        assert(!IsEmpty());
        Node* maximum_node = __Maximum(_root);

        return maximum_node->key;
    }

    Key* Floor(Key key){

        Node * floor = __Floor(_root, key);
        if (floor != NULL){
            return &(floor->key);
        }
        else{
            return NULL;
        }

    }

    Key* Ceil(Key key){
        Node * ceil = __Ceil(_root ,key);
        if(ceil != NULL){
            return &(ceil->key);
        }
        else{
            return NULL;
        }
    }

    void RemoveMin(){
        if(!IsEmpty()){
            _root = __RemoveMin(_root);
        }
    }

    void RemoveMax(){
        if(!IsEmpty()){
            _root = __RemoveMaxRecursion(_root);
        }
    }

    void Remove(Key key){
        if(!IsEmpty()){
            _root = __Remove(_root, key);
        }
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
};

#endif //SUANFA_BST_H
