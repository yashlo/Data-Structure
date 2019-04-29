#include<stdio.h>
#include<math.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
int level=1;
int totalnodes=1;
FILE *fp;
struct node* create(int val)
{
	struct node *tmp;
	tmp=(struct node *)malloc(sizeof(struct node));
	tmp->data=val;
	tmp->right=tmp->left=NULL;
	return tmp;
}
struct node * q[10];
int front=-1;
int rear=-1;
int isempty()
{
	if(front==-1)
		return 1;
	else
		return 0;
}
void enqueue(struct node *s)
{
	if(rear>=10)
		return;
	if(rear==-1)
	{
		rear=front=0;
		q[rear]=s;
	}
	else
	{
		rear++;
		q[rear]=s;
	}
}
struct node* dequeue()
{
	struct node *tmp=NULL;	
	if(front==-1)
		return tmp;
	else
	{
		tmp=q[front];
		if(front==rear)
			front=rear=-1;
		else
			front++;
		return tmp;
	}
	
}
struct node * levelorderinsert(struct node *root,int val)
{
	front=rear=-1;
	struct node *tmp=root;		
	enqueue(tmp);
	while(!isempty())
	{
		tmp=dequeue();
		if(tmp->left==NULL)
		{
			tmp->left=create(val);
			break;
		}
		else
			enqueue(tmp->left);
		if(tmp->right==NULL)
		{
			tmp->right=create(val);
			break;	
		}	
		else
			enqueue(tmp->right);		
	}
}
void levelorder(struct node *root)
{
	front=rear=-1;
	struct node *tmp=root;
	enqueue(tmp);
	while(!isempty())
	{
		tmp=dequeue();
		if(tmp->left!=NULL)
			enqueue(tmp->left);
		if(tmp->right!=NULL)
			enqueue(tmp->right);
		printf("%d\t",tmp->data);
	}
}
void preorder(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);	
		preorder(root->right);
	}
}
int leveloftree(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	else
	{
			int left=leveloftree(root->left);
			int right=leveloftree(root->right);
			if(left>right)
				return left+1;
			else
				return right+1;
	}	
}
int main()
{
	fp=fopen("p7.txt","r");
	struct node *root;
	int val;
	fscanf(fp,"%d",&val);
	root=create(val);	
	while((fscanf(fp,"%d",&val))!=EOF)
	{		
			levelorderinsert(root,val);	
			totalnodes++;
	}
	printf("Binary tree created \n");
	printf("Level order traversal of binary tree\n");	
	levelorder(root);
	fclose(fp);
	printf("\nNumber of level in tree : ");
	printf("%d",leveloftree(root));
	printf("\nTotal node in binary tree : ");
	printf("%d",totalnodes);
	if(pow(2,leveloftree(root))-1 == totalnodes)
		printf("\nBinary tree is completed\n");
	else
		printf("\nBinary tree is not completed\n");	
	
}
