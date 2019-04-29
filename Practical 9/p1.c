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

void Inorder(struct BSTnode* root){
    if(root == NULL)
        return;

    Inorder(root->left);
    printf("%d ->", root->data);
    Inorder(root->right);
}
void Preorder(struct BSTnode* root){
    if(root == NULL)
        return;

    printf("%d ->", root->data);
    Preorder(root->left);
    Preorder(root->right);
}
void Postorder(struct BSTnode* root){
    if(root == NULL)
        return;

    Postorder(root->left);
    Postorder(root->right);
    printf("%d ->", root->data);
}


int main(){
    struct BSTnode *root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 1);
    insert(root, 6);
    insert(root, 7);
    insert(root, 10);
    insert(root, 14);
    insert(root, 4);

    printf("IN ORDER : \n");
    printf("\n");
    Inorder(root);
    printf("\n");
    printf("\n");

    printf("POST ORDER : \n");
    printf("\n");
    Postorder(root);
    printf("\n");
    printf("\n");

    printf("PRE ORDER : \n");
    printf("\n");
    Preorder(root);
    printf("\n");
    printf("\n");
}
