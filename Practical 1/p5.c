#include<stdio.h>
#include<string.h>

void print(char str)
{
    printf("Your string is :%c ",str);
}
int main()
{
    void (*p)(char)=&print;

    (*p)('v');
    return 0;
}

