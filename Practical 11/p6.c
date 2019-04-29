#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
}*head=NULL;

void Insert(int val)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;

    if(head== NULL)
    {
        head=newnode;
        newnode->next=NULL;
    }
    else
    {
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;

        temp->next=newnode;
        newnode->next=NULL;
    }
}
void Bubble_Sort()
{
    struct node *i,*j,*tmp;
    int temp;
    for(i=head;i!=NULL;i=i->next)
    {
        for(j=i->next;j!=NULL;j=j->next)
        {
            if(i->data > j->data)
            {
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

}
void Display()
{
    struct node *temp;
    temp=head;
    while(temp != NULL)
    {
        printf(" | %d | - > ",temp->data);
        temp=temp->next;
    }
    printf("\n\n");
}
void main()
{
    int n,i,x;
    printf("Enter Number of Element Add in Link List : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Data : ");
        scanf("%d",&x);
        Insert(x);
    }

    printf(" Your Link List Before Sort : \n\n");
    Display();

    Bubble_Sort();

    printf(" Your Link List After Sort : \n\n");
    Display();

}
