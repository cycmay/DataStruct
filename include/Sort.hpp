/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/9/2020, 11:22:05 AM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/9/2020, 11:22:09 AM 
 * Description: 
 * 多种排序算法
*/ 

#include "Vector.h"


/* 
 * @Description: swap 交换俩个元素内容
 * @param: 
 * @param: 
 * @return: 
*/ template <typename Comparable>
void swap(Comparable &a, Comparable &b){
    Comparable temp = a;
    a = b;
    b = temp;
}

// 插入排序
template <typename Comparable>
void insertionSort(Vector<Comparable> &a){
    int j;
    for(int p = 1; p < a.size(); ++p){
        Comparable temp = a[p];
        for(j = p; j>0 && temp<a[j-1]; --j){
            // 从p位置向前遍历，移动前一项元素到后一项，直到遍历到迭代器指向的位置前一项不
            // 再大于原p位置的元素值，即找到了p位置元素的合适位置
            a[j] = a[j-1];
        }
        // 将p位置的元素放到适合位置j
        a[j] = temp;
    }
}

/* 
 * @Description: // 插入排序 参数包含左右界
 * 插入排序基于p位置前个元素的序列已经是排序好的，p位置的元素插入到合适位置，使用从后到前交换法
 * @param: 
 * @param: 
 * @param: 
 * @return: 
*/ template <typename Comparable>
void insertionSort(Vector<Comparable> &a, int left, int right){
    int j = 0;
    for(int p = left + 1; p <= right; ++p){
        Comparable temp = a[p];
        for(j = p; j > left&&temp < a[j-1]; --j){
            a[j] = a[j-1];
        }
        a[j] = temp;
    }
}



// 希尔排序
template <typename Comparable>
void shellSort(Vector<Comparable> &a){
    for(int gap = a.size() / 2; gap>0; gap /=2){
        // 希尔增量序列 gap 
        for(int i = gap; i < a.size(); ++i){
            // 分组 对每一组进行插入排序
            Comparable temp = a[i];
            int j = i;
            for(; j >= gap && temp < a[j-gap]; j -= gap)
                a[j] = a[j-gap];
            a[j] = temp;
        }
    }
}

/* 
 * Author:      cKrazy 
 * CreateTime:  4/8/2020, 4:06:28 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/8/2020, 4:06:34 PM 
 * Description: 
 * 堆排序算法
 * 较大的元素放置在堆的顶部，对于左右子树同理
*/ 

template <typename Comparable>
void heapSort(Vector<Comparable> & a){
    // build heap
    // 最后一个非叶结点在n/2处，从此位置开始 依次向前下滤
    for(int i = a.size()/2; i>=0; --i)
        percolateDown(a, i, a.size());
    // sort // delet max
    for(int j = a.size()-1; j>0 ; --j){
        // swap 0,j
        Comparable temp = a[0];
        a[0] = a[j];
        a[j] = temp;
        // 将顶部的元素下滤
        percolateDown(a, 0, j);
    }
        
}


/* 
 * @Description: 二叉堆中的下滤策略 
 * @param a: 容器Vector
 * @param i: 下滤的元素位置 从0开始
 * @param n: 结点个数 
 * @return: 
*/ 
template <typename Comparable>
void percolateDown(Vector<Comparable> & a, int i, int n){
    int child; // 子结点
    Comparable temp;
    // 在源Vector中元素索引下标从0位置开始 i位置元素的孩子结点位置为2*i+1
    for(temp = a[i]; 2*i+1 < n; i = child){
        child = i * 2 + 1;
        // 找到两个子结点中较大的一个
        // 必须要判断是否还存在邻结点
        if(child != n-1 && a[child] < a[child+1])
            child++;
        //  将较小的元素向下滤
        if(temp < a[child])
            a[i] = a[child];
        else 
            break;
    }
    a[i] = temp;
}

/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/8/2020, 11:40:42 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/8/2020, 11:40:44 PM 
 * Description: 归并排序算法
*/ 

template <typename Comparable>
void mergeSort(Vector<Comparable> &a){
    Vector<Comparable> tempArray(a.size());
    mergeSort(a, tempArray, 0, a.size()-1);
}

template <typename Comparable>
void mergeSort(Vector<Comparable> &a,
                Vector<Comparable> & tempArray, int left, int right){
    if(left < right){
        int center = (left + right) /2;
        mergeSort(a, tempArray, left, center);
        mergeSort(a, tempArray, center+1, right);
        merge(a, tempArray, left, center+1, right);
    }
}

/* 
 * @Description: 将一个前后两半部分已排好序的数组合并为一个完整排好序的数组
 * @param a: 源数组
 * @param tempArray: place the merge result. 
 * @param leftpos: left-most index of the subarray. 
 * @param rightpos: the start of the second half.
 * @param rightend: the right-most index of the subarray. 
 * @return: 
*/ 
template <typename Comparable>
void merge(Vector<Comparable> & a, Vector<Comparable> & tempArray, int leftpos,
            int rightpos, int rightend){
    int leftend = rightpos - 1;
    int temppos = leftpos;
    int numElements = rightend - leftpos + 1;

    // main loop
    while(leftpos <= leftend && rightpos <= rightend){
        if(a[leftpos] <= a[rightpos])
            tempArray[temppos++] = a[leftpos++];
        else
            tempArray[temppos++] = a[rightpos++];
    }

    // 将剩余序列全部复制到结果中
    while(leftpos <= leftend){
        tempArray[temppos++] = a[leftpos++];
    }
    while(rightpos <= rightend){
        tempArray[temppos++] = a[rightpos++];
    }

    // copy tempArray back to a
    for(int i = 0; i < numElements; ++i, rightend--)
        a[rightend] = tempArray[rightend];
}

// 快速排序
/* 
 * @Description: 
 * @param a: 原数组
 * @param left:  
 * @param right: 
 * @return: median of left, center, right
 * order these and hide the pivot
*/ 
template <typename Comparable>
const Comparable & median3(Vector<Comparable> & a, int left, int right){
    // 三个数调整顺序 left，right，center
    int center = (left + right)/2;
    if(a[center] < a[left])
        swap(a[center], a[left]);
    if(a[right] < a[left])
        swap(a[right], a[left]);
    if(a[right] < a[center])
        swap(a[right], a[center]);
    
    // place pivot at position right-1
    swap(a[center], a[right-1]);
    return a[right-1];
}

/* 
 * @Description: 
 * Internal quicksort method that makes recursive calls.
 * Uses median-of-three partioning and a cutoff of 10.
 * @param a: is an array of Comparable items. 
 * @param left: is the left-most index of the subarray 
 * @param right: is the right-most index of the subarray 
 * @return: 
*/ template <typename Comparable>
void quickSort(Vector<Comparable> &a, int left, int right){
    // 寻找枢纽元至少需要存在3个元素，所以小数组使用插入排序完成
    if(left + 10 <= right){
        // 根据左右界找到枢纽元素
        Comparable pivot = median3(a, left, right);

        // begin partitioning
        // // 枢纽元素被交换到倒数第二个位置
        // int i = left+1, j = right-2;
        // for(; ;){
        //     // 此时的left绝对小于等于pivot
        //     // 左边i右边j，分别指向小于和大于pivot元素的值，非条件触发后交换之
        //     while(a[i] < pivot){ ++i;}
        //     while(pivot < a[j]){ --j;}
        //     if(i<j)
        //         swap(a[i], a[j]);
        //     else
        //         break;
        // }

        int i = left, j = right-1;
        for(; ;){
            // 此时的left绝对小于等于pivot
            // 左边i右边j，分别指向小于和大于pivot元素的值，非条件触发后交换之
            while(a[++i] < pivot){}
            while(pivot < a[--j]){}
            if(i<j)
                swap(a[i], a[j]);
            else
                break;
        }


        // i指向的元素必然大于pivot 交换之
        swap(a[i], a[right-1]);

        // 递归执行左右子序列
        quickSort(a, left, i-1);
        quickSort(a, i+1, right);
    }
    else{
        // Do an insertion sort on the subarray
        insertionSort(a, left, right);
    }
}

template <typename Comparable>
void quickSort(Vector<Comparable> &a){
    quickSort(a, 0, a.size()-1);
}