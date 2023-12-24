#bracketed
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node * next;
};

void main(){
int choice;
while(1){
printf("1. Insertion/n 2. Deletion/n 3. Display/n 4. Exit");
scanf("%d", &choice);
switch(choice){
case 1:
	insertion();
	break;
case 2:
	deletion();
	break;
case 3:
 	display(head);
 	break();
case 4:
	exit(0);
default:
	printf("Invalid");
}
}

int insertion(){
int type;
struct node *new_node, *temp;
struct node * new_node = ( struct node* )malloc(sizeof(struct node));
printf("1. Insertion at first/n 2.Insertion at index/n 3. Insertion at last/n 4.Exit");
scanf("%d",&type);
temp=head;
printf("Elements : ");
scanf("%d",&new_node->data);
struct node * insertatfirst(int data){
	//struct node * new_node = ( struct node* )malloc(sizeof(struct node));
	new_node->data=data;
	new_node->next=head;
	head=new_node;
}

struct node * insertAtIndex(int data){
	//struct node* new_node = ( struct node* )malloc(sizeof(struct node));
	int i=0;
	while(i!=index-1)
	{
	temp=temp->next;
	i++;
	}
	new_node->data=data;
	new_node>next=temp->next;
	temp->next=new_node;
	return head;
}

struct node * insertAtEnd(int data){
	//struct node * new_node = (struct node *)malloc(sizeof(struct node));
	
	new_node->data = data;
	while(temp->next!=NULL){
	temp=temp->next;
	}
	temp->next=new_node;
	new_node->next=NULL;
	return head;
}
switch(type){
case 1:
		insertatfirst(data);
case 2:
	insertAtIndex(data);
case 3:
	insertAtEnd(data);
case 4:
	exit(0);
default:
	printf("Invalid");
}
return 0;
}

int deletion(){
int type;
struct node *temp, *temp1, *delnode;
temp=head;
printf("1. Insertion at first/n 2.Insertion at index/n 3. Insertion at last/n 4.Exit");
scanf("%d",&type);

void delAtBeg(){
	head=temp->next;
	free(temp);
}

void delAtPos(){
	int position;
	printf("Position : ");
	scanf("%d",&position);
	if(position->size){
	printf("Invalid");
	return;
	}
	int i=2;
	while(i<position){
	temp=temp->next;
	i++;
	}
	delnode=temp->next;
	temp->next = delnode->next;
	free(delnode);
	}

void delAtEnd(){
	while(temp->next!= NULL){
	temp1=temp;
	temp=temp->next;
	}
	temp1->next=NULL;
	free(temp);
}

switch(type){
case 1:
	delAtBeg();
case 2:
	delAtPos();
case 3:
	delAtEnd();
case 4:
	exit(0);
default:
	printf("Invalid");
}
return 0;
}

void display(struct node *ptr)
{
	while (ptr != NULL)	
	{
		printf("element:%d\n",ptr->data);
		ptr = ptr->next;
	}
}


	

	
	






















	
	
	




	
