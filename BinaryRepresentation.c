#include<stdio.h>
int main(){
int a[30],i,n;
printf("Enter a number:");
scanf("%d",&n);
for(i=0;n>0;i++){
    a[i]=n%2;
    n/=2;
}
printf("The binary no obtained is:\n");
for(i=i-1;i>=0;i--){
    printf("%d",a[i]);
}
}