#include<stdio.h>
#include<string.h>
int length_string(char[]);
int i=0,c=0;
void main()
{
    char str[10];
    printf("Enter String to find the length : ");
    gets(str);
    printf("String is %s\n",str);
    printf("Length of String is : %d\n",length_string(str));
}
int length_string(char str[])
{
    if(str[i] != '\0')
    {
        //static int i=0,c=0;
        length_string(&str[i+1]);
        //printf("Function called it self \n");
        c++;
    }
    else{
        return c;
    }
    //printf("%d\n",c);
}
