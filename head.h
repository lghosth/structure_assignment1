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

int Search_AVL(AVL_tree T,int data,AVL_tree f, AVL_tree *p);//查找节点，如果 T 指针为空，说明查找失败，令 p 指针指向查找过程中最后一个叶子结点，并返回查找失败的信息
int Insert_node_S(AVL_tree *T , int data);//依据搜索插入
AVL_tree Insert_node(AVL_tree T, int data);//按照二叉查找树插入值
void In_orderTraversal(AVL_tree T);//中序遍历输出
void Pre_orderTraversal(AVL_tree T);//先序遍历输出
void Post_orderTraversal(AVL_tree T);//后序遍历输出
void In_orderVisitBF(AVL_tree T);//中序遍历输出每个节点的平衡值
int GetHeight(AVL_tree T);//得到树高
int GetBF(AVL_tree T);//得到该节点的平衡因子
void DeleteTree(AVL_tree T);//删除树，释放空间

//查找节点，如果 T 指针为空，说明查找失败，令 p 指针指向查找过程中最后一个叶子结点，并返回查找失败的信息
int Search_AVL(AVL_tree T,int data,AVL_tree f, AVL_tree *p){
    if (!T){
        *p = f;
        return 0;
    }else if (data == T->data){
        *p = T;
        return 1;
    }else if (data < T->data){
        return Search_AVL(T->lchild,data,T,p);
    } else{
        return Search_AVL(T->rchild,data,T,p);
    }
}

//依据搜索插入
int Insert_node_S(AVL_tree *T , int data){
    AVL_tree p = NULL;
    if (!Search_AVL((*T),data,NULL,&p)){
        AVL_tree s = (AVL_tree)malloc(sizeof(AVL_node));
        s->data = data;
        s->lchild = s->rchild = NULL;
        if (!p){
            *T  = s;
        }
        else if (data < p->data){
            p->lchild = s;
        } else{
            p->rchild = s;
        }
        return 1;
    }
    return 0;
}




//按照二叉查找树插入值
AVL_tree Insert_node(AVL_tree T, int data){
    if(!T){//如果原树为空，生成并返回一个节点的二叉树
        T = (AVL_tree)malloc(sizeof(AVL_node));//申请空间并初始化
        T->data = data;
        T->lchild = T->rchild = NULL;
        T->bf = 0;
        T->Height = 1;//约定根节点默认树高为1

    } else {

        if(data < T->data){
            T->lchild=Insert_node(T->lchild,data);//递归插入左子树
        } else if(data > T->data){
            T->rchild=Insert_node(T->rchild,data);//递归插入右子树
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
        ;
    } else{
        In_orderVisitBF( T->lchild );
        printf("%d ",GetBF(T));
        In_orderVisitBF( T->rchild );
    }
}


//得到该节点的平衡因子
int GetBF(AVL_tree T){
    int a = GetHeight(T->lchild) - GetHeight(T->rchild);
    a = abs(a);
    T->bf = a;
    return a;
}

//删除树，释放空间

void DeleteTree(AVL_tree T){
    if(!T){
        return ;
    } else {
        DeleteTree(T->lchild);
        DeleteTree(T->rchild);
        free(T);
    }
    return ;
}



#endif //STRUCTURE_ASSIGNMENT1_HEAD_H
