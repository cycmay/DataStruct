#include "util.h"

#include <ctime>
#include <cassert>
#include <cstdlib>
#include <iostream>

// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR] 闭区间
// arr 为 n个元素的数组
void generateRandomArray(int n, int rangeL, int rangeR, int arr[]) {
    assert(rangeL <= rangeR);
    
    srand((unsigned int)(time(NULL))); // 随机种子
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return;
}

// 生成一个随机数 范围[rangeL, rangeR]
int genRandomInt(int rangeL, int rangeR){
    assert(rangeL <= rangeR);
    return (int)(rand()%(rangeR - rangeL + 1) + rangeL);
}

void log(char str[]){
    std::cout << "\nlog: ";
    std::cout<< str << std::endl;
}