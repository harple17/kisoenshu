#include<stdio.h>
#include<stdlib.h>

#define N 200000
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main() {
    int n;
    int a[N];
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),compare_int);
    int flag;
    int c=0;
    for (int i=n-1;i>1;i--) {
        flag=0;
        for (int j=i-1;j>0;j--) {
            if (i!=j&&a[i]%a[j]==0) {
              flag=1;
              break;
            }
        }
        c++;
    }
    printf("%d\n",c);
  
  	return 0;
}