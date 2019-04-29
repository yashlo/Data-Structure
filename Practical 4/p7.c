#include<stdio.h>
#include<string.h>
#define MAX 100

int top = -1;
char stack[MAX];

char push(char item)
{
	if(top >= MAXtop >= SIZE-1)top >= SIZE-1)top >= SIZE-1)top >= SIZE-1)   -1)
		printf("Stack Overflow\n");
	else
	{
        top = top + 1;
		stack[top] =item;
	}
}

char pop()
{
	if(top == -1)
		printf("Stack Underflow\n");
	else
		return stack[top--];
}

void main()
{
	char str[20];
	int i;
	printf("Enter the string : " );
	gets(str);
	for(i=0;i<strlen(str);i++)
		push(str[i]);

}
//hello395world216
