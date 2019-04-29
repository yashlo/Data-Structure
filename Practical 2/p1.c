#include <stdio.h>
#include<process.h>
void Length(char str[10])
{
    int i, length = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    printf("\n The length of %s = %d", str, length);
}
void Copy(char str[10])
{
    char str1[10];
    int i;
    for(i=0;str[i] != '\0';i++)
    {
        str1[i]=str[i];
    }
    printf("\n %s Copy in new string : ",str);
}
void Compare(char str[10],char nstr[10])
{
    int i=0;
    while(str[i] != '\0')
     {
        if(str[i] > nstr[i])
        {
            printf("\n str1 > str2");
            break;
        }
        else if (str[i] < nstr[i])
        {
            printf("\n str1 < str2");
            break;
        }
        else
            printf("\n str1 = str2");
            break;
        i++;
     }
}
void Concate(char str[10],char nstr[10])
{
    char con[200];
    int i,j,k, length = 0,length1=0,total;
    for (i = 0; str[i] != '\0'; i++)
    {
        length++;
    }
    for (i = 0; nstr[i] != '\0'; i++)
    {
        length1++;
    }
    total=length+length1;
    for(i=0;i<length;i++)
    {
            con[i]=str[i];
    }
    //printf("%d",i);
    for(i=0;i<total;i++)
    {
        con[i+length]=nstr[i];
    }
    printf("\n The Concatenation String is :  %s\n",con);
}

void main()
{
    char string[50],newstr[10],newstr1[10];
    printf("Enter a string \n");
    gets(string);
    Length(string);
    Copy(string);
    printf("\n Enter New String For Comparing : ");
    scanf("%s",newstr);
    Compare(string,newstr);
    printf("\n Enter New String For Concatenation  : ");
    scanf("%s",newstr1);
    Concate(string,newstr1);
}
