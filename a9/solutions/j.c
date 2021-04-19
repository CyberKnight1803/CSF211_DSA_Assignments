#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10

void swap(char *a, char *b){
    char t = *a;
    *a = *b;
    *b = t;
}

void swapStr(char **a, char **b){
    char *t = *a;
    *a = *b;
    *b = t;
}

void reverse(char s[]){
    int n = strlen(s);
    for(int i = 0; i < n / 2; ++i)
        swap(&s[i], &s[n - i - 1]);
}

void invert(char **S, int n, int i){
    if(i >= n){
        return;
    }
    reverse(S[i]);
    invert(S, n, 2 * i + 1);
    invert(S, n, 2 * i + 2);
    swapStr(&S[2 * i + 1], &S[2 * i + 2]);
}

void inorder(char **S, int n, int i){
    if(i >= n)
        return;
    
    inorder(S, n, 2 * i + 1);
    if(strcmp(S[i], "1-"))
        printf("%s ", S[i]);
    inorder(S, n, 2 * i + 2);
}

int main(){
    int n;
    scanf("%d", &n);
    char **S = (char **)malloc(sizeof(char *) * n);
    for(int i = 0; i < n; ++i){
        S[i] = (char *)malloc(sizeof(char) * (N + 1));
        scanf("%s", S[i]);
    }
    invert(S, n, 0);
    inorder(S, n, 0);
    /* for(int i = 0; i < n; ++i){
        printf("%s ", S[i]);
    } */
}