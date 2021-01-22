#include<stdio.h>

int flag = 1;

int matcher(char *s, char *p){
    if(*s == '\0' && *p != '\0'){
        return 0;
    }
    else if(*p == '\0'){
        return 1;
    }
    else if(*s == *p){
        return matcher(s + 1, p + 1);
    }
    else{
        return 0;
    }
}


void rec(int n, char *S){
    static int i = 0;
    if(matcher(S, "baab") && i < n){
        if(flag){
            printf("YES");
            flag = 0;
        }
        printf(" %d", i + 1);
        i += 3;
        rec(n, S + 3);
    }
    else if(i < n){
        i += 1;
        rec(n, S + 1);
    }
    else{
        if(flag)
            printf("NO");
    }
}

int main(){
    int n; scanf("%d", &n);
    char S[n];

    scanf("%s", S);
    rec(n, S);
}