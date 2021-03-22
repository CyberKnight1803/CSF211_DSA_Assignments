#include<stdio.h>


int cubeRoot(int n){
    if(n > 0){
        for(int i = 1; i <= n; ++i){
            if(i * i * i == n){
                return i;
            }
            else if(i * i * i > n){
                return i - 1;
            }
        }
    }
    if(n < 0){
        for(int i = -1; i >= n; --i){
            if(i * i * i == n){
                return i;
            }
            else if(i * i * i < n){
                return i + 1;
            }
        }
    }
    return 0;
}

int main(){
    int n;
    scanf("%d", &n);
    printf("%d", cubeRoot(n));
}
