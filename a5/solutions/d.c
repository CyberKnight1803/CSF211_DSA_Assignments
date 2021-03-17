#include<stdio.h>

#define ll long long

void minMax(ll *Q, int n){
    ll min = 1e9 + 1, minCount = 0, max = -1, maxCount = 0;
    
    for(int i = 0; i < n; ++i){
        if(Q[i] < min){
            min = Q[i];
            minCount = 1;
        }
        else if(Q[i] == min){
            minCount++;
        }
        
        if(Q[i] > max){
            max = Q[i];
            maxCount = 1;
        }
        else if(Q[i] == max){
            maxCount++;
        }
    }

    printf("%lld %lld", max - min, maxCount * minCount);
}

int main(){
    int n;
    scanf("%d", &n);
    ll Q[n];

    for(int i = 0; i < n; ++i){
        scanf("%lld", &Q[i]);
    }

    minMax(Q, n);
}