#include<stdio.h>
#define N 1000
FILE *fp;
int a[N];
int top=-1;
int isempty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int isfull()
{
	if(top==N-1)
		return 1;
	else 
		return 0; 
}
void push(int val)
{
		if(isfull()==1)
		{
			printf("\nStack is overflow");
		}
		else
		{
			top++;
			a[top]=val;
			display();
			
		}
}
int pop()
{
	int tmp;
	if(isempty()==1)
	{
		printf("\nStack is underflow");

		return -1;
	}
	else
	{
		tmp=a[top];
		top--;
		return tmp;
	}	
}
int  peek(int i)
{
	if(top+1-i<0)
		printf("\n Stack underflow");
	else
		return a[top+1-i];
}
void change(int i,int val)
{
	
	if(top+1-i<0)
		printf("\n Stack underflow");
	else
		 a[top+1-i]=val;	
}
void display()
{
	int i;
	if(isempty()==1)
		printf("Stack undeflow");
	else
	{
		for(i=top;i>=0;i--)
		{
			printf("%d \t",a[i]);
		}
	}
}
void main()
{
	int ch,val,i;
	fp=fopen("p10.txt","r");
	while(1)
	{
		printf("\n----Menu-----");
		printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.peek");
		printf("\n4.change");
		printf("\n5.display");
		printf("\n6.Exit");
		printf("\nEnter choice : ");
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
				val=pop();
				if(val!=-1)
					printf("Poped value : %d ",val);

				break;
			case 3:
				printf("\nEnter position : ");
				scanf("%d",&i);
				printf("\npeeked value : %d",peek(i));
				break;
			case 4:
				printf("\nEnter position : ");
				scanf("%d",&i);
				printf("\nEnter new value : ");
				scanf("%d",&val);
				change(i,val);
				break;
			case 5:
				display();
				break;
			case 6:
					exit(0);
					break;
			default:
				printf("\nInvalid choice : ");
				break;	
				
		}
		
	}
}
	
