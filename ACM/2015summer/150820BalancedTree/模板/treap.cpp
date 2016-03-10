#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
struct Treap_Node
{
    Treap_Node *left,*right;
    int value,fix,weight,size;//节点的值，修正值，重复计数，子树大小
    inline int lsize(){return left?left->size:0;}//返回左子树的节点个数
    inline int rsize(){return right?right->size:0;};//饭后右子树的节点个数
};
void Treap_Left_Rotate(Treap_Node *&a)//左旋
{
    Treap_Node *b=a->right;
    a->right=b->left;
    b->left=a;
    a=b;
    b=a->left;
    b->size=b->lsize()+b->rsize()+b->weight;
    a->size=a->lsize()+a->rsize()+a->weight;
}
void Treap_Right_Rotate(Treap_Node *&a)
{
    Treap_Node *b=a->left;
    a->size=b->rsize()+a->rsize()+a->weight;
    b->size=b->lsize()+a->size+b->weight;
    a->left=b->right;
    b->right=a;
    a=b;
    b=a->left;
    b->size=b->lsize()+b->rsize()+b->weight;
    a->size=a->lsize()+a->rsize()+a->weight;
}
int Treap_Findkth(Treap_Node *P,int k)
{
    if (k < P->lsize() + 1)  //左子树中查找排名第k的元素
        return Treap_Findkth(P->left,k);
    else if (k > P->lsize() + P->weight) //在右子树中查找排名第k-(P.lsize() + P.weight)的元素
        return Treap_Findkth(P->right,k-(P->lsize() + P->weight));
    else   return P->value; //返回当前节点
}
void Treap_Delete(Treap_Node *&p,int value)
{
    if(value==p->value)
    {
        if(!p->right||!p->left)
        {
            Treap_Node *t=p;
            if(!p->right)
                p=p->left;
            else p=p->right;
            delete t;
        }
        else
        {
            if(p->left->fix<p->right->fix)
            {
                Treap_Right_Rotate(p);
                Treap_Delete(p->right,value);
            }
            else
            {
                Treap_Left_Rotate(p);
                Treap_Delete(p->left,value);
            }
        }
    }
    else if(value<p->value)
    {
        Treap_Delete(p->left,value);
    }
    else
        Treap_Delete(p->right,value);
}
void Treap_Insert(Treap_Node *&P,int value) //节点指针一定要传递引用
{
    if (!P) //找到位置，建立节点
    {
        P=new Treap_Node;
        P->value=value;
        P->fix=rand();//生成随机的修正值
    }
    else if (value <= P->value)
    {
        Treap_Insert(P->left,value);
        if (P->left->fix < P->fix)
            Treap_Right_Rotate(P);//左子节点修正值小于当前节点修正值，右旋当前节点
    }
    else
    {
        Treap_Insert(P->right,value);
        if (P->right->fix < P->fix)
            Treap_Left_Rotate(P);//右子节点修正值小于当前节点修正值，左旋当前节点
    }
}
int Treap_FindMin(Treap_Node *P)
{
    while (P->left) //如果有左子节点，访问左子节点
        P=P->left;
    return P->value;
}
int Treap_FindMax(Treap_Node *P)
{
    while (P->right) //如果有右子节点，访问右子节点
        P=P->right;
    return P->value;
}
int Treap_Rank(Treap_Node *p,int value,int cur)//求元素value的排名 
{
    if(value==p->value)
        return p->lsize()+cur+1;
    else if(value<p->value)
    {
        return Treap_Rank(p->left,value,cur);//在左子树中查找  
    }
    else return Treap_Rank(p->right,value,cur+p->lsize()+p->weight);//在右子树中查找
}
void DeleteTreap(Treap_Node* &t)
{
    if(t==NULL) return ;
    else if(t->left!=NULL) DeleteTreap(t->left);
    else if(t->right!=NULL) DeleteTreap(t->right);
    delete t;
    t=NULL;
}
int val[2333];
int main()
{
    int n,x,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>val[i];
    }
    int index=1;
    Treap_Node *root = NULL;
    for(int i=1;i<=m;i++)
    {
        cin>>x;
        cout<<x<<endl;
        for(int j=index;j<=x;j++)
        {
            Treap_Insert(root,val[j]);
        }
        index=x+1;
        cout<<Treap_Findkth(root,i)<<endl;
    }
    DeleteTreap(root);
    return 0;
}









