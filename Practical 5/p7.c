#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int temp[SIZE];
int top=-1;
int top2=-1;

void push(int s[],int data,int p)
{
    if(p >= SIZE)
    {
        printf("\tQueue is Overflow \n");
    }
    else
    {
        p++;
        s[p] = data;
    }
}
int pop(int s[],int p)
{
    int d;
    if(p == -1)
    {
        printf("\tQueue is underflow\n");
        exit(0);
    }
    else
    {
        d = s[p];
        p--;
        return d;
    }
}
void enqueue(int n)
{
    push(stack,n,top++);
}
int dequeue()
{
    int x,y;
    while(top!=-1)
    {
        x = pop(stack,top--);
        push(temp,x,top2++);
    }
   // y = pop(temp,top2--);
    while(top2!=-1)
    {
        x = pop(temp,top2--);
        push(stack,x,top++);
    }
    //printf("\tpop from temp : %d\n",y);
}
void display()
{
      int i;
      printf("\t");
      for(i=top;i>=0;i--)
      {
            printf(" | %d | ",stack[i]);
      }
        printf("\n");
}

void main()
{
    int n,data;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter Data : ");
        scanf("%d",&data);
        enqueue(data);
    }
    printf("Reverse Queue : \n");
    display();
}

