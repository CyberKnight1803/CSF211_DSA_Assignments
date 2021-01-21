#include<stdio.h>

#define N 1000

int main(){
    char n1[N], n2[N], ans[N];
    int n1_len, n2_len, ans_len; 
    int i = 0, S = 0, C = 0;

    scanf("%s", n1); scanf("%s", n2);
    
    /* 
    assuming 2nd number to be smaller than first 
    calculating length of both strings using two while loops.
    */
    while(n2[i]) 
        ++i;
    n2_len = i;

    while(n1[i]) 
        ++i;
    n1_len = i;


    for(i = 0; i < n1_len; ++i){
        char n1_d = (i < n1_len)?(n1[n1_len - i - 1] - 48):0;
        char n2_d = (i < n2_len)?(n2[n2_len - i - 1] - 48):0;

        S = n1_d + n2_d + C;
        C = 0;
        if(S > 9){
            C = 1;
            S -= 10;
        }
        ans[i] = S + 48;
    }
    if(C) 
        ans[i++] = C + 48;
    
    ans_len = i;
    for(i = 0; i < ans_len/ 2; ++i){
        char t = ans[i];
        ans[i] = ans[ans_len - i - 1];
        ans[ans_len - i - 1] = t;
    }
    printf("%s", ans);
}