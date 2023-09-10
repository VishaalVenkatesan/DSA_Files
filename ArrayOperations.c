#include<stdio.h>
#include<stdlib.h>
struct Array{
    int *A;
    int size;
    int length;
};
void Display(struct Array arr){
    int i;
    printf("The array elements are:");
    for(i=0;i<arr.length;i++){
        printf("\n%d",arr.A[i]);
    }
}   
void append(struct Array *arr,int x){
    if(arr->length<arr->size)
    arr->A[arr->length++]=x;
    else
    printf("!!The array is full!!\n");
}
void insert(struct Array *arr,int index,int x){
    int i;
    if(index>0 && index<=arr->length){
        for(i=arr->length;i>index;i--)
        arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
    }
}
void delete(struct Array *arr, int index){
    int i;
    if(index>0 && index<arr->length){
        for(i=arr->length;i<=index;i--){
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
}
int linearSearch(struct Array arr, int value){
    int i;
    for(i=0;i<arr.length;i++){
        if(value==arr.A[i])
        return i;
    }
    return -1;
}
void reverse(struct Array *arr){
    int i,j,temp=0;
    for(i=0;i<arr->length;i++){
        for(j=arr->length;j<=0;j--){
            temp=arr->A[i];
            arr->A[j]=arr->A[i];
            arr->A[j]=temp;
        }
        
    }
}
 int main(){
    struct Array arr;
    int i,n;
    printf("Enter the size of your array:");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements in the array:");
    for(i=0;i<n;i++){
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;
   // printf("\nThe element is at:");
    //linearSearch(arr,3);
    reverse(&arr);
     Display(arr);
}