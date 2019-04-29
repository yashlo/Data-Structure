#include<stdio.h>
#include<stdlib.h>
void swap(float *d1 , float *d2)
{
    float temp;
    temp=*d1;
    *d1=*d2;
    *d2=temp;
}
void palin(int n)
{
	int reversedInteger,remainder,originalInteger;
	originalInteger = n;

    // reversed integer is stored in variable 
    while( n!=0 )
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }

    // palindrome if orignalInteger and reversedInteger are equal
    if (originalInteger == reversedInteger)
        printf("%d is a palindrome.", originalInteger);
    else
        printf("%d is not a palindrome.", originalInteger);
    
}

int main()
{
	int x,y;
	FILE *fp;
	fp = fopen("text1.txt","w+");
	fputs("45 75",fp);
	rewind(fp);
	fscanf(fp,"%d %d",&x,&y);
	printf("\n Before swapping values of \n X=%d and Y=%d",x,y);
	swap(&x,&y);
	printf("\n After swapping values of \n X=%d and Y=%d",x,y);
	palin(x);
	palin(y);
	fclose(fp);
	
}
