#include<stdio.h>
#include<stdlib.h>
void mergerarray(int* ptr,int* ptr2,int n,int m)
{
    int*ptr3;
    int c=0,i,j,total=n+m;
    ptr3=(int)malloc(total*sizeof(int));
    printf("Two Array Combine : \n");
    for(i=0;i<n;i++)
    {
        ptr3[i] = ptr[i];
    }
    c=i;
    for(i=c,j=0;i<total,j<m;j++,i++)
    {
        ptr3[i] = ptr2[j];
    }
    for(i=0;i<total;i++)
    {
        printf("%d\n",ptr3[i]);
    }
}
void main()
{
    int n,m,i,j,*ptr,*ptr2,*ptr3;
    printf("Enter First Size : ");
    scanf("%d",&n);
    printf("Enter Second Size : ");
    scanf("%d",&m);
    ptr=(int*)malloc(n*sizeof(int));
    ptr2=(int*)malloc(m*sizeof(int));
    if(ptr==NULL)
    {
        printf("Error!!!");
        exit(0);
    }
        printf("Enter Element First Array : \n");
        for(i=0;i<n;i++)
        {
            scanf("%d",ptr+i);
        }
        printf("Enter Element Second Array : \n");
        for(i=0;i<m;i++)
        {
            scanf("%d",ptr2+i);
        }
        printf("First Array Element :\n");
        for(i=0;i<n;i++)
        {
            printf("%d\n",*(ptr+i));
        }
        printf("Second Array Element : \n");
        for(i=0;i<m;i++)
        {
            printf("%d\n", *(ptr2+i));
        }
        mergerarray(ptr,ptr2,m,n);
}
