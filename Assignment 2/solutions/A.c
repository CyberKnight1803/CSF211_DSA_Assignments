#include<stdio.h>

int f(int x){
    int dCount = 0, div1 = x, div2 = 1;

    for(int i = x - 1; i >= 2; --i){
        if(x % i == 0 && dCount == 0){
            dCount++;
            div1 = i;
            continue;
        }
        if(x % i == 0 && dCount == 1){
            dCount++;
            div2 = i;
            break;
        }
    }
    if(dCount == 2){
        return f(div1) + f(div2);
    }
    else{
        return x;
    }
}


int main(){
    int N; scanf("%d", &N);
    printf("%d", f(N));
}