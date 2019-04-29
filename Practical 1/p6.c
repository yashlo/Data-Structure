#include<stdio.h>
void sort(int[]);
void main()
{
    int i,a[5];
    printf("Enter Element : ");
    for(i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a);
}
void sort(int a[5])
{
    int i,j,temp;
    for(i=0;i<5;i++)
    {
        for(j=i+1;j<5;j++)
        {
            if(a[i] > a[j])
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
    for(i=0;i<5;i++)
    {
        printf("Sorted Array is : %d\n",a[i]);
    }

}
