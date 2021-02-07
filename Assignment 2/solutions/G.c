#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int n, int *arr){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                int T = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = T;
            }
        }
    }
}

int minBoxes(int n, int *smallBoxWeights, int bigBoxWeight){
    bubbleSort(n, smallBoxWeights);
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
    int *smallBoxWeights = (int *)malloc(sizeof(int) * n);

    for(int i = 0; i < n; ++i){
        scanf("%d", &smallBoxWeights[i]);
    }
    int bigBoxWeight; scanf("%d", &bigBoxWeight);

    printf("%d", minBoxes(n, smallBoxWeights, bigBoxWeight));
}