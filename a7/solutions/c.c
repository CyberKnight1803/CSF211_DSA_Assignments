#include<stdio.h>

int max(int a, int b){
    return (a > b)? a : b;
}

int maxHistogram(int row[], int m){
    int idx[m], top = -1;
    int maxArea = 0, area = 0;

    int i = 0, j;
    while(i < m){
        if(top == -1 || row[idx[top]] <= row[i])
            idx[++top] = i++;
        else{
            j = row[idx[top--]];
            area = j * i;

            if(!(top == -1))
                area = j * (i - idx[top] - 1);
            maxArea = max(area, maxArea); 
        }
    }
    while(!(top == -1)){
        j = row[idx[top--]];
        area = j * i;
        if(!(top == -1))
            area = j * (i - idx[top] - 1);
        maxArea = max(area, maxArea);
    }
    return maxArea;
}

int maxSize(int n, int m, int grid[n][m]){
    int maxArea = maxHistogram(grid[0], m);

    for(int i = 1; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(grid[i][j])
                grid[i][j] += grid[i - 1][j];
        }
        maxArea = max(maxArea, maxHistogram(grid[i], m));
    }
    return maxArea;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int grid[n][m];
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    printf("%d", maxSize(n, m, grid));
}