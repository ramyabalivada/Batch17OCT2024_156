/* Description:
A1.Check whether a given number can be expressed as the sum of two prime number

i/p
Enter a positive integer: 34
Output
34 = 3 + 31

34 = 5 + 29
34 = 11 + 23
34 = 17 + 17
NoofWays = 4

NoofWays=-1
DOC:7/11/2024
version:0.1v

*/


#include<stdio.h>
int prime(int);
int main()
{
    int n,i,flag=0,count=0;
    scanf("%d",&n);
    for(i=2;i<=n/2;i++)
    {
        if(prime(i)==1)
        {
           if(prime(n-i)==1){
                printf("%d=%d+%d\n",n,i,n-i);
                flag=1;
                count++;
           }   
            
        }
    }
    if (count > 0) {
        printf("NoofWays = %d\n", count);
    } else {
        printf("NoofWays = -1\n");
    }
    
}
int prime(int n)
{
    int i,flag=1;
    if(n<=1){
        flag=0;
    }
    else{
        for(i=2;i<n/2;i++)
        {
            if(n%i==0)
            {
                flag=0;
                break;
            }
        }
    }
    return flag;
}

    
    
    
    
    
    
    