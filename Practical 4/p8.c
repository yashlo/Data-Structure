//Sort using Recursion
#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int);
int reverseInsert(int);
int reverse();
int pop();

void main(void)
{
    int n,i,data;
    printf("Enter Number of Element Insert in Stack : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Data : ");
        scanf("%d",&data);
        push(data);
    }
    reverse();
    printf("\n\n");
    while(!isEmpty())
    {
        printf("\t %d\n",stack[top]);
        pop();
    }

}
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int item)
{
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		top = top+1;
		stack[top] = item;
	//	printf("PUSH : %d\n",item);
	}
}

int pop()
{
    int item;
	if(top <0)
	{
		printf("stack under flow:");
    }
	else
	{
		item = stack[top];
		//printf("\t %d : DELETE\n",item);
		top = top-1;
		return(item);
	}
}
int reverseInsert(int x)
{
    if (isEmpty())
    {
        push(x);
    }

    int temp = pop();
    reverseInsert(x);
    push(temp);
}

int reverse()
{

    if (isEmpty())
    {
        int x = pop();
      //  printf("POP : %d\n",x);
        reverse();
        //printf("Value : %d\n",x);
        reverseInsert(x);
    }
}

