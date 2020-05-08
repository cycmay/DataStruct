/* File Info 
 * Author:      cKrazy 
 * CreateTime:  4/27/2020, 6:46:58 PM 
 * LastEditor:  cKrazy
 * ModifyTime:  4/27/2020, 7:38:52 PM
 * Description: 
*/ 
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <algorithm>

struct Node{
    int value;
    struct Node *next;
};

typedef struct Node Node;

bool delelteNode(Node **head, int target){
    if(*head==NULL){
        return false;
    }
    
    Node * p = (*head)->next;
    Node * pre = *head;
    if(pre->value == target){
        // 头结点就是要查找的点
        delete *head;
        return true;
    }
    while(p!=NULL){
        if(p->value == target){
            // 找到并删除
            pre->next = p->next;
            delete p;
            return true;
        }else{
            pre = p;
            p = p->next;
        }
    }
    return false;
}

struct Node{
    int value;
    struct Node *left;
    struct Node *right;
};

typedef struct Node Node;

int maxPath(Node *root){
    if(root == NULL)
        return 0;
    std::queue<Node *> q;
    int num = 0;
    // 层次遍历 寻找最低层
    q.push(root);
    while(!q.empty()){
        int len = q.size();
        for(int i = 0; i < len; ++i){
            Node * temp = q.front();
            q.pop();
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
        num++;
    }
    return num;
}

void sortAscending(int *A, int n){
    // 冒泡排序
    
    int flag;
    for(int i = n-1; i>=1; --i){
        flag = 0;
        for(int j = 1; j<=i; ++j){
            if(A[j-1]>A[j]){
                // 两两之间比较 按照小到大顺序
                std::swap(A[j-1], A[j]);
                flag = 1;
            }
        }
        // 一趟排序未发生交换 说明已经排好序
        if(flag == 0)
            return;
    }

}