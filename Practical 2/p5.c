#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void Check_String(char* str)
{
    static int i=0,j=0,c=0,k=0;
    while(str[i]!='\0')
    {
        if(isdigit(str[i]) || !isalpha(str[i]))
        {
            for(j=i;str[j]!='\0';j++)
            {
                str[i]=str[j+1];
                if(isdigit(str[i]) || !isalpha(str[i]))
                {

                    printf("%c | ",str[i]);
                    c++;
                    str[i]=str[j+1];
                }
                else
                {
                    i++;
                }
            }
            break;
        }
        i++;
    }
    printf("\n No of Remove Symbol and Digit : %d",c);
    printf("\n After Remove All Digit and Symbol Your String is : ");
    puts(str);
}
void main()
{
    char *str;
    str=(char*)malloc(20*sizeof(char));
    printf("\n Enter the String : ");
    gets(str);
    printf("\n Your Entered String is : %s\n",str);
    Check_String(str);
}
