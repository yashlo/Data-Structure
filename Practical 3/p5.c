#include<stdio.h>
int power(int,int);
void main()
{
    int n,p;
    printf("Enter Number : ");
    scanf("%d",&n);
    printf("Enter Power : ");
    scanf("%d",&p);
    printf("Power is %d",power(n,p));
}
int power(int x,int p)
{
    if(p!=0)
    {
        return(x*power(x,p-1));
        //return 1;
    }
    else{
        return 1;
    }
}
