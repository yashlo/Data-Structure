#include<stdio.h>
#define SIZE 100
void cal(int array[],int n,int x);
void main()
{
    int i,n,x,array[SIZE];
    printf("Enter the Order of Polynomial : ");
    scanf("%d",&n);
    printf("Enter Value of X : ");
    scanf("%d",&x);
    printf("Enter Equation : ");
    for(i=0;i<=n;i++)
    {
        scanf("%d",&array[i]);
    }
    cal(array,n,x);
}
void cal(int array[],int n,int x)
{
    int i,sum,power;
    sum=array[0];
    for(i=1;i<=n;i++)
    {
        sum=sum*x+array[i];
    }
    printf("sum of Equation : %d \n",sum);
    power=n;
    for(i=0;i<=n;i++)
    {
        printf("%d^%d",array[i],power--);
        if(power < 0)
        {
            break;
        }
        else if(array[i] > 0)
            printf(" + ");
        else if(array[i] < 0)
            printf(" - ");
        else
            printf(" ");
    }
}


