#include<stdio.h>
#define ll long long
#define ABS(x)((x) >= 0 ? (x): -(x))

typedef struct{
    int x, y;
}Point;

int segmentingQuadrant(Point p){
    if (p.x == 0) {
        if (p.y > 0)
            return 3;
        else
            return 7;
    } else if (p.x > 0) {
        if (p.y > 0)
            return 2;
        else if (p.y == 0)
            return 1;
        else
            return 8;
    } else {
        if (p.y < 0)
            return 6;
        else if (p.y == 0)
            return 5;
        else
            return 4;
    }
}

int custom_cmp(Point p1, Point p2){
    if((p1.x) * (p2.x) > 0 && (p1.y) * (p2.y) > 0)
        return p1.y * p2.x - p1.x * p2.y;
    else
        return segmentingQuadrant(p1) - segmentingQuadrant(p2);
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

ll manhattanDistance(Point p1, Point p2){
    int x = p1.x - p2.x;
    int y = p1.y - p2.y;
    return ABS(x) + ABS(y);
}

int main(){
    int n;
    scanf("%d", &n);

    Point points[n];
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    qSort(points, 0, n - 1);

    ll sum = 0;
    for(int i = 0; i < n; ++i){
        sum += manhattanDistance(points[i % n], points[(i + 1) % n]);
    }

    printf("%lld", sum);
}