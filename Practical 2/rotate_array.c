#include<stdio.h>
#include<stdlib.h>
int rotate(int *a,int d,int size)
{
    //rotate array from one two second
    int i,j,*temp;
    temp=(int*)malloc(size*sizeof(int));

    for(i=d,j=0;i<size,j<size;i++,j++)
    {
        temp[j]=a[i];
    }

    //change renaming index value
    for(i=0,j=size-d;i<d,j<size;i++,j++)
    {
        temp[j]=a[i];
    }

    for(i=0;i<size;i++)
    {
        printf("ROTATE [%d] = %d\n",i,temp[i]);
    }
}
void main()
{
    int *a,n,i,j,size;
    //size of array
    printf("Enter Size of Array : \n");
    scanf("%d",&size);

    a=(int*)malloc(size*sizeof(int));

    printf("Enter Data : \n");
    for(i=0;i<size;i++)
    {
        printf("[%d] = ",i);
        scanf("%d",&a[i]);
    }

    printf("Enter Element to rotate : ");
    scanf("%d",&n);
    rotate(a,n,size);
}
