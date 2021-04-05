#include<stdio.h>
#include<stdint.h>

int maxContiguousSubArrSum(int a[], int n){
    int max = INT32_MIN, sum = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] <= sum + a[i])
            sum += a[i];
        else
            sum = a[i];
        
        if(sum > max)
            max = sum;
    }
    return max;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    printf("%d", maxContiguousSubArrSum(a, n));
}