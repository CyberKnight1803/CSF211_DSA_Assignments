#include<stdio.h>
#include<stdlib.h>

void generateBitString(int m, int n,  int *p, int *bitString){
    for(int i = 0; i < n; ++i){
        bitString[p[i]] = 1; 
    }
}

int maxProducts(int m, int *bitString){
    int money = m, products = 0;
    for(int i = 0; i <= m; ++i){
        if(bitString[i] == 1){
            money -= i;
            if(money > 0){
                ++products;
            }
        }
        if(money < 0){
            break;
        }
    }
    return products;
}

int main(){
    int m; scanf("%d", &m);
    int n; scanf("%d", &n);
    int *p = (int *)malloc(sizeof(int) * n);
    int *bitString = (int *)malloc(sizeof(int) * (m + 1));

    for(int i = 0; i < n;  ++i){
        scanf("%d", &p[i]);
    }

    generateBitString(m, n, p, bitString);
    printf("%d", maxProducts(m, bitString));
}