#include<stdio.h>
int main() 
{
    for (int i1=0;i1<5;i1++) {
        for (int i2=0;i2<5;i2++) {
            for (int i3=0;i3<5;i3++) {
                for (int i4=0;i4<5;i4++) {
                    for (int i5=0;i5<5;i5++) {
                        if (i1==i2||i1==i3||i1==i4||i1==i5||i2==i3||i2==i4||i2==i5||i3==i4||i3==i5||i4==i5) continue;
                        else printf("%d%d%d%d%d\n",i1+1,i2+1,i3+1,i4+1,i5+1); 
                    }
                }
            }
        }
    }
    return 0;
}