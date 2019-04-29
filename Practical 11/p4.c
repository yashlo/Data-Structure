//linear search
#include<stdio.h>
int Linear_Search(int a[],int x,int item)
{
    int i,flag=0;
    //printf("data for search %d\n",item);
    for(i=0;i<x;i++)
    {
        if(a[i] == item)
            flag = 1;
    }
    if(flag == 1)
        return 1;
}
void main()
{
    int a[10],n,i,data,s;
    printf("Enter Number of Element : ");
    scanf("%d",&n);
    printf("Enter Element : \n");
    for(i=0;i<n;i++)
    {
        printf("[%d] - > ",i);
        scanf("%d",&a[i]);
    }

    printf("Enter Data For Search : ");
    scanf("%d",&data);

    s = Linear_Search(a,n,data);
   // printf("Return Value %d\n",s);
    if(s == 1)
        printf("Data is Found \n");
    else
        printf("Data is Not Found\n");
}

