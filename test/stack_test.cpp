/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/3/2020, 6:13:00 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/3/2020, 6:13:11 PM 
 * Description: 
*/ 

#include <iostream>
#include <random>
#include <ctime>

#include "Stack.h"

#include "stack_test.h"



void stack_test(){
    std::uniform_int_distribution<unsigned> u(1,1000);
    std::default_random_engine e(time(0));

    Stack<int> stack;
    stack.print(std::cout);

    stack.push((int)(u(e)));
    stack.push((int)(u(e)));
    stack.push((int)(u(e)));

    stack.print(std::cout);

    int temp = stack.pop();
    std::cout << "pop() -> " << temp << std::endl;

    stack.print(std::cout);

    Stack<int> stack1(stack);

    stack1.print(std::cout);
    stack1.push((int)(u(e)));
    stack1.print(std::cout);
    stack.print(std::cout);

}