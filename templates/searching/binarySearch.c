#include<stdio.h>

int recBinarySearch(int arr[], int l, int h, int t){
    if(l <= h){
        int m = (l + h) / 2;

        if(arr[m] == t)
            return m;
        else if(arr[m] < t)
            return recBinarySearch(arr, m + 1, h, t);
        else 
            return recBinarySearch(arr, l, m - 1, t);
    }
    return -1;
}

int itrBinarySearch(int arr[], int l, int h, int t){
    while(l <= h){
        int m = (l + h) / 2;
        if(arr[m] == t)
            return m;
        else if (arr[m] < t)
            l = m + 1;
        else 
            h = m - 1;
    }
    return -1;
}

int lBinarySearch(int arr[], int n, int t){
    int l = 0;
    int r = n;

    while(l < r){
        int m = (l + r) / 2;

        if(arr[m] < t)
            l = m + 1;
        else 
            r = m;
    }
    if(arr[l] == t)
        return l;
    return -1;
}

int rBinarySearch(int arr[], int n, int t){
    int l = 0;
    int r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(arr[m] <= t)
            l = m + 1;
        else 
            r = m;
    }
    if(arr[r - 1] == t)
        return r - 1;
    return -1;
}

int reclBinarySearch(int arr[], int l, int r, int t){
    if(l < r){
        int m = (l + r) / 2;
        if(arr[m] < t)
            return reclBinarySearch(arr, m + 1, r, t);
        else 
            return reclBinarySearch(arr, l, m, t);
    }
    return l;
}



int main(){
    int arr[] = {1, 5, 10, 19, 19, 19, 19, 19, 19, 21, 32, 35, 78, 90, 97};
    int len = sizeof(arr) / sizeof(int);
    int n; scanf("%d", &n);
    printf("%d %d\n", recBinarySearch(arr, 0, len - 1, n), itrBinarySearch(arr, 0, len - 1, n));
    printf("%d %d\n", lBinarySearch(arr, len, n), rBinarySearch(arr, len, n));
    printf("%d ", reclBinarySearch(arr, 0, len, n));
}
