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
    
    while(l <= r){
        int m = (l + r) / 2;

        if(k == getWatermelons(m, T, n))
            return m;
        
        else if(k < getWatermelons(m, T, n))
            r = m - 1;
        
        else
            l = m + 1;
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    ll T[n], max = INT64_MIN;

    for(int i = 0; i < n; ++i){
        scanf("%lld", &T[i]);

        if(T[i] > max)
            max = T[i];
    }
    ll maxTime = max * k;

    ll minTime = binarySearch(T, n, 0, maxTime, k);
    printf("%lld", minTime);
}