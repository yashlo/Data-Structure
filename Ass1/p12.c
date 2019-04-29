#include<stdio.h>
#include<string.h>
#define N 10
char a[N];
int top=-1;
FILE *fp;
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
void push(char val)
{
		if(isfull()==1)
		{
			printf("\nStack is overflow");
		}
		else
		{
			top++;
			a[top]=val;			
		}
}
char pop()
{
	char tmp;
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
void main()
{
	char *original,c,*reverse;
	int i=0,flag=0;
	fp=fopen("p12.txt","r");
	printf("original string :");
	fscanf(fp,"%s",original);
	while(original[i] != '\0')
	{
		push(original[i]);
		printf("%c",original[i]);
		i++;	
	}
	i=0;
	printf("\nReverse string : ");
	while(!isempty())
	{
		c=pop();
		printf("%c",c);
		reverse[i]=c;
		i++;
	}
	i=0;
	while(original[i]!='\0' && reverse[i]!='\0')
	{
		printf("%c - %c\n",original[i],reverse[i]);
		if(original[i] != reverse[i])
		{
			flag=1;
			break;
		}
		i++;
	}
	if(flag==1)
		printf("\nString is not palindogram ");
	else
		printf("\nString is palindogram");
}
