#include<stdio.h>

int log_2(int n){
    int power = 0;
    n >>= 1;
    while(n != 0){
        power++;
        n >>= 1;
    }
    return power;
}

int totalWays(int n, int power){
    if(n == 0){
        return 1;
    }
    else if(power == 0){
        return 1;
    }
    else if(n >= (1 << power)){
        int residue = n - (1 << power);
        return totalWays(n, power - 1) + totalWays(residue, power);
    }
    else{
        return totalWays(n, power - 1);
    }
}

int main(){ 
    int n; scanf("%d", &n);
    printf("%d", totalWays(n, log_2(n)));        
}

