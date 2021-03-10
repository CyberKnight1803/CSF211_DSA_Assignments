#include<stdio.h>

int main(){
    int n, m, mod = 1e9 + 7;
    scanf("%d %d", &n, &m);

    long long int P[n], A[m];
    for(int i = 0; i < n; ++i){
        scanf("%lld", &P[i]);
    }
    for(int i = 0; i < m; ++i){
        scanf("%lld", &A[i]);
    }

    for(int i = 0; i < n - m + 1; ++i){
        for(int j = 0; j < m; ++j){
            P[i + j] = ((P[i + j] % mod) * A[j] % mod) % mod;
        }
    }

    for(int i = 0; i < n; ++i){
        printf("%lld ", P[i]);
    }
    
    return 0;
}