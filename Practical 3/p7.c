#include<stdio.h>
int sum_of_digit(int);
int c=0;
void main()
{
    int n;
    printf("Enter number : ");
    scanf("%d",&n);
    printf("Sum of Digit is : %d\n",sum_of_digit(n));
    printf("Digit : %d",c);
}
int sum_of_digit(int n)
{
    if(n>0)
    {
        c++;
        return (n%10)+sum_of_digit(n/10);
    }
}
