#include<stdio.h>
#define N 4
#define M 4

int main()
{
    int arr[N][M];
    for (int i=0;i<N;i++) {
        for (int j=0;j<M;j++) {
            printf("%d行%d列目の値を入力してください：",i+1,j+1); 
            scanf("%d",&arr[i][j]);
        }
    }
    /*show table*/
    /*row1*/
    printf("      ");
    for (int i=0;i<M;i++) {
        printf(" %5d",i+1);
    }
    printf(" total\n");
    /*row2-row5*/
    for (int i=0;i<N;i++) {
        printf(" %5d",i+1);
        int row_total=0;
        for (int j=0;j<M;j++) {
            printf(" %5d",arr[i][j]);
            row_total+=arr[i][j];
        }
        printf(" %5d\n",row_total);
    }
    /*row6*/
    printf(" total");
    int sum=0;
    for (int i=0;i<M;i++) {
        int line_total=0;
        for (int j=0;j<N;j++) {
            line_total+=arr[j][i];
        }
        printf(" %5d",line_total);
        sum+=line_total;
    }
    printf(" %5d",sum);

    return 0;
}