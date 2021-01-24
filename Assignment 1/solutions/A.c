#include<stdio.h>

int f = 1, m = 0, i = 0;
char c;

void rec(int n){
    if(n != 0){
        scanf("%c", &c);
        if(c == 'b' && m == 0){
            ++i;
            ++m;
            rec(n - 1);
        }
        else if(c == 'a' && m == 1){
            ++i;
            ++m;
            rec(n - 1);
        }
        else if(c == 'a' && m == 2){
            ++i;
            ++m;
            rec(n - 1);
        }
        else if(c == 'b' && m == 3){
            ++i;
            m = 1;
            if(f){
                printf("YES");
                f = 0;
            }
            printf(" %d", i - 3);
            rec(n -1);
        }
        else{
            m = (c == 'b')?1:0;
            ++i;
            rec(n - 1);
        }
    }
    else{
        if(f){
            printf("NO");
        }
    }
}

int main(){
    int n; scanf("%d", &n);
    scanf("%c", &c);
    rec(n);
}