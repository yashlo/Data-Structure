#include<stdio.h>
#define SIZE 100
int stack[SIZE];
int temp[SIZE];
void sort();
static int top=-1;
static int top2=-1;

void push(int,int[],int);
int pop();

void push(int item,int x[],int t)
{
    printf("ITEM : %d\n",item);
    printf("TOP : %d\n",t);
	if(top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		//t = t+1;
		//printf("Top : %d\n",t);
		x[t] = item;
	}
}

int pop(int p[],int tt)
{
    int item;
	if(tt <0)
	{
		printf("stack under flow:");
    }
	else
	{
		item = p[tt];
		return(item);
		//printf("\t %d : DELETE\n",item);
		//tt = tt-1;

	}
}

void sort()
{
    int x,y;
    while(top != NULL)
    {
        printf("Enter in While Loop \n");
        if(top2 == -1)
        {
            printf("Top Of Temp : \n");
            x=pop(stack,top--);
            push(x,temp,++top2);
        }
       else
        {
           x=pop(stack,top--);
           while(top2 != -1)
           {
               y=pop(temp,top2--);
               printf("POP ELEMENT : %d\n",y);
               if(x > y)
               {
                   printf("PUSH ELEMET : %d %d\n",x,y);
                   push(y,temp,++top2);
                   push(x,temp,++top2);
               }
           }

        }

    }


}
void main()
{
   int i,n,data;
   printf("Enter Number : ");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
        printf("Enter Element : ");
        scanf("%d",&data);
        push(data,stack,++top);
   }
   sort();
}
