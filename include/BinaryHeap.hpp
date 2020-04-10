/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/8/2020, 8:34:36 AM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/8/2020, 8:34:44 AM 
 * Description: 
 * 二叉堆 使用简单的数组
*/ 

#pragma once

#include "Vector.h"
#include <iostream>

template <typename Comparable>
class BinaryHeap{
public:
    explicit BinaryHeap(int capacity=100);
    explicit BinaryHeap(const Vector<Comparable> & items);

    bool empty() const;
    const Comparable & findMin() const;
    
    void insert(const Comparable &x);
    void deleteMin();
    void deleteMin(Comparable & minItem);
    void clear();
    void print(std::ostream & out);

private:
    int currentSize;    // number of elements in heap
    Vector<Comparable> array;   // the heap array
    void buildHeap();
    void percolateDown(int hole);
};

// insert item x allowing duplicates
template <typename Comparable>
void BinaryHeap<Comparable>::insert(const Comparable &x){
    if(currentSize == array.size() - 1)
    // array 0位置没有使用
        array.resize(array.size() * 2);
    
    // percolate up
    int hole = ++currentSize;
    for(; hole > 1 && x < array[hole/2]; hole /= 2)
        array[hole] = array[hole/2];
    array[hole] = x;
}

// remove the minimum item
template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(){
    if(empty())
        return;
    // 将最后一个结点的值赋予root结点 同时最后一个指针自减
    array[1] =  array[currentSize--];
    // 将root结点的值下滤
    percolateDown(1);

}

template <typename Comparable>
void BinaryHeap<Comparable>::deleteMin(Comparable & minItem){
    if(empty())
        return;
    minItem = array[1];
    array[1] = array[currentSize--];
    percolateDown(1);
}

// Internal method to percolate down in the heap
// hole is the index at which the percolate begin
template <typename Comparable>
void BinaryHeap<Comparable>::percolateDown(int hole){
    int child;
    Comparable temp = array[hole];
    // 迭代直到没有子结点
    for(; hole*2 <= currentSize; hole = child){
        child = hole*2;
        // 选定两个孩子结点较小的一个
        if(child != currentSize && array[child+1]<array[child])
            child++;
        // 若孩子结点比hole结点更小 交换之 
        if(array[child]<temp)
            array[hole] = array[child];
        else
            break;
    }
    array[hole] = temp;
}

// the heap is empty or not
template <typename Comparable>
bool BinaryHeap<Comparable>::empty() const{
    return currentSize == 0;
}

// find the minimum item in the array
template <typename Comparable>
const Comparable & BinaryHeap<Comparable>::findMin() const{
    if(empty())
        return nullptr;
    return array[1];
}

// Establish heap order property from an arbitary arrangement of items.
template <typename Comparable>
void BinaryHeap<Comparable>::buildHeap(){
    for(int i = currentSize/2; i >0;  --i)
    // currentsize / 2 是当前二叉堆完全二叉树的最后一个非叶子结点
        percolateDown(i);
}

// contractor function
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(const Vector<Comparable> & items):
    currentSize(items.size()), array(items.size()+1){
    // insert items
    // 二叉数组的第一个元素没有实际意义 故加1
    for(int i = 0; i < items.size();  ++i)
        array[i+1] = items[i];
    // build heap
    buildHeap();
}
template <typename Comparable>
BinaryHeap<Comparable>::BinaryHeap(int capcity):currentSize(0){
    array.reserve(capcity);
}

template <typename Comparable>
void BinaryHeap<Comparable>::print(std::ostream & out){
    out << "BinaryHeap: ";
    for(int i = 0; i < currentSize; i++)
        out << array[i+1] << " ";
    out << std::endl;
}