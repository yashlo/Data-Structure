#include<stdio.h>
#define size 5
int queue[size];
int front=-1;
int rear=-1;


void insert()
{
    int data;
    printf("\tEnter Data :");
    scanf("%d",&data);
    if ((front == 0 && rear == size-1) ||  (rear == (front-1)%(size-1)))
    {
        printf("\n\tQueue is Full\n");
        return;
    }

    else if (front == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        queue[rear] = data;
    }

    else
    {
        rear++;
        queue[rear] = data;
    }
}

void Delete()
{
    if (front == -1)
    {
        printf("\nQueue is Empty\n");
    }

    int data = queue[front];
    printf("\t %d : DELETED\n",data);
	//queue[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;
}

void Display()
{
    if (front == -1)
    {
        printf("\n\tQueue is Empty\n");
        return;
    }
    printf("\n\tElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",queue[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", queue[i]);

        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
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
