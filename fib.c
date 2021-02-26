#include<stdio.h>
#define STCK_MAX 100

int fib1(int n) {
    if (n<2) return n;
    else return fib1(n-1)+fib1(n-2);
}
void fib2(int arr[],int n) {
    int a,b;
    a=b=1;
    arr[1]=a;
    for (int i=0;i<n-1;i++) {
        int tmp=a;
        a=b;
        b+=tmp;
        arr[i+2]=a;
    }
}
int N;
int stack[STCK_MAX];
void init() {
    N=0;
}
void push(int x) {
    if (N>=STCK_MAX) printf("stack overflow\n");
    else stack[N++]=x;
}
int pop() {
    if (N<=0) printf("stack underflow\n");
    else return stack[--N];
}
void fib3(int n) {
    init();
    push(1); push(1);
    int a,b;
    for (int i=0;i<n-2;i++) {
        b=pop();
        a=pop();
        push(a);
        push(b);
        push(a+b);
    }
}

int main() {
    printf("入力された回数フィボナッチ数列を計算します。\n");
    int n;
    scanf("%d",&n);
    printf("recursive func\n");
    for (int i=1;i<=n;i++) {
        printf("fib(%d):%d\n",i,fib1(i));
    }
    printf("list\n");
    int arr[100]={0};
    fib2(arr,n);
    for (int i=1;i<=n;i++) {
        printf("fib(%d):%d\n",i,arr[i]);
    }
    printf("stack\n");
    fib3(n);
    for (int i=1;i<=n;i++) {
        printf("fib(%d):%d\n",i,stack[i-1]);
    }
    return 0;
}