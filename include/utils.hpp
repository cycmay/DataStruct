/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/1/2020, 2:43:51 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/7/2020, 10:42:41 AM 
 * Description: 
*/ 

#pragma once

#include <ctime>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>

#include "Vector.h"
#include "BinaryHeap.hpp"


// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR] 闭区间
// arr 为 n个元素的数组
void generateRandomArray(int n, int rangeL, int rangeR, int arr[]) {
    assert(rangeL <= rangeR);
    
    srand((unsigned int)(time(NULL))); // 随机种子
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return;
}

void generateRandomVector(int rangeL, int rangeR, Vector<int> &v){
    assert(rangeL < rangeR);

    std::default_random_engine e(time(0));
    std::uniform_int_distribution<int> u{rangeL, rangeR};

    for(size_t i = 0; i < v.size() ; ++i){
        v[i] = u(e);
    }
    return;
}

// 生成一个随机数 范围[rangeL, rangeR]
int genRandomInt(int rangeL, int rangeR){
    assert(rangeL <= rangeR);
    return (int)(rand()%(rangeR - rangeL + 1) + rangeL);
}

// 打印容器Vector
template <typename Comparable>
void printV(std::ostream & out, Vector<Comparable> & v){
    out << "Vector: " ;
    for(int i = 0; i < v.size(); ++i)
        out << v[i] << " ";
    out << std::endl;
}


void log(char str[]){
    std::cout << "\nlog: ";
    std::cout<< str << std::endl;
}