/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/7/2020, 10:45:35 AM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/7/2020, 10:45:41 AM 
 * Description: 
*/ 

#pragma once

#include "Sort.hpp"
#include "utils.hpp"
#include "Vector.h"

void insertsort_test(){
    Vector<int> test_v(20);
    // generateRandomVector(0,100,test_v);
    // printV(std::cout, test_v);
    // insertionSort<int>(test_v);
    // printV(std::cout, test_v);
    generateRandomVector(0,100,test_v);
    printV(std::cout, test_v);
    // shellSort<int>(test_v);
    insertionSort<int>(test_v, 0, 10);
    printV(std::cout, test_v);

}

void heapsort_test(){
    Vector<int> test_v(10);
    generateRandomVector(0,100,test_v);
    printV(std::cout, test_v);
    heapSort<int>(test_v);
    printV(std::cout, test_v);
}

void mergesort_test(){
    Vector<int> test_v(10);
    generateRandomVector(0,100,test_v);
    printV(std::cout, test_v);
    mergeSort<int>(test_v);
    printV(std::cout, test_v);
}

void quicksort_test(){
    Vector<int> test_v(1000);
    generateRandomVector(0,10000,test_v);
    printV(std::cout, test_v);
    quickSort<int>(test_v);
    printV(std::cout, test_v);
}