#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void palingdrom(char* text)
{
   int begin, middle, end, length = 0;

   while ( text[length] != '\0' )
      length++;

   end = length - 1;
   middle = length/2;

   for( begin = 0 ; begin < middle ; begin++ )
   {
      if ( text[begin] != text[end] )
      {
         printf("Not a palindrome.\n");
         break;
      }
      end--;
   }
   if( begin == middle )
      printf("Palindrome.\n");
}
void  main()
{
   char *text;
   text=(char*)malloc(50*sizeof(char));
   printf("Enter The String : ");
   gets(text);
   //printf("Length of %d",strlen(text));
   //puts(text);
   palingdrom(text);
}
