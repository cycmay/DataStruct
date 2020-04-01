//
//  tree_test.cpp
//  DataStruct
//
//  Created by Mr.Bicycle on 2020/3/31.
//

#include "Tree.h"
#include "utils.h"

#include "tree_test.h"

void tree_test(){
    srand((unsigned int)(time(NULL))); // 随机种子
//    创建一个树
    BinarySearchTree<int> tree;
    for(int i = 0; i < NUM_NODES_MAX; ++i){
        tree.insert(genRandomInt(0, ELE_MAX));
    }

    tree.printTree();
    log((char *)"printTree");
    
}
