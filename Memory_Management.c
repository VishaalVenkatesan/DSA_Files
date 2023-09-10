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
    if(E->p==NULL && Arr_size<=0){
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
    E->p=(char *)realloc(E->p,sizeof(int)*newSize); 
    if(E->p==NULL && newSize==0){
    return false;
    }
    else{
    E->size=newSize;
    return true;
    }
}
bool freeEle(struct Element *E){
    if(E->size!=0)
    free(E->p);
    if(E->p==NULL)
    return true;
    else
    return false;
}
// function to display the array
void display(struct Element *E){
    printf("The Elements inside the array are:\n");
    for(int i=0;i<E->size;i++)
    printf("%c ",E->p[i]);
}

int main(){
    struct Element E;
    create(&E,0);
   if(create(&E,0)!=false){
  printf("Enter Elements (press 'q' to quit):\n");
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
    }
   }
    display(&E);

    freeEle(&E);
    if(freeEle(&E)==false)
    printf("could not free element");

    }

        

      


