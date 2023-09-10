#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Element{
    char *p; //pointer to traverse
    int size; //size of the array
    int used; //no of used elements
};
bool create(struct Element *E, size_t Arr_size){
    E->p=(char *)malloc(sizeof(char)*Arr_size); //malloc function allocating memory to *p struct char array
    if(E->p==NULL){
    return false;
    }
    else{
    E->size=Arr_size;
    E->used=0;
    return true;
    }
}
// function to increase the memory allocated
bool incsize(struct Element *E){
    size_t newSize;
    newSize=E->size*2; //increasing the size by *2 increments
    E->p=(char *)realloc(E->p,sizeof(char)*newSize); 
    if(E->p==NULL){
         return false;
    }
    else{
         E->size=newSize;
         return true;
    }
}
bool freeEle(struct Element *E){
    if(E->p!=NULL)
    free(E->p);
    if(E->p==NULL)
    return true;
    else
    return false;
}
void push(struct Element *stack, char value) {
    if (stack->used == stack->size) {
        incsize(stack);
        
     }
     stack->p[stack->used] = value;
    stack->used++;
}

char pop(struct Element *stack) {
    if (stack->used == 0) {
        printf("Stack underflow\n");
        return '\0';
    }

    stack->used--;
    return stack->p[stack->used];
}
// function to display the array
void display(struct Element *E){
    printf("The Elements inside the array are:\n");
    for(int i=E->used;i>=0;i--)
    printf("%c ",E->p[i]);
}

int main(){
    struct Element E;
   if(create(&E,2)){
 /*  printf("Enter Elements (press 'q' to quit):\n");
    for (int i=0; i<E.size; i++) {
        char input;
        scanf(" %c", &input);
        if (input == 'q') {
            break;  // Exit the loop if 'q' is entered
        }
        E.p[i] = input;
        E.used++;
        if (E.used == E.size)
            incsize(&E);
            if(incsize(&E)==false){
                break;
            }
    }*/
     push(&E,'1');
     push(&E,'2');
     push(&E,'3');
     push(&E,'4');
           
   }
    display(&E);

    freeEle(&E);
   

    }