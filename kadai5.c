#include<stdio.h>
int main() 
{
    int y;
    do {
        printf("西暦を入力してください。(1583以上3999以下)"); scanf("%d",&y);
    } while (y<1583||y>3999);

    if ((y%4==0&&y%100!=0)||(y%400==0)) printf("うるう年です。");
    else printf("うるう年ではありません。");
    return 0;
}