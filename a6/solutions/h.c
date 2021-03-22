#include<stdio.h>
#define N 10001

char S[N], ans[N];

void incrementStr(int s, int e){
    int n = e - s + 1;
    for(int i = 0; i < n; ++i){
        ans[s + i]++;
    }
}

void reverseStr(int s, int e){
    int n = (e - s + 1) / 2;

    char t;
    for(int i = 0; i < n; ++i){
        t = ans[s + i];
        ans[s + i] = ans[e - i];
        ans[e - i] = t;
    }
}

void specialOperation(){
    int brackets[N], paranthesis[N];
    int bTop = -1, pTop = -1;

    int len = 0, idx;
    for(int i = 0; S[i] != '\0'; ++i){
        switch(S[i]){
            case '[':
                brackets[++bTop] = len;
                break;

            case '(':
                paranthesis[++pTop] = len;
                break;

            case ')':
                idx = paranthesis[pTop--];
                reverseStr(idx, len - 1);
                break;

            case ']':
                idx = brackets[bTop--];
                incrementStr(idx, len - 1);
                break;
            
            default:
                ans[len++] = S[i];
                break;
        }
    }
}

int main(){
    scanf("%s%*c", S);
    specialOperation();
    printf("%s", ans);
}
