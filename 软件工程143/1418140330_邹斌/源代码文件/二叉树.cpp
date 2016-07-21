#include <iostream>
#include <stack>
#include <queue>
#include <cstdio>
#include <cstring>
#include <malloc.h>
using namespace std;

//二叉树结点
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//先序创建二叉树
int createBiTree(BiTree &T){
    char data;
    scanf("%c",&data);
    if(data=='#'){
        T=NULL;
    }
    else{
        T = (BiTree)malloc(sizeof(BiTNode));
        T->data = data;
        createBiTree(T->lchild);
        createBiTree(T->rchild);
    }
    return 0;
}

void prin(BiTree T){
    if(T->data != '#'){
        printf("%c ",T->data);
    }
}

void PreOrder(BiTree T){
    if(T != NULL){
        prin(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T){
    if(T != NULL){
        InOrder(T->lchild);
        prin(T);
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T){
    if(T != NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        prin(T);
    }
}

void PreOrder2(BiTree T){
    stack<BiTree> sta;
    BiTree p=T;
    while(p || !sta.empty()){
        if(p != NULL){
            sta.push(p);
            printf("%c ",p->data);
            p = p->lchild;
        }
        else{
            p = sta.top();
            sta.pop();
            p = p->rchild;
        }
    }
}

void InOrder2(BiTree T){
    stack<BiTree> sta;
    BiTree p = T;
    while(p || !sta.empty()){
        if(p != NULL){
            sta.push(p);
            p=p->lchild;
        }
        else{
            p=sta.top();
            printf("%c ",p->data);
            sta.pop();
            p=p->rchild;
        }
    }
}

typedef struct BiNodePost{
    BiTree biTree;
    char tag;
}BiNodePost,*BiTreePost;

void PostOrder2(BiTree T){
    stack<BiTreePost> sta;
    BiTree p = T;
    BiTreePost Bt;
    while(p != NULL || !sta.empty()){
        while(p != NULL){
            Bt = (BiTreePost)malloc(sizeof(BiNodePost));
            Bt->biTree=p;
            Bt->tag='L';
            sta.push(Bt);
            p=p->lchild;
        }
        //左右子树访问完毕访问根节点
        while(!sta.empty()&&(sta.top())->tag=='R'){
            Bt = sta.top();
            sta.pop();
            printf("%c ",Bt->biTree->data);
        }
        //遍历右子树
        if(!sta.empty()){
            Bt = sta.top();
            Bt->tag='R';
            p = Bt->biTree;
            p = p->rchild;
        }
    }
}

//层次遍历
void levelOrder(BiTree T){
    BiTree p = T;
    queue<BiTree> que;
    que.push(p);
    while(!que.empty()){
        p=que.front();
        printf("%c ",p->data);
        que.pop();
        if(p->lchild != NULL){
            que.push(p->lchild);
        }
        if(p->rchild != NULL){
            que.push(p->rchild);
        }
    }
}

int main(){
    printf("请输入序列(按照前序序列输入): \n");
    BiTree T=NULL;
    createBiTree(T);
    printf("先序遍历: \n");
    PreOrder(T);
    printf("\n");
    printf("先序遍历(非递归): \n");
    PreOrder2(T);
    printf("\n");
    printf("中序遍历: \n");
    InOrder(T);
    printf("\n");
    printf("中序遍历(非递归): \n");
    InOrder2(T);
    printf("\n");
    printf("后序遍历: \n");
    PostOrder(T);
    printf("\n");
    printf("后序遍历(非递归): \n");
    PostOrder(T);
    printf("\n");
    printf("层次遍历二叉树(队列): \n");
    levelOrder(T);
    return 0;
}

