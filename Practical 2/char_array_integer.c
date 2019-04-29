#include<stdio.h>
#include<stdlib.h>
void convert(char *ar)
{
    int num=0,i;

    for(i=0;i<ar[i]!='\0';i++)
    {
        num=num*10+ar[i]-'0';
    }

    if(num & 1 == 1)
        printf("Is odd!");
    else
        printf("Is even");
}
int main()
{
    char *arr;
    arr=(char*)calloc(50,sizeof(char));
    printf("Enter number: ");
    scanf("%s",arr);
    convert(arr);

}
