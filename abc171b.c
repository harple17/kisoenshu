#include<stdio.h>
#include<math.h>

int main() {
    int n;
    scanf("%d",&n);
    int keta=1;
    while (n>0) {
        keta++;
        n/=26;
    }
    char name[256];
    int i=0;
    while (i<keta) {
        name[i]='a'+n%26;
        i++;
    }
    return 0;
}