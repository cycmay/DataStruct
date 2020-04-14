/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/13/2020, 9:37:37 PM 
 * LastEditor:  cKrazy
 * ModifyTime:  4/14/2020, 10:57:26 AM
 * Description: 
*/ 

#include <cstdio>
#include <cmath>
#include <algorithm>

// 闰年 能被4整除，但不能被100整除；或者能被400整除
bool isLeapYear(const int year){
    return ((!(year%4)) && (year%100)) || !(year % 400);
}

// 交换值
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

int monthes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
// 计算month day 在今年过了几天了
int finDates(int year, int month, int day){
    int dates = 0;
    for(int i=0; i < month-1; ++i){
        dates += monthes[i];
        if(i==1 && isLeapYear(year)){
            dates +=1;
        }
    }
    // 不算今天
    dates += day-1;
    printf("%d ", dates);
    return dates;
}
// 计算 在今年还剩下多少天 加上本天
int haveDates(int year, int month, int day){
    int hdates = 0;
    int dates = finDates(year, month, day);
    hdates = isLeapYear(year)?(366-dates):(365-dates);
    printf("%d ", hdates);
    return hdates;
}

int main_date(){
    
    int data1, data2;
    while(scanf("%d %d", &data1, &data2) != EOF){
        // 最终结果
        int results = 0;

        if(data1 > data2)
            swap(data1, data2);
        int year1 = data1/10000, month1 = data1%10000/100, day1 = data1%100;
        int year2 = data2/10000, month2 = data2%10000/100, day2 = data2%100;

        if(year1 == year2){
            results = finDates(year2, month2, day2) - 
                        finDates(year1, month1, day1) + 1;
            printf("%d\n", results);
            continue;
        }
        // 增加data1至data2的年份-1, 不能等于，防止越过data2
        for(; year1 < year2-1; year1++){
            results += isLeapYear(year1)?366:365;
        }

        // data1数据在本年份还剩下多少天
        int dates1 = haveDates(year1, month1, day1);
        // data2数据在本年份已经过了多少天 data2得过完
        int dates2 = finDates(year2, month2, day2)+1;
        results = dates2 + dates1;
        printf("%d\n", results);

    }
    return 0;
}

