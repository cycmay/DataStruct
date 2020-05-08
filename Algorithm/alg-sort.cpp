/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/23/2020, 3:10:14 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/23/2020, 3:10:16 PM 
 * Description: 
 * 排序算法
*/ 
#include <iostream>
#include <algorithm>

// partition 将[left, right]左右两半部分用pivot分开
// pivot选取left
int partition(int A[], int left, int right){
    int pivot = A[left];
    while(left<right){
        // 交换左右两个部分 分别处于pivot大小侧
        // 先移动右侧部分
        while(A[right]>pivot&&left<right)
            right--;
        A[left] = A[right]; 

        while(A[left]<=pivot&&left<right)
            left++;
        A[right] = A[left]; 
    }
    // 最后结束时ij相遇
    A[left] = pivot;
    return left;
}

void quickSort(int A[], int left, int right){
    if(left < right){
        int pos = partition(A, left, right);
        quickSort(A, left, pos-1);
        quickSort(A, pos+1, right);
    }
}
int main(){
    int A[10] = {9, 12, 78, 121, 5,1,11,9, 2,44};
    quickSort(A, 0, 9);
    for (size_t i = 0; i < 9; i++)
    {
        std::cout<<A[i]<<" ";
    }
    
}