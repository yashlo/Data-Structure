#include<stdio.h>
#include<stdlib.h>
void array(int n,int *ptr)
{
    int i,j,temp;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ptr[i] < ptr[j])
            {
                temp=ptr[i];
                ptr[i]=ptr[j];
                ptr[j]=temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ptr[i+1] > ptr[j+1])
            {
                temp=ptr[i+1];
                ptr[i+1]=ptr[j+1];
                ptr[j+1]=temp;
            }
        }
    }
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf(" DATA[%d] = %d\n",i,ptr[i]);
    }
}
void main()
{
    int n,*ptr,i;
    printf("Enter number : ");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    printf("Enter The Element : \n");
    for(i=0;i<n;i++)
    {
        printf(" DATA[%d] = ",i);
        scanf("%d",&ptr[i]);
    }
    array(n,ptr);
}
