#include<stdio.h>
#include<string.h>

void combine(char N1[], char N2[]){
    char S[401];
    int n1 = strlen(N1), n2 = strlen(N2);

    int i = 0, j = 0, k = 0;
    while(i < n1 && j < n2){
        if(N1[i] > N2[j]){
            S[k++] = N1[i++];
        }
        else if(N1[i] == N2[j]){
            int t1 = i, t2 = j;
            while(N1[t1] == N2[t2]){
                S[k++] = N1[t1++];
                t2++;
            }
            if(N1[t1] > N2[t2]){
                i = t1;
                S[k++] = N1[i++];
            }
            else{
                j = t2;
                S[k++] = N2[j++];
            }
        }
        else{
            S[k++] = N2[j++];
        }
    }

    while(i < n1){
        S[k++] = N1[i++];
    }
    while(j < n2){
        S[k++] = N2[j++];
    }
    S[k] = '\0';
    printf("%s\n", S);
}

int main(){
    char N1[201], N2[201];
    scanf("%s%*c", N1);
    scanf("%s", N2);
    combine(N1, N2);
}