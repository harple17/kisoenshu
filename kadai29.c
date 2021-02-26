#include<stdio.h>
#define STACK_MAX 50
#define MAX_MERGE 10000
#include<time.h>
#include<stdlib.h>
#define N 400
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
void shellsort(int a[], int n) {
    int h,i,j,tmp;
    for (h=1;h<n/9;h=h*3+1) ;
    for (;h>0;h/=3) {
        for (i=h;i<n;i++) {
            j=i;
            while (j>=h&&a[j-h]>a[j]) {
                tmp=a[j];
                a[j]=a[j-h];
                a[j-h]=tmp;
                j-=h;
            }
        }
    }
}
int getmed(int a[], int left, int right) {
    int mid=(left+right)/2;
    if ((a[left]>=a[mid]&&a[mid]>=a[right])||(a[right]>=a[mid]&&a[mid]>=a[left])) return mid;
    if ((a[mid]>=a[left]&&a[left]>=a[right])||(a[right]>=a[left]&&a[left]>=a[mid])) return left;
    if ((a[left]>=a[right]&&a[right]>=a[mid])||(a[mid]>=a[right]&&a[right]>=a[left])) return right;
}
int partition(int a[], int left, int right) {
    int i=left-1;
    int j=right;
    int med=getmed(a,left,right);
    int pivot=a[med]; a[med]=a[right]; a[right]=pivot;
    int tmp;
    while (1) {
        while (a[++i]<pivot);
        while (i<--j&&a[j]>pivot);
        if (i>=j) break;
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp; 
    }
    tmp=a[i];
    a[i]=a[right];
    a[right]=tmp;
    return i;
}
/*void quicksort_slct_rng(int a[], int left, int right) {
    int v;
    if (left>=right) return ;
    else v=partition(a,left,right);
    quicksort_slct_rng(a,0,v-1);
    quicksort_slct_rng(a,v,right);
}
void quicksort(int a[], int n) {
    quicksort_slct_rng(a,0,n-1);
}*/
void quicksort(int a[], int n) {
    int left,right,v,sp;
    int l[STACK_MAX],r[STACK_MAX];
    l[0]=0;
    r[0]=n-1;
    sp=1;
    while(sp>0) {
        sp--;
        left=l[sp];
        right=r[sp];
        if (left>=right) continue;
        v=partition(a,left,right);
        if (v-left<right-v) {
            l[sp]=v+1;
            r[sp++]=right;
            l[sp]=left;
            r[sp++]=v-1;
        } else {
            l[sp]=left;
            r[sp++]=v-1;
            l[sp]=v+1;
            r[sp++]=right;           
        }
    } 
}
int TMP[MAX_MERGE];
void mergesort_arr(int a[],int left,int right) {
    if(left>=right) return ;
    int mid,i,j,k;
    mid=(left+right)/2;
    mergesort_arr(a,left,mid);
    mergesort_arr(a,mid+1,right);
    for (i=left;i<=mid;i++) TMP[i]=a[i];
    for (i=mid+1,j=right;i<=right;i++,j--) TMP[i]=a[j];
    i=left,j=right;
    for (k=left;k<=right;k++) {
        if (TMP[i]<=TMP[j]) a[k]=TMP[i++];
        else a[k]=TMP[j--];
    }
}

int main() {
    int a[N],b[N],c[N];
    createrandnum(a,N);
    printf("before sort:");
    for (int i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n");
    shellsort(a,N);
    printf("time used:%f\n",(double)clock()/CLOCKS_PER_SEC);
    printf("after sort:");
    for (int i=0;i<N;i++) printf("%d ",a[i]);
    printf("\n\n");
    createrandnum(b,N);
    printf("before sort:");
    for (int i=0;i<N;i++) printf("%d ",b[i]);
    printf("\n");
    quicksort(b,N);
    printf("time used:%f\n",(double)clock()/CLOCKS_PER_SEC);
    printf("after sort:");
    for (int i=0;i<N;i++) printf("%d ",b[i]);
    printf("\n\n");
    createrandnum(c,N);
    printf("before sort:");
    for (int i=0;i<N;i++) printf("%d ",c[i]);
    printf("\n");
    mergesort_arr(c,0,N-1);
    printf("time used:%f\n",(double)clock()/CLOCKS_PER_SEC);
    printf("after sort:");
    for (int i=0;i<N;i++) printf("%d ",c[i]);
    printf("\n");
    return 0;
}