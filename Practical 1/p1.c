#include<stdio.h>
void passbyreference(int*,int*);
void passbyvalue(int a,int b);
void main()
{
    int a,b;
    printf("Enter Number : ");
    scanf("%d",&a);
    printf("Enter Number : ");
    scanf("%d",&b);
    passbyreference(&a,&b);
    passbyvalue(a,b);
    getch();
}
void passbyreference(int *a,int *b)
{
    printf("Before SWAP A:%d B:%d\n",*a,*b);
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
    printf("After SWAP A: %d B: %d\n",*a,*b);
}
void passbyvalue(int a,int b)
{
    int temp;
    printf("Before SWAP A:%d B:%d\n",a,b);
    temp=a;
    a=b;
    b=temp;
    printf("After SWAP A: %d B: %d\n",a,b);
}
