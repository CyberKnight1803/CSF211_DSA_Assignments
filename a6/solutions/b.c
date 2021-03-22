#include<stdio.h>

int maxSegments(int H[], int n){
    int segments = 0, max = 0;
    
    for(int i = 0; i < n; ++i){
        if(H[i] > max){
            ++segments;
            max = H[i];
        }
    }
    return segments;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    printf("%d", maxSegments(a, n));
}