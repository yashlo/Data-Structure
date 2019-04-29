#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;
void push()
{
    int item;
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter Data for Push : ");
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
void pop()
{
    struct node *temp;
    temp=head;
    if(head ==  NULL)
        printf("STACK IS EMPTY\n");
    head=temp->next;
    free(temp);

}
void display()
{
    struct node *temp;
    temp=head;
    if(head == NULL)
    {
        printf("STACK IS EMPTY\n");
    }
    while(temp != NULL)
    {
        printf(" | %d |\n",temp->data);
        temp=temp->next;
    }
}
void main()
{
    int ch;
    printf("STACK OPERATION USING LINK LIST\n");
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    do{
        printf("Enter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Enter Proper Choice : \n");
                break;
        }
    }while(ch!=4);
}
