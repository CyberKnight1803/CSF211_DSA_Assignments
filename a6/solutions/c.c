#include<stdio.h>
#include<stdint.h>
#define ll long long 

ll getWatermelons(ll t, ll T[], int n){
    ll w = 0;
    for(int i = 0; i < n; ++i){
        w += t / T[i];
    }
    return w;
}

ll binarySearch(ll T[], int n, ll l, ll r, ll k){
    
    while(l < r){
        int m = (l + r) / 2;

        if(k == getWatermelons(m, T, n))
            return m;
        
        else if(k < getWatermelons(m, T, n))
            r = m - 1;
        
        else
            l = m + 1;
    }
    return l;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    ll T[n], min = INT64_MAX;

    for(int i = 0; i < n; ++i){
        scanf("%lld", &T[i]);

        if(T[i] < min)
            min = T[i];
    }
    int maxTime = min * k;

    int minTime = binarySearch(T, n, 1, maxTime, k);
    printf("%d", minTime);
}