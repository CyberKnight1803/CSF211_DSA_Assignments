#include<stdio.h>

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *arr, int L, int H){
    int pivot = arr[H];
    int pIdx = L - 1;

    for(int i = L; i <= H - 1; ++i){
        if(arr[i] < pivot){
            pIdx++;
            swap(&arr[pIdx], &arr[i]);
        }
    }
    swap(&arr[pIdx + 1], &arr[H]);
    return pIdx + 1;
}

void qSort(int *arr, int L, int H){
    if(L < H){
        int pIdx = partition(arr, L, H);
        qSort(arr, L, pIdx - 1);
        qSort(arr, pIdx + 1, H);
    }
}


int ternarySearch(int *arr, int l, int r, int targetValue){
    if(l <= r){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;

        if(arr[m1] == targetValue) return m1;
        
        if(arr[m2] == targetValue) return m2;

        if(targetValue < arr[m1])
            return ternarySearch(arr, l, m1 - 1, targetValue);
        else if(targetValue > arr[m2])
            return ternarySearch(arr, m2 + 1, r, targetValue);
        else
            return ternarySearch(arr, m1 + 1, m2 - 1, targetValue);
    }

    return -1;
}

int main(){
    int n, q, t;
    scanf("%d %d", &n, &q);
    
    int notes[n];

    for(int i = 0; i < n; ++i){
        scanf("%d", &notes[i]);
    }

    qSort(notes, 0, n - 1);

    for(int i = 0; i < q; ++i){
        scanf("%d", &t);
        if(ternarySearch(notes, 0, n, t) > -1)
            printf("YES");
        else
            printf("NO");
        if(i != q - 1)
            printf("\n");
    }
}