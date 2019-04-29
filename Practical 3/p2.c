#include<stdio.h>
int fibonacci(int n);
void main()
{
    int n,i,f=0;
    printf("Enter number : ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("%d ",fibonacci(f));
        f++;
    }
}
int fibonacci(int x)
{
    if(x==1)
    {
        return 1;
    }
    else if(x==0)
    {
        return 0;
    }
    else
    {
        return fibonacci(x-1)+fibonacci(x-2);
        //printf("%d",x);
    }
}
