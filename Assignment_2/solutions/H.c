#include<stdio.h>

int log_2(int n){
    int power = 0;
    n >>= 1;
    while(n != 0){
        power++;
        n >>= 1;
    }
    return power;
}

long int sum(int n, int *binaryTree){
    int k = log_2(n) + 1;
    long int S = 0;
    int idx = 0;
    for(int i = 1; i <= k; ++i){
        for(int j = 0; j < (1 << (i - 1)); ++j){
            S += binaryTree[idx] * i;
            idx++;
        }
    }
    return S;
}


int main(){
    int n, S;
    scanf("%d", &n);
    int binaryTree[n];
    
    for(int i = 0; i < n; ++i){
        scanf("%d", &binaryTree[i]);
    }

    printf("%ld", sum(n, binaryTree));
}