#include<stdio.h>
#include<stdlib.h>
char s[100],m;
int top=-1,n=100;
FILE *fp;


void push(char m)
{

	if(top>=n-1)
	{
		printf("\n Stake is overflow");
	}
	else
	{
		top++;
		s[top]=m;
	}
}
void pop()

{

	if (top == -1)

	{

		printf("expression is invalid\n");

		exit(0);

	}	

	else

	{		

		top--;

	}

}
    void find_top()

    {

    	if (top == -1)

    		printf("\nexpression is valid\n");

    	else

    		printf("\nexpression is invalid\n");

    }


int main()
{
	char d;
	fp=fopen("p3.txt","r+");
	while((fscanf(fp,"%c",&d))!=EOF)
	{
		if (d == '(')

		{

			push(d);

		}

		else if (d == ')')

		{

			pop();

		}
		//push(d);
	}
	find_top();
}


