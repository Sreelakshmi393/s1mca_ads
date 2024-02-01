#include<stdio.h>
#include<stdlib.h>

#define size 100

int arr[size];
int n;
 
void createArray();
void display();
void insertion();
void deletion();
void search();
void bubblesort();
void reverse();

void main(){
    while(1){
        int ch;
        printf("\n Enter your choice : \n 1. createArray \n2. display \n3. insertion \n4. deletion \n5.search \n6. bubble sort \n7. reverse \n8. Exit\n");
        scanf("%d", &ch);
        switch(ch){
            case 1:
                createArray();
                break;
            case 2:
                display();
                break;
            case 3:
                insertion();
                break;
            case 4:
                deletion();
                break;
            case 5:
                search();
                break;
            case 6:
                bubblesort();
                break;
            case 7:
                reverse(0, n-1);
                break;
            case 8:
                exit(0); 
        }
    }
}

void createArray(){
    printf("Enter the number of elements : \n");
    scanf("%d", &n);
    printf("\n Enter the elements : \n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
}

void display(){
    printf("\n Array is \n");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
}

void insbeginning(int ele){
    for(int i=n; i>0; i--){
        arr[i]=arr[i-1];
    }
    arr[0]=ele;
    n++;
    display();
}

void insanypos(int ele){
    int pos;
    printf("\nEnter the position : \n");
    scanf("%d",&pos);
    if(pos>n){
        printf("\n Invalid position\n");
    }else{
    for(int i=n; i>pos-1; i--){
        arr[i] = arr[i-1];
    }
    arr[pos-1]=ele;
    n++;
    display();
    }
}

void insend(int ele){
    arr[n]=ele;
    n++;
    display();
}

void insertion(){
        int ch,ele;
        printf("\n Enter the element : \n");
        scanf("%d", &ele);
        printf("\n Enter your choice : \n 1. Insertion at beginning \n 2. Insertion at any pos \n 3. Insertion at end 4. Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                insbeginning(ele);
                break;
            case 2:
                insanypos(ele);
                break;
            case 3:
                insend(ele);
                break;
            case 4:
                exit(0);
        }
}

void delbeginning(){
    for(int i=0; i<n; i++){
        arr[i]=arr[i+1];
    }
    n--;
    display();
}

void delanypos(){
    int pos;
    printf("\n Enter the position : \n");
    scanf("%d", &pos);
    for(int i=pos-1;i<n;i++){
        arr[i]=arr[i+1];
    }
    n--;
    display();
}


void delend(){
    n--;
    display();
}

void deletion(){
    if(n == 0){
        printf("\nArray is empty\n");
        return;
    }
    int ch;
    printf("\n Enter your choice \n 1. Deletion at beginning \n2. Deletion at any position \n 3. Deletion at end 4.exit\n");
    scanf("%d", &ch);
    switch(ch){
        case 1:
            delbeginning();
            break;
        case 2:
            delanypos();
            break;
        case 3:
            delend();
            break;
        case 4:
            exit(0);
    }
}

void search(){
    int ele;
    printf("\nEnter the element to search \n");
    scanf("%d", &ele);
    for(int i=0; i<n; i++){
        if(arr[i]==ele){
            printf("\n %d is found at location %d",ele, i+1);
            return;
        }
    }
    printf("\n Element not found \n");
}

void bubblesort(){
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted successfully\n");
    display();
}


void reverse(int first,int last){
    if(first>=last){
        printf("\n Reversed successfully\n");
        display();
        return;
    }
    int temp = arr[first];
    arr[first] = arr[last];
    arr[last] = temp;
    reverse(first+1, last-1);
}
