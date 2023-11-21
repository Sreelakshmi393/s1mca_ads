#include<stdio.h>
void main()
{
int a[100],i,n,size,val;
printf("enter the size array\n");
scanf("%d",&size);
printf("enter the elemnts of array\n");
for(i=0;i<size;i++)
{
scanf("%d",&a[i]);
}
printf("The arrays is before insertion \n");
for(i=0;i<size;i++)
{
printf("%d",a[i]);
}
printf("Enter the elementn\n");
scanf("%d",&val);
printf("enter the position\n");
scanf("%d",&n);
size++;
for(i=size-1;i>=n;i--)
{
a[i]=a[i-1];
}
a[n-1]=val;
printf("The arrays is \n");
for(i=0;i<size;i++)
{
printf("%d",a[i]);
}
}
