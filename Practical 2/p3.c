#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void reverse(char *str)
{
    char *rev;
    int i,c=0,end;
    while(str[c]!='\0')
        c++;

    rev=(char*)malloc(c*sizeof(char));

    end=c-1;

    for(i=0;str[i]!='\0';i++)
    {
        rev[i]=str[end];
        end--;
    }
    rev[i]='\0';
    printf("Reverse String is : %s",rev);
}
void main()
{
    char *str;
    str=(char*)malloc(10*sizeof(char));
    printf("Enter String : ");
    gets(str);
    reverse(str);
}
