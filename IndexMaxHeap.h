//
// Created by sunzhijun on 18-2-3.
//

#ifndef SUANFA_INDEXMAXHEAP_H
#define SUANFA_INDEXMAXHEAP_H


#include <iostream>
#include <string.h>

#include <cassert>
#include<math.h>
#include<string>
#include <typeinfo>

template<typename Item>
class IndexMaxHeap{

private:
    Item* _data;
    int* _indices;
    int _count;
    int _capacity;
private:
    void __ShiftUp(int index){

        while(HasParent(index) && GetItem(GetParentIndex(index)) < GetItem(index)){
            SwapIndex(index, GetParentIndex(index));
            index = GetParentIndex(index);
        }

    }
    void __ShiftDown(int index){

        while(HasLeftChild(index)){

            int child_index = GetLeftChildIndex(index);
            if(HasRightChild(index) &&
               GetItem(child_index) < GetItem(GetRightChildIndex(index))){
                child_index = GetRightChildIndex(index);
            }

            if(GetItem(index) >= GetItem(child_index)){
                break;
            }

            SwapIndex(index, child_index);
            index = child_index;
        }

    }

    void __Enlarge(){

        _capacity *= 2;
        std::cout << "/* Enlarge "<<_capacity/2+1 << "->"<<_capacity+1 << " */"<<std::endl;

        Item* data = new Item[_capacity + 1];
        memcpy(data, _data, (_indices[0] + 1) * sizeof(Item));//_indices[0]为最大索引

        delete[] _data;
        _data = data;

        int * indices = new int[_capacity + 1];
        memcpy(indices, _indices,(_count + 1) * sizeof(int));

        delete[] _indices;
        _indices = indices;


    }
/*辅助的公共函数*/
public:
    bool HasParent(int index){
        return index/2 > 0;
    }
    bool HasLeftChild(int index){
        return 2*index <= _count;
    }
    Item GetLeftChildIndex(int parent_index){
        return parent_index*2;
    }
    bool HasRightChild(int index){
        return (2*index+1) <= _count;
    }
    Item GetRightChildIndex(int parent_index){
        return parent_index*2 + 1;
    }
//    Item GetParent(int index){
//        return _data[_indices[index/2]];
//    }

    int GetParentIndex(int index){
        return  index / 2;
    }
    Item GetItem(int index){
        return _data[_indices[index]];
    }
    void SwapIndex(int a, int b){
        std::swap(_indices[a],_indices[b]);
    }

/*实现主要功能的公共函数*/
public:

    IndexMaxHeap(int capacity){
        _data = new Item[capacity + 1];
        _indices = new int[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }
    ~IndexMaxHeap(){
        delete[] _data;
        delete[] _indices;
    }
    int Size(){
        return _count;
    }
    bool IsEmpty(){
        return _count == 0;
    }

    //外部索引从0开始
    void Insert(int index, Item item){

        index ++;// 修正：外部从0开始
        assert(index >= 1);
        if(index > _capacity){
            if(_capacity * 2 < index){
                _capacity = index/2 + 1;
            }
            __Enlarge();
        }
        _data[index] = item;
        _indices[_count + 1] = index;
        _count++;
        __ShiftUp(_count);
    }
    Item ExtractMax(){
        assert(_count > 0);

        Item return_item = GetItem(1);
        _indices[1] = _indices[_count];
        _count --;
        __ShiftDown(1);
        return return_item;

    }

    void Print(){
        for (int i = 0; i <= _count; ++i) {
            std::cout<<_data[i]<<" ";
        }
        std::cout<<std::endl;
    }

};

#endif //SUANFA_INDEXMAXHEAP_H
