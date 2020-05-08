/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/15/2020, 5:25:12 PM 
 * LastEditor:  cKrazy
 * ModifyTime:  4/15/2020, 9:01:08 PM
 * Description: 
*/ 

#include <iostream>
#include <cstdio>
#include <cmath>

const int maxn = 11;
// 标记x是否被使用过 
bool hashTable[maxn] = {false};
// 存储当前排列的数组
int n;
int P[maxn] = {0};
int count = 0;

void printP(int P[]){
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", P[i]);
    }
    printf("\n");
}

void generateP(int index){
    if(index > n){
        bool flag = false;
        // 判断每两个皇后是否违背对角线原理
        for (size_t i = 1; i <= n; i++)
        {
            for (size_t j = i+1 ; j <= n; j++)
            {
                if(abs((int)(i-j)) == abs((int)(P[i]-P[j]))){
                    // 存在对角线上的两个元素
                    flag = true;
                    break;
                }
            }
            if(flag)
                break;
        }
        if(!flag){
            count++;
        }
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

// 优化后的解法
// 回溯
void generatePOp(int index){
    if(index > n){
        return;
    }
        
    int x;
    // 找到未被标记的某个x
    for (x = 1; x<= n; x++)
    {
        if(!(hashTable[x])){
            // 将x放入P数组index位置，并标记 
            P[index] = x;
            hashTable[x] = true;
            // 判断是否存在两个元素对角线冲突
            bool flag = false;
            for(size_t i = 1; i < index; ++i){
                if(abs((int)(i-x)) == abs((int)(P[i]-P[index]))){
                    flag = true;
                    break;
                }
            }
            if (flag)
            {
                // 处理完后标记x未使用，使用下一个x
                hashTable[x] = false;
                continue;
            }
            
            // 处理下一个位置index+1
            generateP(index+1);
            // 处理完后标记x未使用，使用下一个x
            hashTable[x] = false;
        }
    }
    
}

int main(){
    n = 8;
    generatePOp(1);
    printf("%d\n", count);
    return 0;
}