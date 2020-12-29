//
// Created by charol on 2020/12/29.
//

#ifndef STRUCTURE_ASSIGNMENT1_HEAD_H
#define STRUCTURE_ASSIGNMENT1_HEAD_H
#include <stdio.h>
#include <stdlib.h>
#define LH +1
#define EH 0
#define RH -1
typedef enum {false=0,true} bool ;
typedef struct AVL_node{
    int data;
    int bf;// 平衡因子,并不实时更新
    int Height;//树高
    struct AVL_node *lchild,*rchild;//左孩子，右孩子
}*AVL_tree,AVL_node;

int Max( int a, int b ){//输出最大值
    return a > b ? a : b ;
}

AVL_tree Insert_node(AVL_tree T, int data);//按照二叉查找树插入值
void In_orderTraversal(AVL_tree T);//中序遍历输出
void Pre_orderTraversal(AVL_tree T);//先序遍历输出
void Post_orderTraversal(AVL_tree T);//后序遍历输出
void In_orderVisitBF(AVL_tree T);//中序遍历输出每个节点的平衡值
int GetHeight(AVL_tree T);//得到树高
int GetBF(AVL_tree T);//得到该节点的平衡因子

//按照二叉查找树插入值
AVL_tree Insert_node(AVL_tree T, int data){
    if(!T){//如果原树为空，生成并返回一个节点的二叉树
        T = (AVL_tree)malloc(sizeof(AVL_tree));//申请空间并初始化
        T->data = data;
        T->lchild = T->rchild = NULL;
        T->bf = 0;
        T->Height = 1;//约定根节点默认树高为1
    } else{
        if(data < T->data){
            T->lchild = Insert_node(T->lchild,data);//递归插入左子树
        } else(data > T->data){
            T->rchild = Insert_node(T->rchild,data);//递归插入右子树
        }
    }
    return T;
}

//中序遍历输出
void In_orderTraversal(AVL_tree T){
    if( T ){
        In_orderTraversal( T->lchild );
        printf("%d ",T->data);
        In_orderTraversal( T->rchild );
    }
}

//得到树高
int GetHeight(AVL_tree T){
    if (!T){
        return 0;
    } else{
        int lHeight = GetHeight(T->lchild);
        int rHeight = GetHeight(T->rchild);
        return Max(lHeight,rHeight)+1;
    }
}

//中序遍历输出每个节点的平衡值
void In_orderVisitBF(AVL_tree T){
    if(!T){
        printf("！所给树节点为空！");
    } else{
        In_orderTraversal( T->lchild );
        printf("%d ",GetBF(T));
        In_orderTraversal( T->rchild );
    }
}


//得到该节点的平衡因子
int GetBF(AVL_tree T){
    int a = GetHeight(T->lchild) - GetHeight(T->rchild);
    a = abs(a);
    T->bf = a;
    return a;
}


#endif //STRUCTURE_ASSIGNMENT1_HEAD_H
