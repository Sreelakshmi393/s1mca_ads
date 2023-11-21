#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 100
void enqueue(int item);
void dequeue();
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
	if((rear+1)% MAX_SIZE==front)
	{
	printf("OVERFLOW");
	}
	if(front==-1 && rear==-1)
	{
	front=rear=0;	
	}
	else if(rear==MAX_SIZE-1 && front!=0)
		{
		rear=0;
		
		}
	else
		{
		rear=rear+1;
		
		}
		
queue[rear]=item;
}
void dequeue(int item){
	if(front==-1)
	{
	printf("UNDERFLOW");
	}
	if(front==rear)
	{
	front=rear=-1;
	}
	else if(front==MAX_SIZE-1)
	{
	front=0;
	}
	else{
	front=front+1;
	}
}
void show()
{
if(front==-1)
	printf("Empty queue \n");
	else{
	printf("Queue : \n");
	for(int i=front; i<=rear; i++)
	printf("%d ",queue[i]);
	printf("\n");
	}
}

	



		
	
		
	

