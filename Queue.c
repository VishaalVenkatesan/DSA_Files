#include<stdio.h>
#include<stdlib.h>
// Creating structure queue
struct queue{
    int size;
    int front;
    int rear;
    int *Q;
};
// Function to create a queue
void create(struct queue *q, int size){
    q->size = size;
    q->front =q -> rear = -1;
    q->Q = (int *)malloc(q->size*sizeof(int));
}
// Function to display the queue inputted.
void display(struct queue q){
    int i;
    for(i=q.front+1;i<=q.rear;i++){
        printf("%d\t",q.Q[i]);
    }
}
// Function to add integers into the queue.
void enqueue(struct queue *q, int element){
    if(q->rear==q->size-1){
        printf("Queue is full!!");
    }
    else{
        q->rear++;
        q->Q[q->rear]=element;
    }
}
// Function to dynamically allocate more memory to the struct array.
void incsize(struct queue *q){
    int modSize;
    printf("Enter size required:");
    scanf("%d",&modSize);
    q->Q=(int *)realloc(q->Q,sizeof(int)*modSize);
    printf("%d",&modSize);
    q->size=modSize;
}
// Function to remove element from the queue.
int dequeue(struct queue *q){
    int x=-1;
    if(q->front==q->rear)
    printf("It's empty!!");
    else{
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}
int main(){
    struct queue q;
    int size;
    printf("Enter size of queue:");
    scanf("%d",&size);
    create(&q,size);
    int x;
    incsize(&q);
    for(int i=0;i<7;i++){
        printf("Enter element %d:",i);
        scanf("%d",&x);
        enqueue(&q,x);
    }
    dequeue(&q);
    display(q);
}

