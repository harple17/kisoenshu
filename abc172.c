#include<stdio.h>
#include<math.h>

long func(long x) {
    long count=1;
    if (x==1) return count;
    for (long i=2;i<sqrt(x);i++) {
        if (x%i==0) count+=2;
    }
    if(x%(long)sqrt(x)==0) count++;
    return count;
}

int main() {
    for (long i=1;i<=4;i++) printf("%d\n",func(i));
    return 0;
}