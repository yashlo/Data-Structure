#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
}*head;
int c=0;
FILE *fp;

void push(int val)
{
	struct Node *new=(struct Node *)malloc(sizeof(struct Node));
	new->data=val;
	new->next=head;
	head=new;
	c++;
}
int pop()
{
	int val=0;
	if(head==NULL)
		printf("Stack underflow");
	else
	{
		struct Node *tmp=head;
		val=tmp->data;
		head=tmp->next;
		free(tmp);
	}
	return val;
}
void display()
{
	if(head==NULL)
		printf("Stack underflow");
	else
	{
		struct Node *tmp=head;
		while(tmp!=NULL)
		{
			printf("%d\t",tmp->data);
			tmp=tmp->next;
		}
	}	
}
int peek(int i)
{
	if(c-i<0)
		printf("stack underflow\n");
	else
	{
		struct Node *tmp=head;
		int j;
		for(j=1;j<i;j++)
		{
			tmp=tmp->next;
		}
		return tmp->data;
	}
}
void change(int i,int val)
{
	if(c-i<0)
		printf("stack underflow\n");
	else
	{
		struct Node *tmp=head;
		int j;
		for(j=1;j<i;j++)
		{
			tmp=tmp->next;
		}
		tmp->data=val;
		printf("\nValue changed !");
	}
}
int main()
{
	int ch=1,val,new;
	fp=fopen("p8.txt","r");
	while(ch!=0)
	{
		printf("\n1.push\n2.pop\n3.disply\n4.peek\n5.change\n0.break");
		printf("\nEnter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				
				if((fscanf(fp,"%d",&val))==EOF)
				{
					printf("No data availble in file for push");
					break;
				}	
				push(val);
				break;
			case 2:
				printf("popped value %d",pop());
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Enter position of  peek value ");
				scanf("%d",&val);
				printf("Peeked value : %d",peek(val));
				break;
			case 5:
				printf("Enter postion of value want to change");
				scanf("%d",&val);
				printf("Enter new value");
				scanf("%d",&new);
				change(val,new);
				break;
			
		}
	}
	
}
