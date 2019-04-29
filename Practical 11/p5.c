#include<stdio.h>

int bubble_sort(int a[],int x)
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
int binary_search(int d[],int n,int si,int ei,int val)
{
    int i,beg=si,end=ei,mid,flag=0;
    mid=(beg+end)/2;
    //printf("Middle Value %d : ",d[mid]);
    if(val > d[mid])
    {
        for(i=mid;i<=ei;i++)
        {
            if(d[i] == val)
                flag=1;

        }
    }
    else if(val < d[mid])
    {
        for(i=si;i<=mid;i++)
        {
            if(d[i] == val)
                flag=1;
        }
    }
    return flag;
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

    //sort the array using bubble sort
    bubble_sort(a,n);

    int data;
    printf("Enter Search Data : ");
    scanf("%d",&data);
    //provide sort array in search function.
    int flag = binary_search(a,n,0,n-1,data);

    if(flag == 1)
    {
        printf("Your Value %d Will Found : \n",data);
    }
    else
    {
        printf("Your Value %d Will Not found : \n",data);
    }

}
