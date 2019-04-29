#include<stdio.h>
int array(int[],int);
void main()
{
    int i,n,a[5];
    printf("Enter number :");
    scanf("%d",&n);
    printf("Enter Array Element : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    array(a,n);
    //printf("Array is : %d",array(a,n));
    printf("\n");
}
int array(int a[5],int n)
{
   static i=0;
   if(n==0)
   {
       return;
   }
   else{
        printf("%d\n",*a);
        n--;
        array(&a[i+1],n);
   }
}
