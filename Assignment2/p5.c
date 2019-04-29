#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *left;
	int data;
	struct node *right;
};
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
int main()
{
	fp=fopen("p5.txt","r");
	struct node *root;
	int val;
	fscanf(fp,"%d",&val);
	root=create(val);	
	while((fscanf(fp,"%d",&val))!=EOF)
	{		
			levelorderinsert(root,val);	
	}
	printf("Binary tree created \n");
	printf("Level order traversal of binary tree\n");	
	levelorder(root);
	printf("\nPre order traversal of binary tree\n");
	preorder(root);
	fclose(fp);
}
