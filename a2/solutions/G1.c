#include<stdio.h>

void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int *arr, int L, int H){
    int pivot = arr[H]; 
    int idx = L - 1;

    for(int j = L; j <= H; ++j){
        if(arr[j] < pivot){
            ++idx;
            swap(&arr[idx], &arr[j]);
        }
    }
    swap(&arr[idx + 1], &arr[H]);
    return idx + 1;
}

void qSort(int *arr, int L, int H){
    if(L < H){
        int pivot_idx = partition(arr, L, H);
        qSort(arr, L, pivot_idx - 1);
        qSort(arr, pivot_idx + 1, H);
    }
}

int minBoxes(int n, int *smallBoxWeights, int bigBoxWeight){
    qSort(smallBoxWeights, 0, n - 1);
    int f = 0, r = n - 1;
    int boxes = 0;

    while(f <= r){
        if(smallBoxWeights[f] + smallBoxWeights[r] <= bigBoxWeight){
            boxes++;
            f++;
            r--;
        }
        else{
            r--;
            boxes++;
        }
    }
    return boxes;
}

int main(){
    int n; scanf("%d", &n);
    int smallBoxWeights[n];

    for(int i = 0; i < n; ++i){
        scanf("%d", &smallBoxWeights[i]);
    }
    int bigBoxWeight; scanf("%d", &bigBoxWeight);

    printf("%d", minBoxes(n, smallBoxWeights, bigBoxWeight));
}