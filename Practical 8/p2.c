#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node* newNode(int data)
{
  // Allocate memory for new node
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;

  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
  return(node);
}
void Display(struct node *temp)
{
    if(temp != NULL)
    {
        printf("%d ",temp->data);
        Display(temp->left);
        Display(temp->right);
    }
}
int main()
{
  struct node *root;
  root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left   = newNode(4);
  root->left->right  = newNode(5);
  root->right->left   = newNode(6);
  root->right->right  = newNode(7);

  /*printf("%d\n",root->data);
  printf("%d\n",root->left->data);
  printf("%d\n",root->right->data);
  printf("%d\n",root->left->left->data);*/

  Display(root);
}
