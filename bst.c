#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;
int isEmpty=1;

int insert();
int display();
void deletion();

void main(){
    while(1){
        int choice;
        printf("Enter ]n 1. Insertion \n 2. Deletion \n 3. Display \n 4. Exit \n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                insert();
                display();
                break;
            case 2:
                deletion();
                display();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter a vaild choice");
                break;
        }
    }
}

//insertion of a node
int insert(){
    int value;
    struct Node *newnode, *temp;
    printf("Element : ");
    scanf("%d",&value);

    newnode = (struct Node *) malloc(sizeof(struct Node));
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;

    if(isEmpty){
        root=newnode;
        isEmpty=0;
        return 0;
    }

    temp=root;
    while(temp != NULL){
        if(temp->data >value){
            if(temp->left==NULL){
                temp->left=newnode;
                return 0;
            }
            temp=temp->left;
        }else{
            if(temp->right==NULL){
                temp->right=newnode;
                return 0;
            }
            temp=temp->right;
        }
    }
    return 0;
}

//smallest node
struct Node *find_min(struct Node *root){
    while (root->left != NULL)
    {
        root=root->left;
    }
    return root;
}

//Delete
struct Node *delete(struct Node *root, int value){
    if(root==NULL){
        printf("Error found\n");
        return root;
    }


//Finding node
struct Node *temp;
if(value<root->data){
    root->left=delete(root->left, value);
}
else if(value>root->data){
    root->right=delete(root->right,value);
}else{
    //Reached the node to be deleted
    //One child condition
    if(root->left==NULL){
        temp=root->right;
        free(root);
        return temp;
    }else if (root->right==NULL)
    {
        temp=root->left;
        free(root);
        return temp;
    }
    //Two children condition
    root->data=find_min(root->right)->data;
    root->right=delete(root->right, root->data);
    }
    return root;
}

void deletion(){
    int value;
    printf("Enter the value of node to delete : ");
    scanf("%d",&value);
    root=delete(root, value);
    //tree empty
    if(root==NULL)
        isEmpty=1;
    display();
}

//traversal
int display(){
    if(root==NULL){
        printf("Tree is empty\n");
        return 1;
    }
    int preOrder(struct Node *root){
        if(root==NULL)
            return 1;
        printf("%d->",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
    int inOrder(struct Node *root){
        if(root==NULL){
            return 1;
        }
        inOrder(root->left);
        printf("%d->", root->data);
        inOrder(root->right);
    }
    int postOrder(struct Node *root){
        if(root==NULL){
            return 1;
        }
        postOrder(root->left);
        postOrder(root->right);
        printf("%d->",root->data);
    }
    printf("\nPreOrder : \n");
    preOrder(root);
    printf("\n InOrder : \n");
    inOrder(root);
    printf("\nPostOrder : \n");
    postOrder(root);
    printf("\n");
    return 0;
}
