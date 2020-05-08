/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/19/2020, 2:39:25 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/19/2020, 2:40:03 PM 
 * Description: 
 * 动态规划问题
*/ 

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <algorithm>

// 找零问题
int main_cost(){

    int F[105], i, n, cost;
    scanf("%d", &n);

    F[0] = 0;

    for(int i = 1; i <= n; ++i){
        cost = INT_MAX;
        // 计算选择各种钞票的cost
        // 后选择其中最小的cost 
        // 这里保存每一中选择的cost，并在后面的选择中继续比较
        if(i-1>=0)
            cost = std::min(F[i-1] + 1, cost);
        if(i-5>=0)
            cost = std::min(F[i-5] + 1, cost);
        if(i-11>=0)
            cost = std::min(F[i-11] + 1, cost);
        // 最终确定当前w的最优化选择
        F[i] = cost;
        printf("f[%d]=%d\n", i, F[i]);
}

    return 0;
}

// 最长递增子序列
int main_LIS(){
    int n, f[105]={0}, a[105]={0};
    scanf("%d", &n);
    for (size_t i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        f[i] = 1;
    }

    for (size_t x = 1; x <= n; x++)
    {
        for (size_t p = x; p > 0; p--)
        {
            if(a[x]>a[p])
                f[x] = std::max(f[p]+1, f[x]);
        }
        printf("f[%ld]=%d\n", x, f[x]);
    }
    int ans = 0;
    for (size_t i = 1; i <= n; i++)
    {
        ans = std::max(ans, f[i]);
    }

    printf("%d", ans);
    
    return 0;
}

#include <vector>
#include <iostream>
int main(){
    int N;
    scanf("%d", &N);
    int C;
    scanf("%d", &C);
    std::vector<int> weight(N+1), value(N+1);
    std::vector<std::vector<int> > f(N+1);
    for (size_t i = 0; i < N+1; i++)
    {
        f[i].assign(C+1, 0);
    }
    
    for (size_t i = 1; i <= N; i++)
    {
        scanf("%d",&value[i]);
    }
    for (size_t i = 1; i <= N; i++)
    {
        scanf("%d",&weight[i]);
    }
    // 遍历每件物品 将其放入背包
    for (size_t i = 1; i <= N; i++)
    {
        // 以往每个物品放入时最大价值
        for (int v = 1; v <= C; v++)
        {
            if(v < weight[i]){
                // 空间不足以放入i物品 则为之前物品放入背包的最大价值问题
                f[i][v] = f[i-1][v];
            }
            else{
                // 状态转移
                // 若不放入第i件物品
                int x = f[i-1][v];
                // 若放入第i件物品
                int y = f[i-1][v-weight[i]] + value[i];
                f[i][v] = std::max(x, y);
            }
        }
        
    }

    for (int i = 0; i <= N; i++){
        for (int j = 0; j <= C; j++){
            printf("%4d ", f[i][j]);
        }
        std::cout << std::endl;
    }

    // 最大价值的必然为f[N][C]
    printf("%d", f[N][C]);
    return 0;
    
}

