#include<stdio.h>
int fact(int n);
int main()
{
    int n,ans;
    printf("Enter Number :");
    scanf("%d",&n);
    ans=fact(n);
    printf("Factorial : %d",ans);
}
int fact(int x)
{
    if(x==1)
    {
        return 1;
    }
    else
    {
        return x*fact(x-1);
    }
}
