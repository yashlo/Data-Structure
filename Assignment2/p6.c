#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
FILE *fp;
struct node * findmin(struct node *root)
{
	while(root->left != NULL )
	{
		root=root->left;
	}
	return root;
}
struct node* createnode(int val)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=val;
	tmp->right=tmp->left=NULL;
	return tmp;
}
struct node * insert(struct node *root,int val)
{
	if(root == NULL)
	{
		root=createnode(val);
		return root;
	}
	else if(root->data > val)
	{
		root->left=insert(root->left,val);
	}	
	else if(root->data<= val)
	{
		root->right=insert(root->right,val);
	}
}
void inorder(struct node *root,int v1,int v2)
{
	if(root!=NULL)
	{
		inorder(root->left,v1,v2);
		if(root->data >= v1 && root->data< v2)
		
			printf("%d\t",root->data);
		inorder(root->right,v1,v2);
	}
}
int main()
{
	int val,v1,v2;
	struct node * root=NULL;
	fp=fopen("p6.txt","r");
	while((fscanf(fp,"%d",&val))!=EOF)
	{
		root=insert(root,val);
	}
	a:
	printf("\nEnter value1 ");
	scanf("%d",&v1); 
	printf("Enter value2 ");
	scanf("%d",&v2);
	if(v1>v2)
	{
			printf("value1 must less than value2");
			goto a;
	}
	printf("Value between %d and %d\n",v1,v2);
	inorder(root,v1,v2);
}
