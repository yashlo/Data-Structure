//bubble sort recursion
#include<stdio.h>
void bubble_sort(int a[],int x)
{
    int i,temp;
    if(x > 0)
    {
        for(i=1;i<x;i++)
        {
            if(a[i-1] > a[i])
            {
                temp=a[i];
                a[i]=a[i-1];
                a[i-1]=temp;
            }
        }
        bubble_sort(a,x-1);
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
