#include<stdio.h>
#include<stdlib.h>
void main()
{
    int i,n,*a,temp;
    printf("Enter Size of Array : ");
    scanf("%d",&n);
    a=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        if(i%2 == 0)
        {
            if(a[i] > a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
            //printf("First Condition : %d\n",a[i]);
        }
        else{

            if(a[i] < a[i+1])
            {
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                //printf("Second Condition  : %d\n",a[i]);
            }
        }

    }
    printf("Rearange the array as per condition : \n");

    for(i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}
