#include<stdio.h>

typedef struct{
    int a, x, y, idx;
}Amplifier;

int custom_cmp(Amplifier amp1, int d2){
    int d1 = amp1.y - amp1.x;

    if(d1 < d2) return 1;
    else return 0;
}

void swap(Amplifier *a, Amplifier *b){
    Amplifier t = *a;
    *a = *b;
    *b = t;
}

int partition(Amplifier *arr, int L, int H){
    int pivot = arr[H].y - arr[H].x;
    int pIdx = L - 1;

    for(int i = L; i <= H - 1; ++i){
        if(custom_cmp(arr[i], pivot)){
            pIdx++;
            swap(&arr[pIdx], &arr[i]);
        }
    }
    swap(&arr[pIdx + 1], &arr[H]);
    return pIdx + 1;
}

void qSort(Amplifier *arr, int L, int H){
    if(L < H){
        int pIdx = partition(arr, L, H);
        qSort(arr, L, pIdx - 1);
        qSort(arr, pIdx + 1, H);
    }
}

int binarySearch(int n, int *cumAmpPower, int l, int r){
    if(l <= r){
        int m = (l + r) / 2;
        int lSum = cumAmpPower[m - 1];
        int rSum = cumAmpPower[n - 1] - cumAmpPower[m - 1];

        if(lSum == rSum)
            return m;
        
        if(lSum > rSum)
            return binarySearch(n, cumAmpPower, l, m - 1);
        else 
            return binarySearch(n, cumAmpPower, m + 1, r);
    }
    return -1;
}

void isPossible(int lastIter){
    int n;
    scanf("%d", &n);
    Amplifier amps[n];
    int cumAmpPower[n];
    for(int i = 0; i < n; ++i){
        amps[i].idx = i;
        scanf("%d %d %d", &amps[i].x, &amps[i].y, &amps[i].a);
        if(i >= 1)
            cumAmpPower[i] = amps[i].a + cumAmpPower[i - 1];
        else
            cumAmpPower[i] = amps[i].a;
    }

    qSort(amps, 0, n - 1);
    if(binarySearch(n, cumAmpPower, 0, n) > 0)
        printf("YES");
    else
        printf("NO");

    if(lastIter)
        printf("\n");
}


int main(){
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; ++i){
        isPossible(i == t - 1);
    }
}