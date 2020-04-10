/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/8/2020, 11:20:01 AM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/8/2020, 11:20:10 AM 
 * Description: 
*/ 
#pragma once

#include "Vector.h"
#include "utils.hpp"
#include "BinaryHeap.hpp"

void binaryHeap_test(){
    Vector<int> test_v(11);
    generateRandomVector(0,100,test_v);
    
    printV<int>(std::cout, test_v);
    BinaryHeap<int> test_BH(test_v);
    test_BH.print(std::cout);
    test_BH.insert(genRandomInt(0,100));
    test_BH.print(std::cout);
    test_BH.deleteMin();
    test_BH.deleteMin();
    test_BH.print(std::cout);
}
