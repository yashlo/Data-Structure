#include<stdio.h>
#include<stdlib.h>

struct BSTnode
{
    int data;
    struct BSTnode* left;
    struct BSTnode* right;
};

struct BSTnode* createNode(value){
    struct BSTnode* newNode = malloc(sizeof(struct BSTnode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


struct BSTnode* insert(struct BSTnode* root, int data)
{
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left  = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

void search(struct BSTnode *temp,int data)
{
    if(temp == NULL)
        return;

    if(data < temp->data)
    {
       //  printf("Data Less Than Root : %d\n",temp->data);
         search(temp->left,data);
    }
    else if(data > temp->data)
    {
         //printf("Data Grater Than Root : %d\n",temp->data);
         search(temp->right,data);
    }

    if(temp->data == data)
        printf("Data is Found : \n");

}

int main(){
    struct BSTnode *root = NULL;

    int rdata;
    printf("Enter Root Node : ");
    scanf("%d",&rdata);
    root = insert(root, rdata);

    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 5);
    insert(root, 10);
    insert(root, 25);
    insert(root, 14);
    insert(root, 20);
    insert(root, 4);

    int data;
    printf("Enter Search Data : ");
    scanf("%d",&data);
    search(root,data);
}
