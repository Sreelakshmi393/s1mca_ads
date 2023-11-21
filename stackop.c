#include<stdio.h>
#include<stdlib.h>
int top=-1,arr[100],choice,size;
void push();
void pop();
void show();
int main()
{
printf("enter the size of array\n");
scanf("%d",&size);
while(1){
printf("\n1.push operation\n2.pop operation\n 3.show\n4.exit\n");
printf("enter the choice\n");
scanf("%d",&choice);
switch(choice)
{
case 1:
push();
break;
case 2:
pop();
break;
case 3:
show();
break;
case 4:
exit(0);
default:
printf("invalid choice\n");
}
}
}
void push()
{

int n;
if(top==size-1)
{
printf("overflow\n");
}
else
{
printf("enter the elemnt to be pushed\n");
scanf("%d",&n);
top=top+1;
arr[top]=n;
}
}
void pop()
{
if(top==-1)
{
printf("underflow\n");
}
else
{
top=top-1;
}
}
void show()
{
if(top==-1)
{
printf("underflow\n");
}
else
{
printf("elmnts of the array\n");
for(int i=top;i>=0;i--)
printf("%d",arr[i]);
}
}

















