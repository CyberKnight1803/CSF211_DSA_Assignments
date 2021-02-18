#include<stdio.h>


int goodPairs(long *x, long *y, int n, int k1, int k2){
    int pairs = 0;

    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            if(x[i] + x[j] + k1 > y[i] + y[j] + k2){
                pairs++;
            }
        }
    }
    return pairs;
}

int main(){
    int n, k1, k2;
    scanf("%d %d %d", &n, &k1, &k2);
    long a[n], b[n];

    for(int i = 0; i < n; ++i){
        scanf("%ld", &a[i]);
    }

    for(int i = 0; i < n; ++i){
        scanf("%ld", &b[i]);
    }

    printf("%d", goodPairs(a, b, n, k1, k2));
}