/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/16/2020, 9:28:17 AM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/16/2020, 9:28:18 AM 
 * Description: 
 * 销售月饼 获取最大销售额
*/ 

#include <cstdio>
#include <vector>
#include <algorithm>

typedef struct mooncake
{
    double store; // 库存量
    double price; // 总售价
    double per_price; // 单价
    mooncake(): store(-1.0), price(-1.0), per_price(-1.0){}
} mooncake;

// 按照降序排列
bool cmp(mooncake &a, mooncake &b){
    if(a.per_price>b.per_price) return true;
    else
    {
        return false;
    }
    
}

int main(){
    unsigned int N;
    double D, prefit = 0.0;
    while(scanf("%d %lf", &N, &D) != EOF){
        std::vector<mooncake> moonTypes;
        for (size_t i = 0; i < N; i++)
        {
            mooncake temp;
            scanf("%lf", &temp.store);
            moonTypes.push_back(temp);
        }
        for (size_t i = 0; i < N; i++)
        {
            scanf("%lf", &moonTypes[i].price);
            moonTypes[i].per_price = moonTypes[i].price/moonTypes[i].store;
        }
        // 排序mooncake类型 
        // 降序排列 比较cmp函数将a>b返回真
        std::sort(moonTypes.begin(), moonTypes.end(), cmp);

        for (size_t i = 0; i < N && D > 0.0; i++)
        {
            if(D > moonTypes[i].store){
                // 单个月饼种类不足
                D -= moonTypes[i].store;
                prefit += moonTypes[i].price;
            }
            else
            {
                // 单个月饼种类能满足市场
                prefit += D*moonTypes[i].per_price;
                D = 0.0;
            }
        }
        printf("%.2lf\n", prefit);
        
    }
    
    
    return 0;
}

