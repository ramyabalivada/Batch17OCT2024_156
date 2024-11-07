/* Description
 A4. rotate array every kth element

1 2 3 4 5 6 7 8 9

k= 3

3 2 1 6 5 4 9 8 7

DOC:7/11/2024
version:0.1v

*/

#include <stdio.h>

void swap(int,int,int);
void rotate(int,int,int);
void printArray(int,int);

void swap(int a[],int start,int end)
{
 int temp=a[start];
 a[start]=a[end];
 a[end]=temp;
}        


void rotate(int a[], int n, int k) {

    for (int i = 0; i < n; i=i+k) {
        int start= i;
        int end = i + k - 1;  
        if (end >= n) {        
            end = n-1;
        }
        swap(a,start,end);
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int k,n,i;
    printf("k value");
    scanf("%d",&k);
    printf("n value");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
    rotate(a, n, k);
    
    printf("rotation of an array every %d elements: ", k);
    printArray(a, n);

    return 0;
}
