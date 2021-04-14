#include<stdio.h>

int maxDigit(int n){
    int max = 0;
    while(n){
        int r = n % 10;
        max = (max < r) ? r : max;
        n /= 10;
    }
    return max;
}

int minOperations(int n){
    int operations = 0;
    while(n){
        operations++;
        n -= maxDigit(n);
    }
    return operations;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", minOperations(n));
}