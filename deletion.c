#include<stdio.h>
void main()
{
int arr[100], i,ind, n,temp;
printf("Enter the size of array\n");
scanf("%d",&n);
printf("Enter  the elements of the array\n");
for(int i =0;i<n; i++)
scanf("%d",&arr[i]);
printf("array elemnts are\n");
for(int i =0;i<n; i++)
printf("%d",arr[i]);

printf("enter the index number for deletion\n");
scanf("%d",&ind);
//temp=arr[ind];

for(i=ind;i<n-1;i++){
arr[i]=arr[i+1];
}
//n=n-1;
printf("array after deletion\n");
for(int i =0;i<n-1; i++)
printf("%d",arr[i]);

}





