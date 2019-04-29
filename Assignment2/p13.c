#include<stdio.h>
#include<stdlib.h>
FILE *fp;
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int data)
{
    int i;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        if(head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;

            /*
             * Create rest of the n-1 nodes
             */
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));

                if(newNode != NULL)
                {
                  //  printf("Enter data of %d node: ", i);
                    //scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last; // Link new node with the previous node
                    newNode->next = NULL;

                    last->next = newNode; // Link previous node with the new node
                    last = newNode;          // Make new node as last/previous node
                }
                else
                {
                    printf("Unable to allocate memory.");
                    break;
                }
            }

            printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        }
        else
        {
            printf("Unable to allocate memory");
        }
    }
}


/**
 * Displays the content of the list from beginning to end
 */
void displayListFromFirst()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;
            
            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}

int main()
{
fp = fopen("p13.txt","r+");
	int x,c=0;
	//fscanf(fp,"%d",&x);
	while((fscanf(fp,"%d",&x))!=EOF)
	{
		createList(x);
		c++;
	}
	printf("The total number of nodes are %d",c);
}
