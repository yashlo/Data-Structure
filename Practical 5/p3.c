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
        //exit(0);
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
    y = pop(temp,top2--);
    while(top2!=-1)
    {
        x = pop(temp,top2--);
        push(stack,x,top++);
    }
}
void display()
{
      int i;
      printf("\t");
      for(i=0;i<=top;i++)
      {
            printf(" | %d | ",stack[i]);
      }
        printf("\n");
}

void main()
{
    int ch,item;
    printf("\tQUEUE OPERATION USING STACK: \n");
    printf("\t1. INSERT\n");
    printf("\t2. DELETE\n");
    printf("\t3. DISPLAY\n");
    printf("\t4. EXIT\n");
    do{
        printf("\tEnter Your Choice : \n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\tEnter Data : ");
                scanf("%d",&item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                 break;
        }
    }while(ch!=4);
}

