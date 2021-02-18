#include<stdio.h>

 int main()
{
    int T; 
    scanf("%d", &T);
    char code;
    int Pcount = 0, P, maxP = 0;
    while(T--) {
        code = ' ';
        while(code != 'E' && code != 'L')
            scanf("%c", &code);
        scanf("%d", &P);
        if(code == 'E')
            Pcount += P;
        else if(code == 'L')
            Pcount -= P;

        if(maxP < Pcount)
            maxP = Pcount;
    }
    printf("%d", maxP);
}
