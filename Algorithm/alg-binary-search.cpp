/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/23/2020, 8:30:43 AM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/23/2020, 8:30:46 AM 
 * Description: 
*/ 

#include <iostream>
#include <algorithm>
#include <cmath>

// 返回数组中第一个大于等于x的元素 A为递增序列
int lower_bound(int A[], int left, int right, int x){
    int mid;
    while(left < right){
        // 防止int溢出
        mid = right + (left-right)/2;
        if(A[mid] >= x){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    return left;
}

// 返回数组中第一个大于x的元素
int upper_bound(int A[], int left, int right, int x){
    int mid;
    while(left<right){
        mid = right + (left-right)/2;
        if(A[mid] > x){
            right = mid;
        }else{
            left = mid + 1;
        }
    }
    // 跳出循环的条件为left == right
    return left;
}

// 利用二分法求根号2
const double eps = 1e-5;
double f(double x){
    return x*x;
}

double calsSqrt(double x){
    // 假设x>1
    double left = 1;
    double right = x;
    double mid = 0.0;
    while((right-left)>eps){
        std::cout<<mid<<std::endl;
        mid = right + (left-right)/2.0;

        if(f(mid)>x){
            right = mid;
        }else{
            left = mid;
        }
    }
    return left;
}

// 水桶装水面积比的问题
const double PI = acos(-1.0);
// 输入R,r 求h
double function2(double R, double h){
    // 结果r关于h递增的
    double alpha = 2 * acos((R-h)/R);
    double r = 2 * alpha * cos((R-h)/R) / PI;
    return r;
}

double solution(double R, double r){
    double left, right, mid;
    left = 0; right = R;
    while (std::abs(left - right) > eps)
    {
        mid = right + (left - right)/2.0;
        if(function2(R, mid) > r){
            // 所求的比例大于题目给定比例 h应在更左侧区间
            right = mid;
        }else{
            left = mid;
        }
    }
    return left;
}

// 使用递归法 求解快速幂
long long binaryPower(long long a, long long b, long long m){
    if(b == 0){
        return 1;
    }
    if(b%2==0){
        // b为偶数
        long long binaryPower_ans = 1;
        binaryPower_ans = binaryPower(a, b/2, m); 
        return binaryPower_ans * binaryPower_ans % m;
    }
    else{
        return a * binaryPower(a, b-1, m) %m;
    }

}
// 使用迭代法
long long binaryPower1(long long a, long long b, long long m){
    long long ans = 1;
    a = a%m;
    while(b!=0){
        if(b&1){
            // b末尾有效
            ans = ans*a%m;
        }
        // a迭代 自增一倍
        a = a*a%m;
        // b二进制向右移动一位
        b = b>>1;
    }
    return ans;
}

int main(){
    std::cout<<binaryPower1(1e5, 1e13, 12345);
    return 0;
}