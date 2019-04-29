#include<stdio.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int);
int pop();
void display();
void main()
{
    int ch,data;
    printf("\t 1. PUSH\n");
    printf("\t 2. POP\n");
    printf("\t 3. DISPLAY\n");
    printf("\t 4. EXIT\n");
    do{
        printf("\t Enter Your Choice \n");
        scanf("\t %d",&ch);
        switch(ch)
        {
            case 1:
                printf("\t Enter Data : ");
                scanf("%d",&data);
                push(data);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default :
                printf("\t Enter Proper Choice \n");
                break;
        }
    }while(ch!=4);
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
		printf("\t %d : DELETE\n",item);
		top = top-1;
		return(item);
	}
}
void display()
{
    if(top==-1)
    {
        printf("\tSTACK IS EMPTY\n");
    }
    int i;
    for(i=top;i>=0;i--)
    {
        printf("\t| %d |\n",stack[i]);
    }
}
