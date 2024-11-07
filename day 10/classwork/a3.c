
/* Description:
A3. Write a program to find the  n-th number made of prime digits

Input Format:
First Line Of Input Contains T Number Of Test Cases
Second Line Of Input Contains an input Number N.

Output Format:
Print the Nth number of sequence and it should be only prime.

Constraints:
1<=T<=100
1<=N<=10000

Examples :
Input  :
1
10
Output :
 33
DOC:7/11/2024
version:0.1v
*/

#include <stdio.h>
#define MAX 10000
int primeDigits[] = {2, 3, 5, 7};
int Num(int arr[], int n) {
   int idx = 0;
   for (int i = 0; i < 4; i++) arr[idx++] = primeDigits[i];
   for (int length = 1; idx < n; length++) {
       for (int i = 0; i < idx; i++) {
           for (int j = 0; j < 4; j++) {
               arr[idx++] = arr[i] * 10 + primeDigits[j];
               if (idx >= n) 
               return 0; 
           }
       }
   }
}
int main() {
   int t, n, arr[MAX];
   scanf("%d", &t);
   Num(arr, MAX);
   while (t--) {
       scanf("%d", &n);
       printf("%d\n", arr[n - 1]);
   }
   return 0;
}