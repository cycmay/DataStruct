/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/15/2020, 5:25:12 PM 
 * LastEditor:  cKrazy
 * ModifyTime:  4/15/2020, 6:00:15 PM
 * Description: 
*/ 

#include <iostream>
#include <cstdio>

const int maxn = 11;
// 标记x是否被使用过 
bool hashTable[maxn] = {false};
// 存储当前排列的数组
int n;
int P[maxn] = {0};

void printP(int P[]){
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", P[i]);
    }
    printf("\n");
}

void generateP(int index){
    if(index > n){
        // 输出P
        printP(P);
        return;
    }
        
    int x;
    // 找到未被标记的x
    for (x = 1; x<= n; x++)
    {
        if(!(hashTable[x])){
            // 将x放入P数组index位置，并标记 
            P[index] = x;
            hashTable[x] = true;
            // 处理下一个位置index+1
            generateP(index+1);
            // 处理完后标记x未使用，使用下一个x
            hashTable[x] = false;
        }
    }
    
}

int main(){
    n = 3;
    generateP(1);
    return 0;
}