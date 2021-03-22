#include<stdio.h>

void lRotate(int a[], int n, int t){
    while(t--){
        int data = a[0];
        for(int i = 0; i < n - 1; ++i){
            a[i] = a[i + 1];
        }
        a[n - 1] = data;
    }
}

void solution(int a[], int n, int T[], int t){
    for(int i = 0; i < t - 1; ++i){
        lRotate(a, n, T[i]);
        printf("%d %d\n", a[0], a[n - 1]);
    }
    lRotate(a, n, T[n - 1]);
    printf("%d %d", a[0], a[n - 1]);
}  


int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    
    int a[n], T[t];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < t; ++i){
        scanf("%d", &T[i]);
    }

    solution(a, n, T, t);
}