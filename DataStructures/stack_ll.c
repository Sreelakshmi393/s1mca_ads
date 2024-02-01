#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *top=NULL;


void push(){
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    printf("\n Enter the element : ");
    scanf("%d",&newnode->data);

    newnode->next=top;
    top=newnode;
}

void pop(){
    if(top == NULL){
        return;
    }
    struct node *temp = top;
    top=top->next;
    free(temp);
}

void display(struct node *top){
    if(top==NULL){
        return;
    }
    printf("%d ",top->data);
    display(top->next);
}

void main(){
    while(1){
        int ch;
        printf("\n Enter your choice : \n1. Push \n2.pop \n3.display");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display(top);
                break;
        }
    }
}