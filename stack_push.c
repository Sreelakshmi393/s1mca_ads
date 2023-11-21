#include<stdio.h>
void main(){
int size=20,n, top=-1,x;
int a[size];
printf("Enter number of elements to be inserted ");
scanf("%d", &n);
if(top==size-1)
{
printf("Stack Overflow");
}
else{
for(int i=0; i<=n; i++){
printf("Enter the element to  be inserted");
scanf("%d ", &x);
top = top+1;
a[top]=x;
}
}
printf("The elements present is ");
for(int i=top; i>=0; i--)
printf("%d\n", a[i]);
}
