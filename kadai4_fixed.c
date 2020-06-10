#include<stdio.h>
int main() 
{
    int day,n_of_days;
    printf("表示する月は何曜日から始まりますか？次の数字で答えてください\n0:日、1:月、2:火、3:水、4:木、5金、6:土=");
    scanf("%d",&day);
    printf("表示する月は何日ありますか？数値を入力してください=");
    scanf("%d",&n_of_days);

    printf("日 月 火 水 木 金 土\n");
    for (int i=0;i<day;i++) {
        printf("   ");
    } 
    for (int j=0;j<n_of_days;j++) {
        if ((day+j)%7==6) printf("%2d\n",j+1);
        else printf("%2d ",j+1);
    }
    
    printf("\n月 火 水 木 金 土 日\n");
    if (day==0) printf("                  ");
    else {
        for (int i=0;i<day-1;i++) {
            printf("   ");
        }
    }
    for (int j=0;j<n_of_days;j++) {
        if ((day+6+j)%7==6) printf("%2d\n",j+1);
        else printf("%2d ",j+1);
    }
    return 0;    
}