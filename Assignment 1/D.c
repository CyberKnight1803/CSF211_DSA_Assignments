#include<stdio.h>

void sort(int n, long *arr){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}

int maxPurchase(int n, long *items, long money){
    sort(n, items);
    int c = 0;
    for(int i = 0; i < n; ++i){
        money -= items[i];
        if(money >= 0){
            c++;
        }
        else{
            break;
        }
    }
    return c;
}

int main(){
    long money; scanf("%ld", &money);
    int n; scanf("%d", &n);
    long items[25];


    for(int i = 0; i < n; ++i){
        scanf("%ld", &items[i]);
    }
    
    printf("%d", maxPurchase(n, items, money));
}