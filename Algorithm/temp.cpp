
#include <iostream>

int num = 0;

void tiziFunc(int n){
    if(n == 0){
        num++;
        return;
    }
    if(n < 0){
        // n<0 说明这种方法不合适
        return;
    }
    tiziFunc(n-1);
    tiziFunc(n-2);
}

int main(){
    tiziFunc(3);
    std::cout<<num<<std::endl;
}