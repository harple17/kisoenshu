#include<stdio.h>

int mystrcmp(const char *p1, const char *p2) {
    int c_p1=0;
    int c_p2=0;
    while(*(p1+c_p1)!='\0') c_p1++;
    while(*(p2+c_p2)!='\0') c_p2++;
    if (c_p1<c_p2) return -1;
    else if (c_p1>c_p2) return 1;
    else if (c_p1==c_p2) {
        int f=0;
        int f1=0;
        int f2=0;
        while (*(p1+f)==*(p2+f)&&*(p1+f)!='\0'&&*(p2+f)!='\0') f++;
        if (f==c_p1) return 0;
        if (*(p1+f)>='A'&&*(p1+f)<='Z') f1=2;
        if (*(p1+f)>='a'&&*(p1+f)<='z') f1=1;
        if (*(p1+f)>='0'&&*(p1+f)<='9') f1=0;
        if (*(p2+f)>='A'&&*(p2+f)<='Z') f2=2;
        if (*(p2+f)>='a'&&*(p2+f)<='z') f2=1;
        if (*(p2+f)>='0'&&*(p2+f)<='9') f2=0;
        if (f1>f2) return 1;
        if (f1<f2) return -1;
        if (f1==f2) {
            if (*(p1+f)>*(p2+f)) return 1;
            if (*(p1+f)<*(p2+f)) return -1;
        }
    }
}

int main() {
    char p1[4]="st\0";
    char p2[4]="str\0";
    printf("%d",mystrcmp(p1,p2));
    return 0;
}