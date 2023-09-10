#include<stdio.h>
#include<stdlib.h>

// Creating a structure called node
struct Node
{
    struct Node *leftChild;
    int data;
    struct Node *rightChild;
}; struct Node *root=NULL;

// Create function to create a Binary Search Tree
void insertEle(int key)
{
    struct Node *t = root;
    struct Node *r=NULL,*p;
    int i;
    
    if(root == NULL){
        p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->leftChild = p->rightChild = NULL;
        root=p;
        return;
    }
    while(t!=NULL)
    {
        r=t;
        if(key < t->data)
           t=t->leftChild;
        else if(key > t->data)  
           t=t->rightChild;
        else
           return;    

    }
      p = (struct Node *)malloc(sizeof(struct Node));
        p->data = key;
        p->leftChild = p->rightChild = NULL;

        if(key < r->data)
            r->leftChild=p;
        else
            r->rightChild=p;
    }


void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->leftChild);
        Preorder(p->rightChild);
    }
}
void Inorder(struct Node *p)
{
    if(p)
    {
        Inorder(p->leftChild);
        printf("%d ",p->data);
        Inorder(p->rightChild);
    }
}
void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->leftChild);
        Postorder(p->rightChild);
        printf("%d ",p->data);
    }
}
int main(){
    int array[5]={1,2,3,4,5};
    int i;

    for(i=0;i<5;i++){
        insertEle0(array[i]);
    }
    Preorder(root);
}

