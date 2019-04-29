#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
void insert()
{
    int item;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\tEnter Data : ");
    scanf("%d",&item);
    newnode->data=item;
    if(head == NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
}
void Delete()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("\tQueue is Empty \n");
    }
    temp=head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
    {
        printf("\tQueue is Empty \n");
    }
    printf("\t");
    while(temp != NULL)
    {
        printf("| %d | -> ",temp->data);
        temp=temp->next;
    }
    printf(" |\n");
    printf("\n");
}
void main()
{
    int ch;
    printf("\t1.INSERT\n");
    printf("\t2.DELETE\n");
    printf("\t3.DISPLAY\n");
    printf("\t4.EXIT\n");
    do{
        printf("\n\tEnter Your Choice : ");
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
                display();
                break;
            case 4:
                break;
            default:
                printf("\tEnter proper choice :\n");
                break;
        }
    }while(ch!=4);
}

