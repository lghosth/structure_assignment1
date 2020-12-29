#include <stdio.h>
#include "head.h"

int main() {
    AVL_tree T= NULL;
    int a[10]={1,3,2,8,5,4,11,45,23,22};//测试数据
    for (int i=0;i<10;i++){
        T = Insert_node(T,a[i]);
    }
    printf("\n中序遍历输出：\n");
    In_orderTraversal(T);
    printf("\n中序遍历输出每个节点的平衡因子:\n");
    In_orderVisitBF(T);
    return 0;
}
