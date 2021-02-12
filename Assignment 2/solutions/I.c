#include <stdio.h>
 
int main()
{
    int m, n, count;
    scanf("%d%d", &m, &n);
    char A[m], str[21];
 
    for(int i = 0; i < m; i++) {
        scanf("%s", str);
        A[i] = *str;
    }
 
    int visited[m];
    for(int i = 0; i < m; i++)
        visited[i] = 0;
    
    int fight = 0;
 
    for(int i = 0; i < m; i++) {
        if(visited[i] == 0) {
            visited[i] = 1;
            count = 1;
            for(int j = i+1; j < m; j++) {
                if(A[i] == A[j]) {
                    visited[j] = 1;
                    count++;
                }
            }
            int d = count/n;
            int r = count%n;
            fight += ((r*d*(d+1)/2) + ((n-r)*d*(d-1)/2) );
        }
    }
 
    printf("%d", fight);
    return 0;
}

