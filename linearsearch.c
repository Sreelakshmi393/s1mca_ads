#include<stdio.h>
void main()
{
int a[10],i,item,flag=0;
printf("enter array elemnts\n");
for(i=0;i<5;i++)
{
scanf("%d",&a[i]);
}
printf("array elemnts are");
for(i=0;i<5;i++)
{
printf("%d",a[i]);
}
printf("enter elemnt to be searched\n");
scanf("%d",&item);
for(i=0;i<5;i++)
{
if(item==a[i])
{
printf("item found\n");
}
else
{
flag=flag++;
}
}
if(flag>0)
{
printf("not found");
}
return 0;
}



