#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*head=NULL;

void Insert()
{
    int item;
    struct node *temp,*newnode,*mid;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\tInsert Data : ");
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

void Delete()
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
        printf(" | %d | -> ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int cnt=0;
int Length(struct node* temp)
{
    if(temp == NULL)
        return 0;
    else
    {
        cnt++;
        return Length(temp->next);
    }
}
//iterative Method
void Find_len()
{
    struct node *temp;
    int c=0;
    temp=head;
    while(temp != NULL)
    {
             c++;
             temp=temp->next;
    }
    printf("\tLENGTH OF LINK LIST  : %d\n",c);
}


void main()
{
    int ch;
    printf("\tLINK LIST FIND MIDDLE VALUE\n");
    printf("\t1.INSERT\n");
    printf("\t2.DELETE\n");
    printf("\t3.DISPLAY\n");
	printf("\t4.FIND LENGTH\n");
    printf("\t5.EXIT\n");
    do{
        printf("\n\tEnter Your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                Insert();
                break;
            case 2:
                Delete();
                break;
            case 3:
                Display();
                break;
            case 4:
				Length(head);
				break;
			case 5:
                break;
            default:
                printf("Enter Proper Choice : \n");
                break;
        }
    }while(ch!=5);
}



