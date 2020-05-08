//
//  Tree.h
//  DataStruct
//
//  Created by Mr.Bicycle on 2020/3/29.
//

#ifndef Tree_h
#define Tree_h

#include <cstdlib>
#include <iostream>

#include "Queue.h"

template <typename Comparable>
class BinarySearchTree {
private:
    struct BinaryNode{
        Comparable element;
        BinaryNode *left;
        BinaryNode *right;
        
        BinaryNode(const Comparable & theElement, BinaryNode *lf,
                   BinaryNode *rt):element(theElement), left(lf), right(rt){}
    };
    BinaryNode *root;
    
    void insert(const Comparable & x, BinaryNode * & t) const;
    void remove(const Comparable & x, BinaryNode * & t) const;
    BinaryNode * findMin(BinaryNode * t) const;
    BinaryNode * findMax(BinaryNode * t) const;
    bool contains(const Comparable & x, BinaryNode * t) const;
    void makeEmpty(BinaryNode * & t);
    void printTree(BinaryNode * t) const;
    BinaryNode * clone(BinaryNode * t) const;
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    
    const Comparable & findMin() const;
    const Comparable & findMax() const;
    bool contains(const Comparable & x) const;
    bool isEmpty() const;
    void printTree() const;
    
    void makeEmpty();
    void insert(const Comparable & x);
    void remove(const Comparable & x);
    
    const BinarySearchTree & operator=(const BinarySearchTree & rhs);
    
    
};

//类内部接口 contains< x, t>
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable & x, BinaryNode *t) const{
    //    判断树中是否含有元素值为x的节点
    if(t == nullptr){
        return false;
    }
    else if(x < t->element){
        //      若树的根节点t的元素值大于x，则去左子树递归查询是否contains
        return contains(x, t->left);
        
    }
    else if(x > t->element){
        //      若树的根节点t的元素值小于x，则去右子树递归查询是否contains
        return contains(x, t->right);
    }
    else
        //        若相等，则返回true
        return true;
}

// 公共接口 contains
template <typename Comparable>
bool BinarySearchTree<Comparable>::contains(const Comparable &x) const{
    //   从根节点root处调用contains函数
    return contains(x, root);
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *
BinarySearchTree<Comparable>::findMin(BinaryNode * t) const{
    if(t == nullptr)
        return nullptr;
    if(t->left == nullptr)
        return t;
    return findMin(t->left);
    
    ////        或者使用循环的方式
    //#if 0
    //        if(t != nullptr)
    //            while(t->left!=nullptr)
    //                t = t->left;
    //        return t;
    //#endif
    
}

template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *
BinarySearchTree<Comparable>::findMax(BinaryNode * t) const {
    if(t == nullptr)
        return nullptr;
    if(t->right == nullptr)
        return t;
    return findMax(t->right);
}

template <typename Comparable>
BinarySearchTree<Comparable>::BinarySearchTree(){
    root = nullptr;
}

template <typename Comparable>
BinarySearchTree<Comparable>::~BinarySearchTree(){
    delete root;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x,
                                            BinaryNode * & t) const{
    if(t == nullptr)
        t = new BinaryNode(x, nullptr, nullptr);
        t->left = t->right = nullptr;
    else if(x < t->element)
        insert(x, t->left);
    else if(x > t->element)
        insert(x, t->right);
    else
        return;
}

template <typename Comparable>
void BinarySearchTree<Comparable>::insert(const Comparable & x){
    insert(x, root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::remove(const Comparable & x,
                                          BinaryNode * & t) const{
    if(t == nullptr)
        return;
//    find the Node
    if(x < t->element)
        remove(t->left);
    if(x > t->element)
        remove(t->right);
    if(t->left == nullptr && t->right == nullptr){
//        没有孩子结点
        delete t;
        t = nullptr;
    }
    if(t->left != nullptr || t->right != nullptr){
//        有一个孩子结点 直接令指针修改 并释放原来的指针指向的内存空间
        BinaryNode * oldNode = t;
        t = (t->left != nullptr) ? t->left : t->right;
        delete oldNode;
    }
    if(t->left != nullptr && t->right != nullptr){
//        有两个孩子结点
//        找到右子树最小元素结点
//        这里存在缺点，寻找最小子结点和删除操作可以放在一起进行。
        BinaryNode * min = findMin(t->right);
//        交换min与当前结点
        t->element = min->element;
//        递归调用 删除min结点 min结点必然不包含左子树
        remove(min->element, t->right);
    }
}

template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(BinaryNode * & t){
    if(t == nullptr)
        return;
    else{
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
//    将t置空
    t = nullptr;
}
//公共接口
template <typename Comparable>
void BinarySearchTree<Comparable>::makeEmpty(){
    makeEmpty(root);
}

//deep copy
template <typename Comparable>
const BinarySearchTree<Comparable> & BinarySearchTree<Comparable>::operator=
    (const BinarySearchTree & rhs){
//    删除原来的树
        makeEmpty();
        root = clone(rhs);
        return *this;
}

// clone a subtree
template <typename Comparable>
typename BinarySearchTree<Comparable>::BinaryNode *
BinarySearchTree<Comparable>::clone(BinaryNode * t) const{
    if(t == nullptr)
        return nullptr;
    BinaryNode * temp = new BinaryNode;
    temp->element = t->element;
    temp->left = clone(t->left);
    temp->right = clone(t->right);
    return temp;
}

//print the tree
template <typename Comparable>
void BinarySearchTree<Comparable>::printTree() const{
    printTree(root);
}

template <typename Comparable>
void BinarySearchTree<Comparable>::printTree(BinaryNode *t) const{
    if(t == nullptr)
        return;
    Queue<BinaryNode *> queue;
    BinaryNode * node = t;
    queue.enqueue(node);
    int nextLevels = 0; // 下一层的结点数
    int currentLevels = 1; // 当前层剩余print的结点数
    while (!queue.empty())
    {
        // 层序遍历 直到队列为空
        // 取队列的队首元素
        // 将队首元素的左右孩子结点放入队尾 重复本程序体
        node = queue.front();
        if(node->left != nullptr){
            queue.enqueue(node->left);
            ++nextLevels;
        }
        if(node->right != nullptr){
            queue.enqueue(node->right);
            ++nextLevels;
        }
        // 打印当前结点信息
        std::cout << node->element << " ";
        // 抛弃当前结点
        queue.dequeue();
        --currentLevels;
        if(0 == currentLevels){
            // 已经打印完 设置层信息
            currentLevels = nextLevels;
            nextLevels = 0;
            // 打印行符号
            std::cout<<std::endl;
        }
    }

    
}


#endif /* Tree_h */
