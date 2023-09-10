#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Creating a structure called Node
struct Node{
    struct Node *LeftChild;
    int data;
    struct Node *RightChild;
    
};

// BELOW IS THE CODE FOR QUEUE
struct queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
// Function to create a queue
void create(struct queue *q, int size){
    q->size = size;
    q->front =q -> rear = -1;
    q->Q = (struct Node **)malloc(q->size*sizeof(int));
}
// Function to insert integers into the queue.
bool enqueue(struct queue *q, struct Node *x){
    if(q->rear==q->size-1){
        return false;
    }
    else{
        q->rear++;
        q->Q[q->rear]=x;
        return true;
    }
}
// Function to dynamically allocate more memory to the struct array.
void incsize(struct queue *q){
    int modSize;
    modSize=q->size*2;
    q->Q=(struct Node **)realloc(q->Q,sizeof(int)*modSize);
    q->size=modSize;
}
// Function to remove element from the queue.
struct Node * dequeue(struct queue *q){
    struct Node *x=NULL;
    if(q->front==q->rear)
    return NULL;
    else{
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
// Function to check if queue is empty
int isEmpty(struct queue q)
{
    return q.front==q.rear;
}




struct Node *root=NULL;
// FUNCTION TO CREATE TREE
void CreateTree()
{
    struct Node *p,*t;
    int x;
    struct queue q;
    create(&q,100);
    
    printf("Enter root value ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));
    root->data=x;
    root->LeftChild=root->RightChild=NULL;
    enqueue(&q,root);
    
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->LeftChild=t->RightChild=NULL;
            p->LeftChild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d ",p->data);
        scanf("%d",&x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->LeftChild=t->RightChild=NULL;
            p->RightChild=t;
            enqueue(&q,t);
        }
    }
}
void Preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        Preorder(p->LeftChild);
        Preorder(p->RightChild);
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
void Postorder(struct Node *p)
{
    if(p)
    {
        Postorder(p->LeftChild);
        Postorder(p->RightChild);
        printf("%d ",p->data);
    }
}
int main()
{
    CreateTree();
    Preorder(root);
    printf("\nPost Order ");
    Postorder(root);
    
    return 0;
}