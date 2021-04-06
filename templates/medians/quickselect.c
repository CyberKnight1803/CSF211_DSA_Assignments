#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int idx = l;
    for(int j = l; j < r; j++){
        if(arr[j] < pivot){
            swap(&arr[idx], &arr[j]);
            ++idx;
        }
    }
    swap(&arr[idx], &arr[r]);
    return idx;
}

int ith_statistic(int arr[], int l, int r, int i){

    if(i > 0 && i <= r - l + 1){
        int p_idx = partition(arr, l, r);

        if(p_idx - l == i - 1)
            return arr[p_idx];
        
        if(p_idx - l > i - 1)
            return ith_statistic(arr, l, p_idx - 1, i);
        else
            return ith_statistic(arr, p_idx + 1, r, i - p_idx + l - 1);
    }
    return -1;
}

int main(){
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(int);

    printf("%d", ith_statistic(arr, 0, n-1, 4));
}