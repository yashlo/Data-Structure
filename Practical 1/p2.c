#include <stdio.h>
#define SIZE 15

int main()
{
   int data[SIZE], i,*ptr,sz;
   printf("Enter elements: ");

   for(i = 0; i < SIZE;i++)
     scanf("%d",&data[i]);

    ptr=data;
    sz=sizeof(data)/sizeof(data[0]);
    printf(" size : %d\n",sz);

    printf("You entered: \n");
    for(i = 0; i < SIZE; i++)
    {
        printf(" data[%d] = %d\n", i,*ptr);
        ptr++;
    }
    return 0;
}
