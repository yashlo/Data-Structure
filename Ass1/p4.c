#include<stdio.h>
#include<stdlib.h>
FILE *fp;
struct node{
    int data;
    struct node *next;
}*head=NULL;
void Insert(int item)
{
    //int item;
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
        printf("Error: Assigning Memory\n");
  //  printf("Insert Data At Last : ");
    //scanf("%d",&item);
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
void removeduplicate()
{
	struct node *tmp,*curr,*del,*prev;
	tmp=head;
	while(tmp)
	{
		curr=tmp->next;
		prev=tmp;
		while(curr)
		{
			if(curr->data == tmp->data)
			{
				del=curr;
				
				prev->next=curr->next;
				curr=curr->next;
				free(del);
		
			}
			else
			{
				prev=curr;
			curr=curr->next;
				
			}
			
		}
		tmp=tmp->next;		
	}
}
void display()
{
	struct node *tmp;
	tmp=head;
	while(tmp)
	{
		printf("\n%d",tmp->data);
		tmp=tmp->next;
	}
}
int main()
{
	fp=fopen("p4.txt","r+");
	int x,c=0;
	//fscanf(fp,"%d",&x);
	while((fscanf(fp,"%d",&x))!=EOF)
	{
		Insert(x);
		c++;
	}
	printf("\n The total number of nodes are %d",c);
	printf("Link list element");
	display();
	removeduplicate();
	printf("\nLink list after remove duplicate ");
	display();
}
