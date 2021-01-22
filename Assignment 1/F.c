#include<stdio.h>

#define R 100000
int flag = 0;

void isPrime(long N, int freq[]){
    int d;

    for(long i = 2; i <= N/2; ++i){
        if(N % i == 0){
            return;
        }
    }
    flag = 1;
    while(N > 0){
        d = N % 10;
        N /= 10;
        freq[d] += 1;
    }
}

void maxFreq(long L, long U, int freq[]){

    int max = 0, D;

    for(long i = L; i <= U; ++i){
        isPrime(i, freq);
    }

    if(flag == 1){
        max = freq[0];
        D = 0;
        for(int i = 0; i < 10; ++i){
            if(freq[i] > max){
                max = freq[i];
                D = i;
            }
        }
        printf("%d %d", D, max);
    }
    else{
        printf("No primes");
    }
}

int main(){
    long A, B;
    scanf("%ld %ld", &A, &B);
    int freq[10] = {0};
    maxFreq(A, B, freq);
}
