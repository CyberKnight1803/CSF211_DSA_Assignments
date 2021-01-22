#include<stdio.h>

int flag = 0, e = 1;

void rec(int n, char *s){

    static int i = 0;
    if(i < n){
        if(*s == 'b' && flag == 0){
            flag++;
            i++;
            rec(n, s+1);
        }
        else if(*s == 'a' && flag == 1){
            i++;
            flag++;
            rec(n, s+1);
        }
        else if(*s == 'a' && flag == 2){
            i++;
            flag++;
            rec(n, s+1);
        }
        else if(*s == 'b' && flag == 3){
            flag = 0;
            if(e){
                printf("YES");
                e = 0;
            }
            printf(" %d", i - 2);
            rec(n, s);
        }
        else{
            i++;
            (*s == 'b')?(flag = 1):(flag = 0);
            rec(n, s+1);
        }
    }
    else{
        if(e) printf("NO");
    }
}

int main(){
    int n; scanf("%d", &n);
    char S[n];
    scanf("%s", S);
    rec(n, S);
}