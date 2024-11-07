/* Description:
  
A5.
Write a c program to print alphabet triangle.
Input: 5
Output:

     A
    ABA
   ABCBA
  ABCDCBA
 ABCDEDCBA

DOC:7/11/2024
version:0.1v

*/


#include <stdio.h>

void pattern(int);

int main()
{
    int n;
    scanf("%d", &n);  
    pattern(n); 
}

void pattern(int n)
{
    int i,j;
    char ch='A';
    for (i = 0; i < n; i++)  
    {
        
        for (j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        for (j = 0; j <= i; j++)
        {
            printf("%c",  ch + j); 
        }

        
        for (j = i - 1; j >= 0; j--)
        {
            printf("%c", ch + j); 
        }

        printf("\n");
    }
}
