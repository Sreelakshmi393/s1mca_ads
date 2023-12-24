#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

int size=0, flag=0;
struct Node *head=NULL;
void display(struct Node *ptr);
void insertion();
void deletion();

void main(){
    int choice;
    while(1){
        printf("\nEnter your choice \n 1. Insertion \n 2. Deletion \n 3. Display \n 4. Exit\n");
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
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid Choice");
        }
    }
}

void insertion(){
    struct Node *newnode, *temp;
    newnode = (struct Node *) malloc(sizeof(struct Node));
    printf("Element : ");
    scanf("%d", &newnode->data);

    if(head==NULL){
        head=newnode;
        newnode->next=head;
        display(head);
        size++;
    }

    void beginning(){
        newnode->next=head;
        temp=head;
        while(temp->next != head){
        temp = temp->next;
        }
        temp->next=newnode;
        head=newnode;
        size++;
    }

    void anypos(){
        int pos;
        printf("Enter the postion : ");
        scanf("%d", &pos);
        if(pos<1 || pos>size-1){
            printf("Enter a valid postion");
            return;
        }
        int i=2;
        temp=head;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        size++;
    }

    void end(){
        temp=head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->next=head;
        size++;
    }

    int ch;
    printf("\nEnter: \n 1. Insertion at beginning \n 2. Insertion at anypos \n 3. Insertion at end \n 4. Exit\n");
    scanf("%d", &ch);
    switch(ch){
        case 1:
            beginning();
            break;
        case 2:
            anypos();
            break;
        case 3:
            end();
            break;
        case 4:
            exit(0);
        default:
            printf("Enter a vaild choice");
    }
    size++;
    display(head);
}

void deletion(){
    struct Node *temp, *delnode;
    temp=head;
    if(head==NULL)
        return;
    
    if(head->next==head){
        head=NULL;
        free(temp);
        return;
    }

    void beginning(){
        delnode=head;
        while(temp->next != head){
            temp=temp->next;
        }
        head=head->next;
        temp->next=head;
        free(delnode);
        size--;
    }


    void anypos(){
        int pos;
        printf("Enter the position : ");
        scanf("%d", &pos);
        if(pos>size-1 || pos<11){
            printf("Invalid position");
            return;
        }

        int i=2;
        while(i<pos){
            temp=temp->next;
            i++;
        }
        delnode=temp->next;
        temp->next=delnode->next;
        free(delnode);
        size--;
    }

    void end(){
        while(temp->next->next != head){
            temp=temp->next;
        }
        delnode=temp->next;
        temp->next=head;
        free(delnode);
        size--;
    }

    int ch;
    printf("\nEnter \n 1. Deletion at beginning \n 2. Deletion at any position \n 3. Deletion at end \n 4. Exit\n");
    scanf("%d", &ch);
    switch(ch){
    case 1:
        beginning();
        break;
    case 2:
        anypos();
        break;
    case 3:
        end();
        break;
    case 4:
        exit(0);
    default:
        return;
    }
    display(head);
}

void display(struct Node *ptr){
    if(head==NULL){
        printf("NULL");
        return;
    }
    if(ptr->next==head){
        printf("%d", ptr->data);
        return;
    }
    printf("%d->",ptr->data);
    display(ptr->next);
}
