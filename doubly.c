#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
struct node *prev;
};


int size = 0;
struct node *head = NULL;
struct node *tail = NULL;

void display(struct node *ptr);
int insertion();
int deletion();

void main()
{
	int choice;
	while (1) {
		printf("Enter 1 to display \n 2 to insert\n 3 to delete \n 4 to exit: ");
		scanf("%d", &choice)
		switch (choice) {
			case 0:
				display(head);
				break;
			case 1:
				insertion();
				break;
			case 2:
				deletion();
				break;
			case 5:
				return;
			default:
				break;
		}
	}
}

// Insertion at any position
int insertion()
{
	int type;
	struct node *newnode, *temp, *temp1;
	newnode = (struct node *) malloc(sizeof(struct node));
	printf("Enter 0 for insertion at the beginning, 1 for insertion at the end or 2 for insertion at any position: ");
	scanf("%d", &type);
	temp = head;
	printf("Element: ");
	scanf("%d", &newnode->data);
	
	
	
	void begin()
	{
	newnode->next=head;
	head->prev=newnode;
	newnode=head;
	newnode->prev=NULL;
	}


	void end()
	{
	tail->next=newnode;
	newnode->prev=tail;
	tail=newnode;
	newnode->next=NULL;
	}
	
	void pos()
	{
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position <= 1 || position >= size) {
			printf("Invalid!\n");
			return;
		}
	struct node *temp,*temp1;
	temp=head;
	int i=1;
	while(i<position)
	{
		if(temp->next!=NULL)
		{
			temp1=temp;
			temp=temp->next;
		}	
		i++;
	}
	temp1->next=newnode;
	newnode->prev=temp1;
	newnode->next=temp;
	temp->prev=newnode;
	}
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
