#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
void enqueue(int item);
int dequeue();
void show();
int queue[MAX_SIZE];
int rear=-1;
int front=-1;
void main()
{
	int ch,item;
	while(1)
	{
		printf("\n 1.insert \n 2.delete \n 3.display \n 4.exit\n");
		printf("enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			printf("\n input the element to insert:");
			scanf("%d",&item);
			enqueue(item);
			break;
			case 2:
			dequeue();
			break;
			case 3:
			show();
			break;
			case 4:
			exit(0);
			default:
			printf("Invalid choice");
		
	  	}
	 }
}

void enqueue(int item){
	if(rear+1)% MAX_SIZE
