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
struct node* Find_mid()
{
    // printf("Inside Find Mid \n");
    // int mid;
    struct node *temp,*temp1;
    temp=head;
    temp1=head;
    while(temp->next->next != NULL)
    {
             temp=temp->next->next;
             temp1=temp1->next;
             //printf("inside loop\n");
    }
    //printf("MID POINT : %d\n",temp1->data);
    return temp1;
}
int Binary_Search(int val)
{
    struct node *mid,*i,*j;
    int flag=0;
    Bubble_Sort();
    mid=Find_mid();
    //printf("MIDDLE VALUE : %d\n",mid->data);
    if(val < mid->data)
    {
        for(i=head;i!= mid;i=i->next)
        {
            if(val == i->data)
                flag=1;
        }
    }
    else if( val > mid -> data)
    {
        for(j=mid;j!=NULL;j=j->next)
        {
            if(val == j->data)
                flag=1;
        }
    }
    return flag;

}
void main()
{
    int n,i,x,ser;
    printf("Enter Number of Element Add in Link List : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter Data : ");
        scanf("%d",&x);
        Insert(x);
    }

    //Display();
    //Find_mid();
    printf("Enter Search Value : ");
    scanf("%d",&ser);
    int res = Binary_Search(ser);
    if(res == 1)
        printf("Your Search Value %d is Found \n",ser);
    else
        printf("Your Search Value %d is Not Found \n",ser);

}
