#include<stdio.h>
#include<stdlib.h>

#define size 5

int q[size];
int front=-1;
int rear=-1;

int isFull(){
    if(rear==size-1){
        printf("\nOverflow\n");
        return 1;
    }
    return 0;
}

int isEmpty(){
    if(front==-1){
        printf("\nUnderflow\n");
        return 1;
    }
    return 0;
}

void display(){
    if(isEmpty()){
        return;
    }
    for(int i=front; i<=rear; i++){
        printf("%d ", q[i]);
    }
}

void enqueue(){
    int ele;
    printf("\n Enter the element for insertion : \n");
    scanf("%d", &ele);

    if(isFull()){
        return;
    }
    if(front=-1){
        front = 0;
    }
    rear++;
    q[rear] = ele;
    display();
}

void dequeue(){
    if(isEmpty()){
        return;
    }
    front++;
    display();
}



void main(){
    while(1){
        int ch;
        printf("\n Enter your choice : \n1. enqueue \n2.dequeue \n3.exit");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break; 
            case 3:
                exit(0);
            
        }
    }
}
