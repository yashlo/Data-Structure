
#include<stdio.h>
int fibonacci(int n);
void main()
{
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    printf("Number is %d",fibonacci(n));
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
    }
}
