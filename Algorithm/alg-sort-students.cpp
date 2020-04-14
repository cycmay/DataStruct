/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/14/2020, 9:50:55 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/14/2020, 9:50:58 PM 
 * Description: 
 * Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

Input Specification:
Each input file contains one test case. For each case, the first line contains a positive number N (≤100), the number of test locations. Then N ranklists follow, each starts with a line containing a positive integer K (≤300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. All the numbers in a line are separated by a space.

Output Specification:
For each test case, first print in one line the total number of testees. Then print the final ranklist in the following format:

registration_number final_rank location_number local_rank

      
    
The locations are numbered from 1 to N. The output must be sorted in nondecreasing order of the final ranks. The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85

      
    
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
 * 
*/ 

#include <cstdio>
#include <cstring>
#include <algorithm>

const int studentIDMaxLen = 15;
typedef struct student{
    char id[studentIDMaxLen];
    int final_rank; // 总成绩排名
    int local_num; // 考场号
    int local_rank; // 考场排名
    int score;
    student(): final_rank(-1), local_num(-1), local_rank(-1), score(-1){}
}student;

bool cmp(student &a, student &b){
    if(a.score != b.score) return a.score>b.score;
    // 分数相同比较id
    else
    {
        // id 按照从小到大排序
        // strcmp(a,b) 若a>b返回大于0的整数 a=b返回0 a<b返回小于0的整数
        return strcmp(a.id, b.id)<0;
    }
    
}

int main(){
    int N, K;
    int num = 0;
    student students_set[300*100+100];
    while(scanf("%d", &N) != EOF)
    {
        for(size_t i=0; i<N; ++i){
            scanf("%d", &K);
            for (size_t j = 0; j < K; ++j)
            {
                scanf("%s %d", students_set[num].id, &(students_set[num].score));
                students_set[num].local_num = i+1; // 考场号
                num++;
            }
            // 对新增的数据排序 左闭右开
            std::sort(students_set+num-K, students_set+num, cmp);
            for (size_t j = 0; j < K; ++j)
            {
                if((j>0) && (students_set[num-K+j].score == 
                                students_set[num-K+j-1].score))
                    students_set[num-K+j].local_rank = 
                                            students_set[num-K+j-1].local_rank;
                else
                    students_set[num-K+j].local_rank = j+1;
            }
        }
        std::sort(students_set, students_set+num, cmp);
        printf("%d\n", num);
        for (size_t j = 0; j < num; j++)
        {
            if((j>0) && (students_set[j].score == students_set[j-1].score))
                    students_set[j].final_rank = students_set[j-1].final_rank;
                else
                    students_set[j].final_rank = j+1;
            printf("%s %d %d %d\n", students_set[j].id, 
                students_set[j].final_rank, students_set[j].local_num,
                students_set[j].local_rank);
    
        }
        
    }
    
    return 0;
}