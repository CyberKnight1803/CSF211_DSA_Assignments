#include<stdio.h>

void securityCode(int numbers[], int n){
    int code[n], top = -1;
    for(int i = 0; i < n; ++i){
        while(top != -1 && numbers[code[top] - 1] >= numbers[i])
            --top;
        
        if(top == -1)
            printf("-1 ");
        else 
            printf("%d ", code[top]);
        
        code[++top] = i + 1;
    }
}

int main(){
    int n;
    scanf("%d", &n);

    int  numbers[n];

    for(int i = 0; i < n; ++i){
        scanf("%d", &numbers[i]);
    }
    securityCode(numbers, n);
}