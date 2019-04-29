#include<stdio.h>
#include<stdlib.h>
void  str_find(char *str,int n,char *c)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if(i == n)
        {
            str[i]=c;
        }
    }
    printf("\n Change String is %s",str);
}

void main()
{
    char *str,*c;
    int n;
    str=(char*)malloc(50*sizeof(char));
    printf("\n Enter String : ");
    gets(str);
    printf("\n Enter index no : ");
    scanf("%d",&n);
    printf("\n Enter Replace Character  : ");
    scanf("%s",&c);
    str_find(str,n,c);
}
