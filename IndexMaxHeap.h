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

        while(__HasParent(index) && __GetItem(__GetParentIndex(index)) < __GetItem(index)){
            __SwapIndex(index, __GetParentIndex(index));
            index = __GetParentIndex(index);
        }

    }
    void __ShiftDown(int index){

        while(__HasLeftChild(index)){

            int child_index = __GetLeftChildIndex(index);
            if(__HasRightChild(index) &&
                    __GetItem(child_index) < __GetItem(GetRightChildIndex(index))){
                child_index = GetRightChildIndex(index);
            }

            if(__GetItem(index) >= __GetItem(child_index)){
                break;
            }

            __SwapIndex(index, child_index);
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
/*辅助的私有函数*/
private:
    bool __HasParent(int index){
        return index/2 > 0;
    }
    bool __HasLeftChild(int index){
        return 2*index <= _count;
    }
    int __GetLeftChildIndex(int parent_index){
        return parent_index*2;
    }
    bool __HasRightChild(int index){
        return (2*index+1) <= _count;
    }
    int GetRightChildIndex(int parent_index){
        return parent_index*2 + 1;
    }

    int __GetParentIndex(int index){
        return  index / 2;
    }
    Item __GetItem(int index){
        return _data[_indices[index]];
    }
    void __SwapIndex(int a, int b){
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

        Item return_item = __GetItem(1);
        _indices[1] = _indices[_count];
        _count --;
        __ShiftDown(1);
        return return_item;

    }

    //外部索引从0开始
    int ExtractMaxIndex(){
        assert(_count > 0);

        int return_index = _indices[1] - 1;//外部索引从0开始
        _indices[1] = _indices[_count];
        _count --;
        __ShiftDown(1);
        return return_index;

    }

    //外部索引从0开始
    Item GetItem(int index){
        return _data[index + 1];
    }

    //外部索引从0开始
    void ChangeItem(int index, Item new_item){

        index++;
        _data[index] = new_item;
        for (int i = 1; i < _count; ++i) {
            if(index == i){
                __ShiftUp(i);
                __ShiftDown(i);
                return;
            }
        }

    }


    void Print(){
        for (int i = 0; i <= _count; ++i) {
            std::cout<<_data[i]<<" ";
        }
        std::cout<<std::endl;
    }

};

#endif //SUANFA_INDEXMAXHEAP_H
