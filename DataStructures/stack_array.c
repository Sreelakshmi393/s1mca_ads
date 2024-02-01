#include<stdio.h>
#include<stdlib.h>

#define size 6

int s[size];
int top=-1;

void push();


int isEmpty(){
    if(top==-1){
        printf("\nStack empty\n");
        return 1;
    }
    return 0;
}

int isFull(){
    if(top==size-1){
        printf("\n Stack full\n");
        return 1;
    }
    return 0;
}

void display(){
    for(int i=0; i<=top; i++){
        printf("%d ", s[i]);
    }
}

void push(){
    if(isFull()){
        return;
    }
    int ele;
    printf("\n Enter the element for insertion : \n");
    scanf("%d", &ele);
    top++;
    s[top]=ele;
    display();
}
void pop(){
    if(isEmpty()){
        return;
    }
    top--;
    display();
}

int count(){
  return top+1;
}  

int peek(){
    return s[top];
}

void main(){
    while(1){
        int ch;
        printf("\n Enter your choice : \n1. Push \n2. Pop \n 3.Count \n4. peek \n5.exit");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                printf("%d ",count());
                break;
            case 4:
                printf("%d", peek());
                break;
            case 5:
                exit(0);
        }

    }
}