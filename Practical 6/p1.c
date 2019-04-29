#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;

void Insert_First()
{
    int item;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data For Insert At First :  ");
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
void Insert_Last()
{
    int item;
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
        printf("Error: Assigning Memory\n");
    printf("Insert Data At Last : ");
    scanf("%d",&item);
    newnode->data=item;
    temp=head;
    if(head == NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
         while(temp->next != NULL)
         {
            temp=temp->next;
         }
         temp->next=newnode;
         newnode->next=NULL;
    }

}

void Insert_Specific()
{
    int search,item;
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));

    printf("Enter Where You Insert New Node : ");
    scanf("%d",&search);

    printf("Enter Data : ");
    scanf("%d",&item);

    temp=head;
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY \n");
    }
    else
    {
        while(temp != NULL)
        {
            if(temp->data == search)
            {
                newnode->next=temp->next;
                temp->next=newnode;
                newnode->data=item;
                printf("DATA SUCESSFULL INSERT\n");
            }
            temp=temp->next;
        }
    }
}
void Delete_First()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    temp=head;
    head=temp->next;
    free(temp);
}
void Delete_Last()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("LIST IS EMPTY\n");
    }
    temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=NULL;
}
void Delete_Specific()
{
    int search;
    struct node *temp,*temp1;
    temp=head;
    printf("Enter Which Element You delete : ");
    scanf("%d",&search);
    while(temp->data != search)
    {
        temp1=temp;
        temp=temp->next;
    }
    printf("DELETED NODE : %d\n",temp->data);
    temp1->next=temp->next;
    free(temp);
}
void Display()
{
    struct node *temp;
    temp=head;
    if(head == NULL)
    {
        printf("LINK LIST IS EMPTY\n");
    }
    while(temp != NULL)
    {
        printf(" | %d |->",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    int ch;
    printf("\t---------------------\n");
    printf("\tLINKED LIST OPERATION\n");
    printf("\t1.INSERT_AT_BEGINNING\n");
    printf("\t2.INSERT_AT_LAST\n");
    printf("\t3.INSERT_AT_SPECIFIC\n");
    printf("\t4.DELETE_AT_BEGINNING\n");
    printf("\t5.DELETE_AT_LAST\n");
    printf("\t6.DELETE_AT_SPECIFIC\n");
    printf("\t7.DISPLAY\n");
    printf("\t8.EXIT\n");
    printf("\t---------------------\n");
    do{
        printf("ENTER YOUR CHOICE : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                Insert_First();
                break;
            case 2:
                Insert_Last();
                break;
            case 3:
                Insert_Specific();
                break;
            case 4:
                Delete_First();
                break;
            case 5:
                Delete_Last();
                break;
            case 6:
                Delete_Specific();
                break;
            case 7:
                Display();
                break;
            case 8:
                break;
            default:
                printf("ENTER PROPER CHOICE \n");
                break;
        }
    }while(ch!=8);
}
