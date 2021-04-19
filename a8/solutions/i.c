#include<stdio.h>

int rotArrSearch(int a[], int l, int h, int t)
{
    if (l > h)
        return -1;

    int m = (l + h) / 2;
    if (a[m] == t)
        return m;
  
    if (a[l] <= a[m]) {
        if (t >= a[l] && t <= a[m])
            return rotArrSearch(a, l, m - 1, t);

        return rotArrSearch(a, m + 1, h, t);
    }

    if (t >= a[m] && t <= a[h])
        return rotArrSearch(a, m + 1, h, t);
  
    return rotArrSearch(a, l, m - 1, t);
}

int search(int a[], int l, int r, int t){
    while(l <= r){
        int m = (l + r) / 2;
        if(a[m] == t)
            return m;
        
        if(a[l] <= a[m]){
            if(t >= a[l] && t <= a[m])
                r = m - 1;
            else
                l = m + 1;
        }

        if(t >= a[m] && t <= a[r])
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i){
        scanf("%d", &a[i]);
    }
    int q;
    scanf("%d", &q);
    while(q--){
        int elmt;
        scanf("%d", &elmt);
        int idx = rotArrSearch(a, 0, n - 1, elmt);
        (idx != -1) ? printf("YES") : printf("NO");
        (q != 0) ? printf("\n") : 0;
    }
}