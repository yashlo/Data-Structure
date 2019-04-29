//bubble sort
#include<stdio.h>

void selection_sort(int a[],int x)
{
    int i,j,temp,pos;
    for(i=0;i<x-1;i++)
    {
        pos=i;
        for(j=i+1;j<x;j++)
        {
            if(a[pos] > a[j])
            {
                pos=j;
            }
        }
        if(pos != i)
        {
            temp=a[i];
            a[i]=a[pos];
            a[pos]=temp;
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

    selection_sort(a,n);

    printf("After Sorting : \n");
    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }


}

