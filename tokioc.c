#include<stdio.h>
#define N 200000
int main() {
    int a[N],buff[N];
    int n,k;
    scanf("%d %d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int l=0;l<k;l++) {
        buff[N]={0};
        for (int i=0;i<n;i++) {
            for(int j=i-a[i];j<i+a[i];j++) {
                buff[j]++;
            }
        }
        for (int i=0;i<n;i++) a[i]=buff[i];
    }
    for (int i=0;i<n;i++) printf("%d ",a[i]);
    return 0;
}