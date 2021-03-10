#include<stdio.h>
#include<stdlib.h>

void combinations(char *list, int N, int K, char S[]){
    if(K == 0){
        printf("%s\n", S);
    }
    else{
        for(int i = 0; i < N; ++i){
            S[K - 1] = list[i];
            combinations(list, N, K - 1, S);
        }
    }
}

int main(){
    int N, K;
    scanf("%d %d", &N, &K);
    char *list = (char *)malloc(sizeof(char) * (N + 1));
    char *S = (char *)malloc(sizeof(char) * (K + 1));
    scanf("%s", list);
    combinations(list, N, K, S);
}