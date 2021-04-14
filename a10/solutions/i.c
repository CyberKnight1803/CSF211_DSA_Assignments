#include<stdio.h>
#include<stdint.h>

int minCoins(int coins[], int n, int x){
    if(x == 0)
        return 0;
    
    int min = INT32_MAX;
    for(int i = 0; i < n; ++i){
        if(coins[i] <= x){
            int _min = minCoins(coins, n, x - coins[i]);

            if(_min != INT32_MAX && _min + 1 < min)
                min = _min + 1;
        }
    }
    return min;
}

int main(){
    int n, x;
    scanf("%d %d", &n, &x);
    int coins[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &coins[i]);
    }
    printf("%d", minCoins(coins, n, x));
}