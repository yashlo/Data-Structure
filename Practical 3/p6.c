#include<stdio.h>
int sum(int);
void main()
{
    int n;
    printf("Enter number :");
    scanf("%d",&n);
    printf("Sum is %d",sum(n));
}
int sum(int n)
{
    if(n>0)
    {
        return n+sum(n-1);
    }
}
