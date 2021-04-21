// verifying grade after compre, largest rectangular area that fits completely within histogram

#include<stdio.h>

int maxRectangle(int a[], int n){
    int hStack[n], top = -1;
    int area, maxArea = 0;
    int i = 0, idx;
    while(i < n){
        if(top == -1 || a[hStack[top]] <= a[i])
            hStack[++top] = i++;
        else{
            idx = hStack[top--];
            area = a[idx] * ((top == -1) ? i : i - hStack[top] - 1);
            if(maxArea < area)
                maxArea = area;
        }
    }
    while(top != -1){
        idx = hStack[top--];
        area = a[idx] * ((top == -1) ? i : i - hStack[top] - 1);
        if(maxArea < area)
            maxArea = area;
    }
    return maxArea;
}

int main(){
    int n;
    scanf("%d", &n);

    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    printf("%d", maxRectangle(a, n));
}

