#include <iostream>

#include "queue_test.h"
#include "tree_test.h"


int main(){
//    List<int> myList;
//

//    myList.push_back(2);
//    myList.push_front(4);
//
//    List<int> List2(myList);
//    List<int>::iterator it = List2.begin();
//    std::cout<< *(it++) << std::endl;
//    std::cout<< *(it--) << std::endl;
//    std::cout<< *it << std::endl;
//    int a[10];
//    memset(a, 0, sizeof(a));
//    int a_len = sizeof(a)/sizeof(int);
//    for(int i=0;i<a_len;i++)
//    {
//        std::cout<<a[i]<<" ";
//    }
//    std::cout<<std::endl;
//    generateRandomArray(a_len, 0, 100, a);
//    for(int i=0;i<a_len;i++)
//    {
//        std::cout<<a[i]<<" ";
//    }
//    std::cout<<std::endl;
    queue_test();
    tree_test();
    return 0;
}



