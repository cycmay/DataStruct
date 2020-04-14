/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/14/2020, 9:50:55 PM 
 * LastEditor:  cKrazy 
 * ModifyTime:  4/14/2020, 9:50:58 PM 
 * Description: 
*/ 

#include <cstdio>
#include <algorithm>

const int studentIDMaxLen = 15;
struct student{
    char id[studentIDMaxLen];
    int final_rank; // 总成绩排名
    int local_num; // 考场号
    int local_rank; // 考场排名
    int score;
    student():id{0}, final_rank(-1), local_num(-1), local_rank(-1), score(-1){}
};

bool cmp(student a, student b){
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
    student * students_set[300*100+100];
    while(scanf("%d", &N) != EOF){
        for(size_t i=0; i<N; ++i){
            scanf("%d", &K);
            for (size_t j = 0; j < K; ++j)
            {
                student * temp = new student;
                scanf("%s %d", &(temp->id), &(temp->score));
                students_set[num++] = temp;
                temp->local_num = i+1; // 考场号
            }
            // 对新增的数据排序 左闭右开
            std::sort(students_set+num-K, students_set+num, cmp);
            for (size_t j = 0; j < K; ++j)
            {
                if((j>0) && (students_set[j]->score == students_set[j-1]->score))
                    students_set[j]->local_rank = students_set[j-1]->local_rank;
                else
                    students_set[j]->local_rank = j+1;
            }
        }
        std::sort(students_set, students_set+num, cmp);
        for (size_t j = 0; j < num; j++)
        {
            if((j>0) && (students_set[j]->score == students_set[j-1]->score))
                    students_set[j]->local_rank = students_set[j-1]->local_rank;
                else
                    students_set[j]->local_rank = j+1;
            printf("%s %d %d %d\n", students_set[j]->id, 
                students_set[j]->final_rank, students_set[j]->local_num,
                students_set[j]->local_rank);
    
        }
        
    }
    return 0;
}