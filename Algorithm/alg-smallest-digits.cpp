/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/16/2020, 2:33:01 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/16/2020, 2:33:02 PM 
 * Description: 
 * 组最小数
*/ 

#include <cstdio>

const int maxn = 10;
unsigned int digitNums[maxn] = {0};



int main(){
    char rhs[9*10] = {0};
    unsigned int len = 0;
    for (size_t i = 0; i < maxn; i++)
    {
        scanf("%d", &digitNums[i]);
    }
    // 首位不能为0 找出最小的能做首位的数 并自减1
    for (size_t i = 1; i < maxn; i++)
    {
        if(digitNums[i] != 0){
            rhs[len++] = i + '0';
            digitNums[i]--;
            break;
        }
        if(i+1 == maxn)
            return 0;
    }
    
    for (size_t i = 0; i < maxn; i++)
    {
        
        while(digitNums[i] != 0){
            digitNums[i]--;
            rhs[len++] = i + '0';
        }
    }
    rhs[len] = '\0';

    printf("%s\n", rhs);
    return 0;
}
