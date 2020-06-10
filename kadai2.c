#include<stdio.h>

int combination(int n,int r);

int main () 
{
    printf("%d",combination(4,2));
    
    return 0;
}

int combination(int n,int r)
{
    if (r==n) return 1;
    else if (r==1) return n;
    else return combination(n-1,r)+combination(n-1,r-1);
}