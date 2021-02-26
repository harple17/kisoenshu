#include<stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    long a;
    long p=1;
    for (int i=0;i<n;i++) {
        scanf("%ld",&a);
        p*=a;
    }
    if (p>1000000000000000000) printf("-1");
    else printf("%ld",p);
    
    return 0;
}