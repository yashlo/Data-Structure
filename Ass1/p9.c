#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int val;
	struct Node *next;
}*f=NULL,*r=NULL;
FILE *fp;
void enqueue(int va)
{
	struct Node *newnode;
	newnode=(struct Node *)malloc(sizeof(struct Node));
	newnode->val=va;
	newnode->next=NULL;
	if(r==NULL)
	{
		r=newnode;
		f=newnode;
	}
	else
	{
		r->next=newnode;
		r=newnode;
	}
	printf("Value inserted %d",va);
}
int dequeue()
{
	struct Node *newnode=f;
	int tmp;
	if(f==NULL)
		printf("Queue empty");
	else
	{
		tmp=f->val;
		if(f->next==NULL)
			f=r=NULL;
		else
			f=f->next;
	}
	free(newnode);
	return tmp;		
	
}
void display()
{
	struct Node *tmp=f;
	if(tmp==NULL)
		printf("Queue empty");
	else
	{
	
		while(tmp)
		{
			printf("%d\t",tmp->val);
			tmp=tmp->next;
		}
	}
}
int main()
{
	int ch,val;
	fp=fopen("p9.txt","r");
	while(1)
	{
		printf("\n---------menu---------");
		printf("\n1.Insert \n2.delete\n3.display\n4.Exit\n");
		printf("Enter choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1 :
				if((fscanf(fp,"%d",&val))==EOF)
				{
					printf("No data availble in file for push");
					break;
				}
				enqueue(val);
				break;
			case 2:
				val=dequeue();
				printf("\nDeleted valude = %d",val);
				break;
			case 3:
				display();
				break;
			case 4:
				exit(1);
				break ;
			default :
				printf("Invalid choice try again ");
				break;		
		}	
	}	
}

