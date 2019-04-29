#include<stdio.h>
#define SIZE 100
int queue[SIZE];
int front=-1;
int rear=-1;

void insert()
{
    int data;
    printf("\t Enter Data : ");
    scanf("%d",&data);

    if(rear == -1)
        front=0;

    if(rear > SIZE)
        printf("\tQueue is Overflow  : \n");
    else
    {
        rear++;
        queue[rear]=data;
    }
}
void Delete()
{
    if(front > rear)
        printf("\tQueue is Underflow : \n");
    else
    {
        printf("\tDelete : %d\n",queue[front]);
        front++;
    }
}
void Display()
{
    int i;
    if(rear == -1 || front > rear)
        printf("\tQueue is Empty \n");
    //printf("Rear : %d\n",rear);
    //printf("Front : %d\n",front);
    printf("\t");
    for(i=front;i<=rear;i++)
        printf("| %d | ",queue[i]);
    printf("\n");
}
void main()
{
    int ch;
    printf("\tQUEUE OPERATION USING ARRAY\n");
    printf("\t 1. INSERT\n");
    printf("\t 2. DELETE\n");
    printf("\t 3. DISPLAY\n");
    printf("\t 4. EXIT\n");
    do{
        printf("\tEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
            case 4:
                return;
            default:
                printf("\tEnter Proper Choice \n");
                break;
        }
    }while(ch !=4);
}
