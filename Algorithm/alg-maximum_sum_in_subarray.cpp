/*
给定整数$A_1, A_2, … ，A_N$ (有可能存在负数)，求$\sum_{k=i}^{j}A_k$的最大值。(为了方便起见，如果所有整数均为负数，则最大子序列和为0.)

例如：对于输入`-2, 11, -4, 13, -5, -2` 答案为20(从$A_2$到$A_4$).
*/

/*
解法：

*/

// 求解最大子序列的和
#include <iostream>
#include <vector>

using namespace std;

int m_max3(int a, int b, int c);

int maxSumRec(const vector<int> &a, int left, int right)
{
	// base case
	if(left == right)
    {	// 题目指出子序列若全为负数则返回0
		if(a[left]>0)
            return a[left];
        else
            return 0;
    }
    int center = (left + right)/2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center+1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for(int i=center; i>=left; i--)
	{
		leftBorderSum += a[i];
		if(leftBorderSum>maxLeftBorderSum)
			maxLeftBorderSum = leftBorderSum;
	}	

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for(int i=center+1; i<=right; i++)
	{
		rightBorderSum += a[i];
		if(rightBorderSum>maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return m_max3(maxLeftSum, maxRightSum, maxLeftBorderSum+maxRightBorderSum);

}

int m_max3(int a, int b, int c)
{
	int max = a;

	if(b>max)
		max = b;
	if(c>max)
		max = c;

	return max;
}

int main()
{
	std::vector<int> v = { -2, 11, -4, 13, -5, -2};
	std::cout << maxSumRec(v, 0, 6) << std::endl;
	return 0;
}
