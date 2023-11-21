#include<stdio.h>
void main()
{
int array[10],i,j,temp;
printf("Enter the array elements");

for(i=0;i<5;i++)
{
scanf("%d",&array[i]);
}
for(i=0;i<5;i++)
{
for(j=0;j+1<5;j++)
if(array[j]>array[j+1])
{
temp=array[j];
array[j]=array[j+1];
array[j+1]=temp;
}
}  

printf(" the sorted array elements are\n");
for(i=0;i<5;i++)
{
printf("%d\t",array[i]);
}
}
     


