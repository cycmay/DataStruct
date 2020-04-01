//
//  queue_test.cpp
//  DataStruct
//
//  Created by Mr.Bicycle on 2020/3/31.
//

#include <iostream>

#include "queue_test.h"

#include "Queue.h"
#include "utils.h"

void queue_test(){
    
    srand((unsigned int)(time(NULL))); // 随机种子
    
    Queue<int> queue;
    for (int i = 0; i < NUM_MAX; ++i) {
        int temp = genRandomInt(0, NUM_RAN_MAX);
        queue.enqueue(temp);
    }
    queue.print(std::cout);
    queue.dequeue();
    queue.dequeue();
    queue.print(std::cout);
    std::cout << queue.back() << std::endl;
    std::cout << queue.front() << std::endl;
    std::cout << queue.empty() << std::endl;
    std::cout << queue.size() << std::endl;
    queue.enqueue(122);
    queue.print(std::cout);
    queue.clear();
    queue.print(std::cout);
    
}

