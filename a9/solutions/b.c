#include<stdio.h>
#include<stdlib.h>
#define N (int)1e9

int max(int a[], int n){
    int max = INT32_MIN;
    for(int i = 0; i < n; ++i){
        max = (max < a[i]) ? a[i] : max;
    }
    return max;
}

int clean(int a[], int n){
    int size = max(a, n);
    int *flag = (int *)calloc(size, sizeof(int));
    int *map = (int *)calloc(size, sizeof(int));
    int elmt = 0;
    for(int i = 0; i < n; ++i){
        map[a[i] - 1]++;
    }
    for(int i = 0; i < n; ++i){
        if(flag[a[i] - 1] == 0){
            flag[a[i] - 1] = 1;
            elmt += a[i] - map[a[i] - 1];
        }
    }
    return elmt;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    printf("%d", clean(a, n));
}
