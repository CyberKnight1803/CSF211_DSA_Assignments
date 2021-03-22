#include<stdio.h>

#define True 1
#define False 0

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int comparator(int a, int b, int k){
    if(a % k > b % k)
        return False;

    else if (a % k == b % k){
        if(a > b)
            return False;
        else
            return True;
    }

    else 
        return True;
}

int partition(int *arr, int L, int H, int k){
    int pivot = arr[H];
    int pIdx = L - 1;

    for(int i = L; i <= H - 1; ++i){
        if(comparator(arr[i], pivot, k)){
            pIdx++;
            swap(&arr[pIdx], &arr[i]);
        }
    }
    swap(&arr[pIdx + 1], &arr[H]);
    return pIdx + 1;
}

void qSort(int *arr, int L, int H, int k){
    if(L < H){
        int pIdx = partition(arr, L, H, k);
        qSort(arr, L, pIdx - 1, k);
        qSort(arr, pIdx + 1, H, k);
    }
}

void printArr(int a[], int n){
    for(int i = 0; i < n; ++i){
        printf("%d ", a[i]);
    }
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    qSort(a, 0, n - 1, k);
    printArr(a, n);
}  