//
// Created by sunzhijun on 18-2-3.
//

#ifndef SUANFA_MAXHEAP_H
#define SUANFA_MAXHEAP_H

#include <iostream>
#include <string.h>

#include <cassert>
#include<math.h>
#include<string>
#include <typeinfo>

template<typename Item>
class MaxHeap{

private:
    Item* _data;
    int _count;
    int _capacity;
private:
    void __ShipUp(int index){
        while(HasParent(index) && GetParent(index) < Get(index)){
            Swap(index, GetParentIndex(index));
            index = GetParentIndex(index);
        }

    }

    void __Enlarge(){
        _capacity *= 2;
        std::cout << "/* Enlarge "<<_capacity/2+1 << "->"<<_capacity+1 << " */"<<std::endl;
        Item* data = new Item[_capacity + 1];
        memcpy(data, _data, (_count + 1) * sizeof(Item));
        delete[] _data;
        _data = data;

    }

public:
    bool HasParent(int index){
        return index/2 > 0;
    }
    Item GetParent(int index){
        return _data[index/2];
    }

    int GetParentIndex(int index){
        return  index / 2;
    }
    Item Get(int index){
        return _data[index];
    }
    void Swap(int a, int b){
        std::swap(_data[a],_data[b]);
    }


public:
    MaxHeap(int capacity){
        _data = new Item[capacity + 1];
        _count = 0;
        _capacity = capacity;
    }
    ~MaxHeap(){
        delete[] _data;
    }
    int Size(){
        return _count;
    }
    bool IsEmpty(){
        return _count == 0;
    }

    void Insert(Item item){
        if(_count + 1 > _capacity){
            __Enlarge();
        }
        _data[_count+1] = item;
        _count++;
        __ShipUp(_count);
    }

    void Print(){
        for (int i = 0; i <= _count; ++i) {
            std::cout<<_data[i]<<" ";
        }
        std::cout<<std::endl;
    }

public:
    // 以树状打印整个堆结构
    void TestPrint(){
        using namespace std;

        // 我们的testPrint只能打印100个元素以内的堆的树状信息
        if( Size() >= 100 ){
            std::cout<<"This print function can only work for less than 100 int";
            return;
        }

        // 我们的testPrint只能处理整数信息
        if( typeid(Item) != typeid(int) ){
            std::cout <<"This print function can only work for int item";
            return;
        }

        cout<<"The max heap size is: "<<Size()<<endl;
        cout<<"Data in the max heap: ";
        for( int i = 1 ; i <= Size() ; i ++ ){
            // 我们的testPrint要求堆中的所有整数在[0, 100)的范围内
            assert( _data[i] >= 0 && _data[i] < 100 );
            cout<<_data[i]<<" ";
        }
        cout<<endl;
        cout<<endl;

        int n = Size();
        int max_level = 0;
        int number_per_level = 1;
        while( n > 0 ) {
            max_level += 1;
            n -= number_per_level;
            number_per_level *= 2;
        }

        int max_level_number = int(pow(2, max_level-1));
        int cur_tree_max_level_number = max_level_number;
        int index = 1;
        for( int level = 0 ; level < max_level ; level ++ ){
            string line1 = string(max_level_number*3-1, ' ');

            int cur_level_number = min(_count-int(pow(2,level))+1,int(pow(2,level)));
            bool isLeft = true;
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index ++ , index_cur_level ++ ){
                putNumberInLine( _data[index] , line1 , index_cur_level , cur_tree_max_level_number*3-1 , isLeft );
                isLeft = !isLeft;
            }
            cout<<line1<<endl;

            if( level == max_level - 1 )
                break;

            string line2 = string(max_level_number*3-1, ' ');
            for( int index_cur_level = 0 ; index_cur_level < cur_level_number ; index_cur_level ++ )
                putBranchInLine( line2 , index_cur_level , cur_tree_max_level_number*3-1 );
            cout<<line2<<endl;

            cur_tree_max_level_number /= 2;
        }
    }

private:
    void putNumberInLine( int num, std::string &line, int index_cur_level, int cur_tree_width, bool isLeft){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int offset = index_cur_level * (cur_tree_width+1) + sub_tree_width;
        assert(offset + 1 < line.size());
        if( num >= 10 ) {
            line[offset + 0] = '0' + num / 10;
            line[offset + 1] = '0' + num % 10;
        }
        else{
            if( isLeft)
                line[offset + 0] = '0' + num;
            else
                line[offset + 1] = '0' + num;
        }
    }

    void putBranchInLine( std::string &line, int index_cur_level, int cur_tree_width){

        int sub_tree_width = (cur_tree_width - 1) / 2;
        int sub_sub_tree_width = (sub_tree_width - 1) / 2;
        int offset_left = index_cur_level * (cur_tree_width+1) + sub_sub_tree_width;
        assert( offset_left + 1 < line.size() );
        int offset_right = index_cur_level * (cur_tree_width+1) + sub_tree_width + 1 + sub_sub_tree_width;
        assert( offset_right < line.size() );

        line[offset_left + 1] = '/';
        line[offset_right + 0] = '\\';
    }
};

#endif //SUANFA_MAXHEAP_H
