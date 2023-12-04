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
		printf("Enter 0 to display \n 1 to insert\n 2 to delete \n 3 to exit: ");
		scanf("%d", &choice);
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
			case 3:
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
	
	// If empty
	if (head == NULL) {
		newnode->next = NULL;
		newnode->prev = NULL;
		head = newnode;
		tail = newnode;
		size++;
		display(head);
		return 0;
	}

	
	void begin()
	{
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
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
	
	switch (type) {
		case 0:
			begin();
			break;
		case 1:
			end();
			break;
		case 2:
			pos();
			break;
	}
	size++;
	display(head);
	return 0;
}

int deletion(){
	int type;
	struct node *delnode, *temp, *temp1;
	printf("Enter 0 deletion at the beginning\n 1 deletion at the end \n 2 deletion at any position: ");
	scanf("%d", &type);
	temp = head;
	
	// If only one node remaining
	if (size == 1) {
		delnode = head;
		head = NULL;
		tail = NULL;
		free(delnode);
		size--;
		display(head);
		return 0;
	}
	
	
	void begin(){
	delnode=head;
	temp=head->next;
	head=temp;
	temp->prev=NULL;
	}
	
	void end(){
	delnode=tail;
	temp=tail->prev;
	tail=temp;
	temp->next=NULL;
	}
	
	
	// Deletion at any position
	void anypos() {
		int position;
		printf("Position: ");
		scanf("%d", &position);
		if (position <= 1 || position >= size || size < 3) {
			printf("Invalid!\n");
			return;
		}
		struct node *temp, *temp1, *temp2;
		temp = head;
		int i = 1;
		while (i < position) {
			if (temp->next != NULL) {
				temp1 = temp;
				temp = temp->next;
				temp2 = temp->next;
			}
			i++;
		}
		delnode = temp;
		temp1->next = temp2;
		temp2->prev = temp1;
	}
	
	switch (type) {
		case 0:
			begin();
			break;
		case 1:
			end();
			break;
		case 2:
			anypos();
			break;
	}
	free(delnode);
	size--;
	display(head);
	return 0;
	}
	
void display(struct node *ptr){
 if(size==0){
 printf("linked list is empty\n");
 return;
 }
 void headtotail(struct node * ptr) {
		if (ptr == head)
			printf("Head ->");
		if (ptr == NULL) {
			printf("<- Tail\n");
			return;
		}
		printf("<- %d -> ", ptr->data);

		headtotail(ptr->next);		
	}
	headtotail(head);
}
 
 
 

	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
