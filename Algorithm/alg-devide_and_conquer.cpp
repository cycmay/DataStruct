#include <iostream>
#include <vector>
// 二分算法 分治的思想
const int NOT_FOUND = -1;

template <typename Comparable>
int binarySearch(const std::vector<Comparable> &a, const Comparable x){
    int low = 0, high = int(a.size()-1);
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid]<x)
            low = mid + 1;
        else if(a[mid]>x)
            high = mid - 1;
        else
            return mid;
    }
    return NOT_FOUND;
}

int main(int argc, const char * argv[]) {
    int temp[] = {-5,-1,3,12,66,3454};
    
    std::vector<int> v(temp, temp+(sizeof(temp)/sizeof(temp[0])));
//    std::vector<int> v = {-5,-1,3,12,66,3454};
    std::cout<< binarySearch(v, 12) << std::endl;
}

