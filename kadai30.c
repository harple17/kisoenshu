#include<stdio.h>
#define M1 31
#define MASK_1 0x1f
#define M2 15
#define MASK_2 0x0f
#include<time.h>
#include<stdlib.h>
#define N 1000

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
int count1[M1+1];
int count2[M2+1];
void radixsort32(int a[], int b[], int n) {
    int i,bit;
    for (bit=0;bit<=M1;bit+=5) {
        for (i=0;i<=M1;i++) count1[i]=0;
        for (i=0;i<n;i++) count1[(a[i]>>bit)&MASK_1]++;
        for (i=0;i<M1;i++) count1[i+1]+=count1[i];
        for (i=n-1;i>=0;i--) b[--count1[(a[i]>>bit)&MASK_1]]=a[i];
        for (i=0;i<n;i++) a[i]=b[i];
    }
}
void radixsort16(int a[], int b[], int n) {
    int i,bit;
    for (bit=0;bit<=M2;bit+=4) {
        for (i=0;i<=M2;i++) count2[i]=0;
        for (i=0;i<n;i++) count2[(a[i]>>bit)&MASK_2]++;
        for (i=0;i<M2;i++) count2[i+1]+=count2[i];
        for (i=n-1;i>=0;i--) b[--count2[(a[i]>>bit)&MASK_2]]=a[i];
        for (i=0;i<n;i++) a[i]=b[i];
    }
}

int main() {
    int a[N],b[N];
    createrandnum(a,N);
    printf("before sort:");
    for (int i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");
    radixsort32(a,b,N);
    printf("time used:%f\n",(double)clock()/CLOCKS_PER_SEC);
    printf("after sort:");
    for (int i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n\n");
    createrandnum(a,N);
    printf("before sort:");
    for (int i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");
    radixsort16(a,b,N);
    printf("time used:%f\n",(double)clock()/CLOCKS_PER_SEC);
    printf("after sort:");
    for (int i=0;i<N;i++) printf("%d ",a[i]);
}