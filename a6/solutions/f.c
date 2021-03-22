#include<stdio.h>

int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }

    int front = 0, rear = n - 1;

    for(int i = 0; i < t; ++i){
        int rotate;
        scanf("%d", &rotate);

        front = (front + rotate) % n;
        rear = (rear + rotate) % n;

        printf("%d %d", a[front], a[rear]);
        if(i != t - 1){
            printf("\n");
        }
    }
}