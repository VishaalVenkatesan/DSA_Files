#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct Node
{
    struct Node *LeftChild;
    int data;
    int bf;
    struct Node *RightChild;
}*root=NULL;

int height(struct Node *p)
{
    int x=0,y=0;
    if(!p)return 0;
    x=height(p->LeftChild);
    y=height(p->RightChild);
    return x>y?x+1:y+1;
}

struct Node * LLRotation(struct Node *p)
{
    int lbf,rbf;
    struct Node *pl=p->LeftChild;
    pl->bf=0;
    p->LeftChild=pl->RightChild;
    pl->RightChild=p;
    lbf=height(p->LeftChild)+1;
    rbf=height(p->RightChild)+1;
    p->bf=lbf-rbf;
    if(p==root)root=pl;
    return pl;
}
struct Node *LRRotation(struct Node *p)
{
    int lbf,rbf;
    struct Node *pl=p->LeftChild;
    struct Node *plr=pl->RightChild;
    plr->bf=0;
    
    p->LeftChild=plr->RightChild;
    pl->RightChild=plr->LeftChild;
    plr->LeftChild=pl;
    plr->RightChild=p;
    lbf=height(p->LeftChild)+1;
    rbf=height(p->RightChild)+1;
    p->bf=lbf-rbf;
    
    lbf=height(pl->LeftChild)+1;
    rbf=height(pl->RightChild)+1;
    pl->bf=lbf-rbf;
    if(p==root)root=plr;
    return plr;
}
struct Node *RRRotation(struct Node *p)
{
    int lbf,rbf;
    struct Node *pr=p->RightChild;
    pr->bf=0;
    p->RightChild=pr->LeftChild;
    pr->LeftChild=p;
    lbf=height(p->LeftChild)+1;
    rbf=height(p->RightChild)+1;
    p->bf=lbf-rbf;
    if(p==root)root=pr;
    return pr;
}
struct Node *RLRotation(struct Node *p)
{
    int lbf,rbf;
    struct Node *pr=p->RightChild;
    struct Node *prl=pr->LeftChild;
    prl->bf=0;
    
    p->RightChild=prl->LeftChild;
    pr->LeftChild=prl->RightChild;
    prl->RightChild=pr;
    prl->LeftChild=p;
    lbf=height(p->LeftChild)+1;
    rbf=height(p->RightChild)+1;
    p->bf=lbf-rbf;
    
    lbf=height(pr->LeftChild)+1;
    rbf=height(pr->RightChild)+1;
    pr->bf=lbf-rbf;
    if(p==root)root=prl;
    return prl;
}
struct Node* RInsert(struct Node *p,int key)
{
    
    struct Node *t;
    int lbf,rbf;
    if(p==NULL)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=key;
        t->bf=0;
        t->LeftChild=t->RightChild=NULL;
        return t;
    }
    if(key<p->data)
        p->LeftChild=RInsert(p->LeftChild,key);
    else if(key>p->data)
        p->RightChild=RInsert(p->RightChild,key);
    
    lbf=height(p->LeftChild)+1;
    rbf=height(p->RightChild)+1;
    p->bf=lbf-rbf;
    if(p->bf==2 && p->LeftChild->bf==1)
        return LLRotation(p);
    if(p->bf==2 && p->LeftChild->bf==-1)
        return LRRotation(p);
    if(p->bf==-2 && p->RightChild->bf==-1)
        return RRRotation(p);
    if(p->bf==-2 && p->RightChild->bf==1)
        return RLRotation(p);
    return p;
}
void Initialize(int key)
{
    struct Node *t=root;
    struct Node *r=NULL,*p;
    
    if(root==NULL)
    {
        p=(struct Node *)malloc(sizeof(struct Node));
        p->data=key;
        p->bf=0;
        p->LeftChild=p->RightChild=NULL;
        root=p;
        return;
    }
  
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->LeftChild);
        printf("%d ",p->data);
        Inorder(p->RightChild);
    }
}

struct Node * Search(int key)
{
    struct Node *t=root;
    
    while(t!=NULL)
    {
        if(key==t->data)
            return t;
        else if(key<t->data)
            t=t->LeftChild;
        else
            t=t->RightChild;
    }
    return NULL;
}
int main()
{
    struct Node *temp;
    
    Initialize(30);
    RInsert(root,50);
    RInsert(root,40);
    RInsert(root,20);
    RInsert(root,10);
    RInsert(root,42);
    RInsert(root,46);
    
    Inorder(root);
    
    

    
    return 0;
}