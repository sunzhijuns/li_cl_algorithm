//
// Created by sunzhijun on 18-2-6.
//

#ifndef SUANFA_SEQUENCEST_H
#define SUANFA_SEQUENCEST_H

#include <iostream>
#include <cassert>

template<typename Key, typename Value>
class SequenceST{
private:
    struct Node{
        Key key;
        Value value;
        Node * next;
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->next = NULL;
        }
    };

    Node* _head;
    int _count;

public:
    SequenceST(){
        _head = NULL;
        _count = 0;
    }

    ~SequenceST(){
        while (_head != NULL){
            Node * node = _head;
            _head = _head->next;
            delete node;
            _count--;
        }

        assert(_head == NULL && _count == 0);
    }

    int Size(){
        return _count;
    }

    bool IsEmpty(){
        return _count == 0;
    }

    void Insert(Key key, Value value){

        Node * node = _head;
        while (node != NULL){

            if(node->key == key){
                node->value = value;
                return;
            }
            node = node->next;

        }

        Node * new_node = new Node(key,value);
        new_node->next = _head;
        _head = new_node;
        _count ++;
    }

    bool Contain(Key key){

        Node * node = _head;
        while (node != NULL){
            if(node->key == key){
                return true;
            }
            else{
                node = node->next;
            }
        }
        return false;

    }

    Value* Search(Key key){

        Node* node = _head;

        while (node != NULL){

            if(node->key == key){
                return &(node->value);
            }
            else{
                node = node->next;
            }
        }

        return NULL;
    }

    bool Remove(Key key){

        if(_head == NULL){
            return true;
        }
//        //一个元素
//        if(_count == 1){
//            if(_head->key == key){
//                delete _head;
//                _head == NULL;
//                _count = 0;
//                return true;
//            }
//            else{
//                return false;
//            }
//        }
        //要删除的是头结点,已知_count >= 1,//不需要_count>=2
        if(_head->key == key){
            Node * node = _head;
            _head = _head->next;
            delete node;
            _count--;
            return true;
        }


        Node * pre_node = _head;
        Node * node = _head->next;

        while(node != NULL){

            if(node->key == key){
                pre_node->next = node->next;
                _count--;
                delete node; node = NULL;
                return true;
            }
            else{
                pre_node = node;
                node = node->next;
            }
        }

        return false;
    }

private:
    bool __Contain(Node * node, Key key){

        if(node == NULL){
            return false;
        }
        else if(node->key == key){
            return true;
        }
        else{
            return __Contain(node->next, key);
        }
    }

    Value* __Search(Node* node, Key key){

        if(node == NULL){
            return NULL;
        }
        else if(node->key == key){
            return &(node->value);
        }
        else{
            return __Search(node->next, key);
        }

    }

};

#endif //SUANFA_SEQUENCEST_H
