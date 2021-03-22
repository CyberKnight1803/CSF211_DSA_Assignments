#include<stdio.h>

int noobCatering(int S[], int R[], int n, int k){
    int supplied = 0;
    for(int i = 0, j = 0; i < n; ++i){
        if(i == R[j]){
            j++;
            continue;
        }
        else{
            supplied += S[i];
        }
    }
    return supplied;
}

int proCatering(int S[], int R[], int n, int k, int x){
    int supplied = 0, max = 0;
    int j = 0;
    for(int i = 0; i < k; ++i){
        int t = x;
        int sIdx = R[i], rIdx = i;
        while(t--){
            if(sIdx == R[rIdx] && rIdx < k){
                supplied += S[sIdx];
                sIdx++;
                rIdx++;
            }
        }
        if(supplied > max){
            max = supplied;
            supplied = 0;
        }
    }
    return max;
}

int main(){
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);

    int S[n], R[k];
    for(int i = 0; i < n; ++i){
        scanf("%d", &S[i]);
    }
    for(int i = 0; i < k; ++i){
        scanf("%d", &R[i]);
    }

    int noob = noobCatering(S, R, n, k);
    int optimal = noob + proCatering(S, R, n, k, x);

    printf("%d %d", noob, optimal);
}