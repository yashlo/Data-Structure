//bubble sort
#include<stdio.h>
void bubble_sort(int a[],int x)
{
    int i,j,temp;
    for(i=0;i<x-1;i++)
    {
        for(j=0;j<x-i-1;j++)
        {
            if(a[j] > a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

}
void main()
{
    int a[10],n,i;
    printf("Enter Number of Element : ");
    scanf("%d",&n);
    printf("Enter Element : \n");
    for(i=0;i<n;i++)
    {
        printf("[%d] - > ",i);
        scanf("%d",&a[i]);
    }
    printf("Before  Sorting : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }

    bubble_sort(a,n);

    printf("After Sorting : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }


}
