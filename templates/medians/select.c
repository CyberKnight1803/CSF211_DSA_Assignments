#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; ++i){
        int key = arr[i];
        int idx = i - 1;

        while(idx >= 0 && arr[idx] > key){
            arr[idx + 1] = arr[idx];
            --idx;
        }
        arr[idx + 1] = key;
    }
}

int partition(int arr[], int l, int r, int x){
    int i;
    for(i = l; i < r; ++i){
        if(arr[i] == x)
            break;
    }
    swap(&arr[i], &arr[r]);

    i = l;
    for(int j = l; j < r; ++j){
        if(arr[j] < x){
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int getMedian(int arr[], int n){
    insertionSort(arr, n);
    return arr[n / 2];
}

int ith_statistic(int arr[], int l, int r, int i){
    if(i >= 0 && i <= r - l + 1){
        int n = r - l + 1;

        int j, median[(n + 4) / 5];
        for(j = 0; j < n / 5; ++j){
            median[j] = getMedian(arr + l + j * 5, n % 5);
        }
        if(j * 5 < n){
            median[j] = getMedian(arr + l + j * 5, n % 5);
            j++;
        }

        int median_of_medians = (j == 1)? median[j - 1] : ith_statistic(median, 0, j - 1, j / 2);

        int p_idx = partition(arr, l, r, median_of_medians);
        
        if(p_idx - l == i - 1)
            return arr[p_idx];

        else if(p_idx - l > i - 1)
            return ith_statistic(arr, l, p_idx - 1, i);
        else
            return ith_statistic(arr, p_idx + 1, r, i - p_idx+ l - 1);
    }
    return -1;
}

int main(){
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(int);

    printf("%d", ith_statistic(arr, 0, n - 1, 3));
}