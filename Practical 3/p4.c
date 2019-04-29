#include<stdio.h>
int gcd(int,int);
void main()
{
    int n1,n2;
    printf("Enter n1 and n2:");
    scanf("%d %d",&n1,&n2);
    printf("GCD : %d",gcd(n1,n2));
}
int gcd(int x1,int x2)
{
    if(x2!=0)
    {
        return gcd(x2,x1%x2);
    }
    else
    {
        return x1;
    }
}
