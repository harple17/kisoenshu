#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 20

int isincluded(int a[],int obj,int n) {
    for (int i=0;i<n;i++) {
        if (obj==a[i]) return 1;
    }
    return 0;
}
void createrandnum(int a[],int n) {
    srand(time(NULL));
    for (int i=0;i<n;i++) {
        a[i]=rand()%n+1;
        if(isincluded(a,a[i],i)) i--;
    }
}

int main() {
    int a[N];
    createrandnum(a,N);
    for (int i=0;i<N;i++) printf("%d ",a[i]);
    return 0;
}