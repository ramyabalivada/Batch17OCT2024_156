/*
Description:

A2.Program to find nth number made of given four digits 1, 4,6 and 9 as the only digits..

Input Format:

The First Line Of Input Contains T no of test cases
The Second Line Of Input Contains N as input taken.

Output Format:
Print the number of digits in the nth number .

Constraints:

1<=T<=100
1<=N<=100

Examples:

Input : 6
Output : 14

1,4 6, 9.11,14

Input : 21
Output : 111

DOC:7/11/2024
Version:0.1v
*/


#include <stdio.h>
 
void findNum(int);
void findNum(int num) {
    int digits[] = {1, 4, 6, 9};
    int res[100];  
 
    int id = 0;
    while (num > 0) {
        res[id++] = digits[(num - 1) % 4];
        num = (num - 1) / 4;  
    }
 
    
    printf("The number is:");
    for (int i = id - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    printf("\n");
}
 
int main() {
    int num;
    printf("Enter the value of num: ");
    scanf("%d", &num);
 
    findNum(num);
 
    return 0;
}
