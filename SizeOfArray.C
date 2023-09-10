#include<stdio.h>
#include<stdlib.h>
int intArray(int A[],size_t s){
    return s;
}
int floatArray(float B[], size_t t){
    return t;
}
int main(){

    int E[]={1,2,3,4,5};
    float F[]={2.45,4,5.67,6,7,6.56,7.98};
    size_t n=sizeof(E);
    size_t x=sizeof(F);
    printf("The size of int Array is %d",intArray(E,n));
    printf("\nThe size of float array is %d",floatArray(F,x));


}