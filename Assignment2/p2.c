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
int search(int a)
{
	int i,j;
	struct node *temp;
	temp=head;
	for(i =0;i<a;i++)
	{
		temp=temp->next;
	}
	j=temp->data;
	return j;
}
void printPowerSet(int set_size) 
{ 
	int pow_set_size = pow(2, set_size); 
    int counter, j; 
  
   
    for(counter = 0; counter < pow_set_size; counter++) 
    { 
      for(j = 0; j < set_size; j++) 
       { 
          
          if(counter & (1<<j)) 
            printf("%d", search(j)); 
       } 
       printf("\n"); 
    } 
} 
int main()
{
	fp=fopen("p2.txt","r+");
	int x,c=0;
	//fscanf(fp,"%d",&x);
	while((fscanf(fp,"%d",&x))!=EOF)
	{
		Insert(x);
		c++;
	}
	printf("The total number of nodes are %d",c);
	int k;
	//k=search(3);
	printPowerSet(c);
	//printf("%d",k);
}

