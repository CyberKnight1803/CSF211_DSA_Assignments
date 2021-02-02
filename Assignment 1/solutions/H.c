#include<stdio.h>
#define N 500

void rotate(int n, int *arr){
    int t = arr[0], i = 0;
    for(i = 0; i < n - 1; ++i){
        arr[i] = arr[i + 1];
    }
    arr[i] = t;
}

long difference(int n, int *arr){
    long cubes = 0, squares = 0;
    for(int i = 0; i < n; ++i){
        if(i % 2){
            cubes += arr[i] * arr[i] * arr[i];
        }
        else{
            squares += arr[i]*arr[i];
        }
    }
    return (squares - cubes);
}

int minMax(int n, int *arr){
    long cost = 0, min, max;
    min = difference(n, arr);
    max = min;
    
    for(int i = 1; i < n; ++i){
        rotate(n, arr);
        cost = difference(n, arr);
        if(max < cost) max = cost;
        if(min > cost) min = cost;
    }
    return max - min;
}

int main(){
    int n; scanf("%d", &n);
    int arr[N];

    for(int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
    }
    printf("%d", minMax(n, arr));
}