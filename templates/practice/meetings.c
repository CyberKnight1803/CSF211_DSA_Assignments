// Max meetings in one room

#include<stdio.h>
#include<stdlib.h>

typedef struct Meeting{
    int start, end;
}Meeting;

void swap(Meeting *a, Meeting *b){
    Meeting t = *a;
    *a = *b;
    *b = t;
}

int cmp(Meeting a, Meeting b){
    if(a.end < b.end){
        return 1;
    }
    else if(a.end == b.end)
        return (a.start < b.start) ? 1 : 0;
    else 
        return 0;
}

int partition(Meeting a[], int l, int r){
    Meeting pivot = a[r];
    int pIdx = l - 1;

    for(int i = l; i <= r; ++i){
        if(cmp(a[i], pivot)){
            pIdx++;
            swap(&a[pIdx], &a[i]);
        }
    }
    swap(&a[pIdx + 1], &a[r]);
    return pIdx + 1;
}

void qSort(Meeting a[], int l, int r){
    if(l < r){
        int pIdx = partition(a, l, r);
        qSort(a, l, pIdx - 1);
        qSort(a, pIdx + 1, r);
    }
}

int maxMeetings(Meeting a[], int n){
    int count = 0;
    int endTime = a[0].end;

    for(int i = 1; i < n; ++i){
        if(a[i].start > endTime){
            count++;
            endTime = a[i].end;
        }
    }
    return count + 1;
}

int main(){
    int n; scanf("%d", &n);
    Meeting meetings[n];
    for(int i = 0; i < n; ++i){
        scanf("%d %d", &meetings[i].start, &meetings[i].end);
    }
    qSort(meetings, 0, n - 1);  

    /* for(int i = 0; i < n; ++i){
        printf("%d %d\n", meetings[i].start, meetings[i].end);
    } */

    printf("%d", maxMeetings(meetings, n));
}
