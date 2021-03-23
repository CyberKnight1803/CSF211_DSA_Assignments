#include<stdio.h>
#define ABS(x)((x) >= 0 ? (x): -(x))

typedef struct{
    int idx;
    int x, y;
    float grad;
}Point;

int manhattanDistance(Point p1){     // wrt to origin
    int x = p1.x;
    int y = p1.y;
    return ABS(x) + ABS(y);
}

int custom_cmp(Point p1, Point p2){
    if(p1.grad > 0 && p2.grad > 0){
        return (p2.grad - p1.grad > 0) ? 1 : 0;
    }
    else if(p1.grad > 0 && p2.grad < 0)
        return 1;
    
    else if(p1.grad < 0 && p2.grad > 0)
        return 0;
    
    else 
        return (p2.grad - p1.grad > 0) ? 1 : 0;
}

void swap(Point *a, Point *b){
    Point t = *a;
    *a = *b;
    *b = t;
}

int partition(Point *arr, int L, int H){
    Point pivot = arr[H];
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

void qSort(Point *arr, int L, int H){
    if(L < H){
        int pIdx = partition(arr, L, H);
        qSort(arr, L, pIdx - 1);
        qSort(arr, pIdx + 1, H);
    }
}

int main(){
    int n;
    scanf("%d", &n);

    Point allMighty, villians[n - 1];
    int minY = 1e6, minY_idx;
    
    for(int i = 0; i < n - 1; ++i){
        scanf("%d %d %d",  &villians[i].idx,  &villians[i].x,  &villians[i].y);

        if(villians[i].y < minY){
            minY = villians[i].y;
            minY_idx = i;
        }
    }
    scanf("%d %d %d", &allMighty.idx, &allMighty.x, &allMighty.y);

    if(allMighty.y > minY){
        Point t = allMighty;
        allMighty = villians[minY_idx];
        villians[minY_idx] = t;
    }

    for(int i = 0; i < n - 1; ++i){
        villians[i].x -= allMighty.x;
        villians[i].y -= allMighty.y;
        villians[i].grad = (float)villians[i].y / (float) villians[i].x;
    }

    qSort(villians, 0, n - 2);

    for(int i = 0; i < n - 1; ++i){
        printf("%d ", villians[i].idx);
    }
}
